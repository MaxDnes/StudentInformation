void savelogs(int l)
{
	FILE* fp;

	if ((fp = fopen(FNL, "w+b")) == NULL)
	{
		cout << " Error:: W+B " << endl;
		system("pause");
		return;
	}

	fwrite(U, sizeof(user), l, fp);
	
	fclose(fp);

}

bool loginexist(int* l);
void login(int *l);

bool checkemail(const char mail[256],int *l)
{
	bool k=false;
	int i = 0;
	do
	{
		if (strcmp(U[i].email, mail) == 0) return 1;
		i++;
	} while (i < *l);
	cout << "\tESC. EXIT  " << endl;
	cout << "\t Any - key continuare de incercare de logare" << endl;
	cout << "\t Email gresit!" << endl;
	switch (_getch())
	{
	case 27: login(l); break;
	default: loginexist(l);
	}

}

char *passenter()
{
	char pass[256];
	int key,i = 0;
	bool K = true;
	system("cls");
	cout << " \n\n\t Introduceti parola :: ";

	while (K)
	{

		key = _getch();

		if (key == 13) { pass[i] = '\0'; K = false; }
		else if (key == 8)
		{
			if (i > 0) { cout << "\b \b"; i--; }
		}
		else {
			pass[i] = key;

			cout << "*";

			i++;
		}
	}

	return pass;
}

char* getpass(const char mail[256],int l)
{
	char pass[256];
	int poz;
	for (int i = 0; i < l; i++)
	{
		if (strcmp(U[i].email, mail) == 0) { return U[i].password; }
	}
	
}
bool registernewacc(int* l);
void setpass(int *l)
{
	char tmp[256];
	do
	{
		strcpy(U[*l].password, passenter());
		strcpy(tmp, passenter());
		if (strcmp(U[*l].password, tmp) != 0) 
		{ 
			cout << "\n\tParolele difera va rugam introduceti datele din nou!" << endl;
			cout << "\tESC. EXIT  " << endl;
			cout << "\t Any - key continuare de incercare de creeare account" << endl;
			switch (_getch())
			{
			case 27: login(l); break;
			default: registernewacc(l);
			}

			system("pause"); registernewacc(l); }
		else { cout << "\nAccountul a fost inregistrat cu succes!"; system("pause"); }
		
	} while (strcmp(U[*l].password, tmp) != 0);
}

bool registernewacc(int *l) 
{
	system("cls");
	bool k = false;
	cout << "Introduceti numele:";
	cin.getline(U[*l].name, 256);
	do
	{
		system("cls");
		cout << "\nIntroduceti emailul accountului:";
		cin.getline(U[*l].email, 256);
		system("pause");
		if (*l > 0)
		{
			for (int i = 0; i < *l; i++)
			{
				if (strcmp(U[i].email, U[*l].email) == 0) { cout << "\nDeja exista un account inregistrat cu acest email va rugam introduceti datele din nou!" << endl; system("pause"); registernewacc(l); }
				else k = true;
			}
		}
		else k = true;
	} while (k != true);
	setpass(l);
	(*l)++;
	savelogs(*l);
	return 1; 
}

bool loginexist(int *l) 
{
	bool z;
	if (*l >= 1)
	{
		char tmp[256];
		char tcmp[256];
		int c = 0;
		do
		{
			system("cls");
			cout << "\nIntroduceti emailul utilizatorului:" << endl;
			cin.getline(tmp, 256);
		} while ( !checkemail(tmp,l));
		do
		{
			strcpy(tcmp, passenter());
			if (strcmp(getpass(tmp, *l), tcmp) == 0)
			{
				cout << "\nLogare cu succes!" << endl;
				system("pause");
				return 1;
			}
			else { cout << "\nParola gresita!" << endl; c++; system("pause"); }
		} while (c < 3);
		cout << "Prea multe incercari de parola gresita!" << endl;
		exit(0);
	}
	else
	{
		cout << "Nu exista accounturi inregistrate pentru a intra creeati una account nou!" << endl;
		z = false;
		system("pause");
	}
	
	return z;
}

void login(int *l)
{
	bool logged_in = false;
	do
	{
		switch (loginmeniu())
		{
		case 49: logged_in = loginexist(l); break;
		case 50: logged_in = registernewacc(l); break;
		case 27: exit(0);
		}
	} while (logged_in != true);
}

int loadlogs()
{
	FILE* fp;

	if ((fp = fopen(FNL, "r+b")) == NULL)
	{
		cout << " Error:: r+B " << endl;
		system("pause");
		return 0;
	}

	int l = fread(U, sizeof(user), 100, fp);

	fclose(fp);

	return l;
}


