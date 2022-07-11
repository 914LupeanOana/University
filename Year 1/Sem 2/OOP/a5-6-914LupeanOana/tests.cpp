//
// Created by Oana Lupean on 21.04.2022.
//
#include "Repository.h"
#include "UserService.h"
#include "AdministratorService.h"
#include "tests.h"
#include <iostream>


Tests::Tests(AdminService& adminService, UserService& userService, Repository& repo) :
        adminService{ adminService }, userService{ userService }, repo{ repo }
{

}

void Tests::test_add_movie(){
    /// valid, non-existing movie
    std::string title = "Lost City";
    std::string genre = "Drama";
    size_t year = 2022;
    size_t likes = 567;
    std::string trailer = "https://google.ro";

    this->adminService.AddMovie(title, genre, year, likes, trailer);
    std::cout<< repo.GetSize();
    assert(repo.GetSize() == 0);

    ///existing movie
     title = "Lost Cit";
     genre = "Drama";
     year = 2022;
     likes = 567;
     trailer = "https://google.ro";

    this->adminService.AddMovie(title, genre, year, likes, trailer);
    std::cout<< repo.GetSize();
    assert(repo.GetSize() == 0);

}

void Tests::delete_movie()
{
    ///delete a movie
    std::string title = "Lost City";
    this->adminService.RemoveMovie(title);
    assert(repo.GetSize() == 0);
}

void Tests::update_movie()
{
    std::string title = "Lost City";

    std::string genre = "Drama";
    size_t year = 2022;
    size_t likes = 567;
    std::string trailer = "https://google.ro";

    this->adminService.AddMovie(title, genre, year, likes, trailer);
    std::string newtitle = "Lost";
    std::string newgenre = "Horror";
    size_t newyear = 2019;
    size_t newlikes = 8;
    std::string newtrailer = "https://youtube.com";
    this->adminService.UpdateMovieTitle("Lost City","Lost");
    this->adminService.UpdateMovieLikes("Lost", newlikes);
    this->adminService.UpdateMovieGenre("Lost", newgenre);
    this->adminService.UpdateMovieYear("Lost", newyear);
    this->adminService.UpdateMovieTrailer("Lost", newtrailer);
    this->adminService.GetRepo();

}

void Tests::test_user_service(){
    std::string title = "Lost City";
    std::string genre = "Drama";
    size_t year = 2022;
    size_t likes = 567;
    std::string trailer = "https://google.ro";
    Movie movie = Movie(title,genre, year, likes, trailer );
    this->adminService.AddMovie(title, genre, year, likes, trailer);
    userService.AddToWatchList(movie);
    userService.DeleteMovieWatchList(title, likes);
    userService.FilterByGenre(genre);
    userService.ReinitializeMovieList();
    userService.GoToNextMovie();
    userService.GetCurrentMovie();
    userService.GetMovieList();
    repo.operator=(repo);
    repo.operator==(repo);
    repo.operator[](0);




}
void Tests::run_tests(){
    test_add_movie();
    delete_movie();
    update_movie();
    test_user_service();
    std::cout<< " Tests done.";
}