#include "ObslugaDXF.hpp"

using namespace std;

int hexHandle = 22303369;				// hex "BBBC09" -> ten numer w hex musi byæ podany w pliku konfiguracyjnym w HEADERS w wartoœci $HANDSEED i kolejne handle musz¹ byæ generowane jako wartoœci mniejsze od tego
string NazwaPlikuWynikowego = "GotoweKosze";
string NazwaFolderuWynikowego = "WygenerowanyRysunek";


bool LiniaDXF::setWspolrzedneLinii(Linia wspolrzedneLinii){
	this->wspolrzedneLinii = wspolrzedneLinii;
	
	return 1;
}
Linia LiniaDXF::getWspolrzedneLinii(){
	return this->wspolrzedneLinii;
}
		
bool LiniaDXF::setNazwaWarstwy(Warstwa nazwaWarstwy){
	this->nazwaWarstwy = nazwaWarstwy;
	
	return 1;
}
Warstwa LiniaDXF::getNazwaWarstwy(){
	return this->nazwaWarstwy;
}

bool PoliliniaDXF::setWspolrzedneVertex(Polilinia wspolrzedneVertex){
	this->wspolrzedneVertex = wspolrzedneVertex;
	
	return 1;
}
Polilinia PoliliniaDXF::getWspolrzedneVertex(){
	return this->wspolrzedneVertex;
}

bool PoliliniaDXF::setNazwaWarstwy(Warstwa nazwaWarstwy){
	this->nazwaWarstwy = nazwaWarstwy;
	
	return 1;
}
Warstwa PoliliniaDXF::getNazwaWarstwy(){
	return this->nazwaWarstwy;
}

bool CircleDXF::setDaneKola(Circle DaneKola){
	this->DaneKola = DaneKola;
	
	return 1;
}
Circle CircleDXF::getDaneKola(){
	return this->DaneKola;
}
		
bool CircleDXF::setNazwaWarstwy(Warstwa nazwaWarstwy){
	this->nazwaWarstwy = nazwaWarstwy;
	
	return 1;
}
Warstwa CircleDXF::getNazwaWarstwy(){
	return this->nazwaWarstwy;
}

CreateDxf::CreateDxf(fstream &Zapis)
	: ZapisDoPliku(Zapis)
{
   cout <<".";
	
}
CreateDxf::~CreateDxf()
{
   cout <<".";
	
}

void  CreateDxf::DxfBegin()
{
		
	// Header section of every dxf file. 
	ifstream NaglowkiDXFrodzajeLinii;
	NaglowkiDXFrodzajeLinii.exceptions(ifstream::failbit | ifstream::badbit);
	
	try{
		
		NaglowkiDXFrodzajeLinii.open("PlikiKonfiguracyjne/NaglowkiDXFrodzajeLinii.config", ios::in);
		
		//kopiuje nag³ówki DXF z pliku zewnêtrznego wsadowego
		do{
			string trescPliku;
			getline(NaglowkiDXFrodzajeLinii, trescPliku);
			this->ZapisDoPliku << trescPliku << endl;
		}
		while(!NaglowkiDXFrodzajeLinii.eof());	
		
		NaglowkiDXFrodzajeLinii.close();
	}
	catch(ifstream::failure e){
		
		throw "Nie uda³o siê odnaleŸæ lub otworzyæ pliku konfiguracyjnego Nag³ówkiDXFrodzajeLinii.config. Wgraj plik konfiguracyjny i ponownie uruchom program.";
		
	}
	
	//kopiuje bloki DXF z pliku zewnêtrznego wsadowego
	ifstream definicjeBlokowDXF;
	definicjeBlokowDXF.exceptions(ifstream::failbit | ifstream::badbit);
	
	try{
		
		definicjeBlokowDXF.open("PlikiKonfiguracyjne/definicjeBlokowDXF.config", ios::in);
		
		//kopiuje nag³ówki DXF z pliku zewnêtrznego wsadowego
		do{
			string trescPliku;
			getline(definicjeBlokowDXF, trescPliku);
			this->ZapisDoPliku << trescPliku << endl;
		}
		while(!definicjeBlokowDXF.eof());	
		
		definicjeBlokowDXF.close();
	}
	catch(ifstream::failure e){
		
		throw "Nie uda³o siê odnaleŸæ lub otworzyæ pliku konfiguracyjnego definicjeBlokowDXF.config. Wgraj plik konfiguracyjny i ponownie uruchom program.";
		
	}

	this->ZapisDoPliku << 0		  << endl;
	this->ZapisDoPliku << "SECTION"  << endl;
	this->ZapisDoPliku << 2		  << endl;
	this->ZapisDoPliku << "ENTITIES" << endl;

	
}
void  CreateDxf::DxfEnd ()
{
	
	this->ZapisDoPliku << 0		 	 << endl;
	this->ZapisDoPliku << "ENDSEC"   << endl;
	
	//bardzo wa¿ny fragment dla wersji DXF R14 - bez tego AutoCAD nie odpali
	this->ZapisDoPliku << 0		  				 << endl;
	this->ZapisDoPliku << "SECTION"   			 << endl;
	this->ZapisDoPliku << 2		  				 << endl;
	this->ZapisDoPliku << "OBJECTS"   			 << endl;
	this->ZapisDoPliku << 0		  				 << endl;
	this->ZapisDoPliku << "DICTIONARY"   		 << endl;
	this->ZapisDoPliku << 5		  				 << endl;
	this->ZapisDoPliku << "C"   				 << endl;
	this->ZapisDoPliku << 100		         	 << endl;
	this->ZapisDoPliku << "AcDbDictionary"   	 << endl;
	this->ZapisDoPliku << 281		  	     	 << endl;
	this->ZapisDoPliku << 1				     	 << endl;
	this->ZapisDoPliku << 3		  	  	   	 	 << endl;
	this->ZapisDoPliku << "ACAD_GROUP"	     	 << endl;
	this->ZapisDoPliku << 350		  	  	   	 << endl;
	this->ZapisDoPliku << "D" 	 				 << endl;
	this->ZapisDoPliku << 0		  				 << endl;
	this->ZapisDoPliku << "DICTIONARY"   		 << endl;
	this->ZapisDoPliku << 5		  				 << endl;
	this->ZapisDoPliku << "D"  					 << endl;
	this->ZapisDoPliku << 100		         	 << endl;
	this->ZapisDoPliku << "AcDbDictionary"   	 << endl;
	this->ZapisDoPliku << 281		  	     	 << endl;
	this->ZapisDoPliku << 1				     	 << endl;
	
	this->ZapisDoPliku << 0		 	 << endl;
	this->ZapisDoPliku << "ENDSEC"   << endl;
	
	this->ZapisDoPliku << 0		  << endl;
	this->ZapisDoPliku << "EOF";

}

