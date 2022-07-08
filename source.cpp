void save(int n)
{
	FILE* fp;

	if ((fp = fopen(FNS, "w+b")) == NULL)
	{
		cout << " Error:: W+B " << endl;
		system("pause");
		return;
	}

	fwrite(S, sizeof(stud), n, fp);

	fclose(fp);

	cout << "Datele au fost salvate cu succes!" << endl;
	system("pause");
	system("cls");
}

void line1()
{
	cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)203 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)203 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)203 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)203 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
}

void line2()
{
	cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)206 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185 << endl;
}

void line3()
{
	cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)202 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)202 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)202 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)202 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
}



double calcmed(int n, int nrtot)
{
	int s = 0;

	for (int i = 0; i < nrtot; i++)
	{
		s += S[n].note[i];
	}

	return s / double(nrtot);
}

void insert(int* n)
{
	do
	{
		system("cls");
		cout << " Student [" << (*n) + 1 << "]" << endl;

		cout << " Enter nume  :: "; cin >> S[*n].nume;
		cout << " Enter ani   :: "; cin >> S[*n].ani;
		cout << " Enter note  for  " << S[*n].nume <<'\n' << endl;

		do
		{
			cout << "Nota [" << S[*n].nrnote+1 << "] = "; cin >> S[*n].note[ S[*n].nrnote ];
			S[*n].nrnote++;
			cout << " ESC - exit,  any key ...." << endl;
		} while (_getch() != 27);

		S[*n].media = calcmed(*n, S[*n].nrnote);

		system("cls");

		(*n)++;

		cout << " ESC - exit,  any key ...." << endl;
	} while (_getch() != 27);
	save(*n);
}



void show(int n)
{

	int x = 2, in = 0, sf = x;
	bool EXIT = 0;

	if (n > 0)
	{
		while (1)
		{
			system("cls");

			line1(); cout << (char)186 << setw(5) << "ID" << (char)186 << setw(15) << "NUME" << (char)186 << setw(10) << "ANI" << (char)186 <<setw(20) << "NOTE" <<char(186)<<setw(10)<<"MEDIA" <<(char)186<< endl; line2();

			for (int i = in; i < sf; i++)
			{
				cout << (char)186 << setw(5) << i + 1
					<< (char)186 << setw(15) << S[i].nume
					<< (char)186 << setw(10) << S[i].ani
					<< (char)186;
				for (int j = 0; j < S[i].nrnote; j++)
				{
					cout << ' ' << S[i].note[j];
				}
				cout << setw(21 - S[i].nrnote*2) << (char)186 << setw(10) << S[i].media <<(char)186 << endl;
				if (i == sf - 1) line3();
				else line2();
			}
			

			switch (_getch())
			{
			case 43: in += x; sf += x; if (sf > n) { in = n - 2; sf = n; } break;
			case 45: in -= x; sf -= x; if (in < 0) { in = 0;   sf = x; } break;
			case 27: EXIT = true;
			}
			system("pause");
			if (EXIT) break;
		}
	}
	else
	{
		system("cls");
		cout << " Nu sunt studenti pentru afisare" << endl;
	}
}

void showinfo(int poz)
{
	cout << "Am gasit informatie cu succes despre: " << S[poz].nume << endl;

	line1(); cout << (char)186 << setw(5) << "ID" << (char)186 << setw(15) << "NUME" << (char)186 << setw(10) << "ANI" << (char)186 << setw(20) << "NOTE" << char(186) << setw(10) << "MEDIA" << (char)186 << endl; line2();

	cout << (char)186 << setw(5) << poz + 1
		<< (char)186 << setw(15) << S[poz].nume
		<< (char)186 << setw(10) << S[poz].ani
		<< (char)186;
	for (int j = 0; j < S[poz].nrnote; j++)
	{
		cout << ' ' << S[poz].note[j];
	}
	cout << setw(21 - S[poz].nrnote * 2) << (char)186 << setw(10) << S[poz].media << (char)186 << endl;
	line3();
}

