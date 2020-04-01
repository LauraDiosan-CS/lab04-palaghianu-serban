#include "Service.h"
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;


Service::Service()
{
	Project* p = new Project[100];
	repo.setAll(p, 0);
	this->len = 0;
}

Service::Service(Repository r)
{
	Project* p = new Project[r.getLenR()];
	repo.setAll(r.getAllR(), r.getLenR());
}

Service::~Service()
{
	if (this->repo.getAllR() != NULL)
		this->repo.setAll(NULL, 0);
}

Repository Service::getRepo()
{
	return this->repo;
}

int Service::addProjectC(const char* gitPathN, const int noBranchesN, const int noCommitsN)
{
	//uses the fuction addProjectR from Repository to add an element to the list
	//in: p an object type Project
	//out: 1
	this->repo.addProjectR(gitPathN, noBranchesN, noCommitsN);
	return 1;
}

int Service::updateProjectC(int i, const char* gitPathN, const int noBranchesN, const int noCommitsN)
{
	//uses the function updateProjectR from Repository to update an element in the list
	//in: p an object type Project and i - an index
	//out: 1
	this->repo.updateProjectR(i, gitPathN, noBranchesN, noCommitsN);
	return 1;
}

int Service::delProjectGitPathC(const char*gitPath)
{
	//uses the function delProjectR from Repository  to delete the elements that have the same gitPaths that is in the parameter, from the list
	//in: gitPath - type const char*
	//out: 1 if the delete was made, 0 instead
	int ok = 0;
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	for (int i = 0; i < len; i++)
		if (strcmp(projects[i].getGitPath(), gitPath) == 0)
		{
			this->repo.delProjectR(projects[i].getGitPath(), projects[i].getNoBranches(), projects[i].getNoCommits());
			ok = 1;
		}
	if (ok == 0)
		return 0;
	return 1;
}

int Service::filterGitPathC(const char* gitPath)
{
	//displays all projects that have the gitPath equal to the one from parameters
	//in: gitPath - type const char*
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (strcmp(projects[i].getGitPath(), gitPath) == 0)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterNoBranchesC(const int noBranches)
{
	//displays all projects that have the noBranches equal to the one from parameters
	//in: noBranches - type const int
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() == noBranches)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterNoCommitsC(const int noCommits)
{
	//displays all projects that have the noCommits equal to the one from parameters
	//in: noCommits - type const int
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoCommits() == noCommits)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterIntervalNoBranchesC(const int noBranches1, const int noBranches2)
{
	//displays all projects that have the noBranches between the 2 parameteres
	//in: noBranches1, noBranches2 - both type const int(the low and high limits of the interval)
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() >= noBranches1 && projects[i].getNoBranches() <= noBranches2)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterIntervalNoCommitsC(const int noCommits1, const int noCommits2)
{
	//displays all projects that have the noCommits between the 2 parameteres
	//in: noCommits1, noCommits2 - both type const int(the low and high limits of the interval)
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() >= noCommits1 && projects[i].getNoBranches() <= noCommits2)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterGreaterNoBranchesC(const int noBranches)
{
	//displays all projects that have the noBranches greater than the one in parameter
	//in: noBranches - type const int
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() > noBranches)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterGreaterNoCommitsC(const int noCommits)
{
	//displays all projects that have the noCommits greater than the one in parameter
	//in: noCommits - type const int
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoCommits() > noCommits)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterLowerNoBranchesC(const int noBranches)
{
	//displays all projects that have the noBranches lower than the one in parameter
	//in: noBranches - type const int
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() < noBranches)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::filterLowerNoCommitsC(const int noCommits)
{
	//displays all projects that have the noCommits lower than the one in parameter
	//in: noCommits - type const int
	//out: returns the number of projects that have that property
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int nr = 0;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoCommits() < noCommits)
		{
			nr++;
			cout << projects[i].toString() << endl;
		}
	}
	return nr;
}

int Service::sumNoBranchesC()
{
	//returns the sum of the noBranches of all projects
	//in: -
	//out: sum - the sum of the noBranches of all projects
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = sum + projects[i].getNoBranches();
	}
	return sum;
}

int Service::sumNoCommitsC()
{
	//returns the sum of the noCommits of all projects
	//in: -
	//out: sum - the sum of the noCommits of all projects
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = sum + projects[i].getNoCommits();
	}
	return sum;
}

int Service::maxNoBranchesC()
{
	//returns the max value that the noBranches hits in all projects
	//in: -
	//out: max - the maximum value the noBranches hits in all projects
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() > max)
			max = projects[i].getNoBranches();
	}
	return max;
}

int Service::maxNoCommitsC()
{
	//returns the max value that the noCommits hits in all projects
	//in: -
	//out: max - the maximum value the noCommits hits in all projects
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoCommits() > max)
			max = projects[i].getNoCommits();
	}
	return max;
}

int Service::minNoBranchesC()
{
	//returns the min value that the noBranches hits in all projects
	//in: -
	//out: min - the minimum value the noBranches hits in all projects
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int min = 1999999999;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoBranches() < min)
			min = projects[i].getNoBranches();
	}
	return min;
}

int Service::minNoCommitsC()
{
	//returns the min value that the noCommits hits in all projects
	//in: -
	//out: min - the minimum value the noCommits hits in all projects
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	int min = 1999999999;
	for (int i = 0; i < len; i++)
	{
		if (projects[i].getNoCommits() < min)
			min = projects[i].getNoCommits();
	}
	return min;
}

int Service::delProjectNoBranchesC(const int noBranches)
{
	//uses the function delProjectR from Repository  to delete the elements that have the same gitPaths that is in the parameter, from the list
	//in: gitPath - type const char*
	//out: 1 if the delete was made, 0 instead
	int ok = 0;
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	for (int i = 0; i < len; i++)
		if (projects[i].getNoBranches() == noBranches)
		{
			this->repo.delProjectR(projects[i].getGitPath(), projects[i].getNoBranches(), projects[i].getNoCommits());
			ok = 1;
		}
	if (ok == 0)
		return 0;
	return 1;
}


int Service::delProjectNoCommitsC(const int noCommits)
{
	//uses the function delProjectR from Repository  to delete the elements that have the same gitPaths that is in the parameter, from the list
	//in: gitPath - type const char*
	//out: 1 if the delete was made, 0 instead
	int ok = 0;
	Project *projects = this->repo.getAllR();
	int len = this->repo.getLenR();
	for (int i = 0; i < len; i++)
		if (projects[i].getNoCommits() == noCommits)
		{
			this->repo.delProjectR(projects[i].getGitPath(), projects[i].getNoBranches(), projects[i].getNoCommits());
			ok = 1;
		}
	if (ok == 0)
		return 0;
	return 1;
}

int Service::getLenC()
{	//returns the length of the list(how many projects are there) using the function getLenR from Repository
	//in: -
	//out: the number of projects in the list
	return this->repo.getLenR();
}

Project* Service::getAllC()
{
	//returns all the elements of the list using the function getAllR from Repository
	//in: -
	//out: returns a list of projects
	return this->repo.getAllR();
}

void Service::readProjectsC()
{
	//reads and lists all the projects that are returned by getLenR
	//in: -
	//out: lists all the projects
	for (int i = 0; i < this->repo.getLenR(); i++)
		cout << this->repo.getAllR()[i].toString() << endl;
}