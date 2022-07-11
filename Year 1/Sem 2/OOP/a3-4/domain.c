//
// Created by Oana Lupean on 23.03.2022.
//


#include "domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Country* createCountry(char* name, char* continent, double population)
{
    Country* p = malloc(sizeof(Country));
    if (p == NULL)
        return NULL;
    p->name = malloc(sizeof(char) * (strlen(name) + 1));
    if (p->name != NULL)
        strcpy(p->name, name);
    p->continent = malloc(sizeof(char) * (strlen(continent) + 1));
    if (p->continent!= NULL)
        strcpy(p->continent, continent);

    p->population = population;

    return p;
}

char* getName(Country* p)
{
    if(p == NULL)
        return NULL;
    return p->name;
}

char* getContinent(Country* p)
{
    if (p == NULL)
        return NULL;
    return p->continent;
}

double getPopulation(Country* p)
{
    if (p == NULL)
        return -1;
    return p->population;
}

void toString(Country* p, char str[])
{
    if (p == NULL)
        return;
    sprintf(str, "The country %s is being located on the continent %s and its population is %.2lf millions.", p->name, p->continent, p->population);
}

void set_population(Country* country, int population){
    country->population = population;
}