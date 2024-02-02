-- 1.sql
select name from songs;

-- 2.sql
select name from songs order by tempo asc;

--3.sql
select name from songs order by duration_ms desc limit 5;

--4.sql
select name from songs where danceability > 0.75 and energy > 0.75 and valence > 0.75;

--5.sql
select avg(energy) as avg_energy from songs;

--6.sql
select songs.name from artists
inner join songs on songs.artist_id = artists.id
where artists.name = 'Post Malone';

--7.sql
select avg(energy) from artists
inner join songs on songs.artist_id = artists.id
where artists.name = 'Drake';

--8.sql
select name from songs
where name like '%feat.%';
