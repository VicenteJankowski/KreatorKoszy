#include <cmath>
#include <iostream>
#include "elementyGeometryczne.hpp"

using namespace std;

/* ##################################################### PUNKT ################################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */
	
bool Punkt::setX(float x){
	this->x = x;
	
	return 1;			
}
float Punkt::getX(){
	return this->x;
}

bool Punkt::setY(float y){
	this->y = y;
	
	return 1;			
}
float Punkt::getY(){
	return this->y;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

float Punkt::OdlegloscMiedzyPunktami(Punkt p1, Punkt p2){
	return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

/* ##################################################### VERTEX ################################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */
	
bool Vertex::setTanZaokraglenia(float tanZaokraglenia){
	this->tanZaokraglenia = tanZaokraglenia;
	
	return 1;			
}
float Vertex::getTanZaokraglenia(){
	return this->tanZaokraglenia;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

/* ##################################################### LINIA ################################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */
bool Linia::setPunktPoczatkowy(Punkt PunktPoczatkowy){

	this->PunktPoczatkowy.setX(PunktPoczatkowy.getX());
	this->PunktPoczatkowy.setY(PunktPoczatkowy.getY());

	return 1;
}
Punkt Linia::getPunktPoczatkowy(){
	return this->PunktPoczatkowy;
}

bool Linia::setPunktKoncowy(Punkt PunktKoncowy){

	this->PunktKoncowy.setX(PunktKoncowy.getX());
	this->PunktKoncowy.setY(PunktKoncowy.getY());
	
	return 1;
}
Punkt Linia::getPunktKoncowy(){
	return this->PunktKoncowy;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

float Linia::Dlugosc(){
	return sqrt(pow(this->getPunktPoczatkowy().getX() - this->getPunktKoncowy().getX(), 2) + pow(this->getPunktPoczatkowy().getY() - this->getPunktKoncowy().getY(), 2));
}

Linia Linia::stworzLinieZeWspolrzednych(float xp, float yp, float xk, float yk){
	
	Punkt wspolrzednaPoczatek, wspolrzednaKoniec;
	Linia linia;
		
	wspolrzednaPoczatek.setX(xp);
	wspolrzednaPoczatek.setY(yp);
	wspolrzednaKoniec.setX(xk);
	wspolrzednaKoniec.setY(yk);
	
	linia.setPunktPoczatkowy(wspolrzednaPoczatek);
	linia.setPunktKoncowy(wspolrzednaKoniec);
	
	return linia;
	
}

Linia Linia::przesunRownolegle(float odsuniecie){
	
	float xp, yp, xk, yk;
	float xp_moved, yp_moved, xk_moved, yk_moved;
	Punkt punktP, punktK;
	Linia linia;
	
	punktP = this->getPunktPoczatkowy();
	punktK = this->getPunktKoncowy();
	
	xp = this->getPunktPoczatkowy().getX();
	yp = this->getPunktPoczatkowy().getY();
	xk = this->getPunktKoncowy().getX();
	yk = this->getPunktKoncowy().getY();

	xp_moved = xp + odsuniecie * ((yp - yk) / (punktP.OdlegloscMiedzyPunktami(punktP, punktK)));
	yp_moved = yp - odsuniecie * ((xp - xk) / (punktP.OdlegloscMiedzyPunktami(punktP, punktK)));
	xk_moved = xk + odsuniecie * ((yp - yk) / (punktP.OdlegloscMiedzyPunktami(punktP, punktK)));
	yk_moved = yk - odsuniecie * ((xp - xk) / (punktP.OdlegloscMiedzyPunktami(punktP, punktK)));
	
	linia = linia.stworzLinieZeWspolrzednych(xp_moved, yp_moved, xk_moved, yk_moved);
	
	return linia;
	
}

/* ################################################### POLILINIA ################################################# */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool Polilinia::setVertex(Punkt Vertex, int i, float tanZaokraglenia){

	this->Vertexy[i].setX(Vertex.getX());
	this->Vertexy[i].setY(Vertex.getY());
	this->Vertexy[i].setTanZaokraglenia(tanZaokraglenia);

	return 1;
}
Vertex Polilinia::getVertex(int i){
	return this->Vertexy[i];
}

bool Polilinia::setLiczbaVertex(int liczbaVertex){
	this->liczbaVertex = liczbaVertex;

	return 1;
}
int Polilinia::getLiczbaVertex(){
	return this->liczbaVertex;
}

bool Polilinia::setCzyZamknieta(bool x){
	this->CzyZamknieta = x;
	
	return 1;
}
bool Polilinia::getCzyZamknieta(){
	return this->CzyZamknieta;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

float Polilinia::DlugoscPolilinii(){
	
	float alfa;
	float c, r;
	float gamma;			// curve-fit tangent direction - to jest tanZaokraglenia
	float dlugosc = 0;
	
	for(int i = 1; i < this->getLiczbaVertex(); i++){
	
		gamma = abs(this->getVertex(i - 1).getTanZaokraglenia());
		
		//wylicza d³ugoœæ ³uku, jeœli jest zaokr¹glenie
		if(this->getVertex(i - 1).getTanZaokraglenia() != 0){
			
			c = this->getVertex(0).OdlegloscMiedzyPunktami(this->getVertex(i), this->getVertex(i - 1)) / 2;
			
			alfa = atan(gamma);
			
			r = c / sin (2 * alfa);
		
			dlugosc += r * 4 * alfa;
			
		}
		else
			dlugosc += this->getVertex(0).OdlegloscMiedzyPunktami(this->getVertex(i), this->getVertex(i - 1));
		
	}
	return dlugosc;
	
}

float Polilinia::WysokoscPolilinii(){																//uwaga, jak polilinia ma zaokr¹glenia to mo¿esz ich nie uwzglêdniaæ!
	
	float maxY = this->getVertex(0).getY();
	float minY = this->getVertex(0).getY();
	
	for(int i = 0; i < this->getLiczbaVertex(); i++){
		if(maxY < this->getVertex(i).getY()) maxY = this->getVertex(i).getY();
		if(minY > this->getVertex(i).getY()) minY = this->getVertex(i).getY();
	}
	
	return maxY - minY;
	
}

float Polilinia::SzerokoscPolilinii(){															//uwaga, jak polilinia ma zaokr¹glenia to mo¿esz ich nie uwzglêdniaæ!
	
	float maxX = this->getVertex(0).getX();
	float minX = this->getVertex(0).getX();
	
	for(int i = 0; i < this->getLiczbaVertex(); i++){
		if(maxX < this->getVertex(i).getX()) maxX = this->getVertex(i).getX();
		if(minX > this->getVertex(i).getX()) minX = this->getVertex(i).getX();
	}
	
	return maxX - minX;
	
}

Punkt Polilinia::getSrodekLuku(int i){
	
	Punkt punktPomocniczy;
	Polilinia obroconaPolilinia;
	
	float x1, x2, y1, y2;
	
	if(this->getLiczbaVertex() == i + 1)
		throw "B³¹d! Ostatni vertex, nie mo¿na wyznaczyæ po³o¿enia œrodka ³uku.";	
	
	x1 = this->getVertex(i).getX();
	y1 = this->getVertex(i).getY();
	x2 = this->getVertex(i + 1).getX();
	y2 = this->getVertex(i + 1).getY();
	
	if(x1 == x2){
		
		if(y1 == y2)
			throw "B³¹d! Oba vertexy pokrywaj¹ siê!";		
		
		punktPomocniczy.setX(x1 - this->getVertex(i).getTanZaokraglenia() * (punktPomocniczy.OdlegloscMiedzyPunktami(this->getVertex(i), this->getVertex(i + 1)) / 2));	
		punktPomocniczy.setY((y1 + y2) / 2);
	}
	else if(y1 == y2){
		
		if(x1 == x2)
			throw "B³¹d! Oba vertexy pokrywaj¹ siê!";
		
		punktPomocniczy.setX((x1 + x2) / 2);
		punktPomocniczy.setY(y1 - this->getVertex(i).getTanZaokraglenia() * (punktPomocniczy.OdlegloscMiedzyPunktami(this->getVertex(i), this->getVertex(i + 1)) / 2));	
	}
	else{
		
		float a, b, c; // wspó³czynniki równania kwadratowego
	
		a = 1 + ((pow((x2 - x1), 2)) / (pow((y1 - y2), 2)));
		b = -(x1 + x2) + 2 * ((x2 - x1) / (y1 - y2)) * (y1 - ((y1 - y2) / (x1 - x2)) * x1 - (y1 + y2) / 2);
		c = (pow((x1 + x2), 2)) / 4 + pow((y1 - ((y1 - y2) / (x1 - x2)) * x1 - (y1 + y2) / 2), 2) - pow(this->getVertex(i).getTanZaokraglenia() * (punktPomocniczy.OdlegloscMiedzyPunktami(this->getVertex(i), this->getVertex(i + 1)) / 2), 2);
		cout << endl << x1 << ", " << y1 << ", " << x2 << ", " << y2 <<endl;
		cout << endl << a << ", " << b << ", " << c << endl;
		float delta;
		
		delta = pow(b, 2) - 4 * a * c;
		
		if(delta < 0)
			throw "Delta mniejsza od zera!";
			
		punktPomocniczy.setX((-b - sqrt(delta) / 2) / (2 * a));	
		punktPomocniczy.setY(((x2 - x1) / (y1 - y2)) * punktPomocniczy.getX() + y1 - ((y1 - y2) / (x1 - x2)) * x1);
		
	}
	
	return punktPomocniczy;	
	
}

Polilinia Polilinia::przesunPolilinie(Punkt przesunietyPunktPoczatkowy){
	
	Punkt punkt;
	Polilinia przesunietaPolilinia;
	
	for(int i = 0; i <  this->getLiczbaVertex(); i++){
		punkt.setX(przesunietyPunktPoczatkowy.getX() + this->getVertex(i).getX());
		punkt.setY(przesunietyPunktPoczatkowy.getY() + this->getVertex(i).getY());	
		
		przesunietaPolilinia.setVertex(punkt, i, this->getVertex(i).getTanZaokraglenia());
		
		przesunietaPolilinia.setLiczbaVertex(i + 1);
	}
	
	return przesunietaPolilinia;
	
}

Polilinia Polilinia::odbicieLustrzanePoliliniiOsX(int WspolrzednaOsiX){
	
	Punkt punktPomocniczy;
	Polilinia odbitaPolilinia;
	
	for(int i = 0; i <  this->getLiczbaVertex(); i++){
		
		punktPomocniczy.setX(this->getVertex(i).getX());
		punktPomocniczy.setY(WspolrzednaOsiX + (WspolrzednaOsiX - this->getVertex(i).getY()));
		
		odbitaPolilinia.setVertex(punktPomocniczy, i, -this->getVertex(i).getTanZaokraglenia());
		
		odbitaPolilinia.setLiczbaVertex(i + 1);
		
	}
	
	return odbitaPolilinia;
}

Polilinia Polilinia::odbicieLustrzanePoliliniiOsY(int WspolrzednaOsiY){
	
	Punkt punktPomocniczy;
	Polilinia odbitaPolilinia;
	
	for(int i = 0; i <  this->getLiczbaVertex(); i++){
		
		punktPomocniczy.setX(WspolrzednaOsiY + (WspolrzednaOsiY - this->getVertex(i).getX()));
		punktPomocniczy.setY(this->getVertex(i).getY());
		
		odbitaPolilinia.setVertex(punktPomocniczy, i, -this->getVertex(i).getTanZaokraglenia());
		
		odbitaPolilinia.setLiczbaVertex(i + 1);
		
	}
	
	return odbitaPolilinia;
}

Polilinia Polilinia::obrocPolilinie(int kat){
	
	Punkt punktPomocniczy;
	Polilinia obroconaPolilinia;
	
	for(int i = 0; i <  this->getLiczbaVertex(); i++){
		
		punktPomocniczy.setX(this->getVertex(i).getX() * cos(kat * PI / 180) - this->getVertex(i).getY() * sin(kat * PI / 180));
		punktPomocniczy.setY(this->getVertex(i).getX() * sin(kat * PI / 180) + this->getVertex(i).getY() * cos(kat * PI / 180));
		
		obroconaPolilinia.setVertex(punktPomocniczy, i, this->getVertex(i).getTanZaokraglenia());
		
		obroconaPolilinia.setLiczbaVertex(i + 1);
		
	}
	
	return obroconaPolilinia;
	
}

/* ################################################### CIRCLE ################################################# */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool Circle::setSrodek(Punkt Srodek){

	this->Srodek.setX(Srodek.getX());
	this->Srodek.setY(Srodek.getY());

	return 1;
}
Punkt Circle::getSrodek(){
	return this->Srodek;
}

bool Circle::setPromien(float Promien){
	this->Promien = Promien;
	
	return 1;
}
float Circle::getPromien(){
	return this->Promien;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

Circle Circle::utworzKolo(float x, float y, float Promien){
	
	Punkt Srodek;
	Srodek.setX(x);
	Srodek.setY(y);
	
	Circle circle;
	
	circle.setSrodek(Srodek);
	circle.setPromien(Promien);
	
	return circle;
}

