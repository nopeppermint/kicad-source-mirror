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

#ifndef KICAD_DIALOG_RULE_CHECK_CONTROL_H
#define KICAD_DIALOG_RULE_CHECK_CONTROL_H

#include <dialogs/dialog_rule_check_control_base.h>

class RULE_CHECK_MANAGER_BASE;
class wxWindow;


/**
 * This dialog is the generic rule checker (DRC/ERC) control UI.
 * It is derived in PcbNew and Eeschema to add some specific functionality.
 */
class DIALOG_RULE_CHECK_CONTROL : public DIALOG_RULE_CHECK_CONTROL_BASE
{
public:
    DIALOG_RULE_CHECK_CONTROL(
            RULE_CHECK_MANAGER_BASE* aManager, wxWindow* aParent,
                                 wxWindowID aId = wxID_ANY );

    virtual ~DIALOG_RULE_CHECK_CONTROL() {}

    bool TransferDataToWindow() override;

    bool TransferDataFromWindow() override;

    virtual void OnEngineFinished( bool aChecksPassed );

    virtual void OnEngineProgress( double aProgress, wxString aStatusMessage );

protected:
    virtual void OnReportCheckBoxClicked( wxCommandEvent& event ) override;

    virtual void OnButtonBrowseReportPathClick( wxCommandEvent& event ) override;

    virtual void OnButtonEditDesignRules( wxCommandEvent& event ) override;

    virtual void OnDeleteAllClick( wxCommandEvent& event ) override;

    virtual void OnCloseClick( wxCommandEvent& event ) override;

    virtual void OnStartChecksClick( wxCommandEvent& event ) override;

protected:
    /// Handler to the manager that spawned this dialog
    RULE_CHECK_MANAGER_BASE* m_manager;
};


#endif
