#include <map>
#include <vector>
#include <iostream>
#include <fstream>

#undef _
#define _(s) wxString::FromUTF8 (s)

int RzutKoscia(int a){
    int wynik = (rand() % a)+1;
    return wynik;
}

void Szabrownik::WylosujStaty(){
    Imie = "John Kanada";
    MEZ = 2*(RzutKoscia(5)+1);
    REF = 2*(RzutKoscia(5)+1);
    WIZ = 2*(RzutKoscia(5)+1);
    INT = 2*(RzutKoscia(5)+1);
    CHR = 2*(RzutKoscia(5)+1);
    WOLA = 2*(RzutKoscia(5)+1);
    DUCH = 2*(RzutKoscia(5)+1);
    SZCZ = 2*(RzutKoscia(5)+1);
    Zloto = 0;
    Zdrowie = MEZ + DUCH/2;
    MAXZdrowie = Zdrowie;

    if(MEZ >= REF && MEZ >= DUCH){
        Bron = 1;
        StatDoWalki = 1;
    }
    else if(REF > MEZ && REF > DUCH){
        Bron = 2;
        StatDoWalki = 2;
    }
    else if(DUCH > MEZ && DUCH > REF){
        Bron = 3;
        StatDoWalki = 3;
    }
    Zbroja = 0;
    Obrona = 0;
    BonusAtaku = 0;


}

std::vector<Pokoj> generacjaPokoi(int n, int pzpz) {
    std::vector<Pokoj> pk;
    std::vector<int> pulaTypow;
    int pozLochu = pzpz;

    int L_Dol = 1;                  //liczba zejsc w dol
    int L_Odpocz = RzutKoscia(3)-1; //liczba pokoj odpoczynek
    int L_Pulap = RzutKoscia(4);    //liczba pokoj pulapka
    int L_Potwor = RzutKoscia(6)+1; //liczba pokoj potwory
    int L_Skarb = RzutKoscia(5);    //liczba pokoj skarb
    int L_Sciana = RzutKoscia(4)+10;//liczba pokoj scian
    int L_Pusty = 49 - L_Dol - L_Pulap - L_Potwor - L_Skarb - L_Sciana;//liczba pokoj pustych

    for(int i = 0; i < L_Pusty; i++) pulaTypow.push_back(1);
    for(int i = 0; i < L_Sciana; i++) pulaTypow.push_back(2);
    for(int i = 0; i < L_Potwor; i++) pulaTypow.push_back(3);
    for(int i = 0; i < L_Skarb; i++) pulaTypow.push_back(4);
    for(int i = 0; i < L_Odpocz; i++) pulaTypow.push_back(5);
    for(int i = 0; i < L_Pulap; i++) pulaTypow.push_back(6);
    for(int i = 0; i < L_Dol; i++) pulaTypow.push_back(7);

    std::random_shuffle(pulaTypow.begin(), pulaTypow.end());

    for (int i = 0; i < n; i++) {
        pk.push_back(Pokoj(pulaTypow[i], pozLochu));
    }
    return pk;
}

