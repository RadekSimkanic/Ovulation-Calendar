/**
 *\brief Funkce.
 *
 *\details Soubor plný užitečných funkcí.
 */

#include<iostream>
#include<string>
#include<string.h>
#include<time.h>
#include <vector>
#include <sstream>
using namespace std;

const int pocet_mesicu=12;
/**
 *\brief      Pole se svátky
 *\details    Pole o velikosti 12 x 31 slouží v tydenním módu pro demonstrování kdy je jaký svátek
 */

const char *s[pocet_mesicu][31]=
{
    {
        "je Nový rok",
        "má svátek Karina",
        "má svátek Radmila",
        "má svátek Diana",
        "má svátek Dalimil",
        "je Tří králů",
        "má svátek Vilma",
        "má svátek Čestmír",
        "má svátek Vladan",
        "má svátek Břetislav",
        "má svátek Bohdana",
        "má svátek Pravoslav",
        "má svátek Edita",
        "má svátek Radovan",
        "má svátek Alice",
        "má svátek Ctirad",
        "má svátek Drahoslav",
        "má svátek Vladislav",
        "má svátek Doubravka",
        "má svátek Ilona",
        "má svátek Běla",
        "má svátek Slavomír",
        "má svátek Zdeněk",
        "má svátek Milena",
        "má svátek Miloš",
        "má svátek Zora",
        "má svátek Ingrid",
        "má svátek Otýlie",
        "má svátek Zdislava",
        "má svátek Robin",
        "má svátek Marika"
    },
    {
        "má svátek Hynek",
        "má svátek Nela",
        "má svátek Blažej",
        "má svátek Jarmila",
        "má svátek Dobromila",
        "má svátek Vanda",
        "má svátek Veronika",
        "má svátek Milada",
        "má svátek Apolena",
        "má svátek Mojmír",
        "má svátek Božena",
        "má svátek Slavěna",
        "má svátek Věnceslav",
        "má svátek Valentýn",
        "má svátek Jiřina",
        "má svátek Ljuba",
        "má svátek Miloslava",
        "má svátek Gizela",
        "má svátek Patrik",
        "má svátek Oldřich",
        "má svátek Lenka",
        "má svátek Petr",
        "má svátek Svatopluk",
        "má svátek Matěj",
        "má svátek Liliana",
        "má svátek Dorota",
        "má svátek Alexandr",
        "má svátek Lumír",
        "má svátek Horymír"
    },
    {
        "má svátek Bedřich",
        "má svátek Anežka",
        "má svátek Kamil",
        "má svátek Stela",
        "má svátek Kazimír",
        "má svátek Miroslav",
        "má svátek Tomáš",
        "má svátek Gabriela",
        "má svátek Františka",
        "má svátek Viktorie",
        "má svátek Anděla",
        "má svátek Řehoř",
        "má svátek Růžena",
        "má svátek Matylda a Rút",
        "má svátek Ida",
        "má svátek Elena a Herbert",
        "má svátek Vlastimil",
        "má svátek Eduard",
        "má svátek Josef",
        "má svátek Světlana",
        "má svátek Radek",
        "má svátek Leona",
        "má svátek Ivona",
        "má svátek Gabriel",
        "má svátek Marián",
        "má svátek Emanuel",
        "má svátek Dita",
        "má svátek Soňa",
        "má svátek Taťána",
        "má svátek Arnošt",
        "má svátek Kvido"
    },
    {
        "má svátek Hugo",
        "má svátek Erika",
        "má svátek Richard",
        "má svátek Ivana",
        "má svátek Miroslava",
        "má svátek Vendula",
        "má svátek Hermína",
        "má svátek Ema",
        "má svátek Dušan",
        "má svátek Darja",
        "má svátek Izabela",
        "má svátek Julius",
        "má svátek Aleš",
        "má svátek Vincenc",
        "má svátek Anastázie",
        "má svátek Irena",
        "má svátek Rudolf",
        "má svátek Valérie",
        "má svátek Rostislav",
        "má svátek Marcela",
        "má svátek Alexandra",
        "má svátek Evžénie",
        "má svátek Vojtěch",
        "má svátek Jiří",
        "má svátek Marek",
        "má svátek Oto",
        "má svátek Jaroslav",
        "má svátek Vlastislav",
        "má svátek Robert",
        "má svátek Blahoslav"
    },
    {
        "je Svátek práce",
        "má svátek Zikmund",
        "má svátek Alexej",
        "má svátek Květoslav",
        "má svátek Klaudie",
        "má svátek Radoslav",
        "má svátek Stanislav",
        "je Statní svátek - Den vítězství",
        "má svátek Ctibor",
        "má svátek Blažena",
        "má svátek Svatava",
        "má svátek Pankrác",
        "má svátek Servác",
        "má svátek Bonifác",
        "má svátek Žofie",
        "má svátek Přemysl",
        "má svátek Aneta",
        "má svátek Nataša",
        "má svátek Ivo",
        "má svátek Zbyšek",
        "má svátek Monika",
        "má svátek Emil",
        "má svátek Vladimír",
        "má svátek Jana",
        "má svátek Viola",
        "má svátek Filip",
        "má svátek Valdemar",
        "má svátek Vilém",
        "má svátek Maxim",
        "má svátek Ferdinand",
        "má svátek Kamila"
    },
    {
        "má svátek Laura",
        "má svátek Jarmil",
        "má svátek Tamara",
        "má svátek Dalibor",
        "má svátek Dobroslav",
        "má svátek Norbert",
        "má svátek Iveta",
        "má svátek Medard",
        "má svátek Stanislava",
        "má svátek Gita",
        "má svátek Bruno",
        "má svátek Antonie",
        "má svátek Antonín",
        "má svátek Roland",
        "má svátek Vít",
        "má svátek Zbyněk",
        "má svátek Adolf",
        "má svátek Milan",
        "má svátek Leoš",
        "má svátek Květa",
        "má svátek Alois",
        "má svátek Pavla",
        "má svátek Zdeňka",
        "má svátek Jan",
        "má svátek Ivan",
        "má svátek Adriana",
        "má svátek Ladislav",
        "má svátek Lubomír",
        "má svátek Petr a Pavel",
        "má svátek Šárka"
    },
    {
        "má svátek Jaroslava",
        "má svátek Patricie",
        "má svátek Radomír",
        "má svátek Prokop",
        "je Státní svátek - Cyril a Metoděj, má svátek Cyril a Metoděj",
        "je Státní svátek - Mistr Jan Hus",
        "má svátek Bohuslava",
        "má svátek Nora",
        "má svátek Drahoslava",
        "má svátek Libuše",
        "má svátek Olga",
        "má svátek Bořek",
        "má svátek Markéta",
        "má svátek Karolína",
        "má svátek Jindřich",
        "má svátek Luboš",
        "má svátek Martina",
        "má svátek Drahomíra",
        "má svátek Čeněk",
        "má svátek Ilja",
        "má svátek Vítězslav",
        "má svátek Magdaléna",
        "má svátek Libor",
        "má svátek Kristýna",
        "má svátek Jakub",
        "má svátek Anna",
        "má svátek Věroslav",
        "má svátek Viktor",
        "má svátek Marta",
        "má svátek Bořivoj",
        "má svátek Ignác"
    },
    {
        "má svátek Oskar",
        "má svátek Gustav",
        "má svátek Miluše",
        "má svátek Dominik",
        "má svátek Kristián",
        "má svátek Oldřiška",
        "má svátek Lada",
        "má svátek Soběslav",
        "má svátek Roman",
        "má svátek Vavřinec",
        "má svátek Zuzana",
        "má svátek Klára",
        "má svátek Alena",
        "má svátek Alan",
        "má svátek Hana",
        "má svátek Jáchym",
        "má svátek Petra",
        "má svátek Helena",
        "má svátek Ludvík",
        "má svátek Bernard",
        "má svátek Johana",
        "má svátek Bohuslav",
        "má svátek Sandra",
        "má svátek Bartoloměj",
        "má svátek Radim",
        "má svátek Luděk",
        "má svátek Otakar",
        "má svátek Augustýn",
        "má svátek Evelína",
        "má svátek Vladěna",
        "má svátek Pavlína"
    },
    {
        "má svátek Linda a Samuel",
        "má svátek Adéla",
        "má svátek Bronislav",
        "má svátek Jindřiška",
        "má svátek Boris",
        "má svátek Boleslav",
        "má svátek Regína",
        "má svátek Mariana",
        "má svátek Daniela",
        "má svátek Irma",
        "má svátek Denisa",
        "má svátek Marie",
        "má svátek Lubor",
        "má svátek Radka",
        "má svátek Jolana",
        "má svátek Ludmila",
        "má svátek Naděžda",
        "má svátek Kryštof",
        "má svátek Zita",
        "má svátek Oleg",
        "má svátek Matouš",
        "má svátek Darina",
        "má svátek Berta",
        "má svátek Jaromír",
        "má svátek Zlata",
        "má svátek Andrea",
        "má svátek Jonáš",
        "má svátek Václav",
        "má svátek Michal",
        "má svátek Jeroným"
    },
    {
        "má svátek Igor",
        "má svátek Olívie a Oliver",
        "má svátek Bohumil",
        "má svátek František",
        "má svátek Eliška",
        "má svátek Hanuš",
        "má svátek Justýna",
        "má svátek Věra",
        "má svátek Sára a Štefan",
        "má svátek Marina",
        "má svátek Andrej",
        "má svátek Marcel",
        "má svátek Renáta",
        "má svátek Agáta",
        "má svátek Tereza",
        "má svátek Havel",
        "má svátek Hedvika",
        "má svátek Lukáš",
        "má svátek Michaela",
        "má svátek Vendelín",
        "má svátek Brigita",
        "má svátek Sabina",
        "má svátek Teodor",
        "má svátek Nina",
        "má svátek Beáta",
        "má svátek Erik",
        "má svátek Šarlota",
        "je Státní svátek",
        "má svátek Silvie",
        "má svátek Tadeáš",
        "má svátek Štěpánka"
    },
    {
        "má svátek Felix",
        "je Památka zesnulých",
        "má svátek Hubert",
        "má svátek Karel",
        "má svátek Miriam",
        "má svátek Liběna",
        "má svátek Saskie",
        "má svátek Bohumír",
        "má svátek Bohdan",
        "má svátek Evžen",
        "má svátek Martin",
        "má svátek Benedikt",
        "má svátek Tibor",
        "má svátek Sáva",
        "má svátek Leopold",
        "má svátek Otmar",
        "má svátek Mahuléna",
        "má svátek Romana",
        "má svátek Alžběta",
        "má svátek Nikola",
        "má svátek Albert",
        "má svátek Cecílie",
        "má svátek Klement",
        "má svátek Emílie",
        "má svátek Kateřina",
        "má svátek Artur",
        "má svátek Xenie",
        "má svátek René",
        "má svátek Zina",
        "má svátek Ondřej"
    },
    {
        "má svátek Iva",
        "má svátek Blanka",
        "má svátek Svatoslav",
        "má svátek Barbora",
        "má svátek Jitka",
        "má svátek Mikuláš",
        "má svátek Ambrož",
        "má svátek Květoslava",
        "má svátek Vratislav",
        "má svátek Julie",
        "má svátek Dana",
        "má svátek Simona",
        "má svátek Lucie",
        "má svátek Lýdie",
        "má svátek Radana",
        "má svátek Albína",
        "má svátek Daniel",
        "má svátek Miloslav",
        "má svátek Ester",
        "má svátek Dagmar",
        "má svátek Natálie",
        "má svátek Šimon",
        "má svátek Vlasta",
        "je Štědrý den, má svátek Adam a Eva",
        "je 1.svátek vánoční",
        "je 2. svátek vánoční, má svátek Štěpán",
        "má svátek Žaneta",
        "má svátek Bohumila",
        "má svátek Judita",
        "má svátek David",
        "má svátek Silvestr"
    }
};





