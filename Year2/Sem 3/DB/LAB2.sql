CREATE TABLE Movies(
	movie_id INT PRIMARY KEY,
	movie_title VARCHAR(100),
    director VARCHAR(50),
    duration INT
);

CREATE TABLE Genres(
	genre_id INT PRIMARY KEY,
    genre_name VARCHAR(25) UNIQUE
);

CREATE TABLE MoviesGenres(
	movie_id INT,
    FOREIGN KEY (movie_id) REFERENCES Movies(movie_id),
	genre_id INT,
    FOREIGN KEY (genre_id) REFERENCES Genres(genre_id),
    UNIQUE (movie_id, genre_id)
);

CREATE TABLE Cinemas(
	cinema_id INT PRIMARY KEY,
    cinema_name VARCHAR(50),
    seats INT,
    CHECK (seats > 10)
);

CREATE TABLE Schedule(
	sch_id INT PRIMARY KEY,
    start_time DATETIME,
    cinema_id INT,
    FOREIGN KEY (cinema_id) REFERENCES Cinemas(cinema_id),
    movie_id INT,
    FOREIGN KEY (movie_id) REFERENCES Movies(movie_id)
);

INSERT INTO Movies(movie_id, movie_title, director, duration) VALUES(1, 'Full Metal Jacket', 'd1', 120);

SELECT * FROM Movies;    