string CreateDxf::getHexHandle(){
	
	char hexHandlePrzypisany[1000];
	hexHandle++;
	itoa(hexHandle, hexHandlePrzypisany, 16);
	
	string s(hexHandlePrzypisany);
	
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	
	//cout << s << endl;
	
	return s;
}

void CreateDxf::Circle (float x, float y, float radius, Warstwa typWarstwy)
{
	
	// Propeties of a circle not bound in any AutoCAd version
	//In AutoCAD 2000 we can have more less 4000 lines of code here. 

	// Draw the circle
	this->ZapisDoPliku << 0		 						  << endl;
	this->ZapisDoPliku << "CIRCLE"					      << endl;
	this->ZapisDoPliku << 5		 						  << endl;
	this->ZapisDoPliku << this->getHexHandle()		 	  << endl;
	this->ZapisDoPliku << 100		 					  << endl;
	this->ZapisDoPliku << "AcDbEntity"				      << endl;
	this->ZapisDoPliku << 8		 		   				  << endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		  << endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					  << endl;
	this->ZapisDoPliku << "AcDbCircle"				      << endl;
	this->ZapisDoPliku << 10						  	  << endl;	// XYZ is the Center point of circle
	this->ZapisDoPliku << x				 				  << endl;	// X in UCS (User Coordinate System)coordinates
	this->ZapisDoPliku << 20			 << endl;
	this->ZapisDoPliku << y				 << endl;	// Y in UCS (User Coordinate System)coordinates
	this->ZapisDoPliku << 30		     << endl;
	this->ZapisDoPliku << 0.0			 << endl;	// Z in UCS (User Coordinate System)coordinates
	this->ZapisDoPliku << 40		 	 << endl;	
	this->ZapisDoPliku << radius	  	 << endl;	// radius of circle

}

void CreateDxf::Line (Linia linia, Warstwa typWarstwy)
{

	// Rysuje liniê
	this->ZapisDoPliku << 0		  					<< endl;
	this->ZapisDoPliku << "LINE"   					<< endl;
	this->ZapisDoPliku << 5		 				    << endl;
	this->ZapisDoPliku << this->getHexHandle()	    << endl;
	this->ZapisDoPliku << 100		 				<< endl;
	this->ZapisDoPliku << "AcDbEntity"	 		    << endl;
	this->ZapisDoPliku << 8		  					<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)	<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 				<< endl;
	this->ZapisDoPliku << "AcDbLine"	    	    << endl;
	this->ZapisDoPliku << 10		 				<< endl;	// XYZ is the Center point of circle
	this->ZapisDoPliku << linia.getPunktPoczatkowy().getX()				<< endl;	// X in UCS (User Coordinate System)coordinates
	this->ZapisDoPliku << 20		 	<< endl;
	this->ZapisDoPliku << linia.getPunktPoczatkowy().getY()		 	<< endl;	// Y in UCS (User Coordinate System)coordinates
	this->ZapisDoPliku << 30		 	<< endl;
	this->ZapisDoPliku << 0.0		 	<< endl;	// Z in UCS (User Coordinate System)coordinates
	this->ZapisDoPliku << 11		 	<< endl;
	this->ZapisDoPliku << linia.getPunktKoncowy().getX()	     	<< endl;
	this->ZapisDoPliku << 21		 	<< endl;
	this->ZapisDoPliku << linia.getPunktKoncowy().getY()		 	<< endl;
	this->ZapisDoPliku << 31		 	<< endl;
	this->ZapisDoPliku << 0.0		 	<< endl;	

}

void CreateDxf::PolyLine (Polilinia polilinia, Warstwa typWarstwy, bool CzyZamknieta)
{

	// Rysuje poliliniê
	// Nag³ówek polilinii
	this->ZapisDoPliku << 0		  					<< endl;
	this->ZapisDoPliku << "LWPOLYLINE"   			<< endl;
	this->ZapisDoPliku << 5		 				    << endl;
	this->ZapisDoPliku << this->getHexHandle()	    << endl;
	this->ZapisDoPliku << 100		 				<< endl;
	this->ZapisDoPliku << "AcDbEntity"	 		    << endl;
	this->ZapisDoPliku << 8		  					<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)	<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 				<< endl;
	this->ZapisDoPliku << "AcDbPolyline"	    	<< endl;
	this->ZapisDoPliku << 90		 				<< endl;
	this->ZapisDoPliku << polilinia.getLiczbaVertex()   	<< endl;
	this->ZapisDoPliku << 70		 				<< endl;
	this->ZapisDoPliku << CzyZamknieta		    	<< endl;
	this->ZapisDoPliku << 43		 				<< endl;
	this->ZapisDoPliku << 0					    	<< endl;
	
	// Rysuje kolejne Vertexy
	for(int i=0; i < polilinia.getLiczbaVertex(); i++){
		
		//cout << polilinia.getVertex(i).getX() << "	|	" << polilinia.getVertex(i).getY() << endl;
		
	  //this->ZapisDoPliku << 0				 									<< endl;
	  //this->ZapisDoPliku << "VERTEX"		 									<< endl;
	  //this->ZapisDoPliku << 100		 										<< endl;
	  //this->ZapisDoPliku << "AcDb3dPolylineVertex"   							<< endl;
		this->ZapisDoPliku << 10		 										<< endl;	
		this->ZapisDoPliku << polilinia.getVertex(i).getX() 					<< endl;	// X in UCS (User Coordinate System)coordinates
		this->ZapisDoPliku << 20		 										<< endl;
		this->ZapisDoPliku << polilinia.getVertex(i).getY() 					<< endl;	// Y in UCS (User Coordinate System)coordinates
		this->ZapisDoPliku << 42												<< endl;
		this->ZapisDoPliku << polilinia.getVertex(i).getTanZaokraglenia()		<< endl;

	}
	
	// Zamkniêcie polilinii
	//this->ZapisDoPliku << 0		  			<< endl;
	//this->ZapisDoPliku << "SEQEND"   		<< endl;

}

