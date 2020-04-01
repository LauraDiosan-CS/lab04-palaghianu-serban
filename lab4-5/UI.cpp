#include "UI.h"

void UI::printMenu()
{
	cout << endl;
	cout << "1. Show the list: " << endl;
	cout << "2. Add an element to the list: " << endl;
	cout << "3. Update an element from the list: " << endl;
	cout << "4. Delete an element from the list by gitPath: " << endl;
	cout << "5. Delete an element from the list by noBranches: " << endl;
	cout << "6. Delete an element from the list by noCommits: " << endl;
	cout << "7. Filter the elements of the list by gitPath: " << endl;
	cout << "8. Filter the elements of the list by noBranches: " << endl;
	cout << "9. Filter the elements of the list by noCommits: " << endl;
	cout << "10. Filter the elements of the list in an interval of noBranches: " << endl;
	cout << "11. Filter the elements of the list in an interval of noCommits: " << endl;
	cout << "12. Filter the elements of the list greater than a noBranches: " << endl;
	cout << "13. Filter the elements of the list greater than a noCommits: " << endl;
	cout << "14. Filter the elements of the list lower than a noBranches: " << endl;
	cout << "15. Filter the elements of the list lower than a noCommits: " << endl;
	cout << "16. Display the sum of the noBranches: " << endl;
	cout << "17. Display the sum of the noCommits: " << endl;
	cout << "18. Display the max noBranches and the projects that have them: " << endl;
	cout << "19. Display the max noCommits and the projects that have them: " << endl;
	cout << "20. Display the min noBranches and the projects that have them: " << endl;
	cout << "21. Display the min noCommits and the projects that have them: " << endl;
	cout << "0. Exit" << endl;
}

