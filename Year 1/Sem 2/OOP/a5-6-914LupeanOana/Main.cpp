#include "Ui.h"
#include "tests.h"
#include <iostream>

int main()
{
	Repository* repo = new Repository(10);
	AdminService* adminService = new AdminService(*repo);
	UserService* userService = new UserService(*repo);
	//Console* console = new Console(*adminService, *userService);
    Tests* tests = new Tests(*adminService, *userService, *repo);
    tests->run_tests();
	
	//console->SelectMode();

	//delete console;
	delete adminService;
	delete userService;
	delete repo;
    delete tests;

	return 0;
}