#include"BMR.h"
#include<string>
#include <algorithm> // znaczenie wielkosci liter
#include<limits> //dzia³anie cin.fail
#include <stdlib.h>//kolorki
#include <windows.h>//kolorki

void BMR::wylicz()
{
	string plec;
	double waga;
	int wiek;
	int wzrost;
	double aktywnosc;
	double PPM;
	double CPM;

	//info
	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "BMR(Basal Metabolic Rate) oznacza Podstawowa Przemiane Materii. ";
	cout << "\nZa pomoca tego wskaznika ustala sie dzienne zapotrzebowanie kaloryczne.";
	cout << "\nSprawdzenie ilosci kalorii wymaga wyliczenia z konkretnych danych.";
	cout << "\nPodazaj zgodnie z instrukcja!\n\n";
	SetConsoleTextAttribute(hOut, 7);

	cout << "1. Podaj swoja plec(kobieta/mezczyzna): ";
	cin >> plec;

	while (cin.fail() || (plec != "kobieta" && plec !="mezczyzna"))
	{
		cout << "Nie oszukuj! Nie ma takiej plci!" << endl;
		cout << "\nPodaj swoja plec: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> plec;
	}
	
	cout << "\n2. Podaj swoja wage w kilogramach: ";
	cin >> waga;

	while (cin.fail() || waga <= 0)
	{
		cout << "Wprowadzono niepoprawna wartosc!" << endl;
		cout << "\nPodaj swoja wage w kilogramach:";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> waga;
	}

	cout << "\n3. Podaj swoj wzrost w centymetrach: ";
	cin >> wzrost;

	while (cin.fail() || wzrost <= 0)
	{
		cout << "Wprowadzono niepoprawna wartosc!" << endl;
		cout << "\nPodaj swoj wzrost w centymetrach:";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> wzrost;
	}

	cout << "\n4. Podaj swoj wiek w latach: ";
	cin >> wiek;

	while (cin.fail() || wiek <= 0)
	{
		cout << "Wprowadzono niepoprawna wartosc!" << endl;
		cout << "\nPodaj swoj wiek:";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> wiek;
	}


	cout << "\n5. Potrzebna jest rowniez wykonywana akywnosc fizyczna. Wpisz jedna z wartosci ponizej, ktora najbardziej odpowiada Twojemu aktualnemu tybowi zycia: \n";
	cout << "a) brak aktywnosci fizycznej, praca siedzaca - wpisz '1.2'\n";
	cout << "b) mala aktywnosc fizyczna np. praca biurowa, cwiczenia raz na kilka dni - wpisz '1.3' lub '1.4' (w zaleznosci od intensywnosci cwiczen)\n";
	cout << "c) umiarkowana aktywnosc fizyczna np. systematyczne i krotkie cwiczenia kilka razy w tygodniu - wpisz '1.5' lub '1.6' (w zaleznosci od intensywnosci cwiczen)\n";
	cout << "d) duza aktywnosc fizyczna np. codzienne cwiczenia i ciezka praca fizyczna - wpisz '1.7' lub '1.8' (w zaleznosci od intensywnosci cwiczen)\n";
	cout << "e) zawodowi sportowcy i osoby trenujace wyczynowo - wpisz '1.9', '2', '2.1' lub '2.2' (w zaleznosci od intensywnosci cwiczen)\n";
	cout << "Intensywnosc aktywnosci fizycznej: ";
	cin >> aktywnosc;

	
	
	while (cin.fail() || aktywnosc != 1.2 && aktywnosc != 1.3 && aktywnosc != 1.4 && aktywnosc != 1.5 && aktywnosc != 1.6 && aktywnosc != 1.7 && aktywnosc != 1.8 && aktywnosc != 1.9 && aktywnosc != 2 && aktywnosc != 2.1 && aktywnosc != 2.2)
	{
		cout << "Wprowadzono niepoprawna wartosc!" << endl;
		cout << "\nPodaj odpowiednia wartosc: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> aktywnosc;
	}

	system("cls");

	//obliczanie PPM i CPM wg odpowiedniej plci
	if (plec.compare("kobieta") == 0)
	{
		PPM = 665.09 + (9.56 * waga) + (1.85 * wzrost) - (4.76 * wiek);
		CPM = PPM * aktywnosc;

		cout << "\nWartosc kaloryczna jaka powinnas spozywac kazdego dnia wynosi " << CPM << " kcal.\n" << endl;

	}
	if (plec.compare("mezczyzna") == 0)
	{
		PPM = 66.47 + (13.7 * waga) + (5.0 * wzrost) - (6.76 * wiek);
		CPM = PPM * aktywnosc;

		cout << "\nWartosc kaloryczna jaka powinienes spozywac kazdego dnia wynosi " << CPM << " kcal.\n" << endl;
	}
}