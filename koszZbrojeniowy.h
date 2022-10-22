#ifndef KOSZZBROJENIOWY_H
#define KOSZZBROJENIOWY_H

#include "elementyGeometryczne.hpp"
#include "UstawieniaKoszZbrojeniowy.hpp"
#include "ObslugaDXF.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Prety{

	private:		
		int sztuki = 0;
		string nrPorzadkowy = "brak";
		string Stal = "AIIIN";
		
		float srednica;
		float masa;
		float otulina;
		float IleNaMetr;
		float odstepMiedzyPretami;
		
	public:	
		bool setSztuki(int);
		int getSztuki();
		
		bool setNrPorzadkowy(string);
		string getNrPorzadkowy();
		
		bool setStal(string);
		string getStal();
		
		bool setSrednica(float);
		float getSrednica();
		
		bool setOtulina(float);
		float getOtulina();
		
		bool setIleNaMetr(float);
		float getIleNaMetr();
		
		bool setOdstepMiedzyPretami(float);
		float getOdstepMiedzyPretami();
		
		Prety(){}
		~Prety(){}
};

class PretyProste : public Prety
{
	private:
		float RzednaWierzchu;
		float RzednaSpodu;
	
	public:
		Linia GeometriaPreta2D;
		
		bool setRzednaWierzchu(float);
		float getRzednaWierzchu();
		
		bool setRzednaSpodu(float);
		float getRzednaSpodu();
		
		float DlugoscPreta();
		
		PretyProste(){}
		~PretyProste(){}
};

class PretyGiete : public Prety
{
	private:
		
	public:
		Polilinia GeometriaPreta2D;
		Polilinia GeometriaPreta2DProsta;
		
		bool setGeometriaPreta2D(Polilinia);
		Polilinia getGeometriaPreta2D();
		
		float DlugoscPreta();
		float DlugoscPretaProsta();
		
		PretyGiete(){}
		~PretyGiete(){}
};

class DaneWejscioweKosz{
	
	private:		
		string PrzekrojObliczeniowy;
		
		float rzednaWierzchuSciany;
		float rzednaSpoduSciany;
		float rzednaWierzchuZbrojenia;
		float rzednaSpoduZbrojenia;
		float poziomMurkowProwadzacych;
		
		float rzednePrzekrojuBB[6];
		int IleRzednychPrzekrojuBB = 0;
				
		int szerokoscKosza[15];	
		int szerokoscSciany;
		int IleSzerokosci = 0;
		
		bool przypisanaRzednaWierzchuSciany = 0;
		bool przypisanaRzednaSpoduSciany = 0;
		bool przypisanaRzednaWierzchuZbrojenia = 0;
		bool przypisanaRzednaSpoduZbrojenia = 0;
		bool przypisanaPoziomMurkowProwadzacych = 0;	
		bool przypisanaSzerokoscKosza = 0;	
		bool przypisanaSzerokoscSciany = 0;
		bool przypisanePretyGlowneOdStronyGruntu = 0;
		bool przypisanePretyGlowneOdStronyWykopu = 0;
		bool przypisaneDozbrojenieOdStronyGruntuI = 0;
		bool przypisaneDozbrojenieOdStronyGruntuII = 0;
		bool przypisaneDozbrojenieOdStronyWykopuI = 0;
		bool przypisaneDozbrojenieOdStronyWykopuII = 0;
		
	public:				
		
		PretyProste PretyGlowne[3];
		PretyProste DozbrojenieOdStronyGruntuI;
		PretyProste DozbrojenieOdStronyGruntuII;
		PretyProste DozbrojenieOdStronyWykopuI;
		PretyProste DozbrojenieOdStronyWykopuII;
		
		bool setPrzekrojObliczeniowy(string);
		string getPrzekrojObliczeniowy();
		
		bool setRzednaWierzchuSciany(float);
		float getRzednaWierzchuSciany();
		
		bool setRzednaWierzchuZbrojenia(float);
		float getRzednaWierzchuZbrojenia();
		
		bool setRzednaSpoduSciany(float);
		float getRzednaSpoduSciany();
		
		bool setRzednaSpoduZbrojenia(float);
		float getRzednaSpoduZbrojenia();

		bool setPoziomMurkowProwadzacych(float);
		float getPoziomMurkowProwadzacych();
		
		bool setIleUszyPowyzejMurkow(float);
		float getIleUszyPowyzejMurkow();

		bool setRzednePrzekrojuBB(float, int);
		float getRzednePrzekrojuBB(int);
		
		bool setIleRzednychPrzekrojuBB(int);
		int getIleRzednychPrzekrojuBB();
		
		bool setSzerokoscKosza(int, int);
		int getSzerokoscKosza(int);
		
		bool setSzerokoscSciany(int);
		int getSzerokoscSciany();
		
		bool setIleSzerokosci(int);
		int getIleSzerokosci();
		
		bool setPretyGlowne(PretyProste, bool);
		PretyProste getPretyGlowne(bool);
		