void search(int n)
{
	system("cls");
	if (n > 0)
	{
		int poz;
		cout << "Introduceti ID-ul studentului cautat:\n"; cin >> poz;

		poz -= 1;

		if (poz < 0)
		{
			cout << "Ne pare rau,n-am gasit asfel de studenti doriti sa cautati din nou? \n(apasati orice tasta pentru a iesi sau y/Y pentru a cauta alt student)\n";
			if (_getch() == 89 || _getch() == 121) search(n);
		}
		else
		{
			showinfo(poz);
		}
	}
	else
	{
		system("cls");
		cout << " Nu sunt studenti pentru afisare" << endl;
	}
}


void editinfo(int n)
{
	if (n > 0)
	{
		int poz;
		char name[256];
		system("cls");
		cout << "Introduceti ID-ul studentului cautat: \n";
		cin >> poz;
		poz -= 1;
		system("pause");
		if (poz >= 0)
		{
			showinfo(poz);
			system("pause");
			do
			{
				cout << "\n\n\n";
				cout << "Ce doriti sa editati:\n1.Numele \n2.Varsta \n3.Notele \nESC pentru a anula actiunea." << endl;
				if (_getch() == 49)
				{
					cout << "Introduceti numele nou:"; cin >> name;

					strcpy(S[poz].nume, name);
				}
				else if (_getch() == 50)
				{
					int* v = new int;
					cout << "Introduceti varsta studentului:"; cin >> *v;

					S[poz].ani = *v;
				}
				else if (_getch() == 51)
				{
					int* v = new int[25];
					cout << "Note curente:" << endl;
					for (int i = 0; i < S[poz].nrnote; i++)
					{
						cout << setw(3) << S[poz].note[i];
					}
					cout << "\nCe actiuni doriti sa faceti:\n1.Inlocuirea unei note\n2.Adaugarea unei note\n" << endl;
					switch (_getch())
					{
					case 49:
					{
						int nota;
						bool present = false;
						int pozn;
						
							cout << "Ce nota doriti sa inlocuiti?"<<endl; cin >> nota;
							for (int i = 0; i < S[poz].nrnote; i++)
							{
								if (nota == S[poz].note[i])
								{
									present = true;
									pozn = i;
								}
							}
							if (present) cout << "Nota este prezenta!" << endl;
							else cout << "Ne pare rau nu exista o astfel de nota incercati din nou sau apasati ESC pentru a iesi" << endl;
						
						if (present)
						{
							cout << "Ce nota o va inlocui pe nota " << S[poz].note[pozn]<<endl; cin >> nota;
							S[poz].note[pozn] = nota;
						}
						S[poz].media=calcmed(poz, S[poz].nrnote);
						break;
					}
					case 50:
					{
						int i = 0;
						int n;
						cout << "Adaugarea notelor " << endl;
						do
						{
							cout << "Nota [" << S[poz].nrnote+i << "] = "; cin >> S[poz].note[S[poz].nrnote + i];
							i++;
							cout << " ESC - exit,  any key ...." << endl;
						} while (_getch() != 27);
						S[poz].nrnote = S[poz].nrnote + i;
						S[poz].media = calcmed(poz, S[poz].nrnote);
						break;
					}
					}
					
				}
				cout << " ESC - exit,  any key ...." << endl;
			} while (_getch() != 27);
		}
		save(n);
	}
	else
	{
		system("cls");
		cout << " Nu sunt studenti pentru afisare" << endl;
		system("pause");
	}
}

void delinfo()
{
	char conf[256];
	do
	{
		system("cls");
		cout << "Pentru a confirma actiunea de stergere a datelor salvate scrieti CONFIRM" << endl;
		cin >> conf;
		if (strcmp(conf, "CONFIRM") == 0)
		{

			FILE* fp;

			if ((fp = fopen(FNS, "w+b")) == NULL)
			{
				cout << " Error:: W+B " << endl;
				system("pause");
				return;
			}

			fwrite(S, sizeof(stud), 0, fp);

			fclose(fp);
			return;
		}
		else
		{
			return;
		}
	} while (_getch() != 27 || _getch() != 110 || getch() != 78 || getch() != 121 || getch() != 89);
}


int load()
{
	FILE* fp;

	if ((fp = fopen(FNS, "r+b")) == NULL)
	{
		cout << " Error:: r+B " << endl;
		system("pause");
		return 0;
	}

	int n = fread(S, sizeof(stud), 100, fp);

	fclose(fp);

	cout << "Datele au fost incarcate cu succes!" << endl;
	system("pause");
	system("cls");

	return n;
}