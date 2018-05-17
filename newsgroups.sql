-- Vous devez creer un utilisareur "newsgroup" qui execute 
-- ce script et est donc l'administrateur, et un utilisateur
-- avec votre login comme membre du forum. 
-- Instructions pour creer un utilisateur:
-- CREATE USER login IDENTIFIED BY password;
-- GRANT CONNECT, RESOURCE TO login;

-- VOUS DEVEZ IMPERATIVEMENT FAIRE SUIVRE TOUTE MISE A JOUR
-- (INSERT, UPDATE, DELETE) DE L'INSTRUCTION COMMIT POUR
-- EVITER DE BLOQUER LA BASE ET POUR QUE TOUS LES MEMBRES VOIENT
-- VOS MISES A JOUR; 

-- Initialisation de la base

drop view nouveaumessage;
drop view supprimermessage;
drop view nouvellelecture;

drop table lecture;
drop table message;
drop table moderateur;
drop table groupe;


create table groupe(
idgroupe number primary key,
nomgroupe varchar(30));

create table moderateur(
idgroupe number references groupe(idgroupe),
mod varchar(10),
primary key (idgroupe,mod));

create table message(
idmessage number  primary key,
titre varchar(50) not null,
datemsg timestamp default sysdate,
auteur varchar(10)  default user,
texte clob not null,
idgroupe number not null references groupe(idgroupe),
msgpere number references message(idmessage) on delete cascade );

create table lecture(
idmessage number  references message(idmessage) on delete cascade,
datelecture timestamp default sysdate,
lecteur varchar(10)  default user,
primary key (idmessage,lecteur));

-- incrementation automatique des numeros de messages

create sequence idm start with 1;

create trigger clemsgnewsgroup  
before insert on message 
for each row begin
select idm.nextval into :new.idmessage  from dual;
end;
/


-- Definition des groupes

insert into groupe values (0,'Global');
insert into groupe values (1,'Projet BD');
insert into groupe values (2,'DUT info 1 / groupe A');
insert into groupe values (3,'DUT info 1 / groupe B');
insert into groupe values (4,'DUT info 1 / groupe C');
insert into groupe values (5,'DUT info 1 / groupe D');
insert into groupe values (6,'Jeux');
insert into groupe values (7,'Cinema');
insert into groupe values (8,'BD');
commit;


-- Definition des moderateurs
insert into moderateur values (0,'LOYER');
commit;

-- Droits d'acces

grant select on groupe to public;

grant select on moderateur to public;

grant select on message to public;

create view nouveaumessage as (select idmessage, titre, texte, idgroupe, msgpere from message);
grant insert on nouveaumessage to public;

create view supprimermessage as 
	(select * from message 
	 where idgroupe in (select idgroupe from moderateur 
	                                    where mod=user)); 
grant delete on supprimermessage to public;
	                                    

grant select on lecture to public;

create view nouvellelecture as (select idmessage from lecture);
grant insert on nouvellelecture to public;


