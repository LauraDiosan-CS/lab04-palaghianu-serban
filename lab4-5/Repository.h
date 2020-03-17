#pragma once
#include "Project.h"

using namespace std;

class Repository
{
private:
	int length = 0;
	Project projects[100];
public:
	Repository() {};
	int addProjectR(Project& p);
	int delProjectR(Project& p);
	int verifDuplicat(Project& p);
	Project* getAllR();
	int getLenR();
};