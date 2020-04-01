#include "Project.h"
#include "Repository.h"
#include "Test.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include "Service.h"
#include "UI.h"

using namespace std;

int main()
{
	test();
	testRepo();
	testService();
	Repository repo;
	Service serv;
	UI u;


	u.run();
	system("pause");
	return 0;
}