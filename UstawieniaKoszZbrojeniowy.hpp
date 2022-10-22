#ifndef UstawieniaKoszZbrojeniowy_hpp
#define UstawieniaKoszZbrojeniowy_hpp

class UstawieniaKoszZbrojeniowy{
	
	private:
		int MaxDlugoscPreta = 1300;
		int MinDlugoscPreta = 300;
		
		int MinDlugoscZakladu = 100;
		
		int DodatkowaDlugoscPretNr7 = 100;
		
	public:
		
		bool setMaxDlugoscPreta(int);
		int getMaxDlugoscPreta();
		
		bool setMinDlugoscPreta(int);
		int getMinDlugoscPreta();
		
		bool setMinDlugoscZakladu(int);
		int getMinDlugoscZakladu();
		
		bool setDodatkowaDlugoscPretNr7(int);
		int getDodatkowaDlugoscPretNr7();
			
		UstawieniaKoszZbrojeniowy(){
			
	
		}
		
};

#endif
