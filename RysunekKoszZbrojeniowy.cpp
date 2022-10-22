
#include "RysunekKoszZbrojeniowy.hpp"

using namespace std;

int CzyObrysPrzerwany(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){

	//sprawdza czy obrys przerwany i zwraca ile beda przesuniete rzednej ponizej;
	if((kosz.getRzednaSpoduZbrojenia() - kosz.getRzednaSpoduSciany()) > UstawieniaRysunku.getPrzyJakiejRoznicyRzednychPrzerywacObrys())
		return kosz.getRzednaSpoduSciany() + UstawieniaRysunku.getIleDolnejCzesciObrysu() - (kosz.getRzednaSpoduZbrojenia() - UstawieniaRysunku.getIlePonizejZbrojeniaPrzerwanie() - UstawieniaRysunku.getIlePrzerwyObrysu());

	return 0;
	
}

float korygujKolizjeOpisow(float RzedneOpisowJuzNarysowanych[], int LiczbaRzednychNarysowanych, int WysokoscOpisowNarysowanych, float RzednaMogacaKolidowac, int WysokoscOpisuNowego, bool przesuwajDoGory = 1){
	
		int j = 0, kierunek;
		
		float yp = RzednaMogacaKolidowac;
		
		vector<int> wektorPomocniczy(RzedneOpisowJuzNarysowanych, RzedneOpisowJuzNarysowanych + LiczbaRzednychNarysowanych);
		sort(wektorPomocniczy.begin(), wektorPomocniczy.end());
	
		if(przesuwajDoGory)
			kierunek = 1;
		else
			kierunek = -1;
		
		for(vector<int>::iterator it=wektorPomocniczy.begin(); it!=wektorPomocniczy.end(); ++it){
			
			if(abs(yp - *it) < (WysokoscOpisowNarysowanych + WysokoscOpisuNowego) / 2 ) {
				
				yp += kierunek * 35; 
				
				it=wektorPomocniczy.begin();
					
			}
		}
		
		return yp;
	
}

SymbolWykopGrunt generujSymbolWykopGrunt(float x, float y, float WysokoscTekstu = 10, int alfa = 0){

	//rysuje symbol wykop grunt
	SymbolWykopGrunt SymbolWykopGrunt;
	int n = 0;
	float xp, yp, xk, yk;
	float xpObrocone, ypObrocone, xkObrocone, ykObrocone;
	
	//tworzy ko³o symbolu	
	Circle circle;				//zmienna pomocnicza do utworzenia ko³a
	
	SymbolWykopGrunt.Circle[0].setDaneKola(
		circle.utworzKolo(x, y, 5));
	SymbolWykopGrunt.Circle[0].setNazwaWarstwy(opisy);
	
	//tworzy linie poziomie i pionowe symbolu
	Linia liniaPomocnicza;
	
	xp = x;
	yp = y;
	xk = x + 35;
	yk = y;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	xkObrocone = (xk - x) * cos(alfa * PI / 180) - (yk - y) * sin(alfa * PI / 180) + x;
	ykObrocone = (xk - x) * sin(alfa * PI / 180) + (yk - y) * cos(alfa * PI / 180) + y;
	
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(xpObrocone, ypObrocone, xkObrocone, ykObrocone);
	SymbolWykopGrunt.Linie[n].setWspolrzedneLinii(liniaPomocnicza);
	SymbolWykopGrunt.Linie[n++].setNazwaWarstwy(opisy);
	
	xp = x;
	yp = y;
	xk = x - 35;
	yk = y;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	xkObrocone = (xk - x) * cos(alfa * PI / 180) - (yk - y) * sin(alfa * PI / 180) + x;
	ykObrocone = (xk - x) * sin(alfa * PI / 180) + (yk - y) * cos(alfa * PI / 180) + y;
	
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(xpObrocone, ypObrocone, xkObrocone, ykObrocone);
	SymbolWykopGrunt.Linie[n].setWspolrzedneLinii(liniaPomocnicza);
	SymbolWykopGrunt.Linie[n++].setNazwaWarstwy(opisy);
	
	xp = x;
	yp = y - 10;
	xk = x;
	yk = y + 10;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	xkObrocone = (xk - x) * cos(alfa * PI / 180) - (yk - y) * sin(alfa * PI / 180) + x;
	ykObrocone = (xk - x) * sin(alfa * PI / 180) + (yk - y) * cos(alfa * PI / 180) + y;
	
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(xpObrocone, ypObrocone, xkObrocone, ykObrocone);
	SymbolWykopGrunt.Linie[n].setWspolrzedneLinii(liniaPomocnicza);
	SymbolWykopGrunt.Linie[n++].setNazwaWarstwy(opisy);
	
	//haczyki strza³ki
	xp = x + 35;
	yp = y;
	xk = x + 20;
	yk = y + 6;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	xkObrocone = (xk - x) * cos(alfa * PI / 180) - (yk - y) * sin(alfa * PI / 180) + x;
	ykObrocone = (xk - x) * sin(alfa * PI / 180) + (yk - y) * cos(alfa * PI / 180) + y;
	
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(xpObrocone, ypObrocone, xkObrocone, ykObrocone);
	SymbolWykopGrunt.Linie[n].setWspolrzedneLinii(liniaPomocnicza);
	SymbolWykopGrunt.Linie[n++].setNazwaWarstwy(opisy);
	
	xp = x - 35;
	yp = y;
	xk = x - 20;
	yk = y + 6;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	xkObrocone = (xk - x) * cos(alfa * PI / 180) - (yk - y) * sin(alfa * PI / 180) + x;
	ykObrocone = (xk - x) * sin(alfa * PI / 180) + (yk - y) * cos(alfa * PI / 180) + y;
	
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(xpObrocone, ypObrocone, xkObrocone, ykObrocone);
	SymbolWykopGrunt.Linie[n].setWspolrzedneLinii(liniaPomocnicza);
	SymbolWykopGrunt.Linie[n++].setNazwaWarstwy(opisy);
	
	//tworzy teksty "grunt" "wykop"
	Punkt punkt;
	
	xp = x - 55 * WysokoscTekstu / 10;
	yp = y - 25 * WysokoscTekstu / 10;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	
	punkt.setX(xpObrocone);
	punkt.setY(ypObrocone);
	SymbolWykopGrunt.Tekst[0].setPunktPoczatkowy(punkt);
	SymbolWykopGrunt.Tekst[0].LinieTekstu[0] = "wykop";
	SymbolWykopGrunt.Tekst[0].setWysokoscTekstu(WysokoscTekstu);
	SymbolWykopGrunt.Tekst[0].setIleLinii(1);

	xp = x + 55 * WysokoscTekstu / 10;
	yp = y - 25 * WysokoscTekstu / 10;
	
	//obrót
	xpObrocone = (xp - x) * cos(alfa * PI / 180) - (yp - y) * sin(alfa * PI / 180) + x;
	ypObrocone = (xp - x) * sin(alfa * PI / 180) + (yp - y) * cos(alfa * PI / 180) + y;
	
	punkt.setX(xpObrocone);
	punkt.setY(ypObrocone);
	SymbolWykopGrunt.Tekst[1].setPunktPoczatkowy(punkt);
	SymbolWykopGrunt.Tekst[1].LinieTekstu[0] = "grunt";
	SymbolWykopGrunt.Tekst[1].setWysokoscTekstu(WysokoscTekstu);
	SymbolWykopGrunt.Tekst[1].setIleLinii(1);
	
	return SymbolWykopGrunt;
	
}