void CreateDxf::hatchujCircle(CircleDXF Circle[], Warstwa typWarstwy, string rodzajKreskowania, int LimitCircles){

	// Rysuje hatcha
	// Nag³ówek polilinii
	
	int i = 0;
	
	while(Circle[i].getNazwaWarstwy() != brak && i < LimitCircles){
		this->ZapisDoPliku << 0		  			<< endl;
		this->ZapisDoPliku << "HATCH"   		<< endl;
		this->ZapisDoPliku << 5		 				    << endl;
		this->ZapisDoPliku << this->getHexHandle()	    << endl;
		this->ZapisDoPliku << 100		 		<< endl;
		this->ZapisDoPliku << "AcDbEntity"	    << endl;
		this->ZapisDoPliku << 8		  			<< endl;	
		this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
		
		this->ZapisDoPliku << 100		   	    << endl;
		this->ZapisDoPliku << "AcDbHatch"	    << endl;
		this->ZapisDoPliku << 10 				<< endl;
		this->ZapisDoPliku << 0.0				<< endl;
		this->ZapisDoPliku << 20 				<< endl;
		this->ZapisDoPliku << 0.0				<< endl;
		this->ZapisDoPliku << 30 				<< endl;
		this->ZapisDoPliku << 0.0				<< endl;
		this->ZapisDoPliku << 210 				<< endl;
		this->ZapisDoPliku << 0.0				<< endl;
		this->ZapisDoPliku << 220 				<< endl;
		this->ZapisDoPliku << 0.0				<< endl;
		this->ZapisDoPliku << 230 				<< endl;
		this->ZapisDoPliku << 1.0				<< endl;
		 
		this->ZapisDoPliku << 2					<< endl;
		this->ZapisDoPliku << "SOLID"			<< endl;
		
		this->ZapisDoPliku << 70				<< endl;
		this->ZapisDoPliku << 1 				<< endl;
		this->ZapisDoPliku << 71				<< endl;
		this->ZapisDoPliku << 1 				<< endl;
		this->ZapisDoPliku << 91 				<< endl;
		this->ZapisDoPliku << 1					<< endl;
		
		this->ZapisDoPliku << 92 				<< endl;
		this->ZapisDoPliku << 3					<< endl;
		this->ZapisDoPliku << 72 				<< endl;
		this->ZapisDoPliku << 1					<< endl;
		this->ZapisDoPliku << 73 				<< endl;
		this->ZapisDoPliku << 1					<< endl;  
		
		this->ZapisDoPliku << 93 				<< endl;
		this->ZapisDoPliku << 2					<< endl;	 
		 
		this->ZapisDoPliku << 10 				<< endl;	//wspó³rzêdne punktów pocz¹tkowych i koñcowych œrednicy poziomej
		this->ZapisDoPliku << Circle[i].getDaneKola().getSrodek().getX() + Circle[i].getDaneKola().getPromien()		<< endl;
		this->ZapisDoPliku << 20 				<< endl;
		this->ZapisDoPliku << Circle[i].getDaneKola().getSrodek().getY() 			<< endl;
		this->ZapisDoPliku << 42 				<< endl;
		this->ZapisDoPliku << 1.0				<< endl; 
		this->ZapisDoPliku << 10 				<< endl;
		this->ZapisDoPliku << Circle[i].getDaneKola().getSrodek().getX() - Circle[i].getDaneKola().getPromien()		<< endl;
		this->ZapisDoPliku << 20 				<< endl;
		this->ZapisDoPliku << Circle[i].getDaneKola().getSrodek().getY()			<< endl;
		this->ZapisDoPliku << 42 				<< endl;
		this->ZapisDoPliku << 1.0				<< endl;
		
		this->ZapisDoPliku << 97 				<< endl;
		this->ZapisDoPliku << 1					<< endl;
		this->ZapisDoPliku << 330 				<< endl;
		this->ZapisDoPliku << 0					<< endl;
		
		this->ZapisDoPliku << 75 				<< endl;
		this->ZapisDoPliku << 0					<< endl;
		this->ZapisDoPliku << 76 				<< endl;
		this->ZapisDoPliku << 1					<< endl;
	
		//te zmienne potrzebne jak chcemy dac hatch pattern
		//this->ZapisDoPliku << 41 				<< endl;
		//this->ZapisDoPliku << 1.0				<< endl;
		//this->ZapisDoPliku << 78 				<< endl;
		//this->ZapisDoPliku << 1					<< endl;
		//this->ZapisDoPliku << 53 				<< endl;
		//this->ZapisDoPliku << 45.0				<< endl;
		//this->ZapisDoPliku << 43 				<< endl;
		//this->ZapisDoPliku << 0.0				<< endl;      
		//this->ZapisDoPliku << 44 				<< endl;
		//this->ZapisDoPliku << 0.0				<< endl;
		//this->ZapisDoPliku << 45 				<< endl;
		//this->ZapisDoPliku << -0.0883883476483184	<< endl; 
		//this->ZapisDoPliku << 46 				<< endl;
		//this->ZapisDoPliku << 0.0883883476483184	<< endl; 
		
		//tu trzeba podac punkt wewnatrz obrysu, zeby wygenerowal hatcha
		this->ZapisDoPliku << 98 				<< endl;
		this->ZapisDoPliku << 1					<< endl;
		this->ZapisDoPliku << 10 				<< endl;
		this->ZapisDoPliku << Circle[i].getDaneKola().getSrodek().getX()		<< endl;
		this->ZapisDoPliku << 20 				<< endl;
		this->ZapisDoPliku << Circle[i].getDaneKola().getSrodek().getY()			<< endl;
		
		i++;
	}
	
}

