/***************************************************************
 * Name:      SzabrownikApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2025-12-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SzabrownikApp.h"

//(*AppHeaders
#include "SzabrownikMain.h"
#include <wx/image.h>
//*)

#undef _
#define _(s) wxString::FromUTF8 (s)

IMPLEMENT_APP(SzabrownikApp);

bool SzabrownikApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        SzabrownikFrame* Frame = new SzabrownikFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)

    return wxsOK;

}
