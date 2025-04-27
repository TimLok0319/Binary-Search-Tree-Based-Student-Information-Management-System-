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

	BST *bst = new BST();

	do
	{
		option = menu();
		if (option == 1)
		{
			if (!readFile("student.txt", bst))
			{
				cout << "\n\n<Student.txt is empty!>\n";
			}
			else
				cout << "\n<Student List BST had been created successfully>\n";


			system("pause");
		}
		else if (option == 2)
		{
			cout << "\n<The Deepest Node(s) in BST>\n";

			if (!bst->deepestNode())
				cout << "The BST is Empty!";

			cout << "\n\n";
			system("pause");

		}
		else if (option == 3)
		{
			int order,source;
			if(bst->count == 0)
				cout << "\nThe Student List BST is Empty!\n";

			else
			{
				cout << "Please select the source to display (1-Screen | 2-File): ";
				cin >> source;
				cout << "Please select the order to display (1-Ascending | 2-Descending): ";
				cin >> order;

				if (!bst->display(order,source))
					cout << "\n\nThe Student List BST is Empty!\n";

				system("pause");
			}

		}
		else if (option == 4)
		{
		}
		else if (option == 5)
		{
			cout << "\n<BST Nodes by Level>\n";

			if(!bst->printLevelNodes())
				cout << "\nThe Student List BST is Empty!\n";

			system("Pause");
		}
		else if (option == 6)
		{
			cout << "\n<Below are all the external paths for the tree>\n";

			if (!bst->printPath())
				cout << "\nThe Student List BST is Empty!\n";

			system("Pause");
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

bool readFile(const char* filename, BST* t1)
{
	int studCount=0;
	char tmp;
	char temp[100];

	Student tempStud;
	ifstream readfile;

	readfile.open(filename);
	if (!readfile)
		return false;

	//Ignore character of each line untill "=" adn read the text after it
	while (!readfile.eof())
	{
		readfile.ignore(100, '=');  
		readfile >> tempStud.id;

		readfile.ignore(100, '=');  
		readfile.get(tmp);
		readfile.getline(temp, 100);
		strcpy(tempStud.name, temp);

		readfile.ignore(100, '='); 
		readfile.get(tmp);
		readfile.getline(temp, 100);
		strcpy(tempStud.address, temp);

		readfile.ignore(100, '=');  
		readfile >> tempStud.DOB;

		readfile.ignore(100, '='); 
		readfile >> tempStud.phone_no;

		readfile.ignore(100, '='); 
		readfile >> tempStud.course;

		readfile.ignore(100, '='); 
		readfile >> tempStud.cgpa;

		cout << "\n\nStudent Name: " << tempStud.name;
		cout << "\nID: " << tempStud.id;
		cout << "\nAddress: " << tempStud.address;
		cout << "\nDOB: " << tempStud.DOB;
		cout << "\nCourse: " << tempStud.course;
		cout << "\nPhoneNo: " << tempStud.phone_no;
		cout << "\nCGPA: " << tempStud.cgpa;

		//insert student into BST
		t1->insert(tempStud);
		studCount++;
		
	}

	cout << "\n\n<" << studCount << " student(s) was read and inserted into BST>";
	readfile.close();
}