void SzabrownikFrame::OdkrywaczPokoi(int a){
/*a - przyjmuje id pokoju w ktorym jest ziutson*/
    std::string obr = listapokoi[a].Obraz;
    std::string obrg = listapokoi[a].ObrazGr;

    pola[a] -> SetBitmap(wxImage((obrg)));
    listapokoi[a].Odkryty = true;
    for(int i = 0; i < 49; i++){
        listapokoi[i].Sasiad = false;
    }
    if(a < 6 && a != 0){
        pola[a+1] -> SetBitmap(wxImage((listapokoi[a+1].Obraz)));
        pola[a-1] -> SetBitmap(wxImage((listapokoi[a-1].Obraz)));
        pola[a+7] -> SetBitmap(wxImage((listapokoi[a+7].Obraz)));
        listapokoi[a+1].Odkryty = true;
        listapokoi[a-1].Odkryty = true;
        listapokoi[a+7].Odkryty = true;
        listapokoi[a+1].Sasiad = true;
        listapokoi[a-1].Sasiad = true;
        listapokoi[a+7].Sasiad = true;
    }
    else if(a > 42 && a != 48){
        pola[a+1] -> SetBitmap(wxImage((listapokoi[a+1].Obraz)));
        pola[a-1] -> SetBitmap(wxImage((listapokoi[a-1].Obraz)));
        pola[a-7] -> SetBitmap(wxImage((listapokoi[a-7].Obraz)));
        listapokoi[a+1].Odkryty = true;
        listapokoi[a-1].Odkryty = true;
        listapokoi[a-7].Odkryty = true;
        listapokoi[a+1].Sasiad = true;
        listapokoi[a-1].Sasiad = true;
        listapokoi[a-7].Sasiad = true;
    }
    else if(a == 0){
        pola[a+1] -> SetBitmap(wxImage((listapokoi[a+1].Obraz)));
        pola[a+7] -> SetBitmap(wxImage((listapokoi[a+7].Obraz)));
        listapokoi[a+1].Odkryty = true;
        listapokoi[a+7].Odkryty = true;
        listapokoi[a+1].Sasiad = true;
        listapokoi[a+7].Sasiad = true;
    }
    else if(a == 48){
        pola[a-1] -> SetBitmap(wxImage((listapokoi[a-1].Obraz)));
        pola[a-7] -> SetBitmap(wxImage((listapokoi[a-7].Obraz)));
        listapokoi[a-1].Odkryty = true;
        listapokoi[a-7].Odkryty = true;
        listapokoi[a-1].Sasiad = true;
        listapokoi[a-7].Sasiad = true;
    }
    else if(a == 6){
        pola[a-1] -> SetBitmap(wxImage((listapokoi[a-1].Obraz)));
        pola[a+7] -> SetBitmap(wxImage((listapokoi[a+7].Obraz)));
        listapokoi[a-1].Odkryty = true;
        listapokoi[a+7].Odkryty = true;
        listapokoi[a-1].Sasiad = true;
        listapokoi[a+7].Sasiad = true;
    }
    else if(a == 42){
        pola[a+1] -> SetBitmap(wxImage((listapokoi[a+1].Obraz)));
        pola[a-7] -> SetBitmap(wxImage((listapokoi[a-7].Obraz)));
        listapokoi[a+1].Odkryty = true;
        listapokoi[a-7].Odkryty = true;
        listapokoi[a+1].Sasiad = true;
        listapokoi[a-7].Sasiad = true;
    }
    else if(a == 7 || a == 14 || a == 21 || a == 28 || a == 35){
        pola[a+1] -> SetBitmap(wxImage((listapokoi[a+1].Obraz)));
        pola[a-7] -> SetBitmap(wxImage((listapokoi[a-7].Obraz)));
        pola[a+7] -> SetBitmap(wxImage((listapokoi[a+7].Obraz)));
        listapokoi[a+1].Odkryty = true;
        listapokoi[a-7].Odkryty = true;
        listapokoi[a+7].Odkryty = true;
        listapokoi[a+1].Sasiad = true;
        listapokoi[a-7].Sasiad = true;
        listapokoi[a+7].Sasiad = true;
    }
    else if(a == 13 || a == 20 || a == 27 || a == 34 || a == 41){
        pola[a-1] -> SetBitmap(wxImage((listapokoi[a-1].Obraz)));
        pola[a-7] -> SetBitmap(wxImage((listapokoi[a-7].Obraz)));
        pola[a+7] -> SetBitmap(wxImage((listapokoi[a+7].Obraz)));
        listapokoi[a-1].Odkryty = true;
        listapokoi[a-7].Odkryty = true;
        listapokoi[a+7].Odkryty = true;
        listapokoi[a-1].Sasiad = true;
        listapokoi[a-7].Sasiad = true;
        listapokoi[a+7].Sasiad = true;
    }
    else{
        pola[a+1] -> SetBitmap(wxImage((listapokoi[a+1].Obraz)));
        pola[a-1] -> SetBitmap(wxImage((listapokoi[a-1].Obraz)));
        pola[a+7] -> SetBitmap(wxImage((listapokoi[a+7].Obraz)));
        pola[a-7] -> SetBitmap(wxImage((listapokoi[a-7].Obraz)));
        listapokoi[a+1].Odkryty = true;
        listapokoi[a-1].Odkryty = true;
        listapokoi[a+7].Odkryty = true;
        listapokoi[a-7].Odkryty = true;
        listapokoi[a+1].Sasiad = true;
        listapokoi[a-1].Sasiad = true;
        listapokoi[a+7].Sasiad = true;
        listapokoi[a-7].Sasiad = true;
    }
}

