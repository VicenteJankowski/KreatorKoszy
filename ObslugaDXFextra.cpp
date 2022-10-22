#include "ObslugaDXFextra.hpp"
#include "RysunekKoszZbrojeniowy.hpp"

void rysujWszystkieTekstyOpisowe(CreateDxf Draw, TekstyOpisowe TekstOpisowy[], Warstwa typWarstwy, int Limit){
	
	int i = 0;
	
	while(TekstOpisowy[i].getIleLinii() > 0 && i < Limit){
		Draw.MTekst(TekstOpisowy[i].getPunktPoczatkowy().getX(), TekstOpisowy[i].getPunktPoczatkowy().getY(), TekstOpisowy[i].LinieTekstu, TekstOpisowy[i].getIleLinii(), opisy, TekstOpisowy[i].getWysokoscTekstu());
		i++;		
	}
	
	if(i >= Limit)
		throw "Wygenerowano wiêcej tekstów opisowych niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieKoty(CreateDxf Draw, KotaWysokosciowa KotyWysokosciowe[], Warstwa typWarstwy, int LimitKot){
	
	int i = 0;
	
	while(KotyWysokosciowe[i].getOpis(0) != "brak" && i < LimitKot){
		Draw.KotaWysokosciowa(KotyWysokosciowe[i].getPunktPoczatkowy(), KotyWysokosciowe[i].getRzedna(), KotyWysokosciowe[i].getOpis(0), KotyWysokosciowe[i].getOpis(1), KotyWysokosciowe[i].getOpis(2), typWarstwy);
		i++;		
	}
	
	if(i >= LimitKot)
		throw "Wygenerowano wiêcej kotew niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieWymiaryNormalne(CreateDxf Draw, WymiarNormalny WymiaryNormalne[], Warstwa typWarstwy, int LimitWymiarow){
	
	int i = 0;
	
	while(WymiaryNormalne[i].getKatObrotuWymiaru() != -360 && i < LimitWymiarow){
		
		Draw.rysujWymiarNormalny(
			WymiaryNormalne[i],
			typWarstwy); 
		i++;		
	}
	
	if(i >= LimitWymiarow)
		throw "Wygenerowano wiêcej wymiarów niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieWymiaryPromienia(CreateDxf Draw, WymiarPromienia WymiaryPromienia[], Warstwa typWarstwy, int LimitWymiarow){
	
	int i = 0;
	
	while(WymiaryPromienia[i].getKatObrotuWymiaru() != -360 && i < LimitWymiarow){
		
		Draw.rysujWymiarPromienia(
			WymiaryPromienia[i],
			typWarstwy); 
		i++;		
	}
	
	if(i >= LimitWymiarow)
		throw "Wygenerowano wiêcej wymiarów niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieOpisyPretBezLinii(CreateDxf Draw, OpisPret Opisy[], Warstwa typWarstwy, int LimitOpisow){
	
	int i = 0;
	
	while(Opisy[i].getNrPorzadkowyPreta() != "brak" && i < LimitOpisow){
		
		Draw.OpisPojedynczyPretyBezLinii(
			Opisy[i],
			typWarstwy);
		i++;		
	}
	
	if(i >= LimitOpisow)
		throw "Wygenerowano wiêcej opisów pretów bez linii niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieOpisyPretZLiniaPoziomo(CreateDxf Draw, OpisPret Opisy[], Warstwa typWarstwy, bool CzyPrawyOpis, bool CzyStrzalkiDoGory, int LimitOpisow){
	
	int i = 0;
	
	while(Opisy[i].getNrPorzadkowyPreta() != "brak" && i < LimitOpisow){
		
		Draw.OpisPojedynczyPretyZLiniaPoziomo(
			Opisy[i],
			typWarstwy,
			CzyPrawyOpis,
			CzyStrzalkiDoGory);
			
		i++;		
	}		
	
	if(i >= LimitOpisow)
		throw "Wygenerowano wiêcej opisów pretów bez linii niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieOpisyPretZLiniaBezposrednio(CreateDxf Draw, OpisPret Opisy[], Warstwa typWarstwy, bool CzyPrawyOpis, int LimitOpisow){
	
	int i = 0;
	
	while(Opisy[i].getNrPorzadkowyPreta() != "brak" && i < LimitOpisow){
		
		Draw.OpisPojedynczyPretyZLiniamiBezposrednio(
			Opisy[i],
			typWarstwy,
			CzyPrawyOpis);
			
		i++;		
	}		
	
	if(i >= LimitOpisow)
		throw "Wygenerowano wiêcej opisów pretów bez linii niz dopuszcza pamiêæ programu.";
	
}

void rysujWszystkieOpisyPretZLiniaRownolegle(CreateDxf Draw, OpisPret Opisy[], Warstwa typWarstwy, bool CzyPrawyOpis, int LimitOpisow){
	
	int i = 0;
	
	while(Opisy[i].getNrPorzadkowyPreta() != "brak" && i < LimitOpisow){
		
		Draw.OpisPojedynczyPretyZLiniamiRownolegle(
			Opisy[i],
			typWarstwy,
			CzyPrawyOpis);
			
		i++;		
	}		
	
	if(i >= LimitOpisow)
		throw "Wygenerowano wiêcej opisów pretów bez linii niz dopuszcza pamiêæ programu.";
	
}
