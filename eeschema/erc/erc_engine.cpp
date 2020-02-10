/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020 Jon Evans <jon@craftyjon.com>
 * Copyright (C) 2020 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <thread>

#include <wx/wx.h>

#include <connection_graph.h>
#include <erc/erc_engine.h>
#include <erc/erc_violation.h>
#include <sch_edit_frame.h>


bool ERC_ENGINE::Start()
{
    try
    {
        m_runner_future = std::async( std::launch::async, &ERC_ENGINE::run, this );
    }
    catch( ... )
    {
        return false;
    }

    return true;
}


double ERC_ENGINE::GetProgress()
{
    return 1.0;
}


void ERC_ENGINE::WaitForFinish()
{
    try
    {
        m_runner_future.wait();
    }
    catch( ... )
    {
    }
}


void ERC_ENGINE::Abort()
{
    m_should_abort = true;
}


void ERC_ENGINE::run()
{
    wxASSERT( m_frame );

    bool success = true;

    reportProgress( 0.5, _( "Checking bus to net conflicts..." ) );

    success &= checkBusToNetConflicts();

    // Make this look harder than it is
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

    if( m_finishedCallback )
        m_finishedCallback( success );
}


bool ERC_ENGINE::checkBusToNetConflicts()
{
    bool      success = true;
    EDA_UNITS units   = m_frame->GetUserUnits();

    for( const auto& subgraph : g_ConnectionGraph->GetSubgraphs() )
    {
        wxString msg;
        auto sheet = subgraph->m_sheet;

        SCH_ITEM* net_item = nullptr;
        SCH_ITEM* bus_item = nullptr;
        SCH_CONNECTION conn;

        for( auto item : subgraph->m_items )
        {
            switch( item->Type() )
            {
            case SCH_LINE_T:
            {
                if( item->GetLayer() == LAYER_BUS )
                    bus_item = ( !bus_item ) ? item : bus_item;
                else
                    net_item = ( !net_item ) ? item : net_item;
                break;
            }

            case SCH_LABEL_T:
            case SCH_GLOBAL_LABEL_T:
            case SCH_SHEET_PIN_T:
            case SCH_HIER_LABEL_T:
            {
                auto text = static_cast<SCH_TEXT*>( item )->GetShownText();
                conn.ConfigureFromLabel( text );

                if( conn.IsBus() )
                    bus_item = ( !bus_item ) ? item : bus_item;
                else
                    net_item = ( !net_item ) ? item : net_item;
                break;
            }

            default:
                break;
            }
        }

        if( net_item && bus_item )
        {
            msg.Printf( _( "%s and %s are graphically connected but cannot"
                           " electrically connect because one is a bus and"
                           " the other is a net." ),
                        bus_item->GetSelectMenuText( m_frame->GetUserUnits() ),
                        net_item->GetSelectMenuText( m_frame->GetUserUnits() ) );

            auto violation = new BUS_NET_CONFLICT_VIOLATION(
                    units, net_item, VECTOR2I( net_item->GetPosition() ),
                    bus_item, VECTOR2I( bus_item->GetPosition() ),
                    msg );

            m_violations.push_back( violation );

            success = false;
        }
    }

    return success;
}
