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

#include <erc/erc_violation.h>


wxString ERC_VIOLATION::GetTypeAsString( ERC_VIOLATION_TYPE aType )
{
    switch( aType )
    {
    case ERC_VIOLATION_TYPE::BUS_NET_CONFLICT:
        return _( "Bus to net conflict" );
#if 0
    case ERC_VIOLATION_TYPE::CONNECTION:
        return _( "Connection violations" ).ToStdString();

    case ERC_VIOLATION_TYPE::DANGLING:
        return _( "Unconnected items" ).ToStdString();

    case ERC_VIOLATION_TYPE::LABEL:
        return _( "Label violations" ).ToStdString();

    case ERC_VIOLATION_TYPE::PIN:
        return _( "Pin-to-pin violations" ).ToStdString();

    case ERC_VIOLATION_TYPE::SHEET:
        return _( "Hierarchical sheet violations" ).ToStdString();

    case ERC_VIOLATION_TYPE::SYMBOL:
        return _( "Symbol violations" ).ToStdString();
#endif
    default:
        break;
    }

    return wxEmptyString;
}
