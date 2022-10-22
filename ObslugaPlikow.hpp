#ifndef ObslugaPlikow_hpp
#define ObslugaPlikow_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h> 
#include <stdio.h> 
#include <dirent.h>
#include <windows.h>
#include <ctime>

#include "koszZbrojeniowy.h"

using namespace std;

void setFontSize(int FontSize);
string nazwa_bez_rozszerzenia(string filename);
bool sprawdz_rozszerzenie(string filename, string, bool NoComment = 0);
bool otworz_plik(string filename, string folderpath, fstream &open_file);
int zapisz_plik(string filename, string folderpath, fstream &save_file, int limit=0);
bool sprawdz_folder(string folderpath);
void poprawnosc_pliku(string, fstream &file_verf);
string pominKomentarze(fstream &file_verf);
void czytaj_plik_ZakladyPretow(fstream &file_verf, UstawieniaKoszZbrojeniowy &UstawieniaKoszZbrojeniowy);
void czytaj_plik_UkladStrzemion(fstream &file_verf, UstawieniaKoszZbrojeniowy &UstawieniaKoszZbrojeniowy);
void czytaj_plik_kosz(fstream &file_verf, DaneWejscioweKosz &Dane);

string przecinek2kropka(string linia);
string kropka2przecinek(string linia);
bool CzyToLiczba(string s);
string szyfrujTresc(string, int);
bool sprawdzLicencjaZakodowanaWProgramie();
bool sprawdzLicencja();
void odtworzDzwiek();

#endif
