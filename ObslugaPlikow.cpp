#include "ObslugaPlikow.hpp"

using namespace std;

void setFontSize(int FontSize)
{
    CONSOLE_FONT_INFOEX info = {0};
    info.cbSize       = sizeof(info);
    info.dwFontSize.Y = FontSize; // leave X as zero
    info.FontWeight   = FW_NORMAL;
    wcscpy(info.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

string szyfrujTresc(string tekst, int x){
	
	// UWAGA!!!  tekst wprowadzaæ bez spacji
	// Szyfr cezara
	 
	for(int i = 0; i <= tekst.length(); i++){
		
		if(tekst[i] >= 48 && tekst[i] <= 57-x) 
			
			tekst[i] = int(tekst[i]) + x; // cyfry
			
		else if(tekst[i] >= 58 - x && tekst[i] <= 57) 
			
			tekst[i] = int(tekst[i]) - 10 + x; // cyfry
		
	}

	
	return tekst;
}

string zamienLiczbyNaLitery(string tekst){
	
	for(int i = 0; i <= tekst.length(); i++){
		
		switch(tekst[i]){
			
			case 47 + 1:
				tekst[i] = 100;
				break;
				
			case 47 + 2:
				tekst[i] = 97;
				break;
				
			case 47 + 3:
				tekst[i] = 98;
				break;
				
			case 47 + 4:
				tekst[i] = 99;
				break;
				
			case 47 + 5:
				tekst[i] = 101;
				break;
				
			case 47 + 6:
				tekst[i] = 103;
				break;
				
			case 47 + 7:
				tekst[i] = 107;
				break;
				
			case 47 + 8:
				tekst[i] = 109;
				break;
				
			case 47 + 9:
				tekst[i] = 111;
				break;
				
			case 47 + 10:
				tekst[i] = 117;
				break;
		}
		
	}
	
	return tekst;
}

string zamienLiteryNaLiczby(string tekst){
	
	for(int i = 0; i <= tekst.length(); i++){
		
		switch(tekst[i]){
			
			case 100:
				tekst[i] = 48;
				break;
				
			case 97:
				tekst[i] = 49;
				break;
				
			case 98:
				tekst[i] = 50;
				break;
				
			case 99:
				tekst[i] = 51;
				break;
				
			case 101:
				tekst[i] = 52;
				break;
				
			case 103:
				tekst[i] = 53;
				break;
				
			case 107:
				tekst[i] = 54;
				break;
				
			case 109:
				tekst[i] = 55;
				break;
				
			case 111:
				tekst[i] = 56;
				break;
				
			case 117:
				tekst[i] = 57;
				break;
		}
		
	}
	
	return tekst;
}

bool sprawdzLicencjaZakodowanaWProgramie(){
	
	try{	
			string linia;
			
			//Ten fragment mo¿e byæ wykorzystywany do generowania nowych licencji, po odkodowaniu -> licz¹ siê tylko pierwsze 8 znaków, póŸniej znaki mog¹ byæ dowolne
		/*	int RokDoZakodowania = 2019;
			string MiesiacDoZakodowania = "04";
			string DzienDoZakodowania = "13";
			
			string TekstSzyfrowany = MiesiacDoZakodowania + to_string(RokDoZakodowania - 1900)+ DzienDoZakodowania;
			
			cout << TekstSzyfrowany << endl;
			
			TekstSzyfrowany = szyfrujTresc(TekstSzyfrowany, 5);
			cout << TekstSzyfrowany << endl;
			cout << zamienLiczbyNaLitery(TekstSzyfrowany) << endl;
			
			TekstSzyfrowany = szyfrujTresc(TekstSzyfrowany, 5);
			cout << TekstSzyfrowany << endl;
			
			TekstSzyfrowany = zamienLiczbyNaLitery(TekstSzyfrowany);
			cout << TekstSzyfrowany << endl;
			TekstSzyfrowany = zamienLiteryNaLiczby(TekstSzyfrowany);
			cout << TekstSzyfrowany << endl;*/
			
			linia = "gukkeko";						// tu jest zakodowana data 13-04-2019
			linia = zamienLiteryNaLiczby(linia);
			
			time_t t = time(0);   // get time now
			tm* now = localtime(&t);
			
			string miesiac = to_string(now->tm_mon + 1);
			
			if(now->tm_mon < 10)
				miesiac = "0" + miesiac;
			
			string dzienMiesiaca = to_string(now->tm_mday);
			
			if(now->tm_mday < 10)
				dzienMiesiaca = "0" + dzienMiesiaca;					
			
			//sprawdza czy data nie jest przekroczona - wybiera z ciagu znakow pierwsze dwa znaki jako dzien, kolejne trzy jako rok, kolejna dwa jak dzien miesiaca; pamiêtaj, ¿e rok jest liczony od 1900, wiêc w 2018 to jest 118
			if(szyfrujTresc(linia.substr(2, 3), 5).c_str() > to_string(now->tm_year))
			
				return 1;
		
			else if(szyfrujTresc(linia.substr(2, 3), 5).c_str() == to_string(now->tm_year)){
				
				if(szyfrujTresc(linia.substr(0, 2), 5).c_str() > miesiac)
					
					return 1;
				
				else if(szyfrujTresc(linia.substr(0, 2), 5).c_str() == miesiac){
				
					if(szyfrujTresc(linia.substr(5, 2), 5).c_str() > dzienMiesiaca)
						
						return 1;
					
					else
						
						return 0;	
				}		
				else
					
					return 0;					
			}
			else
				
				return 0;
	}
	catch(const char* ErrorTekst){
		
		
		
	}
	
}

bool sprawdzLicencja(){
	
	string folderpathData = ".";
	
	DIR *pdir = NULL;
	struct dirent *pent = NULL;
	
	pdir = opendir (folderpathData.c_str());
	
	string filename;
	int j = 0;
	
	while(pent = readdir(pdir)){
	
		try{	
			if(sprawdz_rozszerzenie(pent->d_name, "lic", 1)){
			
				fstream open_file;
				filename = pent->d_name;		
				
				otworz_plik(filename, folderpathData, open_file);	         	
	         	
				int line_limit = 0;
				string linia;
				
				while(!open_file.eof() && line_limit++ != 5000){
					
					//w szóstej linii kod licencji
					getline(open_file, linia);
					getline(open_file, linia);
					getline(open_file, linia);
					getline(open_file, linia);
					getline(open_file, linia);
					getline(open_file, linia);

					//Ten fragment mo¿e byæ wykorzystywany do generowania nowych licencji, po odkodowaniu -> licz¹ siê tylko pierwsze 8 znaków, póŸniej znaki mog¹ byæ dowolne
				/*	int RokDoZakodowania = 2019;
					string MiesiacDoZakodowania = "04";
					string DzienDoZakodowania = "13";
					
					string TekstSzyfrowany = MiesiacDoZakodowania + to_string(RokDoZakodowania - 1900)+ DzienDoZakodowania;
					
					cout << TekstSzyfrowany << endl;
					
					TekstSzyfrowany = szyfrujTresc(TekstSzyfrowany, 5);
					cout << TekstSzyfrowany << endl;
					cout << zamienLiczbyNaLitery(TekstSzyfrowany) << endl;
					
					TekstSzyfrowany = szyfrujTresc(TekstSzyfrowany, 5);
					cout << TekstSzyfrowany << endl;
					
					TekstSzyfrowany = zamienLiczbyNaLitery(TekstSzyfrowany);
					cout << TekstSzyfrowany << endl;
					TekstSzyfrowany = zamienLiteryNaLiczby(TekstSzyfrowany);
					cout << TekstSzyfrowany << endl;*/
					
					linia = zamienLiteryNaLiczby(linia);
					
					time_t t = time(0);   // get time now
	  				tm* now = localtime(&t);
					
					string miesiac = to_string(now->tm_mon + 1);
					
					if(now->tm_mon < 10)
						miesiac = "0" + miesiac;
					
					string dzienMiesiaca = to_string(now->tm_mday);
					
					if(now->tm_mday < 10)
						dzienMiesiaca = "0" + dzienMiesiaca;					
					
					//sprawdza czy data nie jest przekroczona - wybiera z ciagu znakow pierwsze dwa znaki jako dzien, kolejne trzy jako rok, kolejna dwa jak dzien miesiaca; pamiêtaj, ¿e rok jest liczony od 1900, wiêc w 2018 to jest 118
					if(szyfrujTresc(linia.substr(2, 3), 5).c_str() > to_string(now->tm_year))
					
						return 1;
				
					else if(szyfrujTresc(linia.substr(2, 3), 5).c_str() == to_string(now->tm_year)){
						
						if(szyfrujTresc(linia.substr(0, 2), 5).c_str() > miesiac)
							
							return 1;
						
						else if(szyfrujTresc(linia.substr(0, 2), 5).c_str() == miesiac){
						
							if(szyfrujTresc(linia.substr(5, 2), 5).c_str() > dzienMiesiaca)
								
								return 1;
							
							else
								
								return 0;	
						}		
						else
							
							return 0;					
					}
					else
						
						return 0;
				}
				
				open_file.close();
			}
		}
		catch(const char* ErrorTekst){
			
			
			
		}
	
	}
		   
	throw "Brak licencji. Program nie zostanie uruchomiony.";;
	
}

string nazwa_bez_rozszerzenia(string filename){
	
	int  a = 0;
	string nazwa = "";
			
	while(filename[a] != '.'){
	
		nazwa+=filename[a++];
		
		if(filename.length() == a)
			throw "Brak rozszerzenia w nazwie pliku";	
		
	}
		
	return nazwa;	
}

bool sprawdz_rozszerzenie(string filename, string RozszerzenieOczekiwane, bool NoComment){
	
	if(filename == "." || filename == "..")
		return 0;
	
	int  a = 1;
	string rozszerzenie = "";
	
	while(filename[filename.length()-a] != '.')
		rozszerzenie+=filename[filename.length()-(a++)];
	
	rozszerzenie = string(rozszerzenie.rbegin(), rozszerzenie.rend());
	
	if(rozszerzenie == RozszerzenieOczekiwane){
	
		if(!NoComment) cout << "Znaleziono plik " << filename << " w folderze wejœciowym.\n";
		
		return 1;
		
	}
	else{
		
		string blad = filename + string(" <- z³e rozszerzenie pliku.\n");
		
		throw blad.c_str();
		
	}
}

bool otworz_plik(string filename, string folderpath, fstream &open_file){
		
	string filepath = folderpath + "\\" + filename;
	
	open_file.open(filepath.c_str(), ios::in );
	
	if(open_file.fail())	throw "Nie uda³o siê otworzyæ pliku.\n";
	
	return 0;	
}

int zapisz_plik(string filename, string folderpath, fstream &save_file, int limit){
	
	int decyzja = 0;
		
	string filepath = folderpath + "\\" + nazwa_bez_rozszerzenia(filename) + ".dxf";

	
	save_file.open(filepath.c_str(), ios::in );
	
	if(!save_file.fail() && limit == 0){
		
		save_file.close();
		
		cout << "\n\nDomyœlny plik wynikowy ju¿ istnieje. Czy chcesz go nadpisaæ (1), zapisaæ wygenerowane kosze pod inn¹ nazw¹ (2) lub anulowaæ generacjê koszy (3)?\n";
		cin >> decyzja;
				
		while(decyzja != 2 && decyzja != 1 && decyzja != 3){
			cout << "\nZ³y wybór. Wybierz (1), ¿eby nadpisaæ plik, (2) ¿eby zapisaæ wygenerowane kosze pod inn¹ nazw¹ lub (3) ¿eby anulowaæ generacjê.";
			cin >> decyzja;
		}
		
		if(decyzja == 1){
			
			if(save_file.is_open())
				throw "\n\nNie mo¿na otworzyæ pliku wynikowego. Prawdopodobnie jest on otwarty w innym programie. Zamknij plik wynikowy i uruchom ponownie program.";
				
			save_file.open(filepath.c_str(), ios::out | ios::trunc);	
				
			if(save_file.fail())
				throw "\n\nNie mo¿na otworzyæ pliku wynikowego. Prawdopodobnie jest on otwarty w innym programie. Zamknij plik wynikowy i uruchom ponownie program.";
				
			return 0;
			
		}
		
		int ile_razy = 0;
		if(decyzja == 2){
			while(ile_razy++ < 11){
				cout << "\nPodaj now¹ nazwê pliku: ";
				cin >> filename;
				filepath = folderpath + "\\" + filename + ".dxf";
				
				cout << filepath;
				
				save_file.open(filepath.c_str(), ios::in );
	
				if(save_file.fail()) break;	
				
				cout << "\nPlik z tak¹ nazw¹ ju¿ istnieje.\n\n";				
			}
			if(ile_razy > 10) return 6;
		}
		
		if(decyzja == 3){
			cout << "\nGenerowanie kosza przerwane przez u¿ytkownika.\n\n";
			system("PAUSE");
			return 4;
		}
	}
	

	save_file.open(filepath.c_str(), ios::out | ios::app);
	
	if(save_file.fail())
		throw "Nie uda³o siê utworzyæ pliku wynikowego.";
	
	return 0;	
}

bool sprawdz_folder(string folderpath){

	DIR *pdir = NULL;
	struct dirent *pent = NULL;
	
	pdir = opendir (folderpath.c_str());
    if (pdir == NULL){ 
        return 1;
    }
   	return 0;
}

void poprawnosc_pliku(string filename, fstream &file_verf){
	
	cout << "\n\nSprawdzanie pliku " << filename <<" ...\n\n";
	
	int MikeFile = 0;
	int line_limit = 0;
	
	string linia;
	
	while(!file_verf.eof() && line_limit++ != 5000){
		
		getline(file_verf, linia);
		
		if(linia.find("KOSZ-START") != string::npos)
			MikeFile++;
		
		if(MikeFile == 1) break;
		
	}
	
	
	file_verf.seekp(0, ios::beg);
	
	if(MikeFile == 1)
		cout << "Plik wejœciowy wygl¹da na poprawny." << endl;
	else
		throw "To nie jest poprawny plik wejœciowy.";
}

string pominKomentarze(fstream &file_verf){
	
	char znak;
	string linia;
					
	getline(file_verf, linia);
		
	while(linia.length() == 0 && !file_verf.eof())
		getline(file_verf, linia);
		
		if(file_verf.eof()) return linia;
			
		znak = linia.at(0);
		
		//pomija linie z komentarzem
		while(znak == '#'){ 
			getline(file_verf, linia);
			
			while(linia.length() == 0 && !file_verf.eof())
				getline(file_verf, linia);
			
			if(file_verf.eof()) break;
			
			znak = linia.at(0);
		
		}
	
	return linia;
	
}

void czytaj_plik_kosz(fstream &file_verf, DaneWejscioweKosz &Dane){
	
	cout << "Wczytujê dane." << endl;
	
	string linia;
	int line_limit = 0;

	while(!file_verf.eof() && line_limit < 5000){
			
		linia = pominKomentarze(file_verf);
		
		if(file_verf.eof()) break;
		
		if(linia == "RZEDNA-WIERZCHU-SCIANY"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				Dane.setRzednaWierzchuSciany(strtof(linia.c_str(), 0));
				
				cout << "Znaleziono rzêdn¹ wierzchu œciany -> "	<< linia << endl;
					
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;
				cout << "Nie uda³o siê wczytaæ rzêdnej wierzchu œciany. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
			
		}
		if(linia == "RZEDNA-SPODU-SCIANY"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				Dane.setRzednaSpoduSciany(strtof(linia.c_str(), 0));
					
				cout << "Znaleziono rzêdn¹ spodu œciany -> "	<< linia << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ rzêdnej spodu œciany. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "RZEDNA-WIERZCHU-ZBROJENIA"){
			
			linia = pominKomentarze(file_verf);
			
			try{
					
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				Dane.setRzednaWierzchuZbrojenia(strtof(linia.c_str(), 0));
					
				cout << "Znaleziono rzêdn¹ wierzchu zbrojenia -> "	<< linia << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ rzêdnej wierzchu zbrojenia. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "RZEDNA-SPODU-ZBROJENIA"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
						
				Dane.setRzednaSpoduZbrojenia(strtof(linia.c_str(), 0));
					
				cout << "Znaleziono rzêdn¹ spodu zbrojenia -> "	<< linia << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ rzêdnej spodu zbrojenia. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "POZIOM-MURKOW-PROWADZACYCH"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				Dane.setPoziomMurkowProwadzacych(strtof(linia.c_str(), 0));
					
				cout << "Znaleziono poziom murków prowadz¹cych -> "	<< linia << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ poziomu murków prowadz¹cych. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "SZEROKOSC-SCIANY"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				Dane.setSzerokoscSciany(strtof(linia.c_str(), 0));
					
				cout << "Znaleziono szerokoœæ œciany -> "	<< linia << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ szerokoœci œciany. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "ZBROJENIE-GLOWNE-GRUNT"){

			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretyProste PretPomocniczy;
				
				PretPomocniczy.setIleNaMetr(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretPomocniczy.setSrednica(strtof(linia.c_str(), 0) * 10);
				
				Dane.setPretyGlowne(PretPomocniczy, 0);
					
				cout << "Znaleziono zbrojenie g³ówne od strony gruntu -> "	<< PretPomocniczy.getIleNaMetr() << "fi" << PretPomocniczy.getSrednica() << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ zbrojenia g³ównego od strony gruntu. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "ZBROJENIE-GLOWNE-WYKOP"){

			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretyProste PretPomocniczy;
				
				PretPomocniczy.setIleNaMetr(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretPomocniczy.setSrednica(strtof(linia.c_str(), 0) * 10);
				
				Dane.setPretyGlowne(PretPomocniczy, 1);
					
				cout << "Znaleziono zbrojenie g³ówne od strony wykopu -> "	<< PretPomocniczy.getIleNaMetr() << "fi" << PretPomocniczy.getSrednica() << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ zbrojenia g³ównego od strony wykopu. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "DOZBROJENIE-GRUNT-1"){

			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretyProste PretPomocniczy;
				
				PretPomocniczy.setIleNaMetr(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretPomocniczy.setSrednica(strtof(linia.c_str(), 0) * 10);
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaWierzchu(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaSpodu(strtof(linia.c_str(), 0));
				
				Dane.setDozbrojenieOdStronyGruntuI(PretPomocniczy);
					
				cout << "Znaleziono dozbrojenie I od strony gruntu -> "	<< PretPomocniczy.getIleNaMetr() << "fi" << PretPomocniczy.getSrednica() << ", od " << PretPomocniczy.getRzednaWierzchu() << " do " << PretPomocniczy.getRzednaSpodu() << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ dozbrojenia I od strony gruntu. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "DOZBROJENIE-GRUNT-2"){

			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretyProste PretPomocniczy;
				
				PretPomocniczy.setIleNaMetr(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretPomocniczy.setSrednica(strtof(linia.c_str(), 0) * 10);
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaWierzchu(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaSpodu(strtof(linia.c_str(), 0));
				
				Dane.setDozbrojenieOdStronyGruntuII(PretPomocniczy);
					
				cout << "Znaleziono dozbrojenie II od strony gruntu -> "	<< PretPomocniczy.getIleNaMetr() << "fi" << PretPomocniczy.getSrednica() << ", od " << PretPomocniczy.getRzednaWierzchu() << " do " << PretPomocniczy.getRzednaSpodu() << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ dozbrojenia II od strony gruntu. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "DOZBROJENIE-WYKOP-1"){

			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretyProste PretPomocniczy;
				
				PretPomocniczy.setIleNaMetr(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretPomocniczy.setSrednica(strtof(linia.c_str(), 0) * 10);
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaWierzchu(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaSpodu(strtof(linia.c_str(), 0));
				
				Dane.setDozbrojenieOdStronyWykopuI(PretPomocniczy);
					
				cout << "Znaleziono dozbrojenie I od strony wykopu -> "	<< PretPomocniczy.getIleNaMetr() << "fi" << PretPomocniczy.getSrednica() << ", od " << PretPomocniczy.getRzednaWierzchu() << " do " << PretPomocniczy.getRzednaSpodu() << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ dozbrojenia I od strony wykopu. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "DOZBROJENIE-WYKOP-2"){

			linia = pominKomentarze(file_verf);
			
			try{
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretyProste PretPomocniczy;
				
				PretPomocniczy.setIleNaMetr(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
					
				PretPomocniczy.setSrednica(strtof(linia.c_str(), 0) * 10);
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaWierzchu(strtof(linia.c_str(), 0));
				
				linia = pominKomentarze(file_verf);
				
				if(!CzyToLiczba(linia))
					throw "Podany ci¹g znaków nie jest liczb¹.";
				
				PretPomocniczy.setRzednaSpodu(strtof(linia.c_str(), 0));
				
				Dane.setDozbrojenieOdStronyWykopuII(PretPomocniczy);
					
				cout << "Znaleziono dozbrojenie II od strony wykopu -> "	<< PretPomocniczy.getIleNaMetr() << "fi" << PretPomocniczy.getSrednica() << ", od " << PretPomocniczy.getRzednaWierzchu() << " do " << PretPomocniczy.getRzednaSpodu() << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ dozbrojenia II od strony wykopu. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "SZEROKOSCI-KOSZA"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				int j = 0;
				
				for(j; linia != "KONIEC-SZEROKOSCI-KOSZA"; j++){
					
					Dane.setSzerokoscKosza(strtof(linia.c_str(), 0), j);
					
					cout << "Znaleziono szerokoœæ kosza -> " << linia << endl;
					
					linia = pominKomentarze(file_verf);
					
					if(j > 50)
						throw "Nie znaleziono zakoñczenia bloku z szerokoœciami kosza. W linijce poni¿ej zakoñczenia szerokoœci kosza dopisz frazê KONIEC-SZEROKOSCI-KOSZA. ";
				}
				
				Dane.setIleSzerokosci(j);
				
				if(j == 0)
						throw "Nie znaleziono szerokoœci kosza.";
				else
					cout << "Uda³o siê wczytaæ " << j <<  " szerokoœci kosza" << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				cout << "Nie uda³o siê wczytaæ ¿adnej szerokoœci kosza. SprawdŸ poprawnoœæ wprowadzonych danych." << endl;
				
			}
		}
		if(linia == "PRZEKROJEBB"){
			
			linia = pominKomentarze(file_verf);
			
			try{
				
				int j = 0;
				
				for(j; linia != "KONIEC-PRZEKROJEBB"; j++){
					
					Dane.setRzednePrzekrojuBB(strtof(linia.c_str(), 0), j);
					
					cout << "Znaleziono now¹ rzêdn¹ przekroju B-B -> " << linia << endl;
					
					linia = pominKomentarze(file_verf);
					
					if(j > 5)
						throw "Nie znaleziono zakoñczenia bloku z rzêdnymi przekrojów B-B lub liczba rzêdnych jest zbyt du¿a. W linijce poni¿ej zakoñczenia szerokoœci kosza dopisz frazê KONIEC-PRZEKROJEBB lub zmniejsz liczbê rzêdnych. ";
				}
				
				Dane.setIleRzednychPrzekrojuBB(j);
				
				if(j > 0)
					cout << "Uda³o siê wczytaæ " << j <<  " rzêdnych przekroju B-B" << endl;
						
			}catch(const char* ErrorTekst){
				cout << ErrorTekst;	
				
			}
		}
	}
		
	
}

string przecinek2kropka(string linia){
		
	for(int i = 0; i < linia.length(); i++)
		if(linia[i] == ',')
			linia[i] = '.';
	
	return linia;
}

string kropka2przecinek(string linia){
		
	for(int i = 0; i < linia.length(); i++)
		if(linia[i] == '.')
			linia[i] = ',';
	
	return linia;
}

bool CzyToLiczba(string s){
	
	for(int i = 0; i < s.length(); i++)
		if(!isdigit(s.at(i)) && s.at(i) != '.' && s.at(i) != ',' && s.at(i) != '-' && s.at(i) != '+')
			return 0;
			
	return 1;
	
}

void odtworzDzwiek(){
	
/*	Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (392,100);Sleep(700);
    Beep (196,100);Sleep(700);
    Beep (262,300);Sleep(300);
    Beep (196,300);Sleep(300);
    Beep (164,300);Sleep(300);
    Beep (220,300);Sleep(100);
    Beep (246,100);Sleep(300);
    Beep (233,200);
    Beep (220,100);Sleep(300);
    Beep (196,100);Sleep(150);
    Beep (330,100);Sleep(150);
    Beep (392,100);Sleep(150);
    Beep (440,100);Sleep(300);
    Beep (349,100);Sleep(100);
    Beep (392,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(100);
    Beep (247,100);Sleep(500);
    Beep (262,300);Sleep(300);
    Beep (196,300);Sleep(300);
    Beep (164,300);Sleep(300);
    Beep (220,300);Sleep(100);
    Beep (246,100);Sleep(300);
    Beep (233,200);
    Beep (220,100);Sleep(300);
    Beep (196,100);Sleep(150);
    Beep (330,100);Sleep(150);
    Beep (392,100);Sleep(150);
    Beep (440,100);Sleep(300);
    Beep (349,100);Sleep(100);
    Beep (392,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(100);
    Beep (247,100);Sleep(900);
    Beep (392,100);Sleep(100);
    Beep (370,100);Sleep(100);
    Beep (349,100);Sleep(100);
    Beep (311,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (207,100);Sleep(100);
    Beep (220,100);Sleep(100);
    Beep (262,100);Sleep(300);
    Beep (220,100);Sleep(100);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(500);
    Beep (392,100);Sleep(100);
    Beep (370,100);Sleep(100);
    Beep (349,100);Sleep(100);
    Beep (311,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (523,100);Sleep(300);
    Beep (523,100);Sleep(100);
    Beep (523,100);Sleep(1100);
    Beep (392,100);Sleep(100);
    Beep (370,100);Sleep(100);
    Beep (349,100);Sleep(100);
    Beep (311,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (207,100);Sleep(100);
    Beep (220,100);Sleep(100);
    Beep (262,100);Sleep(300);
    Beep (220,100);Sleep(100);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(500);
    Beep (311,300);Sleep(300);
    Beep (296,300);Sleep(300);
    Beep (262,300);Sleep(1300);
    Beep (262,100);Sleep(100);
    Beep (262,100);Sleep(300);
    Beep (262,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(300);
    Beep (330,200);Sleep(50);
    Beep (262,200);Sleep(50);
    Beep (220,200);Sleep(50);
    Beep (196,100);Sleep(700);
    Beep (262,100);Sleep(100);
    Beep (262,100);Sleep(300);
    Beep (262,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(100);
    Beep (330,100);Sleep(700);
    Beep (440,100);Sleep(300);
    Beep (392,100);Sleep(500);
    Beep (262,100);Sleep(100);
    Beep (262,100);Sleep(300);
    Beep (262,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (294,100);Sleep(300);
    Beep (330,200);Sleep(50);
    Beep (262,200);Sleep(50);
    Beep (220,200);Sleep(50);
    Beep (196,100);Sleep(700);*/
    /*Intro*/
  //  Beep (330,100);Sleep(100);
  //  Beep (330,100);Sleep(300);
  //  Beep (330,100);Sleep(300);
  //  Beep (262,100);Sleep(100);
  //  Beep (330,100);Sleep(300);
  //  Beep (392,100);Sleep(700);
  //  Beep (196,100);Sleep(700);
    Beep (196,100);Sleep(125);
    Beep (262,100);Sleep(125);
    Beep (330,100);Sleep(125);
    Beep (392,100);Sleep(125);
    Beep (523,100);Sleep(125);
    Beep (660,100);Sleep(125);
    Beep (784,100);Sleep(575);
    Beep (660,100);Sleep(575);
    Beep (207,100);Sleep(125);
    Beep (262,100);Sleep(125);
    Beep (311,100);Sleep(125);
    Beep (415,100);Sleep(125);
    Beep (523,100);Sleep(125);
    Beep (622,100);Sleep(125);
    Beep (830,100);Sleep(575);
    Beep (622,100);Sleep(575);
    Beep (233,100);Sleep(125);
    Beep (294,100);Sleep(125);
    Beep (349,100);Sleep(125);
    Beep (466,100);Sleep(125);
    Beep (587,100);Sleep(125);
    Beep (698,100);Sleep(125);
    Beep (932,100);Sleep(575);
    Beep (932,100);Sleep(125);
    Beep (932,100);Sleep(125);
    Beep (932,100);Sleep(125);
    Beep (1046,675);
	
}

