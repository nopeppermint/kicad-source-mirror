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

#ifndef KICAD_ERC_MANAGER_H
#define KICAD_ERC_MANAGER_H

#include <tool/rule_check_manager.h>

class ERC_ENGINE;
class SCH_EDIT_FRAME;
class wxWindow;


class ERC_MANAGER : public RULE_CHECK_MANAGER_BASE
{
public:
    ERC_MANAGER();

    virtual ~ERC_MANAGER();

    /// @copydoc TOOL_INTERACTIVE::Reset()
    void Reset( RESET_REASON aReason ) override;

    bool RunChecks() override;

    void ClearViolations() override;

private:
    void createControlDialog( wxWindow* aParent ) override;

    void setTransitions() override;

    SCH_EDIT_FRAME* m_schFrame;
};

#endif