void SzabrownikFrame::Spawner(){
    int start = rand()%49;
    if(listapokoi[start].Zawartosc == 1){
        Bohater.AktualnyPokoj = start;
        Bohater.KliknietyPokoj = start;
        OdkrywaczPokoi(start);
    }
    else if(listapokoi[start].Zawartosc != 1){
        Spawner();
    }
}

void SzabrownikFrame::GuzikStartGryFunkcja(){
    /*Ten blok to to samo co pod guzikiem wylosuj staty jak cos*/
    Bohater.WylosujStaty();
    StaticText15->SetLabel(std::to_string(Bohater.MEZ));
    StaticText16->SetLabel(std::to_string(Bohater.REF));
    StaticText17->SetLabel(std::to_string(Bohater.WIZ));
    StaticText18->SetLabel(std::to_string(Bohater.INT));
    StaticText19->SetLabel(std::to_string(Bohater.CHR));
    StaticText20->SetLabel(std::to_string(Bohater.WOLA));
    StaticText21->SetLabel(std::to_string(Bohater.DUCH));
    StaticText22->SetLabel(std::to_string(Bohater.SZCZ));
    StaticText24->SetLabel(std::to_string(Bohater.Zloto));
    StaticText26->SetLabel(std::to_string(Bohater.Zdrowie) + " / " + std::to_string(Bohater.MAXZdrowie));

    for(int i = 0; i < 49; i++){
        pola[i]->SetBitmap(wxImage(_T("Nieznany.png")));
        listapokoi[i].Odkryty = false;
        listapokoi[i].Sasiad = false;
    }

    PoziomLochu = 0;

    listapokoi = generacjaPokoi(49, PoziomLochu);

    StaticText2->SetLabel(_("LOCH | POZIOM ") + std::to_string(PoziomLochu));

    Spawner();

    OdswiezStaty();
}

void SzabrownikFrame::WygranaSprawdzacz(){
    /*Wygrana przez bycie rich as heell*/
    if(Bohater.Zloto > 999){
        wxMessageBox(_("Zebrałeś kupę złota! Możesz odejść na emeryture"),"WYGRANA!", wxOK | wxICON_INFORMATION);
        ZapisWyniku();
        GuzikStartGryFunkcja();
    }
}

bool SzabrownikFrame::CzyMogeTamWejsc(int a){
    if(listapokoi[a].Sasiad == true && listapokoi[a].Zawartosc != 2 && listapokoi[Bohater.AktualnyPokoj].Zawartosc != 3 && listapokoi[Bohater.AktualnyPokoj].Zawartosc != 6){
        return true;}
    else if(listapokoi[a].Sasiad == true && listapokoi[a].Zawartosc != 2 && Bohater.Akcesorium == 1){
        return true;}
    else{
        return false;}
}

