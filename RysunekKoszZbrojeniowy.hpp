#ifndef RysunekKoszZbrojeniowy_hpp
#define RysunekKoszZbrojeniowy_hpp

#include <string>
#include <algorithm>
#include <vector>
#include "UstawieniaRysunekKoszZbrojeniowy.hpp"
#include "ObslugaDXF.hpp"
#include "ObslugaDXFextra.hpp"
#include "koszZbrojeniowy.h"
#include "elementyGeometryczne.hpp"
#include "ElementyOpisoweRysunku.hpp"

#define PI 3.14159265

class SymbolWykopGrunt{
	
	private:
		
	public:	
		LiniaDXF Linie[6];
		CircleDXF Circle[2];
		
		TekstyOpisowe Tekst[3];
	
};

class ZnacznikPrzekroju{
	
	private:
		
	public:
		LiniaDXF Linie[6];
		
		TekstyOpisowe Tekst[3];
	
};

class SchematRozmieszczeniaPretowGlownych{
	
	private:
		Punkt punktPoczatkowy;
		
	public:
		
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		LiniaDXF PretyGlowne[60];
		
		OpisPret OpisPretyGlowne[60];
		WymiarNormalny WymiaryNormalne[60];
		SymbolWykopGrunt SymbolWykopGrunt;
		
		void generujPretyGlowne(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy, Punkt, Punkt);
		
		SchematRozmieszczeniaPretowGlownych(){}
		~SchematRozmieszczeniaPretowGlownych(){}
		
};

class Widok{
	
	protected:
		Punkt punktPoczatkowy;
		
	public:
		
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		LiniaDXF poziomMurkowProwadzacych[2];
		
		LiniaDXF PretyGlowne[25];
		LiniaDXF Strzemiona[400];
		LiniaDXF Obrys[20];
		PoliliniaDXF Uszy[5];
		PoliliniaDXF PretyNr6[80];
		
		OpisPret OpisPretyGlowne[50];
		OpisPret OpisPretyNr6[50];
		OpisPret OpisUszy[2];
		
		KotaWysokosciowa KotyWysokosciowe[25];
		WymiarNormalny WymiaryNormalne[50];
		ZnacznikPrzekroju ZnacznikPrzekroju[10];
		
		Punkt PunktKoncowy(Punkt, koszZbrojeniowy);
		
		void generujPoziomMurkowProwadzacych(koszZbrojeniowy, Punkt);
		
		void generujPretyGlowne(koszZbrojeniowy);
		void generujStrzemiona(koszZbrojeniowy);
		
		Punkt punktPoczatkowyPretowNr6(koszZbrojeniowy);
		Punkt punktPoczatkowyUszy(koszZbrojeniowy);
		
