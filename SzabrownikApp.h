/***************************************************************
 * Name:      SzabrownikApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2025-12-09
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SZABROWNIKAPP_H
#define SZABROWNIKAPP_H

#include <wx/app.h>

#undef _
#define _(s) wxString::FromUTF8 (s)

class SzabrownikApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SZABROWNIKAPP_H