/* ###################################### SCHEMAT ROZMIESZCZENIA PRETÓW G£ÓWNYCH ################################# */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool SchematRozmieszczeniaPretowGlownych::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt SchematRozmieszczeniaPretowGlownych::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void SchematRozmieszczeniaPretowGlownych::generujPretyGlowne(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz, Punkt PunktWierzchuZbrojenia, Punkt PunktSpoduZbrojenia){

	int i = 0, j = 0, k = 0, l = 0, n = 0;
	int PrzesuniecieX = -15, PrzesuniecieY = -100;
	float xp, x, yp, yk, y0;
	Linia liniaPomocnicza;
	
	int alfa = 90;
	
	x = this->getPunktPoczatkowy().getX();
	y0 = this->getPunktPoczatkowy().getY() - kosz.getRzednaWierzchuSciany();
	
	xp = x;
	
	//rysuje prêty dozbrojenia II od strony gruntu
	for(j = 0; kosz.DozbrojeniaOdStronyGruntuII[j].getNrPorzadkowy() != "brak"; j++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyGruntuII[j].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyGruntuII[j].getRzednaSpodu();
		
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);

		this->PretyGlowne[i].setWspolrzedneLinii(liniaPomocnicza);
		this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);

		//generuje wymiar od wierzchu zbrojenia do pocz¹tku prêta dozbrojenia
		if(j == 0)	
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				PunktWierzchuZbrojenia.getX(),
				PunktWierzchuZbrojenia.getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		//wymiaruje zak³ad
		if(j > 0)		
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getX(),
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				(this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() + this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX()) / 2,
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		this->OpisPretyGlowne[k++].generujOpisDoPreta(kosz.DozbrojeniaOdStronyGruntuII[j], liniaPomocnicza, PrzesuniecieX, PrzesuniecieY);
		
		//rozsuwa prêty na zak³adach
		if(j%2 == 0) 
			x = x - UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
		else
			x = x + UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
				
	}
	
	//generuje wymiar od spodu zbrojenia do pocz¹tku prêta dozbrojenia
	if(j > 0)
		this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getX(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getY(),
			PunktSpoduZbrojenia.getX(),
			PunktSpoduZbrojenia.getY(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
			UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
			alfa
		);
	
	//ustala punkt pocz¹tkowy dla kolejnego poziomu zbrojenia
	if(j > 1)
			xp = xp - 3 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	else if(j == 1)
			xp = xp - 2 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	x = xp;
	
	//rysuje prêty dozbrojenia I od strony gruntu
	for(j = 0; kosz.DozbrojeniaOdStronyGruntuI[j].getNrPorzadkowy() != "brak"; j++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyGruntuI[j].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyGruntuI[j].getRzednaSpodu();
		
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);
		
		this->PretyGlowne[i].setWspolrzedneLinii(liniaPomocnicza);
		this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);

		//generuje wymiar od wierzchu zbrojenia do pocz¹tku prêta dozbrojenia
		if(j == 0)	
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				PunktWierzchuZbrojenia.getX(),
				PunktWierzchuZbrojenia.getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
			
		//wymiaruje zak³ad
		if(j > 0)		
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getX(),
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				(this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() + this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX()) / 2,
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		this->OpisPretyGlowne[k++].generujOpisDoPreta(kosz.DozbrojeniaOdStronyGruntuI[j], liniaPomocnicza, PrzesuniecieX, PrzesuniecieY);
		
		//rozsuwa prêty na zak³adach
		if(j%2 == 0) 
			x = x - UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
		else
			x = x + UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
			
	}

	//generuje wymiar od spodu zbrojenia do pocz¹tku prêta dozbrojenia
	if(j > 0)
		this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getX(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getY(),
			PunktSpoduZbrojenia.getX(),
			PunktSpoduZbrojenia.getY(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
			UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
			alfa
		);

	//ustala punkt pocz¹tkowy dla kolejnego poziomu zbrojenia
	if(j > 1)
			xp = xp - 3 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	else if(j == 1)
			xp = xp - 2 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	x = xp;
			
	//rysuje prêty g³ówne	
	for(j = 0; kosz.PretyGlowne[0][j].getNrPorzadkowy() != "brak"; j++){
		
		yp = y0 + kosz.PretyGlowne[0][j].getRzednaWierzchu();
		yk = y0 + kosz.PretyGlowne[0][j].getRzednaSpodu();
		
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);
		
		this->PretyGlowne[i].setWspolrzedneLinii(liniaPomocnicza);
		this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
		
		//wymiaruje zak³ad
		if(j > 0)		
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getX(),
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				(this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() + this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX()) / 2,
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		this->OpisPretyGlowne[k++].generujOpisDoPreta(kosz.PretyGlowne[0][j], liniaPomocnicza, PrzesuniecieX, PrzesuniecieY);
		
		//rozsuwa prêty na zak³adach
		if(j%2 == 0) 
			x = x - UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
		else
			x = x + UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
			
	}
	
	// wylicza lokalizacje symbolu Wykop Grunt
	float xSymbolWykopGrunt = xp;
	float ySymbolWykopGrunt;

	//ustala punkt pocz¹tkowy dla kolejnego poziomu zbrojenia
	if(j > 1)
			xp = xp - 3 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	else if(j == 1)
			xp = xp - 2 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();

	// wylicza lokalizacje symbolu Wykop Grunt
	xSymbolWykopGrunt = (xSymbolWykopGrunt + xp) / 2;
	ySymbolWykopGrunt = yk - 70;
	
	//rysuje symbol wykop grunt
	this->SymbolWykopGrunt = generujSymbolWykopGrunt(xSymbolWykopGrunt, ySymbolWykopGrunt);
	
	
	x = xp;
		
	int m = j - 1;

	//rysuje prêty g³ówne drugi raz (od drugiej strony œciany)
	for(j = m; j >= 0; j--){

		yp = y0 + kosz.PretyGlowne[1][j].getRzednaWierzchu();
		yk = y0 + kosz.PretyGlowne[1][j].getRzednaSpodu();

		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);
		
		this->PretyGlowne[i].setWspolrzedneLinii(liniaPomocnicza);
		this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
		
		//wymiaruje zak³ad
		if(j < m)
				this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
					this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getX(),
					this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getY(),
					this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
					this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
					(this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() + this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX()) / 2,
					UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
					alfa
				);
		
		this->OpisPretyGlowne[k++].generujOpisDoPreta(kosz.PretyGlowne[1][j], liniaPomocnicza, PrzesuniecieX, PrzesuniecieY);
		
		//rozsuwa prêty na zak³adach
		if(j%2 != 0) 
			x = x + UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
		else
			x = x - UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
			
	}
	
	//ustala punkt pocz¹tkowy dla kolejnego poziomu zbrojenia
	if(j < m)
			xp = xp - 3 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	else if(j == 1)
			xp = xp - 2 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	x = xp;

	//rysuje prêty dozbrojenia I od strony wykopu
	for(j = 0; kosz.DozbrojeniaOdStronyWykopuI[j].getNrPorzadkowy() != "brak"; j++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyWykopuI[j].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyWykopuI[j].getRzednaSpodu();
		
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);
		
		this->PretyGlowne[i].setWspolrzedneLinii(liniaPomocnicza);
		this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
		
		//generuje wymiar od wierzchu zbrojenia do pocz¹tku prêta dozbrojenia
		if(j == 0)	
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				PunktWierzchuZbrojenia.getX(),
				PunktWierzchuZbrojenia.getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		//wymiaruje zak³ad
		if(j > 0)		
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getX(),
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				(this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() + this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX()) / 2,
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		this->OpisPretyGlowne[k++].generujOpisDoPreta(kosz.DozbrojeniaOdStronyWykopuI[j], liniaPomocnicza, PrzesuniecieX, PrzesuniecieY);
		
		//rozsuwa prêty na zak³adach
		if(j%2 != 0) 
			x = x + UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
		else
			x = x - UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
			
	}
	
	//generuje wymiar od spodu zbrojenia do pocz¹tku prêta dozbrojenia
	if(j > 0)
		this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getX(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getY(),
			PunktSpoduZbrojenia.getX(),
			PunktSpoduZbrojenia.getY(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
			UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
			alfa
		);
	
	//ustala punkt pocz¹tkowy dla kolejnego poziomu zbrojenia
	if(j > 1)
			xp = xp - 3 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	else if(j == 1)
			xp = xp - 2 * UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
	x = xp;

	//rysuje prêty dozbrojenia II od strony wykopu
	for(j = 0; kosz.DozbrojeniaOdStronyWykopuII[j].getNrPorzadkowy() != "brak"; j++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyWykopuII[j].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyWykopuII[j].getRzednaSpodu();
		
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);

		this->PretyGlowne[i].setWspolrzedneLinii(liniaPomocnicza);
		this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
		
		//generuje wymiar od wierzchu zbrojenia do pocz¹tku prêta dozbrojenia
		if(j == 0)	
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				PunktWierzchuZbrojenia.getX(),
				PunktWierzchuZbrojenia.getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
			
		//wymiaruje zak³ad
		if(j > 0)		
			this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getX(),
				this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktKoncowy().getY(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX(),
				this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY(),
				(this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() + this->PretyGlowne[i - 2].getWspolrzedneLinii().getPunktPoczatkowy().getX()) / 2,
				UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
				alfa
			);
		
		this->OpisPretyGlowne[k++].generujOpisDoPreta(kosz.DozbrojeniaOdStronyWykopuII[j], liniaPomocnicza, PrzesuniecieX, PrzesuniecieY);
		
		//rozsuwa prêty na zak³adach
		if(j%2 != 0) 
			x = x + UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
		else
			x = x - UstawieniaRysunku.getOdstepPretowGlownychNaSchemacie();
			
	}

	//generuje wymiar od spodu zbrojenia do pocz¹tku prêta dozbrojenia
	if(j > 0)
		this->WymiaryNormalne[l++].generujPojedynczyWymiarNormalny(
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getX(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktKoncowy().getY(),
			PunktSpoduZbrojenia.getX(),
			PunktSpoduZbrojenia.getY(),
			this->PretyGlowne[i - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepWymiarowSchematRozmieszczeniaPretowGlownych(),
			UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	
			alfa
		);

}

/* ########################################### WIDOK KOSZ ZBROJENIOWY ########################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool Widok::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt Widok::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

Punkt Widok::PunktKoncowy(Punkt punktPoczatkowy, koszZbrojeniowy kosz){	//generuje punkt obrysu po przek¹tnej od punktu startowego
	
	Punkt PunktKoncowy;
	
	PunktKoncowy.setX(punktPoczatkowy.getX() + kosz.getSzerokoscKosza());
	PunktKoncowy.setY(punktPoczatkowy.getY() - kosz.WysokoscSciany());
	
	return PunktKoncowy;
}

void Widok::generujPoziomMurkowProwadzacych(koszZbrojeniowy kosz, Punkt PunktPoczatkowyPrzekrojAA){
	
	int ileMaWystawacPoziomMurkow = 50;
	
	Linia liniaPomocnicza;
	
	float xp = this->getPunktPoczatkowy().getX() - ileMaWystawacPoziomMurkow;
	float yp = this->getPunktPoczatkowy().getY() + (kosz.getPoziomMurkowProwadzacych() - kosz.getRzednaWierzchuSciany());
	float xk = PunktPoczatkowyPrzekrojAA.getX() + kosz.getSzerokoscSciany() + ileMaWystawacPoziomMurkow;
	float yk = yp;
	
	this->poziomMurkowProwadzacych[0].setWspolrzedneLinii(liniaPomocnicza.stworzLinieZeWspolrzednych(xp, yp, xk, yk));
	this->poziomMurkowProwadzacych[0].setNazwaWarstwy(przerywana);
	
}

void Widok::generujPretyGlowne(koszZbrojeniowy kosz){
	
	int i=0;
	Linia linia;
	
	//wyliczenie wspó³rzêdnych pierwszego prêta 
	float PPx = this->getPunktPoczatkowy().getX() + (kosz.getSzerokoscKosza() - kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() * (kosz.PretyGlowne[0][0].getSztuki() - 1)) / 2;
	float PPy = this->getPunktPoczatkowy().getY() - (kosz.getRzednaWierzchuSciany() - kosz.getRzednaWierzchuZbrojenia());
	float PKx = PPx;
	float PKy = PPy - kosz.WysokoscKosza();
	
	this->PretyGlowne[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
	
	for(i; i < kosz.PretyGlowne[0][0].getSztuki(); i++){
		PPx = PPx + kosz.PretyGlowne[0][0].getOdstepMiedzyPretami(); // wylicza przesuniêcie kolejnej linii
		
		this->PretyGlowne[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PPy, PPx, PKy));
		this->PretyGlowne[i].setNazwaWarstwy(zbrojenie);
	}
}

void Widok::generujStrzemiona(koszZbrojeniowy kosz){
	
	int i=0;
	int ostatnieStrzemieJakBliskoKoncaZbrojenia = 10;
	Linia linia;
	
	//wyliczenie pierwszego strzemienia
	float PPx = this->getPunktPoczatkowy().getX();
	float PPy = this->getPunktPoczatkowy().getY() - 10;
	float PKx = PPx + kosz.getSzerokoscKosza();
	float PKy = PPy;
	
	this->Strzemiona[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->Strzemiona[i++].setNazwaWarstwy(zbrojenie);
	
	//rysuje dwa kolejne strzemiona o 15cm ni¿ej i potem ju¿ normalnie	
	PPy = PPy - 15;
	PKy = PPy;
	
	this->Strzemiona[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->Strzemiona[i++].setNazwaWarstwy(zbrojenie);
	
	PPy = PPy - 15;
	PKy = PPy;
	
	this->Strzemiona[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->Strzemiona[i++].setNazwaWarstwy(zbrojenie);
	
	//rysuje kolejne strzemiona zgodnie z odstêpem
	PPy = PPy - kosz.StrzemionaDuze.getOdstepMiedzyPretami();
	PKy = PPy;
	
	while(PPy - (this->getPunktPoczatkowy().getY() - (kosz.getRzednaWierzchuSciany() - kosz.getRzednaWierzchuZbrojenia()) - kosz.WysokoscKosza()) >= ostatnieStrzemieJakBliskoKoncaZbrojenia){	//sprawdza czy strzemiê nie wypada poni¿ej kosza zbrojeniowego
	
	this->Strzemiona[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->Strzemiona[i++].setNazwaWarstwy(zbrojenie);
	
	PPy = PPy - kosz.StrzemionaDuze.getOdstepMiedzyPretami();
	PKy = PPy;
	
	}

}

Punkt Widok::punktPoczatkowyPretowNr6(koszZbrojeniowy kosz){
	
	Punkt punkt;
	
	punkt.setX(this->punktPoczatkowy.getX());
	
	if(kosz.PretyNr6.getOdstepMiedzyPretami() > kosz.PretyNr6.GeometriaPreta2D.WysokoscPolilinii())
		punkt.setY(this->punktPoczatkowy.getY() - ((kosz.PretyNr6.getOdstepMiedzyPretami() - kosz.PretyNr6.GeometriaPreta2D.WysokoscPolilinii()) / 2)); //wyœrodkowuje uszy
	else
		punkt.setY(this->punktPoczatkowy.getY());
	
	return punkt;
	
}

Punkt Widok::punktPoczatkowyUszy(koszZbrojeniowy kosz){
	
	Punkt punktPomocniczy;
	
	float WysrodkowanieUszuMiedzyPretamiGlownymi = (kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() - kosz.Uszy.GeometriaPreta2D.SzerokoscPolilinii()) / 2;
	float BocznaOtulinaPretowGlownych = (kosz.getSzerokoscKosza() - kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() * (kosz.PretyGlowne[0][0].getSztuki() - 1)) / 2;

	punktPomocniczy.setX(this->getPunktPoczatkowy().getX() + BocznaOtulinaPretowGlownych + kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() + WysrodkowanieUszuMiedzyPretamiGlownymi);
		punktPomocniczy.setY(this->getPunktPoczatkowy().getY() + (kosz.getPoziomMurkowProwadzacych() - kosz.getRzednaWierzchuSciany()) - kosz.Uszy.GeometriaPreta2D.WysokoscPolilinii() + (kosz.getIleUszyPowyzejMurkow() - kosz.Uszy.GeometriaPreta2D.SzerokoscPolilinii() / 2));
	return punktPomocniczy;
	
}

void Widok::generujOpisyPretowNr6(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){

	int i = 0;
	float x, yp, yk, x1, y1, x2, y2;
	Punkt wspolrzedneZaczepienia[5];
	Linia liniaPomocnicza;

	x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();

	while(this->PretyNr6[2 * i].getNazwaWarstwy() != brak)	{
		
		yp = this->PretyNr6[i].getWspolrzedneVertex().getVertex(0).getY() - this->PretyNr6[i].getWspolrzedneVertex().WysokoscPolilinii() * 0.4;
		
		wspolrzedneZaczepienia[0].setY(this->PretyNr6[i].getWspolrzedneVertex().getVertex(0).getY() - this->PretyNr6[i].getWspolrzedneVertex().WysokoscPolilinii() * 0.25);
		
		//wyznacza równanie prostej i na podstawie zadanego X oblicza punkt na linii danego prêta nr 6
		x1 = this->PretyNr6[i].getWspolrzedneVertex().getVertex(1).getX();
		y1 = this->PretyNr6[i].getWspolrzedneVertex().getVertex(1).getY();
		x2 = this->PretyNr6[i].getWspolrzedneVertex().getVertex(2).getX();
		y2 = this->PretyNr6[i].getWspolrzedneVertex().getVertex(2).getY();
		
		//sprawdzanie kolizji z opisami prêtów g³ownych i korekta
		int j = 0;
		float pomocniczaTabelaY[100];
		for(j = 0; this->OpisPretyGlowne[j].getNrPorzadkowyPreta() != "brak"; j++)
			pomocniczaTabelaY[j] = this->OpisPretyGlowne[j].getPunktPoczatkowy().getY();
		
		yp = korygujKolizjeOpisow(pomocniczaTabelaY, j - 1, 25, yp, 25);
		
		bool przesuwajDoGory = 1;
		if(yp < wspolrzedneZaczepienia[0].getY())
			przesuwajDoGory = 0;
		
		wspolrzedneZaczepienia[0].setY(korygujKolizjeOpisow(pomocniczaTabelaY, j - 1, 15, wspolrzedneZaczepienia[0].getY(), 15, przesuwajDoGory));
		
		yk = yp;
		wspolrzedneZaczepienia[0].setX(((x2 - x1)/(y2 - y1)) * (wspolrzedneZaczepienia[0].getY() - y1) + x1);
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);
		
		this->OpisPretyNr6[i].generujOpisZLinia(kosz.PretyNr6, liniaPomocnicza, wspolrzedneZaczepienia, 1);
		
		//nadpisanie sztuk prêtów, do opisu widoku, bo s¹ wskazywane po dwa prêty na widoku
		this->OpisPretyNr6[i].setIloscPretow(2);
		
		i++;
	}
	
}

void Widok::generujOpisyPretow(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i = 0, j = -1, k = 0 , l = 0, m = 0;
	float x, yp, yk, y0, rzednaOpisu;
	float rzedneYNarysowane[50];
	Punkt wspolrzedneZaczepienia[50];
	Linia liniaPomocnicza;
	
	x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	y0 = this->getPunktPoczatkowy().getY() - kosz.getRzednaWierzchuSciany();
	
	//prety g³ówne
	for(m = 0; m < 2; m++)
		for(i = 0; kosz.PretyGlowne[m][i].getNrPorzadkowy() != "brak"; i++){
			
			yp = y0 + kosz.PretyGlowne[m][i].getRzednaWierzchu();
			yk = y0 + kosz.PretyGlowne[m][i].getRzednaSpodu();
			
			rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 50, (yp + yk) / 2, 50);
			
			//wyœrodkowuje opis pomiêdzy strzemionami
			j = 0;
			do{
				j++;
			}
			while(this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
			
			yp = this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
			yk = this->Strzemiona[j + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
			rzednaOpisu = (yp + yk) / 2;
			
			//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
			liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
			//generuje punkty zaczepienia opisu
			for(l = 0; l < kosz.PretyGlowne[0][i].getSztuki(); l++){
				wspolrzedneZaczepienia[l].setX(this->PretyGlowne[l].getWspolrzedneLinii().getPunktPoczatkowy().getX());
				wspolrzedneZaczepienia[l].setY(yk);
			}
			
			rzedneYNarysowane[k] = rzednaOpisu;
			
			this->OpisPretyGlowne[k++].generujOpisZLinia(kosz.PretyGlowne[m][i], liniaPomocnicza, wspolrzedneZaczepienia, l);
		}
	
	//dozbrojenie I od strony gruntu
	for(i = 0; kosz.DozbrojeniaOdStronyGruntuI[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyGruntuI[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyGruntuI[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->Strzemiona[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		l = 0;
		wspolrzedneZaczepienia[l++].setX(this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		
		for(l; l < kosz.DozbrojeniaOdStronyGruntuI[i].getSztuki(); l++){
			wspolrzedneZaczepienia[l].setX(wspolrzedneZaczepienia[l - 1].getX() + kosz.DozbrojeniaOdStronyGruntuI[i].getOdstepMiedzyPretami());
			wspolrzedneZaczepienia[l].setY(yk);
		}
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[k++].generujOpisZLinia(kosz.DozbrojeniaOdStronyGruntuI[i], liniaPomocnicza, wspolrzedneZaczepienia, l);
	}
	
	//dozbrojenie I od strony wykopu
	for(i = 0; kosz.DozbrojeniaOdStronyWykopuI[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyWykopuI[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyWykopuI[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->Strzemiona[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		l = 0;
		wspolrzedneZaczepienia[l++].setX(this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		
		for(l; l < kosz.DozbrojeniaOdStronyWykopuI[i].getSztuki(); l++){
			wspolrzedneZaczepienia[l].setX(wspolrzedneZaczepienia[l - 1].getX() + kosz.DozbrojeniaOdStronyWykopuI[i].getOdstepMiedzyPretami());
			wspolrzedneZaczepienia[l].setY(yk);
		}
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[k++].generujOpisZLinia(kosz.DozbrojeniaOdStronyWykopuI[i], liniaPomocnicza, wspolrzedneZaczepienia, l);
	}
	
	//dozbrojenie II od strony gruntu
	for(i = 0; kosz.DozbrojeniaOdStronyGruntuII[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyGruntuII[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyGruntuII[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->Strzemiona[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		l = 0;
		wspolrzedneZaczepienia[l++].setX(this->PretyGlowne[1].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		
		for(l; l < kosz.DozbrojeniaOdStronyGruntuII[i].getSztuki(); l++){
			wspolrzedneZaczepienia[l].setX(wspolrzedneZaczepienia[l - 1].getX() + kosz.DozbrojeniaOdStronyGruntuII[i].getOdstepMiedzyPretami());
			wspolrzedneZaczepienia[l].setY(yk);
		}
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[k++].generujOpisZLinia(kosz.DozbrojeniaOdStronyGruntuII[i], liniaPomocnicza, wspolrzedneZaczepienia, l);
	}
	
	//dozbrojenie II od strony wykopu
	for(i = 0; kosz.DozbrojeniaOdStronyWykopuII[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyWykopuII[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyWykopuII[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->Strzemiona[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		l = 0;
		wspolrzedneZaczepienia[l++].setX(this->PretyGlowne[1].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		
		for(l; l < kosz.DozbrojeniaOdStronyWykopuII[i].getSztuki(); l++){
			wspolrzedneZaczepienia[l].setX(wspolrzedneZaczepienia[l - 1].getX() + kosz.DozbrojeniaOdStronyWykopuII[i].getOdstepMiedzyPretami());
			wspolrzedneZaczepienia[l].setY(yk);
		}
		
		rzedneYNarysowane[k] = rzednaOpisu;

		this->OpisPretyGlowne[k++].generujOpisZLinia(kosz.DozbrojeniaOdStronyWykopuII[i], liniaPomocnicza, wspolrzedneZaczepienia, l);
	}
	
}

void Widok::generujOpisyDoUszu(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){

	int i = 0;
	float x, y;
	Punkt wspolrzedneZaczepienia[2];
	Linia liniaPomocnicza;
	
	x = this->getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	y = this->getPunktPoczatkowy().getY() - kosz.getRzednaWierzchuSciany() + kosz.getRzednaWierzchuZbrojenia() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	
	//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, y, x, y);

	//generuje punkty zaczepienia opisu
	wspolrzedneZaczepienia[0].setX(this->Uszy[0].getWspolrzedneVertex().getVertex(1).getX());
	wspolrzedneZaczepienia[0].setY(this->Uszy[0].getWspolrzedneVertex().getVertex(1).getY());
	
	wspolrzedneZaczepienia[1].setX(this->Uszy[1].getWspolrzedneVertex().getVertex(1).getX());
	wspolrzedneZaczepienia[1].setY(this->Uszy[1].getWspolrzedneVertex().getVertex(1).getY());
	
	this->OpisUszy[0].generujOpisZLinia(kosz.Uszy, liniaPomocnicza, wspolrzedneZaczepienia, 2);
	
}

void Widok::generujWymiaryNormalne(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i=0;
	int WspolrzednaLiniiWymiarowej;
	float ZaokraglonyWymiar;
	float xp, yp, xk, yk;
	
	Punkt punktStartowy, punktKoncowy, punktLokalizacjiLiniiWymiarowej, punktLokalizacjiTekstuWymiaru;
	ostringstream TekstZamiastWymiaru;	
	
	//wymiary poziome
	int alfa = 0;
	
	//pierwsza linia wymiarowa
	
	xp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	//zaokr¹gla koñcowe wymiary
	ZaokraglonyWymiar = ceil(2 * (abs(xp - xk))) / 2;			//zaokr¹gla do po³ówek w górê, dodane float bo jak dzielimy dwa inty to daje to inta
	TekstZamiastWymiaru << ZaokraglonyWymiar;
	
	WspolrzednaLiniiWymiarowej = yp - UstawieniaRysunku.getOdstepWymiarowPoziomychPierwszejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa, 1, -8, TekstZamiastWymiaru.str());
	
	//czyszczenie zmiennej z tekstem
	TekstZamiastWymiaru.clear();
	TekstZamiastWymiaru.str("");
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	
	int j = 0;
	while(this->PretyGlowne[++j].getNazwaWarstwy() != brak)	;
	
	xk = this->PretyGlowne[j - 1].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->PretyGlowne[j - 1].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	TekstZamiastWymiaru << j - 1 << "x" << kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() << "=" << (j - 1) * kosz.PretyGlowne[0][0].getOdstepMiedzyPretami();	//tworzy tekst wymiaru LiczbaPretow x OdlegloscMiedzyPretami = DlugoscOdcinka
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa, 1, 0, TekstZamiastWymiaru.str());
	
	//czyszczenie zmiennej z tekstem
	TekstZamiastWymiaru.clear();
	TekstZamiastWymiaru.str("");
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	//zaokr¹gla koñcowe wymiary
	ZaokraglonyWymiar = floor(2 * (abs(xp - xk))) / 2;			//zaokr¹gla do po³ówek w dó³, dodane float bo jak dzielimy dwa inty to daje to inta
	TekstZamiastWymiaru << ZaokraglonyWymiar;
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa, 1, 8, TekstZamiastWymiaru.str());
	
	//czyszczenie zmiennej z tekstem
	TekstZamiastWymiaru.clear();
	TekstZamiastWymiaru.str("");
	
	//druga linia wymiarowa
	
	xp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = yp - UstawieniaRysunku.getOdstepWymiarowPoziomychDrugiejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);


//wymiary pionowe
	alfa = 90;
	
	//pierwsza linia wymiarowa
	
	xp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yk = this->Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = xk - UstawieniaRysunku.getOdstepWymiarowPoziomychPierwszejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);	
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	xk = this->Strzemiona[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yk = this->Strzemiona[0].getWspolrzedneLinii().getPunktPoczatkowy().getY(); 
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);
	
	//kolejny wymiar
	//tutaj rozwi¹zanie przysz³oœciowe - dzieli strzemiona na odcinki o równy rozstawach i na tej podstawie rysuje wymiary
	
	j = 0;
	int OdlegloscStrzemion, PrzesuniecieWymiaru;
	int PoprzedniNumerZmianyRozstawuStrzemion = 0;
		
	while(this->Strzemiona[j].getNazwaWarstwy() != brak){
		
		OdlegloscStrzemion = this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() - this->Strzemiona[j + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	
		while(this->Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() - this->Strzemiona[(j++) + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY() == OdlegloscStrzemion)	;
		
		xp = xk;		//kontynuuje poprzedni wymiar
		yp = yk;
		xk = this->Strzemiona[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX();
		yk = this->Strzemiona[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		
		//czyszczenie zmiennej przechowuj¹cej tekst
		TekstZamiastWymiaru.str("");
		TekstZamiastWymiaru.clear();	 
		
		//tworzy tekst wymiaru LiczbaPretow x OdlegloscMiedzyPretami = DlugoscOdcinka
		TekstZamiastWymiaru << j - PoprzedniNumerZmianyRozstawuStrzemion - 1 << "x" << OdlegloscStrzemion << "=" << (j - PoprzedniNumerZmianyRozstawuStrzemion - 1) * OdlegloscStrzemion;
		
		//przesuwa wymiar jeœli jest za krótki i nie mieœci siê w liniach pomocniczych
		PrzesuniecieWymiaru = 0;
		if(yp - yk < 40)	PrzesuniecieWymiaru = -(yp - yk) - 20;
			
		this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa, 1, PrzesuniecieWymiaru, TekstZamiastWymiaru.str());
		
		PoprzedniNumerZmianyRozstawuStrzemion = j - 1;	
	}
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	xk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);
	
	
	//druga linia wymiarowa
	
	xp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = xk - UstawieniaRysunku.getOdstepWymiarowPoziomychDrugiejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);	
	
}

/* ######################################### PRZEKRÓJ AA KOSZ ZBROJENIOWY ########################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool PrzekrojAA::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt PrzekrojAA::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void PrzekrojAA::generujPretyGlowne(koszZbrojeniowy kosz){
	
	int i=0;
	Linia linia;
	
	//wyliczenie wspó³rzêdnych pierwszego prêta 
	float PPx = this->getPunktPoczatkowy().getX() + kosz.PretyGlowne[0][0].getOtulina();
	float PPy = this->getPunktPoczatkowy().getY() - (kosz.getRzednaWierzchuSciany() - kosz.getRzednaWierzchuZbrojenia());
	float PKx = PPx;
	float PKy = PPy - kosz.WysokoscKosza();
	
	this->PretyGlowne[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
	
	//wyliczenie wspó³rzêdnych drugiego prêta
	PPx = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscSciany() - kosz.PretyGlowne[0][0].getOtulina();
	PKx = PPx; 	
		
	this->PretyGlowne[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PPx, PKy));
	this->PretyGlowne[i++].setNazwaWarstwy(zbrojenie);
	
}

void PrzekrojAA::generujStrzemiona(koszZbrojeniowy kosz){

	int i=0, j=0;
	int ostatnieStrzemieJakBliskoKoncaZbrojenia = 10;
	Punkt przesuniecieStrzemionMalych, przesuniecieStrzemionDuzych;
	
	przesuniecieStrzemionDuzych.setX(-4.5);
	przesuniecieStrzemionDuzych.setY(0);
	
	przesuniecieStrzemionMalych.setX(3.0);
	przesuniecieStrzemionMalych.setY(-2.5);
	
	Linia linia;
	Circle circle;
	
	
	//wyliczenie pierwszego strzemienia
	float PPx = this->getPunktPoczatkowy().getX() + kosz.StrzemionaDuze.getOtulina() + przesuniecieStrzemionDuzych.getX();
	float PPy = this->getPunktPoczatkowy().getY() - 10;
	float PKx = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscSciany() - kosz.StrzemionaDuze.getOtulina() - przesuniecieStrzemionDuzych.getX();
	float PKy = PPy;
	
	this->StrzemionaDuze[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->StrzemionaDuze[i++].setNazwaWarstwy(zbrojenie);
	
	//rysuje strzemiona ma³e
	this->StrzemionaMale[j].setDaneKola(
		circle.utworzKolo(PPx + przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
	this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
	this->StrzemionaMale[j].setDaneKola(
		circle.utworzKolo(PKx - przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
	this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
	
	
	//rysuje dwa kolejne strzemiona o 15cm ni¿ej i potem ju¿ normalnie	
	PPy = PPy - 15;
	PKy = PPy;
	
	this->StrzemionaDuze[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->StrzemionaDuze[i++].setNazwaWarstwy(zbrojenie);
	
	//rysuje strzemiona ma³e
	this->StrzemionaMale[j].setDaneKola(
		circle.utworzKolo(PPx + przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
	this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
	this->StrzemionaMale[j].setDaneKola(
		circle.utworzKolo(PKx - przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
	this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
	
	PPy = PPy - 15;
	PKy = PPy;
	
	this->StrzemionaDuze[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
	this->StrzemionaDuze[i++].setNazwaWarstwy(zbrojenie);
	
		//rysuje strzemiona ma³e
	this->StrzemionaMale[j].setDaneKola(
		circle.utworzKolo(PPx + przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
	this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
	this->StrzemionaMale[j].setDaneKola(
		circle.utworzKolo(PKx - przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
	this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
	
	
	//rysuje kolejne strzemiona zgodnie z odstêpem		
	PPy = PPy - kosz.StrzemionaDuze.getOdstepMiedzyPretami();
	PKy = PPy;
	
	while(PPy - (this->getPunktPoczatkowy().getY() - (kosz.getRzednaWierzchuSciany() - kosz.getRzednaWierzchuZbrojenia()) - kosz.WysokoscKosza()) >= ostatnieStrzemieJakBliskoKoncaZbrojenia){	//sprawdza czy strzemiê nie wypada poni¿ej kosza zbrojeniowego
	
		this->StrzemionaDuze[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PKy));
		this->StrzemionaDuze[i++].setNazwaWarstwy(zbrojenie);
	
		//rysuje strzemiona ma³e
		this->StrzemionaMale[j].setDaneKola(
			circle.utworzKolo(PPx + przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
		this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
	
		this->StrzemionaMale[j].setDaneKola(
			circle.utworzKolo(PKx - przesuniecieStrzemionMalych.getX(), PPy + przesuniecieStrzemionMalych.getY(), 2 * kosz.StrzemionaMale[0].getSrednica() / 2));
		this->StrzemionaMale[j++].setNazwaWarstwy(zbrojenie);
		
		PPy = PPy - kosz.StrzemionaDuze.getOdstepMiedzyPretami();
		PKy = PPy;
	
	}
	
}

Punkt PrzekrojAA::punktPoczatkowyPretowNr7(koszZbrojeniowy kosz){
	
	Punkt punkt;
	
	punkt.setX(this->punktPoczatkowy.getX());
	
	if(kosz.PretyNr7.getOdstepMiedzyPretami() > kosz.PretyNr7.GeometriaPreta2D.WysokoscPolilinii())
		punkt.setY(this->punktPoczatkowy.getY() - ((kosz.PretyNr7.getOdstepMiedzyPretami() - kosz.PretyNr7.GeometriaPreta2D.WysokoscPolilinii()) / 2)); //wyœrodkowuje uszy
	else
		punkt.setY(this->punktPoczatkowy.getY());
	
	return punkt;
	
}

void PrzekrojAA::generujPretyNr9(koszZbrojeniowy kosz){
	
	int i = 0;
	float xp, yp;
	Punkt punkt;
	
	//oblicza punkt pocz¹tkowy prêta
	xp = this->getPunktPoczatkowy().getX() + ((kosz.getSzerokoscSciany() - kosz.UszyDuze[0].GeometriaPreta2D.SzerokoscPolilinii()) / 2);		//wyœrodkowuje prêt
	yp = this->StrzemionaDuze[0].getWspolrzedneLinii().getPunktPoczatkowy().getY() - (kosz.UszyDuze[0].GeometriaPreta2D.getVertex(1).getY() - kosz.UszyDuze[0].GeometriaPreta2D.getVertex(0).getY());
	
	punkt.setX(xp);
	punkt.setY(yp);
	
	this->PretyNr9[i].setWspolrzedneVertex(kosz.UszyDuze[i].GeometriaPreta2D.przesunPolilinie(punkt));
	this->PretyNr9[i].getWspolrzedneVertex().setLiczbaVertex(kosz.UszyDuze[i].GeometriaPreta2D.getLiczbaVertex());
	this->PretyNr9[i++].setNazwaWarstwy(zbrojenie);
	
	this->PretyNr9[i].setWspolrzedneVertex(kosz.UszyDuze[i].GeometriaPreta2D.przesunPolilinie(punkt));
	this->PretyNr9[i].getWspolrzedneVertex().setLiczbaVertex(kosz.UszyDuze[i].GeometriaPreta2D.getLiczbaVertex());
	this->PretyNr9[i++].setNazwaWarstwy(zbrojenie);
	
}

void PrzekrojAA::generujOpisyPretow(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i = 0, j = -1, k = 0 , l = 0;
	float x, yp, yk, y0, rzednaOpisu;
	float rzedneYNarysowane[50];
	Punkt wspolrzedneZaczepienia[10];
	Linia liniaPomocnicza;
	
	x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscSciany() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	y0 = this->getPunktPoczatkowy().getY() - kosz.getRzednaWierzchuSciany();
	
	//prety g³ówne
	for(i = 0; kosz.PretyGlowne[0][i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.PretyGlowne[0][i].getRzednaWierzchu();
		yk = y0 + kosz.PretyGlowne[0][i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->StrzemionaDuze[j + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
	
		//generuje punkty zaczepienia opisu
		wspolrzedneZaczepienia[0].setX(this->PretyGlowne[1].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		wspolrzedneZaczepienia[0].setY(yk);
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[0][k++].generujOpisZLinia(kosz.PretyGlowne[0][i], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	}
	
	//dozbrojenie I od strony gruntu
	for(i = 0; kosz.DozbrojeniaOdStronyGruntuI[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyGruntuI[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyGruntuI[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->StrzemionaDuze[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		wspolrzedneZaczepienia[0].setX(this->PretyGlowne[1].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		wspolrzedneZaczepienia[0].setY(yk);
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[0][k++].generujOpisZLinia(kosz.DozbrojeniaOdStronyGruntuI[i], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	}
	
	//dozbrojenie II od strony gruntu
	for(i = 0; kosz.DozbrojeniaOdStronyGruntuII[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyGruntuII[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyGruntuII[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->StrzemionaDuze[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		wspolrzedneZaczepienia[0].setX(this->PretyGlowne[1].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		wspolrzedneZaczepienia[0].setY(yk);
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[0][k++].generujOpisZLinia(kosz.DozbrojeniaOdStronyGruntuII[i], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	}

	x = this->getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownychLewy();

	//prety g³ówne
	for(i = 0; kosz.PretyGlowne[1][i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.PretyGlowne[1][i].getRzednaWierzchu();
		yk = y0 + kosz.PretyGlowne[1][i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->StrzemionaDuze[j + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
	
		//generuje punkty zaczepienia opisu
		wspolrzedneZaczepienia[0].setX(this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		wspolrzedneZaczepienia[0].setY(yk);
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[1][l++].generujOpisZLinia(kosz.PretyGlowne[1][i], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	}
	
	//dozbrojenie I od strony wykopu
	for(i = 0; kosz.DozbrojeniaOdStronyWykopuI[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyWykopuI[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyWykopuI[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->StrzemionaDuze[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		wspolrzedneZaczepienia[0].setX(this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		wspolrzedneZaczepienia[0].setY(yk);
		
		rzedneYNarysowane[k] = rzednaOpisu;
		
		this->OpisPretyGlowne[1][l++].generujOpisZLinia(kosz.DozbrojeniaOdStronyWykopuI[i], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	}
	
	//dozbrojenie II od strony wykopu
	for(i = 0; kosz.DozbrojeniaOdStronyWykopuII[i].getNrPorzadkowy() != "brak"; i++){
		
		yp = y0 + kosz.DozbrojeniaOdStronyWykopuII[i].getRzednaWierzchu();
		yk = y0 + kosz.DozbrojeniaOdStronyWykopuII[i].getRzednaSpodu();
		
		rzednaOpisu = korygujKolizjeOpisow(rzedneYNarysowane, k, 22, (yp + yk) / 2, 22);
		
		//wyœrodkowuje opis pomiêdzy strzemionami
		j = 0;
		do{
			j++;
		}
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu);
		
		yp = this->StrzemionaDuze[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, rzednaOpisu, x, rzednaOpisu);
		
		//generuje punkty zaczepienia opisu
		wspolrzedneZaczepienia[0].setX(this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX());
		wspolrzedneZaczepienia[0].setY(yk);
		
		rzedneYNarysowane[k] = rzednaOpisu;

		this->OpisPretyGlowne[1][l++].generujOpisZLinia(kosz.DozbrojeniaOdStronyWykopuII[i], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	}
	
}

void PrzekrojAA::generujOpisyPretowNr7(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){

	int i = 0;
	float x, yp, yk, x1, y1, x2, y2;
	Punkt wspolrzedneZaczepienia[5];
	Linia liniaPomocnicza;

	x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscSciany() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();

	while(this->PretyNr7[i].getNazwaWarstwy() != brak)	{
		
		yp = this->PretyNr7[i].getWspolrzedneVertex().getVertex(0).getY() - this->PretyNr7[i].getWspolrzedneVertex().WysokoscPolilinii() * 0.9;
		
		wspolrzedneZaczepienia[0].setY(this->PretyNr7[i].getWspolrzedneVertex().getVertex(0).getY() - this->PretyNr7[i].getWspolrzedneVertex().WysokoscPolilinii() * 0.8);
		
		//wyznacza równanie prostej i na podstawie zadanego X oblicza punkt na linii danego prêta nr 6
		x1 = this->PretyNr7[i].getWspolrzedneVertex().getVertex(3).getX();
		y1 = this->PretyNr7[i].getWspolrzedneVertex().getVertex(3).getY();
		x2 = this->PretyNr7[i].getWspolrzedneVertex().getVertex(4).getX();
		y2 = this->PretyNr7[i].getWspolrzedneVertex().getVertex(4).getY();
		
		//sprawdzanie kolizji z opisami prêtów g³ownych i korekta
		int j = 0;
		float pomocniczaTabelaY[100];
		for(j = 0; this->OpisPretyGlowne[0][j].getNrPorzadkowyPreta() != "brak"; j++)
			pomocniczaTabelaY[j] = this->OpisPretyGlowne[0][j].getPunktPoczatkowy().getY();
	
		yp = korygujKolizjeOpisow(pomocniczaTabelaY, j, 25, yp, 25);

		bool przesuwajDoGory = 1;
		if(yp < wspolrzedneZaczepienia[0].getY())
			przesuwajDoGory = 0;
		
		//wspolrzedneZaczepienia[0].setY(korygujKolizjeOpisow(pomocniczaTabelaY, j - 1, 15, wspolrzedneZaczepienia[0].getY(), 15, przesuwajDoGory));
		
		yk = yp;
		wspolrzedneZaczepienia[0].setX(((x2 - x1)/(y2 - y1)) * (wspolrzedneZaczepienia[0].getY() - y1) + x1);
		liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, yp, x, yk);
		
		this->OpisPretyNr7[i].generujOpisZLinia(kosz.PretyNr7, liniaPomocnicza, wspolrzedneZaczepienia, 1);
		
		//nadpisanie sztuk prêtów, do opisu widoku, bo s¹ wskazywane po dwa prêty na widoku
		switch(kosz.getIleStrzemionWPrzekroju()){
			
			case 3:
				
				this->OpisPretyNr7[i].setIloscPretow(3);
				break;
			
			case 2:
			case 1:
				
				this->OpisPretyNr7[i].setIloscPretow(2);		
				break;
			
		}
		
		i++;
	}
	
}

void PrzekrojAA::generujOpisyDoPretowNr9(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){

	int i = 0;
	float x, y;
	Punkt wspolrzedneZaczepienia[2];
	Linia liniaPomocnicza;
	
	x = this->getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	y = this->getPunktPoczatkowy().getY() - kosz.getRzednaWierzchuSciany() + kosz.getRzednaWierzchuZbrojenia() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	
	//tworzy abstrakcyjn¹ liniê, która pomaga osadziæ opis we w³aœciwym po³o¿eniu
	liniaPomocnicza = liniaPomocnicza.stworzLinieZeWspolrzednych(x, y, x, y);

	//generuje punkty zaczepienia opisu
	wspolrzedneZaczepienia[0].setX(this->PretyNr9[0].getWspolrzedneVertex().getVertex(3).getX());
	wspolrzedneZaczepienia[0].setY(this->PretyNr9[0].getWspolrzedneVertex().getVertex(3).getY());
	
	this->OpisPretyNr9[0].generujOpisZLinia(kosz.UszyDuze[0], liniaPomocnicza, wspolrzedneZaczepienia, 1);
	
}

void PrzekrojAA::generujWymiaryNormalne(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i=0;
	int WspolrzednaLiniiWymiarowej;
	float xp, yp, xk, yk;
	
	Punkt punktStartowy, punktKoncowy, punktLokalizacjiLiniiWymiarowej, punktLokalizacjiTekstuWymiaru;
	ostringstream TekstZamiastWymiaru;	
	
	//wymiary poziome
	int alfa = 0;
	
	//pierwsza linia wymiarowa
	
	xp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = yp - UstawieniaRysunku.getOdstepWymiarowPoziomychPierwszejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);
	
	// wylicza lokalizacje symbolu Wykop Grunt
	float xSymbolWykopGrunt = (xp + xk) / 2;
	float ySymbolWykopGrunt = WspolrzednaLiniiWymiarowej - 40;
	
	//rysuje symbol wykop grunt
	this->SymbolWykopGrunt = generujSymbolWykopGrunt(xSymbolWykopGrunt, ySymbolWykopGrunt);

//wymiary pionowe
	alfa = 90;
	
	//pierwsza linia wymiarowa
	
	xp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yk = this->Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = xk - UstawieniaRysunku.getOdstepWymiarowPoziomychPierwszejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);	
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	xk = this->StrzemionaDuze[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yk = this->StrzemionaDuze[0].getWspolrzedneLinii().getPunktPoczatkowy().getY(); 
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);
	
	//kolejny wymiar
	//tutaj rozwi¹zanie przysz³oœciowe - dzieli strzemiona na odcinki o równy rozstawach i na tej podstawie rysuje wymiary
	
	int j = 0;
	int OdlegloscStrzemion, PrzesuniecieWymiaru;
	int PoprzedniNumerZmianyRozstawuStrzemion = 0;
		
	while(this->StrzemionaDuze[j].getNazwaWarstwy() != brak){
		
		OdlegloscStrzemion = this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() - this->StrzemionaDuze[j + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	
		while(this->StrzemionaDuze[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() - this->StrzemionaDuze[(j++) + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY() == OdlegloscStrzemion)	;
		
		xp = xk;		//kontynuuje poprzedni wymiar
		yp = yk;
		xk = this->StrzemionaDuze[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getX();
		yk = this->StrzemionaDuze[j - 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		
		//czyszczenie zmiennej przechowuj¹cej tekst
		TekstZamiastWymiaru.str("");
		TekstZamiastWymiaru.clear();	 
		
		//tworzy tekst wymiaru LiczbaPretow x OdlegloscMiedzyPretami = DlugoscOdcinka
		TekstZamiastWymiaru << j - PoprzedniNumerZmianyRozstawuStrzemion - 1 << "x" << OdlegloscStrzemion << "=" << (j - PoprzedniNumerZmianyRozstawuStrzemion - 1) * OdlegloscStrzemion;
		
		//przesuwa wymiar jeœli jest za krótki i nie mieœci siê w liniach pomocniczych
		PrzesuniecieWymiaru = 0;
		if(yp - yk < 40)	PrzesuniecieWymiaru = -(yp - yk) - 20;
			
		this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa, 1, PrzesuniecieWymiaru, TekstZamiastWymiaru.str());
		
		PoprzedniNumerZmianyRozstawuStrzemion = j - 1;	
	}
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	xk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);
	
	
	//druga linia wymiarowa
	
	xp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = xk - UstawieniaRysunku.getOdstepWymiarowPoziomychDrugiejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(),	alfa);	
	
}

/* ######################################### PRZEKRÓJ BB KOSZ ZBROJENIOWY ########################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool PrzekrojBB::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt PrzekrojBB::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void PrzekrojBB::generujPretyGlowne(koszZbrojeniowy kosz){
	
	int i=1, j=0;
	Circle circle;
	
	//wyliczenie wspó³rzêdnych pierwszych prêtów w dwóch liniach
	float PPx = this->getPunktPoczatkowy().getX() + (kosz.getSzerokoscKosza() - kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() * (kosz.PretyGlowne[0][0].getSztuki() - 1)) / 2;
	float PPy1 = this->getPunktPoczatkowy().getY() - (kosz.PretyGlowne[0][0].getOtulina() + kosz.PretyGlowne[0][0].getSrednica() / 2);
	float PPy2 = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() + (kosz.PretyGlowne[1][0].getOtulina() + kosz.PretyGlowne[1][0].getSrednica() / 2);
	float Srednica1 = kosz.PretyGlowne[0][0].getSrednica();
	float Srednica2 = kosz.PretyGlowne[1][0].getSrednica();
	
	this->PretyGlowne[0][j].setDaneKola(circle.utworzKolo(PPx, PPy1, Srednica1 / 2));
	this->PretyGlowne[0][j].setNazwaWarstwy(zbrojenie);
	
	this->PretyGlowne[1][j].setDaneKola(circle.utworzKolo(PPx, PPy2, Srednica2 / 2));
	this->PretyGlowne[1][j++].setNazwaWarstwy(zbrojenie);
	
	for(i; i < kosz.PretyGlowne[0][0].getSztuki(); i++){
		PPx = PPx + kosz.PretyGlowne[0][0].getOdstepMiedzyPretami(); // wylicza przesuniêcie kolejnej linii
		
		//rysowanie pierwszej linii prêtów	
		this->PretyGlowne[0][j].setDaneKola(circle.utworzKolo(PPx, PPy1, Srednica1 / 2));
		this->PretyGlowne[0][j].setNazwaWarstwy(zbrojenie);
		
		//rysowanie drugiej linii prêtów
		this->PretyGlowne[1][j].setDaneKola(circle.utworzKolo(PPx, PPy2, Srednica2 / 2));
		this->PretyGlowne[1][j++].setNazwaWarstwy(zbrojenie);
	}

}

void PrzekrojBB::generujStrzemionaDuze(koszZbrojeniowy kosz){
	
	int i = 0;
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	//strzemie górne
	punkt.setX(this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() / 2);
	punkt.setY(this->getPunktPoczatkowy().getY() - kosz.StrzemionaDuze.getOtulina());
	
	this->StrzemionaDuze[i].setWspolrzedneVertex(kosz.StrzemionaDuze.GeometriaPreta2D.przesunPolilinie(punkt));
	this->StrzemionaDuze[i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaDuze.GeometriaPreta2D.getLiczbaVertex());
	this->StrzemionaDuze[i++].setNazwaWarstwy(zbrojenie);
	
	//strzemiê dolne	
	this->StrzemionaDuze[i].setWspolrzedneVertex(StrzemionaDuze[i - 1].getWspolrzedneVertex().odbicieLustrzanePoliliniiOsX(this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() / 2));
	this->StrzemionaDuze[i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaDuze.GeometriaPreta2D.getLiczbaVertex());
	this->StrzemionaDuze[i++].setNazwaWarstwy(zbrojenie);
}

void PrzekrojBB::generujStrzemionaMale(koszZbrojeniowy kosz){
	
	int i = 0;
	int IlePretowObejmuje;
	
	//definicja punktu tymczasowego, przechowuj¹cego wyliczone wspó³rzêdne
	Punkt punkt;
	
	if(kosz.StrzemionaMale[0].getSztuki() == 0 && kosz.StrzemionaMale[1].getSztuki() == 0)
		throw "Liczba wygenerowanych strzemion rowna zero!";
		
	//wylicza po³o¿enie œrodkowego strzemiona	
	int NrPretaSrodkowego = kosz.PretyGlowne[0][0].getSztuki() / 2;

	if(kosz.StrzemionaMale[1].getNrPorzadkowy() != "brak" && kosz.PretyGlowne[0][0].getSztuki() % 2 == 0){
		
		IlePretowObejmuje = kosz.StrzemionaMale[1].GeometriaPreta2D.SzerokoscPolilinii() / kosz.PretyGlowne[0][0].getOdstepMiedzyPretami();

		punkt.setX(this->PretyGlowne[0][NrPretaSrodkowego - IlePretowObejmuje / 2 - 1].getDaneKola().getSrodek().getX());
		punkt.setY(this->getPunktPoczatkowy().getY() - kosz.StrzemionaMale[0].getOtulina());
		
		this->StrzemionaMale[1][i].setWspolrzedneVertex(kosz.StrzemionaMale[1].GeometriaPreta2D.przesunPolilinie(punkt));
		this->StrzemionaMale[1][i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaMale[1].GeometriaPreta2D.getLiczbaVertex());
		this->StrzemionaMale[1][i].wspolrzedneVertex.setCzyZamknieta(1);
		this->StrzemionaMale[1][i++].setNazwaWarstwy(zbrojenie);
		
		i = 0;
		
	}
	else if((kosz.StrzemionaDuze.getSztuki() / 2) * 3 == (kosz.StrzemionaMale[0].getSztuki() + kosz.StrzemionaMale[1].getSztuki())){
		
		punkt.setX(this->PretyGlowne[0][NrPretaSrodkowego - 1].getDaneKola().getSrodek().getX());
		punkt.setY(this->getPunktPoczatkowy().getY() - kosz.StrzemionaMale[0].getOtulina());
		
		this->StrzemionaMale[0][i].setWspolrzedneVertex(kosz.StrzemionaMale[0].GeometriaPreta2D.przesunPolilinie(punkt));
		this->StrzemionaMale[0][i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaMale[0].GeometriaPreta2D.getLiczbaVertex());
		this->StrzemionaMale[0][i].wspolrzedneVertex.setCzyZamknieta(1);
		this->StrzemionaMale[0][i++].setNazwaWarstwy(zbrojenie);
		
	}
	else if(kosz.StrzemionaMale[1].getNrPorzadkowy() != "brak" && kosz.PretyGlowne[0][0].getSztuki() % 2 != 0){				// przypadek gdy mamy jedno strzemiê i liczba pretów jest nieparzysta
		
		punkt.setX(this->PretyGlowne[0][NrPretaSrodkowego - 1].getDaneKola().getSrodek().getX());
		punkt.setY(this->getPunktPoczatkowy().getY() - kosz.StrzemionaMale[1].getOtulina());
		
		this->StrzemionaMale[1][i].setWspolrzedneVertex(kosz.StrzemionaMale[1].GeometriaPreta2D.przesunPolilinie(punkt));
		this->StrzemionaMale[1][i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaMale[1].GeometriaPreta2D.getLiczbaVertex());
		this->StrzemionaMale[1][i].wspolrzedneVertex.setCzyZamknieta(1);
		this->StrzemionaMale[1][i++].setNazwaWarstwy(zbrojenie);
		
		i = 0;
	
	}
		
	
	if(kosz.StrzemionaMale[0].getNrPorzadkowy() != "brak"){
	
		int KtoryPretPierwszyLapieStrzemie = 1;
		IlePretowObejmuje = kosz.StrzemionaMale[0].GeometriaPreta2D.SzerokoscPolilinii() / kosz.PretyGlowne[0][0].getOdstepMiedzyPretami();
		
		if(kosz.getSzerokoscKosza() > 260)
			KtoryPretPierwszyLapieStrzemie++;	
		
		punkt.setY(this->getPunktPoczatkowy().getY() - kosz.StrzemionaMale[0].getOtulina());
		
	
		punkt.setX(this->PretyGlowne[0][KtoryPretPierwszyLapieStrzemie].getDaneKola().getSrodek().getX());
	
		this->StrzemionaMale[0][i].setWspolrzedneVertex(kosz.StrzemionaMale[0].GeometriaPreta2D.przesunPolilinie(punkt));
		this->StrzemionaMale[0][i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaMale[0].GeometriaPreta2D.getLiczbaVertex());
		this->StrzemionaMale[0][i].wspolrzedneVertex.setCzyZamknieta(1);
		this->StrzemionaMale[0][i++].setNazwaWarstwy(zbrojenie);
		
		
		punkt.setX(this->PretyGlowne[0][kosz.PretyGlowne[0][0].getSztuki() - KtoryPretPierwszyLapieStrzemie - IlePretowObejmuje - 1].getDaneKola().getSrodek().getX());
	
		this->StrzemionaMale[0][i].setWspolrzedneVertex(kosz.StrzemionaMale[0].GeometriaPreta2D.przesunPolilinie(punkt));
		this->StrzemionaMale[0][i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaMale[0].GeometriaPreta2D.getLiczbaVertex());
		this->StrzemionaMale[0][i].wspolrzedneVertex.setCzyZamknieta(1);
		this->StrzemionaMale[0][i++].setNazwaWarstwy(zbrojenie);
		
	}
	
}

void PrzekrojBB::generujPretyDozbrojenia(koszZbrojeniowy kosz, float RzednaPrzekroju){
	
	int i = 0, j = 0, k = 0;
	Circle circle;
	float PPx0, PPx, PPy, Srednica;
	
	for(int m = 0; kosz.DozbrojeniaOdStronyGruntuI[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyGruntuI[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyGruntuI[m].getRzednaSpodu()){
			
			//rysuje prêty dozbrojenia I od strony gruntu
			//wyliczenie wspó³rzêdnych pierwszego prêta
			PPx0 = this->PretyGlowne[0][0].getDaneKola().getSrodek().getX() + this->PretyGlowne[0][0].getDaneKola().getPromien() + kosz.DozbrojeniaOdStronyGruntuI[m].getSrednica() / 2;
			PPy = this->getPunktPoczatkowy().getY() - (kosz.DozbrojeniaOdStronyGruntuI[m].getOtulina() + kosz.DozbrojeniaOdStronyGruntuI[m].getSrednica() / 2);
			Srednica = kosz.DozbrojeniaOdStronyGruntuI[m].getSrednica();
			
			this->DozbrojeniaOdStronyGruntuI[i].setDaneKola(circle.utworzKolo(PPx0, PPy, Srednica / 2));
			this->DozbrojeniaOdStronyGruntuI[i++].setNazwaWarstwy(zbrojenie);
		
			for(i; i < kosz.DozbrojeniaOdStronyGruntuI[m].getSztuki(); i++){
				
				PPx = PPx0 + i * kosz.DozbrojeniaOdStronyGruntuI[m].getOdstepMiedzyPretami(); // wylicza przesuniêcie kolejnej linii
				Srednica = kosz.DozbrojeniaOdStronyGruntuI[m].getSrednica();
				
				//sprawdza czy najbli¿szy prêt nie jest ostatnim wewn¹trz strzemienia i jak tak to przerzuca dozbrojenie na lew¹ stronê
				
				//szuka ostatniego prêta g³ównego przed sob¹
				for(j = 0; abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()) < abs(PPx); j++)
					if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak) break;
				
				j--;
				
				//jeœli to ostatni prêt to przerzuca na lewo i koñczy pêtle
				if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak){
					
					PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
					break;
					
				}
				
				//szuka czy dozbrojenie wypada pomiedzy strzemionami skrajnymi
				for(k = 0; abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[0][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				//szuka czy dozbrojenie wypada pomiedzy œrodkowym strzemieniem
				for(k = 0; abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[1][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				this->DozbrojeniaOdStronyGruntuI[i].setDaneKola(circle.utworzKolo(PPx, PPy, Srednica / 2));
				this->DozbrojeniaOdStronyGruntuI[i].setNazwaWarstwy(zbrojenie);
		
			}	
			
		}


	for(int m = 0; kosz.DozbrojeniaOdStronyGruntuII[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyGruntuII[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyGruntuII[m].getRzednaSpodu()){	
		
			//rysuje prêty dozbrojenia II od strony gruntu
			//wyliczenie wspó³rzêdnych pierwszego prêta	
			
			i = 0;
			
			PPx0 = this->PretyGlowne[0][1].getDaneKola().getSrodek().getX() + this->PretyGlowne[0][1].getDaneKola().getPromien() + kosz.DozbrojeniaOdStronyGruntuII[m].getSrednica() / 2;
			PPy = this->getPunktPoczatkowy().getY() - (kosz.DozbrojeniaOdStronyGruntuII[m].getOtulina() + kosz.DozbrojeniaOdStronyGruntuII[m].getSrednica() / 2);
			Srednica = kosz.DozbrojeniaOdStronyGruntuII[m].getSrednica();
			
			this->DozbrojeniaOdStronyGruntuII[i].setDaneKola(circle.utworzKolo(PPx0, PPy, Srednica / 2));
			this->DozbrojeniaOdStronyGruntuII[i++].setNazwaWarstwy(zbrojenie);
		
			for(i; i < kosz.DozbrojeniaOdStronyGruntuII[m].getSztuki(); i++){
				
				PPx = PPx0 + i * kosz.DozbrojeniaOdStronyGruntuII[m].getOdstepMiedzyPretami(); // wylicza przesuniêcie kolejnej linii
				Srednica = kosz.DozbrojeniaOdStronyGruntuII[m].getSrednica();
				
				//sprawdza czy najbli¿szy prêt nie jest ostatnim wewn¹trz strzemienia i jak tak to przerzuca dozbrojenie na lew¹ stronê
				
				//szuka ostatniego prêta g³ównego przed sob¹
				for(j = 0; abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()) < abs(PPx); j++)
					if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak) break;
				
				j--;
		
				if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak){
		
					PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
					break;
					
				}
				
				//szuka czy dozbrojenie wypada pomiedzy strzemionami skrajnymi
				for(k = 0; abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[0][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				//szuka czy dozbrojenie wypada pomiedzy œrodkowym strzemieniem
				for(k = 0; abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[1][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				this->DozbrojeniaOdStronyGruntuII[i].setDaneKola(circle.utworzKolo(PPx, PPy, Srednica / 2));
				this->DozbrojeniaOdStronyGruntuII[i].setNazwaWarstwy(zbrojenie);
		
			}
			
		}
	
	for(int m = 0; kosz.DozbrojeniaOdStronyWykopuI[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyWykopuI[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyWykopuI[m].getRzednaSpodu()){	
			
			//rysuje prêty dozbrojenia I od strony wykopu
			//wyliczenie wspó³rzêdnych pierwszego prêta
			
			i = 0;
			
			PPx0 = this->PretyGlowne[0][0].getDaneKola().getSrodek().getX() + this->PretyGlowne[0][0].getDaneKola().getPromien() + kosz.DozbrojeniaOdStronyWykopuI[m].getSrednica() / 2;
			PPy = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() + (kosz.DozbrojeniaOdStronyWykopuI[m].getOtulina() + kosz.DozbrojeniaOdStronyWykopuI[m].getSrednica() / 2);
			Srednica = kosz.DozbrojeniaOdStronyWykopuI[m].getSrednica();
			
			this->DozbrojeniaOdStronyWykopuI[i].setDaneKola(circle.utworzKolo(PPx0, PPy, Srednica / 2));
			this->DozbrojeniaOdStronyWykopuI[i++].setNazwaWarstwy(zbrojenie);
		
			for(i; i < kosz.DozbrojeniaOdStronyWykopuI[m].getSztuki(); i++){
				
				PPx = PPx0 + i * kosz.DozbrojeniaOdStronyWykopuI[m].getOdstepMiedzyPretami(); // wylicza przesuniêcie kolejnej linii
				Srednica = kosz.DozbrojeniaOdStronyWykopuI[m].getSrednica();
				
				//sprawdza czy najbli¿szy prêt nie jest ostatnim wewn¹trz strzemienia i jak tak to przerzuca dozbrojenie na lew¹ stronê
				
				//szuka ostatniego prêta g³ównego przed sob¹
				for(j = 0; abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()) < abs(PPx); j++)
					if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak) break;
				
				j--;
				
				//jeœli to ostatni prêt to przerzuca na lewo i koñczy pêtle
				if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak){
					
					PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
					break;
					
				}
				
				//szuka czy dozbrojenie wypada pomiedzy strzemionami skrajnymi
				for(k = 0; abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[0][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				//szuka czy dozbrojenie wypada pomiedzy œrodkowym strzemieniem
				for(k = 0; abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[1][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				this->DozbrojeniaOdStronyWykopuI[i].setDaneKola(circle.utworzKolo(PPx, PPy, Srednica / 2));
				this->DozbrojeniaOdStronyWykopuI[i].setNazwaWarstwy(zbrojenie);
		
			}
		}
	
	for(int m = 0; kosz.DozbrojeniaOdStronyWykopuII[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyWykopuII[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyWykopuII[m].getRzednaSpodu()){
		
			//rysuje prêty dozbrojenia II od strony wykopu
			//wyliczenie wspó³rzêdnych pierwszego prêta	
			
			i = 0;
			
			PPx0 = this->PretyGlowne[0][1].getDaneKola().getSrodek().getX() + this->PretyGlowne[0][1].getDaneKola().getPromien() + kosz.DozbrojeniaOdStronyWykopuII[m].getSrednica() / 2;
			PPy = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() + (kosz.DozbrojeniaOdStronyWykopuII[0].getOtulina() + kosz.DozbrojeniaOdStronyWykopuII[m].getSrednica() / 2);
			Srednica = kosz.DozbrojeniaOdStronyWykopuII[m].getSrednica();
			
			this->DozbrojeniaOdStronyWykopuII[i].setDaneKola(circle.utworzKolo(PPx0, PPy, Srednica / 2));
			this->DozbrojeniaOdStronyWykopuII[i++].setNazwaWarstwy(zbrojenie);
		
			for(i; i < kosz.DozbrojeniaOdStronyWykopuII[m].getSztuki(); i++){
				
				PPx = PPx0 + i * kosz.DozbrojeniaOdStronyWykopuII[m].getOdstepMiedzyPretami(); // wylicza przesuniêcie kolejnej linii
				Srednica = kosz.DozbrojeniaOdStronyWykopuII[m].getSrednica();
				
				//sprawdza czy najbli¿szy prêt nie jest ostatnim wewn¹trz strzemienia i jak tak to przerzuca dozbrojenie na lew¹ stronê
				
				//szuka ostatniego prêta g³ównego przed sob¹
				for(j = 0; abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()) < abs(PPx); j++)
					if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak) break;
				
				j--;
		
				if(this->PretyGlowne[0][j + 1].getNazwaWarstwy() == brak){
		
					PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
					break;
					
				}
				
				//szuka czy dozbrojenie wypada pomiedzy strzemionami skrajnymi
				for(k = 0; abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[0][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[0][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				//szuka czy dozbrojenie wypada pomiedzy œrodkowym strzemieniem
				for(k = 0; abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) < abs(PPx); k++){
					
					if(this->StrzemionaMale[1][k].getNazwaWarstwy() == brak) break;
					
					if(abs(this->StrzemionaMale[1][k].getWspolrzedneVertex().getVertex(2).getX()) > abs(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX()))
							PPx = PPx - 2 * this->PretyGlowne[0][j].getDaneKola().getPromien() - Srednica;
							
				}
				
				this->DozbrojeniaOdStronyWykopuII[i].setDaneKola(circle.utworzKolo(PPx, PPy, Srednica / 2));
				this->DozbrojeniaOdStronyWykopuII[i].setNazwaWarstwy(zbrojenie);
		
			}
		}

} 

void PrzekrojBB::generujOpisyPretyGlowne(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz, float RzednaPrzekroju){
	
	int i = 0, j = 0;
	float x, y; 
	Punkt WspolrzedneZaczepienia[50];
	Linia linia;
	
	for(int m = 0; kosz.DozbrojeniaOdStronyGruntuII[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyGruntuII[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyGruntuII[m].getRzednaSpodu()){
			
			//lokalizacja opisu - od strony gruntu - dozbrojenie II
			x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
			y = this->getPunktPoczatkowy().getY() + kosz.getSzerokoscSciany() * 0.75;
			
			linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
			
			//punkty zaczepienia
			for(j = 0; this->DozbrojeniaOdStronyGruntuII[j].getNazwaWarstwy() != brak; j++){
				WspolrzedneZaczepienia[j].setX(this->DozbrojeniaOdStronyGruntuII[j].getDaneKola().getSrodek().getX());
				WspolrzedneZaczepienia[j].setY(this->DozbrojeniaOdStronyGruntuII[j].getDaneKola().getSrodek().getY());
			}
			
			//tworzy opis
		
			this->OpisPretyGlowne[i].generujOpisZLinia(kosz.DozbrojeniaOdStronyGruntuII[m], linia, WspolrzedneZaczepienia, j);
			this->OpisPretyGlowne[i].setSkala(0.5);
			this->OpisPretyGlowne[i++].setIloscPretow(j);
		
		}
	
	for(int m = 0; kosz.DozbrojeniaOdStronyGruntuI[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyGruntuI[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyGruntuI[m].getRzednaSpodu()){
		
			//lokalizacja opisu - od strony gruntu - dozbrojenie I
			x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
			y = this->getPunktPoczatkowy().getY() + kosz.getSzerokoscSciany() * 0.5;
			
			linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
			
			//punkty zaczepienia
			for(j = 0; this->DozbrojeniaOdStronyGruntuI[j].getNazwaWarstwy() != brak; j++){
				WspolrzedneZaczepienia[j].setX(this->DozbrojeniaOdStronyGruntuI[j].getDaneKola().getSrodek().getX());
				WspolrzedneZaczepienia[j].setY(this->DozbrojeniaOdStronyGruntuI[j].getDaneKola().getSrodek().getY());
			}
			
			//tworzy opis
			this->OpisPretyGlowne[i].generujOpisZLinia(kosz.DozbrojeniaOdStronyGruntuI[m], linia, WspolrzedneZaczepienia, j);
			this->OpisPretyGlowne[i].setSkala(0.5);
			this->OpisPretyGlowne[i++].setIloscPretow(j);
			
		}
	
	//lokalizacja opisu - od strony gruntu
	x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	y = this->getPunktPoczatkowy().getY() + kosz.getSzerokoscSciany() * 0.25;
	
	linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
	
	//punkty zaczepienia
	for(j = 0; this->PretyGlowne[0][j].getNazwaWarstwy() != brak; j++){
		WspolrzedneZaczepienia[j].setX(this->PretyGlowne[0][j].getDaneKola().getSrodek().getX());
		WspolrzedneZaczepienia[j].setY(this->PretyGlowne[0][j].getDaneKola().getSrodek().getY());
	}
	
	//tworzy opis
	this->OpisPretyGlowne[i].generujOpisZLinia(kosz.PretyGlowne[0][0], linia, WspolrzedneZaczepienia, j);
	this->OpisPretyGlowne[i].setSkala(0.5);
	this->OpisPretyGlowne[i++].setIloscPretow(j);
	
	
	//lokalizacja opisu - od strony wykopu
	x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
	y = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() * 1.25;
	
	linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
	
	//punkty zaczepienia
	for(j = 0; this->PretyGlowne[1][j].getNazwaWarstwy() != brak; j++){
		WspolrzedneZaczepienia[j].setX(this->PretyGlowne[1][j].getDaneKola().getSrodek().getX());
		WspolrzedneZaczepienia[j].setY(this->PretyGlowne[1][j].getDaneKola().getSrodek().getY());
	}
	
	//tworzy opis
	this->OpisPretyGlowne[i].generujOpisZLinia(kosz.PretyGlowne[1][0], linia, WspolrzedneZaczepienia, j);
	this->OpisPretyGlowne[i].setSkala(0.5);
	this->OpisPretyGlowne[i++].setIloscPretow(j);
	
	for(int m = 0; kosz.DozbrojeniaOdStronyWykopuI[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyWykopuI[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyWykopuI[m].getRzednaSpodu()){
		
			//lokalizacja opisu - od strony wykopu - dozbrojenie I
			x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
			y = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() * 1.5;
			
			linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
			
			//punkty zaczepienia
			for(j = 0; this->DozbrojeniaOdStronyWykopuI[j].getNazwaWarstwy() != brak; j++){
				WspolrzedneZaczepienia[j].setX(this->DozbrojeniaOdStronyWykopuI[j].getDaneKola().getSrodek().getX());
				WspolrzedneZaczepienia[j].setY(this->DozbrojeniaOdStronyWykopuI[j].getDaneKola().getSrodek().getY());
			}
			
			//tworzy opis
			this->OpisPretyGlowne[i].generujOpisZLinia(kosz.DozbrojeniaOdStronyWykopuI[m], linia, WspolrzedneZaczepienia, j);
			this->OpisPretyGlowne[i].setSkala(0.5);
			this->OpisPretyGlowne[i++].setIloscPretow(j);
			
		}
	
	for(int m = 0; kosz.DozbrojeniaOdStronyWykopuII[m].getNrPorzadkowy() != "brak"; m++)
		if(RzednaPrzekroju <= kosz.DozbrojeniaOdStronyWykopuII[m].getRzednaWierzchu() && RzednaPrzekroju >= kosz.DozbrojeniaOdStronyWykopuII[m].getRzednaSpodu()){
		
			//lokalizacja opisu - od strony wykopu - dozbrojenie II
			x = this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
			y = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() * 1.75;
			
			linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
			
			//punkty zaczepienia
			for(j = 0; this->DozbrojeniaOdStronyWykopuII[j].getNazwaWarstwy() != brak; j++){
				WspolrzedneZaczepienia[j].setX(this->DozbrojeniaOdStronyWykopuII[j].getDaneKola().getSrodek().getX());
				WspolrzedneZaczepienia[j].setY(this->DozbrojeniaOdStronyWykopuII[j].getDaneKola().getSrodek().getY());
			}
			
			//tworzy opis
			this->OpisPretyGlowne[i].generujOpisZLinia(kosz.DozbrojeniaOdStronyWykopuII[m], linia, WspolrzedneZaczepienia, j);
			this->OpisPretyGlowne[i].setSkala(0.5);
			this->OpisPretyGlowne[i++].setIloscPretow(j);
			
		}
	
}

void PrzekrojBB::generujOpisyStrzemionMalych(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i = 0, j = 0;
	float x, y; 
	Punkt WspolrzedneZaczepienia[10];
	Linia linia;
	
	if(this->StrzemionaMale[0][0].getNazwaWarstwy() != brak){	
		
		//lokalizacja opisu
		x = this->getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
		y = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() * 0.25;
		
		linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
		
		//punkty zaczepienia
		for(j = 0; this->StrzemionaMale[0][j].getNazwaWarstwy() != brak; j++){
			WspolrzedneZaczepienia[j].setX(this->StrzemionaMale[0][j].getWspolrzedneVertex().getVertex(7).getX());
			WspolrzedneZaczepienia[j].setY(0);
		}
		
		//tworzy opis
		this->OpisStrzemionaMale[i].generujOpisZLinia(kosz.StrzemionaMale[i], linia, WspolrzedneZaczepienia, j);
		this->OpisStrzemionaMale[i].setSkala(0.5);
		this->OpisStrzemionaMale[i++].setIloscPretow(j);
	}
	
	if(this->StrzemionaMale[1][0].getNazwaWarstwy() != brak){	
		
		//lokalizacja opisu
		x = this->getPunktPoczatkowy().getX() - UstawieniaRysunku.getOdstepBocznyOpisowPretowGlownych();
		y = this->getPunktPoczatkowy().getY() - kosz.getSzerokoscSciany() * 0.75;
		
		linia = linia.stworzLinieZeWspolrzednych(x, y, x, y);
		
		//punkty zaczepienia
		for(j = 0; this->StrzemionaMale[1][j].getNazwaWarstwy() != brak; j++){
			WspolrzedneZaczepienia[j].setX(this->StrzemionaMale[1][j].getWspolrzedneVertex().getVertex(7).getX());
			WspolrzedneZaczepienia[j].setY(0);
		}
		
		//tworzy opis
		this->OpisStrzemionaMale[i].generujOpisZLinia(kosz.StrzemionaMale[i], linia, WspolrzedneZaczepienia, j);
		this->OpisStrzemionaMale[i].setSkala(0.5);
		this->OpisStrzemionaMale[i++].setIloscPretow(j);
	}
	
}

void PrzekrojBB::generujWymiaryNormalne(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i = 0;
	int minY = 0;
	int WspolrzednaLiniiWymiarowej;
	float ZaokraglonyWymiar;
	float xp, yp, xk, yk, Skala = 0.5;
	
	Punkt punktStartowy, punktKoncowy, punktLokalizacjiLiniiWymiarowej, punktLokalizacjiTekstuWymiaru;
	ostringstream TekstZamiastWymiaru;	
	
	//wymiary poziome
	int alfa = 0;
	
	//pierwsza linia wymiarowa
	
	xp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->PretyGlowne[1][0].getDaneKola().getSrodek().getX();
	yk = this->PretyGlowne[1][0].getDaneKola().getSrodek().getY(); 
	
	//zaokr¹gla koñcowe wymiary
	ZaokraglonyWymiar = ceil(2 * (abs(xp - xk))) / 2;			//zaokr¹gla do po³ówek w górê, dodane float bo jak dzielimy dwa inty to daje to inta
	TekstZamiastWymiaru << ZaokraglonyWymiar;
	
	minY = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	
	for(int j = 0; this->OpisPretyGlowne[j].getNrPorzadkowyPreta() != "brak"; j++)
		if(minY > this->OpisPretyGlowne[j].getPunktPoczatkowy().getY())
			minY = this->OpisPretyGlowne[j].getPunktPoczatkowy().getY();
	
	WspolrzednaLiniiWymiarowej = minY - Skala * UstawieniaRysunku.getOdstepWymiarowPoziomychPierwszejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala, -8, TekstZamiastWymiaru.str());
	
	//czyszczenie zmiennej z tekstem
	TekstZamiastWymiaru.clear();
	TekstZamiastWymiaru.str("");
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	
	int j = 0;
	while(this->PretyGlowne[1][++j].getNazwaWarstwy() != brak)	;
	
	xk = this->PretyGlowne[1][j - 1].getDaneKola().getSrodek().getX();
	yk = this->PretyGlowne[1][j - 1].getDaneKola().getSrodek().getY(); 
	
	TekstZamiastWymiaru << j - 1 << "x" << kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() << "=" << (j - 1) * kosz.PretyGlowne[0][0].getOdstepMiedzyPretami();	//tworzy tekst wymiaru LiczbaPretow x OdlegloscMiedzyPretami = DlugoscOdcinka
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala, 0, TekstZamiastWymiaru.str());
	
	//czyszczenie zmiennej z tekstem
	TekstZamiastWymiaru.clear();
	TekstZamiastWymiaru.str("");
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	//zaokr¹gla koñcowe wymiary
	ZaokraglonyWymiar = floor(2 * (abs(xp - xk))) / 2;			//zaokr¹gla do po³ówek w górê, dodane float bo jak dzielimy dwa inty to daje to inta
	TekstZamiastWymiaru << ZaokraglonyWymiar;
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala, 8, TekstZamiastWymiaru.str());
	
	//czyszczenie zmiennej z tekstem
	TekstZamiastWymiaru.clear();
	TekstZamiastWymiaru.str("");
	
	//druga linia wymiarowa
	
	xp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getX();
	yp = this->Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	WspolrzednaLiniiWymiarowej = minY - Skala * UstawieniaRysunku.getOdstepWymiarowPoziomychDrugiejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala);

//wymiary pionowe
	alfa = 90;
	
	//pierwsza linia wymiarowa
	
	xp = this->Obrys[2].getWspolrzedneLinii().getPunktKoncowy().getX();
	yp = this->Obrys[2].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	xk = this->PretyGlowne[0][j - 1].getDaneKola().getSrodek().getX();
	yk = this->PretyGlowne[0][j - 1].getDaneKola().getSrodek().getY() + this->PretyGlowne[0][j - 1].getDaneKola().getPromien();
	
	WspolrzednaLiniiWymiarowej = xk + Skala * UstawieniaRysunku.getOdstepWymiarowPoziomychPierwszejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala);	
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	xk = this->PretyGlowne[1][j - 1].getDaneKola().getSrodek().getX();
	yk = this->PretyGlowne[1][j - 1].getDaneKola().getSrodek().getY() - this->PretyGlowne[1][j - 1].getDaneKola().getPromien();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala);
	
	//kolejny wymiar
	
	xp = xk;		//kontynuuje poprzedni wymiar
	yp = yk;
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala);
	
	//druga linia wymiarowa
	
	xp = this->Obrys[2].getWspolrzedneLinii().getPunktKoncowy().getX();
	yp = this->Obrys[2].getWspolrzedneLinii().getPunktKoncowy().getY(); 
	xk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getX();
	yk = this->Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY();
	
	WspolrzednaLiniiWymiarowej = xk + Skala * UstawieniaRysunku.getOdstepWymiarowPoziomychDrugiejLinii();
	
	this->WymiaryNormalne[i++].generujPojedynczyWymiarNormalny(xp, yp, xk, yk, WspolrzednaLiniiWymiarowej, UstawieniaRysunku.getIleTekstWymiaruNadLinia(), alfa, Skala);	
	
	// wylicza lokalizacje symbolu Wykop Grunt
	float xSymbolWykopGrunt = WspolrzednaLiniiWymiarowej + 60;
	float ySymbolWykopGrunt = (yp + yk) / 2;
	
	//rysuje symbol wykop grunt
	this->SymbolWykopGrunt = generujSymbolWykopGrunt(xSymbolWykopGrunt, ySymbolWykopGrunt, 5, 90);
}

/* ############################################### PRÊTY WYRZUCONE ################################################ */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool PretyWyrzucone::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt PretyWyrzucone::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void PretyWyrzucone::obmiarujPolilinie(Polilinia polilinia){
	
	int i = 0, k = 0;
	Punkt p1, p2, srodekLuku;
	Linia linia;
	
	//szuka w tablicy pierwszego wolnego miejsca na wymiar
	for(i; this->WymiaryNormalne[i].getKatObrotuWymiaru() != -360; i++) ;

	for(int j = 1; j < polilinia.getLiczbaVertex(); j++){
		
		if(polilinia.getVertex(j - 1).getTanZaokraglenia() == 0){
			p1 = polilinia.getVertex(j - 1);
			p2 = polilinia.getVertex(j);
			
			linia.setPunktPoczatkowy(p1);
			linia.setPunktKoncowy(p2);
			
			this->WymiaryNormalne[i].setPunktStartowy(p1);
			this->WymiaryNormalne[i].setPunktKoncowy(p2);
			
			//wyznacza odsuniêcie linii wymiarowej
			linia = linia.przesunRownolegle(2);
			
			p1.setX((linia.getPunktPoczatkowy().getX() + linia.getPunktKoncowy().getX()) / 2);
			p1.setY((linia.getPunktPoczatkowy().getY() + linia.getPunktKoncowy().getY()) / 2);
			
			this->WymiaryNormalne[i].setPunktLokalizacjiLiniiWymiarowej(p1);
			
			//wyznacza odsuniêcie tekstu wymiarowego		
			linia = linia.przesunRownolegle(0);
			
			p1.setX((linia.getPunktPoczatkowy().getX() + linia.getPunktKoncowy().getX()) / 2);
			p1.setY((linia.getPunktPoczatkowy().getY() + linia.getPunktKoncowy().getY()) / 2);
			
			this->WymiaryNormalne[i].setPunktLokalizacjiTekstuWymiaru(p1);
			this->WymiaryNormalne[i].setAligned(1);
			this->WymiaryNormalne[i].setStyl("OPIS_ZBROJ");
			this->WymiaryNormalne[i].setDokladnosc(0);
			
			this->WymiaryNormalne[i++].setKatObrotuWymiaru(0);
		}
		else{
			cout << endl << polilinia.getSrodekLuku(j - 1).getX() << "		##		" << polilinia.getSrodekLuku(j - 1).getY() << endl;
		/*	p1 = polilinia.getVertex(j);
			p2 = polilinia.getVertex(j + 1);
			srodekLuku = polilinia.getSrodekLuku(j);
			
			linia.setPunktPoczatkowy(p1);
			linia.setPunktKoncowy(p2);
			
			this->WymiarPromienia[k].setPunktStartowy(p1);
			this->WymiarPromienia[k].setPunktKoncowy(p2);
			
			//wyznacza odsuniêcie linii wymiarowej
			linia = linia.przesunRownolegle(2);
			
			p1.setX((linia.getPunktPoczatkowy().getX() + linia.getPunktKoncowy().getX()) / 2);
			p1.setY((linia.getPunktPoczatkowy().getY() + linia.getPunktKoncowy().getY()) / 2);
			
			this->WymiarPromienia[k].setPunktLokalizacjiLiniiWymiarowej(p1);
			
			//wyznacza odsuniêcie tekstu wymiarowego		
			linia = linia.przesunRownolegle(0);
			
			p1.setX((linia.getPunktPoczatkowy().getX() + linia.getPunktKoncowy().getX()) / 2);
			p1.setY((linia.getPunktPoczatkowy().getY() + linia.getPunktKoncowy().getY()) / 2);
			
			this->WymiarPromienia[k].setPunktLokalizacjiTekstuWymiaru(p1);
			this->WymiarPromienia[k].setAligned(1);
			this->WymiarPromienia[k].setStyl("OPIS_ZBROJ");
			this->WymiarPromienia[k].setDokladnosc(0);
			
			this->WymiarPromienia[k++].setKatObrotuWymiaru(0);*/
			
		}
		
	}
	
}

void PretyWyrzucone::generujPretyWyrzucone(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunku, koszZbrojeniowy kosz){
	
	int i = 0, j = 0;
	float xp, yp;
	Punkt punkt;
	Linia linia;
	
	//Prêt nr 4 - strzemiê du¿e
	xp = this->getPunktPoczatkowy().getX() + kosz.StrzemionaDuze.GeometriaPreta2DProsta.SzerokoscPolilinii() / 2;
	yp = this->getPunktPoczatkowy().getY();
	
	punkt.setX(xp);
	punkt.setY(yp);
	
	linia = linia.stworzLinieZeWspolrzednych(
		xp + 25,
		(yp + yp - kosz.StrzemionaDuze.GeometriaPreta2DProsta.WysokoscPolilinii()) / 2,
		xp + 25,
		(yp + yp - kosz.StrzemionaDuze.GeometriaPreta2DProsta.WysokoscPolilinii()) / 2
	);
	
	this->GeometriaPretyWyrzucone[i].setWspolrzedneVertex(kosz.StrzemionaDuze.GeometriaPreta2DProsta.przesunPolilinie(punkt));
	this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaDuze.GeometriaPreta2DProsta.getLiczbaVertex());
	this->GeometriaPretyWyrzucone[i].setNazwaWarstwy(zbrojenie);
	
	this->OpisPretyWyrzucone[i].generujOpisDoPreta(kosz.StrzemionaDuze, linia);
	this->OpisPretyWyrzucone[i].setSkala(0.5);
	this->OpisPretyWyrzucone[i].setPokazDlugosc(1);
	
	this->obmiarujPolilinie(this->GeometriaPretyWyrzucone[i++].getWspolrzedneVertex());
	
	//Prêty nr 5 - strzemiona ma³e
	j = 0;
	int OdchylenieStrzemiona = 15;
	int OdchylenieZaczepuStrzemiona = 45;
	int DlugoscZaczepuStrzemiona = 10;
	Punkt Vertex;
	Polilinia polilinia;
	
	xp = this->getPunktPoczatkowy().getX();
	yp = yp - kosz.StrzemionaDuze.GeometriaPreta2DProsta.WysokoscPolilinii() - 50;
	
	if(kosz.StrzemionaMale[0].getNrPorzadkowy() != "brak"){
		
		punkt.setX(xp);
		punkt.setY(yp);
		
		this->GeometriaPretyWyrzucone[i].setWspolrzedneVertex(kosz.StrzemionaMale[0].GeometriaPreta2DProsta.przesunPolilinie(punkt));
		this->GeometriaPretyWyrzucone[i].wspolrzedneVertex.setLiczbaVertex(kosz.StrzemionaMale[0].GeometriaPreta2DProsta.getLiczbaVertex());
		this->GeometriaPretyWyrzucone[i].setNazwaWarstwy(zbrojenie);
		
		//generuje opis do strzemiona
		linia = linia.stworzLinieZeWspolrzednych(
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getX(),
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getY() - 20,
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getX(),
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getY() - 20
		);
		
		this->OpisPretyWyrzucone[i].generujOpisDoPreta(kosz.StrzemionaMale[0], linia);
		this->OpisPretyWyrzucone[i].setSkala(0.5);
		this->OpisPretyWyrzucone[i].setPokazDlugosc(1);
		
		this->obmiarujPolilinie(this->GeometriaPretyWyrzucone[i++].getWspolrzedneVertex());
		
		yp = yp - kosz.StrzemionaMale[0].GeometriaPreta2D.WysokoscPolilinii() - 80;
		polilinia = Polilinia();		//czyœci klase;
		j = 0;
		
	}
	
	if(kosz.StrzemionaMale[1].getNrPorzadkowy() != "brak"){
		
		punkt.setX(xp);
		punkt.setY(yp);
		
		this->GeometriaPretyWyrzucone[i].setWspolrzedneVertex(kosz.StrzemionaMale[1].GeometriaPreta2DProsta.przesunPolilinie(punkt));
		this->GeometriaPretyWyrzucone[i].wspolrzedneVertex.setLiczbaVertex(kosz.StrzemionaMale[1].GeometriaPreta2DProsta.getLiczbaVertex());
		this->GeometriaPretyWyrzucone[i].setNazwaWarstwy(zbrojenie);
		
		//generuje opis do strzemiona
		linia = linia.stworzLinieZeWspolrzednych(
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getX(),
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getY() - 20,
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getX(),
			this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().getVertex(2).getY() - 20
		);
		
		this->OpisPretyWyrzucone[i].generujOpisDoPreta(kosz.StrzemionaMale[1], linia);
		this->OpisPretyWyrzucone[i].setSkala(0.5);
		this->OpisPretyWyrzucone[i].setPokazDlugosc(1);
		
		this->obmiarujPolilinie(this->GeometriaPretyWyrzucone[i++].getWspolrzedneVertex());
		
		yp = yp - kosz.StrzemionaMale[1].GeometriaPreta2D.WysokoscPolilinii();
		j = 0;
		
	}
	
	//Prêt nr 7 - trapez
	polilinia = kosz.PretyNr7.GeometriaPreta2DProsta.obrocPolilinie(90);
	
	xp = this->getPunktPoczatkowy().getX() + 120;
	yp = this->getPunktPoczatkowy().getY() - kosz.StrzemionaDuze.GeometriaPreta2D.WysokoscPolilinii() - 50 - polilinia.WysokoscPolilinii();
	
	punkt.setX(xp);
	punkt.setY(yp);
	
	linia = linia.stworzLinieZeWspolrzednych(
		xp + polilinia.SzerokoscPolilinii() / 2 + 25,
		yp - 35,
		xp + polilinia.SzerokoscPolilinii() / 2 + 25,
		yp - 35
	);
	
	this->GeometriaPretyWyrzucone[i].setWspolrzedneVertex(polilinia.przesunPolilinie(punkt));
	this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().setLiczbaVertex(kosz.StrzemionaDuze.GeometriaPreta2DProsta.getLiczbaVertex());
	this->GeometriaPretyWyrzucone[i].setNazwaWarstwy(zbrojenie);
	
	this->OpisPretyWyrzucone[i].generujOpisDoPreta(kosz.PretyNr7, linia);
	this->OpisPretyWyrzucone[i].setSkala(0.5);
	this->OpisPretyWyrzucone[i].setPokazDlugosc(1);
	
	this->obmiarujPolilinie(this->GeometriaPretyWyrzucone[i++].getWspolrzedneVertex());
	
	//szuka w tablicy pierwszego wolnego miejsca na wymiar
	for(j = 0; this->WymiaryNormalne[j].getKatObrotuWymiaru() != -360; j++) ;
	
	//rysuje dodatkowe wymiary dla prêta nr 7
	this->WymiaryNormalne[j].generujPojedynczyWymiarNormalny(
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(1).getX(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(1).getY(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(2).getX(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(2).getY(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(0).getX() - 20,
		UstawieniaRysunku.getIleTekstWymiaruNadLinia(),
		90,
		0.5
	);
	this->WymiaryNormalne[j].setDokladnosc(0);
	this->WymiaryNormalne[j++].setTekstZamiastWymiaru("<>*");
	
	this->WymiaryNormalne[j].generujPojedynczyWymiarNormalny(
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(1).getX(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(1).getY(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(2).getX(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(2).getY(),
		this->GeometriaPretyWyrzucone[i - 1].getWspolrzedneVertex().getVertex(0).getY() - 20,
		UstawieniaRysunku.getIleTekstWymiaruNadLinia(),
		0,
		0.5
	);
	this->WymiaryNormalne[j].setDokladnosc(0);
	this->WymiaryNormalne[j++].setTekstZamiastWymiaru("<>*");
	
	//Prêt nr 6 - X
	polilinia = kosz.PretyNr6.GeometriaPreta2DProsta.odbicieLustrzanePoliliniiOsY(kosz.PretyNr6.GeometriaPreta2DProsta.SzerokoscPolilinii() / 2).obrocPolilinie(0);
	
	xp = this->getPunktPoczatkowy().getX();
	yp = yp - 55;
	
	punkt.setX(xp);
	punkt.setY(yp);
	
	linia = linia.stworzLinieZeWspolrzednych(
		xp + 40,
		yp - polilinia.WysokoscPolilinii() * 0.7,
		xp + 40,
		yp - polilinia.WysokoscPolilinii() * 0.7
	);
	
	this->GeometriaPretyWyrzucone[i].setWspolrzedneVertex(polilinia.przesunPolilinie(punkt));
	this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().setLiczbaVertex(kosz.PretyNr6.GeometriaPreta2DProsta.getLiczbaVertex());
	this->GeometriaPretyWyrzucone[i].setNazwaWarstwy(zbrojenie);
	
	this->OpisPretyWyrzucone[i].generujOpisDoPreta(kosz.PretyNr6, linia);
	this->OpisPretyWyrzucone[i].setSkala(0.5);
	this->OpisPretyWyrzucone[i].setPokazDlugosc(1);
	
	this->obmiarujPolilinie(this->GeometriaPretyWyrzucone[i++].getWspolrzedneVertex());
	
	//Prêt nr 8 - Uszy
	xp = this->getPunktPoczatkowy().getX();
	yp = yp - polilinia.WysokoscPolilinii() - 20;
	
	polilinia = kosz.Uszy.GeometriaPreta2D.obrocPolilinie(-32);
	
	punkt.setX(xp);
	punkt.setY(yp);
	
	linia = linia.stworzLinieZeWspolrzednych(
		xp + polilinia.SzerokoscPolilinii() / 2,
		yp - polilinia.WysokoscPolilinii() / 2,
		xp + polilinia.SzerokoscPolilinii() / 2,
		yp - polilinia.WysokoscPolilinii() / 2
	);
	
	this->GeometriaPretyWyrzucone[i].setWspolrzedneVertex(polilinia.przesunPolilinie(punkt));
	this->GeometriaPretyWyrzucone[i].getWspolrzedneVertex().setLiczbaVertex(kosz.Uszy.GeometriaPreta2DProsta.getLiczbaVertex());
	this->GeometriaPretyWyrzucone[i].setNazwaWarstwy(zbrojenie);
	
	this->OpisPretyWyrzucone[i].generujOpisDoPreta(kosz.Uszy, linia, 0, 0, 0);
	this->OpisPretyWyrzucone[i].setSkala(0.5);
	this->OpisPretyWyrzucone[i].setPokazDlugosc(1);
	
	this->obmiarujPolilinie(this->GeometriaPretyWyrzucone[i++].getWspolrzedneVertex());
	
}

/* ########################################### RYSUNEK KOSZ ZBROJENIOWY ########################################### */
/* ############################################# SETTERS AND GETTERS ############################################# */

bool RysunekKoszZbrojeniowy::setPunktPoczatkowy(Punkt PunktPoczatkowy){
	this->punktPoczatkowy = PunktPoczatkowy;
	
	return 1;
}
Punkt RysunekKoszZbrojeniowy::getPunktPoczatkowy(){
	return this->punktPoczatkowy;
}

bool RysunekKoszZbrojeniowy::setRzednePrzekrojuBB(float rzednePrzekrojuBB, int i){
	this->RzednePrzekrojuBB[i] = rzednePrzekrojuBB;
	
	this->IleRzednychPrzekrojuBB = this->IleRzednychPrzekrojuBB + 1;
	
	return 1;
}
float RysunekKoszZbrojeniowy::getRzednePrzekrojuBB(int i){
	return this->RzednePrzekrojuBB[i];	
}

bool RysunekKoszZbrojeniowy::setIleRzednychPrzekrojuBB(int x){
	this->IleRzednychPrzekrojuBB = x;
	
	return 1;
}
int RysunekKoszZbrojeniowy::getIleRzednychPrzekrojuBB(){
	return this->IleRzednychPrzekrojuBB;	
}

/* ############################################# POZOSTA£E FUNKCJE ############################################# */

void RysunekKoszZbrojeniowy::generujObrys(UstawieniaRysunekKoszZbrojeniowy UstawieniaRysunek, koszZbrojeniowy kosz, Punkt punktPoczatkowy, LiniaDXF GenerowanyObrys[], float WysokoscObrysu, float SzerokoscObrysu, bool CzySprawdzacPrzerwanieObrysu){
		
	int i=0;
	Linia linia;
	
	float PPx, PPy, PKx, PKy;
	
	//Sprawdza czy kosz jest du¿o krótszy od spodu œciany i rysuje ewentualnie przerwan¹ œcianê	albo jeœli nie ma uwzglêdniaæ przerwania to wchodzi do tego warunku
	if(!CzyObrysPrzerwany(this->UstawieniaRysunku, kosz) || !CzySprawdzacPrzerwanieObrysu){
	
		//odczyt z klasy danych
		PPx = punktPoczatkowy.getX();
		PPy = punktPoczatkowy.getY();
		PKx = punktPoczatkowy.getX() + SzerokoscObrysu;
		PKy = punktPoczatkowy.getY() - WysokoscObrysu;
		
		
		//linie pionowe
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PPy, PPx, PKy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
	
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PKx, PPy, PKx, PKy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
		
		//linie poziome		
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PPy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
		
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PKy, PKx, PKy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
		
	}
	else{
		
		PPx = punktPoczatkowy.getX();
		PPy = punktPoczatkowy.getY();
		PKx = punktPoczatkowy.getX() + SzerokoscObrysu;
		PKy = punktPoczatkowy.getY() - (kosz.getRzednaWierzchuSciany() - kosz.getRzednaWierzchuZbrojenia()) - kosz.WysokoscKosza() - UstawieniaRysunek.getIlePonizejZbrojeniaPrzerwanie();
		
		//linie pionowe g³ówne
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PPy, PPx, PKy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
	
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PKx, PPy, PKx, PKy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
		
		//Rysuje skrajne poziome linie, jeœli kosz przerwany
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PPy, PKx, PPy));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
		
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PKy - UstawieniaRysunek.getIlePrzerwyObrysu() - UstawieniaRysunek.getIleDolnejCzesciObrysu(), PKx, PKy - UstawieniaRysunek.getIlePrzerwyObrysu() - UstawieniaRysunek.getIleDolnejCzesciObrysu()));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);	
		
		//Rysuje dodatkowe pionowe linie, jeœli kosz przerwany	
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx, PKy - UstawieniaRysunek.getIlePrzerwyObrysu(), PPx, PKy - UstawieniaRysunek.getIlePrzerwyObrysu() - UstawieniaRysunek.getIleDolnejCzesciObrysu()));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
	
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PKx, PKy - UstawieniaRysunek.getIlePrzerwyObrysu(), PKx, PKy - UstawieniaRysunek.getIlePrzerwyObrysu() - UstawieniaRysunek.getIleDolnejCzesciObrysu()));
		GenerowanyObrys[i++].setNazwaWarstwy(widok);
		
		//linie poœrednie poziome linie, jeœli kosz przerywane
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx - UstawieniaRysunek.getJakDuzoWystajePrzerywanaOdObrysu(), PKy, PKx + UstawieniaRysunek.getJakDuzoWystajePrzerywanaOdObrysu(), PKy));
		GenerowanyObrys[i++].setNazwaWarstwy(przerywana);
		
		GenerowanyObrys[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx - UstawieniaRysunek.getJakDuzoWystajePrzerywanaOdObrysu(), PKy - UstawieniaRysunek.getIlePrzerwyObrysu(), PKx + UstawieniaRysunek.getJakDuzoWystajePrzerywanaOdObrysu(), PKy - UstawieniaRysunek.getIlePrzerwyObrysu()));
		GenerowanyObrys[i++].setNazwaWarstwy(przerywana);

	}	
	
}

