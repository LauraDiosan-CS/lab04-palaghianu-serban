#include "Test.h"
#include "Project.h"
#include "Repository.h"
#include "assert.h"
#include <iostream>
#include <string.h>
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
	repo.addProjectR(p1);
	repo.addProjectR(p2);
	assert(repo.getLenR() == 2);

	cout << "Repository tests passed" << endl;
}