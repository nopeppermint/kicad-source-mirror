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

#ifndef KICAD_RULE_CHECK_MANAGER_H
#define KICAD_RULE_CHECK_MANAGER_H

#include <tool/tool_interactive.h>

class DIALOG_RULE_CHECKER_CONTROL_BASE;


class RULE_CHECK_MANAGER_BASE : public TOOL_INTERACTIVE
{
public:
    RULE_CHECK_MANAGER_BASE( const std::string& aName );

    virtual ~RULE_CHECK_MANAGER_BASE() {}

    /// @copydoc TOOL_INTERACTIVE::Reset()
    void Reset( RESET_REASON aReason ) override;

    void ShowControlDialog( wxWindow* aParent );

    int ShowControlDialog( const TOOL_EVENT& aEvent )
    {
        ShowControlDialog( nullptr );
        return 0;
    }

    /**
     * Deletes this ui dialog box and zeros out its pointer to remember
     * the state of the dialog's existence.
     *
     * @param aReason Indication of which button was clicked to cause the destruction.
     * if aReason == wxID_OK, design parameters values which can be entered from the dialog
     * will bbe saved in design parameters list
     */
    void DestroyDRCDialog( int aReason );

protected:
    DIALOG_RULE_CHECKER_CONTROL_BASE* m_controlDialog;

    ///> Sets up handlers for various events.
    void setTransitions() override {}

    virtual void createControlDialog( wxWindow* aParent ) = 0;
};

#endif
