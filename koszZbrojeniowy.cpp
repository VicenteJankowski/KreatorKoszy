#include "koszZbrojeniowy.h"

using namespace std;

/* ############################################# DANE WEJŒCIOWE KOSZ ############################################## */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool DaneWejscioweKosz::setPrzekrojObliczeniowy(string x){
	this->PrzekrojObliczeniowy = x;
	
	return 1;
}
string DaneWejscioweKosz::getPrzekrojObliczeniowy(){
	return this->PrzekrojObliczeniowy;
}

bool DaneWejscioweKosz::setRzednaWierzchuSciany(float rzednaWierzchuSciany){
	this->rzednaWierzchuSciany = rzednaWierzchuSciany;
	
	this->przypisanaRzednaWierzchuSciany = 1;
	
	return 1;
}
float DaneWejscioweKosz::getRzednaWierzchuSciany(){
	return this->rzednaWierzchuSciany;
}

bool DaneWejscioweKosz::setRzednaWierzchuZbrojenia(float rzednaWierzchuZbrojenia){
	this->rzednaWierzchuZbrojenia = rzednaWierzchuZbrojenia;
	
	this->przypisanaRzednaWierzchuZbrojenia = 1;
	
	return 1;
}
float DaneWejscioweKosz::getRzednaWierzchuZbrojenia(){
	return this->rzednaWierzchuZbrojenia;
}
	
		
bool DaneWejscioweKosz::setRzednaSpoduSciany(float rzednaSpoduSciany){
	this->rzednaSpoduSciany = rzednaSpoduSciany;

	this->przypisanaRzednaSpoduSciany = 1;

	return 1;
}
float DaneWejscioweKosz::getRzednaSpoduSciany(){
	return this->rzednaSpoduSciany;
}

bool DaneWejscioweKosz::setRzednaSpoduZbrojenia(float rzednaSpoduZbrojenia){
	this->rzednaSpoduZbrojenia = rzednaSpoduZbrojenia;
	
	this->przypisanaRzednaSpoduZbrojenia = 1;
	
	return 1;
}
float DaneWejscioweKosz::getRzednaSpoduZbrojenia(){
	return this->rzednaSpoduZbrojenia;
}

bool DaneWejscioweKosz::setPoziomMurkowProwadzacych(float poziomMurkowProwadzacych){
	
	this->poziomMurkowProwadzacych = poziomMurkowProwadzacych;
	
	this->przypisanaPoziomMurkowProwadzacych = 1;
	
	return 1;
}
float DaneWejscioweKosz::getPoziomMurkowProwadzacych(){
	return this->poziomMurkowProwadzacych;
}

bool DaneWejscioweKosz::setRzednePrzekrojuBB(float rzednePrzekrojuBB, int i){
	this->rzednePrzekrojuBB[i] = rzednePrzekrojuBB;
	
	return 1;
}
float DaneWejscioweKosz::getRzednePrzekrojuBB(int i){
	return this->rzednePrzekrojuBB[i];	
}

bool DaneWejscioweKosz::setIleRzednychPrzekrojuBB(int x){
	this->IleRzednychPrzekrojuBB = x;
	
	return 1;
}
int DaneWejscioweKosz::getIleRzednychPrzekrojuBB(){
	return this->IleRzednychPrzekrojuBB;	
}

bool DaneWejscioweKosz::setSzerokoscKosza(int szerokoscKosza, int i){
	this->szerokoscKosza[i] = szerokoscKosza;
	
	this->przypisanaSzerokoscKosza = 1;
	
	return 1;
}
int DaneWejscioweKosz::getSzerokoscKosza(int i){
	return this->szerokoscKosza[i];	
}

bool DaneWejscioweKosz::setSzerokoscSciany(int szerokoscSciany){
	this->szerokoscSciany = szerokoscSciany;
	
	this->przypisanaSzerokoscSciany = 1;
	
	return 1;
}
int DaneWejscioweKosz::getSzerokoscSciany(){
	return this->szerokoscSciany;	
}

bool DaneWejscioweKosz::setIleSzerokosci(int x){
	this->IleSzerokosci = x;
	
	return 1;
}
int DaneWejscioweKosz::getIleSzerokosci(){
	return this->IleSzerokosci;	
}

bool DaneWejscioweKosz::setPretyGlowne(PretyProste Dane, bool CzyWykop){
	
	this->PretyGlowne[CzyWykop] = Dane;
	
	if(!CzyWykop)
		this->przypisanePretyGlowneOdStronyGruntu = 1;
	else
		this->przypisanePretyGlowneOdStronyWykopu = 1;
	
	return 1;
	
}
PretyProste DaneWejscioweKosz::getPretyGlowne(bool CzyWykop){
	return this->PretyGlowne[CzyWykop];
}

bool DaneWejscioweKosz::setDozbrojenieOdStronyGruntuI(PretyProste Dane){
	
	this->DozbrojenieOdStronyGruntuI = Dane;
	
	if(Dane.getIleNaMetr() > 0)
		this->przypisaneDozbrojenieOdStronyGruntuI = 1;
	else if(Dane.getIleNaMetr() < 0)
		throw "B³¹d! Liczba prêtów dozbrojenia zdefiniowana jako mniejsza od zera.";
		
	return 1;
	
}
PretyProste DaneWejscioweKosz::getDozbrojenieOdStronyGruntuI(){
	return this->DozbrojenieOdStronyGruntuI;
}

bool DaneWejscioweKosz::setDozbrojenieOdStronyGruntuII(PretyProste Dane){
	
	this->DozbrojenieOdStronyGruntuII = Dane;
	
	if(Dane.getIleNaMetr() > 0)
		this->przypisaneDozbrojenieOdStronyGruntuII = 1;
	else if(Dane.getIleNaMetr() < 0)
		throw "B³¹d! Liczba prêtów dozbrojenia zdefiniowana jako mniejsza od zera.";
	
	return 1;
	
}
PretyProste DaneWejscioweKosz::getDozbrojenieOdStronyGruntuII(){
	return this->DozbrojenieOdStronyGruntuII;
}

bool DaneWejscioweKosz::setDozbrojenieOdStronyWykopuI(PretyProste Dane){
	
	this->DozbrojenieOdStronyWykopuI = Dane;
	
	if(Dane.getIleNaMetr() > 0)
		this->przypisaneDozbrojenieOdStronyWykopuI = 1;
	else if(Dane.getIleNaMetr() < 0)
		throw "B³¹d! Liczba prêtów dozbrojenia zdefiniowana jako mniejsza od zera.";
	
	return 1;
	
}
PretyProste DaneWejscioweKosz::getDozbrojenieOdStronyWykopuI(){
	return this->DozbrojenieOdStronyWykopuI;
}

bool DaneWejscioweKosz::setDozbrojenieOdStronyWykopuII(PretyProste Dane){
	
	this->DozbrojenieOdStronyWykopuII = Dane;
	
	if(Dane.getIleNaMetr() > 0)
		this->przypisaneDozbrojenieOdStronyWykopuII = 1;
	else if(Dane.getIleNaMetr() < 0)
		throw "B³¹d! Liczba prêtów dozbrojenia zdefiniowana jako mniejsza od zera.";
	
	return 1;
	
}
PretyProste DaneWejscioweKosz::getDozbrojenieOdStronyWykopuII(){
	return this->DozbrojenieOdStronyWykopuII;
}

