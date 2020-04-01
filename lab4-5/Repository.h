#pragma once
#include "Project.h"

using namespace std;

class Repository
{
private:
	int length;
	Project* projects;
public:
	Repository();
	~Repository();

	int addProjectR(const char* gitPathN, const int noBranchesN, const int noCommitsN);
	int delProjectR(const char* gitPathN, const int noBranchesN, const int noCommitsN);
	int verifDuplicat(const char* gitPathN, const int noBranchesN, const int noCommitsN);
	int updateProjectR(int i, const char* gitPathN, const int noBranchesN, const int noCommitsN);

	void setAll(Project* p, int l);

	Project* getAllR();
	int getLenR();
};