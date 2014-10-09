/**
 *\author "Radek Simkanič, DiS - ID SIM0094"
 *
 *\version 1.0
 *
 *\brief Kalendář: Semestrální projekt do základu programování na VŠB - FEI.
 *
 *\details Kalendář je sesynchronizován aktuálním datem a je možno se v něm pohybova do budoucnosti nebo minulosti v měsičním či týdením módu.
 *\details Další mód je menstruační kalendář, který vygeneruje HTML dokument s označenými menstruacemi, plodnými a neplodnými dny a ovulací na určitý počet cyklů.
 *
 *\date 2011/12
 *
 *\copyright GNU BSD license
 */

/*
 Kalendář: Semestrální projekt do základu programování na VŠB - FEI.
 Kalendář je sesynchronizován aktuálním datem a je možno se v něm pohybova do budoucnosti nebo minulosti v měsičním či týdením módu.
 Další mód je menstruační kalendář, který vygeneruje HTML dokument s označenými menstruacemi, plodnými a neplodnými dny a ovulací na určitý počet cyklů.

    License (Original ENG):
 Copyright © 2011, Radek Simkanič, DiS - Gulliver.
 All rights reserved.
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other
       materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    Licence (Neoficiální CZE):
 Copyright © 2011, Radek Simkanič, DiS - Gulliver.
 Všechna práva vyhrazena.
 Redistribuce a použití zdrojových i binárních forem díla, v původním i upravovaném tvaru, jsou povoleny za následujících podmínek:

    * Šířený zdrojový kód musí obsahovat výše uvedenou informaci o copyrightu, tento seznam podmínek a níže uvedené zřeknutí se odpovědnosti.
    * Šířený binární tvar musí nést výše uvedenou informaci o copyrightu, tento seznam podmínek a níže uvedené zřeknutí se odpovědnosti ve své dokumentaci a/nebo dalších
      poskytovaných materiálech.
 TENTO SOFTWARE JE POSKYTOVÁN DRŽITELEM LICENCE A JEHO PŘISPĚVATELI „JAK STOJÍ A LEŽÍ“ A JAKÉKOLIV VÝSLOVNÉ NEBO PŘEDPOKLÁDANÉ ZÁRUKY VČETNĚ, ALE NEJEN, PŘEDPOKLÁDANÝCH
 OBCHODNÍCH ZÁRUK A ZÁRUKY VHODNOSTI PRO JAKÝKOLIV ÚČEL JSOU POPŘENY. DRŽITEL, ANI PŘISPĚVATELÉ NEBUDOU V ŽÁDNÉM PŘÍPADĚ ODPOVĚDNI ZA JAKÉKOLIV PŘÍMÉ, NEPŘÍMÉ, NÁHODNÉ,
 ZVLÁŠTNÍ, PŘÍKLADNÉ NEBO VYPLÝVAJÍCÍ ŠKODY (VČETNĚ, ALE NEJEN, ŠKOD VZNIKLÝCH NARUŠENÍM DODÁVEK ZBOŽÍ NEBO SLUŽEB; ZTRÁTOU POUŽITELNOSTI, DAT NEBO ZISKŮ;
 NEBO PŘERUŠENÍM OBCHODNÍ ČINNOSTI) JAKKOLIV ZPŮSOBENÉ NA ZÁKLADĚ JAKÉKOLIV TEORIE O ZODPOVĚDNOSTI, AŤ UŽ PLYNOUCÍ Z JINÉHO SMLUVNÍHO VZTAHU, URČITÉ ZODPOVĚDNOSTI NEBO
 PŘEČINU (VČETNĚ NEDBALOSTI) NA JAKÉMKOLIV ZPŮSOBU POUŽITÍ TOHOTO SOFTWARE, I V PŘÍPADĚ, ŽE DRŽITEL PRÁV BYL UPOZORNĚN NA MOŽNOST TAKOVÝCH ŠKOD.
*/


#include<iostream>
#include<fstream>
#include<cstring>
#include<string>//.h
#include<stdlib.h>
#include "funkce.h"

using namespace std;

#define SOUBOR "index.html"

