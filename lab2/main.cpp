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

	cout << "Введите число элементов:\n> ";
	cin >> n;
	cout << "Введите интервал:\n> ";
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

	cout << "Последний оставшийся элемент = " << list->getValue(0);
	delete list;

	return 0;
	/*CycleList<char>* list = new CycleList<char>();
	while (1) {
		system("cls");
		cout << "Состояние очереди: ";
		list->printState();

		cout << "\nВыберите действие: \n1) Положить элемент в конец списка\n2) Положить элемент в список\n3) Удалить элемент\n4) Выход\n\n> ";
		int choise;
		cin >> choise;
		if (choise == 4) {
			break;
		}
		if (choise == 1) {
			system("cls");
			char a;
			cout << "Введите элемент:\n> ";
			cin >> a;
			list->insert(a);
			system("pause");
		}
		if (choise == 2) {
			system("cls");
			char a;
			int ind;
			cout << "Введите элемент:\n> ";
			cin >> a;
			cout << "Введите индекс:\n> ";
			cin >> ind;
			list->insert(a,ind);
			system("pause");
		}
		if (choise == 3) {
			system("cls");
			int ind;
			cout << "Введите индекс:\n> ";
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
		cout << "Состояние очереди: ";
		q->printState();

		cout << "\nВыберите действие: \n1) Положить элемент в очередь\n2) Взять элемент из очередь\n3) Выход\n\n> ";
		int choise;
		cin >> choise;
		if (choise == 3) {
			break;
		}
		if (choise == 1) {
			system("cls");
			char a;
			cout << "Введите элемент:\n> ";
			cin >> a;
			q->push(a);
		}
		if (choise == 2) {
			system("cls");
			char a = q->pop();
			cout << "Текущий элемент:\n> " << a << endl;
			system("pause");
		}
	}
	delete q;
	return 0;*/
}