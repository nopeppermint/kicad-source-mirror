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

#ifndef KICAD_VIOLATION_BASE_H
#define KICAD_VIOLATION_BASE_H

#include <common.h>
#include <math/vector2d.h>

class EDA_ITEM;

/**
 * Represents a rule checker (ERC / DRC) violation.
 * This stores the metadata about the violation and has no graphical representation.
 */
class VIOLATION
{
public:
    /**
     * Encodes the severity of a violation, for display purposes.
     */
    enum class SEVERITY
    {
        INFO,
        WARN,
        ERR
    };

    VIOLATION( int aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem, const VECTOR2I& aFirstPosition,
               EDA_ITEM* aSecondItem, const VECTOR2I& aSecondPosition ) :
            m_type( aType ), m_units( aUnits ), m_firstItem( aFirstItem ),
            m_firstPosition( aFirstPosition ), m_secondItem( aSecondItem ),
            m_secondPosition( aSecondPosition )
    {}

    VIOLATION( int aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem, const VECTOR2I& aFirstPosition ) :
            m_type( aType ), m_units( aUnits ), m_firstItem( aFirstItem ),
            m_firstPosition( aFirstPosition ), m_secondItem( nullptr ), m_secondPosition()
    {}

    virtual ~VIOLATION() {}

    SEVERITY GetSeverity() { return m_severity; }

    /// Returns the violation title: a short string used to display the violation in a list
    virtual wxString GetTitle() = 0;

    /// Returns the violation description: a longer text that explains the violation in detail
    virtual wxString GetDescription() = 0;

    /**
     * Returns some extra text that can be displayed in the UI in addition to the description.
     * The purpose of this optional extra text is to provide suggestions or hints to the user
     * about how to resolve this violation.
     *
     * @return help text, or empty string if not overridden
     */
    virtual wxString GetHelpText() { return wxEmptyString; };

    EDA_ITEM* FirstItem() { return m_firstItem; }

    VECTOR2D FirstPosition() { return m_firstPosition; }

    EDA_ITEM* SecondItem() { return m_secondItem; }

    VECTOR2D SecondPosition() { return m_secondPosition; }

protected:

    /// Stores the type of violation, normally represented by enums in derived classes
    int m_type;

    /// The severity class of this violation (can be set by the user per violation type)
    SEVERITY m_severity;

    /// Units of the position (and any other distance measurements stored in derived classes)
    EDA_UNITS m_units;

    /// The first (or only) linked item to this violation
    EDA_ITEM* m_firstItem;

    /// The position (in world space) of the violation's first "point of interest"
    VECTOR2D m_firstPosition;

    /// The second linked item, or nullptr for unary violations
    EDA_ITEM* m_secondItem;

    /// The position (in world space) of the violation's second "point of interest", if relevant
    VECTOR2D m_secondPosition;
};

#endif