const char *zkratky_dny[]={"Po", "Ut", "St", "Ct", "Pa", "So", "Ne"};
const char *nazvy_mesicu[] = {"Leden", "Únor", "Březen", "Duben", "Květen", "Červen", "Červenec", "Srpen", "Září", "Říjen", "Listopad", "Prosinec"};
const char *css_class[] = {"menstruace", "neplodne_dny", "nic", "velmi_pl_1", "ovulace", "velmi_pl_1", "nic", "neplodne_dny"};
const int PCSS=8;

void volba_m(unsigned int, bool);
void volba_mm(int, int, int, int, int, int);//http://www.plodne-dny-vypocet.cz/ - vzane vzorce ale semtam jim to hapruje jinak testovano ještě podle: http://calendar.zoznam.sk/menstruacni-kalendar.php
void volba_t(unsigned int, bool);
void volba_s();
void volba_null();
void prikazy(const char *);

namespace argument{
    char **ar;
    int arc=0;
}

//Globální proměnné
int kroku=0;
bool way=true;

int main(int argc, char *argv[]){

    //cout<<argc<<endl;
    if(argc>1){
        argument::ar = new char *[argc-1];
        argument::arc = argc;
        for(int i=0; i<argc-1; i++){
            argument::ar[i]=argv[i+1];
        }
        prikazy("argv");
    }
    else{
        cout<<"nic nevybrano"<<endl;
        volba_null();
    }

    cout<<endl;

    return 0;
}



/**
 *\brief                volba_null - Help
 *\details              Funkce, která vypíše sadu příkazu a odkáže se na funkci prikazy().
 *\return               (void).
 */

void volba_null(){
    cout<<"\fSeznam hlavních příkazu (použitelné i jako parametr)"<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;

    cout<<"\t-m\tMěsiční kalendář a krokování v něm"<<endl<<"\t\t-m [kroků] [next|back]"<<endl;
    cout<<"\t\t\t[kroků] (nepoviný parametr) je číslo o kolik měsícu se má kalendář posunout od aktuálního data"<<endl;
    cout<<"\t\t\t[next|back] (nepoviný parametr) je přepinač zda se má krokovat dopředu nebo zpět. Pro krokováni zpět je parametr poviny jinak je defaultní hodnota next"<<endl;

    cout<<"\t-t\tTydenní kalendář a krokování v něm"<<endl<<"\t\t-t [kroků] [next|back]"<<endl;
    cout<<"\t\t\t[kroků] (nepoviný parametr) je číslo o kolik týdnů se má kalendář posunout od aktuálního data"<<endl;
    cout<<"\t\t\t[next|back] (nepoviný parametr) je přepinač zda se má krokovat dopředu nebo zpět. Pro krokováni zpět je parametr poviny jinak je defaultní hodnota next"<<endl;

    cout<<"\t-mm\tMenstruační kalendář, který se uloží jako HTML"<<endl<<"\t\t-mm d [datum] c [cyklus] k [kroků] - nepřehazovat!"<<endl;
    cout<<"\t\t\td [datum] (nepoviný parametr) datum poslední menstruace (ve formátu dd mm rrrr). Neni-li zadán bude se brát rok 1990 (nejnižší hodnota)!"<<endl;
    cout<<"\t\t\tc [cyklus] (nepoviný parametr) jak dlouhý je cyklus menstruace (od začátku k začátku menstruace). Výchozí hodnota je 28 (dnů)!"<<endl;
    //cout<<"\t\t\tm [menstruace] (nepoviný parametr) jak dlouhá je menstruace (kolik dní trvá). Výchozí hodnota je 5!"<<endl;
    cout<<"\t\t\tk [kroků] (nepoviný parametr) kolik následujících cyklu vypočítat a zapsát. Výchozí hodnota je 12!"<<endl;
    prikazy("null");


}

/**
 *\brief                prikazy - Příkazy
 *\details              Funkce umožní spustit příkazy a zároveň vyvolá určitou funkci pro daný příkaz.
 *\param[in]    akt_pozice (char *) sekce.
 *\return               (void).
 */
