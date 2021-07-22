/* W zadaniu nalezy skonstruowac logiczna hierarchie klas na podstawie
 * ponizszego programu. Prosze zauwazyc, ze PredkoscMaksymalna to osobna
 * klasa.
 * 
 * Prosze nie implementowac pol w klasach bazowych jezeli nie sa one tam
 * wymagane (na podstawie ponizszego kodu).
 * 
 * Jezeli ktos chce, to uzywanie biblioteki standardowej jest dozwolone 
 * bez ograniczen. 
 * 
 * Trzeba sie zastanowic jak za pomocą funkcji pomocniczej zaimplemenetować
 * "dziedziczenie" operatora wypisywania, (prosze nie kombinowac z przyjazniami).
 */

#include <iostream>
#include "Pojazdy.h"

void sprawdzWskaznik(const void* p) {
	if ( p == 0 )
		std::cout << "null ptr" << std::endl;
	else
		std::cout << "ok ptr" << std::endl;
}

void wypiszRodzaj(const Pojazd* poj) {
	if ( poj )
		std::cout << "Typ pojazdu: " << (*poj) << std::endl;
	else
		std::cout << "Pojazd nierozpoznany." << std::endl;
}

int main() {
	PredkoscMaksymalna prMax(140);
	std::cout << "Przykladowa predkosc maksymalna = " << prMax << std::endl;
	
	Samochod * ss = new Samochod( prMax );
	sprawdzWskaznik(dynamic_cast<PojazdLadowy*>(ss));
	wypiszRodzaj(ss);
	
	Motorowka * mm = new Motorowka( PredkoscMaksymalna(50) );
	sprawdzWskaznik(dynamic_cast<const PojazdLadowy*>(mm));
	wypiszRodzaj(mm);

	const Rower rr = Rower();
	sprawdzWskaznik(dynamic_cast<const PojazdLadowy*>(&rr));
	wypiszRodzaj(&rr);

	std::cout << "--------" << std::endl;

	Pojazd * a =  new Amfibia( PredkoscMaksymalna(80), PredkoscMaksymalna(40) );
	const Motorowka * m = dynamic_cast<Motorowka*>(a);
	const Samochod * s = dynamic_cast<Samochod*>(a);  
	const Rower * r = dynamic_cast<Rower*>(a);  
	sprawdzWskaznik(m);
	wypiszRodzaj(m);
	sprawdzWskaznik(s);
	wypiszRodzaj(s);
	sprawdzWskaznik(r);
	wypiszRodzaj(r);

	std::cout << "Na ladzie: v_max = " << s->predkoscMaksymalna() << std::endl;
	std::cout << "W wodzie: v_max = " << m->predkoscMaksymalna() << std::endl;

	Amfibia * aa = dynamic_cast<Amfibia*>(a);
	std::cout << "Na ladzie: v_max = " << aa->predkoscMaksymalna_Lad() << std::endl;
	std::cout << "W wodzie: v_max = " << aa->predkoscMaksymalna_Woda() << std::endl;

	delete ss;
	delete mm;
	delete a;
	
}

/* wynik
Przykladowa predkosc maksymalna = 140km/h
ok ptr
Typ pojazdu: Samochod
null ptr
Typ pojazdu: Motorowka
ok ptr
Typ pojazdu: Rower
--------
ok ptr
Typ pojazdu: Amfibia
ok ptr
Typ pojazdu: Amfibia
null ptr
Pojazd nierozpoznany.
Na ladzie: v_max = 80km/h
W wodzie: v_max = 40km/h
Na ladzie: v_max = 80km/h
W wodzie: v_max = 40km/h
*/