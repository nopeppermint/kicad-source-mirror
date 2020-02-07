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

#ifndef KICAD_DRC_VIOLATION_H
#define KICAD_DRC_VIOLATION_H

#include <violation_base.h>


/**
 * Defines the basic types of DRC violations.  This is mostly used for grouping violations into
 * categories in the UI, and allowing users to quickly ignore/skip entire classes of violation.
 */
enum class DRC_VIOLATION_TYPE
{
    BOARD_EDGE,     ///< An item crosses or is outside the board edge
    CLEARANCE,      ///< A violation of any clearance rule
    COLLISION,      ///< A collision (overlap) between two footprints
    DANGLING,       ///< Dangling copper (tracks or vias)
    FOOTPRINT,      ///< An issue with a footprint (missing courtyard, etc)
    KEEPOUT,        ///< Violation of a keepout constraint
    LENGTH,         ///< Violation of a length constraint (including matched-length pairs)
    OTHER,          ///< Any violations that don't fit the other categories
    PADSTACK,       ///< Violation of via/hole constraints (drill and antipad sizes, etc)
    SHORT,          ///< A short between copper items of different nets
    TRACK,          ///< Issues with a track segment (track in pad, zero length track, etc)
    UNCONNECTED,    ///< Missing connection between parts of a net
    WIDTH,          ///< Violation of a width constraint
};


class DRC_VIOLATION : public VIOLATION
{
public:
    DRC_VIOLATION( DRC_VIOLATION_TYPE aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
                   EDA_ITEM* aSecondItem, VECTOR2I aFirstPosition, VECTOR2I aSecondPosition ) :
            VIOLATION( static_cast<int>( aType ), aUnits, aFirstItem, aFirstPosition,
                       aSecondItem, aSecondPosition )
    {}

    DRC_VIOLATION( DRC_VIOLATION_TYPE aType, EDA_UNITS aUnits, EDA_ITEM* aFirstItem,
                   VECTOR2I aFirstPosition ) :
            VIOLATION( static_cast<int>( aType ), aUnits, aFirstItem, aFirstPosition )
    {}

    virtual ~DRC_VIOLATION() {}

    static std::string GetTypeAsString( DRC_VIOLATION_TYPE aType );
};

#endif
