#include "UstawieniaRysunekKoszZbrojeniowy.hpp"

/* ####################################### USTAWIENIA RYSUNEK KOSZ ZBROJENIOWY #################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool UstawieniaRysunekKoszZbrojeniowy::setPunktPoczatkowyPierwszegoKosza(Punkt PunktPoczatkowy){
	this->punktPoczatkowyPierwszegoKosza = PunktPoczatkowy;
	
	return 1;
}
Punkt UstawieniaRysunekKoszZbrojeniowy::getPunktPoczatkowyPierwszegoKosza(){
	return this->punktPoczatkowyPierwszegoKosza;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepKoszyWPionie(int x){
	this->OdstepKoszyWPionie = x;
	
	return 1;	
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepKoszyWPionie(){
	return this->OdstepKoszyWPionie;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepKoszyWPoziomie(int x){
	this->OdstepKoszyWPoziomie = x;
	
	return 1;	
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepKoszyWPoziomie(){
	return this->OdstepKoszyWPoziomie;
}

bool UstawieniaRysunekKoszZbrojeniowy::setPrzyJakiejRoznicyRzednychPrzerywacObrys(int x){
	this->PrzyJakiejRoznicyRzednychPrzerywacObrys = x;
	
	return 1;	
}
int UstawieniaRysunekKoszZbrojeniowy::getPrzyJakiejRoznicyRzednychPrzerywacObrys(){
	return this->PrzyJakiejRoznicyRzednychPrzerywacObrys;
}

bool UstawieniaRysunekKoszZbrojeniowy::setIlePonizejZbrojeniaPrzerwanie(int x){
	this->ilePonizejZbrojeniaPrzerwanie = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getIlePonizejZbrojeniaPrzerwanie(){
	return this->ilePonizejZbrojeniaPrzerwanie;
}

bool UstawieniaRysunekKoszZbrojeniowy::setIlePrzerwyObrysu(int x){
	this->ilePrzerwyObrysu = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getIlePrzerwyObrysu(){
	return this->ilePrzerwyObrysu;
}

bool UstawieniaRysunekKoszZbrojeniowy::setIleDolnejCzesciObrysu(int x){
	this->ileDolnejCzesciObrysu = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getIleDolnejCzesciObrysu(){
	return this->ileDolnejCzesciObrysu;
}

bool UstawieniaRysunekKoszZbrojeniowy::setJakDuzoWystajePrzerywanaOdObrysu(int x){
	this->jakDuzoWystajePrzerywanaOdObrysu = x;
	
	return 1;	
}
int UstawieniaRysunekKoszZbrojeniowy::getJakDuzoWystajePrzerywanaOdObrysu(){
	return this->jakDuzoWystajePrzerywanaOdObrysu;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWidokSchematRozmieszczeniaPretowGlownych(int odstep){
	this->OdstepWidokSchematRozmieszczeniaPretowGlownych = odstep;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWidokSchematRozmieszczeniaPretowGlownych(){
	return this->OdstepWidokSchematRozmieszczeniaPretowGlownych;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWidokPrzekrojAA(int odstep){
	this->OdstepWidokPrzekrojAA = odstep;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWidokPrzekrojAA(){
	return this->OdstepWidokPrzekrojAA;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepPrzekrojAAPrzekrojBB(int odstep){
	this->OdstepPrzekrojAAPrzekrojBB = odstep;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepPrzekrojAAPrzekrojBB(){
	return this->OdstepPrzekrojAAPrzekrojBB;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepPrzekrojBBOdGory(int odstep){
	this->OdstepPrzekrojBBOdGory = odstep;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepPrzekrojBBOdGory(){
	return this->OdstepPrzekrojBBOdGory;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepPrzekrojBBPretyWyrzucone(int odstep){
	this->OdstepPrzekrojBBPretyWyrzucone = odstep;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepPrzekrojBBPretyWyrzucone(){
	return this->OdstepPrzekrojBBPretyWyrzucone;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepPretowGlownychNaSchemacie(int odstep){
	this->OdstepPretowGlownychNaSchemacie = odstep;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepPretowGlownychNaSchemacie(){
	return this->OdstepPretowGlownychNaSchemacie;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepBocznyKotWysokosciowych(int x){
	this->OdstepBocznyKotWysokosciowych = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepBocznyKotWysokosciowych(){
	return this->OdstepBocznyKotWysokosciowych;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepDodatkowyKotyMurkowProwadzacych(int x){
	this->OdstepDodatkowyKotyMurkowProwadzacych = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepDodatkowyKotyMurkowProwadzacych(){
	return this->OdstepDodatkowyKotyMurkowProwadzacych;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepBocznyOpisowPretowGlownych(int x){
	this->OdstepBocznyOpisowPretowGlownych = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepBocznyOpisowPretowGlownych(){
	return this->OdstepBocznyOpisowPretowGlownych;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepBocznyOpisowPretowGlownychLewy(int x){
	this->OdstepBocznyOpisowPretowGlownychLewy = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepBocznyOpisowPretowGlownychLewy(){
	return this->OdstepBocznyOpisowPretowGlownychLewy;
}

bool UstawieniaRysunekKoszZbrojeniowy::setIleTekstWymiaruNadLinia(int x){
	this->IleTekstWymiaruNadLinia = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getIleTekstWymiaruNadLinia(){
	return this->IleTekstWymiaruNadLinia;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWymiarowPoziomychPierwszejLinii(int x){
	this->OdstepWymiarowPoziomychPierwszejLinii = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWymiarowPoziomychPierwszejLinii(){
	return this->OdstepWymiarowPoziomychPierwszejLinii;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWymiarowPoziomychDrugiejLinii(int x){
	this->OdstepWymiarowPoziomychDrugiejLinii = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWymiarowPoziomychDrugiejLinii(){
	return this->OdstepWymiarowPoziomychDrugiejLinii;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWymiarowPionowychPierwszejLinii(int x){
	this->OdstepWymiarowPionowychPierwszejLinii = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWymiarowPionowychPierwszejLinii(){
	return this->OdstepWymiarowPionowychPierwszejLinii;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWymiarowPionowychDrugiejLinii(int x){
	this->OdstepWymiarowPionowychDrugiejLinii = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWymiarowPionowychDrugiejLinii(){
	return this->OdstepWymiarowPionowychDrugiejLinii;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepWymiarowSchematRozmieszczeniaPretowGlownych(int x){
	this->OdstepWymiarowSchematRozmieszczeniaPretowGlownych = x;
	
	return 1;
}
int UstawieniaRysunekKoszZbrojeniowy::getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(){
	return this->OdstepWymiarowSchematRozmieszczeniaPretowGlownych;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepTytuluKoszy(Punkt Punkt){
	this->OdstepTytuluKoszy = Punkt;
	
	return 1;
}
Punkt UstawieniaRysunekKoszZbrojeniowy::getOdstepTytuluKoszy(){
	return this->OdstepTytuluKoszy;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepNapisuWidok(Punkt Punkt){
	this->OdstepNapisuWidok = Punkt;
	
	return 1;
}
Punkt UstawieniaRysunekKoszZbrojeniowy::getOdstepNapisuWidok(){
	return this->OdstepNapisuWidok;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepNapisuPrzekrojAA(Punkt Punkt){
	this->OdstepNapisuPrzekrojAA = Punkt;
	
	return 1;
}
Punkt UstawieniaRysunekKoszZbrojeniowy::getOdstepNapisuPrzekrojAA(){
	return this->OdstepNapisuPrzekrojAA;
}

bool UstawieniaRysunekKoszZbrojeniowy::setOdstepNapisuPrzekrojBB(Punkt Punkt){
	this->OdstepNapisuPrzekrojBB = Punkt;
	
	return 1;
}
Punkt UstawieniaRysunekKoszZbrojeniowy::getOdstepNapisuPrzekrojBB(){
	return this->OdstepNapisuPrzekrojBB;
}
/* ############################################# POZOSTA£E FUNKCJE ############################################# */
