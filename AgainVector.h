#pragma once

template <class T>
class AgainVector
{
private:
	int Size;
	T *Data;
public:
	AgainVector();
	void Push_Back(const T&);
	void Remove(const T&);
	int ret_size();
	void show();
	bool is_there(const T&);
	T& operator[](int);
	~AgainVector();
};
#include " AgainVector.cpp"
