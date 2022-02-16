#include <iostream>
using namespace std;

struct patient
{
	string name;
	bool sta;
};

patient allP[20][5];
int pNum[20]{};

void run();
void list();
void add();
void printAll();
void nextP();
void shiftDown(int sp);
void shiftUp(int sp);


int main()
{
	run();
	return 0;
}

void run()
{
	int ch{};
	while (ch != 4)
	{
		list();
		cin >> ch;
		if (ch == 1)
			add();
		else if (ch == 2)
			printAll();
		else if (ch == 3)
			nextP();
		else if (ch == 4)
			cout << "\nStay in peace\a\n";
		else
			cout << "Wrong chouse\a\n";
	}
	return;
}

void list()
{
	
	cout << "\n1) Add new patient\n";
	cout << "2) Print all patients\n";
	cout << "3) Get next patient\n";
	cout << "4) Exit\n";
	cout << "Enter your choice:\n";
}

void shiftDown(int sp)
{
	for (int i{ 4 }; i >= 0; i--)
		allP[sp][i] = allP[sp][i - 1];
}
void shiftUp(int sp)
{
	for (int i{}; i < 5; i++)
		allP[sp][i] = allP[sp][i + 1];
}

void add()
{
	cout << "Enter specialization, name, statis: \n";
	int sp{};
	cin >> sp;
	if (sp > 0 && sp < 21)
	{
		sp--;
		if (pNum[sp] == 5)
			cout << "This specialization is full.\nWE can't take the patient\n\a";
		else
		{
			pNum[sp]++;
			string n;
			bool sta;
			cin >> n >> sta;
			if (sta)
			{
				shiftDown(sp);
				allP[sp][0].name = n;
				allP[sp][0].sta = sta;
			}
			else
			{
				allP[sp][pNum[sp] - 1].name = n;
				allP[sp][pNum[sp] - 1].sta = sta;
			}
		}
	}
	else
		cout << "Wrong specialization.\n\a";
	return;
}

void printAll()
{
	cout << "*****************************\n";
	for (int i{}; i < 20; i++)
		if (pNum[i])
		{
			cout << "There are " << pNum[i] << " pationts in specialization " << i + 1 << "\n";
			for (int j{}; j < pNum[i]; j++)
			{
				cout << allP[i][j].name;
				cout << (allP[i][j].sta ? " urgent\n" : " regular\n");
			}
		}
	cout << "*****************************\n";
}

void nextP()
{
	cout << "Enter specialization : ";
	int sp{};
	cin >> sp;
	if (sp > 0 && sp < 21)
	{
		sp--;
		cout << allP[sp][0].name << (allP[sp][0].sta ? " urgent\n" : " regular\n");
		shiftUp(sp);
		pNum[sp]--;
	}
	else
		cout << "Wrong specialization.\n\a";
}

/*
1
3 ali 1
1
3 mo 1
1
3 ab 1
1
3 zed 1
1
3 asd 1
2




*/