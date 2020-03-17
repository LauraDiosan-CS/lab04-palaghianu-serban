#pragma once
#include <string.h>

using namespace std;

class Project
{
private:
	char* gitPath=new char[100];
	int noBranches;
	int noCommits;
public:
	Project();
	Project(const char* gitPath, int noBranches, int noCommits);
	Project(const Project &p);
	//~Project();

	char* getGitPath();
	void setGitPath(const char* gitPathN);
	int getNoBranches();
	void setNoBranches(int noBranchesN);
	int getNoCommits();
	void setNoCommits(int noCommitsN);

	bool compare(Project &p);
	Project& operator=(Project& p);
	char* toString();
};