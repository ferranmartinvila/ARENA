#ifndef _GLOBALS_
#define _GLOBALS_
//TYPEDEFS
typedef unsigned int uint;
//DATA TYPES
enum DATA_TYPE{

	STRING
};
//COLOR TYPES
enum COLOR{
	BLACK, 
	BLUE, 
	GREEN,
	CYAN, 
	RED, 
	MAGENTA, 
	BROWN, 
	NORMAL, 
	DARK_GREY, 
	LIGHT_BLUE, 
	LIGHT_GREEN, 
	LIGHT_CYAN, 
	LIGHT_RED, 
	LIGHT_MAGENTA, 
	YELLOW, 
	WHITE
};

//GLOBAL TYPES
enum TYPE{

	OBJECT,
	CREATURE,
	ROOM,
	EXIT,
};
//CREATURE TYPES
enum CREATURE_TYPE{

	PLAYER,
	GOBLIN,
	ORC,
	ARCHER,
	ELF,
	DEMON,
	GOLEM,
	HARPY,
	MINOTAUR,
	CYCLOP,
	GORGON,
	MERCHANT,
	RUNNER,
	TAMER,
	HELL_HORSE,
	TURTLE_OF_WIND,
	GOLDEN_FOX,
	UNICORN,
	ARTIC_HORSE,
	FLYING_KOI,
	IRON_GOAT,
	MAGIC_YAK,
	FLYING_GOLDFISH,
	GIANT_TURTLE
};
//CREATURE STATE
enum CREATURE_STATE{

	//Base
	IDLE,
	TALK,
	//Items
	BUY,
	SELL,
	ENCHANT,
	FUSE_RUNES,
	EXTRACT_RUNES,
	//Fight
	ATTACK,
	IN_ARENA,
	DEAD
};
//OBJECTS TYPES
enum OBJECT_TYPE{

	HELM,
	ARMOR,
	GLOBES,
	PANTS,
	BOOTS,
	WEAPON,
	EQUIP,
	RUNE,
	POTION,
	UNDEFINED
};
//POTION TYPES
enum POTION_TYPE{
	HEAL_POTION,
	DEFENCE_POTION,
	ATTACK_POTION,
	AGILITY_POTION
};
//RUNE TYPES
enum RUNE_TYPE{
	LIVE_RUNE,
	DEFENCE_RUNE,
	ATTACK_RUNE,
	AGILITY_RUNE
};
//DIRECTIONS
enum DIRECTION{

	NORTH,
	SOUTH,
	EAST,
	WEST,
	UNKKOWN
};
//DIFFICULTY
enum DIFFICULTY{
	EASY,
	MEDIUM,
	HARD
};
#endif