void prikazy(const char *akt_pozice="null"){
    vector<string> slova;
    if(comp_str(akt_pozice, "argv") ){
        akt_pozice="null";
        cout<<"Byly použité vstupní parametry!"<<endl;
        char_array_to_string_vector(argument::ar, 0, argument::arc, slova);
    }
    else{
        cout<<endl<<"zadejte příkaz: ";
        const int velikost=40;
        char *param = new char [velikost];
        char ch='.';
        bool pokracovat=true;
        for (int i=0; ch!='\n' ; i++){
            cin.get(ch);
            if(i<velikost && pokracovat){
                if(i==velikost-1 && ch!='\n')
                    param[velikost-1]='\0';
                else if(ch=='\n'){
                    param[i]='\0';
                    pokracovat=false;
                }
                else
                    param[i]=ch;
            }
        }

        cout<<endl;

        split_string(param, slova);
        delete [] param;
    }

    cout<<"Počet zadaných příkazu: "<<slova.size()<<endl;
    if(slova.size()>0){
        if(comp_str(slova[0], "-main") )
            volba_null();
        else if(comp_str(slova[0], "-m") ){//
            kroku=0;
            way=true;
            if(slova.size()>1 && int_dec(slova[1]) )
                kroku=str_to_int(slova[1]);

            if(slova.size()>2 && comp_str(slova[2], "back") )
                way=false;

            volba_m(kroku, way);
        }
        else if(comp_str(slova[0], "-mm") ){
            unsigned int den=1;
            unsigned int mesic=1;
            unsigned int rok=1990;
            unsigned int cyklus=28;
            unsigned int menstruace=5;
            unsigned int kroku=12;

            unsigned int uroven=1;

            if(slova.size()>uroven+3 && comp_str(slova[uroven],"d") && int_dec(slova[uroven+1]) && int_dec(slova[uroven+2]) && int_dec(slova[uroven+3]) ){
                int den2 =      str_to_int(slova[uroven+1]);
                int mesic2 =    str_to_int(slova[uroven+2]);
                int rok2 =      str_to_int(slova[uroven+3]);
                if(rok2>9999)
                    rok=9999;
                else if(rok2<1990)
                    rok=1990;
                else
                    rok=rok2;

                if(mesic2>12)
                    mesic=12;
                else if(mesic2<1)
                    mesic=1;
                else
                    mesic=mesic2;

                if(den2 > dny_v_mesici(mesic, rok) )
                    den=dny_v_mesici(mesic, rok);
                else if(den2<1)
                    den=1;
                else
                    den=den2;
                uroven+=4;
            }
            if(slova.size()>uroven+1 && comp_str(slova[uroven], "c") && int_dec(slova[uroven+1]) ){
                cyklus=str_to_int(slova[uroven+1]);
                if(cyklus<21)
                    cyklus=21;
                else if(cyklus>35)
                    cyklus = 35;
                uroven+=2;
            }
            /*if(slova.size()>uroven+1 && comp_str(slova[uroven], "m") && int_dec(slova[uroven+1]) ){
                menstruace=str_to_int(slova[uroven+1]);
                if(menstruace<2)
                    menstruace=2;
                else if(menstruace>9)
                    menstruace = 9;
                uroven+=2;
            }*/
            if(slova.size()>uroven+1 && comp_str(slova[uroven], "k") && int_dec(slova[uroven+1]) ){
                kroku=str_to_int(slova[uroven+1]);
                if(kroku<2)
                    kroku=2;
                else if(kroku>100)
                    kroku = 100;
                //uroven+=2;
            }
            volba_mm(kroku, den, mesic, rok, cyklus, menstruace);
        }
        else if(comp_str(slova[0], "-t") ){
            kroku=0;
            way=true;
            if(slova.size()>1 && int_dec(slova[1]) )
                kroku=str_to_int(slova[1]);

            if(slova.size()>2 && comp_str(slova[2], "back") )
                way=false;

            volba_t(kroku, way);
        }
        else if(comp_str(slova[0], "-c")){
            cout<<"-c nedoděláno"<<endl;
        }
        else if(comp_str(slova[0], "end") || comp_str(slova[0], "exit") || comp_str(slova[0], "konec") || comp_str(slova[0], "kill") || comp_str(slova[0], "bye") || comp_str(slova[0], "microsoft") ){
            cout<<"bye bye"<<endl;
            if(comp_str(slova[0], "microsoft") )
                cout<<"...příště použij svěcenou vodu!"<<endl;
        }
        else{
            if(comp_str(akt_pozice, "null") ){
                cout<<"Příkaz: "<<slova[0]<<" není definován! (pro funkční parametry zadej -main)"<<endl<<endl;
                prikazy("null");
            }
            //tady podle toho kde se uživatel nachází
            if(comp_str(akt_pozice, "-m") ){
                if(int_dec(slova[0]) )
                    kroku=str_to_int(slova[0]);
                if(comp_str(slova[0], "back") ){
                    if(kroku>0 && way){
                        kroku--;
                    }
                    else if(kroku>0 && !way){
                        kroku++;
                    }
                    else if(kroku==0 && way){
                        kroku++;
                        way=false;
                    }
                    else if(kroku==0 && !way){
                        kroku++;
                    }
                    else
                        cout<<"chyba"<<endl;
                }

                if(comp_str(slova[0], "next") ){
                    if(kroku>0 && way){
                        kroku++;
                    }
                    else if(kroku>0 && !way){
                        kroku--;
                    }
                    else if(kroku==0 && way){
                        kroku++;
                    }
                    else if(kroku==0 && !way){
                        kroku++;
                        way=true;
                    }
                }

                if(slova.size()>1 && comp_str(slova[1], "back") )
                    way=false;
                else if(slova.size()>1 && comp_str(slova[1], "next") )
                    way=true;
                volba_m(kroku, way);
            }
            else if(comp_str(akt_pozice, "-t") ){
                if(int_dec(slova[0]) )
                    kroku=str_to_int(slova[0]);
                if(comp_str(slova[0], "back") ){
                    if(kroku>0 && way){
                        kroku--;
                    }
                    else if(kroku>0 && !way){
                        kroku++;
                    }
                    else if(kroku==0 && way){
                        kroku++;
                        way=false;
                    }
                    else if(kroku==0 && !way){
                        kroku++;
                    }
                    else
                        cout<<"chyba"<<endl;
                }

                if(comp_str(slova[0], "next") ){
                    if(kroku>0 && way){
                        kroku++;
                    }
                    else if(kroku>0 && !way){
                        kroku--;
                    }
                    else if(kroku==0 && way){
                        kroku++;
                    }
                    else if(kroku==0 && !way){
                        kroku++;
                        way=true;
                    }
                }

                if(slova.size()>1 && comp_str(slova[1], "back") )
                    way=false;
                else if(slova.size()>1 && comp_str(slova[1], "next") )
                    way=true;
                volba_t(kroku, way);
            }
        }
    }
    else{
        prikazy(akt_pozice);
    }

}