void UI::run()
{
	char* gitPath = new char[100];
	int noBranches, noCommits;
	int noBranches1, noBranches2;
	int noCommits1, noCommits2;
	int n;
	int max, min;
	int i;
	serv.addProjectC("blabla/land", 5, 8);
	serv.addProjectC("lala/band", 7, 313);
	serv.addProjectC("fwfw", 8, 11);
	serv.addProjectC("blabla/land", 11, 8);
	while (true)
	{
		printMenu();
		cout << "Choose an option: ";
		int opt = 0;
		cin >> opt;
		cin.ignore();
		if (opt == 0)
			break;
		switch (opt)
		{
		case 1:
			serv.readProjectsC();
			break;
		case 2:
			cout << "Type a gitPath: " << endl;
			cin >> gitPath;
			cout << "Type a noBranches: " << endl;
			cin >> noBranches;
			cout << "Type a noCommits: " << endl;
			cin >> noCommits;
			serv.addProjectC(gitPath,noBranches,noCommits);
			break;
		case 3:
			cout << "Enter the number of the project you want to update: " << endl;
			cin >> n;
			cout << "Type a gitPath: " << endl;
			cin >> gitPath;
			cout << "Type a noBranches: " << endl;
			cin >> noBranches;
			cout << "Type a noCommits: " << endl;
			cin >> noCommits;
			serv.updateProjectC(n-1, gitPath, noBranches, noCommits);
			break;
		case 4:
			cout << "Type a gitPath that you want to delete: " << endl;
			cin >> gitPath;
			serv.delProjectGitPathC(gitPath);
			break;
		case 5:
			cout << "Type a noBranches that you want to delete: " << endl;
			cin >> noBranches;
			serv.delProjectNoBranchesC(noBranches);
			break;
		case 6:
			cout << "Type a noCommits that you want to delete: " << endl;
			cin >> noCommits;
			serv.delProjectNoCommitsC(noCommits);
			break;
		case 7:
			cout << "Type a gitPath that you wanna filter by: " << endl;
			cin >> gitPath;
			cout << "List of projects with this gitPath: " << endl;
			cout << "Number of projects with this gitPath: " << serv.filterGitPathC(gitPath) << endl;
			break;
		case 8:
			cout << "Type a noBranches that you wanna filter by: " << endl;
			cin >> noBranches;
			cout << "List of projects with this noBranches: " << endl;
			cout << "Number of projects with this noBranches: " << serv.filterNoBranchesC(noBranches) << endl;
			break;
		case 9:
			cout << "Type a noCommits that you wanna filter by: " << endl;
			cin >> noCommits;
			cout << "List of projects with this noCommits: " << endl;
			cout << "Number of projects with this noCommits: " << serv.filterNoCommitsC(noCommits) << endl;
			cout << endl;
			break;
		case 10:
			cout << "Type the low end of the interval: " << endl;
			cin >> noBranches1;
			cout << "Type the high end of the interval: " << endl;
			cin >> noBranches2;
			cout << "List of projects in this interval of noBranches: " << serv.filterIntervalNoBranchesC(noBranches1, noBranches2) << endl;
			cout << "Number of projects in this interval of noBranches: " << endl;
			cout << endl;
			break;
		case 11:
			cout << "Type the low end of the interval: " << endl;
			cin >> noCommits1;
			cout << "Type the high end of the interval: " << endl;
			cin >> noCommits2;
			cout << "List of projects in this interval of noCommits: " << serv.filterIntervalNoCommitsC(noCommits1, noCommits2) << endl;
			cout << "Number of projects in this interval of noCommits: " << endl;
			cout << endl;
			break;
		case 12:
			cout << "Type a noBranches to be greater by: " << endl;
			cin >> noBranches;
			cout << "List of projects with noBranches greater than that: " << serv.filterGreaterNoBranchesC(noBranches) << endl;
			cout << "Number of projects with noBranches greater than that: " << endl;
			cout << endl;
			break;
		case 13:
			cout << "Type a noCommits to be greater by: " << endl;
			cin >> noCommits;
			cout << "List of projects with noCommits greater than that: " << serv.filterGreaterNoCommitsC(noCommits) << endl;
			cout << "Number of projects with noCommits greater than that: " << endl;
			cout << endl;
			break;
		case 14:
			cout << "Type a noBranches to be lower by: " << endl;
			cin >> noBranches;
			cout << "List of projects with noBranches lower than that: " << serv.filterLowerNoBranchesC(noBranches) << endl;
			cout << "Number of projects with noBranches lower than that: " << endl;
			cout << endl;
			break;
		case 15:
			cout << "Type a noCommits to be lower by: " << endl;
			cin >> noCommits;
			cout << "List of projects with noCommits lower than that: " << serv.filterLowerNoCommitsC(noCommits) << endl;
			cout << "Number of projects with noCommits lower than that: " << endl;
			cout << endl;
			break;
		case 16:
			cout << "Sum of the noBranches of all projects: " << serv.sumNoBranchesC() << endl;
			break;
		case 17:
			cout << "Sum of the noCommits of all projects: " << serv.sumNoCommitsC() << endl;
			break;
		case 18:
			max = serv.maxNoBranchesC();
			cout << "The maximum noBranches is: " << max << endl;
			cout << "The list of the projects with maximum noBranches is: " << endl;
			for (i = 0; i < serv.getLenC(); i++)
				if (serv.getAllC()[i].getNoBranches() == max)
					cout << serv.getAllC()[i].toString() << endl;
			break;
		case 19:
			max = serv.maxNoCommitsC();
			cout << "The maximum noCommits is: " << max << endl;
			cout << "The list of the projects with maximum noCommits is: " << endl;
			for (i = 0; i < serv.getLenC(); i++)
				if (serv.getAllC()[i].getNoCommits() == max)
					cout << serv.getAllC()[i].toString() << endl;
			break;
		case 20:
			min = serv.minNoBranchesC();
			cout << "The minimum noBranches is: " << min << endl;
			cout << "The list of the projects with minimum noBranches is: " << endl;
			for (i = 0; i < serv.getLenC(); i++)
				if (serv.getAllC()[i].getNoBranches() == min)
					cout << serv.getAllC()[i].toString() << endl;
			break;
		case 21:
			min = serv.minNoCommitsC();
			cout << "The minimum noCommits is: " << min << endl;
			cout << "The list of the projects with minimum noCommits is: " << endl;
			for (i = 0; i < serv.getLenC(); i++)
				if (serv.getAllC()[i].getNoCommits() == min)
					cout << serv.getAllC()[i].toString() << endl;
			break;
		}
	}
}