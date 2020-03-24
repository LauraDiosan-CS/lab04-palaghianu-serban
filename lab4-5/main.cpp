#include "Project.h"
#include "Repository.h"
#include "Test.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include "Service.h"

using namespace std;

int main()
{
	Repository repo;
	Service serv{ &repo };
	test();
	testRepo();
	testService();
	Project p1 = Project("blabla/land", 381, 0);
	Project p2 = Project("6rffhfjhf", 3, 7);
	serv.addProjectC(p1);
	serv.addProjectC(p2);
	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
	serv.readProjectsC();
	serv.updateProjectC(0, p2);
	serv.readProjectsC();
	//serv.delProjectC(p2.getGitPath());
	serv.readProjectsC();
	system("pause");
	return 0;
}