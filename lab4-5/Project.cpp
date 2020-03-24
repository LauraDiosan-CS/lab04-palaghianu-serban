#include <iostream>
#include <string>
#include "Project.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

Project::Project()
{
	//constructor default(sets all values NULL or 0
	this->noBranches = 0;
	this->noCommits = 0;
	this->gitPath = NULL;
}

Project::Project(const char* gitPathN, int noBranchesN, int noCommitsN)
{
	//constructor cu 3 parametrii
	this->gitPath = new char[strlen(gitPathN) +1];
	strcpy_s(this->gitPath, strlen(gitPathN) + 1, gitPathN);
	this->noBranches = noBranchesN;
	this->noCommits = noCommitsN;
}

Project::Project(const Project &p)
{
	//constructor cu 1 singur parametru
	//in: p de tip Project
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->noBranches = p.noBranches;
	this->noCommits = p.noCommits;
}

Project::~Project() {
	if (this->gitPath) {
		delete[] this->gitPath;
		this->gitPath = NULL;
	}
}

char* Project::getGitPath()
{
	//out: returns GitPath
	return this->gitPath;
}

void Project::setGitPath(const char* gitPathN)
{
	//setter GitPath
	//in: gitPathN (new value)
	//out: -
	if (this->gitPath) {
		delete[] this->gitPath;
	}
	this->gitPath = new char[strlen(gitPathN) + 1];
	strcpy_s(this->gitPath, strlen(gitPathN) + 1, gitPathN);
}

int Project::getNoBranches()
{
	//out: returns number of branches
	return this->noBranches;
}

void Project::setNoBranches(int noBranchesN)
{
	//setter number of branches
	//in: noBranchesN (new value)
	//out: -
	this->noBranches = noBranchesN;
}

int Project::getNoCommits()
{
	//out: returns number of commits
	return this->noCommits;
}

void Project::setNoCommits(int noCommitsN)
{
	//setter number of commits
	//in: noCommitsN (new value)
	//out: -
	this->noCommits = noCommitsN;
}

bool Project::compare(Project &p)
{
	//functie de comparare
	//in: c de tip Project
	return((this->noBranches == p.noBranches) && (strcmp(this->gitPath, p.gitPath)==0) && (this->noCommits == p.noCommits));
}



Project & Project::operator=(Project &p)
{
	//suprascriere
	if (this != &p)
	{
		this->setNoBranches(p.noBranches);
		this->setNoCommits(p.noCommits);
		this->setGitPath(p.gitPath);
	}
	return *this;
}

char* Project::toString()
{
	//afisarea unei variabile de tip project
	if (this->gitPath != NULL) {
		int noChars = strlen(this->gitPath) + 1 + 5 + 5 + 2;
		char* s = new char[noChars];
		char* aux = new char[5];
		strcpy_s(s, noChars, this->gitPath);
		strcat_s(s, noChars, " | ");
		_itoa_s(this->noBranches, aux, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, " | ");
		_itoa_s(this->noCommits, aux, 5, 10);
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		return s;
	}
	else
		return NULL;
}