void CreateDxf::MTekst(float x, float y, string LinieTekstu[], int IleLinii, Warstwa typWarstwy, float WysokoscTekstu){

	this->ZapisDoPliku << 0		  			<< endl;
	this->ZapisDoPliku << "MTEXT"   		<< endl;
	this->ZapisDoPliku << 5		 				    << endl;
	this->ZapisDoPliku << this->getHexHandle()	    << endl;
	this->ZapisDoPliku << 100		 		<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    << endl;
	this->ZapisDoPliku << 8		  			<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	
	this->ZapisDoPliku << 100		   	    << endl;
	this->ZapisDoPliku << "AcDbMText"	    << endl;
	this->ZapisDoPliku << 10 				<< endl;
	this->ZapisDoPliku << x					<< endl;
	this->ZapisDoPliku << 20 				<< endl;
	this->ZapisDoPliku << y					<< endl;
	this->ZapisDoPliku << 30 				<< endl;
	this->ZapisDoPliku << 0.0				<< endl;
	this->ZapisDoPliku << 40 				<< endl;
	this->ZapisDoPliku << WysokoscTekstu	<< endl;
	this->ZapisDoPliku << 41 				<< endl;			//dlugosc tego prostok¹ta, w którym edytuje siê tekst i który powoduje, ¿e zawijaj¹ siê wiersze
	this->ZapisDoPliku << 2500				<< endl;
	this->ZapisDoPliku << 71 				<< endl;
	this->ZapisDoPliku << 5					<< endl;
	this->ZapisDoPliku << 72 				<< endl;
	this->ZapisDoPliku << 1					<< endl;
	this->ZapisDoPliku << 1 				<< endl;
	
	for(int i = 0; i < IleLinii; i++){
		
		this->ZapisDoPliku << LinieTekstu[i] << "\\P";	
		
		if(i > 100)
			throw "Za du¿o linii tesktu w MTekst.";
			
	}
		
	this->ZapisDoPliku << endl;
	
}

void CreateDxf::KotaWysokosciowa(Punkt punktPoczatkowy, float rzedna, string opis1, string opis2, string opis3, Warstwa typWarstwy){
	
	ostringstream rzednaTekst;

	if(rzedna < 0){
		
		rzednaTekst << "- ";
		rzedna = -rzedna;
		
	}
	else if(rzedna > 0)
		
		rzednaTekst << "+ ";
	
	else
		
		rzednaTekst << "%%p ";
		
	rzednaTekst << fixed << setprecision(2) << rzedna;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "INSERT"   					<< endl;
	this->ZapisDoPliku << 5		 						  << endl;
	this->ZapisDoPliku << this->getHexHandle()		 	  << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		   	    			<< endl;
	this->ZapisDoPliku << "AcDbBlockReference"	   		<< endl;
	this->ZapisDoPliku << 66		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "KOTA"				   		<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getX()   		<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getY()		<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1.28					   		<< endl;
	this->ZapisDoPliku << 42		   	    			<< endl;
	this->ZapisDoPliku << 1.28					   		<< endl;
	this->ZapisDoPliku << 43		   	    			<< endl;
	this->ZapisDoPliku << 1.28					   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getX() - 9	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getY() + 16	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 12.8					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << rzednaTekst.str()		   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 0.8					   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "RZEDNA"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	   				<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getX() + 26	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getY()		<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 12.8					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << opis1					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 0.8					   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "OPIS1"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getX() + 26	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getY() - 16	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 12.8					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << opis2					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 0.8					   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "OPIS2"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getX() + 26	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getY() - 31	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 12.8					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << opis3					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 0.8					   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "OPIS3"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	// Zamkniêcie bloku
	this->ZapisDoPliku << 0		  			<< endl;
	this->ZapisDoPliku << "SEQEND"   		<< endl;
	this->ZapisDoPliku << 5		  			<< endl;
	this->ZapisDoPliku << this->getHexHandle()   		<< endl;
	this->ZapisDoPliku << 100		  		<< endl;
	this->ZapisDoPliku << "AcDbEntity"   	<< endl;
	
}

void CreateDxf::rysujWymiarNormalny(WymiarNormalny Wymiar, Warstwa typWarstwy){
	
	if(Wymiar.getPunktStartowy().getX() == Wymiar.getPunktKoncowy().getX() && Wymiar.getPunktStartowy().getY() == Wymiar.getPunktKoncowy().getY()){
		cout << endl << "UWAGA! Rysujê zerowy wymiar.";
		cout << "PK: " << Wymiar.getPunktStartowy().getX() << ", " << Wymiar.getPunktStartowy().getY() << " | PS: " << Wymiar.getPunktKoncowy().getX() << ", " << Wymiar.getPunktKoncowy().getY();
	}
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "DIMENSION"  					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)

	//The point (13,23,33) specifies the start point of the first extension line and the point (14,24,34) specifies the start point of the second extension line. 
	//Point (10,20,30) specifies the dimension line location. The point (11,21,31) specifies the midpoint of the dimension text.

	this->ZapisDoPliku << 100		 									<< endl;
	this->ZapisDoPliku << "AcDbDimension"    							<< endl;
	this->ZapisDoPliku << 10		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiLiniiWymiarowej().getX()   		<< endl;
	this->ZapisDoPliku << 20		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiLiniiWymiarowej().getY()		<< endl;
	this->ZapisDoPliku << 30		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;
	this->ZapisDoPliku << 11		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiTekstuWymiaru().getX()			<< endl;
	this->ZapisDoPliku << 21		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiTekstuWymiaru().getY() 			<< endl;
	this->ZapisDoPliku << 31		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;
	this->ZapisDoPliku << 70		   	    							<< endl;	// typ wymiaru, trzeba dodaæ, ¿eby przesuwa³o tekst opisu
	this->ZapisDoPliku << 160 + Wymiar.getAligned()						<< endl;
	
	this->ZapisDoPliku << 1			   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getTekstZamiastWymiaru()				<< endl;
	this->ZapisDoPliku << 3			   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getStyl()		   						<< endl;
	
	this->ZapisDoPliku << 100		 									<< endl;
	this->ZapisDoPliku << "AcDbAlignedDimension"						<< endl;
	this->ZapisDoPliku << 13		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktStartowy().getX()				<< endl;
	this->ZapisDoPliku << 23		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktStartowy().getY()				<< endl;
	this->ZapisDoPliku << 33		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;
	this->ZapisDoPliku << 14		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktKoncowy().getX()				<< endl;
	this->ZapisDoPliku << 24		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktKoncowy().getY()				<< endl;
	this->ZapisDoPliku << 34		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;	
	
	if(Wymiar.getAligned() == 0){
		this->ZapisDoPliku << 50		   	    							<< endl;
		this->ZapisDoPliku << Wymiar.getKatObrotuWymiaru()					<< endl;
		this->ZapisDoPliku << 100		 									<< endl;
		this->ZapisDoPliku << "AcDbRotatedDimension"    					<< endl;
	}
	
	this->ZapisDoPliku << 1001		   	    							<< endl;
	this->ZapisDoPliku << "ACAD"		   	    						<< endl;
	this->ZapisDoPliku << 1000		   	    							<< endl;
	this->ZapisDoPliku << "DSTYLE"		   	    						<< endl;
	this->ZapisDoPliku << 1002		   	    							<< endl;
	this->ZapisDoPliku << "{"		   	    							<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 49		   	    							<< endl;
	this->ZapisDoPliku << 1040		   	    							<< endl;
	this->ZapisDoPliku << 30	   	    								<< endl;	//tutaj siê okreœla sta³¹ d³ugoœæ pomocniczej linii wymiarowej
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 271		   	    							<< endl;	//dokladnosc wymiaru: kod
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getDokladnosc()						<< endl;	//dokladnosc wymiaru: liczba zer po przecinku
/*	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 77	   	    								<< endl;	//tutaj okreœla, ¿e wymiary maj¹ byæ na zewn¹trz, teraz zdefiniowane to jest w stylu w nag³ówkach
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 2		   	    							    << endl;*/
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 279		   	    							<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 0		   	    							    << endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 290		   	    							<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 1		   	    								<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 40	   	    								<< endl;
	this->ZapisDoPliku << 1040		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getSkala()								<< endl;
	this->ZapisDoPliku << 1002		   	    							<< endl;
	this->ZapisDoPliku << "}"		   	    							<< endl;
	
}

