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

#ifndef KICAD_ERC_VIOLATION_H
#define KICAD_ERC_VIOLATION_H

#include <violation_base.h>


/**
 * Defines the types of ERC violations, each of which is a subclass of ERC_VIOLATION
 */
enum class ERC_VIOLATION_TYPE
{
    BUS_NET_CONFLICT,    ///< A bus and net are graphically connected but don't match each other
#if 0
    CONNECTION,     ///< Issues relating to connectivity issues other than pin-to-pin
    DANGLING,       ///< Single-pin net, wire to nowhere, etc
    LABEL,          ///< Issues relating to local, global, and hierarchical labels
    PIN,            ///< Issues relating to pin types (i.e. no driver, etc)
    SHEET,          ///< Issues relating to hierarchical sheets
    SYMBOL,         ///< Issues relating to schematic symbols
#endif
};


class ERC_VIOLATION : public VIOLATION
{
public:
    ERC_VIOLATION( ERC_VIOLATION_TYPE aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
            const VECTOR2I& aFirstPosition, EDA_ITEM* aSecondItem, const VECTOR2I& aSecondPosition,
            const wxString& aDescription, const wxString& aHelp = wxEmptyString ) :
            VIOLATION( static_cast<int>( aType ), aUnits, aFirstItem, aFirstPosition,
                       aSecondItem, aSecondPosition ), m_description( aDescription ),
                       m_helpText( aHelp )
    {}

    ERC_VIOLATION( ERC_VIOLATION_TYPE aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
            const VECTOR2I& aFirstPosition, const wxString& aDescription,
            const wxString& aHelp = wxEmptyString ) :
            VIOLATION( static_cast<int>( aType ), aUnits, aFirstItem, aFirstPosition ),
                    m_description( aDescription ), m_helpText( aHelp )
    {}

    virtual ~ERC_VIOLATION() {}

    wxString GetTitle() override
    {
        return GetTypeAsString( static_cast<ERC_VIOLATION_TYPE>( m_type ) );
    }

    static wxString GetTypeAsString( ERC_VIOLATION_TYPE aType );

    wxString GetDescription() override
    {
        return m_description;
    }

    wxString GetHelpText() override
    {
        return m_helpText;
    }

private:

    wxString m_description;

    wxString m_helpText;
};


class BUS_NET_CONFLICT_VIOLATION : public ERC_VIOLATION
{
public:
    BUS_NET_CONFLICT_VIOLATION( EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
            const VECTOR2I& aFirstPosition, EDA_ITEM* aSecondItem, const VECTOR2I& aSecondPosition,
            const wxString& aDescription, const wxString& aHelpText = wxEmptyString ) :
            ERC_VIOLATION( ERC_VIOLATION_TYPE::BUS_NET_CONFLICT, aUnits, aFirstItem, aFirstPosition,
                    aSecondItem, aSecondPosition, aDescription, aHelpText )
    {}

    virtual ~BUS_NET_CONFLICT_VIOLATION() = default;

};

#endif
