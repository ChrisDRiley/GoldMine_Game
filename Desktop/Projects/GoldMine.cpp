#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include "GoldMine.h"
#ifndef GOLDMINE_CPP
#define GOLDMINE_CPP
using namespace std;
GoldMine::GoldMine(){
	srand (time(NULL));
	gold = rand() % 9000 + 1000;
	found = false;
	cheatMode = false;
	setRainbow();
	setGold();
	setCoal();
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			gm[i][j].setGoldLost(rand() % 300 + 200);
		}
	}
}
void GoldMine::randomRowColumn(int &row, int &column){
	srand (time(NULL));
	row = rand() % 6;
	column = rand() % 6;
}
void GoldMine::setMyBox(char c){
	int row = -1;
	int col = -1;
	
	randomRowColumn(row,col);
	bool valid = false;
	while(!valid){
		if(gm[row][col].getCharacter() == 'N'){
			if(c == 'G'){
				gm[row][col].setCharacter('G');
				locRowGold = row;
				locColGold = col;
				valid = true;
			}
			else if(c == 'R'){
				gm[row][col].setCharacter('R');
				valid = true;
			}
			else if(c == 'C'){
				gm[row][col].setCharacter('C');
				valid = true;
			}
		
		}
		else{
			randomRowColumn(row,col);
		}
	}
}
void GoldMine::setRainbow(){
	setMyBox('R');
}
void GoldMine::setGold(){
	setMyBox('G');
}
void GoldMine::setCoal(){
	setMyBox('C');
}
void GoldMine::rainbowMessage(){
	if(locRowGold < 3 && locColGold < 3){
		cout << "The gold is in the northwest quadrant!" << endl;
	}
	else if(locRowGold < 3 && locColGold > 2){
		cout << "The gold is in the northeast quadrant!" << endl;
	}
	else if(locRowGold > 2 && locColGold < 3){
		cout << "The gold is in the southwest quadrant!" << endl;
	}
	else if(locRowGold > 2 && locColGold > 2){
		cout << "The gold is in the southeast quadrant!" << endl;
	}
}
void GoldMine::revealSelection(int row, int column){
	if(row == 9 && column == 9){
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				gm[i][j].setVisited(true);
			}
		}
		cout << "Cheats on! Nosy little sonuva gun aren't ya?" << endl;
		cheatMode = true;
	}
	else if(gm[row][column].getVisited() && !cheatMode){
		cout << "You have already visited that space dummy!" << endl;
	}
	else if(gm[row][column].getCharacter() == 'N'){
		gm[row][column].setVisited(true);
		gold -= gm[row][column].getGoldLost();
		cout << "There was nothing there! " << gm[row][column].getGoldLost() << " gold disappeared while you were searching!" << endl;
	}
	else if(gm[row][column].getCharacter() == 'C'){
		gm[row][column].setVisited(true);
		gold = 0;
		cout << "Oh no! You found the coal! You passed out from noxious fumes!" << endl;
	}
	else if(gm[row][column].getCharacter() == 'G'){
		gm[row][column].setVisited(true);
		found = true;
		cout << "You found the gold! Well aren't you lucky?" << endl;
	}
	else if(gm[row][column].getCharacter() == 'R'){
		gm[row][column].setVisited(true);
		cout << "Holy crap a rainbow! It leads to the gold!" << endl;
	 	rainbowMessage();
		gold -= gm[row][column].getGoldLost();
	}
	
}
void GoldMine::printGoldMine(){
	cout << "   0  1  2  3  4  5" << endl;
	for(int i = 0; i < 6; i++){
		cout << i << "  ";
		for(int j = 0; j < 6; j++){
			if(!(gm[i][j].getVisited())){
				cout << "*  ";
			}
			else{
				if(gm[i][j].getCharacter() == 'N'){
					cout << "-  ";
				}
				else{
					cout << gm[i][j].getCharacter() << "  ";
				}
			}
		}
		cout << endl;
	}
}
int GoldMine::getGold(){
	return gold;
}
bool GoldMine::getWinner(){
	return found;
}

#endif
