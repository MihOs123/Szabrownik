/***************************************************************
 * Name:      SzabrownikMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2025-12-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SzabrownikMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(SzabrownikFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8 (s)

#include <memory>
#include <vector>
#include "SzabrownikDwa.h"
#include <iostream>
#include <string>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SzabrownikFrame)
const wxWindowID SzabrownikFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT4 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT16 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT5 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT17 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT6 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT18 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT7 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT19 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT8 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT20 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT9 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT21 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT10 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT22 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT11 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT23 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICLINE3 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT24 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT25 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICBITMAP2 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT26 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT27 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICBITMAP3 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT12 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT15 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICBITMAP5 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICLINE1 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT28 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT29 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT30 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT31 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT32 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT33 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT34 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT35 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT36 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BITMAPBUTTON1 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON3 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON1 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT3 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICBITMAP1 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT13 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICTEXT14 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON2 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON7 = wxNewId();
const wxWindowID SzabrownikFrame::ID_PANEL1 = wxNewId();
const wxWindowID SzabrownikFrame::ID_STATICBITMAP4 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON4 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON5 = wxNewId();
const wxWindowID SzabrownikFrame::ID_BUTTON6 = wxNewId();
const wxWindowID SzabrownikFrame::ID_PANEL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SzabrownikFrame,wxFrame)
    //(*EventTable(SzabrownikFrame)
    //*)
END_EVENT_TABLE()

SzabrownikFrame::SzabrownikFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SzabrownikFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxGridSizer* GridSizer1;

    Create(parent, wxID_ANY, _("Szabrownik"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    panel_gra = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(400,175), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panel_gra->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(panel_gra, ID_STATICTEXT1, _("POSTAĆ"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5 = new wxFlexGridSizer(8, 2, 0, 0);
    StaticText4 = new wxStaticText(panel_gra, ID_STATICTEXT4, _("Mężność"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT4"));
    FlexGridSizer5->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(panel_gra, ID_STATICTEXT16, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer5->Add(StaticText15, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(panel_gra, ID_STATICTEXT5, _("Refleks"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
    FlexGridSizer5->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(panel_gra, ID_STATICTEXT17, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer5->Add(StaticText16, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(panel_gra, ID_STATICTEXT6, _("Wizualizacja"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT6"));
    FlexGridSizer5->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(panel_gra, ID_STATICTEXT18, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer5->Add(StaticText17, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(panel_gra, ID_STATICTEXT7, _("Inteligencja"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT7"));
    FlexGridSizer5->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText18 = new wxStaticText(panel_gra, ID_STATICTEXT19, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    FlexGridSizer5->Add(StaticText18, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(panel_gra, ID_STATICTEXT8, _("Charyzma"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT8"));
    FlexGridSizer5->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(panel_gra, ID_STATICTEXT20, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    FlexGridSizer5->Add(StaticText19, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(panel_gra, ID_STATICTEXT9, _("Wola"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT9"));
    FlexGridSizer5->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(panel_gra, ID_STATICTEXT21, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    FlexGridSizer5->Add(StaticText20, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(panel_gra, ID_STATICTEXT10, _("Duch"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT10"));
    FlexGridSizer5->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText21 = new wxStaticText(panel_gra, ID_STATICTEXT22, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    FlexGridSizer5->Add(StaticText21, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(panel_gra, ID_STATICTEXT11, _("Szczęście"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT11"));
    FlexGridSizer5->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    StaticText22 = new wxStaticText(panel_gra, ID_STATICTEXT23, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    FlexGridSizer5->Add(StaticText22, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine3 = new wxStaticLine(panel_gra, ID_STATICLINE3, wxDefaultPosition, wxSize(150,2), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    StaticLine3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    StaticLine3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    FlexGridSizer2->Add(StaticLine3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7 = new wxFlexGridSizer(3, 3, 0, 0);
    StaticText23 = new wxStaticText(panel_gra, ID_STATICTEXT24, _("ZŁOTO"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT24"));
    wxFont StaticText23Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText23->SetFont(StaticText23Font);
    FlexGridSizer7->Add(StaticText23, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText24 = new wxStaticText(panel_gra, ID_STATICTEXT25, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT25"));
    FlexGridSizer7->Add(StaticText24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap2 = new wxStaticBitmap(panel_gra, ID_STATICBITMAP2, wxBitmap(wxImage(_T("Moneta.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP2"));
    FlexGridSizer7->Add(StaticBitmap2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(panel_gra, ID_STATICTEXT26, _("ŻYCIE"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT26"));
    wxFont StaticText25Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText25->SetFont(StaticText25Font);
    FlexGridSizer7->Add(StaticText25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText26 = new wxStaticText(panel_gra, ID_STATICTEXT27, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT27"));
    FlexGridSizer7->Add(StaticText26, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap3 = new wxStaticBitmap(panel_gra, ID_STATICBITMAP3, wxBitmap(wxImage(_T("Serce.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP3"));
    FlexGridSizer7->Add(StaticBitmap3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(panel_gra, ID_STATICTEXT12, _("ZBROJA"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    wxFont StaticText12Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText12->SetFont(StaticText12Font);
    FlexGridSizer7->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText36 = new wxStaticText(panel_gra, ID_STATICTEXT15, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer7->Add(StaticText36, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap5 = new wxStaticBitmap(panel_gra, ID_STATICBITMAP5, wxBitmap(wxImage(_T("Tarcza.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP5"));
    FlexGridSizer7->Add(StaticBitmap5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(panel_gra, ID_STATICLINE1, wxDefaultPosition, wxSize(150,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer2->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText27 = new wxStaticText(panel_gra, ID_STATICTEXT28, _("EKWIPUNEK"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    wxFont StaticText27Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText27->SetFont(StaticText27Font);
    BoxSizer3->Add(StaticText27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText28 = new wxStaticText(panel_gra, ID_STATICTEXT29, _("Broń:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    FlexGridSizer8->Add(StaticText28, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText29 = new wxStaticText(panel_gra, ID_STATICTEXT30, _("Brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer8->Add(StaticText29, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText30 = new wxStaticText(panel_gra, ID_STATICTEXT31, _("Zbroja:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    FlexGridSizer8->Add(StaticText30, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText31 = new wxStaticText(panel_gra, ID_STATICTEXT32, _("Brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    FlexGridSizer8->Add(StaticText31, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText32 = new wxStaticText(panel_gra, ID_STATICTEXT33, _("Akcesorium:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    FlexGridSizer8->Add(StaticText32, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(panel_gra, ID_STATICTEXT34, _("Brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    FlexGridSizer8->Add(StaticText33, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText34 = new wxStaticText(panel_gra, ID_STATICTEXT35, _("Przedmiot:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    FlexGridSizer8->Add(StaticText34, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText35 = new wxStaticText(panel_gra, ID_STATICTEXT36, _("Brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    FlexGridSizer8->Add(StaticText35, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(panel_gra, ID_STATICTEXT2, _("LOCH | POZIOM 0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(20,wxFONTFAMILY_DECORATIVE,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Tempus Sans ITC"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1 = new wxGridSizer(7, 7, 0, 0);
    BitmapButton1 = new wxBitmapButton(panel_gra, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("Nieznany.png"))), wxDefaultPosition, wxSize(100,100), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetMinSize(wxSize(100,100));
    BitmapButton1->SetMaxSize(wxSize(100,100));
    BitmapButton1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    BitmapButton1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    GridSizer1->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    FlexGridSizer3->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    Button3 = new wxButton(panel_gra, ID_BUTTON3, _("Nowa Gra"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer6->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(panel_gra, ID_BUTTON1, _("Odkryj Mape"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(panel_gra, ID_STATICTEXT3, _("POKÓJ"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap1 = new wxStaticBitmap(panel_gra, ID_STATICBITMAP1, wxBitmap(wxImage(_T("Nieznany.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer4->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText13 = new wxStaticText(panel_gra, ID_STATICTEXT13, _("Zawartość"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer6->Add(StaticText13, 1, wxALL, 5);
    StaticText14 = new wxStaticText(panel_gra, ID_STATICTEXT14, _("Zawartosc2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer6->Add(StaticText14, 1, wxALL, 5);
    FlexGridSizer4->Add(FlexGridSizer6, 1, wxALL|wxEXPAND, 5);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    Button2 = new wxButton(panel_gra, ID_BUTTON2, _("Wejdź"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer7->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(panel_gra, ID_BUTTON7, _("Interakcja"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer7->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    panel_gra->SetSizer(FlexGridSizer1);
    BoxSizer1->Add(panel_gra, 1, wxALL, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxSize(50,50), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetMinSize(wxSize(500,-1));
    Panel2->Hide();
    Panel2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticBitmap4 = new wxStaticBitmap(Panel2, ID_STATICBITMAP4, wxBitmap(wxImage(_T("Tytul.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP4"));
    BoxSizer8->Add(StaticBitmap4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GUZIK_START = new wxButton(Panel2, ID_BUTTON4, _("START"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    GUZIK_START->SetMaxSize(wxSize(-1,500));
    GUZIK_START->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer8->Add(GUZIK_START, 1, wxALL|wxEXPAND, 5);
    GUZIK_CREDITS = new wxButton(Panel2, ID_BUTTON5, _("CREDITS"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    GUZIK_CREDITS->SetMaxSize(wxSize(-1,500));
    GUZIK_CREDITS->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer8->Add(GUZIK_CREDITS, 1, wxALL|wxEXPAND, 5);
    GUZIK_WYJSCIE = new wxButton(Panel2, ID_BUTTON6, _("WYJŚCIE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    GUZIK_WYJSCIE->SetMaxSize(wxSize(-1,500));
    GUZIK_WYJSCIE->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    BoxSizer8->Add(GUZIK_WYJSCIE, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer8);
    BoxSizer1->Add(Panel2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BITMAPBUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnBitmapButton1Click);
    Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnButton3Click);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnButton1Click);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnButton2Click);
    Connect(ID_BUTTON7, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnButtonInterakcjaClick);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnButton4Click);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnGUZIK_CREDITSClick);
    Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnGUZIK_WYJSCIEClick);
    //*)

    /*Pola[] zawierają w sobie wxWidgetowe id danego pola, są od 0 do 48*/
    pola[0] = BitmapButton1;
    for(int i=1; i<49; i++){
        pola [i] = new wxBitmapButton(panel_gra, wxNewId(), wxBitmap(wxImage(_T("Nieznany.png"))), wxDefaultPosition, wxSize(100,100), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
        Connect(pola [i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SzabrownikFrame::OnBitmapButton1Click);
        GridSizer1->Add(pola [i], 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    }
        for (int i = 0; i<49; i++){
            numer[pola[i]->GetId()] = i;
        }

    srand(time(0));

    /*Listapokoi to jest wektor*/
    listapokoi = generacjaPokoi(49, PoziomLochu);
    /*lista pokoi 1 ==== pola[0]*/
    /*doslownie chyba nawet to nie prawda*/

    panel_gra -> Show(false);//ukrycie gierki
    Panel2 -> Show(true);//wyswietla sie menu
    Layout();

    Button2->Enable(false);

    Bind(wxEVT_CHAR_HOOK, &SzabrownikFrame::KluczLapacz, this);


}



SzabrownikFrame::~SzabrownikFrame()
{
    //(*Destroy(SzabrownikFrame)
    //*)
}

void SzabrownikFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SzabrownikFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SzabrownikFrame::OnBitmapButton1Click(wxCommandEvent& event)
{
    /*funckja co sie aktywuje gdy klikasz na pokoj*/
    KlikPoleFunkcja(numer[event.GetId()]);
}


void SzabrownikFrame::OnButton2Click(wxCommandEvent& event)
{
    int a = Bohater.KliknietyPokoj;
    Bohater.AktualnyPokoj = a;
    KlikPoleFunkcja(Bohater.AktualnyPokoj);
    OdkrywaczPokoi(a);
}

void SzabrownikFrame::OnButton1Click(wxCommandEvent& event)
{
    /*żeby były polskie znaki robisz tak:  _("")*/
    /*Ten przycisk sluzy do odkrycia calej planszy*/

    for(int i = 0; i < 49; i++){
        if(i == Bohater.AktualnyPokoj){
            pola[i]->SetBitmap(wxImage(listapokoi[i].ObrazGr));
        }
        else{
        pola[i]->SetBitmap(wxImage(listapokoi[i].Obraz));
        }
        listapokoi[i].Odkryty = true;
    }
}


void SzabrownikFrame::OnButton3Click(wxCommandEvent& event)
{
    /*Guzik start gry*/
    GuzikStartGryFunkcja();
    ZapisWyniku();
}


void SzabrownikFrame::OnButtonInterakcjaClick(wxCommandEvent& event)
{
    InterakcjaZPolem();
}


//guziki z menu//////////////////////////////////////////////////////
void SzabrownikFrame::OnButton4Click(wxCommandEvent& event)//guzik startowy chowa menu odpala gre
{
    Panel2 -> Show(false);
    panel_gra -> Show(true);
    Layout();
    GuzikStartGryFunkcja();
    panel_gra->SetMinSize(wxSize(1450, -1));
    this -> Layout();
    this->Fit();
    this->Centre();

}

void SzabrownikFrame::OnGUZIK_WYJSCIEClick(wxCommandEvent& event)

{
    Close();
}

void SzabrownikFrame::OnGUZIK_CREDITSClick(wxCommandEvent& event)

{
         // 1. Ukryj bieżące okno (SzabrownikFrame)
    this->Hide();

    // 2. Jeśli TestFrame już istnieje, pokaż je
    if (m_test)
    {
        m_test->Show();
        m_test->Raise(); // Przenieś na wierzch
        m_test->SetFocus(); // Ustaw fokus
    }
    else
    {
        // 3. Jeśli nie istnieje, utwórz nowe okno
        m_test = new Test(this); // Przekazujemy this jako parent

        // Ustaw rozmiar i pozycję (opcjonalnie)
        m_test->SetSize(this->GetSize());
        m_test->SetPosition(this->GetPosition());

        m_test->Show();
    }

     /*wxMessageBox("Autor: Kostek i Koziol \nWersja: 0.1", _("O Twórcach"), wxOK | wxICON_INFORMATION);*/
}

void SzabrownikFrame::OnPanel2Paint(wxPaintEvent& event)
{
}


