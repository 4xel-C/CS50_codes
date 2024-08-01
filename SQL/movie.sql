-- This file shows exemple of SQL request using sqlite3 and the movies.db file.

-- Find the average rating of films in 2012

sqlite> SELECT AVG(rating) FROM ratings WHERE movie_id IN
   ...> (SELECT id FROM movies WHERE year = 2012);


-- Find all peoples who starred in Toy Story movies: (3 tables relationnal)
sqlite> SELECT name FROM people WHERE id IN (
   ...> SELECT person_id FROM stars WHERE movie_id IN
   ...> (SELECT id FROM movies WHERE title = 'Toy Story'));



-- Find all peoples with their birth who starred in a movie released in 2004
sqlite> SELECT name, birth FROM people WHERE id IN
   ...> (SELECT person_id FROM stars WHERE movie_id IN
   ...> (SELECT id FROM movies WHERE year = 2004))
   ...> ORDER BY birth;

--  Joining table solution => Give duplicate without the group by function
sqlite> SELECT name, birth FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE movies.year = 2004 GROUP BY name, birth ORDER BY people.birth;


-- Select Name of the directors from movies with a rating of at least 9.0
sqlite> SELECT name FROM people WHERE id IN
   ...> (SELECT person_id FROM directors WHERE movie_id IN
   ...> (SELECT movie_id FROM ratings WHERE rating >= 9.0));

-- Select the 5 highest rated movies from Chadwick boseman
sqlite> SELECT title FROM movies JOIN ratings ON id = movie_id WHERE id IN
   ...> (SELECT movie_id FROM stars WHERE person_id IN
   ...> (SELECT id FROM people WHERE name = "Chadwick Boseman"))
   ...> ORDER BY rating DESC
   ...> LIMIT 5;


-- Selectionne les titres où joue soit Jennifer lawrence ou Bradley Cooper
sqlite> SELECT title FROM movies WHERE id IN
   ...> (SELECT movie_id FROM stars WHERE person_id IN
   ...> (SELECT id FROM people WHERE name = 'Jennifer Lawrence')
   ...> OR person_id IN
   ...> (SELECT id FROM people WHERE name = 'Bradley Cooper'))
   ...> ORDER BY title
   ...> ;

--  même chose
SELECT title, name FROM movies, people , stars WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND name IN ('Jennifer Lawrence', 'Bradley Cooper');

--  Permet d'avoir les noms des films où Jennifer Lawrence et Bradley Cooper ont joués en même temps
SELECT title, COUNT(name) FROM movies, people , stars WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND name IN ('Jennifer Lawrence', 'Bradley Cooper') GROUP BY title HAVING COUNT(name) = 2;

-- By joining tables
SELECT title FROM movies, people , stars WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND name IN ('Jennifer Lawrence', 'Bradley Cooper') GROUP BY title HAVING COUNT(name) = 2;


-- Permet d'avoir les noms des films où Jennifer Lawrence et Bradley Cooper ont joués en même temps by nested query
sqlite> SELECT title FROM movies WHERE id IN
   ...> (SELECT movie_id FROM stars WHERE person_id IN
   ...> (SELECT id FROM people WHERE name = 'Jennifer Lawrence' OR name = 'Bradley Cooper')
   ...> GROUP BY movie_id HAVING COUNT(movie_id) = 2);


--  Find all the peoples who starred in a movi in which Kevin Bacon also starre.
--       nested query
sqlite> SELECT name FROM people WHERE id IN
   ...> (SELECT person_id FROM stars WHERE movie_id IN
   ...> (SELECT movie_id FROM stars WHERE person_id IN
   ...> (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958)));

--       Joining tables

sqlite> SELECT name, title FROM people, stars, movies WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND movies.id IN (SELECT movie_id  FROM stars WHERE person_id IN (SELECT id FROM people  WHERE name = 'Kevin Bacon'));

