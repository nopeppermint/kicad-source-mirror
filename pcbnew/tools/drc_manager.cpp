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
#include <dialogs/dialog_drc_control.h>
#include <pcb_edit_frame.h>
#include <tools/pcb_actions.h>
#include <tools/drc_manager.h>


DRC_MANAGER::DRC_MANAGER() : RULE_CHECK_MANAGER_BASE( "pcbnew.DRCManager" ),
        m_pcbFrame( nullptr )
{
}


void DRC_MANAGER::Reset( RESET_REASON aReason )
{
    m_pcbFrame = getEditFrame<PCB_EDIT_FRAME>();
}


void DRC_MANAGER::createControlDialog( wxWindow* aParent )
{
    m_controlDialog = new DIALOG_DRC_CONTROL( this, m_pcbFrame, aParent );
}


void DRC_MANAGER::setTransitions()
{
    if( ADVANCED_CFG::GetCfg().m_newDrc )
        Go( &DRC_MANAGER::ShowControlDialog,    PCB_ACTIONS::runDRC.MakeEvent() );
}