SELECT title FROM movies WHERE year = 2008;
SELECT birth FROM people WHERE name = "Emma Stone";
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;
SELECT count(movie_id) FROM ratings WHERE rating = 10.0;
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;
SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);
SELECT title, rating FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE year = "2010" ORDER BY rating DESC, title;
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = "Toy Story"));
SELECT name FROM people WHERE ID IN (
    SELECT DISTINCT person_id FROM stars WHERE movie_id IN (
        SELECT id FROM movies WHERE year = "2004"
    )
) ORDER BY birth;
SELECT name FROM people WHERE id IN (
    SELECT DISTINCT person_id FROM directors WHERE movie_id IN (
        SELECT movie_id FROM ratings WHERE rating >= 9.0
    )
);
SELECT title FROM movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN ratings ON ratings.movie_id = movies.id
    JOIN people ON people.id = stars.person_id
    WHERE people.name = "Chadwick Boseman"
    ORDER BY ratings.rating DESC
    LIMIT 5;
SELECT title FROM movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN people ON people.id = stars.person_id
    WHERE people.name = "Johnny Depp" INTERSECT
    SELECT title FROM movies
        JOIN stars ON stars.movie_id = movies.id
        JOIN people ON people.id = stars.person_id
        WHERE people.name = "Helena Bonham Carter";
SELECT name FROM people WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN (
        SELECT movie_id FROM stars
        JOIN people ON people.id = stars.person_id
        WHERE name = "Kevin Bacon" AND birth = "1958"
    )
) AND NOT name = "Kevin Bacon";