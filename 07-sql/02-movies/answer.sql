-- 1.sql
select title from movies where year = 2008;

-- 2.sql
select birth from people where name = 'Emma Stone';

-- 3.sql
select * from movies where year >= 2018 order by title;

-- 4.sql
select
	count(*) as best_movies_count
from movies as m
inner join ratings as r on r.movie_id = m.id
where r.rating = 10;

--5.sql
select title, year from movies where title like 'Harry Potter%' order by year;

--6.sql
select avg(rating) from movies as m
inner join ratings as r on r.movie_id = m.id
where year = 2012;

-- 7.sql
select title, rating from movies as m
inner join ratings as r on r.movie_id = m.id
where year = 2010
order by r.rating desc;

--8.sql
select name from movies as m
inner join stars as s on s.movie_id = m.id
inner join people as p on p.id = s.person_id
where title = 'Toy Story';

--9.sql
select name from movies as m
inner join stars as s on s.movie_id = m.id
inner join people as p on p.id = s.person_id
where year = 2004
group by person_id
order by birth;

--10.sql
select name from movies as m
inner join ratings as r on r.movie_id = m.id
inner join directors as d on d.movie_id = m.id
inner join people as p on p.id = d.person_id
where r.rating >= 9
group by d.person_id;

-- 11.sql
select title from people as p
inner join stars as s on s.person_id = p.id
inner join movies as m on m.id = s.movie_id
inner join ratings as r on r.movie_id = m.id
where p.name = 'Chadwick Boseman'
order by r.rating desc
limit 5;

-- 12.sql
select title from
	(select movie_id from people as p
	inner join stars as s on s.person_id = p.id
	inner join movies as m on m.id = s.movie_id
	where p.name = 'Jennifer Lawrence'
	intersect
	select movie_id from people as p
	inner join stars as s on s.person_id = p.id
	inner join movies as m on m.id = s.movie_id
	where p.name = 'Bradley Cooper'
	) as c
inner join movies as m on m.id = c.movie_id;

--13.sql
select distinct name from stars as s 
inner join people as p on p.id = s.person_id
where s.movie_id IN (select movie_id from people as p inner join stars as s on s.person_id = p.id where name = 'Kevin Bacon' and birth = 1958)
and p.name != 'Kevin Bacon'
