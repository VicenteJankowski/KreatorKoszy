#include "UstawieniaKoszZbrojeniowy.hpp"

/* ########################################### USTAWIENIA KOSZ ZBROJENIOWY #################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool UstawieniaKoszZbrojeniowy::setMaxDlugoscPreta(int x){
	this->MaxDlugoscPreta = x;
	
	return 1;
}
unsigned short int UstawieniaKoszZbrojeniowy::getMaxDlugoscPreta(){
	return this->MaxDlugoscPreta;
}

bool UstawieniaKoszZbrojeniowy::setMinDlugoscPreta(int x){
	this->MinDlugoscPreta = x;
	
	return 1;
}
unsigned short int UstawieniaKoszZbrojeniowy::getMinDlugoscPreta(){
	return this->MinDlugoscPreta;
}

bool UstawieniaKoszZbrojeniowy::setMinDlugoscZakladu(int x){
	this->MinDlugoscZakladu = x;
	
	return 1;
}
unsigned short int UstawieniaKoszZbrojeniowy::getMinDlugoscZakladu(){
	return this->MinDlugoscZakladu;
}

bool UstawieniaKoszZbrojeniowy::setDlugoscZakladuPret(int SrednicaPreta, int DlugoscZakladu){
	
	int i=0;
	
	while(i < this->LiczbaTypowychSrednicPretow){
		
		if(SrednicaPreta <= this->TypoweSrednicePretow[i]){
		
			if(DlugoscZakladu < (200 * SrednicaPreta / 10))
				this->DlugoscZakladuPret[i][1] = DlugoscZakladu;
			else{
				std::cout << "B£¥D! D³ugoœæ zak³adu wiêksza ni¿ 200x œrednica prêta. Przyjêto standardow¹ d³ugoœæ zak³adu 100cm.";
				system("PAUSE");	
			}
		
			break;
		}
		
		i++;	
	}
	
	return 1;
}

unsigned short int UstawieniaKoszZbrojeniowy::getDlugoscZakladuPret(float SrednicaPreta){
	
	int SrednicaPretaUstalona = 0;
	
	int i = 0;
	
	while(i < this->LiczbaTypowychSrednicPretow){
		if(SrednicaPreta <= this->TypoweSrednicePretow[i]){
			SrednicaPretaUstalona = this->TypoweSrednicePretow[i];
			break;
		}
		
		i++;	
	}		
	
	for(i=0; i < this->LiczbaTypowychSrednicPretow; i++)
		if(SrednicaPretaUstalona == this->TypoweSrednicePretow[i])
			return this->DlugoscZakladuPret[i][1];	
	}

bool UstawieniaKoszZbrojeniowy::setDodatkowaDlugoscPretNr7(int x){
	this->DodatkowaDlugoscPretNr7 = x;
	
	return 1;
}
unsigned short int UstawieniaKoszZbrojeniowy::getDodatkowaDlugoscPretNr7(){
	return this->DodatkowaDlugoscPretNr7;
}

bool UstawieniaKoszZbrojeniowy::setUkladStrzemion(float NowaPozycja, int Pozycja, int WartoscCzyIlePowtorzen){
	this->UkladStrzemion[Pozycja][WartoscCzyIlePowtorzen] = NowaPozycja;
	
	return 1;
}
float UstawieniaKoszZbrojeniowy::getUkladStrzemion(int Pozycja, int WartoscCzyIlePowtorzen){
	return this->UkladStrzemion[Pozycja][WartoscCzyIlePowtorzen];
}
		
bool UstawieniaKoszZbrojeniowy::setIlePozycjiUkladStrzemion(int a){
	this->IlePozycjiUkladStrzemion = a;
	
	return 1;
}
unsigned short int UstawieniaKoszZbrojeniowy::getIlePozycjiUkladStrzemion(){
	return this->IlePozycjiUkladStrzemion;
}

bool UstawieniaKoszZbrojeniowy::setMinOdlegloscStrzemieniaOdKoncaKosza(float MinOdlegloscStrzemieniaOdKoncaKosza){
	this->MinOdlegloscStrzemieniaOdKoncaKosza = MinOdlegloscStrzemieniaOdKoncaKosza;
	
	return 1;
}
float UstawieniaKoszZbrojeniowy::getMinOdlegloscStrzemieniaOdKoncaKosza(){
	return this->MinOdlegloscStrzemieniaOdKoncaKosza;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */
