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

#ifndef KICAD_RULE_CHECK_ENGINE_H
#define KICAD_RULE_CHECK_ENGINE_H

#include <functional>
#include <wx/string.h>

/**
 * A rule checker (ERC or DRC) that is controlled and owned by a rule check manager.
 * Responsible for actually running the checks.
 */
class RULE_CHECK_ENGINE
{
public:
    RULE_CHECK_ENGINE() : m_should_abort( false )
    {
    }

    virtual ~RULE_CHECK_ENGINE() = default;

    virtual bool Start() = 0;

    void SetCallbacks( std::function<void(bool)> aFinishedCallback,
                       std::function<void(double, wxString)> aProgressCallback = {} )
    {
        m_finishedCallback = std::move( aFinishedCallback );
        m_progressCallback = std::move( aProgressCallback );
    }

    virtual void Abort() = 0;

    std::vector<VIOLATION*>& GetViolations() { return m_violations; }

protected:

    void reportProgress( double aProgress, const wxString& aMessage )
    {
        if( m_progressCallback )
            m_progressCallback( aProgress, aMessage );
    }

    /// Called when the rule check finishes.  Argument is true if no violations, false otherwise.
    std::function<void(bool)> m_finishedCallback;

    /// Called with the progress is updated.  Argument is progress as a ratio, and a status message
    std::function<void(double, wxString)> m_progressCallback;

    bool m_should_abort;

    std::vector<VIOLATION*> m_violations;
};

#endif
