//
// Created by Oana Lupean on 23.03.2022.
//

#ifndef A3_4_DOMAIN_H
#define A3_4_DOMAIN_H

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
void set_population(Country* country, int population);

#endif //A3_4_DOMAIN_H
