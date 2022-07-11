#include <fstream>
#include "CSV_Watchlist.h"

CSVWatchlist::CSVWatchlist() = default;
CSVWatchlist::~CSVWatchlist() = default;

void CSVWatchlist::SaveToFile()
{
    std::ofstream f("/Users/oanalupean/CLionProjects/a11-12/Files/Watchlist.csv");
    for(const auto& coat : this->movies)
        f << coat << "\n";
    f.close();
}

void CSVWatchlist::OpenInApp()
{
system("open /Users/oanalupean/CLionProjects/a11-12/Files/Watchlist.csv");
}