#include "Project.h"
#include "Repository.h"
#include "Test.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	Repository repo;
	Project p1 = Project("blabla/land", 381, 0);
	repo.addProjectR(p1);
	cout << p1.toString() << endl;
	system("pause");
	return 0;
}