void CreateDxf::rysujWymiarPromienia(WymiarNormalny Wymiar, Warstwa typWarstwy){
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "DIMENSION"  					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)

	this->ZapisDoPliku << 100		 									<< endl;
	this->ZapisDoPliku << "AcDbDimension"    							<< endl;
	this->ZapisDoPliku << 10		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiLiniiWymiarowej().getX()   		<< endl;
	this->ZapisDoPliku << 20		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiLiniiWymiarowej().getY()		<< endl;
	this->ZapisDoPliku << 30		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;
	this->ZapisDoPliku << 11		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiTekstuWymiaru().getX()			<< endl;
	this->ZapisDoPliku << 21		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktLokalizacjiTekstuWymiaru().getY() 			<< endl;
	this->ZapisDoPliku << 31		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;
	this->ZapisDoPliku << 70		   	    							<< endl;	// typ wymiaru, trzeba dodaæ, ¿eby przesuwa³o tekst opisu
	this->ZapisDoPliku << 160 + Wymiar.getAligned()						<< endl;
	
	this->ZapisDoPliku << 1			   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getTekstZamiastWymiaru()				<< endl;
	this->ZapisDoPliku << 3			   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getStyl()		   						<< endl;
	
	this->ZapisDoPliku << 100		 									<< endl;
	this->ZapisDoPliku << "AcDbRadialDimension"							<< endl;
	this->ZapisDoPliku << 15		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktStartowy().getX()				<< endl;
	this->ZapisDoPliku << 25		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getPunktStartowy().getY()				<< endl;
	this->ZapisDoPliku << 35		   	    							<< endl;
	this->ZapisDoPliku << 0.0					   						<< endl;

	this->ZapisDoPliku << 1001		   	    							<< endl;
	this->ZapisDoPliku << "ACAD"		   	    						<< endl;
	this->ZapisDoPliku << 1000		   	    							<< endl;
	this->ZapisDoPliku << "DSTYLE"		   	    						<< endl;
	this->ZapisDoPliku << 1002		   	    							<< endl;
	this->ZapisDoPliku << "{"		   	    							<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 49		   	    							<< endl;
	this->ZapisDoPliku << 1040		   	    							<< endl;
	this->ZapisDoPliku << 30	   	    								<< endl;	//tutaj siê okreœla sta³¹ d³ugoœæ pomocniczej linii wymiarowej
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 271		   	    							<< endl;	//dokladnosc wymiaru: kod
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getDokladnosc()						<< endl;	//dokladnosc wymiaru: liczba zer po przecinku
/*	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 77	   	    								<< endl;	//tutaj okreœla, ¿e wymiary maj¹ byæ na zewn¹trz, teraz zdefiniowane to jest w stylu w nag³ówkach
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 2		   	    							    << endl;*/
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 279		   	    							<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 0		   	    							    << endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 290		   	    							<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 1		   	    								<< endl;
	this->ZapisDoPliku << 1070		   	    							<< endl;
	this->ZapisDoPliku << 40	   	    								<< endl;
	this->ZapisDoPliku << 1040		   	    							<< endl;
	this->ZapisDoPliku << Wymiar.getSkala()								<< endl;
	this->ZapisDoPliku << 1002		   	    							<< endl;
	this->ZapisDoPliku << "}"		   	    							<< endl;

}

void CreateDxf::OpisPojedynczyPretyBezLinii(OpisPret Opis, Warstwa typWarstwy){
	
	int zmiennaKalibracjiLokalizacjiNumeruPreta;
	int wielkoscCzcionki = 10;
	
	//dopasowanie numeru prêta, ¿eby zmieœci³ siê w kó³ku
	switch(Opis.getNrPorzadkowyPreta().length()){
		
		case 2:
			zmiennaKalibracjiLokalizacjiNumeruPreta = -5;
			break;
		case 3:
			zmiennaKalibracjiLokalizacjiNumeruPreta = -5;
			wielkoscCzcionki = 7;
			break;
		default:
			zmiennaKalibracjiLokalizacjiNumeruPreta = 0;
			wielkoscCzcionki = 10;
			break;
		
	}
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "INSERT"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		   	    			<< endl;
	this->ZapisDoPliku << "AcDbBlockReference"	   		<< endl;
	this->ZapisDoPliku << 66		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "OPIS_PRET_BEZ_LINII"	   		<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX()   		<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY()		<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 42		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 43		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 90					   		<< endl;	

	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 5 * Opis.getSkala() 	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 22 * Opis.getSkala() + zmiennaKalibracjiLokalizacjiNumeruPreta * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << wielkoscCzcionki * Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getNrPorzadkowyPreta()	<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 90					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "NUMER"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	   				<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 4 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 41 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()			<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getIloscPretow()	   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 90					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "ILOSC"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 4 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 70 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getSrednicaPreta()  		<< endl;
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 90					   		<< endl;			
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "SREDNICA"			   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 4 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 100 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << "L=" << Opis.getDlugoscPreta()	   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 90					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "DLUGOSC"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 4 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 160 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getStal()		   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 90					   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "STAL"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	// Zamkniêcie bloku
	this->ZapisDoPliku << 0		  			<< endl;
	this->ZapisDoPliku << "SEQEND"   		<< endl;
	this->ZapisDoPliku << 5		  			<< endl;
	this->ZapisDoPliku << this->getHexHandle()   		<< endl;
	this->ZapisDoPliku << 100		  		<< endl;
	this->ZapisDoPliku << "AcDbEntity"   	<< endl;	
	
}

