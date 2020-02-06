///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_rule_checker_control_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_RULE_CHECKER_CONTROL_BASE::DIALOG_RULE_CHECKER_CONTROL_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* m_MainSizer;
	m_MainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_CreateRptCtrl = new wxCheckBox( this, ID_CHECKBOX_RPT_FILE, _("Create report file:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CreateRptCtrl->SetToolTip( _("Enable writing report to this file") );

	bSizer12->Add( m_CreateRptCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxLEFT|wxRIGHT, 5 );

	m_RptFilenameCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_RptFilenameCtrl->SetToolTip( _("Enter the report filename") );

	bSizer12->Add( m_RptFilenameCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_btnBrowseReportPath = new wxBitmapButton( this, ID_BUTTON_BROWSE_RPT_FILE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	m_btnBrowseReportPath->SetMinSize( wxSize( 30,28 ) );

	bSizer12->Add( m_btnBrowseReportPath, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	m_MainSizer->Add( bSizer12, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_txtStatus = new wxStaticText( this, wxID_ANY, _("Reticulating splines..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtStatus->Wrap( -1 );
	bSizer11->Add( m_txtStatus, 0, wxLEFT|wxRIGHT|wxTOP, 5 );


	m_MainSizer->Add( bSizer11, 0, wxEXPAND|wxLEFT, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_progressBar = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,-1 ), wxGA_HORIZONTAL );
	m_progressBar->SetValue( 0 );
	bSizer8->Add( m_progressBar, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

	m_btnSettings = new wxButton( this, wxID_ANY, _("&Edit design rules..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnSettings, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	m_MainSizer->Add( bSizer8, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_dataView = new wxDataViewTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,300 ), 0 );
	m_dataView->SetMinSize( wxSize( -1,100 ) );

	bSizer9->Add( m_dataView, 1, wxALL|wxEXPAND, 5 );


	m_MainSizer->Add( bSizer9, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_sizerButtons = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_btnClearAll = new wxButton( this, wxID_ANY, _("Clear all &violations"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_btnClearAll, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_cbCenter = new wxCheckBox( this, wxID_ANY, _("Ce&nter on items"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_cbCenter, 0, wxALL, 5 );

	m_cbZoom = new wxCheckBox( this, wxID_ANY, _("&Zoom to fit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_cbZoom, 0, wxALL, 5 );

	m_cbHighlight = new wxCheckBox( this, wxID_ANY, _("&Highlight items"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_cbHighlight, 0, wxALL, 5 );


	m_sizerButtons->Add( bSizer10, 1, wxEXPAND|wxLEFT, 5 );

	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();

	m_sizerButtons->Add( m_sdbSizer, 1, wxEXPAND, 5 );


	m_MainSizer->Add( m_sizerButtons, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( m_MainSizer );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnActivateDlg ) );
	m_CreateRptCtrl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnReportCheckBoxClicked ), NULL, this );
	m_RptFilenameCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnReportFilenameEdited ), NULL, this );
	m_btnBrowseReportPath->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnButtonBrowseRptFileClick ), NULL, this );
	m_btnSettings->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnButtonEditDesignRules ), NULL, this );
	m_btnClearAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnDeleteAllClick ), NULL, this );
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnCancelClick ), NULL, this );
	m_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnStartdrcClick ), NULL, this );
}

DIALOG_RULE_CHECKER_CONTROL_BASE::~DIALOG_RULE_CHECKER_CONTROL_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnActivateDlg ) );
	m_CreateRptCtrl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnReportCheckBoxClicked ), NULL, this );
	m_RptFilenameCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnReportFilenameEdited ), NULL, this );
	m_btnBrowseReportPath->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnButtonBrowseRptFileClick ), NULL, this );
	m_btnSettings->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnButtonEditDesignRules ), NULL, this );
	m_btnClearAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnDeleteAllClick ), NULL, this );
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnCancelClick ), NULL, this );
	m_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_RULE_CHECKER_CONTROL_BASE::OnStartdrcClick ), NULL, this );

}