/**
 *\brief                prestupny_rok - Přestupný rok
 *\details              Funkce, která ověří klasickými způsoby zda daný rok je přestupný.
 *\param[in]    rok     (int) Číslo roku k ověření.
 *\return               (bool) [true] přestupný; [false] nepřestupný
 */
bool prestupny_rok(int rok){ //v gregorianském kalendáři nastáva chyba a to: každých 2620 let schází 1 den - dalo by se to podle mě vyřešit tak že následující rok by byl také přestupný, ale tak že by únor měl 30 případně 29 dní místo 29 či 28 - pouze by se přidál jeden den
    bool bool_v=false;
    if (rok % 4 == 0){
		bool_v = true;
		if (rok % 100 == 0 && rok % 400 == 0){
			bool_v = true;
		}
		else{
            if (rok % 100 == 0 && rok % 400 != 0)
                bool_v = false;
		}
	}
    return bool_v;
}

/**
 *\brief                prestupny_rok2 - Přestupný rok 2 (v programu se tato funkce nepoužívá)
 *\details              Funkce, která ověří zda daný rok je přestupný. Ukazuje jak by se dál řešit problém v gregorianském kalendáři který nastává každých 2620 let.
 *\param[in]    rok     (int) Číslo roku k ověření.
 *\return               (int) počet dnů v přestupném roce pro vyrovnání (0 - 2).
 */
