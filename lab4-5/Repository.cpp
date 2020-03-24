#include "Repository.h"
#include <string>
#include <iostream>

using namespace std;

int Repository::addProjectR(Project& p)
{
	//verifies if the new project exists in the list already, if not adds it
	//in: p project type variable
	//out: 1 if the action was performed, 0 otherwise
	int poz = verifDuplicat(p);
	if (poz == -1)
	{
		this->projects[this->length] = p;
		this->length = this->length + 1;
		return 1;
	}
	return 0;
}

int Repository::delProjectR(Project& p)
{
	//verifies if the new project exists in the list already, if yes, delete it
	//in: p project type variable
	//out: 1 if the action was performed, 0 otherwise
	int poz = verifDuplicat(p);
	if (poz != -1)
	{
		for (int i = poz; i <= this->length - 1; i++)
		{
			this->projects[i] = this->projects[i + 1];
		}
		this->length = this->length - 1;
		return 1;
	}
	else
		return 0;
}

int Repository::updateProjectR(int i, Project& newP)
{
		this->getAllR()[i].setGitPath(newP.getGitPath());
		this->getAllR()[i].setNoBranches(newP.getNoBranches());
		this->getAllR()[i].setNoCommits(newP.getNoCommits());
		return 1;
}

int Repository::verifDuplicat(Project& p)
{
	//verifies if the new project exists in the list already
	//in: p project type variable
	//out: returns the position where it exists if it does, -1 otherwise
	for (int i = 0; i < this->length; i++)
		if ((p.getNoBranches() == this->projects[i].getNoBranches()) && (strcmp(p.getGitPath(),this->projects[i].getGitPath())==0) && (p.getNoCommits() == projects[i].getNoCommits()))
			return i;
	return -1;
}

Project* Repository::getAllR()
{
	//returns all the elements of the list
	//in: -
	//out: returns a list of projects
	return this->projects;
}

int Repository::getLenR()
{
	//returns the length of the list(how many projects are there)
	//in: -
	//out: the number of projects in the list
	return this->length;
}
