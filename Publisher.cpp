#include "Publisher.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include "InterfaceSubscriber.h"
#include "Subscriber.h"
using namespace std;

Publisher::Publisher(char *a)
{
	count++;
	clc = 0;

	name = new char[25];
	article = new char[600];
	all_text = new char[5000];

	for (int i = 0; i < 25; i++)
	{
		this->name[i] = a[i];
	}
	path = new char[25];
	toTXT(name, path);

	ifstream fin;
	try
	{
		fin.open(path);
		if (!fin.is_open())
			throw 2;
	}
	catch (int i)
	{
		cout << "Отсутствует входной файл с ифнормацией о журнале " << name << endl;
		exit(1);
	}
	int i = 0;
	do
	{
		fin.get(all_text[i]);
		i++;
	} while (!fin.eof());
	all_text[i - 1] = '\0';
	fin.close();
}

void Publisher::get_latest_info()
{
	int i = 0;
	do
	{
		article[i] = all_text[clc];
		i++;	clc++;
	} while (all_text[clc] != '\\');
	clc++;
	article[i] = '\0';
}

void Publisher::subscribe(InterfaceSubscriber &subscriber)
{
	this->address.Push_Back(&subscriber);
}

void Publisher::unsubscribe(InterfaceSubscriber &subscriber)
{
	this->address.Remove(&subscriber);
}

void Publisher::notify()
{
	for (int i = 0; i<address.ret_size(); i++)
	{
		address[i]->update(name, article);
	}
}

bool Publisher::status(InterfaceSubscriber &subscriber)
{
	return address.is_there(&subscriber);
}

void Publisher::some_logic(Publisher *a)
{
	const int kol_vo_statei = 5;
	while (cntr_for_artcl<kol_vo_statei && !_kbhit())
	{
		for (int i = 0; i < count; i++)
		{
			a[i].get_latest_info();
			a[i].notify();
		}
		Sleep(5000);
		cout << "------------------------------Прошло 30 секунд---------------------------------------------------------------------------------" << endl;
		cntr_for_artcl++;
	}
}

int Publisher::count = 0;
int Publisher::cntr_for_artcl = 0;

Publisher::~Publisher()
{
	delete[] name;
	delete[] article;
	delete[] all_text;
}
