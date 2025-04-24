#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"

using namespace std;

bool readFile(const char *, BST *);
int menu();


int main() {

	int option;

	do
	{
		option = menu();
		if (option == 1)
		{

		}
		else if (option == 2)
		{
		}
		else if (option == 3)
		{
		}
		else if (option == 4)
		{
		}
		else if (option == 5)
		{
		}
		else
		{
		}

	} while (option != 7);

	system("pause");
	return 0;
}

int menu()
{
	int option;

	cout << "\n<Student Record in BST>";
	cout << "\n\nPlease Select from the following menu";
	cout << "\n(1)	Read data to BST\n(2)	Print deepest nodes\n(3)	Display student\n(4)	Clone Subtree\n(5)	Print Level Nodes\n(6)	Print Path\n(7)	Exit";
	cout << "\n\nOption: ";
	cin >> option;

	return option;
}



