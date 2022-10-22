#ifndef UstawieniaKoszZbrojeniowy_hpp
#define UstawieniaKoszZbrojeniowy_hpp

#include <iostream>

class UstawieniaKoszZbrojeniowy{
	
	private:
		unsigned short int MaxDlugoscPreta = 1300;
		unsigned short int MinDlugoscPreta = 300;
		
		int LiczbaTypowychSrednicPretow	= 12;
		int TypoweSrednicePretow[12] = {6, 8, 10, 12, 14, 16, 18, 20, 22, 25, 32, 40};
		
		unsigned short int MinDlugoscZakladu = 100;
		
		unsigned short int DlugoscZakladuPret[20][2];	
		
		unsigned short int DodatkowaDlugoscPretNr7 = 100;
			
		float UkladStrzemion[200][2];
		unsigned short int IlePozycjiUkladStrzemion = 0;
		float MinOdlegloscStrzemieniaOdKoncaKosza = 10;
		
	public:
		
		bool setMaxDlugoscPreta(int);
		unsigned short int getMaxDlugoscPreta();
		
		bool setMinDlugoscPreta(int);
		unsigned short int getMinDlugoscPreta();
		
		bool setMinDlugoscZakladu(int);
		unsigned short int getMinDlugoscZakladu();
		
		bool setDlugoscZakladuPret(int, int);
		unsigned short int getDlugoscZakladuPret(float);
		
		bool setDodatkowaDlugoscPretNr7(int);
		unsigned short int getDodatkowaDlugoscPretNr7();
		
		bool setUkladStrzemion(float, int, int);
		float getUkladStrzemion(int, int);
		
		bool setIlePozycjiUkladStrzemion(int);
		unsigned short int getIlePozycjiUkladStrzemion();
		
		bool setMinOdlegloscStrzemieniaOdKoncaKosza(float);
		float getMinOdlegloscStrzemieniaOdKoncaKosza();
		
		UstawieniaKoszZbrojeniowy(){
			
			for(int i = 0; i < this->LiczbaTypowychSrednicPretow; i++){
				this->DlugoscZakladuPret[i][0] = this->TypoweSrednicePretow[i];
				this->DlugoscZakladuPret[i][1] = 100;	
			}
				
		}
		
};

#endif
