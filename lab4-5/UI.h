#pragma once
#include "Service.h"
#include <iostream>

using namespace std;

class UI 
{
public:
	Service serv;
	void run();
	void printMenu();
};