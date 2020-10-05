#include <iostream>
#include <stdlib.h>
#include "toTXT.cpp"
#include "AgainVector.h"
#include "InterfaceSubscriber.h"
#include "InterfacePublisher.h"
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "rus");
	char s0[]{ "TopGear" };
	char s1[]{ "National Geographic" };
	char s2[]{ "People" };
	char s3[]{ "BusinessWeek" };
	char s4[]{ "PROSport" };
	char s5[]{ "Forbes" };

	Publisher publishers[6]
	{
		Publisher(s0),
		Publisher(s1),
		Publisher(s2),
		Publisher(s3),
		Publisher(s4),
		Publisher(s5)
	};

	char s00[]{ "Danechka" };
	char s01[]{ "Vados" };
	char s02[]{ "Kot_Barsik" };
	Subscriber Abonents[3]
	{
		Subscriber(s00),
		Subscriber(s01),
		Subscriber(s02)
	};

	for (int i = 0; i < Subscriber::counter; i++)		//очистить файлы
	{
		Abonents[i].clear_file();
	}

	while (1) {
		int choise;
		try {

			cout << "Вы можете выбрать действие:" << endl;
			cout << "\t1 - Выбрать пользователя" << endl;
			cout << "\t2 - Начать раздачу выпусков" << endl;
			cout << "\t0 - Выход" << endl;
			cin >> choise;
			if (choise < 0 & choise>2)
				throw 3;

		}
		catch (int i)
		{
			cout << "Неверный ввод! ошибка в меню номер " << i << endl;
			system("pause");
		}
		switch (choise)
		{
		case 1:
		{
			int ch_person;
			cout << "Выберите пользователя:" << endl;
			for (int i = 0; i < Subscriber::counter; i++)
			{
				cout << i + 1 << ") " << Abonents[i].ret_name() << endl;
			}
			while (1)
			{
				try
				{
					cin >> ch_person;
					if (ch_person<0 || ch_person>Subscriber::counter)
						throw 4;
					else break;
				}
				catch (int i)
				{
					cout << "Неверный ввод!" << endl;
				}
			}
			ch_person--;
			int ch = -1;
			while (ch != 0)
			{

				cout << "\t1 Подписаться на журналы" << endl;
				cout << "\t2 Отписаться от журналов" << endl;
				cout << "\t0 Выход\n>" << endl;
				cin >> ch;
				switch (ch)
				{
				case 1:
					int ch2;
					cout << "\nЖурналы, доступные для подписки:" << endl;
					cout << "1 TopGear\t\t\t";
					if (publishers[0].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "2 National Geographic\t\t";
					if (publishers[1].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "3 Peoples\t\t\t";
					if (publishers[2].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "4 BusinessWeek\t\t\t";
					if (publishers[3].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "5 PROSport\t\t\t";
					if (publishers[4].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "6 Forbes\t\t\t";
					if (publishers[5].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "0 Назад\n>";
					cin >> ch2;
					switch (ch2)
					{
					case 1:
						if (!publishers[0].status(Abonents[ch_person]))
							publishers[0].subscribe(Abonents[ch_person]);
						break;
					case 2:
						if (!publishers[1].status(Abonents[ch_person]))
							publishers[1].subscribe(Abonents[ch_person]);
						break;
					case 3:
						if (!publishers[2].status(Abonents[ch_person]))
							publishers[2].subscribe(Abonents[ch_person]);
						break;
					case 4:
						if (!publishers[3].status(Abonents[ch_person]))
							publishers[3].subscribe(Abonents[ch_person]);
						break;
					case 5:
						if (!publishers[4].status(Abonents[ch_person]))
							publishers[4].subscribe(Abonents[ch_person]);
						break;
					case 6:
						if (!publishers[5].status(Abonents[ch_person]))
							publishers[5].subscribe(Abonents[ch_person]);
						break;
					case 0:
						break;
					}
					system("pause");
					break;
				case 2:
					int ch3;
					cout << "Отписаться от:"<< endl;
					cout << "1 TopGear\t\t\t";
					if (publishers[0].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "2 National Geographic\t\t";
					if (publishers[1].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "3 Peoples\t\t\t";
					if (publishers[2].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "4 BusinessWeek\t\t\t";
					if (publishers[3].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "5 PROSport\t\t\t";
					if (publishers[4].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "6 Forbes\t\t\t";
					if (publishers[5].status(Abonents[ch_person]))
						cout << '+' << endl;
					else
						cout << '-' << endl;
					cout << "0)Назад\n>";
					cin >> ch3;
					switch (ch3)
					{
					case 1:
						publishers[0].unsubscribe(Abonents[ch_person]);
						break;
					case 2:
						publishers[1].unsubscribe(Abonents[ch_person]);
						break;
					case 3:
						publishers[2].unsubscribe(Abonents[ch_person]);
						break;
					case 4:
						publishers[3].unsubscribe(Abonents[ch_person]);
						break;
					case 5:
						publishers[4].unsubscribe(Abonents[ch_person]);
						break;
					case 6:
						publishers[5].unsubscribe(Abonents[ch_person]);
						break;
					case 0:
						break;
					}
					system("pause");
					break;

				case 0:
					break;
				}
				system("cls");
			}
			break;
		}
		case 2:
		{
			Publisher::some_logic(publishers);
			break;
		}
		case 0:
			return 0;
		}
		system("cls");
	}
}
