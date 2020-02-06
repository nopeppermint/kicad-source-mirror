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

#include <dialogs/dialog_rule_checker_control.h>
#include <tool/rule_check_manager.h>
#include <wx/wx.h>


DIALOG_RULE_CHECKER_CONTROL::DIALOG_RULE_CHECKER_CONTROL( RULE_CHECK_MANAGER_BASE* aManager,
                                                          wxWindow* aParent ) :
        DIALOG_RULE_CHECKER_CONTROL_BASE( aParent ),
        m_manager( aManager )
{
}


void DIALOG_RULE_CHECKER_CONTROL::OnReportCheckBoxClicked( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECKER_CONTROL::OnButtonBrowseReportPathClick( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECKER_CONTROL::OnButtonEditDesignRules( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECKER_CONTROL::OnDeleteAllClick( wxCommandEvent& event )
{
}


void DIALOG_RULE_CHECKER_CONTROL::OnCloseClick( wxCommandEvent& event )
{
}

void DIALOG_RULE_CHECKER_CONTROL::OnStartChecksClick( wxCommandEvent& event )
{
}