void RysunekKoszZbrojeniowy::dobierzRzednePrzekrojuBB(koszZbrojeniowy kosz){
	
	//sprawdza czy u¿ytkownik poda³ rzêdne przekroju B-B, jak nie to generuje sam
	if(this->getIleRzednychPrzekrojuBB() == 0){
		
		int j = 0;
		Linia linia;
		float PPy, PKy;
		float yp, yk;	
		
		PPy = kosz.getRzednaWierzchuZbrojenia() - 100;
		PKy = kosz.getRzednaSpoduZbrojenia();
		
		float maxYgrunt = PPy;
		float maxYwykop = PPy;
		float minYgrunt = PKy;
		float minYwykop = PKy;
		
		if(kosz.DozbrojeniaOdStronyGruntuI[0].getNrPorzadkowy() != "brak"){
		
			maxYgrunt = min(maxYgrunt, kosz.DozbrojeniaOdStronyGruntuI[0].getRzednaWierzchu());
			minYgrunt = max(minYgrunt, kosz.DozbrojeniaOdStronyGruntuI[0].getRzednaSpodu());
			
		}
			
		if(kosz.DozbrojeniaOdStronyGruntuII[0].getNrPorzadkowy() != "brak"){
			
			maxYgrunt = min(maxYgrunt, kosz.DozbrojeniaOdStronyGruntuII[0].getRzednaWierzchu());
			minYgrunt = max(minYgrunt, kosz.DozbrojeniaOdStronyGruntuII[0].getRzednaSpodu());
			
		}
		
		if(kosz.DozbrojeniaOdStronyWykopuI[0].getNrPorzadkowy() != "brak"){
			
			maxYwykop = min(maxYwykop, kosz.DozbrojeniaOdStronyWykopuI[0].getRzednaWierzchu());
			minYwykop = max(minYwykop, kosz.DozbrojeniaOdStronyWykopuI[0].getRzednaSpodu());
			
		}
			
		if(kosz.DozbrojeniaOdStronyWykopuII[0].getNrPorzadkowy() != "brak"){
			
			maxYwykop = min(maxYwykop, kosz.DozbrojeniaOdStronyWykopuII[0].getRzednaWierzchu());
			minYwykop = max(minYwykop, kosz.DozbrojeniaOdStronyWykopuII[0].getRzednaSpodu());
			
		}

		//sprawdza czy zakresy prêtów siê pokrywaj¹ i wystarczy jeden przekrój
		if(maxYgrunt > minYwykop && minYgrunt < maxYwykop){
			
			this->setRzednePrzekrojuBB(min(maxYgrunt, maxYwykop), 0);
			
			this->setIleRzednychPrzekrojuBB(1);
			
		}
		else{
			
			this->setRzednePrzekrojuBB(maxYgrunt, 0);	
			this->setRzednePrzekrojuBB(maxYwykop, 1);
			
			this->setIleRzednychPrzekrojuBB(2);
		}
		
	}
	
}

