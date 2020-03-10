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
class ERC_HTML_LISTFRAME;

#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/html/htmlwin.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_ERASE_DRC_MARKERS 1000
#define ID_RESET_MATRIX 1001

///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_ERC_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_ERC_BASE : public DIALOG_SHIM
{
	private:

	protected:
		wxNotebook* m_NoteBook;
		wxPanel* m_PanelERC;
		wxStaticText* m_ErcTotalErrorsText;
		wxTextCtrl* m_TotalErrCount;
		wxStaticText* m_WarnErcErrorsText;
		wxTextCtrl* m_LastWarningCount;
		wxStaticText* m_LastErrCountText;
		wxTextCtrl* m_LastErrCount;
		wxStaticText* m_titleMessages;
		wxTextCtrl* m_MessagesList;
		wxStaticText* m_textMarkers;
		ERC_HTML_LISTFRAME* m_MarkersList;
		wxPanel* m_PanelERCOptions;
		wxPanel* m_matrixPanel;
		wxBoxSizer* m_buttonsSizer;
		wxButton* m_buttondelmarkers;
		wxButton* m_ResetOptButton;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseErcDialog( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnLeftClickMarkersList( wxHtmlLinkEvent& event ) { event.Skip(); }
		virtual void OnLeftDblClickMarkersList( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnEraseDrcMarkersClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetMatrixClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnErcCmpClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		DIALOG_ERC_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Electrical Rules Checker"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~DIALOG_ERC_BASE();

};

