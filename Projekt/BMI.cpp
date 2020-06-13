#include"BMI.h"	
#include <stdlib.h>//kolorki
#include <windows.h>//kolorki


void BMI::oblicz()
{
	double masa;
	double wzrost;
	double BMI;

	//Info
	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "BMI(Body Mass Index) oznacza Wskaznik Masy Ciala.";
	cout << "\nMozna go bardzo latwo obliczyc - wystarczy podac kilka istotnych wartosci.";
	cout << "\nPostepuj zgodnie z instrukcja!\n\n";
	SetConsoleTextAttribute(hOut, 7);


	//podanie danych do obliczen przez uzytkownika
	cout << "1. Podaj swoja aktualna mase ciala w kilogramach: ";
	cin >> masa;

	while (cin.fail() || masa<=0)
	{
		cout << "Podano niepoprawna wartosc!" << endl;
		cout << "\nPodaj swoja wage: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> masa;
	}
	cout << endl << "2. Podaj swoj wzrost w metrach: ";
	cin >> wzrost;

	while (cin.fail() || wzrost <= 0)
	{
		cout << "Podano niepoprawna wartosc!" << endl;
		cout << "\nPodaj swoj wzrost: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> wzrost;
	}

	cout << endl;

	system("cls");

	//obliczanie i wynik s³owny dla konkretnych danych
	if (masa > 0 && wzrost > 0)
	{
		BMI = masa / (wzrost * wzrost);
		BMI = truncf(BMI * 10) / 10; //zamiana z double na jedn¹ po przecinku
		cout << "Twoje BMI na dzien dzisiejszy wynosi: " << BMI << ", co oznacza ";
		if (BMI < 18.5)
		{
			cout << "niedowage!\nZaleca sie przyjmowanie wiekszej ilosci kalorycznej dziennie!\n" << endl;
		}
		if (18.5 <= BMI && BMI<= 24.9)
		{
			cout << "prawidlowa wage ciala!\nSwietna robota! Oby tak dalej!\n" << endl;
		}
		if (24.9 < BMI && BMI<= 29.9)
		{
			cout << "lekka nadwage!\nNie jest zle, ale moze byc lepiej! Zaleca sie zmniejszenie dziennej porcji kalorii lub zwiekszenie aktywnosci fizycznej! \nPamietaj jednak, ze nie nalezy obnizac swojego zapotrzebowania kalorycznego o wiecej niz 500kcal dziennie!" << endl;
		}
		if (29.9 < BMI)
		{
			cout << "nadwage!!!\nNiestety, ale sytuacja wyglada zle! Najlepiej bedzie skontaktowac sie ze specjalista i wspolnie ustalic plan diety oraz ilosci aktywnosci fizycznej.\n" << endl;
		}
	}
}