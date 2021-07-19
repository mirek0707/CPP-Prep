/* Celem zadania jest napisanie klasy MapPoint opisujacej punkt na mapie
 * oraz przećwiczenie użycia referencji, funkcji statycznych, a także 
 * referencji i obiektów niemodyfikowalnych (const)
 * 
 * 
 * Prosze kompilować przynajmniej z opcja -Wall 
 */

#include <iostream>
#include "MapPoint.h"
#include "MapPoint.h"

int main() {

  // ============== Cracow ==============
  const double latKRK = 50.06139;
  const double lonKRK = 19.93833;
  const MapPoint krk( latKRK,  lonKRK);
  krk.print();
  
  // =============== Pisa ===============
  MapPoint pisa(43.70853, 10.4036);
  pisa.move(0.1, -0.1);
  pisa.print();

  // =============== Bali ===============
  MapPoint bali(-8.40952, 115.18892);
  MapPoint& inIndonesia = bali;
  inIndonesia.print();
    
  const MapPoint& cl = krk.furtherFrom( pisa, inIndonesia ); // wybieramy jeden z dwoch punktow zadanych jako arg 1 i 2, taki ktorego odleglosc do obiektu jest wieksza
  cl.print();

  MapPoint mp = MapPoint::inTheMiddle(krk,  cl); // punkt w polowie drogi miedzy dwoma przekazanymi w arg 1 i 2
  mp.print();


}
/* wynik
Point (50.0614N, 19.9383E)
Point (43.8085N, 10.3036E)
Point (8.40952S, 115.189E)
Point (8.40952S, 115.189E)
Point (58.4709S, 95.2506E)*/
