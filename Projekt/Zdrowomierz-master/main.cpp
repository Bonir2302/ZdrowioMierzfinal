#include "BMI.h"
#include "BMR.h"
#include "funkcje.h"

using namespace std;


int main()
{

	int opcja;

	cout << "**************MENU GLOWNE*************";
	cout << "\nWitaj w aplikacji 'nazwa'! Skoro tu jestes to znaczy, ze zaczynasz dbac o swoje codzienne zdrowie!";
	cout << "\nPierwszy krok w strone lepszej jakosci zycia wykonany - teraz malymi kroczkami do przodu ;)";
	cout << "\n\nWybierz opcje:";
	cout << "\n1. Obliczanie BMI";
	cout << "\n2. Obliczanie BMR";
	cout << "\n3. Twoj dziennik zywnosci";
	cout << "\n4. Wyjscie";
	cout << "\n######################################";
	cout << "\n\nNumer opcji:";
	cin >> opcja;

	while (true)
	{
		//zabezpieczenie
		while (opcja < 1 || opcja>4)
		{
			cout << "Nie oszukuj! Nie ma takiej opcji!" << endl;
			cout << "\nNumer opcji:";
			cin >> opcja;
		}

		system("cls"); //czyszczenie


		//kolejne opcje
		if (opcja == 1)
		{
			BMI mojeBMI;

			mojeBMI.oblicz();

			//cout << "Wroc do menu(dowolny przycisk)";
		}

		if (opcja == 2)
		{
			BMR mojeBMR;

			mojeBMR.wylicz();
		}

		if (opcja == 3)
		{
			string posilek;
			double kcal;
			double il{};

			posilek = wczytajposilek();
			kcal = wczytajkalorie(il);

			wpiszdopliku(posilek, kcal);

		}

		if (opcja == 4)
		{
			return 0;
		}

		system("pause");
		system("cls");
		cout << "**************MENU GLOWNE*************";
		cout << "\nWitaj w aplikacji 'nazwa'! Skoro tu jestes to znaczy, ze zaczynasz dbac o swoje codzienne zdrowie!";
		cout << "\nPierwszy krok w strone lepszej jakosci zycia wykonany - teraz malymi kroczkami do przodu ;)";
		cout << "\n\nWybierz opcje:";
		cout << "\n1. Obliczanie BMI";
		cout << "\n2. Obliczanie BMR";
		cout << "\n3. Twoj dziennik zywnosci";
		cout << "\n4. Wyjscie";
		cout << "\n######################################";
		cout << "\n\nNumer opcji:";
		cin >> opcja;
	}


}
