#include "Repository.h"
#include <string>
#include <iostream>

using namespace std;

Repository::Repository()
{
	this->projects = new Project[100];
	this->length = 0;
}

Repository::~Repository()
{
	if (this->projects != NULL)
	{
		this->projects = NULL;
		this->length = 0;
	}
}

int Repository::addProjectR(const char* gitPathN, const int noBranchesN,const int noCommitsN)
{
	//verifies if the new project exists in the list already, if not adds it
	//in: p project type variable
	//out: 1 if the action was performed, 0 otherwise
	Project p = Project(gitPathN, noBranchesN, noCommitsN);
	int poz = verifDuplicat(gitPathN,noBranchesN,noCommitsN);
	if (poz == -1)
	{
		this->projects[this->length] = p;
		this->length = this->length + 1;
		return 1;
	}
	return 0;
}

int Repository::delProjectR(const char* gitPathN, const int noBranchesN, const int noCommitsN)
{
	//verifies if the new project exists in the list already, if yes, delete it
	//in: p project type variable
	//out: 1 if the action was performed, 0 otherwise
	int poz = verifDuplicat(gitPathN, noBranchesN, noCommitsN);
	if (poz != -1)
	{
		for (int i = poz; i <= this->length - 2; i++)
		{
			this->projects[i] = this->projects[i + 1];
		}
		this->length = this->length - 1;
		return 1;
	}
	else
		return 0;
}

int Repository::updateProjectR(int i, const char* gitPathN, const int noBranchesN, const int noCommitsN)
{
		this->getAllR()[i].setGitPath(gitPathN);
		this->getAllR()[i].setNoBranches(noBranchesN);
		this->getAllR()[i].setNoCommits(noCommitsN);
		return 1;
}

void Repository::setAll(Project * p, int l)
{
	this->length = l;
	for (int i = 0; i < this->length; i++)
		this->projects[i] = p[i];
}

int Repository::verifDuplicat(const char* gitPathN, const int noBranchesN, const int noCommitsN)
{
	//verifies if the new project exists in the list already
	//in: p project type variable
	//out: returns the position where it exists if it does, -1 otherwise
	for (int i = 0; i < this->length; i++)
		if ((noBranchesN == this->projects[i].getNoBranches()) && (strcmp(gitPathN,this->projects[i].getGitPath())==0) && (noCommitsN == projects[i].getNoCommits()))
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
