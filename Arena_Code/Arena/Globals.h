#ifndef _GLOBALS_
#define _GLOBALS_
typedef unsigned int uint;
//GLOBAL TYPES
enum TYPE{

	OBJECT,
	CREATURE,
	ROOM,
	EXIT,
	UNDEFINED
};
//CREATURE TYPES
enum CREATURE_TYPE{

	PLAYER,
	GOBLIN,
	MERCHANT,
	CRAFTER

};
//CREATURE STATE
enum CREATURE_STATE{
	IDLE,
	TALK,
	BUY,
	SELL,
	ENCHANT,
	FUSE_RUNES,
	ATTACK,
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
	RUNE,
	POTION
};
//DIRECTIONS
enum DIRECTION{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

#endif