		bool setDozbrojenieOdStronyGruntuI(PretyProste);
		PretyProste getDozbrojenieOdStronyGruntuI();
		
		bool setDozbrojenieOdStronyGruntuII(PretyProste);
		PretyProste getDozbrojenieOdStronyGruntuII();
		
		bool setDozbrojenieOdStronyWykopuI(PretyProste);
		PretyProste getDozbrojenieOdStronyWykopuI();
		
		bool setDozbrojenieOdStronyWykopuII(PretyProste);
		PretyProste getDozbrojenieOdStronyWykopuII();
		
		bool getPrzypisaneDozbrojenieOdStronyGruntuI();
		bool getPrzypisaneDozbrojenieOdStronyGruntuII();
		bool getPrzypisaneDozbrojenieOdStronyWykopuI();
		bool getPrzypisaneDozbrojenieOdStronyWykopuII();
		
		bool sprawdzCzySaWszystkieDane();		
		
		DaneWejscioweKosz(){}
		~DaneWejscioweKosz(){}
	
};

class koszZbrojeniowy
{
	protected:
		string PrzekrojObliczeniowy;
				
		float rzednaWierzchuSciany;
		float rzednaSpoduSciany;
		float rzednaWierzchuZbrojenia;
		float rzednaSpoduZbrojenia;
		float poziomMurkowProwadzacych;
		
		float ileUszyPowyzejMurkow = 10;
		
		int szerokoscKosza;	
		int szerokoscSciany;
		
		int ileStrzemionWPrzekroju = 0;
		
		int podzielPretyNaDluzyce(PretyProste[], float, float, string, int, float, float, float, int, int, int, int);
		
		int obliczSztukiPretaPoWysokosci(PretyGiete, int DodanaWysokosc = 0);
		Prety obliczRozstawPretaGietego(PretyGiete, int);
		
		bool generujGeometrieStrzemionaDuze();
		Polilinia generujGeometriePojedynczegoStrzemionaMalego(int);
		Polilinia generujGeometrieProstaPojedynczegoStrzemionaMalego(int);
		bool generujGeometriePretaNr6();
		bool generujGeometriePretaNr7();
		bool generujGeometrieUszy();
		bool generujGeometriePretaNr9();
		
	public:
		UstawieniaKoszZbrojeniowy UstawieniaKosza;
		
		PretyProste PretyGlowne[2][25];
		PretyProste DozbrojeniaOdStronyGruntuI[25];
		PretyProste DozbrojeniaOdStronyGruntuII[25];
		PretyProste DozbrojeniaOdStronyWykopuI[25];
		PretyProste DozbrojeniaOdStronyWykopuII[25];
		PretyGiete StrzemionaDuze;
		PretyGiete StrzemionaMale[5];	
		PretyGiete PretyNr6;
		PretyGiete PretyNr7;
		PretyGiete Uszy;
		PretyGiete UszyDuze[2];
				
		bool setPrzekrojObliczeniowy(string);
		string getPrzekrojObliczeniowy();
		
		bool setRzednaWierzchuSciany(float);
		float getRzednaWierzchuSciany();
		
		bool setRzednaWierzchuZbrojenia(float);
		float getRzednaWierzchuZbrojenia();
		
		bool setRzednaSpoduSciany(float);
		float getRzednaSpoduSciany();
		
		bool setRzednaSpoduZbrojenia(float);
		float getRzednaSpoduZbrojenia();

		bool setPoziomMurkowProwadzacych(float);
		float getPoziomMurkowProwadzacych();
		
		bool setIleUszyPowyzejMurkow(float);
		float getIleUszyPowyzejMurkow();
		
		
		bool setSzerokoscKosza(int);
		int getSzerokoscKosza();
		
		bool setSzerokoscSciany(int);
		int getSzerokoscSciany();
		
		
		bool setIleStrzemionWPrzekroju(int);
		int getIleStrzemionWPrzekroju();
		
		
		float dobierzOdstepMiedzyPretami(int, int);
		void setPretyGlowne(DaneWejscioweKosz, float, bool);
		
		Polilinia stworzGeometriePretaProstego(float, float);
		bool setDozbrojeniaPoziomI(float, float, int, float, float, float, string);
		bool setDozbrojeniaPoziomII(float, float, int, float, float, float, string);
		
		
		int WysokoscKosza();
		int WysokoscKoszaOdWierzchuSciany();
		int WysokoscSciany();
		
		bool generujGeometrieStrzemionaMale();
		void generujKosz(DaneWejscioweKosz, int);
		
		//
		
		float odstepMiedzyStrzemionami = 30.0;
		
		koszZbrojeniowy(UstawieniaKoszZbrojeniowy UstawieniaKosza, DaneWejscioweKosz Dane, int SzerokoscKosza){
			
			this->UstawieniaKosza = UstawieniaKosza;
			
			this->generujKosz(Dane, SzerokoscKosza);
			
		}
		
		~koszZbrojeniowy(){}
};

#endif
