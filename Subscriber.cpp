#include "Subscriber.h"
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

Subscriber::Subscriber(char *a)
{
	counter++;
	name = new char[25];
	for (int i = 0; i < 25; i++)
	{
		this->name[i] = a[i];
	}
	path = new char[25];
	toTXT(name, path);
}
char* Subscriber::ret_name()
{
	return name;
}
void Subscriber::update(char *name, char *article)
{
	cout << "Свежий выпуск журнала " << name << " для " << this->name << endl;
	cout << article << endl;
	ofstream fout;
	fout.open(this->path, ios::app);
	fout << name;
	fout << article << endl;
	fout.close();
}
void Subscriber::clear_file()
{
	ofstream clear; clear.open(path);	clear.close();
}
Subscriber::~Subscriber()
{
	delete[] name;
	delete[] path;
}
int Subscriber::counter = 0;