/**
 *\brief                volba_m - Volba měsiční kalendář
 *\details              Funkce, která vygeneruje podle příkazu měsiční kalendář (v budoucnu i v minulosti) a vyvolá funkci prikazy.
 *\param[in]    page    (int) Krokování.
 *\param[in]    way     (bool) [true] vpřed; [false] zpět.
 *\return               (void).
 */
void volba_m(unsigned int page, bool way=true){
    if(page<0)
        page=0;
    if(page>134217728){//134217728 = 4294967296÷32 = int/(max počet dnu v měsici + 1)
        page=134217728;
        cout<<"maximum kroku je 134217728!"<<endl;
    }
    kroku=page;

    int gen[6];

    cout<<"počet kroků: "<<kroku<<endl;
    generator_dnu(page, way, gen);

        int &pocet_dnu_v_mesici = gen[1];   //pocet dnu v predpovezenem mesici
        int &mesic = gen[2];                //mesic
        int &rok = gen[3];                  //rok
        int &den = gen[4];                  //první den v měsící
        //int &aktualni_den = gen[5];       //může sloužít pro označení aktuálního dne
    int rokm;
    if(mesic==1)
        rokm = rok;
    else
        rokm = rok - 1;

    int pocet_dnu_minuleho_mesice = dny_v_mesici(predchozi_mesic(mesic), rokm);
    int pocet_dnu_z_minuleho_mesice = den-1;

    int pocet_zobrazujicich_dnu = pocet_dnu_z_minuleho_mesice + pocet_dnu_v_mesici;
    int modulo = 7-(pocet_zobrazujicich_dnu%7);
    if(modulo==7)
        modulo=0;
    pocet_zobrazujicich_dnu+=modulo;

    int radku;
    switch(pocet_zobrazujicich_dnu){
        case 28:
            radku = 4;
            break;
        case 35:
            radku = 5;
            break;
        case 42:
            radku = 6;
            break;
    }

    cout<<"########################"<<endl
    <<"# Po Út St Čt Pá So Ne #"<<endl
    <<"#======================#"<<endl;

    int j=1, k=1;
    for(;radku!=0; radku--){
        cout<<"# ";
        for(int i=1; i<=7; i++){
            if(pocet_dnu_z_minuleho_mesice!=0){
                vypis_cislo(pocet_dnu_minuleho_mesice-pocet_dnu_z_minuleho_mesice+1);
                pocet_dnu_z_minuleho_mesice--;
            }
            else
                if(j<=pocet_dnu_v_mesici){
                    vypis_cislo(j);
                    j++;
                }
                else{
                    vypis_cislo(k);
                    k++;
                }
            cout<<" ";
        }
        cout<<"#"<<endl;
    }
    cout<<"#======================#"<<endl
    <<nazvy_mesicu[mesic-1]<<" "<<rok<<endl
    <<"########################"<<endl;
    prikazy("-m");
}

