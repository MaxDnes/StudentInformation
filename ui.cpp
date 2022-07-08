int meniu()
{
	system("cls");

	cout << "\n\n\t *** MENIU STUDENT ***" << endl;
	cout << "\t  1. Insert STUDENT  " << endl;
	cout << "\t  2. Show STUDENT  " << endl;
	cout << "\t  3. Cautare STUDENT" << endl;
	cout << "\t  4. Editare info STUDENT" << endl;
	cout << "\t  5. Save info STUDENT" << endl;
	cout << "\t  6. Load info STUDENT" << endl;
	cout << "\t  7. Delete all saved info STUDENT" << endl;
	cout << "\tESC. EXIT  " << endl;

	return _getch();
}

int loginmeniu()
{
	system("cls");

	cout << "\n\n\t *** MENIU LOGARE ***" << endl;
	cout << "\t  1. Login in account existent" << endl;
	cout << "\t  2. Creeare/inregistrare account nou" << endl;
	cout << "\tESC. EXIT  " << endl;

	return _getch();
}