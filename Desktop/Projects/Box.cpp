#include <stdlib.h>
#include <time.h>
#include "Box.h"
#ifndef BOX_CPP
#define BOX_CPP

Box::Box(){
	selected = false;
	character = 'N';
}
bool Box::getVisited(){
	return selected;
}
void Box::setVisited(bool visited){
	selected = visited;
}
int Box::getGoldLost(){
	return goldLost;
}
void Box::setGoldLost(int amount){
	goldLost = amount;
}
char Box::getCharacter(){
	return character;
}
void Box::setCharacter(char special){
	character = special;
}
#endif
	

