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

#include <bitmaps.h>
#include <dialogs/dialog_rule_check_control.h>
#include <rule_check_engine.h>
#include <tool/rule_check_manager.h>
#include <wx/wx.h>

using namespace std::placeholders;


DIALOG_RULE_CHECK_CONTROL::DIALOG_RULE_CHECK_CONTROL( RULE_CHECK_MANAGER_BASE* aManager,
                                                      wxWindow* aParent, wxWindowID aId ) :
        DIALOG_RULE_CHECK_CONTROL_BASE( aParent, aId ),
        m_manager( aManager )
{
    m_btnBrowseReportPath->SetBitmap( KiBitmap( folder_xpm ) );

    m_manager->GetEngine()->SetCallbacks(
            std::bind( &DIALOG_RULE_CHECK_CONTROL::onEngineFinished, this, _1 ),
            std::bind( &DIALOG_RULE_CHECK_CONTROL::onEngineProgress, this, _1, _2 ) );
}


bool DIALOG_RULE_CHECK_CONTROL::TransferDataToWindow()
{
    return true;
}


bool DIALOG_RULE_CHECK_CONTROL::TransferDataFromWindow()
{
    return true;
}


void DIALOG_RULE_CHECK_CONTROL::OnReportCheckBoxClicked( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECK_CONTROL::OnButtonBrowseReportPathClick( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECK_CONTROL::OnButtonEditDesignRules( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECK_CONTROL::OnDeleteAllClick( wxCommandEvent& event )
{
    m_manager->ClearViolations();
}


void DIALOG_RULE_CHECK_CONTROL::OnCloseClick( wxCommandEvent& event )
{
    event.Skip();
}


void DIALOG_RULE_CHECK_CONTROL::OnStartChecksClick( wxCommandEvent& event )
{
    m_sdbSizerOK->Disable();
    m_progressBar->SetValue( 0 );
    m_progressBar->Show();

    m_manager->RunChecks();
}


void DIALOG_RULE_CHECK_CONTROL::onEngineFinished( bool aChecksPassed )
{
    m_progressBar->SetValue( 100 );
    m_progressBar->Hide();
    m_txtStatus->SetLabel( wxEmptyString );
    m_sdbSizerOK->Enable();
}


void DIALOG_RULE_CHECK_CONTROL::onEngineProgress( double aProgress, wxString aStatusMessage )
{
    m_progressBar->SetValue( 100 * aProgress );
    m_txtStatus->SetLabel( aStatusMessage );
}
