#include "Movie.h"
#include <sstream>

Movie::Movie() :
	title{ "" }, genre{ "" }, year{ 0 }, likes{ 0 }, trailer{ "" }
{
}

Movie::Movie(std::string title, std::string genre, size_t year, size_t likes, std::string trailer) :
	title {title}, genre {genre}, year {year}, likes {likes}, trailer {trailer}
{
}

Movie::~Movie()
{
}

std:: string Movie:: GetTitle() const
{
	return this->title;
}

std::string Movie :: GetGenre() const
{
	return this->genre;
}

size_t Movie:: GetYear() const
{
	return this->year;
}

size_t Movie :: GetLikes() const
{
	return this->likes;
}

std::string Movie:: GetTrailer() const
{
	return this->trailer;
}


bool Movie::operator==(const Movie& other) const
{
	return this->title == other.title;
}

void Movie:: SetTitle(std::string newTitle)
{
	this->title = newTitle;
}

void Movie:: SetGenre(std::string newGenre)
{
	this->genre = newGenre;
}

void Movie:: SetYear(size_t newYear)
{
	this->year = newYear;
}

void Movie:: SetLikes(size_t newLikes)
{
	this->likes = newLikes;
}


void Movie:: SetTrailer(std::string newTrailer)
{
	this->trailer = newTrailer;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
	return os << "Movie: " << movie.title << " | Genre: " << movie.genre << " | Year: " << movie.year << " | Nr. of likes: "
		<< movie.likes << " | Trailer: " << movie.trailer << "\n";
}