void CreateDxf::OpisPojedynczyPretyZLinia(OpisPret Opis, Warstwa typWarstwy){
	
	int zmiennaKalibracjiLokalizacjiNumeruPreta;
	int zmiennaKalibracjiLokalizacjiIlosciPretow = 0;
	int wielkoscCzcionki = 10;
	
	//dopasowanie numeru prêta, ¿eby zmieœci³ siê w kó³ku
	switch(Opis.getNrPorzadkowyPreta().length()){
		case 2:
			zmiennaKalibracjiLokalizacjiNumeruPreta = -4;
			break;
		case 3:
			zmiennaKalibracjiLokalizacjiNumeruPreta = -4;
			wielkoscCzcionki = 7;
			break;
		default:
			zmiennaKalibracjiLokalizacjiNumeruPreta = 0;
			wielkoscCzcionki = 10;
			break;
	}
	
	if(Opis.getIloscPretow() > 9){
		zmiennaKalibracjiLokalizacjiIlosciPretow = -7;
	}
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "INSERT"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		   	    			<< endl;
	this->ZapisDoPliku << "AcDbBlockReference"	   		<< endl;
	this->ZapisDoPliku << 66		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "OPIS_PRAWY"			   		<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX()   		<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY()		<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 42		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 43		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	   				<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 20 * Opis.getSkala() + zmiennaKalibracjiLokalizacjiIlosciPretow * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 2 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getIloscPretow()			   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "ILOSC"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 36 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 2 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getSrednicaPreta()		<< endl;
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;			
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "SREDNICA"			   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	if(Opis.getPokazDlugosc()){
		this->ZapisDoPliku << 0		  						<< endl;
		this->ZapisDoPliku << "ATTRIB"   					<< endl;
		this->ZapisDoPliku << 5		 				   	    << endl;
		this->ZapisDoPliku << this->getHexHandle()		    << endl;
		this->ZapisDoPliku << 100		 					<< endl;
		this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
		this->ZapisDoPliku << 8		  						<< endl;	
		this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
		this->ZapisDoPliku << 100		 					<< endl;
		this->ZapisDoPliku << "AcDbText"	    			<< endl;
		this->ZapisDoPliku << 10		   	    			<< endl;
		this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 30 * Opis.getSkala()	<< endl;
		this->ZapisDoPliku << 20		   	    			<< endl;
		this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() - 15 * Opis.getSkala()	<< endl;
		this->ZapisDoPliku << 30		   	    			<< endl;
		this->ZapisDoPliku << 0.0					   		<< endl;	
		this->ZapisDoPliku << 40		   	    			<< endl;
		this->ZapisDoPliku << 10 * Opis.getSkala()			<< endl;
		this->ZapisDoPliku << 1			   	    			<< endl;
		this->ZapisDoPliku << "L=" << Opis.getDlugoscPreta()<< endl;	
		this->ZapisDoPliku << 50		   	    			<< endl;
		this->ZapisDoPliku << 0						   		<< endl;	
		this->ZapisDoPliku << 41		   	    			<< endl;
		this->ZapisDoPliku << 1						   		<< endl;
		this->ZapisDoPliku << 7			   	    			<< endl;
		this->ZapisDoPliku << "ARIAL"				   		<< endl;
		this->ZapisDoPliku << 100		 					<< endl;
		this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
		this->ZapisDoPliku << 2			   	    			<< endl;
		this->ZapisDoPliku << "DLUGOSC"				   		<< endl;
		this->ZapisDoPliku << 70		   	    			<< endl;
		this->ZapisDoPliku << 0						   		<< endl;
	}
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 57 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 2 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getStal()		   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "STAL"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() + 96 * Opis.getSkala() + zmiennaKalibracjiLokalizacjiNumeruPreta * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() - 5 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << wielkoscCzcionki * Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getNrPorzadkowyPreta()		   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "NUMER"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	// Zamkniêcie bloku
	this->ZapisDoPliku << 0		  			<< endl;
	this->ZapisDoPliku << "SEQEND"   		<< endl;
	this->ZapisDoPliku << 5		  			<< endl;
	this->ZapisDoPliku << this->getHexHandle()   		<< endl;
	this->ZapisDoPliku << 100		  		<< endl;
	this->ZapisDoPliku << "AcDbEntity"   	<< endl;
	
}

