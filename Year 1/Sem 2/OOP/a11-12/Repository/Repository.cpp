#include "Repository.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>
#include "../Exceptions/Exceptions.h"

Repository::Repository(std::string filename) {
    this->filename = std::move(filename);
    this->readFromFile();
}

void Repository::incrementLikesService(int index){

    this->movies[index].incrementLikes();
}

void Repository::addMovie(const Movie& movie) {

    int pos = this->findPositionOfMovie(movie);
    if(pos == -1)
    {
        this->movies.push_back(movie);
        this->writeToFile();
    }
    else
//        throw DuplicateMovie();
        int a = 0;
}

void Repository::deleteMovie(int position) {
   auto it = this->movies.begin();
   std::advance(it, position);

   if(position < 0 || position >= this->movies.size())
       throw IncorrectPosition();
   else
   {
       this->movies.erase(this->movies.begin()+position);
       this->writeToFile();
   }
}

bool Repository::compareIfSameMovieRepo(const Movie& movie, const std::string& title, const std::string& genre, int year) {
    if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year)
        return true;
    return false;
}

int Repository::updateMovie(int position, const Movie& movie) {
//    auto it = this->movies.begin();
//    std::advance(it, position);
//
//    if(position < 0 || position >= this->movies.size())
//        throw IncorrectPosition();
//    else
//    {
//        this->updateMovie(position, movie);
//        this->writeToFile();
//    }
    if (this->search(movie.getTitle(), movie.getGenre(), movie.getYear()))
        throw DuplicateMovie();
    this->movies[position] = movie;
    this->writeToFile();
}


bool Repository::search(const std::string& title, const std::string& genre, int year) {
    bool returnValue = false;
    std::for_each(this->movies.begin(), this->movies.end(), [=, &returnValue](const Movie& movie) {
        if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year) returnValue = true;});
    return returnValue;
}

int Repository::findPositionOfMovie(const Movie &movie) {
    for (int i = 0; i < this->movies.size(); i++)
        if (this->movies[i].getGenre() == movie.getGenre() && this->movies[i].getTitle() == movie.getTitle() && this->movies[i].getYear() == movie.getYear())
            return i;
    return -1;
}

Movie Repository::operator[](int index) {
    return this->movies[index];
}

void Repository::readFromFile()
{
    std::ifstream file(this->filename);

    if(!file.is_open())
        throw FileExceptions("This file could not be opened!");
    Movie movie;
    while(file >> movie)
        this->movies.push_back(movie);
    file.close();

}

void Repository::writeToFile()
{
    std::ofstream file(this->filename);
    if(!file.is_open())
        throw FileExceptions("This file could not be opened!");
    for(const auto& movie : this->movies)
        file << movie;
    file.close();
}