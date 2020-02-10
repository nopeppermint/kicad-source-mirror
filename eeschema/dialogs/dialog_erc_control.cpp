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

#include <dialogs/dialog_erc_control.h>
#include <erc/erc_engine.h>
#include <erc/erc_violation.h>
#include <sch_edit_frame.h>
#include <tools/erc_manager.h>


DIALOG_ERC_CONTROL::DIALOG_ERC_CONTROL( ERC_MANAGER* aManager, SCH_EDIT_FRAME* aEditorFrame,
                                        wxWindowID aId ) :
        DIALOG_RULE_CHECK_CONTROL( aManager, aEditorFrame, aId ),
        m_editFrame( aEditorFrame )
{
    SetTitle( _( "ERC Control" ) );

    m_btnSettings->SetLabel( _( "Edit electrical rules..." ) );

    // We use a sdbSizer here to get the order right, which is platform-dependent
    m_sdbSizerOK->SetLabel( _( "Run ERC" ) );
    m_sdbSizerCancel->SetLabel( _( "Close" ) );
    m_sizerButtons->Layout();

    m_sdbSizerOK->SetDefault();

    FinishDialogSettings();
}


DIALOG_ERC_CONTROL::~DIALOG_ERC_CONTROL()
{
}


void DIALOG_ERC_CONTROL::onEngineFinished( bool aChecksPassed )
{
    DIALOG_RULE_CHECK_CONTROL::onEngineFinished( aChecksPassed );

    auto view = m_editFrame->GetCanvas()->GetView();

    for( const auto& violation : getManager()->GetEngine<ERC_ENGINE>()->GetViolations() )
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

    m_editFrame->GetCanvas()->Refresh();
}


ERC_MANAGER* DIALOG_ERC_CONTROL::getManager()
{
    return static_cast<ERC_MANAGER*>( m_manager );
}