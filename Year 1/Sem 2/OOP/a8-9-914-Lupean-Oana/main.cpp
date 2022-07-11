#include "repository.h"
#include "service.h"
#include "ui.h"
#include "movie.h"
#include <vector>
#include "validators.h"
//#include <crtdbg.h>

int main()
{

    std::vector<Movie> repoAdminVector;
    repoAdminVector.reserve(10);
    std::string filename = R"(/Users/oanalupean/Downloads/a8-9-914-Lupean-Oana/movies.txt)";
    Repository repo{repoAdminVector, filename};
    repo.initialiseRepo();
    Service service{repo};
    std::vector<Movie> repoUserVector;
    UserService userService{repo};
    MovieValidator validator{};
    UI ui{service, userService, validator};
    ui.start();

    return 0;
}
