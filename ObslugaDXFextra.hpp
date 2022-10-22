#ifndef ObslugaDXFextra_hpp
#define ObslugaDXFextra_hpp

#include "elementyGeometryczne.hpp"
#include "RysunekKoszZbrojeniowy.hpp"

void rysujWszystkieTekstyOpisowe(CreateDxf, TekstyOpisowe[], Warstwa, int Limit = 1000);
void rysujWszystkieKoty(CreateDxf, KotaWysokosciowa KotaWysokosciowa[], Warstwa typWarstwy, int LimitKot = 100);
void rysujWszystkieWymiaryNormalne(CreateDxf draw, WymiarNormalny[], Warstwa, int LimitWymiarow = 100);
void rysujWszystkieWymiaryPromienia(CreateDxf, WymiarPromienia[], Warstwa, int LimitWymiarow = 100);
void rysujWszystkieOpisyPretBezLinii(CreateDxf, OpisPret[], Warstwa, int LimitOpisow = 100);
void rysujWszystkieOpisyPretZLiniaPoziomo(CreateDxf, OpisPret[], Warstwa, bool CzyPrawyOpis = 1, bool CzyStrzalkiDoGory = 1, int LimitOpisow = 100);
void rysujWszystkieOpisyPretZLiniaBezposrednio(CreateDxf, OpisPret[], Warstwa, bool CzyPrawyOpis = 1, int LimitOpisow = 100);
void rysujWszystkieOpisyPretZLiniaRownolegle(CreateDxf, OpisPret[], Warstwa, bool CzyPrawyOpis = 1, int LimitOpisow = 100);

#endif
