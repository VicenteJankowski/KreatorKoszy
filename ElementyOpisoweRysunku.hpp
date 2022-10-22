#ifndef ElementOpisoweRysunku_hpp
#define ElementOpisoweRysunku_hpp

class PretyProste;
class PretyGiete;
#include "koszZbrojeniowy.h"

using namespace std;

class TekstyOpisowe{

	private:
		
		Punkt punktPoczatkowy;
		float WysokoscTekstu = 15;
		int IleLinii = 0;
		
	public:
		
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		bool setWysokoscTekstu(float);
		float getWysokoscTekstu();
		
		bool setIleLinii(int);
		int getIleLinii();
		
		string LinieTekstu[10];
		
};

class KotaWysokosciowa{
	
	protected:
		
		Punkt punktPoczatkowy;
		
		float Rzedna;
		string Opis[3];
		
	public:
		
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		bool setRzedna(float);
		float getRzedna();
		
		bool setOpis(string opis1 = "brak", string opis2 = "", string opis3 = "");
		string getOpis(int i);
		
		KotaWysokosciowa(){
			this->setOpis();
		}
};

class WymiarNormalny{
	
	private:
		
		Punkt punktStartowy;
		Punkt punktKoncowy;
		Punkt punktLokalizacjiLiniiWymiarowej;
		Punkt punktLokalizacjiTekstuWymiaru;
		
		int katObrotuWymiaru = -360;
		
		int Dokladnosc = 2;
		bool Aligned = 0;
		float Skala = 1;
		
		string Styl = "DIM_1-50";
		string TekstZamiastWymiaru = "";
		
	public:
		
		bool setPunktStartowy(Punkt);
		Punkt getPunktStartowy();
		
		bool setPunktKoncowy(Punkt);
		Punkt getPunktKoncowy();
		
		bool setPunktLokalizacjiLiniiWymiarowej(Punkt);
		Punkt getPunktLokalizacjiLiniiWymiarowej();
		
		bool setPunktLokalizacjiTekstuWymiaru(Punkt);
		Punkt getPunktLokalizacjiTekstuWymiaru();
		
		bool setKatObrotuWymiaru(int);
		int getKatObrotuWymiaru();
		
		bool setDokladnosc(int);
		int getDokladnosc();
		
		bool setAligned(bool);
		bool getAligned();
		
		bool setSkala(float);
		float getSkala();
		
		bool setStyl(string);
		string getStyl();
		
		bool setTekstZamiastWymiaru(string);
		string getTekstZamiastWymiaru();
		
		void generujPojedynczyWymiarNormalny(float, float, float, float, int, int, int katObrotuWymiaru = 0, float Skala = 1, int PrzesunWymiar = 0, string TekstZamiastWymiaru = "");
		
};

class OpisPret{
	
	private:
		
		Punkt punktPoczatkowy;
		
		bool PokazDlugosc = 0;
		float Skala = 1;
		
		int LiczbaPunktowZaczepienia = 0;
		string NrPorzadkowyPreta = "brak";
		string Stal = "AIIIN";
		int IloscPretow;
		int SrednicaPreta;
		int DlugoscPreta;
		
	public:
		
		Punkt punktZaczepienia[50];
		
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		bool setPokazDlugosc(bool);
		bool getPokazDlugosc();
		
		bool setSkala(float);
		float getSkala();
		
		bool setPunktZaczepienia(Punkt, int);
		Punkt getPunktZaczepienia(int);
		
		bool setLiczbaPunktowZaczepienia(int);
		int getLiczbaPunktowZaczepienia();
		
		bool setNrPorzadkowyPreta(string);
		string getNrPorzadkowyPreta();
		
		bool setStal(string);
		string getStal();
		
		bool setIloscPretow(int);
		int getIloscPretow();
		
		bool setSrednicaPreta(int);
		int getSrednicaPreta();
		
		bool setDlugoscPreta(int);
		int getDlugoscPreta();
		
		void generujOpisDoPreta(PretyProste, Linia, int PrzesuniecieX = 0, int PrzesuniecieY = 0);
		void generujOpisDoPreta(PretyGiete, Linia, int PrzesuniecieX = 0, int PrzesuniecieY = 0, bool CzyDlugoscProsta = 1);
		void generujOpisZLinia(PretyProste, Linia, Punkt[], int, int PrzesuniecieX = 0, int PrzesuniecieY = 0);
		void generujOpisZLinia(PretyGiete, Linia, Punkt[], int, int PrzesuniecieX = 0, int PrzesuniecieY = 0);
	
};

#endif