void SzabrownikFrame::InterakcjaZPolem(){
    //POKÓJ PUSTY
    if(listapokoi[Bohater.AktualnyPokoj].Zawartosc == 1 && listapokoi[Bohater.KliknietyPokoj].Zawartosc != 2){
        int test = RzutKoscia(10);
        if(test < 6){
            Bohater.Zdrowie = Bohater.Zdrowie + RzutKoscia(2);
            if(Bohater.Zdrowie > Bohater.MAXZdrowie){
                Bohater.Zdrowie = Bohater.MAXZdrowie;
            }
            wxMessageBox(_("Odpoczynek odnowił ci trochę zdrowia"),"Odpoczynek", wxOK | wxICON_NONE);
        }
        if(test > 5 && test < 10){
            Bohater.Zdrowie = Bohater.Zdrowie - RzutKoscia(4);
            if(Bohater.Zdrowie < 1){
                if(Bohater.Przedmiot == 2){
                    Bohater.Przedmiot = 0;
                    Bohater.Zdrowie = Bohater.MAXZdrowie/2;
                    wxMessageBox(_("Kryształ uratował cię przed śmiercią we śnie i odnowił ci zdrowie!"),_("KRYSZTAŁ ODRODZENIA!"), wxOK | wxICON_WARNING);
                }
                else{
                wxMessageBox(_("Potwór cię zgładził gdy odpoczywałeś! Koniec Gry!"),"Odpoczynek - Zasadzka", wxOK | wxICON_WARNING);
                GuzikStartGryFunkcja();}
            }
            else{
                wxMessageBox(_("Gdy spałeś napadł cię potwór! Tracisz zdrowie"),"Odpoczynek - Zasadzka", wxOK | wxICON_NONE);
            }
        }
        if(test == 10){
            Bohater.Zloto = Bohater.Zloto / 2;
            wxMessageBox(_("Gdy spałeś ktoś cię okradł! Tracisz trochę złota"),"Odpoczynek - Zasadzka", wxOK | wxICON_NONE);
        }
    }
    //POKÓJ PUSTY

    //POKÓJ-ŚCIANA (DETONACJA)
    if(listapokoi[Bohater.KliknietyPokoj].Zawartosc == 2 && listapokoi[Bohater.KliknietyPokoj].Sasiad == true && Bohater.Przedmiot == 1){//poprawiona bomba
        listapokoi[Bohater.KliknietyPokoj].Zawartosc = 1;
        listapokoi[Bohater.KliknietyPokoj].Obraz = "Nic.png";
        listapokoi[Bohater.KliknietyPokoj].ObrazGr = "NicG.png";
        listapokoi[Bohater.KliknietyPokoj].ObrazK = "NicK.png";
        listapokoi[Bohater.KliknietyPokoj].ObrazGrK = "NicGK.png";
        Bohater.Przedmiot = 0;
        OdswiezStaty();
        KlikPoleFunkcja(Bohater.KliknietyPokoj);


    }

    //POKÓJ-ŚCIANA (DETONACJA)

    //POKÓJ Z POTWOREM
    if(listapokoi[Bohater.AktualnyPokoj].Zawartosc == 3 && listapokoi[Bohater.KliknietyPokoj].Zawartosc != 2){
        int a;
        switch(Bohater.StatDoWalki){
        case 1:
            a = RzutKoscia(Bohater.MEZ);
            break;
        case 2:
            a = RzutKoscia(Bohater.REF);
            break;
        case 3:
            a = RzutKoscia(Bohater.DUCH);
            break;
        }
        a = a+Bohater.BonusAtaku;

        if(a < listapokoi[Bohater.AktualnyPokoj].SilaPotwora){
            if(Bohater.Obrona > 0){Bohater.Obrona = Bohater.Obrona-2;}
            else{Bohater.Zdrowie = Bohater.Zdrowie-2;}
            OdswiezStaty();
            if(Bohater.Zdrowie < 1){
                if(Bohater.Przedmiot == 2){
                    Bohater.Przedmiot = 0;
                    Bohater.Zdrowie = Bohater.MAXZdrowie/2;
                    wxMessageBox(_("Kryształ uratował cię przed śmiercią i odnowił ci zdrowie!"),_("KRYSZTAŁ ODRODZENIA!"), wxOK | wxICON_WARNING);
                }
                else{
                wxMessageBox(_("Potwór cię zgładził! Koniec Gry!"),"WALKA!", wxOK | wxICON_WARNING);
                GuzikStartGryFunkcja();}
            }
            else{
                wxMessageBox(_("Potwór cię uderzył! Straciłeś 2 Zdrowia!"),"WALKA!", wxOK | wxICON_NONE);
                listapokoi[Bohater.AktualnyPokoj].SilaPotwora = listapokoi[Bohater.AktualnyPokoj].SilaPotwora - 2;
                OdkrywaczPokoi(Bohater.AktualnyPokoj);
                KlikPoleFunkcja(Bohater.AktualnyPokoj);
            }

        }
        else{
            Bohater.Zloto = Bohater.Zloto + (listapokoi[Bohater.AktualnyPokoj].SilaPotwora*2) + (PoziomLochu*2);
            listapokoi[Bohater.AktualnyPokoj].Zawartosc = 1;
            listapokoi[Bohater.AktualnyPokoj].Obraz = "Nic.png";
            listapokoi[Bohater.AktualnyPokoj].ObrazGr = "NicG.png";
            listapokoi[Bohater.AktualnyPokoj].ObrazK = "NicK.png";
            listapokoi[Bohater.AktualnyPokoj].ObrazGrK = "NicGK.png";
            OdkrywaczPokoi(Bohater.AktualnyPokoj);
            StaticText24->SetLabel(std::to_string(Bohater.Zloto));
            wxMessageBox(_("Potwór został zgładzony! Zyskałeś jego złoto"),"WALKA!", wxOK | wxICON_INFORMATION);
            WygranaSprawdzacz();

        }
    }
    //POKÓJ Z POTWOREM

    //POKÓJ ZE SKARBEM
    if(listapokoi[Bohater.AktualnyPokoj].Zawartosc == 4 && listapokoi[Bohater.KliknietyPokoj].Zawartosc != 2){
        listapokoi[Bohater.AktualnyPokoj].Zawartosc = 1;
        listapokoi[Bohater.AktualnyPokoj].Obraz = "Nic.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazGr = "NicG.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazK = "NicK.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazGrK = "NicGK.png";
        LosowanieSkarbow();
        OdswiezStaty();
        OdkrywaczPokoi(Bohater.AktualnyPokoj);
        WygranaSprawdzacz();
    }
    //POKÓJ ZE SKARBEM

    //POKÓJ Z ODPOCZYNKIEM
    if(listapokoi[Bohater.AktualnyPokoj].Zawartosc == 5 && listapokoi[Bohater.KliknietyPokoj].Zawartosc != 2){
        Bohater.Zdrowie = Bohater.Zdrowie + RzutKoscia(4) + 2;
        if(Bohater.Zdrowie > Bohater.MAXZdrowie){
            Bohater.Zdrowie = Bohater.MAXZdrowie;
        }
        wxMessageBox(_("Odpoczynek odnowił ci trochę zdrowia"),"Odpoczynek", wxOK | wxICON_NONE);

        listapokoi[Bohater.AktualnyPokoj].Zawartosc = 1;
        listapokoi[Bohater.AktualnyPokoj].Obraz = "Nic.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazGr = "NicG.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazK = "NicK.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazGrK = "NicGK.png";
    }
    //POKÓJ Z ODPOCZYNKIEM

    //POKOJ Z PULAPKA
    if(listapokoi[Bohater.AktualnyPokoj].Zawartosc == 6 && listapokoi[Bohater.KliknietyPokoj].Zawartosc != 2){
        int test = RzutKoscia(Bohater.REF) + RzutKoscia(Bohater.INT);
        if(test < 10){
            if(Bohater.Obrona > 0){Bohater.Obrona = Bohater.Obrona-2;}
            else{Bohater.Zdrowie = Bohater.Zdrowie-2;}
            if(Bohater.Zdrowie < 1){
                if(Bohater.Przedmiot == 2){
                    Bohater.Przedmiot = 0;
                    Bohater.Zdrowie = Bohater.MAXZdrowie/2;
                    wxMessageBox(_("Kryształ uratował cię przed śmiercią i odnowił ci zdrowie!"),_("KRYSZTAŁ ODRODZENIA!"), wxOK | wxICON_WARNING);
                }
                else{
                wxMessageBox(_("Umarłeś w pułapce! Koniec Gry!"),_("PUŁAPKA!"), wxOK | wxICON_WARNING);
                GuzikStartGryFunkcja();}
            }
            else{
                wxMessageBox(_("Pułapka cię zraniła i się rozbroiła!"),_("PUŁAPKA!"), wxOK | wxICON_NONE);
            }
        }
        else{
            LosowanieSkarbow();
            wxMessageBox(_("Pułapka została rozbrojona! Znalazłeś też trochę skarbów"),_("PUŁAPKA!"), wxOK | wxICON_NONE);
        }

        listapokoi[Bohater.AktualnyPokoj].Zawartosc = 1;
        listapokoi[Bohater.AktualnyPokoj].Obraz = "Nic.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazGr = "NicG.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazK = "NicK.png";
        listapokoi[Bohater.AktualnyPokoj].ObrazGrK = "NicGK.png";
        OdswiezStaty();
    }
    //POKOJ Z PULAPKA

    //POKOJ Z ZEJSCIEM NIZEJ
    if(listapokoi[Bohater.AktualnyPokoj].Zawartosc == 7 && listapokoi[Bohater.KliknietyPokoj].Zawartosc != 2){
        for(int i = 0; i < 49; i++){
            pola[i]->SetBitmap(wxImage(_T("Nieznany.png")));
            listapokoi[i].Odkryty = false;
            listapokoi[i].Sasiad = false;
        }
        PoziomLochu = PoziomLochu + 1;

        listapokoi = generacjaPokoi(49, PoziomLochu);

        Spawner();

        StaticText2->SetLabel(_("LOCH | POZIOM ") + std::to_string(PoziomLochu));
    }
    //POKOJ Z ZEJSCIEM NIZEJ

    //Tak na wszelki wypadek
    OdswiezStaty();
    OdkrywaczPokoi(Bohater.AktualnyPokoj);

}

