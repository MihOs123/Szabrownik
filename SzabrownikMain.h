/***************************************************************
 * Name:      SzabrownikMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2025-12-09
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SZABROWNIKMAIN_H
#define SZABROWNIKMAIN_H
#include <map>
#include <vector>

//(*Headers(SzabrownikFrame)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

#undef _
#define _(s) wxString::FromUTF8 (s)

class Szabrownik
{
    public:
        std::string Imie;
        int MEZ;
        int REF;
        int WIZ;
        int INT;
        int CHR;
        int WOLA;
        int DUCH;
        int SZCZ;
        int Zloto = 0;
        int Zdrowie;
        int MAXZdrowie;
        int AktualnyPokoj = -1;
        int KliknietyPokoj;
        int PzLochu;

        void WylosujStaty();

};

class Pokoj
{
    public:
        int Zawartosc; /*1 - nic, 2 - blok, 3 - potwor, 4 - skarb 5 - odpoczynek, 6 - pulapka, 7 - zejscie nizej*/
        bool Odkryty;
        bool Sasiad;
        std::string Obraz;
        std::string ObrazGr; /*Obraz pola gdy jest w nim gracz*/
        std::string ObrazK; /*Obraz pola gdy jest zaznaczone*/
        std::string ObrazGrK;
        int SilaPotwora;
        int PzLochu;

        Pokoj(int narzuconyTyp, int pziom);
};



class SzabrownikFrame: public wxFrame
{
    public:
        SzabrownikFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SzabrownikFrame();

        int PoziomLochu = 0;
        std::map<int, int> numer;
        wxBitmapButton * pola[49];
        std::vector<Pokoj> listapokoi;
        Szabrownik Bohater;


        void OdkrywaczPokoi(int b);
        void Spawner();
        void GuzikStartGryFunkcja();
        void WygranaSprawdzacz();
        void ZapisWyniku();
        void wxEVT_KEY_DOWN(wxKeyEvent& event);
        void KlikPoleFunkcja(int a);
        void KluczLapacz(wxKeyEvent &event);
        void OdswiezStaty();
        bool CzyMogeTamWejsc(int a);
        void InterakcjaZPolem();



    private:

        //(*Handlers(SzabrownikFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnGUZIK_WYJSCIEClick(wxCommandEvent& event);
        void OnGUZIK_CREDITSClick(wxCommandEvent& event);
        void OnButtonPrzeszukajClick(wxCommandEvent& event);
        void OnButtonZaatakujClick(wxCommandEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnButtonInterakcjaClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(SzabrownikFrame)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_STATICTEXT4;
        static const wxWindowID ID_STATICTEXT16;
        static const wxWindowID ID_STATICTEXT5;
        static const wxWindowID ID_STATICTEXT17;
        static const wxWindowID ID_STATICTEXT6;
        static const wxWindowID ID_STATICTEXT18;
        static const wxWindowID ID_STATICTEXT7;
        static const wxWindowID ID_STATICTEXT19;
        static const wxWindowID ID_STATICTEXT8;
        static const wxWindowID ID_STATICTEXT20;
        static const wxWindowID ID_STATICTEXT9;
        static const wxWindowID ID_STATICTEXT21;
        static const wxWindowID ID_STATICTEXT10;
        static const wxWindowID ID_STATICTEXT22;
        static const wxWindowID ID_STATICTEXT11;
        static const wxWindowID ID_STATICTEXT23;
        static const wxWindowID ID_STATICLINE3;
        static const wxWindowID ID_STATICTEXT24;
        static const wxWindowID ID_STATICTEXT25;
        static const wxWindowID ID_STATICTEXT26;
        static const wxWindowID ID_STATICTEXT27;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_BITMAPBUTTON1;
        static const wxWindowID ID_BUTTON3;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_STATICTEXT3;
        static const wxWindowID ID_STATICBITMAP1;
        static const wxWindowID ID_STATICTEXT12;
        static const wxWindowID ID_STATICTEXT13;
        static const wxWindowID ID_STATICTEXT14;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_BUTTON7;
        static const wxWindowID ID_PANEL1;
        static const wxWindowID ID_STATICTEXT15;
        static const wxWindowID ID_BUTTON4;
        static const wxWindowID ID_BUTTON5;
        static const wxWindowID ID_BUTTON6;
        static const wxWindowID ID_PANEL2;
        //*)

        //(*Declarations(SzabrownikFrame)
        wxBitmapButton* BitmapButton1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* GUZIK_CREDITS;
        wxButton* GUZIK_START;
        wxButton* GUZIK_WYJSCIE;
        wxPanel* Panel2;
        wxPanel* panel_gra;
        wxStaticBitmap* StaticBitmap1;
        wxStaticLine* StaticLine3;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
        wxStaticText* StaticText16;
        wxStaticText* StaticText17;
        wxStaticText* StaticText18;
        wxStaticText* StaticText19;
        wxStaticText* StaticText1;
        wxStaticText* StaticText20;
        wxStaticText* StaticText21;
        wxStaticText* StaticText22;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxStaticText* StaticText25;
        wxStaticText* StaticText26;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStaticText* TEXT_TYTUL;
        //*)

        DECLARE_EVENT_TABLE()
};



#endif // SZABROWNIKMAIN_H
