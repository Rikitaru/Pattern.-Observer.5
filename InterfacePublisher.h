#pragma once
class InterfacePublisher
{
public:
	void virtual subscribe(InterfaceSubscriber &) = 0;
	void virtual unsubscribe(InterfaceSubscriber &) = 0;
	void virtual notify() = 0;
};
#include "Publisher.h"
