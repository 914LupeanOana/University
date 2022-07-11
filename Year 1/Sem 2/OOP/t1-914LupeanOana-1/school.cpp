//
// Created by Oana Lupean on 07.04.2022.
//
#include "school.h"

School::School() :
        name{ "" }, adress{ ""}, date { "" }
{
}

School::School(const std::string name, const std::string adress,const  std::string date) :
        name {name}, adress {adress}, date {date}
{
}

School::~School()
{
}

std:: string School:: GetName() const
{
    return this->name;
}

std:: string School:: GetAdress() const
{
    return this->adress;
}

std:: string School :: GetDate() const
{
    return this->date;
}

bool School::operator==(const School& other) const
{
    return this->name == other.name;
}

void School:: SetName(std::string newTitle)
{
    this->name = newTitle;
}


void School:: SetAdress(std:: string newAdress)
{
    this->adress = newAdress;
}

void School:: SetDate(std:: string newDate)
{
    this->date = newDate;
}



std::ostream& operator<<(std::ostream& os, const School& school)
{
    return os << "School: " << school.name << " | Address: " << school.adress << " | Date: " << school.date << "\n";
}