void CreateDxf::OpisPojedynczyPretyZLiniaLewy(OpisPret Opis, Warstwa typWarstwy){
	
	int zmiennaKalibracjiLokalizacjiNumeruPreta;
	int zmiennaKalibracjiLokalizacjiIlosciPretow = 0;
	int wielkoscCzcionki = 10;
	
	//dopasowanie numeru prêta, ¿eby zmieœci³ siê w kó³ku
	switch(Opis.getNrPorzadkowyPreta().length()){
		case 2:
			zmiennaKalibracjiLokalizacjiNumeruPreta = 4;
			break;
		case 3:
			zmiennaKalibracjiLokalizacjiNumeruPreta = 4;
			wielkoscCzcionki = 7;
			break;
		default:
			zmiennaKalibracjiLokalizacjiNumeruPreta = 0;
			wielkoscCzcionki = 10;
			break;
	}
	
	if(Opis.getIloscPretow() > 9){
		zmiennaKalibracjiLokalizacjiIlosciPretow = 11;
	}
	if(Opis.getIloscPretow() > 99){
		zmiennaKalibracjiLokalizacjiIlosciPretow = 15;
	}
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "INSERT"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		   	    			<< endl;
	this->ZapisDoPliku << "AcDbBlockReference"	   		<< endl;
	this->ZapisDoPliku << 66		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "OPIS_LEWY"			   		<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX()   	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY()		<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 42		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 43		   	    			<< endl;
	this->ZapisDoPliku << Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	   				<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() - 76 * Opis.getSkala() - zmiennaKalibracjiLokalizacjiIlosciPretow * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 2 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()			<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getIloscPretow()	   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "ILOSC"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() - 60 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 2 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()			<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getSrednicaPreta()		<< endl;
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;			
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "SREDNICA"			   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
		
	if(Opis.getPokazDlugosc()){
		this->ZapisDoPliku << 0		  						<< endl;
		this->ZapisDoPliku << "ATTRIB"   					<< endl;
		this->ZapisDoPliku << 5		 				   	    << endl;
		this->ZapisDoPliku << this->getHexHandle()		    << endl;
		this->ZapisDoPliku << 100		 					<< endl;
		this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
		this->ZapisDoPliku << 8		  						<< endl;	
		this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
		this->ZapisDoPliku << 100		 					<< endl;
		this->ZapisDoPliku << "AcDbText"	    			<< endl;
		this->ZapisDoPliku << 10		   	    			<< endl;
		this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() - 65 * Opis.getSkala()	<< endl;
		this->ZapisDoPliku << 20		   	    			<< endl;
		this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() - 15 * Opis.getSkala()	<< endl;
		this->ZapisDoPliku << 30		   	    			<< endl;
		this->ZapisDoPliku << 0.0					   		<< endl;	
		this->ZapisDoPliku << 40		   	    			<< endl;
		this->ZapisDoPliku << 10 * Opis.getSkala()			<< endl;
		this->ZapisDoPliku << 1			   	    			<< endl;
		this->ZapisDoPliku << "L=" << Opis.getDlugoscPreta()<< endl;	
		this->ZapisDoPliku << 50		   	    			<< endl;
		this->ZapisDoPliku << 0						   		<< endl;	
		this->ZapisDoPliku << 41		   	    			<< endl;
		this->ZapisDoPliku << 1						   		<< endl;
		this->ZapisDoPliku << 7			   	    			<< endl;
		this->ZapisDoPliku << "ARIAL"				   		<< endl;
		this->ZapisDoPliku << 100		 					<< endl;
		this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
		this->ZapisDoPliku << 2			   	    			<< endl;
		this->ZapisDoPliku << "DLUGOSC"				   		<< endl;
		this->ZapisDoPliku << 70		   	    			<< endl;
		this->ZapisDoPliku << 0						   		<< endl;
	}
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() - 32 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() + 2 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << 10 * Opis.getSkala()					   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getStal()		   		<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "STAL"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "ATTRIB"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbText"	    			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getX() - 104 * Opis.getSkala() - zmiennaKalibracjiLokalizacjiNumeruPreta * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << Opis.getPunktPoczatkowy().getY() - 5 * Opis.getSkala()	<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;	
	this->ZapisDoPliku << 40		   	    			<< endl;
	this->ZapisDoPliku << wielkoscCzcionki * Opis.getSkala()		   		<< endl;
	this->ZapisDoPliku << 1			   	    			<< endl;
	this->ZapisDoPliku << Opis.getNrPorzadkowyPreta()	<< endl;	
	this->ZapisDoPliku << 50		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;	
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1						   		<< endl;
	this->ZapisDoPliku << 7			   	    			<< endl;
	this->ZapisDoPliku << "ARIAL"				   		<< endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbAttribute"    			<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "NUMER"				   		<< endl;
	this->ZapisDoPliku << 70		   	    			<< endl;
	this->ZapisDoPliku << 0						   		<< endl;
	
	// Zamkniêcie bloku
	this->ZapisDoPliku << 0		  			<< endl;
	this->ZapisDoPliku << "SEQEND"   		<< endl;
	this->ZapisDoPliku << 5		  			<< endl;
	this->ZapisDoPliku << this->getHexHandle()   		<< endl;
	this->ZapisDoPliku << 100		  		<< endl;
	this->ZapisDoPliku << "AcDbEntity"   	<< endl;
	
}

void CreateDxf::OpisPojedynczyPretyZLiniaPoziomo(OpisPret Opis, Warstwa typWarstwy, bool CzyPrawyOpis, bool CzyStrzalkiDoGory){
	
	if(CzyPrawyOpis) 
		OpisPojedynczyPretyZLinia(Opis, typWarstwy);
	else
		OpisPojedynczyPretyZLiniaLewy(Opis, typWarstwy);
	
	int i, dlugoscStrzalki = 15 * Opis.getSkala();
	int katStrzalki = 20;
	float xp, yp, xk, yk, maxX, odleglosc, odlegloscMAX;
	Punkt punkt;
	Linia linia;
	LiniaDXF liniaDXF[50];
	
	maxX = Opis.punktZaczepienia[0].getX();
	
	punkt.setX(maxX);
	punkt.setY(Opis.getPunktPoczatkowy().getY());
	odlegloscMAX = punkt.OdlegloscMiedzyPunktami(punkt, Opis.getPunktPoczatkowy());
	
	for(i = 0; i < Opis.getLiczbaPunktowZaczepienia(); i++){
		
		xp = Opis.punktZaczepienia[i].getX();
		yp = Opis.getPunktPoczatkowy().getY();
		
		if(CzyPrawyOpis) 
			xk = xp + dlugoscStrzalki * cos(katStrzalki * PI / 180);
		else
			xk = xp - dlugoscStrzalki * cos(katStrzalki * PI / 180);
	
		if(CzyStrzalkiDoGory)
			yk = yp + dlugoscStrzalki * sin(katStrzalki * PI / 180);
		else
			yk = yp + dlugoscStrzalki * sin(katStrzalki * PI / 180);
		
		linia = linia.stworzLinieZeWspolrzednych(xp, yp, xk, yk);
		
		liniaDXF[i].setWspolrzedneLinii(linia);
		liniaDXF[i].setNazwaWarstwy(typWarstwy);
		
		punkt.setX(xp);
		punkt.setY(Opis.getPunktPoczatkowy().getY());
		odleglosc = punkt.OdlegloscMiedzyPunktami(punkt, Opis.getPunktPoczatkowy());
		if(odlegloscMAX < odleglosc){
			maxX = xp;
			odlegloscMAX = odleglosc;
		}
		
	}
	
	if(Opis.getLiczbaPunktowZaczepienia() > 0){
		this->rysujLinie(liniaDXF);
		this->Line(linia.stworzLinieZeWspolrzednych(maxX, yp, Opis.getPunktPoczatkowy().getX(), yp), typWarstwy);
	}
	
}

