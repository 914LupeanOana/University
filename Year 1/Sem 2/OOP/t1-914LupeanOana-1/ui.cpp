//
// Created by Oana Lupean on 07.04.2022.
//
#include "ui.h"
#include "exception.h"
#include<string>

using namespace std;

Console::Console(Service& s) :
        serv{ s }
{
    serv.initializeRepo();
}

void Console::printMenu()
{
    cout << endl;
    cout << "1. Add new school" << endl;
    cout << "2. Display all schools" << endl;
    cout << "0. Exit" << endl;
}

void Console::addUI()
{
    cout << "Enter the school name: ";
    std::string name;
    getline(cin, name);
    cout << "Enter the address: ";
    std::string adress;
    getline(cin, adress);
    cout << "Enter the date: ";
    std::string date;
    getline(cin, date);

    this->serv.addServ(name, adress, date);
}
void Console::displayAllSchools()
{
    cout << endl;
    DynamicVector<School> schools = this->serv.getRepo().getSchools();
    if (schools.getSize() == 0)
    {
        cout << "There are no schools in the repository." << endl;
        return;
    }

    for (int i = 0; i < schools.getSize(); i++)
    {
        School s = schools[i];
        cout << s.GetName() << " | " << s.GetAdress() << " | " << s.GetDate()  << endl;
    }
}

void Console::run()
{
    bool ok = 1;
    while (ok)
    {
        Console::printMenu();
        int command ;
        cout << "Enter command: ";
        cin >> command;
        cin.ignore();
        if (command == 0)
            ok = 0;
        else
            try
            {
                switch (command)
                {
                    case 1:
                        this->addUI();
                        cout << "School succesfully added!\n";
                        break;
                    case 2:
                        this->displayAllSchools();
                        break;

                }
            }
            catch (const RepoException& re)
            {
                cout << re.getMessage();
            }
            catch (const ValidatorException& ve)
            {
                cout << ve.getMessage();
            }
    }
}