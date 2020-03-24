#include "Service.h"
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;


int Service::addProjectC(Project p)
{
	this->repo->addProjectR(p);
	return 1;
}

int Service::updateProjectC(int i, Project p1)
{
	this->repo->updateProjectR(i, p1);
	return 1;
}

int Service::delProjectC(const char*gitPath)
{
	int ok = 0;
	Project *projects = this->repo->getAllR();
	int len = this->repo->getLenR();
	for (int i = 0; i < len; i++)
		if (strcmp(projects[i].getGitPath(), gitPath) == 0)
		{
			this->repo->delProjectR(projects[i]);
			ok = 1;
		}
	if (ok == 0)
		return 0;
	else
		return 1;
}

int Service::getLenC()
{
	return this->repo->getLenR();
}

Project* Service::getAllC()
{
	return this->repo->getAllR();
}

void Service::readProjectsC()
{
	for (int i = 0; i < this->repo->getLenR(); i++)
		cout << this->repo->getAllR()[i].toString() << endl;
}