/**
 *\brief                volba_t - Volba týdenní kalendář
 *\details              Funkce, která vygeneruje podle příkazu týdenní kalendář (v budoucnu i v minulosti), vypíše pro každý den svátky a vyvolá funkci prikazy().
 *\param[in]    page    (int) Krokování.
 *\param[in]    way     (bool) [true] vpřed; [false] zpět.
 *\return               (void).
 */
void volba_t(unsigned int page, bool way=true){
    if(page<0)
        page=0;
    if(page>536870912){//536870912 = 4294967296÷8 = int/(max počet dnu v tydnu + 1)
        page=536870912;
        cout<<"maximum kroku je 536870912!"<<endl;
    }
    kroku=page;

    int gen[5];
    cout<<"počet kroků: "<<kroku<<endl;
    tydenni_generator_dnu(page, way, gen);
        //int &pocet_dnu_v_mesici = gen[4];   //pocet dnu v predpovezenem mesici
        int &den_v_tydnu = gen[0];
        int &den = gen[1];
        int &mesic = gen[2];                //mesic
        int &rok = gen[3];                  //rok
        //int &den = gen[4];                  //první den v měsící
        //int &aktualni_den = gen[5];       //může sloužít pro označení aktuálního dne

    for(int i=0; i<7; i++){
        cout<<den<<". "<<nazvy_mesicu[mesic-1]<<" "<<rok<<"\t"<<zkratky_dny[den_v_tydnu-1]<<"\t";
        svatky(mesic, den);
        cout<<endl;
        den_v_tydnu=nasledujici_den(den_v_tydnu);
        den=nasledujici_den_v_mesici(den, mesic, rok);
        if(den==1){
            mesic=nasledujici_mesic(mesic);
            if(mesic==1)
                rok++;
        }
    }

    prikazy("-t");
}

/**
 *\brief                volba_mm - Volba menstruační kalendář
 *\details              Funkce, která vygeneruje podle příkazu měsiční kalendář (v budoucnu i v minulosti) a vyvolá funkci prikazy.
 *\param[in]    kroku   (int) Krokování.
 *\param[in]    den     (int) Den.
 *\param[in]    mesic   (int) Měsíc.
 *\param[in]    rok     (int) Rok.
 *\param[in]    cyklus  (int) Menstruační cyklus
 *\param[in]    menstruace  (int) Délka menstruace.
 *\return               (void).
 */
