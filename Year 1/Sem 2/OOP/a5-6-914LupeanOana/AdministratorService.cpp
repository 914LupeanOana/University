#include "AdministratorService.h"
#include <exception>
#include <stdexcept>
using namespace std::string_literals;

AdminService::AdminService(Repository& repository) :
	repo{ repository }
{
}

void AdminService::AddMovie(std::string title, std::string genre, size_t year, size_t likes, std::string trailer)
{
	//if (!Validator::ValidMovieAttributes(title, genre, year, likes, trailer))
	//	throw std::invalid_argument("Invalid movie parameters!!");

	Movie newMovie = Movie(title, genre, year, likes, trailer);

	//bool duplicate = false;
	//for (size_t i = 0; i < this->repo.GetSize(); ++i)
	//	if (this->repo[i] == newMovie) duplicate = true;

	//if (duplicate) throw std::invalid_argument("A movie with the same name already exists!");

	this->repo.AddElement(newMovie);

}

void AdminService::RemoveMovie(std::string title)
{
	size_t pos = this->repo.FindElemByTitle(title);
	//if (pos >= this->repo.GetSize())
	//	throw std::invalid_argument("Movie not found!");

	this->repo.RemoveElemnt(pos);
}

void AdminService::UpdateMovieTitle(std::string title, std::string newTitle)
{
	//if (!Validator::ValidMovieTitle) throw std::invalid_argument("Invalid movie!");
	size_t pos = this->repo.FindElemByTitle(title);

	//if (pos > this->repo.GetSize()) throw std::invalid_argument("Movie not found!");
	this->repo.UpdateTitle(pos, newTitle);
}

void AdminService::UpdateMovieGenre(std::string title, std::string newGenre)
{
	//if (!Validator::ValidMovieTitle) throw std::invalid_argument("Invalid movie!");
	size_t pos = this->repo.FindElemByTitle(title);

	//if (pos > this->repo.GetSize()) throw std::invalid_argument("Movie not found!");
	this->repo.UpdateGenre(pos, newGenre);
}

void AdminService::UpdateMovieYear(std::string title, size_t newYear)
{
	//if (!Validator::ValidMovieTitle) throw std::invalid_argument("Invalid movie!");
	size_t pos = this->repo.FindElemByTitle(title);

	//if (pos > this->repo.GetSize()) throw std::invalid_argument("Movie not found!");
	this->repo.UpdateYear(pos, newYear);
}

void AdminService::UpdateMovieLikes(std::string title, size_t newLikes)
{
	//if (!Validator::ValidMovieTitle) throw std::invalid_argument("Invalid movie!");
	size_t pos = this->repo.FindElemByTitle(title);

	//if (pos > this->repo.GetSize()) throw std::invalid_argument("Movie not found!");
	this->repo.UpdateLikes(pos, newLikes);
}

void AdminService::UpdateMovieTrailer(std::string title, std::string newTraier)
{
	//if (!Validator::ValidMovieTitle) throw std::invalid_argument("Invalid movie!");
	size_t pos = this->repo.FindElemByTitle(title);

	//if (pos > this->repo.GetSize()) throw std::invalid_argument("Movie not found!");
	this->repo.UpdateTrailer(pos, newTraier);
}

Repository AdminService::GetRepo() const
{
	return this->repo;
}

//void AdminService::InitializeRepo()
//{
//	AddMovie("Sinister", "Horror", 2010, 100, "https://google.ro");
//	AddMovie("JurasicPark", "Adventure", 2011, 210, "https://google.ro");
//	AddMovie("Flowers", "Horror", 2013, 1000, "https://google.ro");
//	AddMovie("Mermaid", "Romance", 2018, 3000, "https://google.ro");
//	AddMovie("Sinner", "Drama", 2017, 4000, "https://google.ro");
//	AddMovie("Anabelle", "Horror", 2020, 2993, "https://google.ro");
//	AddMovie("Beatiful", "Romance", 2016, 4002, "https://google.ro");
//	AddMovie("Christmas", "Horror", 2022, 4563, "https://google.ro");
//	AddMovie("Mama", "Horror", 2013, 10024, "https://google.ro");
//	AddMovie("Home", "Horror", 2015, 3000, "https://youtube.com");
//}