void CreateDxf::OpisPojedynczyPretyZLiniamiBezposrednio(OpisPret Opis, Warstwa typWarstwy, bool CzyPrawyOpis){
	
	Linia linia;
	
	if(CzyPrawyOpis) 
		OpisPojedynczyPretyZLinia(Opis, typWarstwy);
	else
		OpisPojedynczyPretyZLiniaLewy(Opis, typWarstwy);
	
	float xp, yp, xk, yk;
	
	xp = Opis.getPunktPoczatkowy().getX();
	yp = Opis.getPunktPoczatkowy().getY();
	
	for(int i = 0; i < Opis.getLiczbaPunktowZaczepienia(); i++){
		
		xk = Opis.punktZaczepienia[i].getX();
		yk = Opis.punktZaczepienia[i].getY();
		
		this->Line(linia.stworzLinieZeWspolrzednych(xp, yp, xk, yk), typWarstwy);
		
	}
	
}

void CreateDxf::OpisPojedynczyPretyZLiniamiRownolegle(OpisPret Opis, Warstwa typWarstwy, bool CzyPrawyOpis){
	
	if(CzyPrawyOpis) 
		OpisPojedynczyPretyZLinia(Opis, typWarstwy);
	else
		OpisPojedynczyPretyZLiniaLewy(Opis, typWarstwy);
	
	int i;
	int katLinii = 20;
	int OpisPonizej = 1;
	float xp, yp, xk, yk, maxX, odleglosc, odlegloscMAX;
	Punkt punkt;
	Linia linia;
	LiniaDXF liniaDXF[50];
	
	yk = Opis.getPunktPoczatkowy().getY();	
	
	maxX = Opis.getPunktPoczatkowy().getX();
	odlegloscMAX = 0;
	
	Opis.getPunktPoczatkowy().getY() < Opis.punktZaczepienia[0].getY() ? OpisPonizej = 1 : OpisPonizej = -1;
	
	for(i = 0; i < Opis.getLiczbaPunktowZaczepienia(); i++){
		
		xp = Opis.punktZaczepienia[i].getX();
		yp = Opis.punktZaczepienia[i].getY();
		
		if(CzyPrawyOpis) 
			xk = xp + OpisPonizej * (yp - Opis.getPunktPoczatkowy().getY()) * sin(katLinii * PI / 180) / cos(katLinii * PI / 180);
		else
			xk = xp - OpisPonizej * (yp - Opis.getPunktPoczatkowy().getY()) * sin(katLinii * PI / 180) / cos(katLinii * PI / 180);
		
		linia = linia.stworzLinieZeWspolrzednych(xp, yp, xk, yk);
		
		liniaDXF[i].setWspolrzedneLinii(linia);
		liniaDXF[i].setNazwaWarstwy(typWarstwy);

		odleglosc = abs(xk - Opis.getPunktPoczatkowy().getX());
		if(odlegloscMAX < odleglosc){
			maxX = xk;
			odlegloscMAX = odleglosc;
		}

	}
	
	this->rysujLinie(liniaDXF);
	this->Line(linia.stworzLinieZeWspolrzednych(maxX, yk, Opis.getPunktPoczatkowy().getX(), yk), typWarstwy);
	
}

void CreateDxf::BlokUszyDuze(Punkt punktPoczatkowy, Warstwa typWarstwy){
	
	this->ZapisDoPliku << 0		  						<< endl;
	this->ZapisDoPliku << "INSERT"   					<< endl;
	this->ZapisDoPliku << 5		 				   	    << endl;
	this->ZapisDoPliku << this->getHexHandle()		    << endl;
	this->ZapisDoPliku << 100		 					<< endl;
	this->ZapisDoPliku << "AcDbEntity"	    			<< endl;
	this->ZapisDoPliku << 8		  						<< endl;	
	this->ZapisDoPliku << warstwaNazwa(typWarstwy)		<< endl;	// Layer number (default layer in autocad)
	this->ZapisDoPliku << 100		   	    			<< endl;
	this->ZapisDoPliku << "AcDbBlockReference"	   		<< endl;
	this->ZapisDoPliku << 2			   	    			<< endl;
	this->ZapisDoPliku << "BLOK_USZY_DUZE"	   			<< endl;
	this->ZapisDoPliku << 10		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getX()   		<< endl;
	this->ZapisDoPliku << 20		   	    			<< endl;
	this->ZapisDoPliku << punktPoczatkowy.getY()		<< endl;
	this->ZapisDoPliku << 30		   	    			<< endl;
	this->ZapisDoPliku << 0.0					   		<< endl;
	this->ZapisDoPliku << 41		   	    			<< endl;
	this->ZapisDoPliku << 1.0					   		<< endl;
	this->ZapisDoPliku << 42		   	    			<< endl;
	this->ZapisDoPliku << 1.0					   		<< endl;
	this->ZapisDoPliku << 43		   	    			<< endl;
	this->ZapisDoPliku << 1.0					   		<< endl;	
	
} 

string CreateDxf::warstwaNazwa(Warstwa rodzajWarstwy){
	switch(rodzajWarstwy){
		case zbrojenie:
			return "__SOL-ZBROJENIE";
		case widok:
			return "__SOL-WIDOK";
		case przerywana:
			return "__SOL-PRZERYWANA";
		case kreskowanie:
			return "__SOL-HATCH";
		case koty_wysokosciowe:
			return "__SOL-KOTY_WYSOKOSCIOWE";
		case wymiary:
			return "__SOL-WYMIARY";
		case opisy:
			return "__SOL-OPISY";
		default:
			return "ERROR";
	}	
}

void CreateDxf::rysujCircles(CircleDXF Circle[], int LimitCircles){
	
	int i = 0;
	
	while(Circle[i].getNazwaWarstwy() != brak && i < LimitCircles){
		this->Circle(
			Circle[i].getDaneKola().getSrodek().getX(),
			Circle[i].getDaneKola().getSrodek().getY(),
			Circle[i].getDaneKola().getPromien(),
			Circle[i].getNazwaWarstwy()
		);
		i++;
	}
}

void CreateDxf::rysujLinie(LiniaDXF Linie[], int LimitLinii){
	
	int i = 0;
	
	while(Linie[i].getNazwaWarstwy() != brak && i < LimitLinii){
		this->Line(
			Linie[i].getWspolrzedneLinii(),
			Linie[i].getNazwaWarstwy()
		);
		i++;
	}
}

void CreateDxf::rysujPolilinie(PoliliniaDXF Polilinie[], int LimitLinii){
	
	int i = 0;
	
	while(Polilinie[i].getNazwaWarstwy() != brak && i < LimitLinii){
		this->PolyLine(Polilinie[i].getWspolrzedneVertex(), Polilinie[i].getNazwaWarstwy(), Polilinie[i].getWspolrzedneVertex().getCzyZamknieta());
		i++;
	}
}
