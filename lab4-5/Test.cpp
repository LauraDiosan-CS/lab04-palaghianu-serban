#include "Test.h"
#include "Project.h"
#include "Repository.h"
#include "assert.h"
#include <iostream>
#include <string.h>
#include "Service.h"
using namespace std;

void test()
{
	//tests for the Project class
	Project p1 = Project();

	assert(p1.getGitPath() == NULL);
	assert(p1.getNoBranches() == 0);
	assert(p1.getNoCommits() == 0);

	Project p2 = Project("iwgfuw", 11, 21);
	assert(strcmp(p2.getGitPath(), "iwgfuw") == 0);
	assert(p2.getNoBranches() == 11);
	assert(p2.getNoCommits() == 21);

	Project p3 = Project(p2);
	assert(strcmp(p3.getGitPath(), "iwgfuw") == 0);
	assert(p3.getNoBranches() == 11);
	assert(p3.getNoCommits() == 21);

	cout << "Testele functioneaza" << endl;
}

void testRepo()
{
	//tests for the Repository class
	Repository repo;
	Project p2 = Project("qqeqehvbf", 5, 3);
	Project p1 = Project("C/repo/source", 10, 6);
	repo.addProjectR("qqeqehvbf", 5, 3);
	repo.addProjectR("C/repo/source", 10, 6);
	assert(repo.getLenR() == 2);

	cout << "Repository tests passed" << endl;
}

void testService()
{
	//tests for the Service class
	Repository repo;
	Service serv;
	Project p2 = Project("blabla", 5, 3);
	Project p1 = Project("mama", 10, 6);
	serv.addProjectC("mypc/datcom", 5, 3);
	serv.addProjectC("sooper", 11, 6);
	serv.addProjectC("blabla/land", 15, 20);
	serv.addProjectC("yeeeey", 10, 8);
	assert(serv.addProjectC("mypc/datcom", 5, 3) == 1);
	assert(serv.addProjectC("sooper", 11, 6) == 1);
	assert(serv.updateProjectC(0, "supamida", 13, 11) == 1);
	assert(serv.getLenC() == 4);
	assert(p2.compare(serv.getAllC()[0]) == false);
	assert(p1.compare(serv.getAllC()[1]) == false);
	serv.delProjectGitPathC("sooper");
	assert(serv.getLenC() == 3);

	serv.delProjectNoBranchesC(10);
	assert(serv.getLenC() == 2);
	serv.addProjectC("vreausatrec", 64, 100);
	serv.addProjectC("mypcdatcom", 32, 451);

	//assert(serv.filterGitPathC("mypcdatcom") == 1);
	//assert(serv.filterNoCommitsC(100) == 1);
	//assert(serv.filterGreaterNoBranchesC(60) == 1);
	//assert(serv.filterIntervalNoCommitsC(10,16) == 2);
	assert(serv.maxNoBranchesC() == 64);
	assert(serv.minNoCommitsC() == 11);
	assert(serv.sumNoBranchesC() == 124);
	assert(serv.sumNoCommitsC() == 582);
	assert(serv.filternoBranchesNoCommits(60, 2) == 1);
	serv.delProjectNoBranchesXNoCommits();

	cout << "Service tests passed" << endl;
}
