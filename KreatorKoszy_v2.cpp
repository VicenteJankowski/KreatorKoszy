#include <fstream>		
#include <iostream>
#include <string>
#include <sstream>  // To avoid bug if the user will enter letters or words.
#include <ctime>

#include "RysunekKoszZbrojeniowy.hpp"
#include "ObslugaPlikow.hpp"

using namespace std;

 //Driver program.
int main()
{   
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //do kolorowania tekstu
	
	try{
			
		setlocale(LC_CTYPE, "Polish"); // ustawia polskie znaki w konsoli; uwaga nie dzia�a gdy program wprowadza znaki polskie
		
		string folderpathData, folderpathResults, folderpathPlikiKonfiguracyjne;
		folderpathData = "DaneWejscioweKosza";
		folderpathPlikiKonfiguracyjne = "PlikiKonfiguracyjne";
		folderpathResults = "WygenerowanyRysunek";
		
		setFontSize(14); //Funkcja zdefiniowana w obs�udze plik�w cpp
		SetConsoleTitle("Kreator Koszy 2000 GOLDEN EDITION");
    	
		SetConsoleTextAttribute(hConsole, 23);
		cout << "\nKreator Koszy 2000 ";
		
		SetConsoleTextAttribute(hConsole, 225);
		cout << "GOLDEN EDITION";
		
		SetConsoleTextAttribute(hConsole, 23);
		cout << " - v 4.23.2";
		
		//by� b��d przy pominianiy rz�dnych przekroju, je�li u�ytkownik poda� je spoza zakresu - poprawione
		
		SetConsoleTextAttribute(hConsole, 207);
		cout << "\nAutor: Micha� Jankowski\n\n";
		/*
		if(!sprawdzLicencjaZakodowanaWProgramie())
			throw "Brak licencji. Program nie zostanie uruchomiony.";
			//throw "Program wygenerowa� niespotykany b��d. Zostanie zamkni�ty.";
		
		system("PAUSE");
		*/
		if(!sprawdz_folder(folderpathData)) 
			cout << "Znaleziono folder "<< folderpathData <<"\n";
		else{
			cout << "Nie znaleziono folderu "<< folderpathData <<". Program utworzy folder i zako�czy dzia�anie. Wgraj dane do folderu i uruchom ponownie program.\n";
			mkdir(folderpathData.c_str());
		}
		
		if(!sprawdz_folder(folderpathPlikiKonfiguracyjne)) 
			cout << "Znaleziono folder "<< folderpathPlikiKonfiguracyjne <<".\n";
		else{
			cout << "Nie znaleziono folderu "<< folderpathPlikiKonfiguracyjne <<". Program utworzy folder i zako�czy dzia�anie. Wgraj tam pliki konfiguracyjne, bez nich program nie zadzia�a.\n";
			mkdir(folderpathPlikiKonfiguracyjne.c_str());
		}
		
		if(!sprawdz_folder(folderpathResults)) 
			cout << "Znaleziono folder "<< folderpathResults <<".\n";
		else{
			cout << "Nie znaleziono folderu "<< folderpathResults <<". Program utworzy folder i zako�czy dzia�anie.\n";
			mkdir(folderpathResults.c_str());
		}
		
		string filename;
		int error_nr = 0;
		
		fstream ZapisDoDXF;
		zapisz_plik("GotoweKosze.dxf", folderpathResults, ZapisDoDXF);
		
		DaneWejscioweKosz Dane;
		CreateDxf Draw(ZapisDoDXF);
		
		UstawieniaKoszZbrojeniowy *UstawieniaKosza = new UstawieniaKoszZbrojeniowy;
		UstawieniaRysunekKoszZbrojeniowy *UstawieniaRysunku = new UstawieniaRysunekKoszZbrojeniowy;
		
		try{
			
			fstream PlikZakladyPretow;
		    otworz_plik("ZakladyPretow.txt", folderpathPlikiKonfiguracyjne, PlikZakladyPretow);
		    czytaj_plik_ZakladyPretow(PlikZakladyPretow, *UstawieniaKosza);
			
		}
		catch(const char* ErrorTekst){
			
			SetConsoleTextAttribute(hConsole, 236);
			cout << endl << "Nie uda�o si� odnale�� lub otworzy� pliku z ustawieniami zak�ad�w pr�t�w. Wczytano domy�lny zak�ad r�wny 100cm" << endl;
			
			Beep(523,500);
			Sleep(125);
			Beep(523,500);
			
			system("PAUSE");
			SetConsoleTextAttribute(hConsole, 207);
		}
		
		try{
			
			fstream PlikUkladStrzemion;
		    otworz_plik("UkladStrzemion.txt", folderpathPlikiKonfiguracyjne, PlikUkladStrzemion);
		    czytaj_plik_UkladStrzemion(PlikUkladStrzemion, *UstawieniaKosza);
			
		}
		catch(const char* ErrorTekst){
			
			UstawieniaKosza->setUkladStrzemion(10, 0, 0);
			UstawieniaKosza->setUkladStrzemion(1, 0, 1);
			UstawieniaKosza->setUkladStrzemion(15, 1, 0);
			UstawieniaKosza->setUkladStrzemion(2, 1, 1);
			UstawieniaKosza->setUkladStrzemion(30, 2, 0);
			UstawieniaKosza->setUkladStrzemion(1, 2, 1);
			UstawieniaKosza->setIlePozycjiUkladStrzemion(3);
			
			SetConsoleTextAttribute(hConsole, 236);
			cout << endl << "Nie uda�o si� odnale�� lub otworzy� pliku z uk�adem strzemion. Wczytano domy�lny uk�ad 10cm, 15cm*2, 30cm" << endl;
			
			Beep(523,500);
			Sleep(125);
			Beep(523,500);
			
			system("PAUSE");
			SetConsoleTextAttribute(hConsole, 207);
		}
		
		Punkt punktPoczatkowy;
		
		//okre�la punkt pocz�tkowy pierwszego kosza;
		punktPoczatkowy.setX(UstawieniaRysunku->getPunktPoczatkowyPierwszegoKosza().getX());	
		punktPoczatkowy.setY(UstawieniaRysunku->getPunktPoczatkowyPierwszegoKosza().getY());	
		
		Draw.DxfBegin();
		
		int k = 0;
		
		
		DIR *pdir = NULL;
		struct dirent *pent = NULL;
		
		pdir = opendir (folderpathData.c_str());
		while(pent = readdir(pdir)){
			
			try{
					if(sprawdz_rozszerzenie(pent->d_name, "kosz")){
					
						fstream open_file;
						filename = pent->d_name;		
						
						otworz_plik(filename, folderpathData, open_file);
						
						poprawnosc_pliku(filename, open_file);
						
						Dane = DaneWejscioweKosz();
						Dane.setPrzekrojObliczeniowy(nazwa_bez_rozszerzenia(filename));
						czytaj_plik_kosz(open_file, Dane);
						
						open_file.close();
						
						Dane.sprawdzCzySaWszystkieDane();
						
						//tworzenie pliku DXF
						koszZbrojeniowy kosz(*UstawieniaKosza, Dane, Dane.getSzerokoscKosza(0));
						
						RysunekKoszZbrojeniowy Rysunek(*UstawieniaRysunku, punktPoczatkowy);
						cout << "\n\nGeneruj� kosz " << kosz.getSzerokoscKosza();
						Rysunek.generujRysunekKoszaZbrojeniowego(kosz, Dane);
						
						//Nazwa przekroju obliczeniowego jako nazwa pliku txt z danymi wej�ciowymi
						string LinieTekstu[2];
						LinieTekstu[0] = Dane.getPrzekrojObliczeniowy();
						
						Draw.MTekst(
							punktPoczatkowy.getX() - 3000, 
							(Rysunek.Widok.PretyGlowne[0].getWspolrzedneLinii().getPunktPoczatkowy().getY() + Rysunek.Widok.PretyGlowne[0].getWspolrzedneLinii().getPunktKoncowy().getY()) / 2,
							LinieTekstu,
							1,
							opisy,
							200
							);
						
						//rysuje wszystkie szeroko�ci danego kosza
						for(k = 1; k < Dane.getIleSzerokosci(); k++){
						
							Rysunek.rysujKosz(Draw);
							
							//okre�la punkt pocz�tkowy kolejnego kosza w poziomie;
							punktPoczatkowy.setX(Rysunek.PrzekrojBB[0].Obrys[0].getWspolrzedneLinii().getPunktKoncowy().getX() + UstawieniaRysunku->getOdstepKoszyWPoziomie());
							
							kosz = koszZbrojeniowy(*UstawieniaKosza, Dane, Dane.getSzerokoscKosza(k));
							
							Rysunek = RysunekKoszZbrojeniowy(*UstawieniaRysunku, punktPoczatkowy);
							cout << "\nGeneruj� kosz " << kosz.getSzerokoscKosza();
							
							Rysunek.generujRysunekKoszaZbrojeniowego(kosz, Dane);
						
						}
					
						Rysunek.rysujKosz(Draw);
						
						//okre�la punkt pocz�tkowy kolejnego kosza w pionie;
						punktPoczatkowy.setX(UstawieniaRysunku->getPunktPoczatkowyPierwszegoKosza().getX());	
						punktPoczatkowy.setY(Rysunek.Widok.Obrys[3].getWspolrzedneLinii().getPunktKoncowy().getY() - UstawieniaRysunku->getOdstepKoszyWPionie());
						
						cout << endl;																								
						//system("PAUSE");
						
					}
			}
			catch(const char* ErrorTekst){
				
				SetConsoleTextAttribute(hConsole, 236);
				cerr << ErrorTekst << endl;
				cout << "Kosze z tego pliku nie zostan� wygenerowane." << endl;
				
				Beep(523,500);
				Sleep(125);
				Beep(523,500);
				
				system("PAUSE");
				SetConsoleTextAttribute(hConsole, 207);
				
			}
		}
		
		if(Dane.getIleSzerokosci() == 0)
			throw "\nNie odnaleziono plik�w z danymi wej�ciowymi. Wgraj dane wej�ciowe i ponownie uruchom program.";
		
		Draw.DxfEnd();
		ZapisDoDXF.close();
		
		if(k > 0){			
			cout << "\nProgram pomy�lnie zako�czy� generacj� koszy." << endl;
			odtworzDzwiek();		
		}
		else
			cout << "\nNie uda�o si� wygenerowa� �adnych koszy." << endl;
		
	} catch(const char* ErrorTekst){
		
		SetConsoleTextAttribute(hConsole, 236);
		cerr << ErrorTekst << endl;
		SetConsoleTextAttribute(hConsole, 207);
		
		Beep(523,500);
		Sleep(125);
		Beep(523,500);
		
	}
	
	cout << endl << endl;
   	system("PAUSE");
	return 0;
	
}
