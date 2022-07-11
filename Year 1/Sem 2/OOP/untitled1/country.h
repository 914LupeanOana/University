//
// Created by Oana Lupean on 09.03.2022.
//
#ifndef UNTITLED1_COUNTRY_H
#define UNTITLED1_COUNTRY_H

typedef struct
{
    char* name;
    char* continent;
    double population;
}Country;

Country* createCountry(char* name, char* continent, double population);

char* getName(Country* p);
char* getContinent(Country* p);
double getPopulation(Country* p);

void toString(Country* p, char str[]);
void set_population(Country* country, double population);

#endif //UNTITLED1_COUNTRY_H