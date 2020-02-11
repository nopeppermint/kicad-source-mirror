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

#ifndef KICAD_ERC_ENGINE_H
#define KICAD_ERC_ENGINE_H

#include <future>

#include <rule_check_engine.h>

class ERC_VIOLATION;
class SCH_EDIT_FRAME;


class ERC_ENGINE : public RULE_CHECK_ENGINE
{
public:
    ERC_ENGINE() :
            RULE_CHECK_ENGINE(), m_frame( nullptr )
    {
    }

    virtual ~ERC_ENGINE() = default;

    bool Start() override;

    void WaitForFinish();

    void Abort() override;

    void SetEditFrame( SCH_EDIT_FRAME* aFrame )
    {
        m_frame = aFrame;
    }

private:

    void run();

    // This is temporary for testing the higher-level plumbing.
    // Where to store checks, etc. needs another architecture pass later.
    bool checkBusToNetConflicts();

    SCH_EDIT_FRAME* m_frame;

    std::future<void> m_runner_future;
};


#endif
