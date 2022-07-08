#include <iomanip>
#include <iostream>   
#include <cstdlib>  
#include <ctime>    
#include <conio.h> 
#include <cstring>  
#include <windows.h>


#pragma warning(disable:4996)
using namespace std;

#include "struct.cpp"
#include "ui.cpp"
#include "source.cpp"
#include "LoginSource.cpp"


int main()
{

	FILE* fp;

	fp = fopen("config.ini", "r+");

	fscanf(fp, "%s", &FNS);
	fscanf(fp, "%s", &FNL);

	fclose(fp);

	int l = 0;
	l = loadlogs();
	login(&l);

	int n = 0;

	while (1)
	{

		switch (meniu())
		{
		case 49:  insert(&n); system("pause"); break;
		case 50:  show(n); system("pause"); break;
		case 51:  search(n); system("pause"); break;
		case 52:  editinfo(n); system("pause"); break;
		case 53:  save(n); system("pause"); break;
		case 54:  n = load(); system("pause"); break;
		case 55:  delinfo(); system("pause"); break;
		case 27:  exit(0);
		}

	}



	return 0;
}
