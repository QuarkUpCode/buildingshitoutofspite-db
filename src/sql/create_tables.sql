-- DROP TABLE IF EXISTS TestTable;

-- CREATE TABLE TestTable (
-- 	id INT PRIMARY KEY,
-- 	username VARCHAR(127)
-- );


DROP TABLE IF EXISTS users CASCADE;

CREATE TABLE users (
	id SERIAL PRIMARY KEY,
	username VARCHAR(127),
	level INT,
	exp INT,
	gold INT
);


DROP TABLE IF EXISTS characters CASCADE;

CREATE TABLE characters (
	player_id INT,
	character_id SERIAL PRIMARY KEY,
	name VARCHAR(127),
	strenght INT,
	agility INT,
	intelligence INT,
	health INT,
	mana INT,
	class INT
);


DROP TABLE IF EXISTS inventory CASCADE;

CREATE TABLE inventory(
	characcter_id INT PRIMARY KEY,
	capacity INT
);


DROP TABLE IF EXISTS freeitems CASCADE;

CREATE TABLE freeitems(
	name VARCHAR(127),
	cid INT,
	amount INT,
	PRIMARY KEY (name, cid, amount)
);


DROP TABLE IF EXISTS equipeditems CASCADE;

CREATE TABLE equipeditems(
	freeitem_instance freeitems,
	slot INT,
	PRIMARY KEY (freeitem_instance, slot)
);


DROP TABLE IF EXISTS items CASCADE;

CREATE TABLE items(
	name VARCHAR(127) PRIMARY KEY,
	price INT,
	atk INT,
	def INT,
	heal INT
);


DROP TABLE IF EXISTS itemability CASCADE;

CREATE TABLE itemability(
	item_name VARCHAR(127),
	ability VARCHAR(511),
	PRIMARY KEY (item_name, ability)
);


DROP TABLE IF EXISTS spells CASCADE;

CREATE TABLE spells(
	name VARCHAR(127) PRIMARY KEY,
	mana_cost INT,
	cooldown INT,
	atk INT
);


DROP TABLE IF EXISTS spell_per_character CASCADE;

CREATE TABLE spell_per_character(
	spell_name VARCHAR(127),
	character_id INT,
	PRIMARY KEY (spell_name, character_id)
);















-- CREATE TABLE quête(
--         _Nom_ INT,
--         Description INT,
--         Difficulté INT,
-- );
-- CREATE TABLE récompense(
--         _Nom de la Quête_ INT,
--         Or INT,
--         XP INT,
-- );
-- CREATE TABLE quêteparpersonnage(
--         _Nom de la Quête_ INT,
--         _CID_ INT,
--         Status INT,
-- );
-- CREATE TABLE pnj(
--         _ID_ INT,
--         Dialogue INT,
-- );
-- CREATE TABLE pnjitemtable(
--         _NPCID_ INT,
--         _Nom d'objet_ INT,
-- );
-- CREATE TABLE pnjquesttable(
--         _NPCID_ INT,
--         _Nom de la Quête_ INT,
-- );
-- CREATE TABLE monstre(
--         _Nom_ INT,
--         Attaque INT,
--         Défense INT,
--         PV INT,
-- );
-- CREATE TABLE monstredroptable(
--         _Nom du Monstre_ INT,
--         _Nom d'objet_ INT,
--         _Quantitée_ INT,
--         Probabilité INT,
-- );