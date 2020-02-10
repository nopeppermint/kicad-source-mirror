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

#include <drc/drc_violation.h>


std::string DRC_VIOLATION::GetTypeAsString( DRC_VIOLATION_TYPE aType )
{
    switch( aType )
    {
    case DRC_VIOLATION_TYPE::BOARD_EDGE:
        return _( "Board edge violations" ).ToStdString();

    case DRC_VIOLATION_TYPE::CLEARANCE:
        return _( "Clearance constraints" ).ToStdString();

    case DRC_VIOLATION_TYPE::COLLISION:
        return _( "Collisions" ).ToStdString();

    case DRC_VIOLATION_TYPE::DANGLING:
        return _( "Dangling items" ).ToStdString();

    case DRC_VIOLATION_TYPE::FOOTPRINT:
        return _( "Footprint violations" ).ToStdString();

    case DRC_VIOLATION_TYPE::KEEPOUT:
        return _( "Keepout constraints" ).ToStdString();

    case DRC_VIOLATION_TYPE::LENGTH:
        return _( "Length constraints" ).ToStdString();

    case DRC_VIOLATION_TYPE::OTHER:
        return _( "Other violations" ).ToStdString();

    case DRC_VIOLATION_TYPE::PADSTACK:
        return _( "Hole/via violations" ).ToStdString();

    case DRC_VIOLATION_TYPE::SHORT_CIRCUIT:
        return _( "Short circuit violations" ).ToStdString();

    case DRC_VIOLATION_TYPE::TRACK:
        return _( "Track violations" ).ToStdString();

    case DRC_VIOLATION_TYPE::UNCONNECTED:
        return _( "Unconnected items" ).ToStdString();

    case DRC_VIOLATION_TYPE::WIDTH:
        return _( "Width constraints" ).ToStdString();

    default:
        break;
    }

    return std::string();
}
