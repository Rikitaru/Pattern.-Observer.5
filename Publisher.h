#pragma once
class Publisher : public InterfacePublisher
{
private:
	char *name;
	char *all_text;
	char *article;
	int clc;
	char *path;
	AgainVector<class InterfaceSubscriber *> address;
	static int count;
	static int cntr_for_artcl;
public:
	Publisher(char *);
	void get_latest_info();
	void subscribe(InterfaceSubscriber &) override;
	void unsubscribe(InterfaceSubscriber &) override;
	void notify() override;
	bool status(InterfaceSubscriber &);
	static void some_logic(Publisher *);
	~Publisher();
}; 
#include "Publisher.cpp"