void RysunekKoszZbrojeniowy::generujZnacznikPrzekroju(koszZbrojeniowy kosz, ZnacznikPrzekroju ZnacznikPrzekroju[], LiniaDXF Obrys[]){
	
	int i = 0, j = 0, m = 0, k = 0;
	Linia linia;
	float PPx, PPy;
	float yp, yk;
	float rzednaOpisu;
	Punkt punkt;
	stringstream TrescLinii;
	
	int NrLinii = 0;
	char LiterkaPorzadkowa = 66;

	for(k = 0; k < this->getIleRzednychPrzekrojuBB(); k++){
		
		i = 0;
		
		PPx = Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getX();
		rzednaOpisu = Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getY() + (this->getRzednePrzekrojuBB(k) - kosz.getRzednaWierzchuSciany());
		
		//wyœrodkowuje znacznik pomiêdzy strzemionami
		j = 0;
		while(this->Widok.Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY() > rzednaOpisu){
			j++;
		}
		
		yp = this->Widok.Strzemiona[j].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		yk = this->Widok.Strzemiona[j + 1].getWspolrzedneLinii().getPunktPoczatkowy().getY();
		rzednaOpisu = (yp + yk) / 2;
		
		ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx - 120, rzednaOpisu, PPx - 160, rzednaOpisu));
		ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
		
		ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx - 145, rzednaOpisu - 8, PPx - 160, rzednaOpisu));
		ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
		
		//generuje literkê przekroju
		for(m = 0; this->TekstyOpisowe[m].getIleLinii() > 0; m++) ; 	//szuka ostatniej wolnej pozycji w TekstyOpisowe
		TrescLinii.str("");
		
		punkt.setX(PPx - 125);
		punkt.setY(rzednaOpisu + 10);
		this->TekstyOpisowe[m].setPunktPoczatkowy(punkt);
		this->TekstyOpisowe[m].setWysokoscTekstu(10);
		
		NrLinii = 0;
		LiterkaPorzadkowa = 66 + k;
		
		TrescLinii << LiterkaPorzadkowa;
		this->TekstyOpisowe[m].LinieTekstu[NrLinii++] = TrescLinii.str();
		TrescLinii.str("");
		
		this->TekstyOpisowe[m++].setIleLinii(NrLinii);
		
		
		PPx = Obrys[1].getWspolrzedneLinii().getPunktPoczatkowy().getX();
		
		ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx + 160, rzednaOpisu, PPx + 200, rzednaOpisu));
		ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
		
		ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
			linia.stworzLinieZeWspolrzednych(PPx + 185, rzednaOpisu - 8, PPx + 200, rzednaOpisu));
		ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
		
		//generuje literkê przekroju
		TrescLinii.str("");
		
		punkt.setX(PPx + 165);
		punkt.setY(rzednaOpisu + 10);
		this->TekstyOpisowe[m].setPunktPoczatkowy(punkt);
		this->TekstyOpisowe[m].setWysokoscTekstu(10);
		
		NrLinii = 0;
		
		TrescLinii << LiterkaPorzadkowa;
		this->TekstyOpisowe[m].LinieTekstu[NrLinii++] = TrescLinii.str();
		TrescLinii.str("");
		
		this->TekstyOpisowe[m].setIleLinii(NrLinii);
	
	}
	
	i = 0;
	
	PPx = (Obrys[0].getWspolrzedneLinii().getPunktPoczatkowy().getX() + Obrys[1].getWspolrzedneLinii().getPunktKoncowy().getX()) / 2;
	PPy = this->Widok.PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	
	ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy + 40, PPx, PPy + 80));
	ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
	
	ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx - 8, PPy + 65, PPx, PPy + 80));
	ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
	
	//generuje literkê przekroju
	for(m = 0; this->TekstyOpisowe[m].getIleLinii() > 0; m++) ; 	//szuka ostatniej wolnej pozycji w TekstyOpisowe
	TrescLinii.str("");
	
	punkt.setX(PPx + 10);
	punkt.setY(PPy + 45);
	this->TekstyOpisowe[m].setPunktPoczatkowy(punkt);
	this->TekstyOpisowe[m].setWysokoscTekstu(10);
	
	NrLinii = 0;
	
	TrescLinii << "A";
	this->TekstyOpisowe[m].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	this->TekstyOpisowe[m++].setIleLinii(NrLinii);
	
	
	PPy = Obrys[3].getWspolrzedneLinii().getPunktPoczatkowy().getY();
	
	ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx, PPy - 140, PPx, PPy - 180));
	ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
	
	ZnacznikPrzekroju[k].Linie[i].setWspolrzedneLinii(
		linia.stworzLinieZeWspolrzednych(PPx - 8, PPy - 165, PPx, PPy - 180));
	ZnacznikPrzekroju[k].Linie[i++].setNazwaWarstwy(opisy);
	
	//generuje literkê przekroju
	TrescLinii.str("");
	
	punkt.setX(PPx + 10);
	punkt.setY(PPy - 145);
	this->TekstyOpisowe[m].setPunktPoczatkowy(punkt);
	this->TekstyOpisowe[m].setWysokoscTekstu(10);
	
	NrLinii = 0;
	
	TrescLinii << "A";
	this->TekstyOpisowe[m].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	this->TekstyOpisowe[m].setIleLinii(NrLinii);
	
}

