#pragma once
#include "WatchList.h"

class HTMLWatchlist : public WatchList
{
public:
    HTMLWatchlist();
    ~HTMLWatchlist();

    void SaveToFile() override;
    void OpenInApp() override;
};
