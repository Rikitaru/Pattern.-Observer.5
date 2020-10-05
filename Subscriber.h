#pragma once
class Subscriber : public InterfaceSubscriber
{
private:
	char *name;
	char *path;
public:
	Subscriber(char *);
	char* ret_name();
	static int counter;
	void update(char *name, char *article) override;
	void clear_file();
	~Subscriber();
};
#include "Subscriber.cpp"
