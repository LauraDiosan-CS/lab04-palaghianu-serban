#pragma once
#include "Project.h"
#include "Repository.h"

using namespace std;

class Service
{
private:
	Repository repo;
	int len;
public:
	Service();
	Service(Repository r);
	~Service();
	Repository getRepo();

	int addProjectC(const char* gitPathN, const int noBranches, const int noCommits);

	int updateProjectC(int i, const char* gitPathN, const int noBranchesN, const int noCommitsN);

	int delProjectGitPathC(const char* path);
	int delProjectNoBranchesC(const int noBranches);
	int delProjectNoCommitsC(const int noCommits);

	int filterGitPathC(const char* gitPath);
	int filterNoBranchesC(const int noBranches);
	int filterNoCommitsC(const int noCommits);
	int filterIntervalNoBranchesC(const int noBranches1, const int noBranches2);
	int filterIntervalNoCommitsC(const int noCommits1, const int noCommits2);
	int filterGreaterNoBranchesC(const int noBranches);
	int filterGreaterNoCommitsC(const int noCommits);
	int filterLowerNoBranchesC(const int noBranches);
	int filterLowerNoCommitsC(const int noCommits);

	int sumNoCommitsC();
	int sumNoBranchesC();

	int maxNoBranchesC();
	int maxNoCommitsC();
	int minNoBranchesC();
	int minNoCommitsC();

	void readProjectsC();

	Project* getAllC();
	int getLenC();
};