void volba_mm(int kroku, int den, int mesic, int rok, int cyklus, int menstruace){
    cout<<"Zrovna se generuje Váš menstruační kalendář..."<<endl;
    vector <int> kalendar;
    int err = krokovani_menstruace(rok, mesic, den, cyklus, menstruace, kroku, kalendar);
    if(err)
        cout<<"... vygenerováno. Nyní stačí jen otevřít soubor "<<SOUBOR<<endl;
    else
        cout<<"... nepodařilo se vygenerovat!"<<endl;
    /*//výpis z datumů
    for(int i=0; kalendar.size()>i; i++){
        cout<<"i: "<<i<<" hodnota: "<<kalendar[i]<<endl;
        if((i+1)%3==0)
            cout<<endl;
        if((i+1)%21==0)
            cout<<"================"<<endl;
    }*/
    ofstream fout(SOUBOR);//otevření souboru pro zápis
    //stream do souboru
    fout<<"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"<<endl<<"<HTML>"<<endl<<"<HEAD>"<<endl;
    fout<<"\t <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"<<endl;
    fout<<"\t <meta http-equiv=\"Content-language\" content=\"cs\" />"<<endl;
    fout<<"\t <meta name=\"author\" content=\"Gulliver - Radek Simkanič\" />"<<endl;
    fout<<"\t <TITLE> ..:: Vygenerovaný kalendář menstruačních a ovulačních dnů ::.. - Projekt do algoritmů na VŠB-FEI </TITLE>"<<endl;
    //styly
    fout<<"\t <STYLE>"<<endl;
        fout<<"\t\t .table_info     {border: solid black; background: silver }"<<endl;
        fout<<"\t\t .table_head     {color: white; background: black }"<<endl;
        fout<<"\t\t .akce           {color: white; background: black }"<<endl;
        fout<<"\t\t .nic            {color: black; background: silver }"<<endl;
        fout<<"\t\t .menstruace     {color: white; background: red }"<<endl;
        fout<<"\t\t .neplodne_dny   {color: white; background: #440000 }"<<endl;
        fout<<"\t\t .velmi_pl_1     {color: white; background: #008800 }"<<endl;
        fout<<"\t\t .ovulace        {color: black; background: lime }"<<endl;
        fout<<"\t\t .nedef          {color: gray; background: black }"<<endl;
    fout<<"\t </STYLE>"<<endl<<"</HEAD>"<<endl<<"<BODY>"<<endl<<endl;
    //obsah
        //informační tabulka
        fout<<"<h1>Informace z kterých se generovalo</h1>"<<endl;
        fout<<"<table class=\"table_info\" border=0>"<<endl;
        fout<<"<tr><td class=\"table_head\"> Začátek poslední znamé menstruace: </td><td>"<<den<<"."<<mesic<<". "<<rok<<" (dd.mm. rrrr) </td></tr>"<<endl;
        fout<<"<tr><td class=\"table_head\"> Perioda menstruačního cyklu: </td><td>"<<cyklus<<" - počet dní od začátku menstruace k dalšímu začátku menstruace </td></tr>"<<endl;
        fout<<"<tr><td class=\"table_head\"> Délka menstruace: </td><td>"<<menstruace<<" </td></tr>"<<endl;
        fout<<"<tr><td class=\"table_head\"> Počet cyklu k vygenerování </td><td>"<<kroku<<"</td></tr>"<<endl;
        fout<<"</table>"<<endl;

        fout<<"<h1>Legenda</h1>"<<endl;
        fout<<"<table class=\"table_info\" border=0>"<<endl;
        fout<<"<tr><td class=\""<< css_class[0] <<"\"> Menstruace </td><td>Průběh menstruace</td></tr>"<<endl;
        fout<<"<tr><td class=\""<< css_class[1] <<"\"> Neplodné dny </td><td>Průběh neplodných dnů</td></tr>"<<endl;
        fout<<"<tr><td class=\""<< css_class[2] <<"\"> Normální dny </td><td>Slabé plodné dny</td></tr>"<<endl;
        fout<<"<tr><td class=\""<< css_class[3] <<"\"> Velmi plodné dny </td><td>Průběh velmi plodných dnů</td></tr>"<<endl;
        fout<<"<tr><td class=\""<< css_class[4] <<"\"> Ovulace </td><td>Ovulace - uvolnění vajíčka z vaječníku. </td></tr>"<<endl;
        fout<<"</table>"<<endl;

        fout<<"<h1>Vygenerované kalendáře</h1>"<<endl;

        bool dokoncit=false;
        bool zacit_m=true;
        bool start=true;
        int mesic2= kalendar[1];
        int rok2 = kalendar[2];
        int den2 = 1;//kalendar[0];
        int den_v_t=den_v_tydnu(den2, mesic2, rok2);
        //cout<<"den v týdnu start "<<den_v_t<<endl;

        bool dodatecne=false;
        for(unsigned int i=0, a=0, c=PCSS-1; i<(kalendar.size()/3)-3 && rok2<=kalendar[(i*3)+2]; a++){//buňky kalendaře ... podmínka && rok2<=kalendar[(i*3)+2] - je zde jen pro jistotu aby se program nedostal do nekonečné smyčky kdyby náhodou nějaký datum byl špatně vygenerován
            if(zacit_m){
                fout<<"<h2>"<<nazvy_mesicu[mesic2-1]<<" "<<rok2<<"</h2>"<<endl;
                fout<<"<table>"<<endl<<"<tr>"<<endl;
                for(int j=0; j<7; j++)
                    fout<<"\t<td> "<<zkratky_dny[j]<<" </td>"<<endl;
                fout<<"</tr>"<<endl;
            }
            if(den_v_t==1)
                fout<<"<tr>"<<endl;
            if(zacit_m){
                for(int j=1;j<den_v_t;j++)
                    fout<<"\t<td> </td>"<<endl;
                zacit_m=false;
            }

            if(den2==kalendar[i*3] && mesic2==kalendar[(i*3)+1] && rok2==kalendar[(i*3)+2]){
                dodatecne = false;
                start = false;
                if(c<PCSS-1){
                    if(c==0 || c==1 || c==5)
                        dodatecne=true;
                    else if(c==3){
                        c++;
                        dodatecne=true;
                    }
                    else
                        c++;
                }
                else
                    c=0;


                fout<<"\t<td class=\""<<css_class[c]<<"\"> *"<<den2<<" </td>"<<endl;
                if(dodatecne){
                    if(c<PCSS-1)
                        c++;
                    else
                        c=0;
                }
                if(c==1 && i<(kalendar.size()/3)/*-3*/-3 && den2==kalendar[(i+1)*3] && mesic2==kalendar[((i+1)*3)+1] && rok2==kalendar[((i+1)*3)+2]){
                    c++;
                    i++;
                }

                i++;
                if(i==(kalendar.size()/3)-3 ){
                    den_v_t=den_v_t;//nevím proč, ale musí to tak byt :D bo když ne tak se nezalomí
                    while(den2<=dny_v_mesici(mesic2, rok2) ){
                        den2++;
                        den_v_t=nasledujici_den(den_v_t);
                        if(den_v_t<=7)
                            fout<<"\t<td class=\"nedef\"> "<<den2<<" </td>"<<endl;
                        if(den_v_t==7 || den_v_t==0)
                            fout<<"</tr>"<<endl;
                        if(den_v_t>=7 && den2<dny_v_mesici(mesic2, rok2) ){
                            fout<<"<tr>"<<endl;
                        }
                        if(den2==dny_v_mesici(mesic2, rok2) ){
                            while(den_v_t<=7){
                                den_v_t++;
                                fout<<"\t<td> </td>"<<endl;
                                //if(den_v_t==7)
                            }
                            fout<<"</tr>"<<endl<<"</table>"<<endl;
                        }
                    }
                }
            }
            else{
                if(start)
                    fout<<"\t<td class=\"nedef\"> "<<den2<<" </td>"<<endl;
                else
                    fout<<"\t<td class=\""<<css_class[c]<<"\"> "<<den2<<" </td>"<<endl;
            }


            if(den2==dny_v_mesici(mesic2, rok2) ){ //pokud je 1 den v měsící tak dat hodnotu true aby se mohl vytvořit následně další měsíc po ukončení aktuálního
                zacit_m=true;
                for(int j=1; j<den_v_t; j++)
                    fout<<"\t<td> </td>"<<endl;
                fout<<"</tr>"<<endl<<"</table>"<<endl;
                dokoncit=true;
            }
            den_v_t = nasledujici_den(den_v_t);
            den2 = nasledujici_den_v_mesici(den2, mesic2, rok2);
            if(den2==1)
                mesic2 = nasledujici_mesic(mesic2);
            if(mesic2==1 && den2==1)
                rok2++;

            if(den_v_t==1 && !dokoncit)
                fout<<"</tr>"<<endl;
            dokoncit = false;
        }

    fout<<"</BODY>"<<endl<<"</HTML>"<<endl;
    fout.close();//zavření souboru

    prikazy("-mm");
}
