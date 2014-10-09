/**
 *\brief Hlavíčkový soubor.
 *
 *\details Prototypy funkcí.
 */
//#include<string>
#include <vector>
using namespace std;

bool prestupny_rok(int rok);

int prestupny_rok2(int rok);

int dny_v_mesici(int cislo_mesice, int rok);

int nasledujici_mesic(int cislo_mesice);

int predchozi_mesic(int cislo_mesice);

int nasledujici_den(int cislo_dne);

int predchozi_den(int cislo_dne);

int dnu_v_roce(int rok);

int posun_mesice_roky(int next, bool smer, int mesic, int rok, int *vystup);
void tydenni_posun_mesice_roky(int next, bool smer, int den, int mesic, int rok, int *vystup);

int pocet_dnu(int den, int mesic, int rok, int den2, int mesic2, int rok2);

void tydenni_generator_dnu(int, bool, int *);

void generator_dnu(int, bool, int *);

int nasledujici_den_v_mesici(int, int, int);

int predchozi_den_v_mesici(int, int, int);

void posun_data_v_dnech(bool, int, int, int, int, int *[]);

void vypis_cislo(int cislo);

int den_v_tydnu(int, int, int);

void svatky(int mesic, int den);

bool comp_str(char const *, char const *);
bool comp_str(string, string);

bool int_dec(char *);
bool int_dec(string);

void split_string(string, vector<string> &);

int str_to_int(string);

bool dalsi_menstruace(int rok, int mesic, int den, int cyklus, int delka_m, /*int kroku,*/ int * pole);

bool krokovani_menstruace(int rok, int mesic, int den, int cyklus, int delka_m, int kroku, vector <int> &);

bool char_array_to_string_vector(char * [], int, int, vector<string> &);
