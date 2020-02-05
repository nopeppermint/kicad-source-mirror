///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/gauge.h>
#include <wx/dataview.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_CHECKBOX_RPT_FILE 1000
#define ID_BUTTON_BROWSE_RPT_FILE 1001

///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_RULE_CHECKER_CONTROL_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_RULE_CHECKER_CONTROL_BASE : public DIALOG_SHIM
{
	private:

	protected:
		wxCheckBox* m_CreateRptCtrl;
		wxTextCtrl* m_RptFilenameCtrl;
		wxBitmapButton* m_btnBrowseReportPath;
		wxStaticText* m_txtStatus;
		wxGauge* m_progressBar;
		wxButton* m_btnSettings;
		wxDataViewTreeCtrl* m_dataView;
		wxBoxSizer* m_sizerButtons;
		wxButton* m_btnClearAll;
		wxCheckBox* m_cbCenter;
		wxCheckBox* m_cbZoom;
		wxCheckBox* m_cbHighlight;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void OnActivateDlg( wxActivateEvent& event ) { event.Skip(); }
		virtual void OnReportCheckBoxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReportFilenameEdited( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonBrowseRptFileClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEditDesignRules( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteAllClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartdrcClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		DIALOG_RULE_CHECKER_CONTROL_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("%s Control"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~DIALOG_RULE_CHECKER_CONTROL_BASE();

};

