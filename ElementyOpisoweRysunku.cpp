#include "ElementyOpisoweRysunku.hpp"


/* ############################################### TEKSTY OPISOWE ############################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool TekstyOpisowe::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt TekstyOpisowe::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

bool TekstyOpisowe::setWysokoscTekstu(float x){
	this->WysokoscTekstu = x;

	return 1;	
}
float TekstyOpisowe::getWysokoscTekstu(){
	return this->WysokoscTekstu;
}

bool TekstyOpisowe::setIleLinii(int x){
	this->IleLinii = x;

	return 1;	
}
int TekstyOpisowe::getIleLinii(){
	return this->IleLinii;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */



/* ############################################### KOTA WYSOKOSCIOWA ############################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool KotaWysokosciowa::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt KotaWysokosciowa::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

bool KotaWysokosciowa::setRzedna(float Rzedna){
	this->Rzedna = Rzedna;
	
	return 1;
}
float KotaWysokosciowa::getRzedna(){
	return this->Rzedna;
}

bool KotaWysokosciowa::setOpis(string opis1, string opis2, string opis3){
	this->Opis[0] = opis1;
	this->Opis[1] = opis2;
	this->Opis[2] = opis3;
	
	return 1;
}
string KotaWysokosciowa::getOpis(int i){
	return this->Opis[i];
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */



/* ############################################### WYMIAR NORMALNY ############################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool WymiarNormalny::setPunktStartowy(Punkt punkt){
	this->punktStartowy = punkt;
	
	return 1;
}
Punkt WymiarNormalny::getPunktStartowy(){
	return this->punktStartowy;
}

bool WymiarNormalny::setPunktKoncowy(Punkt punkt){
	this->punktKoncowy = punkt;
	
	return 1;
}
Punkt WymiarNormalny::getPunktKoncowy(){
	return this->punktKoncowy;
}

bool WymiarNormalny::setPunktLokalizacjiLiniiWymiarowej(Punkt punkt){
	this->punktLokalizacjiLiniiWymiarowej = punkt;
	
	return 1;
}
Punkt WymiarNormalny::getPunktLokalizacjiLiniiWymiarowej(){
	return this->punktLokalizacjiLiniiWymiarowej;
}

bool WymiarNormalny::setPunktLokalizacjiTekstuWymiaru(Punkt punkt){
	this->punktLokalizacjiTekstuWymiaru = punkt;
	
	return 1;
}
Punkt WymiarNormalny::getPunktLokalizacjiTekstuWymiaru(){
	return this->punktLokalizacjiTekstuWymiaru;
}

bool WymiarNormalny::setKatObrotuWymiaru(int x){
	this->katObrotuWymiaru = x;
	
	return 1;
}
int WymiarNormalny::getKatObrotuWymiaru(){
	return this->katObrotuWymiaru;
}

bool WymiarNormalny::setDokladnosc(int x){
	this->Dokladnosc = x;
	
	return 1;
}
int WymiarNormalny::getDokladnosc(){
	return this->Dokladnosc;
}

bool WymiarNormalny::setAligned(bool x){
	this->Aligned = x;
	
	return 1;
}
bool WymiarNormalny::getAligned(){
	return this->Aligned;
}

bool WymiarNormalny::setSkala(float Skala){
	this->Skala = Skala;
	
	return 1;
}
float WymiarNormalny::getSkala(){
	return this->Skala;
}

bool WymiarNormalny::setStyl(string x){
	this->Styl = x;
	
	return 1;
}
string WymiarNormalny::getStyl(){
	return this->Styl;
}

bool WymiarNormalny::setTekstZamiastWymiaru(string tekst){
	this->TekstZamiastWymiaru = tekst;
	
	return 1;
}
string WymiarNormalny::getTekstZamiastWymiaru(){
	return this->TekstZamiastWymiaru;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void WymiarNormalny::generujPojedynczyWymiarNormalny(float xp, float yp, float xk, float yk, int WspolrzednaLiniiWymiarowej, int IleTekstWymiaruNadLinia, int katObrotuWymiaru, float Skala, int PrzesunWymiar, string TekstZamiastWymiaru){
	
	//sprawdza czy wymiar jest pionowy lub poziomy
	if(katObrotuWymiaru != 0 && katObrotuWymiaru != 90){
		
		cout << "B³¹d! Wymiar nie jest ani pionowy, ani poziomy." << endl;
		system("PAUSE");
		
		exit;
		
	}
	
	Punkt punktStartowy, punktKoncowy, punktLokalizacjiLiniiWymiarowej, punktLokalizacjiTekstuWymiaru;
	
	punktStartowy.setX(xp); 
	punktStartowy.setY(yp);
	
	punktKoncowy.setX(xk); 
	punktKoncowy.setY(yk);
	
	if(katObrotuWymiaru == 0){
	
		punktLokalizacjiLiniiWymiarowej.setX(punktStartowy.getX()); 
		punktLokalizacjiLiniiWymiarowej.setY(WspolrzednaLiniiWymiarowej);
		
		punktLokalizacjiTekstuWymiaru.setX((punktStartowy.getX() + punktKoncowy.getX()) / 2 + PrzesunWymiar); 														//ustawia tekst wymiaru na œrodku
		punktLokalizacjiTekstuWymiaru.setY(punktLokalizacjiLiniiWymiarowej.getY() - IleTekstWymiaruNadLinia * Skala);
	
	}
	else if(katObrotuWymiaru == 90){
	
		punktLokalizacjiLiniiWymiarowej.setX(WspolrzednaLiniiWymiarowej); 
		punktLokalizacjiLiniiWymiarowej.setY(punktStartowy.getY());
		
		punktLokalizacjiTekstuWymiaru.setY((punktStartowy.getY() + punktKoncowy.getY()) / 2 + PrzesunWymiar);														//ustawia tekst wymiaru na œrodku
		punktLokalizacjiTekstuWymiaru.setX(punktLokalizacjiLiniiWymiarowej.getX() - IleTekstWymiaruNadLinia * Skala); 										
	}
	
	this->setSkala(Skala);
	this->setKatObrotuWymiaru(katObrotuWymiaru);	
	this->setPunktStartowy(punktStartowy);
	this->setPunktKoncowy(punktKoncowy);
	this->setPunktLokalizacjiLiniiWymiarowej(punktLokalizacjiLiniiWymiarowej);
	this->setPunktLokalizacjiTekstuWymiaru(punktLokalizacjiTekstuWymiaru);
	this->setTekstZamiastWymiaru(TekstZamiastWymiaru);
	
}

/* ################################################## OPIS PRET ################################################## */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool OpisPret::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt OpisPret::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

