#ifndef elementyGeometryczne_H
#define elementyGeometryczne_H

#define PI 3.14159265

class Punkt
{
	private:
		float x;
		float y;

	public:				
		bool setX(float);
		float getX();
		
		bool setY(float);
		float getY();
		
		float OdlegloscMiedzyPunktami(Punkt, Punkt);
};

class Vertex : public Punkt						//klasa-dziecko dla Punktu, dodatkowa opcja to tangens 1/4 k¹ta zaokr¹glenia (1 to rysuje pó³kole)
{
	private:
		float tanZaokraglenia = 0;				// to jest wspó³czynnik którym mno¿y po³owê odleg³oœci miêdzy punktami i odk³ada na normalnej przechodz¹cej przez œrodek odleg³oœci miedzy punktami i przez te 3 punkty rysuje okr¹g
	
	public:
		bool setTanZaokraglenia(float);
		float getTanZaokraglenia();	
		
};

class Linia
{
	private:
		Punkt PunktPoczatkowy;
		Punkt PunktKoncowy;
		
	public:	
		bool setPunktPoczatkowy(Punkt);
		Punkt getPunktPoczatkowy();
		
		bool setPunktKoncowy(Punkt);
		Punkt getPunktKoncowy();
				
		float Dlugosc();
		Linia stworzLinieZeWspolrzednych(float, float, float, float);
		Linia przesunRownolegle(float odsuniecie);
};

class Polilinia
{
	private:
		Vertex Vertexy[50];
		int liczbaVertex;
		bool CzyZamknieta = 0;
	
	public:
		bool setVertex(Punkt, int, float tanZaokraglenia = 0);
		Vertex getVertex(int);
		
		bool setLiczbaVertex(int);
		int getLiczbaVertex();
		
		bool setCzyZamknieta(bool);
		bool getCzyZamknieta();
		
		float DlugoscPolilinii();
		float WysokoscPolilinii();
		float SzerokoscPolilinii();
		Punkt getSrodekLuku(int);
		
		Polilinia przesunPolilinie(Punkt);
		Polilinia odbicieLustrzanePoliliniiOsX(int);
		Polilinia odbicieLustrzanePoliliniiOsY(int);
		Polilinia obrocPolilinie(int);
		
};

class Circle{
	private:
		Punkt Srodek;
		float Promien;
		
	public:
		bool setSrodek(Punkt);
		Punkt getSrodek();
		
		bool setPromien(float);
		float getPromien();
		
		Circle utworzKolo(float, float, float);
};

#endif
