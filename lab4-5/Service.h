#pragma once
#include "Project.h"
#include "Repository.h"

using namespace std;

class Service
{
private:
	Repository *repo;
public:
	Service(Repository* r) : repo(r) {}
	Repository getRepo() const { return *repo; }
	Service() {}
	~Service() {}

	int addProjectC(Project p);
	int updateProjectC(int i, Project p1);
	int delProjectC(const char* path);
	void readProjectsC();

	Project* getAllC();
	int getLenC();
};