bool OpisPret::setPokazDlugosc(bool PokazDlugosc){
	this->PokazDlugosc = PokazDlugosc;
	
	return 1;
}
bool OpisPret::getPokazDlugosc(){
	return this->PokazDlugosc;
}

bool OpisPret::setSkala(float Skala){
	this->Skala = Skala;
	
	return 1;
}
float OpisPret::getSkala(){
	return this->Skala;
}

bool OpisPret::setPunktZaczepienia(Punkt PunktZaczepienia, int i){
	this->punktZaczepienia[i] = PunktZaczepienia;
	
	return 1;
}
Punkt OpisPret::getPunktZaczepienia(int i){
	return this->punktZaczepienia[i];
}

bool OpisPret::setLiczbaPunktowZaczepienia(int i){
	this->LiczbaPunktowZaczepienia = i;
	
	return 1;
}
int OpisPret::getLiczbaPunktowZaczepienia(){
	return this->LiczbaPunktowZaczepienia;
}

bool OpisPret::setNrPorzadkowyPreta(string nr){
	this->NrPorzadkowyPreta = nr;
	
	return 1;
}
string OpisPret::getNrPorzadkowyPreta(){
	return this->NrPorzadkowyPreta;
}

bool OpisPret::setStal(string Stal){
	this->Stal = Stal;
	
	return 1;
}
string OpisPret::getStal(){
	return this->Stal;
}

bool OpisPret::setIloscPretow(int x){
	this->IloscPretow = x;
	
	return 1;
}
int OpisPret::getIloscPretow(){
	return this->IloscPretow;
}