void SzabrownikFrame::KluczLapacz(wxKeyEvent &event){
    int keyCode = event.GetKeyCode();
    int a = Bohater.KliknietyPokoj;



    if (keyCode == 'A' || keyCode == 'a')
    {
        if(a != 0){
            KlikPoleFunkcja(a-1);
            if(CzyMogeTamWejsc(a-1) == true){
                Bohater.AktualnyPokoj = a-1;
                KlikPoleFunkcja(Bohater.AktualnyPokoj);
                OdkrywaczPokoi(a-1);
            }
        }
    }
    if (keyCode == 'S' || keyCode == 's')
    {
        if(a < 42){
            KlikPoleFunkcja(a+7);
            if(CzyMogeTamWejsc(a+7) == true){
                Bohater.AktualnyPokoj = a+7;
                KlikPoleFunkcja(Bohater.AktualnyPokoj);
                OdkrywaczPokoi(a+7);
            }
        }
    }
    if (keyCode == 'D' || keyCode == 'd')
    {
        if(a != 48){
            KlikPoleFunkcja(a+1);
            if(CzyMogeTamWejsc(a+1) == true){
                Bohater.AktualnyPokoj = a+1;
                KlikPoleFunkcja(Bohater.AktualnyPokoj);
                OdkrywaczPokoi(a+1);
            }
        }
    }
    if (keyCode == 'W' || keyCode == 'w')
    {
        if(a > 6){
            KlikPoleFunkcja(a-7);
            if(CzyMogeTamWejsc(a-7) == true){
                Bohater.AktualnyPokoj = a-7;
                KlikPoleFunkcja(Bohater.AktualnyPokoj);
                OdkrywaczPokoi(a-7);
            }
        }
    }
    if (keyCode == ' ')
    {
        InterakcjaZPolem();
    }
     return; // Pozwól na normalne przetworzenie innych klawiszy
}

