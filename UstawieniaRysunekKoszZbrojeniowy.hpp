#ifndef UstawieniaRysunekKoszZbrojeniowy_hpp
#define UstawieniaRysunekKoszZbrojeniowy_hpp

#include "elementyGeometryczne.hpp"

class UstawieniaRysunekKoszZbrojeniowy{
	
	private:
		
		Punkt punktPoczatkowyPierwszegoKosza;
		int OdstepKoszyWPoziomie = 2000;
		int OdstepKoszyWPionie = 1000;
		
		int PrzyJakiejRoznicyRzednychPrzerywacObrys = 100;
		int ilePonizejZbrojeniaPrzerwanie = 50;
		int ilePrzerwyObrysu = 25;
		int ileDolnejCzesciObrysu = 50;
		int jakDuzoWystajePrzerywanaOdObrysu = 20;
		
		int OdstepWidokSchematRozmieszczeniaPretowGlownych = -250;		
		int OdstepWidokPrzekrojAA = 1200;
		int OdstepPrzekrojAAPrzekrojBB = 780;
		int OdstepPrzekrojBBOdGory = 250;
		int OdstepPrzekrojBBPretyWyrzucone = 150;
		
		int OdstepPretowGlownychNaSchemacie = 60;
		
		int OdstepBocznyKotWysokosciowych = 80;
		int OdstepDodatkowyKotyMurkowProwadzacych = 250;
		
		int OdstepBocznyOpisowPretowGlownych = 30;
		int OdstepBocznyOpisowPretowGlownychLewy = 90;
		
		int IleTekstWymiaruNadLinia = 10;
		int OdstepWymiarowPoziomychPierwszejLinii = 50;
		int OdstepWymiarowPoziomychDrugiejLinii = 90;
		int OdstepWymiarowPionowychPierwszejLinii = 50;
		int OdstepWymiarowPionowychDrugiejLinii = 90;
		int OdstepWymiarowSchematRozmieszczeniaPretowGlownych = 35;
		
		Punkt OdstepTytuluKoszy;
		Punkt OdstepNapisuWidok;
		Punkt OdstepNapisuPrzekrojAA;
		Punkt OdstepNapisuPrzekrojBB;
		
	public:
		
		bool setPunktPoczatkowyPierwszegoKosza(Punkt PunktPoczatkowy);
		Punkt getPunktPoczatkowyPierwszegoKosza();
		
		bool setOdstepKoszyWPoziomie(int);
		int getOdstepKoszyWPoziomie();
		
		bool setOdstepKoszyWPionie(int);
		int getOdstepKoszyWPionie();		
				
		bool setPrzyJakiejRoznicyRzednychPrzerywacObrys(int);
		int getPrzyJakiejRoznicyRzednychPrzerywacObrys();
		
		bool setIlePonizejZbrojeniaPrzerwanie(int);
		int getIlePonizejZbrojeniaPrzerwanie();
		
		bool setIlePrzerwyObrysu(int);
		int getIlePrzerwyObrysu();
		
		bool setIleDolnejCzesciObrysu(int);
		int getIleDolnejCzesciObrysu();
		
		bool setJakDuzoWystajePrzerywanaOdObrysu(int);
		int getJakDuzoWystajePrzerywanaOdObrysu();
		
		bool setOdstepWidokSchematRozmieszczeniaPretowGlownych(int);
		int getOdstepWidokSchematRozmieszczeniaPretowGlownych();
				
		bool setOdstepWidokPrzekrojAA(int);
		int getOdstepWidokPrzekrojAA();
		
		bool setOdstepPrzekrojAAPrzekrojBB(int);
		int getOdstepPrzekrojAAPrzekrojBB();
				
		bool setOdstepPrzekrojBBOdGory(int);
		int getOdstepPrzekrojBBOdGory();
		
		bool setOdstepPrzekrojBBPretyWyrzucone(int);
		int getOdstepPrzekrojBBPretyWyrzucone();
		
		bool setOdstepPretowGlownychNaSchemacie(int);
		int getOdstepPretowGlownychNaSchemacie();
		
		bool setOdstepBocznyKotWysokosciowych(int);
		int getOdstepBocznyKotWysokosciowych();
		
		bool setOdstepBocznyOpisowPretowGlownych(int);
		int getOdstepBocznyOpisowPretowGlownych();
		
		bool setOdstepBocznyOpisowPretowGlownychLewy(int);
		int getOdstepBocznyOpisowPretowGlownychLewy();
		
		bool setOdstepDodatkowyKotyMurkowProwadzacych(int);
		int getOdstepDodatkowyKotyMurkowProwadzacych();
		
		bool setIleTekstWymiaruNadLinia(int);
		int getIleTekstWymiaruNadLinia();
		
		bool setOdstepWymiarowPoziomychPierwszejLinii(int);
		int getOdstepWymiarowPoziomychPierwszejLinii();
		
		bool setOdstepWymiarowPoziomychDrugiejLinii(int);
		int getOdstepWymiarowPoziomychDrugiejLinii();
		
		bool setOdstepWymiarowPionowychPierwszejLinii(int);
		int getOdstepWymiarowPionowychPierwszejLinii();
		
		bool setOdstepWymiarowPionowychDrugiejLinii(int);
		int getOdstepWymiarowPionowychDrugiejLinii();
		
		bool setOdstepWymiarowSchematRozmieszczeniaPretowGlownych(int);
		int getOdstepWymiarowSchematRozmieszczeniaPretowGlownych();
		
		
		bool setOdstepTytuluKoszy(Punkt Punkt);
		Punkt getOdstepTytuluKoszy();	

		bool setOdstepNapisuWidok(Punkt Punkt);
		Punkt getOdstepNapisuWidok();	
		
		bool setOdstepNapisuPrzekrojAA(Punkt Punkt);
		Punkt getOdstepNapisuPrzekrojAA();	
		
		bool setOdstepNapisuPrzekrojBB(Punkt Punkt);
		Punkt getOdstepNapisuPrzekrojBB();	
			
		UstawieniaRysunekKoszZbrojeniowy(){
			
			Punkt punktPoczatkowy;
	
			punktPoczatkowy.setX(-1000.0);
			punktPoczatkowy.setY(-2555.0);
			
			this->setPunktPoczatkowyPierwszegoKosza(punktPoczatkowy);
			
			
			Punkt OdstepTytuluKoszy;
	
			OdstepTytuluKoszy.setX(0.0);
			OdstepTytuluKoszy.setY(170.0);
			
			OdstepNapisuWidok.setX(0.0);
			OdstepNapisuWidok.setY(140.0);
			
			OdstepNapisuPrzekrojAA.setX(0.0);
			OdstepNapisuPrzekrojAA.setY(100.0);
			
			OdstepNapisuPrzekrojBB.setX(0.0);
			OdstepNapisuPrzekrojBB.setY(25.0);
			
			this->setOdstepTytuluKoszy(OdstepTytuluKoszy);
	
		}
		
};

#endif
