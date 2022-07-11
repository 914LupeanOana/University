#include <stdio.h>
#include "ui.h"
#include "test.h"

int main() {
    run_tests();

    CountryRepo *repo = createRepo();

    service *serv = createService(repo);

    UI* ui = createUI(serv);

    start(ui);

    deallocate_user_interface(ui);

    return 0;

}
