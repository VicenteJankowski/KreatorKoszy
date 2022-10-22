#ifndef ObslugaDXF_hpp
#define ObslugaDXF_hpp

#include <fstream>		
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include "elementyGeometryczne.hpp"

class OpisPret;
class WymiarNormalny;

#include "ElementyOpisoweRysunku.hpp"

#define PI 3.14159265

using namespace std;

enum Warstwa {
		widok,
		zbrojenie,
		przerywana,
		kreskowanie,
		wymiary,
		opisy,
		koty_wysokosciowe,
		brak
	};

class LiniaDXF{
	
	private:
		Linia wspolrzedneLinii;
		Warstwa nazwaWarstwy = brak;
		
	public:
		bool setWspolrzedneLinii(Linia);
		Linia getWspolrzedneLinii();
		
		bool setNazwaWarstwy(Warstwa);
		Warstwa getNazwaWarstwy();
		
		LiniaDXF(){}
		~LiniaDXF(){}
};

class PoliliniaDXF{
	
	private:
		Warstwa nazwaWarstwy = brak;
		
	public:
		
		Polilinia wspolrzedneVertex;
		
		bool setWspolrzedneVertex(Polilinia);
		Polilinia getWspolrzedneVertex();
		
		bool setNazwaWarstwy(Warstwa);
		Warstwa getNazwaWarstwy();
		
		PoliliniaDXF(){}
		~PoliliniaDXF(){}
};

class CircleDXF{
	
	private:
		Circle DaneKola;
		Warstwa nazwaWarstwy = brak;
		
	public:
		bool setDaneKola(Circle);
		Circle getDaneKola();
		
		bool setNazwaWarstwy(Warstwa);
		Warstwa getNazwaWarstwy();
		
		CircleDXF(){}
		~CircleDXF(){}
};

class CreateDxf 
{
private:

	fstream &ZapisDoPliku;
	
public:
	CreateDxf(fstream &Zapis);
	~CreateDxf();
	
	void DxfBegin();
	void DxfEnd();
	
	string getHexHandle();
	
	// funkcje rysuj¹ce elementy rysunku DXF
	void Circle		(float, float, float, Warstwa);
	void Line		(Linia, Warstwa);
	void PolyLine	(Polilinia, Warstwa, bool CzyZamknieta = 0);
	void hatchujCircle (CircleDXF[], Warstwa, string, int LimitCircles = 10000);
	void BlokUszyDuze(Punkt, Warstwa);
	void MTekst(float, float, string[], int, Warstwa, float WysokoscTekstu = 15);
	void KotaWysokosciowa(Punkt, float, string, string, string, Warstwa);
	void rysujWymiarNormalny(WymiarNormalny, Warstwa);
	void rysujWymiarPromienia(WymiarNormalny, Warstwa);
	void OpisPojedynczyPretyBezLinii(OpisPret, Warstwa);
	void OpisPojedynczyPretyZLinia(OpisPret, Warstwa);
	void OpisPojedynczyPretyZLiniaLewy(OpisPret, Warstwa);
	void OpisPojedynczyPretyZLiniaPoziomo(OpisPret, Warstwa, bool CzyPrawyOpis = 1, bool CzyStrzalkiDoGory = 1);
	void OpisPojedynczyPretyZLiniamiBezposrednio(OpisPret, Warstwa, bool CzyPrawyOpis = 1);
	void OpisPojedynczyPretyZLiniamiRownolegle(OpisPret Opis, Warstwa typWarstwy, bool CzyPrawyOpis = 1);
		
	string warstwaNazwa(Warstwa);
	void rysujCircles(CircleDXF[], int LimitCircles = 10000);
	void rysujLinie(LiniaDXF[], int LimitLinii = 10000);
	void rysujPolilinie(PoliliniaDXF[], int LimitLinii = 10000);
};
#endif