void RysunekKoszZbrojeniowy::generujPretyGiete(Punkt punktPoczatkowy, Polilinia DanyPret, float OdstepMiedzyPretami, int ilePretow, PoliliniaDXF GenerowanePretyGiete[], Warstwa typWarstwy){
	
	Punkt punktPomocniczy;
	Polilinia poliliniaPomocnicza;
	
	punktPomocniczy.setX(punktPoczatkowy.getX());
	punktPomocniczy.setY(punktPoczatkowy.getY());
	
	int ilePretowJuzIstnieje = 0;
	
	//sprawdza czy w danej tabilicy s¹ ju¿ polilinie, ¿eby ich nie nadpisaæ
	while(GenerowanePretyGiete[ilePretowJuzIstnieje].getNazwaWarstwy() != brak)
			ilePretowJuzIstnieje++;

	//generuje nowe polilinie uwzglêdniaj¹c przesuniêcie w tabeli o polilinie ju¿ istniej¹ce, jeœli takowe s¹
	for(int i = ilePretowJuzIstnieje; i < ilePretow + ilePretowJuzIstnieje; i++){
		
		poliliniaPomocnicza = DanyPret.przesunPolilinie(punktPomocniczy);
			
		GenerowanePretyGiete[i].setWspolrzedneVertex(poliliniaPomocnicza);
			
		GenerowanePretyGiete[i].getWspolrzedneVertex().setLiczbaVertex(poliliniaPomocnicza.getLiczbaVertex());
		GenerowanePretyGiete[i].setNazwaWarstwy(typWarstwy);
			
		punktPomocniczy.setY(punktPomocniczy.getY() - OdstepMiedzyPretami);
		
	}
}

