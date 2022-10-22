#include "UstawieniaKoszZbrojeniowy.hpp"

/* ########################################### USTAWIENIA KOSZ ZBROJENIOWY #################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool UstawieniaKoszZbrojeniowy::setMaxDlugoscPreta(int x){
	this->MaxDlugoscPreta = x;
	
	return 1;
}
int UstawieniaKoszZbrojeniowy::getMaxDlugoscPreta(){
	return this->MaxDlugoscPreta;
}

bool UstawieniaKoszZbrojeniowy::setMinDlugoscPreta(int x){
	this->MinDlugoscPreta = x;
	
	return 1;
}
int UstawieniaKoszZbrojeniowy::getMinDlugoscPreta(){
	return this->MinDlugoscPreta;
}

bool UstawieniaKoszZbrojeniowy::setMinDlugoscZakladu(int x){
	this->MinDlugoscZakladu = x;
	
	return 1;
}
int UstawieniaKoszZbrojeniowy::getMinDlugoscZakladu(){
	return this->MinDlugoscZakladu;
}

bool UstawieniaKoszZbrojeniowy::setDodatkowaDlugoscPretNr7(int x){
	this->DodatkowaDlugoscPretNr7 = x;
	
	return 1;
}
int UstawieniaKoszZbrojeniowy::getDodatkowaDlugoscPretNr7(){
	return this->DodatkowaDlugoscPretNr7;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */
