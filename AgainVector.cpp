#include <iostream>
#include " AgainVector.h"
using namespace std;

template <class T>
AgainVector<T>::AgainVector()
{
	Data = new T[0];
	Size = 0;
}
template <class T>
void AgainVector<T>::Push_Back(const T &val)
{
	T *buf = new T[Size + 1];
	for (int i = 0; i<Size; i++)
	{
		*(buf + i) = *(Data + i);
	}
	*(buf + Size) = val;
	Size++;
	delete[] Data;
	Data = buf;
}
template <class T>
void AgainVector<T>::Remove(const T &val)
{
	T *buf = new T[Size + 1];
	int Position;
	bool was_found = false;
	for (int i = 0; i<Size; i++)
	{
		if (*(Data + i) == val)
		{
			Position = i;
			was_found = true;
		}
	}
	if (was_found)
	{
		for (int i = 0; i<Position; i++)
		{
			*(buf + i) = *(Data + i);
		}
		for (int i = Position + 1; i<Size; i++)
		{
			*(buf + i - 1) = *(Data + i);
		}
		Size--;
		delete[] Data;
		Data = buf;
	}
}
template <class T>
int AgainVector<T>::ret_size()
{
	return Size;
}
template <class T>
void AgainVector<T>::show()
{
	for (int i = 0; i<Size; i++)
	{
		cout << *(Data + i) << endl;
	}
}
template<class T>
bool AgainVector<T>::is_there(const T &arg)
{
	for (int i = 0; i<Size; i++)
	{
		if (*(Data + i) == arg)
			return true;
	}
	return false;
}
template <class T>
T& AgainVector<T>::operator[](int n)
{
	if (n<0 || n >= Size)
	{
		cout << "\nВыход за пределы массива!"; exit(1);
	}
	return Data[n];
}
template <class T>
AgainVector<T>::~AgainVector()
{
	delete[] Data;
}
