#pragma once
#include "AdministratorService.h"
#include "UserService.h"

class Console
{
public:
	Console(AdminService& adminService, UserService& userService);
	
	void SelectMode();
	void MainLoopAdmin();

	void AddMovie();
	void RemoveMovie();
	void UpdateMovie();
	void UpdateMovieTitle(std::string title, std::string newTitle);
	void UpdateMovieGenre(std::string title, std::string newGenre);
	void UpdateMovieYear(std::string title, size_t newYear);
	void UpdateMovieLikes(std::string title, size_t newLikes);
	void UpdateMovieTrailer(std::string title, std::string newTrailer);
	void PrintAllMovies();

	void PrintAdminMenu();

	void MainLoopUser();
	void PrintUserMenu();
	void AddWatchListNoFilter();
	void AddWatchListFiter();
	void DeleteMovieFromWatchList();
	void ViewWatchList();
	void AddWatchList();
	void NoAddWatchList();
	void UserReinitializationWatchList();
	void UserFilterByGenre();


private:
	AdminService adminService;
	UserService userService;
};