KotaWysokosciowa RysunekKoszZbrojeniowy::generujPojedynczaKotaWysokosciowa(koszZbrojeniowy kosz, int poczatkowyX, float poziomZero, float rysowanaRzedna, string opis1, string opis2, string opis3){
	
	KotaWysokosciowa KotaWysokosciowa;
	Punkt punkt;
	float obliczonePolozenieRzednej; 
	int przesuniecieRzednej = 0;
	
	if(rysowanaRzedna < (kosz.getRzednaSpoduZbrojenia() - this->UstawieniaRysunku.getIlePonizejZbrojeniaPrzerwanie())) 
		przesuniecieRzednej = CzyObrysPrzerwany(this->UstawieniaRysunku, kosz);
		
	obliczonePolozenieRzednej = poziomZero + rysowanaRzedna - przesuniecieRzednej;
	
	punkt.setX(poczatkowyX);
	punkt.setY(obliczonePolozenieRzednej);
	
	KotaWysokosciowa.setPunktPoczatkowy(punkt);
	
	KotaWysokosciowa.setRzedna(rysowanaRzedna / 100);
	
	KotaWysokosciowa.setOpis(opis1, opis2, opis3);
	
	return KotaWysokosciowa;
	
}

void RysunekKoszZbrojeniowy::generujKotyWysokosciowe(koszZbrojeniowy kosz, int poczatkowyX, KotaWysokosciowa KotaWysokosciowa[]){
	
	int i = 0;
	float poziomZero = this->getPunktPoczatkowy().getY() - kosz.getRzednaWierzchuSciany();
	
	float rysowanaRzedna = 0;


	//oblicza parametry koty wysokoœciowej rzêdnej wierzchu œciany
	rysowanaRzedna = kosz.getRzednaWierzchuSciany();
	KotaWysokosciowa[i++] = generujPojedynczaKotaWysokosciowa(kosz, poczatkowyX, poziomZero, rysowanaRzedna, "wierzch œciany", "szczelinowej");

	//oblicza parametry koty wysokoœciowej rzêdnej wierzchu zbrojenia
	rysowanaRzedna = kosz.getRzednaWierzchuZbrojenia();
	KotaWysokosciowa[i++] = generujPojedynczaKotaWysokosciowa(kosz, poczatkowyX, poziomZero, rysowanaRzedna, "wierzch zbrojenia", "œciany szczelinowej");
	
	//oblicza parametry koty wysokoœciowej rzêdnej wierzchu murków prowadz¹cych
	rysowanaRzedna = kosz.getPoziomMurkowProwadzacych();
	KotaWysokosciowa[i++] = generujPojedynczaKotaWysokosciowa(kosz, poczatkowyX + this->UstawieniaRysunku.getOdstepDodatkowyKotyMurkowProwadzacych(), poziomZero, rysowanaRzedna, "poziom murków", "prowadz¹cych");
	
	//oblicza parametry koty wysokoœciowej rzêdnej wierzchu spodu zbrojenia
	rysowanaRzedna = kosz.getRzednaSpoduZbrojenia();
	KotaWysokosciowa[i++] = generujPojedynczaKotaWysokosciowa(kosz, poczatkowyX, poziomZero, rysowanaRzedna, "spód zbrojenia", "œciany szczelinowej");
	
	//oblicza parametry koty wysokoœciowej rzêdnej wierzchu spodu œciany
	rysowanaRzedna = kosz.getRzednaSpoduSciany();	
	KotaWysokosciowa[i++] = generujPojedynczaKotaWysokosciowa(kosz, poczatkowyX + this->UstawieniaRysunku.getOdstepDodatkowyKotyMurkowProwadzacych(), poziomZero, rysowanaRzedna, "spód œciany", "szczelinowej");
	
}