		void generujOpisyPretowNr6(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		void generujOpisyPretow(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		void generujOpisyDoUszu(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz);
		void generujWymiaryNormalne(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		
		void generujUszy();
		
		Widok(){}
		~Widok(){}
};

class PrzekrojAA{
	
	protected:
		Punkt punktPoczatkowy;
		
	public:
	
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
	
		LiniaDXF Obrys[20];
		LiniaDXF PretyGlowne[20];
		LiniaDXF StrzemionaDuze[400];
		CircleDXF StrzemionaMale[400];
		PoliliniaDXF PretyNr7[130];
		PoliliniaDXF PretyNr9[3];
		
		OpisPret OpisPretyGlowne[2][30];
		OpisPret OpisPretyNr7[50];
		OpisPret OpisPretyNr9[2];
		
		KotaWysokosciowa KotyWysokosciowe[25];
		WymiarNormalny WymiaryNormalne[50];
		SymbolWykopGrunt SymbolWykopGrunt;
		ZnacznikPrzekroju ZnacznikPrzekroju;
		
		void generujPretyGlowne(koszZbrojeniowy);
		void generujStrzemiona(koszZbrojeniowy);
		Punkt punktPoczatkowyPretowNr7(koszZbrojeniowy);
		void generujPretyNr9(koszZbrojeniowy);
		
		void generujOpisyPretow(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		void generujOpisyPretowNr7(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		void generujOpisyDoPretowNr9(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		void generujWymiaryNormalne(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);
		
		PrzekrojAA(){}
		~PrzekrojAA(){}
};

class PrzekrojBB{
	
	private:
		Punkt punktPoczatkowy;
		
	public:
	
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		LiniaDXF Obrys[5];
		CircleDXF PretyGlowne[3][50];
		CircleDXF DozbrojeniaOdStronyGruntuI[25];
		CircleDXF DozbrojeniaOdStronyGruntuII[25];
		CircleDXF DozbrojeniaOdStronyWykopuI[25];
		CircleDXF DozbrojeniaOdStronyWykopuII[25];
		PoliliniaDXF StrzemionaDuze[5];
		PoliliniaDXF StrzemionaMale[3][10];
		
		OpisPret OpisPretyGlowne[10];
		OpisPret OpisStrzemionaMale[3];
		
		WymiarNormalny WymiaryNormalne[20];
		SymbolWykopGrunt SymbolWykopGrunt;
		
		void generujPretyGlowne(koszZbrojeniowy);
		void generujStrzemionaDuze(koszZbrojeniowy);
		void generujStrzemionaMale(koszZbrojeniowy);	
		void generujPretyDozbrojenia(koszZbrojeniowy, float);
		
		void generujOpisyPretyGlowne(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy, float);
		void generujOpisyStrzemionMalych(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);	
		
		void generujWymiaryNormalne(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);	
		
		PrzekrojBB(){}
		~PrzekrojBB(){}
};

class PretyWyrzucone{
	
	private:
		Punkt punktPoczatkowy;
		
	public:
	
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		PoliliniaDXF GeometriaPretyWyrzucone[30];
		
		OpisPret OpisPretyWyrzucone[30];
		
		WymiarNormalny WymiaryNormalne[150];
		WymiarPromienia WymiarPromienia[20];
		
		void obmiarujPolilinie(Polilinia);
		void generujPretyWyrzucone(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy);

		PretyWyrzucone(){}
		~PretyWyrzucone(){}			
};

class RysunekKoszZbrojeniowy{
	
	private:
		
		Punkt punktPoczatkowy;
		
		void generujObrys(UstawieniaRysunekKoszZbrojeniowy, koszZbrojeniowy, Punkt, LiniaDXF[], float, float, bool CzySprawdzacPrzerwanieObrysu = 1);
		void generujPretyGiete(Punkt, Polilinia, float, int, PoliliniaDXF[], Warstwa);
		
		KotaWysokosciowa generujPojedynczaKotaWysokosciowa(koszZbrojeniowy, int, float, float, string opis1 = "", string opis2 = "", string opis3 = "");
		void generujKotyWysokosciowe(koszZbrojeniowy, int, KotaWysokosciowa[]);
		
		float RzednePrzekrojuBB[5];
		int IleRzednychPrzekrojuBB = 0;
		void dobierzRzednePrzekrojuBB(koszZbrojeniowy);
		void generujPrzekrojBB(Punkt, koszZbrojeniowy, float, int);
		void generujZnacznikPrzekroju(koszZbrojeniowy, ZnacznikPrzekroju[], LiniaDXF[]);
		
	public:
		
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		bool setRzednePrzekrojuBB(float, int);
		float getRzednePrzekrojuBB(int);
		
		bool setIleRzednychPrzekrojuBB(int);
		int getIleRzednychPrzekrojuBB();
		
		UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku;
		
		SchematRozmieszczeniaPretowGlownych SchematRozmieszczeniaPretowGlownych;
		Widok Widok;
		PrzekrojAA PrzekrojAA;
		PrzekrojBB PrzekrojBB[5];
		PretyWyrzucone PretyWyrzucone;
		
		TekstyOpisowe TekstyOpisowe[30];
				
		void generujRysunekKoszaZbrojeniowego(koszZbrojeniowy, DaneWejscioweKosz);
		void rysujKosz(CreateDxf);
		
		RysunekKoszZbrojeniowy(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, Punkt punktPoczatkowy){
			
			this->UstawieniaRysunku = UstawieniaRysunku;
			
			this->setPunktPoczatkowy(punktPoczatkowy);
			
		}
		
		~RysunekKoszZbrojeniowy(){}
};

#endif
