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
 * Defines the basic types of ERC violations.  This is mostly used for grouping violations into
 * categories in the UI, and allowing users to quickly ignore/skip entire classes of violation.
 */
enum class ERC_VIOLATION_TYPE
{
    BUS,            ///< Issues related to buses
    CONNECTION,     ///< Issues relating to connectivity issues other than pin-to-pin
    DANGLING,       ///< Single-pin net, wire to nowhere, etc
    LABEL,          ///< Issues relating to local, global, and hierarchical labels
    PIN,            ///< Issues relating to pin types (i.e. no driver, etc)
    SHEET,          ///< Issues relating to hierarchical sheets
    SYMBOL,         ///< Issues relating to schematic symbols
};


class ERC_VIOLATION : public VIOLATION
{
public:
    ERC_VIOLATION( ERC_VIOLATION_TYPE aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
                   EDA_ITEM* aSecondItem, VECTOR2I aFirstPosition, VECTOR2I aSecondPosition ) :
            VIOLATION( static_cast<int>( aType ), aUnits, aFirstItem, aFirstPosition,
                       aSecondItem, aSecondPosition )
    {}

    ERC_VIOLATION( ERC_VIOLATION_TYPE aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
                   VECTOR2I aFirstPosition ) :
            VIOLATION( static_cast<int>( aType ), aUnits, aFirstItem, aFirstPosition )
    {}

    virtual ~ERC_VIOLATION() {}

    static std::string GetTypeAsString( ERC_VIOLATION_TYPE aType );
};

#endif