void SzabrownikFrame::KlikPoleFunkcja(int a){
    /*funckja co sie aktywuje gdy klikasz na pokoj*/

    /*Naprawia ci wyglad pokoja ktory kliknales wczesniek*/
    if(listapokoi[Bohater.KliknietyPokoj].Odkryty == true && Bohater.KliknietyPokoj == Bohater.AktualnyPokoj){
        pola[Bohater.KliknietyPokoj]->SetBitmap(wxImage(listapokoi[Bohater.KliknietyPokoj].ObrazGr));
    }
    else if(listapokoi[Bohater.KliknietyPokoj].Odkryty == true){
        pola[Bohater.KliknietyPokoj]->SetBitmap(wxImage(listapokoi[Bohater.KliknietyPokoj].Obraz));
    }
    else{
        pola[Bohater.KliknietyPokoj]->SetBitmap(wxImage("Nieznany.png"));
    }


    Bohater.KliknietyPokoj = a;

    Button4->Enable(false);
    if(Bohater.KliknietyPokoj == Bohater.AktualnyPokoj){
    Button4->Enable(true);}
    Button4->SetLabel("Interakcja");

    if(listapokoi[a].Odkryty == true){
        if(listapokoi[a].Zawartosc == 1){
                StaticText13->SetLabel("W tym pokoju nie ma nic ciekawego");
                StaticText14->SetLabel(_("Odpoczynek odnowi ci zdrowie ale we śnie jesteś łatwą ofiarą..."));
                Button4->SetLabel("Odpocznij");}
        else if(listapokoi[a].Zawartosc == 2){
                StaticText13->SetLabel(_("Ten pokój jest zablokowany"));
                StaticText14->SetLabel(_(""));
                if(Bohater.Przedmiot == 1 && listapokoi[a].Sasiad == true){
                    Button4->Enable(true);
                    Button4->SetLabel("Zdetonuj");
                }



                else{
                    Button4->Enable(false);
                }
                }
        else if(listapokoi[a].Zawartosc == 3){
                StaticText13->SetLabel(_("W tym pokoju jest potwór! Moc potwora: ") + std::to_string(listapokoi[a].SilaPotwora));
                StaticText14->SetLabel(_("Do walki używasz statystyki zależnej od broni."));
                Button4->SetLabel("Zaatakuj");}
        else if(listapokoi[a].Zawartosc == 4){
                StaticText13->SetLabel("W tym pokoju jest skarb!");
                StaticText14->SetLabel(_("Do przeszukiwania używasz Wizualizacji i Szczęścia"));
                Button4->SetLabel("Przeszukaj");}
        else if(listapokoi[a].Zawartosc == 5){
                StaticText13->SetLabel(_("W tym pokoju jest bezpiecznie. Można tu spokojnie odpocząć"));
                StaticText14->SetLabel(_(""));
                Button4->SetLabel("Odpocznij");}
        else if(listapokoi[a].Zawartosc == 6){
                StaticText13->SetLabel(_("W tym pokoju jest pułapka!"));
                StaticText14->SetLabel(_("Do rozbrojenia pułapki używasz Refleksu i Inteligencji"));}
        else if(listapokoi[a].Zawartosc == 7){
                StaticText13->SetLabel(_("W tym pokoju jest zejście na niższy poziom!"));
                StaticText14->SetLabel(_("Nie będziesz mógł wrócić na ten poziom."));
                Button4->SetLabel(_("Zejdź Niżej"));}
        StaticBitmap1->SetBitmap(wxImage(listapokoi[a].Obraz));
        if(Bohater.KliknietyPokoj == Bohater.AktualnyPokoj){
            pola[a]->SetBitmap(wxImage(listapokoi[a].ObrazGrK));
        }
        else if(Bohater.KliknietyPokoj != Bohater.AktualnyPokoj){
            pola[a]->SetBitmap(wxImage(listapokoi[a].ObrazK));
        }
    }
    else{
        Button4->Enable(false);
        StaticText13->SetLabel("Nie wiadomo co jest w tym pokoju");
        StaticBitmap1->SetBitmap(wxImage("Nieznany.png"));
        pola[a]->SetBitmap(wxImage("NieznanyK.png"));
    }

    Button2->Enable(false);

    if(listapokoi[a].Sasiad == true && listapokoi[a].Zawartosc != 2 && listapokoi[Bohater.AktualnyPokoj].Zawartosc != 3 && listapokoi[Bohater.AktualnyPokoj].Zawartosc != 6){
        Button2->Enable(true);
    }
    if(listapokoi[a].Sasiad == false || listapokoi[a].Zawartosc == 2){
        Button2->Enable(false);
    }
    /*if(listapokoi[a].Zawartosc == 4 && Bohater.KliknietyPokoj == Bohater.AktualnyPokoj){
        Button4->Enable(true);
    }*/
}

