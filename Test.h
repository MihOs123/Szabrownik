#ifndef TEST_H
#define TEST_H

//(*Headers(Test)
#include <wx/frame.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class Test: public wxFrame
{
    public:

        Test(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~Test();

        //(*Declarations(Test)
        wxStaticText* RWAAAAAA;
        //*)

    protected:

        //(*Identifiers(Test)
        static const wxWindowID ID_STATICTEXT1;
        //*)

    private:

        //(*Handlers(Test)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
