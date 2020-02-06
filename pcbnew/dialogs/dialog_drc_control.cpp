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

#include <bitmaps.h>
#include <dialogs/dialog_drc_control.h>
#include <pcb_edit_frame.h>
#include <tools/drc_manager.h>


DIALOG_DRC_CONTROL::DIALOG_DRC_CONTROL( DRC_MANAGER* aManager, PCB_EDIT_FRAME* aEditorFrame,
                                        wxWindow* aParent ) :
        DIALOG_RULE_CHECKER_CONTROL( aManager, aParent ), m_editFrame( aEditorFrame )
{
    SetName( DIALOG_DRC_WINDOW_NAME );
    SetTitle( _( "DRC Control" ) );

    m_btnBrowseReportPath->SetBitmap( KiBitmap( folder_xpm ) );

    // We use a sdbSizer here to get the order right, which is platform-dependent
    m_sdbSizerOK->SetLabel( _( "Run DRC" ) );
    m_sdbSizerCancel->SetLabel( _( "Close" ) );
    m_sizerButtons->Layout();

    m_sdbSizerOK->SetDefault();

    FinishDialogSettings();
}

DIALOG_DRC_CONTROL::~DIALOG_DRC_CONTROL()
{

}