void SzabrownikFrame::OdswiezStaty(){
    StaticText24->SetLabel(std::to_string(Bohater.Zloto));
    StaticText26->SetLabel(std::to_string(Bohater.Zdrowie) + " / " + std::to_string(Bohater.MAXZdrowie));
    if(Bohater.Obrona < 0){Bohater.Obrona = 0;}
    StaticText36->SetLabel(std::to_string(Bohater.Obrona));

    //Broń
    switch(Bohater.Bron){
    case 0:
        StaticText29->SetLabel(_("Brak"));
        break;
    case 1:
        StaticText29->SetLabel(_("Miecz"));
        break;
    case 2:
        StaticText29->SetLabel(_("Łuk"));
        break;
    case 3:
        StaticText29->SetLabel(_("Różdżka"));
        break;
    case 4:
        StaticText29->SetLabel(_("Wielki Miecz [+2]"));
        break;
    case 5:
        StaticText29->SetLabel(_("Łuk Refleksyjny [+2]"));
        break;
    case 6:
        StaticText29->SetLabel(_("Magiczny Kryształ [+2]"));
        break;
    default:
        StaticText29->SetLabel(_("Brak"));
        break;
    }


    //Zbroja
    switch(Bohater.Zbroja){
    case 0:
        StaticText31->SetLabel(_("Brak"));
        break;
    case 1:
        StaticText31->SetLabel(_("Skóra Potwora"));
        break;
    case 2:
        StaticText31->SetLabel(_("Przyszywanica"));
        break;
    case 3:
        StaticText31->SetLabel(_("Kolczuga"));
        break;
    case 4:
        StaticText31->SetLabel(_("Zbroja Płytowa"));
        break;
    }

    //Akcesorium
    switch(Bohater.Akcesorium){
    case 0:
        StaticText33->SetLabel(_("Brak"));
        break;
    case 1:
        StaticText33->SetLabel(_("Buty Ucieczki"));
        break;
    }

    //Przedmiot
    switch(Bohater.Przedmiot){
    case 0:
        StaticText35->SetLabel(_("Brak"));
        break;
    case 1:
        StaticText35->SetLabel(_("Bomba Burząca"));
        break;
    case 2:
        StaticText35->SetLabel(_("Kryształ Odrodzenia"));
        break;
    }
}

