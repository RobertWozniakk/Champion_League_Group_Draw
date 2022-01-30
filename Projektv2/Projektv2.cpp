#include <iostream>
#include<fstream>//potrzebny do czytania z pliku
#include<string> // string potrzebny jest do instrukcji getline
#include <random> // potrzebny do losowania
#include<stdlib.h> //biblioteka ta pozwala na skorzystanie z funkcji exit()
using namespace std;
void los(string A[], string B[]) // funkcja wypisujaca pary i obslugujaca menu
{
	int x = 0; //zmienna pomocnicza okreslajaca numer elementu w tablicy
	cout << "Witam zgromadzonych państwa na losowaniu fazy pucharowej piłkarskiej Ligi Mistrzów !" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "1. Naciśnij dowolny przycisk by poznać parę" << endl;
	cout << "2. Naciśnij 2 by wyjść z programu" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	char q;
	cout << "Nie możemy doczekać się poznania pary numer jeden" << endl;
	cin >> q;
	if (q == '2')
		exit(2); // wychodzi z programu
	else
	{
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;
	}
	
	cin >> q;
	if (q == '2')
		exit(2);
	else
	{
		cout << "Poznajmy drugą parę" << endl;
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;	
	}
	cin >> q;
	if (q == '2')
		exit(2);
	else
	{
		cout << "Para numer trzy prezentuje się następująco" << endl;
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;
	}
	cin >> q;
	if (q == '2')
		exit(2);
	else
	{
		cout << "Oto czwarte zestawienie" << endl;
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;
	}
	cin >> q;
	if (q == '2')
		exit(2);
	else
	{
		cout << "Piąta para" << endl;
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;
	}
	cin >> q;
	if (q == '2')
		exit(2);
	else
	{
		cout << "To już 10 drużyn zna już swoich rywali, poznajmy kolejną dwójkę" << endl;
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;
	}
	cin >> q;
	if (q == '2')
		exit(2);
	else
	{
		cout << "Oto siódma para, a zatem znamy już rozstawienie pucharowe wszystkich drużyn" << endl;
		cout << A[x] << " vs " << B[x] << endl;
		q = 0;
		x++;
	}
	cout << "Ostatnie zestawienie na liście" << endl << A[x] << " vs " << B[x] << endl;
		
}
int main()
{
	setlocale(LC_CTYPE, "Polish"); //potrzebne do wyswietlenia polskich znakow w konsoli
	string T[16]; //tablica wszystkich druzyn
	string T1[8]; // druzyny zajmujace 1 miejsce
	string T2[8]; //druzyny zajmujace 2 miejsce 
	int a = 0; //zmienna pomocnicza do dodania linii dokumentu do tablicy
	ifstream File;
	File.open("druzyny.txt"); 
	if (File.is_open())     //otwieramy plik, standardowe operacje
	{
		string linia;
		while (getline(File, linia))
		{
			T[a] = linia;
			a++;
		}
	}
	// ^^^^^^^ dodawanie dokumentu tekstowego do tablicy
	int k = 0;
	int l = 0;
	//^^^ zmienne pomocnicze potrzebne, gdyz tablice do ktorych bedziemy rozkladac druzyny maja mniejszy rozmiar od poczatkowej
	for (int i = 0; i < 16; i++)
	{
		if (T[i].find("1")) //jesli jest 1 to znaczy ze zajela pierwsze miejsce, zatem wedruje do odpowiedniej tabeli
		{
			T2[k] = T[i];
			k = k + 1;
		}
		if (T[i].find("2"))//analogicznie
		{
			T1[l] = T[i];

			l = l + 1;
		}

	}
	random_device rd;
	default_random_engine generator(rd()); // generator liczb pseudolosowych
	int pomoc = 0; // zmienna pomocnicza do wyjscia z while
	while (pomoc == 0)
	{
		if (T1[0][T1[0].length() - 1] != T2[0][T2[0].length() - 1] && T1[0][2] != T2[0][2]
			&& T1[1][T1[1].length() - 1] != T2[1][T2[1].length() - 1] && T1[1][2] != T2[1][2]
			&& T1[2][T1[2].length() - 1] != T2[2][T2[2].length() - 1] && T1[2][2] != T2[2][2]
			&& T1[3][T1[3].length() - 1] != T2[3][T2[3].length() - 1] && T1[3][2] != T2[3][2]
			&& T1[4][T1[4].length() - 1] != T2[4][T2[4].length() - 1] && T1[4][2] != T2[4][2]
			&& T1[5][T1[5].length() - 1] != T2[5][T2[5].length() - 1] && T1[5][2] != T2[5][2]
			&& T1[6][T1[6].length() - 1] != T2[6][T2[6].length() - 1] && T1[6][2] != T2[6][2]
			&& T1[7][T1[7].length() - 1] != T2[7][T2[7].length() - 1] && T1[7][2] != T2[7][2]
			) //zestaw warunkow by nasze potasowanie bylo takie jak chcemy
		{
			for (int i = 0; i < 8; i++)
			{
				if (T1[i] == "1_A_Man_City_E")
					T1[i] = "Manchester City";
				if (T1[i] == "1_B_Liverpool_E")
					T1[i] = "Liverpool FC";
				if (T1[i] == "1_C_Ajax_Amsterdam_N")
					T1[i] = "Ajax Amsterdam";
				if (T1[i] == "1_D_Real_Madryt_S")
					T1[i] = "Real Madryt";
				if (T1[i] == "1_E_Bayern_G")
					T1[i] = "Bayern Monachium";
				if (T1[i] == "1_F_Man_Utd_E")
					T1[i] = "Manchester United";
				if (T1[i] == "1_G_Lille_F")
					T1[i] = "LOSC Lille";
				if (T1[i] == "1_H_Juventus_I")
					T1[i] = "Juventus Turyn";

			}
			for (int i = 0; i < 8; i++)
			{
				if (T2[i] == "2_A_PSG_F")
					T2[i] = "Paris Saint Germain";
				if (T2[i] == "2_B_Atletico_Madryt_S")
					T2[i] = "Atletico Madryt";
				if (T2[i] == "2_C_Sporting_CP_P")
					T2[i] = "Sporting CP";
				if (T2[i] == "2_D_Inter_I")
					T2[i] = "Inter FC";
				if (T2[i] == "2_E_Benfica_P")
					T2[i] = "SL Benfica";
				if (T2[i] == "2_F_Villareal_S")
					T2[i] = "Villareal";
				if (T2[i] == "2_G_RB_Salzburg_A")
					T2[i] = "Red Bull Salzburg";
				if (T2[i] == "2_H_Chelsea_E")
					T2[i] = "Chelsea FC";
				//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ zmieniamy nazwy druzyn na przyjemniejsze dla oka
			}
			los(T1, T2); // wszystko sie zgadza , mamy wylosowane druzyny w odpowiednim formacie mozna przejsc do ladnego wypisania
			pomoc = 3; // moze byc cokolwiek rozne od 0 
		}
		else
			shuffle(T2, T2 + 8, generator); // bardzo wazne, tasowanie druzyn w przypadku nie spelniania warunkow
	}
	system("pause");
}