void RysunekKoszZbrojeniowy::generujPrzekrojBB(Punkt punktPoczatkowy, koszZbrojeniowy kosz, float RzednaPrzekroju, int i){
	
	//generowanie przekroju B-B kosza
	this->PrzekrojBB[i].setPunktPoczatkowy(punktPoczatkowy);

	this->generujObrys(
		this->UstawieniaRysunku,
		kosz, 
		this->PrzekrojBB[i].getPunktPoczatkowy(), 
		this->PrzekrojBB[i].Obrys, 
		kosz.getSzerokoscSciany(),
		kosz.getSzerokoscKosza(),
		0);
	
	this->PrzekrojBB[i].generujPretyGlowne(kosz);
	this->PrzekrojBB[i].generujStrzemionaDuze(kosz);
	this->PrzekrojBB[i].generujStrzemionaMale(kosz);
	this->PrzekrojBB[i].generujPretyDozbrojenia(kosz, RzednaPrzekroju);

	//generuje opisy
	this->PrzekrojBB[i].generujOpisyPretyGlowne(this->UstawieniaRysunku, kosz, RzednaPrzekroju);
	this->PrzekrojBB[i].generujOpisyStrzemionMalych(this->UstawieniaRysunku, kosz);
	this->PrzekrojBB[i].generujWymiaryNormalne(this->UstawieniaRysunku, kosz);
	
	//generuje nag³ówek przekroju
	for(i = 0; this->TekstyOpisowe[i].getIleLinii() > 0; i++) ; 	//szuka ostatniej wolnej pozycji w TekstyOpisowe
	
	Punkt punkt;
	stringstream TrescLinii;
	TrescLinii.str("");
	
	punkt.setX(punktPoczatkowy.getX() + kosz.getSzerokoscKosza() / 2 + this->UstawieniaRysunku.getOdstepNapisuPrzekrojBB().getX());
	punkt.setY(this->PrzekrojBB[i].OpisPretyGlowne[0].getPunktPoczatkowy().getY() + this->UstawieniaRysunku.getOdstepNapisuPrzekrojBB().getY());
	this->TekstyOpisowe[i].setPunktPoczatkowy(punkt);
	this->TekstyOpisowe[i].setWysokoscTekstu(7.5);
	
	int NrLinii = 0;
	char LiterkaPorzadkowa = 66 + i;
	
	TrescLinii << "PRZEKRÓJ " << LiterkaPorzadkowa << "-" << LiterkaPorzadkowa;
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	TrescLinii << "skala 1:25";
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	this->TekstyOpisowe[i].setIleLinii(NrLinii);
	
}