void SzabrownikFrame::ZapisWyniku(){

    /*
    std::ifstream Plik("ZapisGry.txt");

    std::string NowyWynik = std::to_string(Bohater.Zloto) + " ";
    std::string StareWyniki;
    while(std::getline(Plik, StareWyniki)){
        StareWyniki = StareWyniki;
    }
    NowyWynik = NowyWynik + StareWyniki;

    std::ofstream Plik2("ZapisGry.txt");

    Plik2 << NowyWynik;

    Plik.close();

    */
}

void SzabrownikFrame::LosowanieSkarbow(){
    int roll = RzutKoscia(20);
    if(roll < 16){
        Bohater.Zloto = Bohater.Zloto + RzutKoscia(Bohater.WIZ) + RzutKoscia(Bohater.SZCZ) + PoziomLochu*2;
    }
    else{
        int roll2 = RzutKoscia(10);
        switch(roll2){
        case 1:
            Bohater.Bron = 4;
            Bohater.BonusAtaku = 2;
            Bohater.StatDoWalki = 1;
            break;
        case 2:
            Bohater.Bron = 5;
            Bohater.BonusAtaku = 2;
            Bohater.StatDoWalki = 2;
            break;
        case 3:
            Bohater.Bron = 6;
            Bohater.BonusAtaku = 2;
            Bohater.StatDoWalki = 3;
            break;
        case 4:
            Bohater.Zbroja = 1;
            Bohater.Obrona = 2;
            break;
        case 5:
            Bohater.Zbroja = 2;
            Bohater.Obrona = 4;
            break;
        case 6:
            Bohater.Zbroja = 3;
            Bohater.Obrona = 8;
            break;
        case 7:
            Bohater.Zbroja = 4;
            Bohater.Obrona = 16;
            break;
        case 8:
            Bohater.Akcesorium = 1;
            break;
        case 9:
            Bohater.Przedmiot = 1;
            break;
        case 10:
            Bohater.Przedmiot = 2;
            break;
        }
    }
    OdswiezStaty();
}


Pokoj::Pokoj(int narzuconyTyp, int pz){
    /*Przyjmuje id buttona, oraz ilość wszystkich buttonów (to dodam pozniej idc)*/

    Zawartosc = narzuconyTyp; // Tutaj przypisujemy typ z listy, a nie z rand()
    Odkryty = false;
    PzLochu = pz;
    if(Zawartosc == 1 ){
        Obraz = "Nic.png";
        ObrazGr = "NicG.png";
        ObrazK = "NicK.png";
        ObrazGrK = "NicGK.png";
        }
    else if(Zawartosc == 2){
        Obraz = "Blok.png";
        ObrazGr = "Nieznany.png";
        ObrazK = "BlokK.png";
        ObrazGrK = "NieznanyK.png";}
    else if(Zawartosc == 3){
        Obraz = "Potwor.png";
        ObrazGr = "PotworG.png";
        ObrazK = "PotworK.png";
        ObrazGrK = "PotworGK.png";
        SilaPotwora = RzutKoscia(6) + RzutKoscia(6) + PzLochu;}
    else if(Zawartosc == 4){
        Obraz = "Skarb.png";
        ObrazGr = "SkarbG.png";
        ObrazK = "SkarbK.png";
        ObrazGrK = "SkarbGK.png";}
    else if(Zawartosc == 5){
        Obraz = "Odpoczynek.png";
        ObrazGr = "OdpoczynekG.png";
        ObrazK = "OdpoczynekK.png";
        ObrazGrK = "OdpoczynekGK.png";}
    else if(Zawartosc == 6){
        Obraz = "Pulapka.png";
        ObrazGr = "PulapkaG.png";
        ObrazK = "PulapkaK.png";
        ObrazGrK = "PulapkaGK.png";}
    else if(Zawartosc == 7){
        Obraz = "Wdol.png";
        ObrazGr = "WdolG.png";
        ObrazK = "WdolK.png";
        ObrazGrK = "WdolGK.png";}
}