bool DaneWejscioweKosz::getPrzypisaneDozbrojenieOdStronyGruntuI(){
	return this->przypisaneDozbrojenieOdStronyGruntuI;
}
bool DaneWejscioweKosz::getPrzypisaneDozbrojenieOdStronyGruntuII(){
	return this->przypisaneDozbrojenieOdStronyGruntuII;
}
bool DaneWejscioweKosz::getPrzypisaneDozbrojenieOdStronyWykopuI(){
	return this->przypisaneDozbrojenieOdStronyWykopuI;
}
bool DaneWejscioweKosz::getPrzypisaneDozbrojenieOdStronyWykopuII(){
	return this->przypisaneDozbrojenieOdStronyWykopuII;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

bool DaneWejscioweKosz::sprawdzCzySaWszystkieDane(){
	
	if(
		!this->przypisanaRzednaSpoduSciany ||
		!this->przypisanaRzednaSpoduZbrojenia ||
		!this->przypisanaRzednaWierzchuSciany ||
		!this->przypisanaRzednaWierzchuZbrojenia ||
		!this->przypisanaSzerokoscKosza ||
		!this->przypisanaSzerokoscSciany ||
		!this->przypisanaPoziomMurkowProwadzacych ||
		!this->przypisanePretyGlowneOdStronyGruntu ||
		!this->przypisanePretyGlowneOdStronyWykopu
		){
		
		throw "Niekompletne dane. Przerwano generowanie kosza."; 
		
	}
	
	if(this->PretyGlowne[0].getSrednica() == this->PretyGlowne[1].getSrednica()){
		
		this->PretyGlowne[0].setNrPorzadkowy("1");
		this->PretyGlowne[1].setNrPorzadkowy("1");
		
	}
	else{
		
		this->PretyGlowne[0].setNrPorzadkowy("10");
		this->PretyGlowne[1].setNrPorzadkowy("1");
		
	}
	
	
	//b³êdy danych wejœciowych
	if(this->poziomMurkowProwadzacych < this->rzednaWierzchuSciany)
		throw "\nB³¹d w danych wejœciowych. Poziom murków jest poni¿ej wierzchu œciany szczelinowej.";
		
	if(this->rzednaSpoduSciany > this->rzednaWierzchuSciany)
		throw "\nB³¹d w danych wejœciowych. Spód œciany zdefiniowano wy¿ej ni¿ wierzch.";
		
	if(this->rzednaSpoduZbrojenia > this->rzednaWierzchuZbrojenia)
		throw "\nB³¹d w danych wejœciowych. Spód zbrojenia zdefiniowano wy¿ej ni¿ wierzch.";
		
	if(this->rzednaSpoduSciany > this->rzednaSpoduZbrojenia)
		throw "\nB³¹d w danych wejœciowych. Spód œciany zdefiniowano powy¿ej spodu zbrojenia.";
		

	if(this->przypisaneDozbrojenieOdStronyGruntuI && this->przypisaneDozbrojenieOdStronyGruntuII){
		
		if(this->getDozbrojenieOdStronyGruntuII().getRzednaWierzchu() > this->getDozbrojenieOdStronyGruntuI().getRzednaWierzchu())
			throw "\nB³¹d w danych wejœciowych. Dobzbrojenie II od strony gruntu zaczyna siê wy¿ej ni¿ dozbrojenie I.";
			
		if(this->getDozbrojenieOdStronyGruntuII().getRzednaSpodu() < this->getDozbrojenieOdStronyGruntuI().getRzednaSpodu())
			throw "\nB³¹d w danych wejœciowych. Dobzbrojenie II od strony gruntu koñczy siê ni¿ej ni¿ dozbrojenie I.";
	}

	if(this->przypisaneDozbrojenieOdStronyWykopuI && this->przypisaneDozbrojenieOdStronyWykopuII){
		
		if(this->getDozbrojenieOdStronyWykopuII().getRzednaWierzchu() > this->getDozbrojenieOdStronyWykopuI().getRzednaWierzchu())
			throw "\nB³¹d w danych wejœciowych. Dobzbrojenie II od strony wykopu zaczyna siê wy¿ej ni¿ dozbrojenie I.";
			
		if(this->getDozbrojenieOdStronyWykopuII().getRzednaSpodu() < this->getDozbrojenieOdStronyWykopuI().getRzednaSpodu())
			throw "\nB³¹d w danych wejœciowych. Dobzbrojenie II od strony wykopu koñczy siê ni¿ej ni¿ dozbrojenie I.";
	}
	
	
	//ostrze¿enia
	if(this->rzednaWierzchuSciany - this->rzednaWierzchuZbrojenia > 50){
		
		cout <<  "\nUWAGA! Wierzch œciany jest wiêcej ni¿ 50cm powy¿ej wierzchu zbrojenia.\n" << endl;	
		system("PAUSE");
		
	}
	
	//sprawdza czy zdefiniowane rzêdne przekrojów B-B maj¹ sens	
	float tymczasoweRzednePrzekrojuBB[6] = {};
	int i = 0, g = 0;
	
	for(i = 0; i < this->getIleRzednychPrzekrojuBB(); i++)
		if(this->getRzednePrzekrojuBB(i) > this->getRzednaWierzchuZbrojenia() || this->getRzednePrzekrojuBB(i) < this->getRzednaSpoduZbrojenia()){
			
			if((i + 1) == this->getIleRzednychPrzekrojuBB()) break;	// przerywa pêtle jeœli ostatni element jest poza zakresem
			
			cout << "\nUWAGA! Zdefiniowana rzêdna przekroju B-B " << this->getRzednePrzekrojuBB(i) << " jest poza zakresem zbrojenia. Zostanie pominiêta.\n";
			system("PAUSE");
			
			for(g = i; g < this->getIleRzednychPrzekrojuBB() - 1; g++)
				this->setRzednePrzekrojuBB(this->getRzednePrzekrojuBB(g + 1), g); // przepisuje kolejn¹ wartoœæ, wywalaj¹c t¹ poza zakresem
			
			this->setIleRzednychPrzekrojuBB(this->getIleRzednychPrzekrojuBB() - 1);
				
			i--;
			
		}

}

/* #################################################### PRETY #################################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool Prety::setSztuki(int liczbaPretowGlownych){
	this->sztuki = liczbaPretowGlownych;
	
	return 1;
}
int Prety::getSztuki(){
	return this->sztuki;
}

bool Prety::setNrPorzadkowy(string nrPorzadkowy){
	this->nrPorzadkowy = nrPorzadkowy;
	
	return 1;
}
string Prety::getNrPorzadkowy(){
	return this->nrPorzadkowy;
}

bool Prety::setStal(string Stal){
	this->Stal = Stal;
	
	return 1;
}
string Prety::getStal(){
	return this->Stal;
}

bool Prety::setSrednica(float Srednica){
	this->srednica = Srednica / 10;
	
	return 1;
}
float Prety::getSrednica(){
	return this->srednica;
}

bool Prety::setOtulina(float otulina){
	this->otulina = otulina;
	
	return 1;
}
float Prety::getOtulina(){
	return this->otulina;
}

bool Prety::setIleNaMetr(float x){
	this->IleNaMetr = x;
	
	return 1;
}
float Prety::getIleNaMetr(){
	return this->IleNaMetr;
}

bool Prety::setOdstepMiedzyPretami(float odstep){
	this->odstepMiedzyPretami = odstep;
	
	return 1;
}
float Prety::getOdstepMiedzyPretami(){
	return this->odstepMiedzyPretami;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */


/* ################################################ PRETY PROSTE ################################################# */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool PretyProste::setRzednaWierzchu(float x){
	this->RzednaWierzchu = x;
	
	return 1;
}
float PretyProste::getRzednaWierzchu(){
	return this->RzednaWierzchu;
}

bool PretyProste::setRzednaSpodu(float x){
	this->RzednaSpodu = x;
	
	return 1;
}
float PretyProste::getRzednaSpodu(){
	return this->RzednaSpodu;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

float PretyProste::DlugoscPreta(){
	return this->getRzednaWierzchu() - this->getRzednaSpodu();
}

/* ################################################ PRETY GIÊTE ################################################# */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool PretyGiete::setGeometriaPreta2D(Polilinia polilinia){
	this->GeometriaPreta2D = polilinia;
	
	return 1;
}
Polilinia PretyGiete::getGeometriaPreta2D(){
	return this->GeometriaPreta2D;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

float PretyGiete::DlugoscPreta(){
	
	return this->GeometriaPreta2D.DlugoscPolilinii();
	
}

float PretyGiete::DlugoscPretaProsta(){
	
	return this->GeometriaPreta2DProsta.DlugoscPolilinii();
	
}

/* ############################################### KOSZ ZBROJENIOWY ############################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool koszZbrojeniowy::setPrzekrojObliczeniowy(string x){
	this->PrzekrojObliczeniowy = x;
	
	return 1;
}
string koszZbrojeniowy::getPrzekrojObliczeniowy(){
	return this->PrzekrojObliczeniowy;
}

bool koszZbrojeniowy::setRzednaWierzchuSciany(float rzednaWierzchuSciany){
	this->rzednaWierzchuSciany = rzednaWierzchuSciany * 100;
	
	return 1;
}
float koszZbrojeniowy::getRzednaWierzchuSciany(){
	return this->rzednaWierzchuSciany;
}

bool koszZbrojeniowy::setRzednaWierzchuZbrojenia(float rzednaWierzchuZbrojenia){
	this->rzednaWierzchuZbrojenia = rzednaWierzchuZbrojenia * 100;
	
	return 1;
}
float koszZbrojeniowy::getRzednaWierzchuZbrojenia(){
	return this->rzednaWierzchuZbrojenia;
}
	
		
bool koszZbrojeniowy::setRzednaSpoduSciany(float rzednaSpoduSciany){
	this->rzednaSpoduSciany = rzednaSpoduSciany * 100;
	
	return 1;
}
float koszZbrojeniowy::getRzednaSpoduSciany(){
	return this->rzednaSpoduSciany;
}

bool koszZbrojeniowy::setRzednaSpoduZbrojenia(float rzednaSpoduZbrojenia){
	this->rzednaSpoduZbrojenia = rzednaSpoduZbrojenia * 100;
	
	return 1;
}
float koszZbrojeniowy::getRzednaSpoduZbrojenia(){
	return this->rzednaSpoduZbrojenia;
}

bool koszZbrojeniowy::setPoziomMurkowProwadzacych(float poziomMurkowProwadzacych){
	this->poziomMurkowProwadzacych = poziomMurkowProwadzacych * 100;
	
	return 1;
}
float koszZbrojeniowy::getPoziomMurkowProwadzacych(){
	return this->poziomMurkowProwadzacych;
}

bool koszZbrojeniowy::setIleUszyPowyzejMurkow(float ile){
	this->ileUszyPowyzejMurkow = ile;
	
	return 1;
}
float koszZbrojeniowy::getIleUszyPowyzejMurkow(){
	return this->ileUszyPowyzejMurkow;
}


bool koszZbrojeniowy::setSzerokoscKosza(int szerokoscKosza){
	this->szerokoscKosza = szerokoscKosza;
	
	return 1;
}
int koszZbrojeniowy::getSzerokoscKosza(){
	return this->szerokoscKosza;	
}

bool koszZbrojeniowy::setSzerokoscSciany(int szerokoscSciany){
	this->szerokoscSciany = szerokoscSciany;
	
	return 1;
}
int koszZbrojeniowy::getSzerokoscSciany(){
	return this->szerokoscSciany;	
}

bool koszZbrojeniowy::setIleStrzemionWPrzekroju(int x){
	this->ileStrzemionWPrzekroju = x;
	
	return 1;
}

int koszZbrojeniowy::getIleStrzemionWPrzekroju(){
	return this->ileStrzemionWPrzekroju;			
}

void koszZbrojeniowy::setPretyGlowne(DaneWejscioweKosz Dane, float Otulina, bool CzyWykop){
	
	int Sztuki = ceil((this->getSzerokoscKosza() * Dane.PretyGlowne[CzyWykop].getIleNaMetr()) / 100 ) + 1;
	float OdstepMiedzyPretami = this->dobierzOdstepMiedzyPretami(this->getSzerokoscKosza(), Sztuki);	
	
	this->podzielPretyNaDluzyce(this->PretyGlowne[CzyWykop], this->getRzednaWierzchuZbrojenia(), this->getRzednaSpoduZbrojenia(), Dane.PretyGlowne[CzyWykop].getNrPorzadkowy(), Dane.PretyGlowne[CzyWykop].getSrednica(), Otulina, OdstepMiedzyPretami, Dane.PretyGlowne[CzyWykop].getIleNaMetr(), Sztuki, this->UstawieniaKosza.getMinDlugoscZakladu(), this->UstawieniaKosza.getMaxDlugoscPreta(), this->UstawieniaKosza.getMinDlugoscPreta());
	
}

bool koszZbrojeniowy::setDozbrojeniaPoziomI(float RzednaWierzchu, float RzednaSpodu, int Srednica, float Otulina, float OdstepMiedzyPretami, float IleNaMetr, string strona){
	
	bool CzyWykop = 0;
	int Sztuki;
	float wielokrotnosc = 0;
	
	RzednaWierzchu = RzednaWierzchu * 100;
	RzednaSpodu = RzednaSpodu * 100;
	
	if(strona == "grunt")
		CzyWykop = 0;
	else if(strona == "wykop")
		CzyWykop = 1;	
	
	if(IleNaMetr > this->PretyGlowne[CzyWykop][0].getIleNaMetr())
		throw "Blad, pretow dozbrojenia poziom I wiecej niz pretow glownych.";
	else
		wielokrotnosc = this->PretyGlowne[CzyWykop][0].getIleNaMetr() / IleNaMetr;
	
	if(wielokrotnosc - (int)wielokrotnosc == 0){
		
		Sztuki = ceil(this->PretyGlowne[CzyWykop][0].getSztuki() * IleNaMetr / this->PretyGlowne[CzyWykop][0].getIleNaMetr());
		
		if(strona == "grunt"){	
			
			if(RzednaWierzchu > this->getRzednaWierzchuZbrojenia()){
				
				cout << "UWAGA! Rzêdna wierzchu dozbrojenia poziomu I od strony gruntu jest wiêksza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaWierzchu = this->getRzednaWierzchuZbrojenia();
				
			}
			if(RzednaSpodu < this->getRzednaSpoduZbrojenia()){
				
				cout << "UWAGA! Rzêdna spodu dozbrojenia poziomu I od strony gruntu jest mniejsza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaSpodu = this->getRzednaSpoduZbrojenia();
				
			}
			
			
			this->podzielPretyNaDluzyce(this->DozbrojeniaOdStronyGruntuI, RzednaWierzchu, RzednaSpodu, "11", Srednica, Otulina, OdstepMiedzyPretami, IleNaMetr, Sztuki, this->UstawieniaKosza.getMinDlugoscZakladu(), this->UstawieniaKosza.getMaxDlugoscPreta(), this->UstawieniaKosza.getMinDlugoscPreta());			
		
		}
		else if (strona == "wykop"){
			
			if(RzednaWierzchu > this->getRzednaWierzchuZbrojenia()){
				
				cout << "UWAGA! Rzêdna wierzchu dozbrojenia poziomu I od strony wykopu jest wiêksza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaWierzchu = this->getRzednaWierzchuZbrojenia();
				
			}
			if(RzednaSpodu < this->getRzednaSpoduZbrojenia()){
				
				cout << "UWAGA! Rzêdna spodu dozbrojenia poziomu I od strony wykopu jest mniejsza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaSpodu = this->getRzednaSpoduZbrojenia();
				
			}
			
			
			this->podzielPretyNaDluzyce(this->DozbrojeniaOdStronyWykopuI, RzednaWierzchu, RzednaSpodu, "2", Srednica, Otulina, OdstepMiedzyPretami, IleNaMetr, Sztuki, this->UstawieniaKosza.getMinDlugoscZakladu(), this->UstawieniaKosza.getMaxDlugoscPreta(), this->UstawieniaKosza.getMinDlugoscPreta());
			
		}
		else		
			
			cout << "B³¹d, nierozpoznana strona œciany dozbrojenia poziomu I." << endl;
	}
	else
		
		cout << "Blad, ilosc pretow dozbrojenia poziomu I nie jest wielokrotnoscia rozstawu pretow glownych." << endl;
		
	return 1;	
	
}

bool koszZbrojeniowy::setDozbrojeniaPoziomII(float RzednaWierzchu, float RzednaSpodu, int Srednica, float Otulina, float OdstepMiedzyPretami, float IleNaMetr, string strona){

	bool CzyWykop = 0;	
	int Sztuki;
	float wielokrotnosc;
	
	RzednaWierzchu = RzednaWierzchu * 100;
	RzednaSpodu = RzednaSpodu * 100;
	
	if(strona == "grunt")
		CzyWykop = 0;
	else if(strona == "wykop")
		CzyWykop = 1;	
	
	if(IleNaMetr > this->PretyGlowne[CzyWykop][0].getIleNaMetr())
		throw "B³¹d, prêtów dozbrojenia poziom II wiêcej niz prêtów g³ównych.";
	else
		wielokrotnosc = this->PretyGlowne[CzyWykop][0].getIleNaMetr() / IleNaMetr;
	
	if(wielokrotnosc - (int)wielokrotnosc == 0){	
		
		Sztuki = floor(this->PretyGlowne[CzyWykop][0].getSztuki() * IleNaMetr / this->PretyGlowne[CzyWykop][0].getIleNaMetr());
		
		if(strona == "grunt"){		
			
			//sprawdza czy na pewno zdefiniowano dozbrojenie poziomu I
			if(this->DozbrojeniaOdStronyGruntuI[0].getSztuki() == 0)
				throw "Próba zdefiniowania dozbrojenia poziom II, bez dozbrojenia poziom I";
			
			//sprawdza czy dozbrojen lacznie nie jest wiecej niz pretow glownych
			if(Sztuki + this->DozbrojeniaOdStronyGruntuI[0].getSztuki() > this->PretyGlowne[CzyWykop][0].getSztuki())
				throw "B³¹d, za du¿o pretów dozbrojeñ.";
				
			//sprawdza czy prêty dozbrojenia poziomu I nie wystêpuj¹ przy ka¿dym prêtcie g³ównym, bo wtedy nie ma miejsca na kolejne dozbrojenie
			if(this->PretyGlowne[CzyWykop][0].getSztuki() == this->DozbrojeniaOdStronyGruntuI[0].getSztuki())
				throw "Próba zdefiniowania dozbrojenia poziom II, gdy dozbrojenia poziomu I s¹ ju¿ przy ka¿dym prêcie g³ównym";
			
			if(RzednaWierzchu > this->getRzednaWierzchuZbrojenia()){
				
				cout << "UWAGA! Rzêdna wierzchu dozbrojenia poziomu II od strony gruntu jest wiêksza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaWierzchu = this->getRzednaWierzchuZbrojenia();
				
			}
			if(RzednaSpodu < this->getRzednaSpoduZbrojenia()){
				
				cout << "UWAGA! Rzêdna spodu dozbrojenia poziomu II od strony gruntu jest mniejsza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaSpodu = this->getRzednaSpoduZbrojenia();
				
			}
			
			this->podzielPretyNaDluzyce(this->DozbrojeniaOdStronyGruntuII, RzednaWierzchu, RzednaSpodu, "12", Srednica, Otulina, OdstepMiedzyPretami, IleNaMetr, Sztuki, this->UstawieniaKosza.getMinDlugoscZakladu(), this->UstawieniaKosza.getMaxDlugoscPreta(), this->UstawieniaKosza.getMinDlugoscPreta());
			
		}
		else if (strona == "wykop"){
			
			//sprawdza czy na pewno zdefiniowano dozbrojenie poziomu I
			if(this->DozbrojeniaOdStronyWykopuI[0].getSztuki() == 0)
				throw "Próba zdefiniowania dozbrojenia poziom II, bez dozbrojenia poziom I";
			
			//sprawdza czy dozbrojen lacznie nie jest wiecej niz pretow glownych
			if(Sztuki + this->DozbrojeniaOdStronyWykopuI[0].getSztuki() > this->PretyGlowne[CzyWykop][0].getSztuki())
				throw "Blad, za duzo pretow dozbrojen.";
			
			//sprawdza czy prêty dozbrojenia poziomu I nie wystêpuj¹ przy ka¿dym prêtcie g³ównym, bo wtedy nie ma miejsca na kolejne dozbrojenie
			if(this->PretyGlowne[CzyWykop][0].getSztuki() == this->DozbrojeniaOdStronyWykopuI[0].getSztuki())
				throw "Próba zdefiniowania dozbrojenia poziom II, gdy dozbrojenia poziomu I s¹ ju¿ przy ka¿dym prêcie g³ównym";
			
			if(RzednaWierzchu > this->getRzednaWierzchuZbrojenia()){
				
				cout << "UWAGA! Rzêdna wierzchu dozbrojenia poziomu II od strony wykopu jest wiêksza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaWierzchu = this->getRzednaWierzchuZbrojenia();
				
			}
			if(RzednaSpodu < this->getRzednaSpoduZbrojenia()){
				
				cout << "UWAGA! Rzêdna spodu dozbrojenia poziomu II od strony wykopu jest mniejsza ni¿ zbrojenia g³ównego. Program automatycznie wyrówna rzêdn¹ dozbrojenia do rzêdnej zbrojenia g³ównego." << endl;
				RzednaSpodu = this->getRzednaSpoduZbrojenia();
				
			}
			
			this->podzielPretyNaDluzyce(this->DozbrojeniaOdStronyWykopuII, RzednaWierzchu, RzednaSpodu, "3", Srednica, Otulina, OdstepMiedzyPretami, IleNaMetr, Sztuki, this->UstawieniaKosza.getMinDlugoscZakladu(), this->UstawieniaKosza.getMaxDlugoscPreta(), this->UstawieniaKosza.getMinDlugoscPreta());
			
		}
		else	
			
			throw "B³¹d, nierozpoznana strona wykopu dozbrojenia poziomu II.";
			
	}
	else
	
		throw "B³¹d, z³a iloœæ prêtów dozbrojenia poziomu II na metr.";
		
	return 1;	
	
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

int koszZbrojeniowy::WysokoscSciany(){
	return this->getRzednaWierzchuSciany() - this->getRzednaSpoduSciany();
}

int koszZbrojeniowy::WysokoscKosza(){	
	return this->getRzednaWierzchuZbrojenia() - this->getRzednaSpoduZbrojenia();
}

int koszZbrojeniowy::WysokoscKoszaOdWierzchuSciany(){
	return this->getRzednaWierzchuSciany() - this->getRzednaSpoduZbrojenia();
}

float koszZbrojeniowy::dobierzOdstepMiedzyPretami(int SzerokoscKosza, int Sztuki){

	float OdstepMiedzyPretami = floor(2 * ((float)SzerokoscKosza / ((float)Sztuki - 1))) / 2;			//zaokr¹gla do po³ówek w dó³, dodane float bo jak dzielimy dwa inty to daje to inta
	float OtulinaBoczna = (SzerokoscKosza - OdstepMiedzyPretami * (Sztuki - 1)) / 2;
	
	int limit = 0;
	while(OtulinaBoczna < 1.9){
		while(OtulinaBoczna < 1.9){
			OdstepMiedzyPretami = OdstepMiedzyPretami - 0.5;
			OtulinaBoczna = (SzerokoscKosza - OdstepMiedzyPretami * (Sztuki - 1)) / 2;
		}
		while(OtulinaBoczna > 4.1){
			OdstepMiedzyPretami = OdstepMiedzyPretami + 0.5;
			OtulinaBoczna = (SzerokoscKosza - OdstepMiedzyPretami * (Sztuki - 1)) / 2;
		}
		if(limit++ > 20){
			string trescBledu = "\nNie uda³o siê dobraæ rozstawu pretów. Zmieñ ustawienia dopuszczalnych otulin bocznych lub iloœæ pretów na metr. " + to_string((int)(OtulinaBoczna * 10));
			throw trescBledu.c_str();
		}
	}

	return OdstepMiedzyPretami;
}

int koszZbrojeniowy::podzielPretyNaDluzyce(PretyProste TablicaPretowProstych[], float RzednaWierzchu, float RzednaSpodu, string nrPorzadkowyPreta, int Srednica, float Otulina, float OdstepMiedzyPretami, float IleNaMetr, int Sztuki, int DlugoscZakladu, int MaxDlugoscPretaProstego, int MinDlugoscPretaProstego){
	
	ostringstream nrPorzadkowyPretaWygenerowany;
	char LiterkaPorzadkowa = 98;						//przypisuje zmiennej ma³¹ litere "b"
	
	nrPorzadkowyPretaWygenerowany << nrPorzadkowyPreta;
	
	int i = 0;
	int DlugoscOdcinkaPretaProstego = 0;
	
	int RzednaNowegoWierzchu = RzednaWierzchu;

	TablicaPretowProstych[i].setRzednaWierzchu(RzednaNowegoWierzchu);
	TablicaPretowProstych[i].setNrPorzadkowy(nrPorzadkowyPretaWygenerowany.str());

	TablicaPretowProstych[i].setSrednica(Srednica);
	TablicaPretowProstych[i].setOtulina(Otulina);
	TablicaPretowProstych[i].setOdstepMiedzyPretami(OdstepMiedzyPretami);
	TablicaPretowProstych[i].setIleNaMetr(IleNaMetr);
	TablicaPretowProstych[i].setSztuki(Sztuki);
	
	while(RzednaNowegoWierzchu - RzednaSpodu > MaxDlugoscPretaProstego){
		
		//oczyszcza i przygotowuje zmienn¹ na kolejny nr porz¹dkowy
		nrPorzadkowyPretaWygenerowany.clear();
		nrPorzadkowyPretaWygenerowany.str("");
		
		TablicaPretowProstych[i].setRzednaSpodu(TablicaPretowProstych[i].getRzednaWierzchu() - MaxDlugoscPretaProstego);
		
		//zaczyna kolejny prêt
		RzednaNowegoWierzchu = TablicaPretowProstych[i++].getRzednaSpodu() + DlugoscZakladu;
		
		nrPorzadkowyPretaWygenerowany << nrPorzadkowyPreta << LiterkaPorzadkowa++;
		
		TablicaPretowProstych[i].setRzednaWierzchu(RzednaNowegoWierzchu);
		TablicaPretowProstych[i].setSrednica(Srednica);
		TablicaPretowProstych[i].setOtulina(Otulina);
		TablicaPretowProstych[i].setOdstepMiedzyPretami(OdstepMiedzyPretami);
		TablicaPretowProstych[i].setIleNaMetr(IleNaMetr);
		TablicaPretowProstych[i].setSztuki(Sztuki);
		TablicaPretowProstych[i].setNrPorzadkowy(nrPorzadkowyPretaWygenerowany.str());
	}
	
	TablicaPretowProstych[i].setRzednaSpodu(RzednaSpodu);
	

	//sprawdza dalej jeœli wygenerowano przynajmniej dwa prêty
	if(i > 0){
		
		TablicaPretowProstych[0].setNrPorzadkowy(TablicaPretowProstych[0].getNrPorzadkowy().append("a"));
		
		int BrakujacaDlugoscOstatniegoPreta; 
		BrakujacaDlugoscOstatniegoPreta =  MinDlugoscPretaProstego - TablicaPretowProstych[i].DlugoscPreta();
		
		
		//sprawdza czy d³ugoœæ prêta nie bêdzie zbyt krótka i jeœli tak jest to wyd³u¿a go kosztem poprzedniego prêta
		if(BrakujacaDlugoscOstatniegoPreta > 0){
			
			TablicaPretowProstych[i].setRzednaWierzchu(
				TablicaPretowProstych[i].getRzednaWierzchu() + BrakujacaDlugoscOstatniegoPreta);
		
			TablicaPretowProstych[i - 1].setRzednaSpodu(
				TablicaPretowProstych[i - 1].getRzednaSpodu() + BrakujacaDlugoscOstatniegoPreta);
			
		}
	}
	
	return i;
}

bool koszZbrojeniowy::generujGeometrieStrzemionaDuze(){
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	//ustawia punkt poczatkowy polilinii geometrii prêta
	punkt.setX(0);
	punkt.setY(0);
	
//generuje prost¹ geometriê strzemiona du¿ego
	
	//wylicza kolejne punkty
	punkt.setX(punkt.getX() - this->getSzerokoscKosza() / 2);
	this->StrzemionaDuze.GeometriaPreta2DProsta.setVertex(punkt, 1);
	
	//wylicza kolejne punkty
	int alfa = 45;
	
	punkt.setX(punkt.getX() + (this->getSzerokoscSciany() - 20) * cos(alfa * PI / 180));
	punkt.setY(punkt.getY() - (this->getSzerokoscSciany() - 20) * sin(alfa * PI / 180));
	this->StrzemionaDuze.GeometriaPreta2DProsta.setVertex(punkt, 0);
	
	//odbicie lustrzane drugiej po³owy
	punkt.setX(-this->StrzemionaDuze.GeometriaPreta2DProsta.getVertex(1).getX());
	punkt.setY(this->StrzemionaDuze.GeometriaPreta2DProsta.getVertex(1).getY());
	this->StrzemionaDuze.GeometriaPreta2DProsta.setVertex(punkt, 2);
	
	punkt.setX(-this->StrzemionaDuze.GeometriaPreta2DProsta.getVertex(0).getX());
	punkt.setY(this->StrzemionaDuze.GeometriaPreta2DProsta.getVertex(0).getY());
	this->StrzemionaDuze.GeometriaPreta2DProsta.setVertex(punkt, 3);
	
	this->StrzemionaDuze.GeometriaPreta2DProsta.setLiczbaVertex(4);

//generuje geometriê z zaokr¹gleniami strzemiona du¿ego	
	float ileOdBokuZagiecie = 1.5;
	
	//ustawia punkt poczatkowy polilinii geometrii prêta
	punkt.setX(0);
	punkt.setY(0);
	
	//wylicza kolejne punkty
	punkt.setX(punkt.getX() - this->getSzerokoscKosza() / 2 + ileOdBokuZagiecie);
	this->StrzemionaDuze.GeometriaPreta2D.setVertex(punkt, 2);
	
	//wylicza kolejne punkty
	punkt.setX(punkt.getX() -  0.5);
	punkt.setY(punkt.getY() - 3.5);
	this->StrzemionaDuze.GeometriaPreta2D.setVertex(punkt, 1, -0.7);
	
	punkt.setX(punkt.getX() + (this->getSzerokoscSciany() - 20) * cos(alfa * PI / 180));
	punkt.setY(punkt.getY() - (this->getSzerokoscSciany() - 20) * sin(alfa * PI / 180));
	this->StrzemionaDuze.GeometriaPreta2D.setVertex(punkt, 0);
	
	//odbicie lustrzane drugiej po³owy
	punkt.setX(-this->StrzemionaDuze.GeometriaPreta2D.getVertex(2).getX());
	punkt.setY(this->StrzemionaDuze.GeometriaPreta2D.getVertex(2).getY());
	this->StrzemionaDuze.GeometriaPreta2D.setVertex(punkt, 3, -0.7);
	
	punkt.setX(-this->StrzemionaDuze.GeometriaPreta2D.getVertex(1).getX());
	punkt.setY(this->StrzemionaDuze.GeometriaPreta2D.getVertex(1).getY());
	this->StrzemionaDuze.GeometriaPreta2D.setVertex(punkt, 4);
	
	punkt.setX(-this->StrzemionaDuze.GeometriaPreta2D.getVertex(0).getX());
	punkt.setY(this->StrzemionaDuze.GeometriaPreta2D.getVertex(0).getY());
	this->StrzemionaDuze.GeometriaPreta2D.setVertex(punkt, 5);
	
	this->StrzemionaDuze.GeometriaPreta2D.setLiczbaVertex(6);
	
	
	//wyliczenie sztuki strzemion
	int i=0;
	int ostatnieStrzemieJakBliskoKoncaZbrojenia = 10;
	
	float PPy = + 10;

	i++;
	
	PPy = PPy + 15;
	
	i++;
	
	PPy = PPy + 15;
	
	i++;
	
	//rysuje kolejne strzemiona zgodnie z odstêpem
	PPy = PPy + this->StrzemionaDuze.getOdstepMiedzyPretami();

	while(PPy  <= this->WysokoscKosza() - ostatnieStrzemieJakBliskoKoncaZbrojenia){	//sprawdza czy strzemiê nie wypada poni¿ej kosza zbrojeniowego
	
		i++;
		
		PPy = PPy + this->StrzemionaDuze.getOdstepMiedzyPretami();
	}
	
	this->StrzemionaDuze.setSztuki(2 * (i - 2));

	return 1;
}

Polilinia koszZbrojeniowy::generujGeometriePojedynczegoStrzemionaMalego(int ileObejmujePretowGlownych){
	
	int i = 0;
	float kalibracjaZaokrogleniaNaroznikow = 0.5;
	float tanZaokreglania = -(sqrt(2) - 1);
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	Polilinia poliliniaPomocnicza;
	
	float xp = 0 - this->PretyGlowne[0][0].getSrednica() / 2;
	float yp = 0;
	float xk = xp + this->PretyGlowne[0][0].getOdstepMiedzyPretami() * (ileObejmujePretowGlownych - 1) + this->PretyGlowne[0][0].getSrednica();
	float yk = yp - (this->getSzerokoscSciany() - 2 * this->StrzemionaMale[0].getOtulina()); 
	
	//ustawia punkt poczatkowy polilinii geometrii prêta
	//0
	punkt.setX(xp + kalibracjaZaokrogleniaNaroznikow);
	punkt.setY(yp);
	
	poliliniaPomocnicza.setVertex(punkt, i++);
	
	//wylicza kolejne punkty
	//1
	punkt.setX(xk - kalibracjaZaokrogleniaNaroznikow);
	poliliniaPomocnicza.setVertex(punkt, i++, tanZaokreglania);
	
	//2
	punkt.setX(xk);
	punkt.setY(yp - kalibracjaZaokrogleniaNaroznikow);
	poliliniaPomocnicza.setVertex(punkt, i++);
	
	//3
	punkt.setY(yk + kalibracjaZaokrogleniaNaroznikow);
	poliliniaPomocnicza.setVertex(punkt, i++, tanZaokreglania);
	
	//4
	punkt.setX(xk - kalibracjaZaokrogleniaNaroznikow);
	punkt.setY(yk);
	poliliniaPomocnicza.setVertex(punkt, i++);
	
	//5
	punkt.setX(xp + kalibracjaZaokrogleniaNaroznikow);
	punkt.setY(yk);
	poliliniaPomocnicza.setVertex(punkt, i++, tanZaokreglania);
	
	//6
	punkt.setX(xp);
	punkt.setY(yk + kalibracjaZaokrogleniaNaroznikow);
	poliliniaPomocnicza.setVertex(punkt, i++);
	
	//7
	punkt.setX(xp);
	punkt.setY(yp - kalibracjaZaokrogleniaNaroznikow);
	poliliniaPomocnicza.setVertex(punkt, i++, tanZaokreglania);
	
	poliliniaPomocnicza.setLiczbaVertex(i);
	
	return poliliniaPomocnicza;
	
}

Polilinia koszZbrojeniowy::generujGeometrieProstaPojedynczegoStrzemionaMalego(int ileObejmujePretowGlownych){
	
	int j = 0;
	float OdchylenieStrzemiona = 15;
	float OdchylenieZaczepuStrzemiona = 45;
	float DlugoscZaczepuStrzemiona = 10;
	Punkt Vertex;
	Polilinia polilinia;
	
	float xp = 0 - this->PretyGlowne[0][0].getSrednica();
	float yp = 0;
	float xk = xp + this->PretyGlowne[0][0].getOdstepMiedzyPretami() * (ileObejmujePretowGlownych - 1) + 2 * this->PretyGlowne[0][0].getSrednica();
	float yk = yp - (this->getSzerokoscSciany() - 2 * this->StrzemionaMale[0].getOtulina()); 
	
	//rysuje now¹ poliliniê z otwartym strzemieniem
	Vertex.setX(xk - DlugoscZaczepuStrzemiona * sin(OdchylenieZaczepuStrzemiona * PI / 180));
	Vertex.setY(yp - DlugoscZaczepuStrzemiona * cos(OdchylenieZaczepuStrzemiona * PI / 180));
	polilinia.setVertex(Vertex, j++);
	
	Vertex.setX(xk);
	Vertex.setY(yp);
	polilinia.setVertex(Vertex, j++);
	
	Vertex.setY(yk);
	polilinia.setVertex(Vertex, j++);
	
	Vertex.setX(xp);
	polilinia.setVertex(Vertex, j++);
	
	Vertex.setY(yp);
	polilinia.setVertex(Vertex, j++);

	Vertex.setX(Vertex.getX() + abs(xk - xp) * cos(OdchylenieStrzemiona * PI / 180));
	Vertex.setY(Vertex.getY() + abs(xk - xp) * sin(OdchylenieStrzemiona * PI / 180));
	polilinia.setVertex(Vertex, j++);
	
	Vertex.setX(Vertex.getX() - DlugoscZaczepuStrzemiona * sin(OdchylenieZaczepuStrzemiona * PI / 180));
	Vertex.setY(Vertex.getY() - DlugoscZaczepuStrzemiona * cos(OdchylenieZaczepuStrzemiona * PI / 180));
	polilinia.setVertex(Vertex, j++);
	
	polilinia.setLiczbaVertex(j);
	
	return polilinia;
	
}

bool koszZbrojeniowy::generujGeometrieStrzemionaMale(){

	int ileObejmujePretowGlownych[3];
	int minimalnaSzerokoscStrzemienia = 40;
	float SzerokoscWolnegoSrodka;
	
	ileObejmujePretowGlownych[0] = 2;

	//dobiera szerokoœæ najmniejszego strzemienia
	while(this->PretyGlowne[0][0].getOdstepMiedzyPretami() * (ileObejmujePretowGlownych[0] - 1) + this->PretyGlowne[0][0].getSrednica() < minimalnaSzerokoscStrzemienia)
		ileObejmujePretowGlownych[0]++;

	//sprawdza ile strzemion ma³ych bêdzie
	int ileStrzemion = (this->PretyGlowne[0][0].getSztuki() - 2) / ileObejmujePretowGlownych[0];
	
	switch(ileStrzemion){
		
		case 4:
		case 3:
			
			if(this->PretyGlowne[0][0].getSztuki() % 2 == 0){
				
				this->StrzemionaMale[0].GeometriaPreta2D = this->generujGeometriePojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[0]);
				this->StrzemionaMale[0].GeometriaPreta2DProsta = this->generujGeometrieProstaPojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[0]);
				this->StrzemionaMale[0].setSztuki((this->StrzemionaDuze.getSztuki() / 2) * 2);
				this->StrzemionaMale[0].setNrPorzadkowy("5a");
				
				ileObejmujePretowGlownych[1] = ileObejmujePretowGlownych[0] + 1;
				this->StrzemionaMale[1].GeometriaPreta2D = this->generujGeometriePojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[1]);
				this->StrzemionaMale[1].GeometriaPreta2DProsta = this->generujGeometrieProstaPojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[1]);
				this->StrzemionaMale[1].setSztuki((this->StrzemionaDuze.getSztuki() / 2));
				this->StrzemionaMale[1].setNrPorzadkowy("5b");
				
			}
			else{
				
				this->StrzemionaMale[0].GeometriaPreta2D = this->generujGeometriePojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[0]);
				this->StrzemionaMale[0].GeometriaPreta2DProsta = this->generujGeometrieProstaPojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[0]);
				this->StrzemionaMale[0].setSztuki((this->StrzemionaDuze.getSztuki() / 2) * 3);
				this->StrzemionaMale[0].setNrPorzadkowy("5");
				
			}	
				
			this->setIleStrzemionWPrzekroju(3); //ustawia ile bedzie prêtów nr 7 w przekroju poprzecznym -> 3 jak 3 strzemiona, 2 jak 2 lub 1 strzemiê
			break;
		
		case 2:
			
			this->StrzemionaMale[0].GeometriaPreta2D = this->generujGeometriePojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[0]);
			this->StrzemionaMale[0].GeometriaPreta2DProsta = this->generujGeometrieProstaPojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[0]);
			this->StrzemionaMale[0].setSztuki((this->StrzemionaDuze.getSztuki() / 2) * 2);
			this->StrzemionaMale[0].setNrPorzadkowy("5");
			
			this->setIleStrzemionWPrzekroju(2); //ustawia ile bedzie prêtów nr 7 w przekroju poprzecznym -> 3 jak 3 strzemiona, 2 jak 2 lub 1 strzemiê
			break;
			
		case 1:
			
			if(this->PretyGlowne[0][0].getSztuki() % 2 == 0){
				
				ileObejmujePretowGlownych[1] = ileObejmujePretowGlownych[0] + 1;
				
			}
			else{
				
				ileObejmujePretowGlownych[1] = ileObejmujePretowGlownych[0];
				
			}
			
			this->StrzemionaMale[1].GeometriaPreta2D = this->generujGeometriePojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[1]);
			this->StrzemionaMale[1].GeometriaPreta2DProsta = this->generujGeometrieProstaPojedynczegoStrzemionaMalego(ileObejmujePretowGlownych[1]);
			this->StrzemionaMale[1].setSztuki((this->StrzemionaDuze.getSztuki() / 2));
			this->StrzemionaMale[1].setNrPorzadkowy("5");
			
			this->setIleStrzemionWPrzekroju(2); //ustawia ile bedzie prêtów nr 7 w przekroju poprzecznym -> 3 jak 3 strzemiona, 2 jak 2 lub 1 strzemiê
			break;
			
		default:
			
			throw "Coœ posz³o nie tak przy generowaniu strzemion ma³ych";
		
	}
}

bool koszZbrojeniowy::generujGeometriePretaNr6(){
	
	int i = 0;
	int DlugoscOdcinkowProstychPretaNr6 = 20;
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	//ustawia punkt poczatkowy polilinii geometrii prêta
	punkt.setX(0);
	punkt.setY(0);
	
	this->PretyNr6.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kolejne punkty
	punkt.setY(punkt.getY() - DlugoscOdcinkowProstychPretaNr6);
	this->PretyNr6.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kolejne punkty
	int alfa = 45;																						//k¹t zagiêcia prêta nr 6
	
	punkt.setX(this->getSzerokoscKosza());
	punkt.setY(
		punkt.getY() - this->getSzerokoscKosza() * cos(alfa * PI / 180) / sin(alfa * PI / 180)); 		//wylicza wspó³rzêdn¹ Y jako y = -szerokosc * ctg(alfa)
	this->PretyNr6.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kawa³ek prostego odcinka na koñcu prêta;
	punkt.setY(punkt.getY() - DlugoscOdcinkowProstychPretaNr6);
	this->PretyNr6.GeometriaPreta2D.setVertex(punkt, i++);
	
	this->PretyNr6.GeometriaPreta2D.setLiczbaVertex(i);
	
	this->PretyNr6.GeometriaPreta2DProsta = this->PretyNr6.GeometriaPreta2D;
	
	return 1;
}

bool koszZbrojeniowy::generujGeometriePretaNr7(){
	
	int i = 0;
	int DlugoscOdcinkowProstychPretaNr7Zewnetrznych = 15;
	int DlugoscOdcinkowProstychPretaNr7Srodkowego = 30;
	int OtulinaPretaNr7 = 9;
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	//ustawia punkt poczatkowy polilinii geometrii prêta
	punkt.setX(OtulinaPretaNr7);
	punkt.setY(0);
	
	this->PretyNr7.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kolejne punkty
	punkt.setY(punkt.getY() - DlugoscOdcinkowProstychPretaNr7Zewnetrznych);
	this->PretyNr7.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kolejne punkty
	int alfa = 55;																		//k¹t zagiêcia prêta nr 7
	
	punkt.setX(punkt.getX() + (this->szerokoscSciany - 2 * OtulinaPretaNr7));
	punkt.setY(
		punkt.getY() - (this->szerokoscSciany - 2 * OtulinaPretaNr7) * cos(alfa * PI / 180) / sin(alfa * PI / 180)); 
	this->PretyNr7.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kawa³ek prostego odcinka na srodku prêta;
	punkt.setY(punkt.getY() - DlugoscOdcinkowProstychPretaNr7Srodkowego);
	this->PretyNr7.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kolejne punkty
	//alfa = 55;																		//k¹t zagiêcia prêta nr 7
	
	punkt.setX(punkt.getX() - (this->szerokoscSciany - 2 * OtulinaPretaNr7));
	punkt.setY(
		punkt.getY() - (this->szerokoscSciany - 2 * OtulinaPretaNr7) * cos(alfa * PI / 180) / sin(alfa * PI / 180)); 
	this->PretyNr7.GeometriaPreta2D.setVertex(punkt, i++);
	
	//wylicza kawa³ek prostego odcinka na koñcu prêta;
	punkt.setY(punkt.getY() - DlugoscOdcinkowProstychPretaNr7Zewnetrznych);
	this->PretyNr7.GeometriaPreta2D.setVertex(punkt, i++);
	
	this->PretyNr7.GeometriaPreta2D.setLiczbaVertex(i);
	
	this->PretyNr7.GeometriaPreta2DProsta = this->PretyNr7.GeometriaPreta2D;
	
	return 1;
}

bool koszZbrojeniowy::generujGeometrieUszy(){
	
	int i = 0;
	int IleZakladu = 20;											//20cm zak³adu, bo to nie jest spaw konstrukcyjny tylko monta¿owy
	int szerokoscUszu = 18;
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	punkt.setX(0);
	punkt.setY(0);
	this->Uszy.GeometriaPreta2D.setVertex(punkt, i++);
	
	//sprawdza czy wierzch kosza nie jest powy¿ej murków prowadz¹cych
	int WydluzenieUszu = 0;
	WydluzenieUszu = this->getPoziomMurkowProwadzacych() - this->getRzednaWierzchuZbrojenia();
	if(WydluzenieUszu < 0) WydluzenieUszu = 0;
	
	punkt.setY(WydluzenieUszu + (this->getIleUszyPowyzejMurkow() - szerokoscUszu / 2) + IleZakladu);
	this->Uszy.GeometriaPreta2D.setVertex(punkt, i++, -1);	//w tym miejscu generuje zaokr¹glenie ucha
	
	punkt.setX(szerokoscUszu);
	this->Uszy.GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setY(0);
	this->Uszy.GeometriaPreta2D.setVertex(punkt, i++);
	
	this->Uszy.GeometriaPreta2D.setLiczbaVertex(i);
	
	//sprawdza czy uszy nie s¹ krótsze ni¿ 120cm i wyd³u¿a je jak trzeba
	int MinimalnaDlugoscUszu = 120;
	
	if(this->Uszy.DlugoscPreta() < MinimalnaDlugoscUszu){

		punkt.setY(this->Uszy.GeometriaPreta2D.getVertex(1).getY() + ((MinimalnaDlugoscUszu - this->Uszy.DlugoscPreta()) / 2));
		punkt.setX(0);
		
		this->Uszy.GeometriaPreta2D.setVertex(punkt, 1, -1);
		
		punkt.setX(szerokoscUszu);
		this->Uszy.GeometriaPreta2D.setVertex(punkt, 2);
		
	}

	//zaokr¹glanie do pe³nej d³ugoœci ca³ego prêta
	int DlugoscZaokraglona = ceil(this->Uszy.DlugoscPreta() / 10) * 10;

	punkt.setY(this->Uszy.GeometriaPreta2D.getVertex(1).getY() + ((DlugoscZaokraglona - this->Uszy.DlugoscPreta()) / 2));
	
	punkt.setX(0);
	this->Uszy.GeometriaPreta2D.setVertex(punkt, 1, -1);
		
	punkt.setX(szerokoscUszu);
	this->Uszy.GeometriaPreta2D.setVertex(punkt, 2);

}

bool koszZbrojeniowy::generujGeometriePretaNr9(){
	
	int i = 0;
	int alfa = 40;
	float kalibracjaZaokreglenia[3];
	float tanZaokreglenia[3];
	
	switch(this->getSzerokoscSciany()){

		case 150:
			kalibracjaZaokreglenia[0] = 6.5;
			kalibracjaZaokreglenia[1] = 2;
			kalibracjaZaokreglenia[2] = 1.5;
			tanZaokreglenia[0] = -0.5;
			tanZaokreglenia[1] = -0.22;
			break;		
		case 120:
			kalibracjaZaokreglenia[0] = 6.5;
			kalibracjaZaokreglenia[1] = 2;
			kalibracjaZaokreglenia[2] = 1.5;
			tanZaokreglenia[0] = -0.5;
			tanZaokreglenia[1] = -0.22;
			break;
		case 100:
			kalibracjaZaokreglenia[0] = 6.5;
			kalibracjaZaokreglenia[1] = 2;
			kalibracjaZaokreglenia[2] = 1.5;
			tanZaokreglenia[0] = -0.5;
			tanZaokreglenia[1] = -0.22;
			break;
		case 80:
			kalibracjaZaokreglenia[0] = 6.5;
			kalibracjaZaokreglenia[1] = 2;
			kalibracjaZaokreglenia[2] = 1.5;
			tanZaokreglenia[0] = -0.5;
			tanZaokreglenia[1] = -0.22;
			break;
		case 60:
			kalibracjaZaokreglenia[0] = 6.5;
			kalibracjaZaokreglenia[1] = 2;
			kalibracjaZaokreglenia[2] = 1.5;
			tanZaokreglenia[0] = -0.5;
			tanZaokreglenia[1] = -0.22;
			break;
		case 50:
			kalibracjaZaokreglenia[0] = 5.6;
			kalibracjaZaokreglenia[1] = 1;
			kalibracjaZaokreglenia[2] = 1.3;
			tanZaokreglenia[0] = -0.45;
			tanZaokreglenia[1] = -0.16;
			alfa = 37;
			break;
		default:
			throw "Szerokoœæ œciany jest niestandardowa.";
			break;		
	}
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	punkt.setX(0);
	punkt.setY(0);
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setY(punkt.getY() + 48.5);
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++, tanZaokreglenia[1]);
	
	punkt.setX(punkt.getX() + kalibracjaZaokreglenia[1]);
	punkt.setY(punkt.getY() + kalibracjaZaokreglenia[2] + kalibracjaZaokreglenia[1] * cos(alfa * PI / 180) / sin(alfa * PI / 180));
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setX(punkt.getX() + (this->getSzerokoscSciany() - 18) / 2 - kalibracjaZaokreglenia[0] - kalibracjaZaokreglenia[1]);
	punkt.setY(punkt.getY() + ((this->getSzerokoscSciany() - 18) / 2 - kalibracjaZaokreglenia[0] - kalibracjaZaokreglenia[1]) * cos(alfa * PI / 180) / sin(alfa * PI / 180));
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++, tanZaokreglenia[0]);
	
	punkt.setX(punkt.getX() + 2 * kalibracjaZaokreglenia[0]);
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setX(punkt.getX() + (this->getSzerokoscSciany() - 18) / 2 - kalibracjaZaokreglenia[0] - kalibracjaZaokreglenia[1]);
	punkt.setY(punkt.getY() - ((this->getSzerokoscSciany() - 18) / 2 - kalibracjaZaokreglenia[0] - kalibracjaZaokreglenia[1]) * cos(alfa * PI / 180) / sin(alfa * PI / 180));
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++, tanZaokreglenia[1]);
	
	punkt.setX(punkt.getX() + kalibracjaZaokreglenia[1]);
	punkt.setY(punkt.getY() - kalibracjaZaokreglenia[2] - kalibracjaZaokreglenia[1] * cos(alfa * PI / 180) / sin(alfa * PI / 180));
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setY(punkt.getY() - 48.5);
	this->UszyDuze[0].GeometriaPreta2D.setVertex(punkt, i++);
	
	this->UszyDuze[0].GeometriaPreta2D.setLiczbaVertex(i);
	
	
	//rysuje dolny prêt
	i = 0;
	tanZaokreglenia[2] = -0.48;
	
	punkt.setX(this->UszyDuze[0].GeometriaPreta2D.getVertex(0).getY() + 2.5);
	punkt.setY(31);
	this->UszyDuze[1].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setY(punkt.getY() + 19 - 4);
	this->UszyDuze[1].GeometriaPreta2D.setVertex(punkt, i++, tanZaokreglenia[2]);
	
	punkt.setX(punkt.getX() + 4);
	punkt.setY(punkt.getY() + 4);
	this->UszyDuze[1].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setX(this->getSzerokoscSciany() - 18 - 2.5 - 4);
	this->UszyDuze[1].GeometriaPreta2D.setVertex(punkt, i++, tanZaokreglenia[2]);
	
	punkt.setX(punkt.getX() + 4);
	punkt.setY(punkt.getY() - 4);
	this->UszyDuze[1].GeometriaPreta2D.setVertex(punkt, i++);
	
	punkt.setY(punkt.getY() - (19 - 4));
	this->UszyDuze[1].GeometriaPreta2D.setVertex(punkt, i++);
	
	this->UszyDuze[1].GeometriaPreta2D.setLiczbaVertex(i);
	
}

int koszZbrojeniowy::obliczSztukiPretaPoWysokosci(PretyGiete Pret, int DodanaWysokosc){	
	
	int ileSztuk = 0;
	float LacznaWysokoscPretow = 0;
	
	LacznaWysokoscPretow += Pret.GeometriaPreta2D.WysokoscPolilinii();
	
	while(LacznaWysokoscPretow < this->WysokoscKoszaOdWierzchuSciany()){
		
		ileSztuk++;
		LacznaWysokoscPretow += (Pret.GeometriaPreta2D.WysokoscPolilinii() + DodanaWysokosc);
		
	}
	LacznaWysokoscPretow -= (Pret.GeometriaPreta2D.WysokoscPolilinii() + DodanaWysokosc);
	
	//sprawdza czy w przypadku ujemnej dodanej wysokoœci nie przekroczono do³u zbrojenia, bo wtedy prêt wypadnie poza koszem
	if((LacznaWysokoscPretow - DodanaWysokosc) > this->WysokoscKoszaOdWierzchuSciany())
		ileSztuk--;
	
	return ileSztuk;
}

Prety koszZbrojeniowy::obliczRozstawPretaGietego(PretyGiete Pret, int sztukiPretaPoWysokosci){
	
	Prety pomocniczyPret;
	
	float DystansDoRozdzialu = 0;
	
	if(sztukiPretaPoWysokosci > 0)
		DystansDoRozdzialu = this->WysokoscKoszaOdWierzchuSciany() - Pret.GeometriaPreta2D.WysokoscPolilinii() * sztukiPretaPoWysokosci;
	else
			throw "Ujemna liczba prêtów po wysokoœci.";
	
	if(DystansDoRozdzialu >= 0){
	
		if(sztukiPretaPoWysokosci > 1)
			pomocniczyPret.setOdstepMiedzyPretami(Pret.GeometriaPreta2D.WysokoscPolilinii() + DystansDoRozdzialu / (sztukiPretaPoWysokosci));	// oblicza rozstaw figur;
		else
			pomocniczyPret.setOdstepMiedzyPretami(Pret.GeometriaPreta2D.WysokoscPolilinii() + DystansDoRozdzialu);	// oblicza rozstaw figur;		
	}
	else{

		if(sztukiPretaPoWysokosci > 1)
			pomocniczyPret.setOdstepMiedzyPretami(Pret.GeometriaPreta2D.WysokoscPolilinii() + DystansDoRozdzialu / (sztukiPretaPoWysokosci - 1));	// oblicza rozstaw figur;
		else
			pomocniczyPret.setOdstepMiedzyPretami(Pret.GeometriaPreta2D.WysokoscPolilinii() + DystansDoRozdzialu);	// oblicza rozstaw figur;			
		
	}
	
	
	return pomocniczyPret;
}

void koszZbrojeniowy::generujKosz(DaneWejscioweKosz Dane, int SzerokoscKosza){
	
	this->setPrzekrojObliczeniowy(Dane.getPrzekrojObliczeniowy());
	
	this->setRzednaWierzchuSciany(Dane.getRzednaWierzchuSciany());
	this->setRzednaWierzchuZbrojenia(Dane.getRzednaWierzchuZbrojenia());
	this->setRzednaSpoduSciany(Dane.getRzednaSpoduSciany());
	this->setRzednaSpoduZbrojenia(Dane.getRzednaSpoduZbrojenia());
	this->setPoziomMurkowProwadzacych(Dane.getPoziomMurkowProwadzacych());
	
	this->setSzerokoscKosza(SzerokoscKosza);
	this->setSzerokoscSciany(Dane.getSzerokoscSciany());

	this->setPretyGlowne(Dane, 7.5, 0);
	this->setPretyGlowne(Dane, 7.5, 1);
	
	this->StrzemionaDuze.setNrPorzadkowy("4");
	this->StrzemionaDuze.setSrednica(12);
	this->StrzemionaDuze.setOdstepMiedzyPretami(30);
	this->StrzemionaDuze.setOtulina(7.5);
	this->generujGeometrieStrzemionaDuze();
	
	this->StrzemionaMale[0].setSrednica(12);
	this->StrzemionaMale[0].setOdstepMiedzyPretami(30);
	this->StrzemionaMale[0].setOtulina(7.5);
	this->StrzemionaMale[1].setSrednica(12);
	this->StrzemionaMale[1].setOdstepMiedzyPretami(30);
	this->StrzemionaMale[1].setOtulina(7.5);
	this->generujGeometrieStrzemionaMale();
	
	generujGeometriePretaNr6();
	this->PretyNr6.setNrPorzadkowy("6");
	
	if(this->WysokoscKosza() < 1300)
		this->PretyNr6.setSrednica(16);
	else
		this->PretyNr6.setSrednica(20);
	
	this->PretyNr6.setSztuki(2 * this->obliczSztukiPretaPoWysokosci(this->PretyNr6, -30));								//oblicza sztuki prêta giêtego i potem je ustawia; mno¿y razy 2 bo te prêty s¹ z dwóch stron po sztuce; da³em -30 bo prêty X mog¹ delikatnie na siebie zachodziæ
	this->PretyNr6.setOdstepMiedzyPretami(obliczRozstawPretaGietego(this->PretyNr6, this->PretyNr6.getSztuki() / 2).getOdstepMiedzyPretami());
				
	generujGeometriePretaNr7();
	this->PretyNr7.setNrPorzadkowy("7");

	if(this->WysokoscKosza() < 1300)
		this->PretyNr7.setSrednica(16);
	else
		this->PretyNr7.setSrednica(20);

	this->PretyNr7.setSztuki(this->getIleStrzemionWPrzekroju() * this->obliczSztukiPretaPoWysokosci(this->PretyNr7, this->UstawieniaKosza.getDodatkowaDlugoscPretNr7()));
	this->PretyNr7.setOdstepMiedzyPretami(obliczRozstawPretaGietego(this->PretyNr7, this->PretyNr7.getSztuki() / this->getIleStrzemionWPrzekroju()).getOdstepMiedzyPretami());
	

	
	this->Uszy.setNrPorzadkowy("8");
	this->Uszy.setSrednica(16);
	this->Uszy.setSztuki(4);
	this->Uszy.setStal("AI");
	generujGeometrieUszy();
	
	this->UszyDuze[0].setNrPorzadkowy("9");
	this->UszyDuze[1].setNrPorzadkowy("9");
	this->UszyDuze[0].setSrednica(25);
	this->UszyDuze[1].setSrednica(25);
	this->UszyDuze[0].setSztuki(2);
	this->UszyDuze[1].setSztuki(2);
	this->UszyDuze[0].setStal("AI");
	this->UszyDuze[1].setStal("AI");
	generujGeometriePretaNr9();
	
	if(Dane.getPrzypisaneDozbrojenieOdStronyGruntuI())
		this->setDozbrojeniaPoziomI(Dane.getDozbrojenieOdStronyGruntuI().getRzednaWierzchu(), Dane.getDozbrojenieOdStronyGruntuI().getRzednaSpodu(), Dane.getDozbrojenieOdStronyGruntuI().getSrednica(), this->PretyGlowne[0][0].getOtulina(), 2 * this->PretyGlowne[0][0].getOdstepMiedzyPretami(), Dane.getDozbrojenieOdStronyGruntuI().getIleNaMetr(), "grunt");

	if(Dane.getPrzypisaneDozbrojenieOdStronyGruntuII())
		this->setDozbrojeniaPoziomII(Dane.getDozbrojenieOdStronyGruntuII().getRzednaWierzchu(), Dane.getDozbrojenieOdStronyGruntuII().getRzednaSpodu(), Dane.getDozbrojenieOdStronyGruntuII().getSrednica(), this->PretyGlowne[0][0].getOtulina(), 2 * this->PretyGlowne[0][0].getOdstepMiedzyPretami(), Dane.getDozbrojenieOdStronyGruntuII().getIleNaMetr(), "grunt");
	
	if(Dane.getPrzypisaneDozbrojenieOdStronyWykopuI())
		this->setDozbrojeniaPoziomI(Dane.getDozbrojenieOdStronyWykopuI().getRzednaWierzchu(), Dane.getDozbrojenieOdStronyWykopuI().getRzednaSpodu(), Dane.getDozbrojenieOdStronyWykopuI().getSrednica(), this->PretyGlowne[0][0].getOtulina(), 2 * this->PretyGlowne[0][0].getOdstepMiedzyPretami(), Dane.getDozbrojenieOdStronyWykopuI().getIleNaMetr(), "wykop");

	if(Dane.getPrzypisaneDozbrojenieOdStronyWykopuII())
		this->setDozbrojeniaPoziomII(Dane.getDozbrojenieOdStronyWykopuII().getRzednaWierzchu(), Dane.getDozbrojenieOdStronyWykopuII().getRzednaSpodu(), Dane.getDozbrojenieOdStronyWykopuII().getSrednica(), this->PretyGlowne[0][0].getOtulina(), 2 * this->PretyGlowne[0][0].getOdstepMiedzyPretami(), Dane.getDozbrojenieOdStronyWykopuII().getIleNaMetr(), "wykop");

}
