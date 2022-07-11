//
// Created by Oana Lupean on 07.04.2022.
//

#ifndef T1_914LUPEANOANA_1_SCHOOL_H
#define T1_914LUPEANOANA_1_SCHOOL_H
#include <iostream>
class School
{
public:

    School();


    School(std::string name, std::string adress, std::string date);


    ~School();

    //Getters
    std::string GetName() const;
    std::string GetAdress() const;
    std::string GetDate() const;

    //Setters
    void SetName(std::string newName);
    void SetAdress(std::string newAdress);
    void SetDate(std::string newDate);

    bool operator==(const School& other) const;


    friend std::ostream& operator<<(std::ostream& os, const School& school);
private:

    std::string name;
    std::string adress;
    std::string date;
};

#endif //T1_914LUPEANOANA_1_SCHOOL_H
