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

class DIALOG_RULE_CHECK_CONTROL;
class RULE_CHECK_ENGINE;
class VIOLATION;


extern const wxChar* ruleTrace;


class RULE_CHECK_MANAGER_BASE : public TOOL_INTERACTIVE
{
public:
    RULE_CHECK_MANAGER_BASE( const std::string& aName );

    virtual ~RULE_CHECK_MANAGER_BASE() {}

    void ShowControlDialog( wxWindow* aParent );

    int ShowControlDialog( const TOOL_EVENT& aEvent )
    {
        ShowControlDialog( nullptr );
        return 0;
    }

    /**
     * Deletes this control dialog and zeros out its pointer to remember
     * the state of the dialog's existence.
     */
    void DestroyControlDialog();

    /**
     * Clears all current violations and starts the rule checker engine
     * @return true if the engine was started, false otherwise (maybe already running?)
     */
    virtual bool RunChecks();

    /**
     * Checks if a rule checker engine is running in a background thread
     * @return true if the rule checker engine is currently running (in a background thread)
     */
    bool IsRunning();

    /**
     * Stops a running checker engine.  Has no effect if the engine is not running.
     */
    void AbortChecks();

    /**
     * Retrieves the progress of a running checker engine.
     * @return a ratio of progress (0.0 - 1.0) if running, or 1.0 if not running
     */
    double GetProgress();

    /**
     * Clears the violations list and cleans up (i.e. removes the links to the EDA_ITEMS referenced
     * in the violation).  All violation pointers held after this call are invalidated.
     */
    virtual void ClearViolations();

    /**
     * Updates the ignored state of a given violation
     * @param aViolation is a pointer to a validation to mark as ignored
     * @param aIgnore chooses whether to set (true) or clear (false) the ignore state
     */
    void Ignore( VIOLATION* aViolation, bool aIgnore = true );

    /**
     * Updates the ignored state of all violations of a given type
     * @param aViolationType is the type (typically cast fron an enum of derived class)
     * @param aIgnore chooses whether to set (true) or clear (false) the ignore state
     */
    void Ignore( int aViolationType, bool aIgnore = true );

    std::vector<VIOLATION*>& GetViolations()
    {
        return m_violations;
    }

    template <typename EngineType = RULE_CHECK_ENGINE>
    EngineType* GetEngine()
    {
        return static_cast<EngineType*>( m_engine );
    }

protected:
    DIALOG_RULE_CHECK_CONTROL* m_controlDialog;

    RULE_CHECK_ENGINE* m_engine;

    /// Violations are owned here
    std::vector<VIOLATION*> m_violations;

    /// Sets up handlers for various events.
    void setTransitions() override {}

    /// Overridden in derived classes to construct an appropriate control dialog
    virtual void createControlDialog( wxWindow* aParent ) = 0;

    /// Can be overridden to add some logic to RunChecks() before the engine starts
    virtual void onRunChecks() {}

    /// Can be overridden to add some logic after the checker completes (callback)
    virtual void onChecksCompleted() {}
};

#endif
