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

#ifndef KICAD_DIALOG_ERC_CONTROL_H
#define KICAD_DIALOG_ERC_CONTROL_H

#include <dialogs/dialog_rule_check_control.h>

class ERC_MANAGER;
class SCH_EDIT_FRAME;


class DIALOG_ERC_CONTROL : public DIALOG_RULE_CHECK_CONTROL
{
public:
    DIALOG_ERC_CONTROL( ERC_MANAGER* aManager, SCH_EDIT_FRAME* aEditorFrame, wxWindowID aId );

    ~DIALOG_ERC_CONTROL();

private:
    SCH_EDIT_FRAME* m_editFrame;
};

#endif
