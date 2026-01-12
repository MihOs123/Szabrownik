#include "Test.h"

//(*InternalHeaders(Test)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Test)
const wxWindowID Test::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Test,wxFrame)
    //(*EventTable(Test)
    //*)
END_EVENT_TABLE()

Test::Test(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(Test)
    wxBoxSizer* BoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    RWAAAAAA = new wxStaticText(this, ID_STATICTEXT1, _("RWAAAAA"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(RWAAAAAA, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);
    //*)
}

Test::~Test()
{
    //(*Destroy(Test)
    //*)
}

