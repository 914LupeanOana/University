//
// Created by Oana Lupean on 21.04.2022.
//

#ifndef A5_6_914LUPEANOANA_TESTS_H
#define A5_6_914LUPEANOANA_TESTS_H
#include "AdministratorService.h"
#include "UserService.h"
#include "Repository.h"

class Tests
{
public:
    Tests(AdminService& adminService, UserService& userService, Repository& repo);

    void test_add_movie();
    void delete_movie();
    void update_movie();
    void test_user_service();
    void run_tests();

private:
    AdminService adminService;
    UserService userService;
    Repository repo;
};
#endif //A5_6_914LUPEANOANA_TESTS_H