void RysunekKoszZbrojeniowy::generujRysunekKoszaZbrojeniowego(koszZbrojeniowy kosz, DaneWejscioweKosz Dane){	
	
	//obliczanie punktów pocz¹tkowych poszczególnych elementów rysunku
	Punkt punktPoczatkowyPrzekrojAA;
	punktPoczatkowyPrzekrojAA.setX(this->punktPoczatkowy.getX() + this->UstawieniaRysunku.getOdstepWidokPrzekrojAA());
	punktPoczatkowyPrzekrojAA.setY(this->punktPoczatkowy.getY());
	
	Punkt punktPoczatkowyPrzekrojBB;
	punktPoczatkowyPrzekrojBB.setX(punktPoczatkowyPrzekrojAA.getX() + this->UstawieniaRysunku.getOdstepPrzekrojAAPrzekrojBB());
	punktPoczatkowyPrzekrojBB.setY(punktPoczatkowyPrzekrojAA.getY() - this->UstawieniaRysunku.getOdstepPrzekrojBBOdGory());
	
	Punkt punktPoczatkowySchematRozmieszczeniaPretowGlownych;
	punktPoczatkowySchematRozmieszczeniaPretowGlownych.setX(this->punktPoczatkowy.getX() + UstawieniaRysunku.getOdstepWidokSchematRozmieszczeniaPretowGlownych());
	punktPoczatkowySchematRozmieszczeniaPretowGlownych.setY(this->punktPoczatkowy.getY());

	
	//#################################################################### WIDOK
	this->Widok.setPunktPoczatkowy(this->punktPoczatkowy);
	
	this->Widok.generujPoziomMurkowProwadzacych(kosz, punktPoczatkowyPrzekrojAA);
	
	this->generujObrys(
		this->UstawieniaRysunku,
		kosz, 
		this->Widok.getPunktPoczatkowy(), 
		this->Widok.Obrys, 
		kosz.WysokoscSciany(),
		kosz.getSzerokoscKosza());
	
	this->Widok.generujPretyGlowne(kosz);
	this->Widok.generujStrzemiona(kosz);
	
	
	//generuje prêty nr 6
	this->generujPretyGiete(
		this->Widok.punktPoczatkowyPretowNr6(kosz), 
		kosz.PretyNr6.GeometriaPreta2D.odbicieLustrzanePoliliniiOsY(
			kosz.PretyNr6.GeometriaPreta2D.getVertex(0).getX() + kosz.PretyNr6.GeometriaPreta2D.SzerokoscPolilinii() / 2), 
		kosz.PretyNr6.getOdstepMiedzyPretami(), 
		kosz.PretyNr6.getSztuki() / 2, 
		this->Widok.PretyNr6, 
		zbrojenie);
		
	this->generujPretyGiete(
		this->Widok.punktPoczatkowyPretowNr6(kosz),
		kosz.PretyNr6.GeometriaPreta2D,
		kosz.PretyNr6.getOdstepMiedzyPretami(),
		kosz.PretyNr6.getSztuki() / 2,
		this->Widok.PretyNr6,
		przerywana);

	
	//generuje uszy	
	this->generujPretyGiete(
		this->Widok.punktPoczatkowyUszy(kosz),
		kosz.Uszy.GeometriaPreta2D,
		0,
		1,
		this->Widok.Uszy,
		zbrojenie);
	
	Punkt punktPomocniczy;
	punktPomocniczy.setX(this->Widok.punktPoczatkowyUszy(kosz).getX() + kosz.PretyGlowne[0][0].getOdstepMiedzyPretami() * (kosz.PretyGlowne[0][0].getSztuki() - 4));
	punktPomocniczy.setY(this->Widok.punktPoczatkowyUszy(kosz).getY());	
	
	this->generujPretyGiete(
		punktPomocniczy,
		kosz.Uszy.GeometriaPreta2D,
		0,
		1,
		this->Widok.Uszy,
		zbrojenie);
	
	//generuje opisy
	this->Widok.generujOpisyPretow(this->UstawieniaRysunku, kosz);
	this->Widok.generujOpisyPretowNr6(this->UstawieniaRysunku, kosz);
	this->Widok.generujOpisyDoUszu(this->UstawieniaRysunku, kosz);
	this->generujKotyWysokosciowe(kosz, this->Widok.getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() + this->UstawieniaRysunku.getOdstepBocznyKotWysokosciowych(), this->Widok.KotyWysokosciowe);
	this->Widok.generujWymiaryNormalne(this->UstawieniaRysunku, kosz);
	
	//#################################################################### PRZEKRÓJ A-A	
	
	//generowanie przekroju A-A kosza
	this->PrzekrojAA.setPunktPoczatkowy(punktPoczatkowyPrzekrojAA);
	
	this->generujObrys(
		this->UstawieniaRysunku,
		kosz,
		this->PrzekrojAA.getPunktPoczatkowy(),
		this->PrzekrojAA.Obrys,
		kosz.WysokoscSciany(),
		kosz.getSzerokoscSciany());
	
	this->PrzekrojAA.generujPretyGlowne(kosz);
	this->PrzekrojAA.generujStrzemiona(kosz);
	
	this->generujPretyGiete(
		this->PrzekrojAA.punktPoczatkowyPretowNr7(kosz),
		kosz.PretyNr7.GeometriaPreta2D,
		kosz.PretyNr7.getOdstepMiedzyPretami(),
		kosz.PretyNr7.getSztuki() / kosz.getIleStrzemionWPrzekroju(),
		this->PrzekrojAA.PretyNr7, zbrojenie);
		
	this->PrzekrojAA.generujPretyNr9(kosz);
	
	//generuje opisy
	this->PrzekrojAA.generujOpisyPretow(this->UstawieniaRysunku, kosz);
	this->PrzekrojAA.generujOpisyPretowNr7(this->UstawieniaRysunku, kosz);
	this->PrzekrojAA.generujOpisyDoPretowNr9(this->UstawieniaRysunku, kosz);
	this->generujKotyWysokosciowe(kosz, this->PrzekrojAA.getPunktPoczatkowy().getX() + kosz.getSzerokoscSciany() + this->UstawieniaRysunku.getOdstepBocznyKotWysokosciowych(), this->PrzekrojAA.KotyWysokosciowe);
	this->PrzekrojAA.generujWymiaryNormalne(this->UstawieniaRysunku, kosz);
	
	//#################################################################### PRZEKRÓJ B-B	
	
	int k = 0;
	for(k = 0; k < Dane.getIleRzednychPrzekrojuBB(); k++)
		this->setRzednePrzekrojuBB(Dane.getRzednePrzekrojuBB(k) * 100, k);	
	this->setIleRzednychPrzekrojuBB(k);
	
	this->dobierzRzednePrzekrojuBB(kosz);
	
	//generowanie przekroju B-B kosza
	
	punktPomocniczy.setX(punktPoczatkowyPrzekrojBB.getX());
	punktPomocniczy.setY(punktPoczatkowyPrzekrojBB.getY());

	for(int i = 0; i < this->getIleRzednychPrzekrojuBB(); i++){

		punktPomocniczy.setY(punktPoczatkowyPrzekrojBB.getY() - i * (kosz.getSzerokoscSciany() + 200));
		this->generujPrzekrojBB(punktPomocniczy, kosz, this->getRzednePrzekrojuBB(i), i);	
		
	}
	
	this->generujZnacznikPrzekroju(kosz, this->Widok.ZnacznikPrzekroju, this->Widok.Obrys);
	
	//#################################################################### SCHEMAT ROZMIESZCZENIA PRÊTÓW G£ÓWNYCH	
	this->SchematRozmieszczeniaPretowGlownych.setPunktPoczatkowy(punktPoczatkowySchematRozmieszczeniaPretowGlownych);
	this->SchematRozmieszczeniaPretowGlownych.generujPretyGlowne(this->UstawieniaRysunku, kosz, this->Widok.PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy(), this->Widok.PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy());	

	//#################################################################### PRÊTY WYRZUCONE
	Punkt punktPoczatkowyPretyWyrzucone;
	punktPoczatkowyPretyWyrzucone.setX(punktPomocniczy.getX());
	punktPoczatkowyPretyWyrzucone.setY(punktPomocniczy.getY() - kosz.getSzerokoscSciany() * 1.75 - UstawieniaRysunku.getOdstepPrzekrojBBPretyWyrzucone());
	
	this->PretyWyrzucone.setPunktPoczatkowy(punktPoczatkowyPretyWyrzucone);
	this->PretyWyrzucone.generujPretyWyrzucone(this->UstawieniaRysunku, kosz);
	
	//#################################################################### TEKSTY OPISOWE
	int i = 0, NrLinii = 0;
	Punkt punkt;
	stringstream TrescLinii;
	
	for(i = 0; this->TekstyOpisowe[i].getIleLinii() > 0; i++) ; 	//szuka ostatniej wolnej pozycji w TekstyOpisowe
	
	//Nazwa przekroju obliczeniowego jako nazwa pliku txt z danymi wejœciowymi	
	
	//Kosz zbrojeniowy AXXX nr X, X, X
	punkt.setX(punktPoczatkowyPrzekrojBB.getX() + kosz.getSzerokoscKosza() / 2 + this->UstawieniaRysunku.getOdstepTytuluKoszy().getX());
	punkt.setY(punktPoczatkowyPrzekrojBB.getY() + this->UstawieniaRysunku.getOdstepTytuluKoszy().getY());
	this->TekstyOpisowe[i].setPunktPoczatkowy(punkt);
	
	TrescLinii << "Kosz zbrojeniowy A" << to_string(kosz.getSzerokoscKosza()) << " nr X, X, X";
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	TrescLinii << "X szt.";
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	this->TekstyOpisowe[i++].setIleLinii(NrLinii);
	
	//WIDOK
	punkt.setX(this->getPunktPoczatkowy().getX() + kosz.getSzerokoscKosza() / 2 + this->UstawieniaRysunku.getOdstepNapisuWidok().getX());
	punkt.setY(this->Widok.PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY() + this->UstawieniaRysunku.getOdstepNapisuWidok().getY());
	this->TekstyOpisowe[i].setPunktPoczatkowy(punkt);
	
	TrescLinii << "WIDOK";
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	this->TekstyOpisowe[i++].setIleLinii(NrLinii);
	
	//PRZEKRÓJ A-A
	punkt.setX(punktPoczatkowyPrzekrojAA.getX() + kosz.getSzerokoscSciany() / 2 + this->UstawieniaRysunku.getOdstepNapisuPrzekrojAA().getX());
	punkt.setY(this->PrzekrojAA.PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY() + this->UstawieniaRysunku.getOdstepNapisuPrzekrojAA().getY());
	this->TekstyOpisowe[i].setPunktPoczatkowy(punkt);
	
	TrescLinii << "PRZEKRÓJ A-A";
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	TrescLinii << "skala 1:50";
	this->TekstyOpisowe[i].LinieTekstu[NrLinii++] = TrescLinii.str();
	TrescLinii.str("");
	
	this->TekstyOpisowe[i++].setIleLinii(NrLinii);
	
}

void RysunekKoszZbrojeniowy::rysujKosz(CreateDxf Draw){
	
	Draw.rysujLinie(this->Widok.poziomMurkowProwadzacych);
	rysujWszystkieTekstyOpisowe(Draw, this->TekstyOpisowe, opisy);

	 
	//#################################################################### SCHEMAT ROZMIESZCZENIA PRÊTÓW G£ÓWNYCH	
	Draw.rysujLinie(this->SchematRozmieszczeniaPretowGlownych.PretyGlowne);
	Draw.rysujLinie(this->SchematRozmieszczeniaPretowGlownych.SymbolWykopGrunt.Linie);
	Draw.rysujCircles(this->SchematRozmieszczeniaPretowGlownych.SymbolWykopGrunt.Circle);
	Draw.hatchujCircle(this->SchematRozmieszczeniaPretowGlownych.SymbolWykopGrunt.Circle, opisy, "SOLID");
	rysujWszystkieTekstyOpisowe(Draw, this->SchematRozmieszczeniaPretowGlownych.SymbolWykopGrunt.Tekst, opisy);
	rysujWszystkieOpisyPretBezLinii(Draw, this->SchematRozmieszczeniaPretowGlownych.OpisPretyGlowne, opisy);
	rysujWszystkieWymiaryNormalne(Draw, this->SchematRozmieszczeniaPretowGlownych.WymiaryNormalne, wymiary);

	//#################################################################### WIDOK
	Draw.rysujLinie(this->Widok.Obrys);
	Draw.rysujLinie(this->Widok.PretyGlowne);
	Draw.rysujLinie(this->Widok.Strzemiona);
	Draw.rysujPolilinie(this->Widok.PretyNr6);
	Draw.rysujPolilinie(this->Widok.Uszy);
	
	for(int i = 0; this->Widok.ZnacznikPrzekroju[i].Linie[0].getNazwaWarstwy() != brak; i++)
		Draw.rysujLinie(this->Widok.ZnacznikPrzekroju[i].Linie);
	
	rysujWszystkieOpisyPretZLiniaPoziomo(Draw, this->Widok.OpisPretyGlowne, opisy);
	rysujWszystkieOpisyPretZLiniaBezposrednio(Draw, this->Widok.OpisPretyNr6, opisy);
	rysujWszystkieOpisyPretZLiniaBezposrednio(Draw, this->Widok.OpisUszy, opisy, 0);
	rysujWszystkieKoty(Draw, this->Widok.KotyWysokosciowe, koty_wysokosciowe);
	rysujWszystkieWymiaryNormalne(Draw, this->Widok.WymiaryNormalne, wymiary);

	//#################################################################### PRZEKRÓJ A-A		
	Draw.rysujLinie(this->PrzekrojAA.Obrys);
	Draw.rysujLinie(this->PrzekrojAA.PretyGlowne);
	Draw.rysujLinie(this->PrzekrojAA.StrzemionaDuze);
	Draw.rysujCircles(this->PrzekrojAA.StrzemionaMale);
	Draw.hatchujCircle(this->PrzekrojAA.StrzemionaMale, zbrojenie, "SOLID");
	Draw.rysujPolilinie(this->PrzekrojAA.PretyNr7);
	Draw.rysujPolilinie(this->PrzekrojAA.PretyNr9);
	Draw.rysujLinie(this->PrzekrojAA.SymbolWykopGrunt.Linie);
	Draw.rysujCircles(this->PrzekrojAA.SymbolWykopGrunt.Circle);
	Draw.hatchujCircle(this->PrzekrojAA.SymbolWykopGrunt.Circle, opisy, "SOLID");
	rysujWszystkieTekstyOpisowe(Draw, this->PrzekrojAA.SymbolWykopGrunt.Tekst, opisy);
	rysujWszystkieOpisyPretZLiniaPoziomo(Draw, this->PrzekrojAA.OpisPretyGlowne[0], opisy);
	rysujWszystkieOpisyPretZLiniaPoziomo(Draw, this->PrzekrojAA.OpisPretyGlowne[1], opisy, 0);
	rysujWszystkieOpisyPretZLiniaBezposrednio(Draw, this->PrzekrojAA.OpisPretyNr7, opisy);
	rysujWszystkieOpisyPretZLiniaBezposrednio(Draw, this->PrzekrojAA.OpisPretyNr9, opisy, 0);
	rysujWszystkieKoty(Draw, this->PrzekrojAA.KotyWysokosciowe, koty_wysokosciowe);
	rysujWszystkieWymiaryNormalne(Draw, this->PrzekrojAA.WymiaryNormalne, wymiary);
	
	//#################################################################### PRZEKRÓJ B-B		
	for(int i = 0; i < this->getIleRzednychPrzekrojuBB(); i++){
		
		Draw.rysujLinie(this->PrzekrojBB[i].Obrys);
		Draw.rysujCircles(this->PrzekrojBB[i].PretyGlowne[0]);
		Draw.hatchujCircle(this->PrzekrojBB[i].PretyGlowne[0], zbrojenie, "SOLID");
		Draw.rysujCircles(this->PrzekrojBB[i].PretyGlowne[1]);
		Draw.hatchujCircle(this->PrzekrojBB[i].PretyGlowne[1], zbrojenie, "SOLID");
		Draw.rysujCircles(this->PrzekrojBB[i].DozbrojeniaOdStronyGruntuI);
		Draw.hatchujCircle(this->PrzekrojBB[i].DozbrojeniaOdStronyGruntuI, zbrojenie, "SOLID");
		Draw.rysujCircles(this->PrzekrojBB[i].DozbrojeniaOdStronyGruntuII);
		Draw.hatchujCircle(this->PrzekrojBB[i].DozbrojeniaOdStronyGruntuII, zbrojenie, "SOLID");
		Draw.rysujPolilinie(this->PrzekrojBB[i].StrzemionaDuze);		
		Draw.rysujCircles(this->PrzekrojBB[i].DozbrojeniaOdStronyWykopuI);
		Draw.hatchujCircle(this->PrzekrojBB[i].DozbrojeniaOdStronyWykopuI, zbrojenie, "SOLID");
		Draw.rysujCircles(this->PrzekrojBB[i].DozbrojeniaOdStronyWykopuII);
		Draw.hatchujCircle(this->PrzekrojBB[i].DozbrojeniaOdStronyWykopuII, zbrojenie, "SOLID");	
		Draw.rysujPolilinie(this->PrzekrojBB[i].StrzemionaDuze);	
		Draw.rysujPolilinie(this->PrzekrojBB[i].StrzemionaMale[0]);
		Draw.rysujPolilinie(this->PrzekrojBB[i].StrzemionaMale[1]);
		
		Draw.rysujLinie(this->PrzekrojBB[i].SymbolWykopGrunt.Linie);
		Draw.rysujCircles(this->PrzekrojBB[i].SymbolWykopGrunt.Circle);
		Draw.hatchujCircle(this->PrzekrojBB[i].SymbolWykopGrunt.Circle, opisy, "SOLID");
		rysujWszystkieTekstyOpisowe(Draw, this->PrzekrojBB[i].SymbolWykopGrunt.Tekst, opisy);
	
		rysujWszystkieOpisyPretZLiniaRownolegle(Draw, this->PrzekrojBB[i].OpisPretyGlowne, opisy);
		rysujWszystkieOpisyPretZLiniaPoziomo(Draw, this->PrzekrojBB[i].OpisStrzemionaMale, opisy, 0);
		rysujWszystkieWymiaryNormalne(Draw, this->PrzekrojBB[i].WymiaryNormalne, wymiary);
		
	}
		
	//#################################################################### PRÊTY WYRZUCONE		
	Draw.rysujPolilinie(this->PretyWyrzucone.GeometriaPretyWyrzucone);
	rysujWszystkieOpisyPretZLiniaPoziomo(Draw, this->PretyWyrzucone.OpisPretyWyrzucone, opisy, 0);
	rysujWszystkieWymiaryNormalne(Draw, this->PretyWyrzucone.WymiaryNormalne, wymiary);
	rysujWszystkieWymiaryPromienia(Draw, this->PretyWyrzucone.WymiarPromienia, wymiary);
	
}
