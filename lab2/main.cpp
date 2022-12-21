#include "stack.h"
#include "queue.h"
#include "cyclelist.h"
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	CycleList<int>* list = new CycleList<int>();
	int n, k;

	cout << "������� ����� ���������:\n> ";
	cin >> n;
	cout << "������� ��������:\n> ";
	cin >> k;
	for (int i = 0; i < n; i++) {
		list->insert(i + 1);
	}

	int cur = (k - 1) % n;

	while (n != 1) {
		list->deleteElement(cur);
		n = list->getSize();
		cur = (cur + k - 1) % n;
	}

	cout << "��������� ���������� ������� = " << list->getValue(0);
	delete list;

	return 0;
	/*CycleList<char>* list = new CycleList<char>();
	while (1) {
		system("cls");
		cout << "��������� �������: ";
		list->printState();

		cout << "\n�������� ��������: \n1) �������� ������� � ����� ������\n2) �������� ������� � ������\n3) ������� �������\n4) �����\n\n> ";
		int choise;
		cin >> choise;
		if (choise == 4) {
			break;
		}
		if (choise == 1) {
			system("cls");
			char a;
			cout << "������� �������:\n> ";
			cin >> a;
			list->insert(a);
			system("pause");
		}
		if (choise == 2) {
			system("cls");
			char a;
			int ind;
			cout << "������� �������:\n> ";
			cin >> a;
			cout << "������� ������:\n> ";
			cin >> ind;
			list->insert(a,ind);
			system("pause");
		}
		if (choise == 3) {
			system("cls");
			int ind;
			cout << "������� ������:\n> ";
			cin >> ind;
			list->deleteElement(ind);
			system("pause");
		}
	}

	delete list;
	return 0;
}	*/

/*int main()
{
	setlocale(LC_ALL, "Russian");

	Queue<char> *q = new Queue<char>();
	while (1) {
		system("cls");
		cout << "��������� �������: ";
		q->printState();

		cout << "\n�������� ��������: \n1) �������� ������� � �������\n2) ����� ������� �� �������\n3) �����\n\n> ";
		int choise;
		cin >> choise;
		if (choise == 3) {
			break;
		}
		if (choise == 1) {
			system("cls");
			char a;
			cout << "������� �������:\n> ";
			cin >> a;
			q->push(a);
		}
		if (choise == 2) {
			system("cls");
			char a = q->pop();
			cout << "������� �������:\n> " << a << endl;
			system("pause");
		}
	}
	delete q;
	return 0;*/
}