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
#include <id.h>
#include <sch_edit_frame.h>
#include <tools/ee_actions.h>
#include <tools/erc_manager.h>


ERC_MANAGER::ERC_MANAGER() : RULE_CHECK_MANAGER_BASE( "eeschema.ERCManager" ),
        m_schFrame( nullptr )
{
}


ERC_MANAGER::~ERC_MANAGER()
{
    if( m_engine )
        delete m_engine;
}


void ERC_MANAGER::Reset( RESET_REASON aReason )
{
    m_schFrame = getEditFrame<SCH_EDIT_FRAME>();
    m_engine = new ERC_ENGINE;
}


void ERC_MANAGER::createControlDialog( wxWindow* aParent )
{
    m_controlDialog = new DIALOG_ERC_CONTROL( this, m_schFrame, ID_DIALOG_ERC );
}


void ERC_MANAGER::setTransitions()
{
    if( ADVANCED_CFG::GetCfg().m_newErc )
        Go( &ERC_MANAGER::ShowControlDialog,    EE_ACTIONS::runERC.MakeEvent() );
}
