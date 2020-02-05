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

#ifndef KICAD_DIALOG_DRC_CONTROL_H
#define KICAD_DIALOG_DRC_CONTROL_H

#include <dialogs/dialog_rule_checker_control_base.h>

#define DIALOG_DRC_WINDOW_NAME "DialogDrcWindowName"

class DRC_MANAGER;
class PCB_EDIT_FRAME;


class DIALOG_DRC_CONTROL : public DIALOG_RULE_CHECKER_CONTROL_BASE
{
public:
    DIALOG_DRC_CONTROL( DRC_MANAGER* aManager, PCB_EDIT_FRAME* aEditorFrame, wxWindow* aParent );

    ~DIALOG_DRC_CONTROL();

private:
    DRC_MANAGER*        m_drcManager;

    PCB_EDIT_FRAME*     m_editFrame;
};

#endif
