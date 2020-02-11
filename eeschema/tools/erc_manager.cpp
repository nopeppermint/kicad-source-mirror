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

#include <advanced_config.h>
#include <dialogs/dialog_erc_control.h>
#include <erc/erc_engine.h>
#include <erc/erc_violation.h>
#include <id.h>
#include <sch_edit_frame.h>
#include <tool/tool_manager.h>
#include <tools/ee_actions.h>
#include <tools/erc_manager.h>


ERC_MANAGER::ERC_MANAGER() : RULE_CHECK_MANAGER_BASE( "eeschema.ERCManager" ),
        m_schFrame( nullptr )
{
}


ERC_MANAGER::~ERC_MANAGER()
{
    delete m_engine;
}


void ERC_MANAGER::Reset( RESET_REASON aReason )
{
    m_schFrame = getEditFrame<SCH_EDIT_FRAME>();
    m_engine = new ERC_ENGINE;

    static_cast<ERC_ENGINE*>( m_engine )->SetEditFrame( m_schFrame );

    m_engine->SetCallbacks(
            [&]( bool aResult )
            {
                onEngineFinished( aResult );
            },
            [&]( double aProgress, const wxString& aMsg )
            {
                onEngineProgress( aProgress, aMsg );
            } );
}


bool ERC_MANAGER::RunChecks()
{
    static_cast<ERC_ENGINE*>( m_engine )->WaitForFinish();
    return RULE_CHECK_MANAGER_BASE::RunChecks();
}


void ERC_MANAGER::ClearViolations()
{
    std::set<EDA_ITEM*> to_update;

    for( const auto& violation : m_engine->GetViolations() )
    {
        to_update.insert( violation->FirstItem() );

        if( violation->SecondItem() )
            to_update.insert( violation->SecondItem() );
    }

    RULE_CHECK_MANAGER_BASE::ClearViolations();

    auto view = m_schFrame->GetCanvas()->GetView();

    for( auto& item : to_update )
    {
        view->Update( item );
    }

    m_schFrame->GetCanvas()->Refresh();
}


int ERC_MANAGER::OnERCUpdate( const TOOL_EVENT& aEvent )
{
    if( aEvent.Matches( ProgressEvent ) )
    {
        std::lock_guard<std::mutex> lock( m_mutex );

        if( m_controlDialog )
            m_controlDialog->OnEngineProgress( m_progress.load(), m_status );

        return 0;
    }

    wxASSERT( aEvent.Matches( FinishedEvent ) );

    if( m_controlDialog )
        m_controlDialog->OnEngineFinished( aEvent.Parameter<bool>() );

    auto view = m_schFrame->GetCanvas()->GetView();

    for( const auto& violation : GetEngine<ERC_ENGINE>()->GetViolations() )
    {
        EDA_ITEM* first  = violation->FirstItem();
        EDA_ITEM* second = violation->SecondItem();

        wxASSERT( first );

        first->AddViolation( violation );
        view->Update( first );

        if( second )
        {
            second->AddViolation( violation );
            view->Update( second );
        }
    }

    m_schFrame->GetCanvas()->Refresh();

    return 0;
}


void ERC_MANAGER::createControlDialog( wxWindow* aParent )
{
    m_controlDialog = new DIALOG_ERC_CONTROL( this, m_schFrame, ID_DIALOG_ERC );
}


void ERC_MANAGER::setTransitions()
{
    if( ADVANCED_CFG::GetCfg().m_newErc )
        Go( &ERC_MANAGER::ShowControlDialog,    EE_ACTIONS::runERC.MakeEvent() );

    Go( &ERC_MANAGER::OnERCUpdate, ProgressEvent );
    Go( &ERC_MANAGER::OnERCUpdate, FinishedEvent );
}


void ERC_MANAGER::onEngineProgress( double aProgress, wxString aStatusMessage )
{
    m_progress.store( aProgress );

    std::lock_guard<std::mutex> lock( m_mutex );
    m_status = aStatusMessage;

    TOOL_EVENT evt = ProgressEvent;
    m_toolMgr->PostEvent( evt );
}


void ERC_MANAGER::onEngineFinished( bool aChecksPassed )
{
    TOOL_EVENT evt = FinishedEvent;
    evt.SetParameter<bool>( aChecksPassed );
    m_toolMgr->PostEvent( evt );
}


const TOOL_EVENT ERC_MANAGER::ProgressEvent(
        TC_MESSAGE, TA_ACTION, "eeschema.ERCManager.progress" );


const TOOL_EVENT ERC_MANAGER::FinishedEvent(
        TC_MESSAGE, TA_ACTION, "eeschema.ERCManager.finished" );
