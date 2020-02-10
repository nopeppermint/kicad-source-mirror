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

#include <dialogs/dialog_rule_check_control.h>
#include <rule_check_engine.h>
#include <tool/rule_check_manager.h>
#include <violation_base.h>

/**
 * Trace mask for debugging the rule checker system
 * @ingroup trace_env_vars
 */
const wxChar* ruleTrace = wxT( "RULE_CHECK" );


RULE_CHECK_MANAGER_BASE::RULE_CHECK_MANAGER_BASE( const std::string& aName ) :
        TOOL_INTERACTIVE( aName ),
        m_controlDialog(), m_engine()
{
}


void RULE_CHECK_MANAGER_BASE::ShowControlDialog( wxWindow* aParent )
{
    if( !m_controlDialog )
        createControlDialog( aParent );

    m_controlDialog->Show( true );
}


void RULE_CHECK_MANAGER_BASE::DestroyControlDialog()
{
}


bool RULE_CHECK_MANAGER_BASE::RunChecks()
{
    ClearViolations();
    return m_engine->Start();
}


bool RULE_CHECK_MANAGER_BASE::IsRunning()
{
    return false;
}


void RULE_CHECK_MANAGER_BASE::AbortChecks()
{
}


double RULE_CHECK_MANAGER_BASE::GetProgress()
{
    return 1.0;
}


void RULE_CHECK_MANAGER_BASE::ClearViolations()
{
    for( auto violation : m_engine->GetViolations() )
    {
        violation->FirstItem()->ClearViolations();

        if( violation->SecondItem() )
            violation->SecondItem()->ClearViolations();

        delete violation;
    }

    m_engine->GetViolations().clear();
}


void RULE_CHECK_MANAGER_BASE::Ignore( VIOLATION* aViolation, bool aIgnore )
{
}


void RULE_CHECK_MANAGER_BASE::Ignore( int aViolationType, bool aIgnore )
{
}