bool OpisPret::setSrednicaPreta(int x){
	this->SrednicaPreta = x;
	
	return 1;
}
int OpisPret::getSrednicaPreta(){
	return this->SrednicaPreta;
}

bool OpisPret::setDlugoscPreta(int x){
	this->DlugoscPreta = x;
	
	return 1;
}
int OpisPret::getDlugoscPreta(){
	return this->DlugoscPreta;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void OpisPret::generujOpisDoPreta(PretyProste DanePrety, Linia liniaPomocnicza, int PrzesuniecieX, int PrzesuniecieY){
	
	this->setNrPorzadkowyPreta(DanePrety.getNrPorzadkowy());
	this->setIloscPretow(DanePrety.getSztuki());
	this->setSrednicaPreta(DanePrety.getSrednica() * 10);
	this->setDlugoscPreta(DanePrety.DlugoscPreta());
	this->setStal(DanePrety.getStal());
	
	Punkt punktPomocniczy;
	
	punktPomocniczy.setX(liniaPomocnicza.getPunktPoczatkowy().getX() + PrzesuniecieX);
	punktPomocniczy.setY((liniaPomocnicza.getPunktPoczatkowy().getY() + liniaPomocnicza.getPunktKoncowy().getY()) / 2 + PrzesuniecieY);
	
	this->setPunktPoczatkowy(punktPomocniczy);
	
}

void OpisPret::generujOpisDoPreta(PretyGiete DanePrety, Linia liniaPomocnicza, int PrzesuniecieX, int PrzesuniecieY, bool CzyDlugoscProsta){
	
	this->setNrPorzadkowyPreta(DanePrety.getNrPorzadkowy());
	this->setIloscPretow(DanePrety.getSztuki());
	this->setSrednicaPreta(DanePrety.getSrednica() * 10);
	
	if(CzyDlugoscProsta)
		this->setDlugoscPreta(DanePrety.DlugoscPretaProsta());
	else
		this->setDlugoscPreta(DanePrety.DlugoscPreta());
		
	this->setStal(DanePrety.getStal());
	
	Punkt punktPomocniczy;
	
	punktPomocniczy.setX(liniaPomocnicza.getPunktPoczatkowy().getX() + PrzesuniecieX);
	punktPomocniczy.setY((liniaPomocnicza.getPunktPoczatkowy().getY() + liniaPomocnicza.getPunktKoncowy().getY()) / 2 + PrzesuniecieY);
	
	this->setPunktPoczatkowy(punktPomocniczy);
	
}

void OpisPret::generujOpisZLinia(PretyProste DanePrety, Linia liniaPomocnicza, Punkt WspolrzednePunktowZaczepienia[], int LiczbaPunktowZaczepienia, int PrzesuniecieX, int PrzesuniecieY){
	
	Punkt punkt;
	
	this->generujOpisDoPreta(DanePrety, liniaPomocnicza);
	
	for(int i = 0; i < LiczbaPunktowZaczepienia; i++){
		punkt.setX(WspolrzednePunktowZaczepienia[i].getX());
		punkt.setY(WspolrzednePunktowZaczepienia[i].getY());
		
		this->setPunktZaczepienia(punkt, i);
		
		this->setLiczbaPunktowZaczepienia(i + 1);
	}
	
}

void OpisPret::generujOpisZLinia(PretyGiete DanePrety, Linia liniaPomocnicza, Punkt WspolrzednePunktowZaczepienia[], int LiczbaPunktowZaczepienia, int PrzesuniecieX, int PrzesuniecieY){
	
	Punkt punkt;
	
	this->generujOpisDoPreta(DanePrety, liniaPomocnicza);
	
	for(int i = 0; i < LiczbaPunktowZaczepienia; i++){
		punkt.setX(WspolrzednePunktowZaczepienia[i].getX());
		punkt.setY(WspolrzednePunktowZaczepienia[i].getY());
		
		this->setPunktZaczepienia(punkt, i);
		
		this->setLiczbaPunktowZaczepienia(i + 1);
	}
	
}
