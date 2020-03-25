#include "Service.h"
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;


int Service::addProjectC(Project p)
{
	//uses the fuction addProjectR from Repository to add an element to the list
	//in: p an object type Project
	//out: 1
	this->repo->addProjectR(p);
	return 1;
}

int Service::updateProjectC(int i, Project p1)
{
	//uses the function updateProjectR from Repository to update an element in the list
	//in: p an object type Project and i - an index
	//out: 1
	this->repo->updateProjectR(i, p1);
	return 1;
}

int Service::delProjectC(const char*gitPath)
{
	//uses the function delProjectR from Repository  to delete the elements that have the same gitPaths that is in the parameter, from the list
	//in: gitPath - type const char*
	//out: 1 if the delete was made, 0 instead
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
{	//returns the length of the list(how many projects are there) using the function getLenR from Repository
	//in: -
	//out: the number of projects in the list
	return this->repo->getLenR();
}

Project* Service::getAllC()
{
	//returns all the elements of the list using the function getAllR from Repository
	//in: -
	//out: returns a list of projects
	return this->repo->getAllR();
}

void Service::readProjectsC()
{
	//reads and lists all the projects that are returned by getLenR
	//in: -
	//out: lists all the projects
	for (int i = 0; i < this->repo->getLenR(); i++)
		cout << this->repo->getAllR()[i].toString() << endl;
}