//
// Created by Oana Lupean on 07.04.2022.
//

#include "service.h"


Service::Service(Repository& r) :
        repo{ r }
{
}

Repository Service::getRepo() const
{
    return this->repo;
}

void Service::addServ(const std::string& name, const std::string adress, const std::string date)
{
    School s{ name, adress, date };

    this->repo.addSchool(s);
}

void Service::initializeRepo()
{
    addServ("Avram_Iancu", "46.77,23.60" , "15-04-2022");
    addServ("George_Cosbuc", "46.77,23.58" , "18-04-2022");
    addServ("Alexandr_Vaida_Voieod", "46.77,23.63" , "23-04-2022");
    addServ("Romulus_Guga", "46.53,24.57" , "04-05-2022");
    addServ("Colegiu_Transilvania", "46.54,24.57" ,"03-05-2022");

}