int prestupny_rok2(int rok){ //tato funkce je ukázka jak by se mohl vyřešít problém v gregorianském kalendáři který nastává každých 2620 let
    int dnu=0;
    if (rok % 4 == 0){
		dnu = 1;
		if (rok % 100 == 0 && rok % 400 == 0){
			dnu = 1;
		}
		else{
            if (rok % 100 == 0 && rok % 400 != 0)
                dnu = 0;
		}
    }
    if(rok%2620 && rok>0)
        dnu+=1;
    return dnu;
}

/**
 *\brief                dny_v_mesici - Dny v měsící
 *\details              Funkce, která zjistí kolik dní má daný měsíc.
 *\param[in]    mesic   (int) Číslo měsíce k ověření.
 *\param[in]    rok     (int) Číslo roku ve kterém se zjišťovaný měsíc nachází.
 *\return               (int) počet dnů (0 - 31).
 */
int dny_v_mesici(int cislo_mesice, int rok){ //počet dnů v měsící
    int prestupny_mesic = 28;
    if (prestupny_rok(rok))
        prestupny_mesic = 29;
    int dny[pocet_mesicu] = {31, prestupny_mesic, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return dny[cislo_mesice-1];
}

/**
 *\brief                nasledujici_mesic - Následující měsíc
 *\details              Funkce, která zjistí jaký je následující měsíc.
 *\param[in]    mesic   (int) Číslo aktuálního měsíce.
 *\return               (int) Číslo následujícího měsíce (1 - 12).
 */
int nasledujici_mesic(int cislo_mesice){
    if(cislo_mesice==12)
        return 1;
    else
        return cislo_mesice + 1;
}

/**
 *\brief                predchozi_mesic - Předchozí měsíc
 *\details              Funkce, která zjistí jaký je předchozí měsíc.
 *\param[in]    mesic   (int) Číslo aktuálního měsíce.
 *\return               (int) Číslo předchozího měsíce (1 - 12).
 */
int predchozi_mesic(int cislo_mesice){
    if(cislo_mesice==1)
        return 12;
    else
        return cislo_mesice - 1;
}

/**
 *\brief                nasledujici_den - Následující den v týdnu
 *\details              Funkce, která zjistí jaký je následující den v týdnu.
 *\param[in]    den     (int) Číslo aktuálního dne v týdnu.
 *\return               (int) Číslo následujícího dne v týdnu (1 - 7).
 */
int nasledujici_den(int cislo_dne){
    if(cislo_dne==7)
        return 1;
    else
        return cislo_dne + 1;
}

/**
 *\brief                predchozi_den - Předchozí den v týdnu
 *\details              Funkce, která zjistí jaký je předchozí den v týdnu.
 *\param[in]    den     (int) Číslo aktuálního dne v týdnu.
 *\return               (int) Číslo předchozího dne v týdnu (1 - 7).
 */
int predchozi_den(int cislo_dne){
    if(cislo_dne==1)
        return 7;
    else
        return cislo_dne - 1;
}

/**
 *\brief                dnu_v_roce - Dnů v roce
 *\details              Funkce, která zjistí kolik dnů je v daném roce.
 *\param[in]    den     (int) Číslo aktuálního roku.
 *\return               (int) Počet dnů (365, 366).
 */
int dnu_v_roce(int rok){
    if(prestupny_rok(rok))
        return 366;
    else
        return 365;
}

/**
 *\brief                posun_mesice_roky - Posun měsíce roky
 *\details              Funkce, která zjistí jaký je následující rok a měsíc při daném krokování od aktuálního (zadáného) data.
 *\param[in]    next    (int) Počet roků.
 *\param[in]    smer    (bool) Směr [true] vpřed; [false] zpět.
 *\param[in]    mesic   (int) Aktuální měsíc.
 *\param[in]    rok     (int) Aktuální rok.
 *\param[out]   vystup  (int)[0] Následující rok; (int)[1] Následující měsíc.
 *\return               (void).
 */
void posun_mesice_roky(int next, bool smer, int mesic, int rok, int *vystup){ //smer - pokud je true tak je to jako dopředu a naopak
    for(;next!=0;next--){
        if(smer){
            mesic = nasledujici_mesic(mesic);
            if(mesic==1)
                rok++;
        }
        else{
            mesic = predchozi_mesic(mesic);
            if(mesic==12)
                rok--;
        }
    }
    vystup[0] = rok;
    vystup[1] = mesic;
    //int array[2]={rok, mesic};
    //return array;
}


/**
 *\brief                pocet_dnu - Počet dnů
 *\details              Funkce, která zjistí kolik je dnů mezi dvěma daty. Je jedno pokud se zadá napřed menší datum a pak větší nebo naopak.
 *\param[in]    den     (int) Den z data 1.
 *\param[in]    mesic   (int) Měsíc z data 1.
 *\param[in]    rok     (int) Rok z data 1.
 *\param[in]    den2    (int) Den z data 2.
 *\param[in]    mesic2  (int) Měsíc z data 2.
 *\param[in]    rok2    (int) Rok z data 2.
 *\return               (int) počet dnů.
 */
int pocet_dnu(int den, int mesic, int rok, int den2, int mesic2, int rok2){// druhý datum musí byt vždy vyšší - v opačném připadě se přehodí
    int pocet_dnu=0;

    if( ( (rok*10000)+(mesic*100)+(den) ) > ( (rok2*10000)+(mesic2*100)+(den2) ) ){
        int x = rok;
        int y = mesic;
        int z = den;
        rok = rok2;
        mesic = mesic2;
        den = den2;
        rok2 = x;
        mesic2 = y;
        den2 = z;
    }
    int pocet_dnu_1=dny_v_mesici(mesic, rok)-den;
    int pocet_dnu_2=den2;
    for(int i=1; mesic+i<=12; i++){//pocet dnu do konce roku
        pocet_dnu_1+=dny_v_mesici(mesic+i, rok);
    }
    for(int i=1; mesic2-i>=1; i++){//pocet dnu od zacatku roku
        pocet_dnu_2+=dny_v_mesici(mesic2-i, rok2);
    }
    for(int i=1; rok+i<rok2;i++){//pocet dnu mezi roky
        pocet_dnu+=dnu_v_roce(rok+i);
    }

    if(rok==rok2 && mesic==mesic2)
        pocet_dnu=pocet_dnu_2-(dnu_v_roce(rok)-pocet_dnu_1);
    else if(rok==rok2){
        pocet_dnu=pocet_dnu_2-(dnu_v_roce(rok)-pocet_dnu_1);//dnu_v_roce(rok)-pocet_dnu_2+pocet_dnu_1-1;
    }
    else
        pocet_dnu=pocet_dnu+pocet_dnu_1+pocet_dnu_2;
    return pocet_dnu;
}

/**
 *\brief                generator_dnu - Generátor dnů
 *\details              Funkce, která vypočítá měsíc, rok, atd v konečném měsící podle počtu kroků z aktuálního data (nevolitelného - synchronizace).
 *\param[in]    next    (int) Počet kroků.
 *\param[in]    smer    (bool) Směr k získání konečného měsíce [true] vpřed; [false] zpět.
 *\param[out]   pole    (int)[6] Data s výstupem: [0] Den v týdnu aktuálního dne; [1] Počet dnů v aktuálnímm měsící; [2] Výpočítány konečný měsíc; [3] Výpočítány konečný rok; [4] Den v týdnu, kterým začíná vypočtený měsíc; [5] Den v aktuálním měsící.
 *\return               (void).
 */
void generator_dnu(int next, bool smer, int *pole){ //smer - pokud je true tak je to jako dopředu a naopak
    time_t t;

    struct tm *pt;
    t = time(NULL);
    pt = localtime(&t);
    //synchronizace kalendaře - dá se to i pevně nadefinovat bez času. V tom případě by kalendař nebyl na aktuální stránce.
    int den = pt->tm_mday; // den v mesici 1 - 31
    int den_v_tydnu = predchozi_den(pt->tm_wday+1);//1 - pondeli 2 - utery ...
    int mesic = pt->tm_mon+1;//1 - leden, 2 - unor ...
    int rok = pt->tm_year+1900;


    int posun_data[2];
    posun_mesice_roky(next, smer, mesic, rok, posun_data); //[0] - novy rok [1] - novy mesic

    int dnu_v_mesici = dny_v_mesici(posun_data[1], posun_data[0]);
/////////
    int pocet = pocet_dnu(den, mesic, rok, 1, posun_data[1], posun_data[0]);
////////

    int pricist = pocet%7;

    int prvni_den_v_mesici=den_v_tydnu;

    if(smer && next>0){
        for(; pricist!=0; pricist--){
            prvni_den_v_mesici = nasledujici_den(prvni_den_v_mesici);
        }
    }
    else{
        for(; pricist!=0; pricist--){
            prvni_den_v_mesici = predchozi_den(prvni_den_v_mesici);
        }
    }

    pole[0]=den_v_tydnu;
    pole[1]=dnu_v_mesici;
    pole[2]=posun_data[1];
    pole[3]=posun_data[0];
    pole[4]=prvni_den_v_mesici;
    pole[5]=den;


}

/**
 *\brief                nasledujici_den_v_mesici - Následující den v měsící
 *\details              Funkce, která zjistí jaký je následující den v měsící.
 *\param[in]    den     (int) Číslo aktuálního dne v měsící.
 *\param[in]    mesic   (int) Číslo aktuálního měsíce.
 *\param[in]    rok     (int) Číslo aktuálního roku.
 *\return               (int) Číslo následujícího dne v měsící (1 - 31).
 */
int nasledujici_den_v_mesici(int den, int mesic, int rok){
    int nden=0;
    if(den == dny_v_mesici(mesic, rok)){
        nden=1;
    }
    else{
        nden=den+1;
    }

    return nden;
}

/**
 *\brief                predchozi_den_v_mesici - Předchozí den v měsící
 *\details              Funkce, která zjistí jaký je předchozí den v měsící.
 *\param[in]    den     (int) Číslo aktuálního dne v měsící.
 *\param[in]    mesic   (int) Číslo aktuálního měsíce.
 *\param[in]    rok     (int) Číslo aktuálního roku.
 *\return               (int) Číslo předchozího dne v měsící (1 - 31).
 */
int predchozi_den_v_mesici(int den, int mesic, int rok){
    int nden=0;
    int nmesic=mesic;
    int nrok=rok;
    if(den == 1){
        nmesic = predchozi_mesic(nmesic);
        if(nmesic==12)
            nrok--;
        nden=dny_v_mesici(nmesic, nrok);
    }
    else{
        nden=den-1;
    }

    return nden;
}

/**
 *\brief                tydenni_posun_mesice_roky - Týdenní posun měsíce roky
 *\details              Funkce, která zjistí jaký je den, měsíc a rok ve vypočteném týdením bloku, který se vypočítá počtem kroků od zadaného data.
 *\param[in]    next    (int) Počet kroků.
 *\param[in]    smer    (bool) Směr krokování [true] vpřed; [false] zpět.
 *\param[in]    den     (int) Den zadaného data.
 *\param[in]    mesic   (int) Měsíc zadaného data.
 *\param[in]    rok     (int) Rok zadaného data.
 *\param[out]   vystup  (int)[3] Výstup start dne vypočteného týdne [0] rok; [1] měsíc; [2] rok.
 *\return               (void).
 */
void tydenni_posun_mesice_roky(int next, bool smer, int den, int mesic, int rok, int *vystup){ //smer - pokud je true tak je to jako dopředu a naopak
    int start_den=den;
    for(;next!=0;next--){
        if(smer){
            if(start_den<=dny_v_mesici(mesic, rok)-7 )
                start_den+=7;
            else{
                start_den=7-(dny_v_mesici(mesic, rok)-start_den);
                mesic=nasledujici_mesic(mesic);
            }
            if(mesic==1 && start_den<=7)
                rok++;
        }
        else{
            if(start_den>7)
                start_den-=7;
            else{
                start_den-=7;
                mesic=predchozi_mesic(mesic);
                if(mesic==12)
                    rok--;
                start_den=dny_v_mesici(mesic, rok)+start_den;
            }
        }
    }
    vystup[0] = rok;
    vystup[1] = mesic;
    vystup[2] = start_den;
}

/**
 *\brief                tydenni_generator_dnu - Týdenní generátor dnů
 *\details              Funkce, která zjistí jaký je den, měsíc a rok ve vypočteném týdením bloku, který se vypočítá počtem kroků od aktualního data.
 *\param[in]    next    (int) Počet kroků.
 *\param[in]    smer    (bool) Směr krokování [true] vpřed; [false] zpět.
 *\param[out]   vystup  (int)[3] Výstup start dne vypočteného týdne [0] rok; [1] měsíc; [2] rok.
 *\return               (void).
 */
void tydenni_generator_dnu(int next, bool smer, int *pole){
    time_t t;

    struct tm *pt;
    t = time(NULL);
    pt = localtime(&t);
    //synchronizace kalendaře - dá se to i pevně nadefinovat bez času. V tom případě by kalendař nebyl na aktuální stránce.
    int den = pt->tm_mday; // den v mesici 1 - 31
    int den_v_tydnu = predchozi_den(pt->tm_wday+1);//1 - pondeli 2 - utery ...
    int mesic = pt->tm_mon+1;//1 - leden, 2 - unor ...
    int rok = pt->tm_year+1900;

    int posun_data[3];
    tydenni_posun_mesice_roky(next, smer, den, mesic, rok, posun_data);

    pole[0]=den_v_tydnu;
    pole[1]=posun_data[2];//start den
    pole[2]=posun_data[1];//start mesic
    pole[3]=posun_data[0];//start rok
    pole[4]=dny_v_mesici(posun_data[1], posun_data[0]);
    //pole[5]=den;

}

/**
 *\brief                vypis_cislo - Výpis číslo
 *\details              Vypíše číslo zarovnané na dvě cifry.
 *\param[in]    cislo   (int) Číslo připraveno na vypis.
 *\return               (void).
 */
void vypis_cislo(int cislo){
    if(cislo<10)
        cout<<" "<<cislo;
    else
        cout<<cislo;
}

/**
 *\brief                den_v_tydnu - Den v týdnu
 *\details              Funkce zjistí, který den v týdnu, je zadané datum.
 *\param[in]    den     (int) Den zadaného data.
 *\param[in]    mesic   (int) Mesic zadaného data.
 *\param[in]    rok     (int) Rok zadaného data.
 *\return               (int) Den v týdnu (1 - 7).
 */
int den_v_tydnu(int den, int mesic, int rok){
    time_t t;

    struct tm *pt;
    t = time(NULL);
    pt = localtime(&t);

    //synchronizace kalendaře - dá se to i pevně nadefinovat bez času. V tom případě by kalendař nebyl na aktuální stránce.
    int den2 = pt->tm_mday; // den v mesici 1 - 31
    //cout<<"original: "<<den2<<endl;
    int den_v_tydnu = predchozi_den(pt->tm_wday+1);//1 - pondeli 2 - utery ...
    int mesic2 = pt->tm_mon+1;//1 - leden, 2 - unor ...
    int rok2 = pt->tm_year+1900;
    bool smer=false;
    if( ( (rok*10000)+(mesic*100)+(den) ) > ( (rok2*10000)+(mesic2*100)+(den2) ) )
        smer=true;

    int pocet = pocet_dnu(den2, mesic2, rok2, den, mesic, rok);

    int posun = pocet - ( ( (int) pocet/7)*7);

    for(;0<posun;posun--)
        if(smer)
            den_v_tydnu = nasledujici_den(den_v_tydnu);
        else
            den_v_tydnu = predchozi_den(den_v_tydnu);
    return den_v_tydnu;
}

/**
 *\brief                svatky - Svatky
 *\details              Funkce, která vypíše v daný den svátek (jmén či státní svátky).
 *\param[in]    den     (int) Den zadaného data.
 *\param[in]    mesic   (int) Mesic zadaného data.
 *\return               (void).
 */
void svatky(int mesic, int den){
    char const *vystup = s[mesic-1][den-1];
    cout<<vystup;
}

/**
 *\brief                dalsi_menstruace - Další menstruace
 *\details              Funkce zjistí, kdy bude další menstruace, ovulace apod.
 *\param[in]    rok     (int) Rok zadaného data.
 *\param[in]    mesic   (int) Mesic zadaného data.
 *\param[in]    den     (int) Den zadaného data.
 *\param[in]    cyklus  (int) Délka menstruačního cyklu.
 *\param[in]    delka_m (int) Délka menstruace.
 *\param[out]   pole    (int) [21] Výstupní pole. [0] Menstruace den; [1] Menstruace měsíc; [2] Menstruace rok; [3] Konec předchozí menstruace den; [4] Konec předchozí menstruace měsíc; [5] Konec předchozí menstruace rok; [6] Ovulace den; [7] Ovulace měsíc; [8] Ovulace rok; [9] Začátek velmi plodných dnů - den; [10] Začátek velmi plodných dnů - měsíc; [11] Začátek velmi plodných dnů - rok; [12] Konec velmi plodných dnů - den; [13] Konec velmi plodných dnů - měsíc; [14] Konec velmi plodných dnů - rok; [15] Začátek neplodných dnů - den; [16] Začátek neplodných dnů - měsíc; [17] Začátek neplodných dnů - rok; [18] Konec neplodných dnů - den; [19] Konec neplodných dnů - měsíc; [20] Konec neplodných dnů - rok
 *\return               (bool) [true] vše proběhlo ok; [false] chyba.
 */
bool dalsi_menstruace(int rok, int mesic, int den, int cyklus, int delka_m, int * pole){//tato funkce udělá výpočet do další menstruace
    bool b = true;
    int menstruace_den_z=den;
    int menstruace_mesic_z=mesic;
    int menstruace_rok_z=rok;

    int menstruace_den_k=den;
    int menstruace_mesic_k=mesic;
    int menstruace_rok_k=rok;

    int ovulace_den=0;
    int ovulace_mesic=0;
    int ovulace_rok=0;

    int velmiplodne_den_z=den;
    int velmiplodne_mesic_z=mesic;
    int velmiplodne_rok_z=rok;

    int velmiplodne_den_k=0;
    int velmiplodne_mesic_k=0;
    int velmiplodne_rok_k=0;

    int neplodne_den_z=0;
    int neplodne_mesic_z=0;
    int neplodne_rok_z=0;

    int neplodne_den_k=0;
    int neplodne_mesic_k=0;
    int neplodne_rok_k=0;

    if(den>0 && den<=31 && mesic>0 && mesic<=12 && cyklus>0 && delka_m>0){
        for(int i=1;i<delka_m; i++){//menstruace konec
            menstruace_den_k=nasledujici_den_v_mesici(menstruace_den_k, menstruace_mesic_k, menstruace_rok_k);
            if(menstruace_den_k==1)
                menstruace_mesic_k=nasledujici_mesic(menstruace_mesic_k);
            if(menstruace_mesic_k==1 && menstruace_den_k==1)
                menstruace_rok_k++;
        }

        for(int i=0; i<cyklus; i++){//další menstruace začátek
            menstruace_den_z=nasledujici_den_v_mesici(menstruace_den_z, menstruace_mesic_z, menstruace_rok_z);
            if(menstruace_den_z==1)
                menstruace_mesic_z=nasledujici_mesic(menstruace_mesic_z);
            if(menstruace_mesic_z==1 && menstruace_den_z==1)
                menstruace_rok_z++;
        }

        /*for(int i=0; i<(((int)cyklus/2)-2); i++){//velmi plodné dny začátek
            velmiplodne_den_z=nasledujici_den_v_mesici(velmiplodne_den_z, velmiplodne_mesic_z, velmiplodne_rok_z);
            if(velmiplodne_den_z==1)
                velmiplodne_mesic_z=nasledujici_mesic(velmiplodne_mesic_z);
            if(velmiplodne_mesic_z==1 && velmiplodne_den_z==1)
                velmiplodne_rok_z++;
        }*/

        for(int i=0; i<(12+(cyklus-28)); i++){//velmi plodné dny začátek
            velmiplodne_den_z=nasledujici_den_v_mesici(velmiplodne_den_z, velmiplodne_mesic_z, velmiplodne_rok_z);
            if(velmiplodne_den_z==1)
                velmiplodne_mesic_z=nasledujici_mesic(velmiplodne_mesic_z);
            if(velmiplodne_mesic_z==1 && velmiplodne_den_z==1)
                velmiplodne_rok_z++;
        }
        neplodne_den_k=velmiplodne_den_z;
        neplodne_mesic_k=velmiplodne_mesic_z;
        neplodne_rok_k=velmiplodne_rok_z;
        int ndk;
        for(int i=0; i<4; i++){
            ndk=neplodne_den_k;
            neplodne_den_k=predchozi_den_v_mesici(neplodne_den_k, neplodne_mesic_k, neplodne_rok_k);
            if(ndk==1/*dny_v_mesici(neplodne_mesic_k,neplodne_rok_k)*/ ) //if(nasledujici_den_v_mesici(neplodne_den_k, neplodne_mesic_k, neplodne_rok_k)==1
                neplodne_mesic_k=predchozi_mesic(neplodne_mesic_k);
            if(neplodne_mesic_k==12 && neplodne_den_k==dny_v_mesici(12, neplodne_rok_k) )
                neplodne_rok_k--;
        }

        velmiplodne_den_k=velmiplodne_den_z;
        velmiplodne_mesic_k=velmiplodne_mesic_z;
        velmiplodne_rok_k=velmiplodne_rok_z;
        for(int i=1; i<5; i++){//velmi plodné dny konec a ovulace
            velmiplodne_den_k=nasledujici_den_v_mesici(velmiplodne_den_k, velmiplodne_mesic_k, velmiplodne_rok_k);
            if(velmiplodne_den_k==1)
                velmiplodne_mesic_k=nasledujici_mesic(velmiplodne_mesic_k);
            if(velmiplodne_mesic_k==1 && velmiplodne_den_k==1)
                velmiplodne_rok_k++;
            if(i==2){
                ovulace_den=velmiplodne_den_k;
                ovulace_mesic=velmiplodne_mesic_k;
                ovulace_rok=velmiplodne_rok_k;
            }
        }
        neplodne_den_z=velmiplodne_den_k;
        neplodne_mesic_z=velmiplodne_mesic_k;
        neplodne_rok_z=velmiplodne_rok_k;
        for(int i=0; i<4; i++){//nasledující neplodné dny začátek
            neplodne_den_z=nasledujici_den_v_mesici(neplodne_den_z, neplodne_mesic_z, neplodne_rok_z);
            if(neplodne_den_z==1)
                neplodne_mesic_z=nasledujici_mesic(neplodne_mesic_z);
            if(neplodne_mesic_z==1 && neplodne_den_z==1)
                neplodne_rok_z++;
        }

        pole[0]=    menstruace_den_z;   //Další menstruace DEN
        pole[1]=    menstruace_mesic_z; //Další menstruace MESIC
        pole[2]=    menstruace_rok_z;   //Další menstruace ROK

        pole[3]=    menstruace_den_k;   //Konec předchozí menstruace DEN
        pole[4]=    menstruace_mesic_k; //Konec předchozí menstruace MESIC
        pole[5]=    menstruace_rok_k;   //Konec předchozí menstruace ROK

        pole[6]=    ovulace_den;        //Ovulace - nejlplodnější den DEN
        pole[7]=    ovulace_mesic;      //Ovulace - nejlplodnější den MESIC
        pole[8]=    ovulace_rok;        //Ovulace - nejlplodnější den ROK

        pole[9]=    velmiplodne_den_z;  //Začátek velmi plodných dnů DEN
        pole[10]=   velmiplodne_mesic_z;    //Začátek velmi plodných dnů MESIC
        pole[11]=   velmiplodne_rok_z;  //Začátek velmi plodných dnů ROK

        pole[12]=   velmiplodne_den_k;  //Konec velmi plodných dnů DEN
        pole[13]=   velmiplodne_mesic_k;//Konec velmi plodných dnů MESIC
        pole[14]=   velmiplodne_rok_k;  //Konec velmi plodných dnů ROK

        pole[15]=   neplodne_den_z;     //Začátek neplodných dnů DEN
        pole[16]=   neplodne_mesic_z;   //Začátek neplodných dnů MESIC
        pole[17]=   neplodne_rok_z;     //Začátek neplodných dnů ROK

        pole[18]=   neplodne_den_k;     //Konec neplodných dnů DEN
        pole[19]=   neplodne_mesic_k;   //Konec neplodných dnů MESIC
        pole[20]=   neplodne_rok_k;     //Konec neplodných dnů ROK

    }
    else{
        b=false;
    }
    return b;
}

/**
 *\brief                krokovani_menstruace - Krokování menstruace
 *\details              Funkce zjistí, kdy budou další menstruace, ovulace apod. podle počtu kroků.
 *\param[in]    rok     (int) Rok zadaného data.
 *\param[in]    mesic   (int) Mesic zadaného data.
 *\param[in]    den     (int) Den zadaného data.
 *\param[in]    cyklus  (int) Délka menstruačního cyklu.
 *\param[in]    delka_m (int) Délka menstruace.
 *\param[in]    delka_m (int) Počet kroků.
 *\param[out]   kalendar (vector <int>&) [x] Výstupní pole. Po třech den/měsíc/rok: První den menstruace, Konec menstruace, Konec neplodných dnů, Začátek velmi plodných dnů, Ovulace, Konec plodných dnů, Začátek neplodných dnů, Začátek další menstruace
 *\return               (bool) [true] vše proběhlo ok, [false] chyba.
 */
bool krokovani_menstruace(int rok, int mesic, int den, int cyklus, int delka_m, int kroku, vector <int> &kalendar){
    if(den>0 && den<=31 && mesic>0 && mesic<=12 && cyklus>0 && delka_m>0 && kroku>=0  ){
        int pole[21];
        kalendar.push_back(den);    //První den menstruace DEN
        kalendar.push_back(mesic);  //První den menstruace MESIC
        kalendar.push_back(rok);    //První den menstruace ROK

        for(;kroku>0;kroku--){
            //dalsi_menstruace(pole[2], pole[1], pole[0], cyklus, delka_m, pole);
            dalsi_menstruace(rok, mesic, den, cyklus, delka_m, pole);
            den=        pole[0];
            mesic=      pole[1];
            rok=        pole[2];

            //Plnění vektoru
            kalendar.push_back(pole[3]);    //Konec menstruace DEN
            kalendar.push_back(pole[4]);    //Konec menstruace MESIC
            kalendar.push_back(pole[5]);    //Konec menstruace ROK

            if( ( (pole[20]*10000)+(pole[19]*100)+(pole[18]) ) < ( (pole[5]*10000)+(pole[4]*100)+(pole[3]) ) ){
                pole[18]=pole[3];
                pole[19]=pole[4];
                pole[20]=pole[5];
            }

            kalendar.push_back(pole[18]);   //Konec neplodných dnů DEN
            kalendar.push_back(pole[19]);   //Konec neplodných dnů MESIC
            kalendar.push_back(pole[20]);   //Konec neplodných dnů ROK

            kalendar.push_back(pole[9]);    //Začátek velmi plodných dnů DEN
            kalendar.push_back(pole[10]);   //Začátek velmi plodných dnůcMESIC
            kalendar.push_back(pole[11]);   //Začátek velmi plodných dnů ROK

            kalendar.push_back(pole[6]);    //Ovulace DEN
            kalendar.push_back(pole[7]);    //Ovulace MESIC
            kalendar.push_back(pole[8]);    //Ovulace ROK

            kalendar.push_back(pole[12]);   //Konec velmi plodných dnů DEN
            kalendar.push_back(pole[13]);   //Konec velmi plodných dnů MESIC
            kalendar.push_back(pole[14]);   //Konec velmi plodných dnů ROK

            kalendar.push_back(pole[15]);   //Začátek neplodných dnů DEN
            kalendar.push_back(pole[16]);   //Začátek neplodných dnů MESIC
            kalendar.push_back(pole[17]);   //Začátek neplodných dnů ROK

            kalendar.push_back(pole[0]);    //Začátek menstruace DEN
            kalendar.push_back(pole[1]);    //Začátek menstruace MESIC
            kalendar.push_back(pole[2]);    //Začátek menstruace ROK
        }
        return true;
    }
    else{
        return false;
    }
}

/**
 *\brief                comp_str - Compare string
 *\details              Funkce zjistí zda jsou si dva (char *) řetězce totožné.
 *\param[in]    str1    (char const *) První řetězec.
 *\param[in]    str2    (char const *) Druhý řetězec.
 *\return               (bool) [true] jsou shodné; [false] neshodné.
 */
bool comp_str(char const *str1, char const *str2){ //porovnání dvou stringu: true - stejné; false - jiné
    bool b = true;
    if(strlen(str1)==strlen(str2)){
        if(strspn(str1, str2)!=strlen(str1))
            b = false;
    }
    else
        b = false;
    return b;
}

/**
 *\brief                comp_str - Compare string
 *\details              Funkce zjistí zda jsou si dva (string) řetězce totožné.
 *\param[in]    str1    (string) První řetězec.
 *\param[in]    str2    (string) Druhý řetězec.
 *\return               (bool) [true] jsou shodné; [false] neshodné.
 */
bool comp_str(string str1, string str2){ //porovnání dvou stringu: true - stejné; false - jiné
    bool b = true;
    if(str1.size()==str2.size() ){
        if(str1.compare(str2)!=0)
            b = false;
    }
    else
        b = false;
    return b;
}

/**
 *\brief                int_dec - Is Integer
 *\details              Funkce zjistí zda vložený řetězec (char *) je číslo.
 *\param[in]    str     (char *) Číslo k ověření.
 *\return               (bool) [true] je číslo; [false] není číslo.
 */
bool int_dec(char *str){
    bool b = true;
    if(strlen(str)>0)
        for(unsigned int i=0; i<strlen(str); i++){
            if(!isdigit(str[i])){
                b=false;
                break;
            }
        }

    return b;
}

/**
 *\brief                int_dec - Is Integer
 *\details              Funkce zjistí zda vložený řetězec (string) je číslo.
 *\param[in]    str     (string) Číslo k ověření.
 *\return               (bool) [true] je číslo; [false] není číslo.
 */
bool int_dec(string str){
    bool b = true;
    if(str.size()>0)
        for(unsigned int i=0; i<str.size(); i++){
            if(!isdigit(str[i])){
                b=false;
                break;
            }
        }

    return b;
}

/**
 *\brief                split_string - Split String
 *\details              Funkce rozkouskuje větu na slova (příkazy) a vloží je do vectoru.
 *\param[in]    tosplit (string) Řetězec - věta.
 *\param[out]   splited (vector<string> &) Vector se slovy (příkazy).
 *\return               (void).
 */
void split_string(string tosplit, vector<string> & splited){
  // pomocna promenna
  string tmp;
  // vytvoreni vstupniho streamu ze predaneho stringu
  istringstream iss(tosplit);

  // dokud je co, tak ctem
  while (iss >> tmp) {
    // a cpem to do vectoru
    splited.push_back(tmp);
  }
}

/**
 *\brief                str_to_int - String to integer
 *\details              Funkce převede číselný řetězec (string) na číslo (integer).
 *\param[in]    str     (string) Čiselný řetězec.
 *\return               (int) číslo.
 */
int str_to_int(string str){
    istringstream is(str);
    int cislo;
    float cislo2;
    if(str.size()<10){
        is >> cislo;
    }
    else if(str.size()==10){
        is >> cislo2;
        if(cislo2>2147483647)
            cislo=2147483647;
        else
            cislo=(int) cislo2;
    }
    else
        cislo=2147483647;
    return cislo;
}

/**
 *\brief                char_array_to_string_vector - Char string array to string vector
 *\details              Funkce převede pole s řetězci (char) do vectoru (string).
 *\param[in]    pole    (char * []) Řetězce v polí.
 *\param[in]    start   (int) Od které pozice se má začít zapisovát do vectoru.
 *\param[out]   splited (vector<string> &) Vector pro ukládání řetězců.
 *\return               (bool) [true] převod byl proveden úspěšně; [false] převod nebyl proveden.
 */
bool char_array_to_string_vector(char *pole[], int start, int velikost, vector<string> & splited){
    bool b=false;
    for(int i=start; i<velikost-1 ; i++){
        splited.push_back(pole[i]);
        b=true;
    }
    return b;
}
