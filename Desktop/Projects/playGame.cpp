#include <string>
#include <iostream>
#include "Box.h"
#include "GoldMine.h"
#ifndef PLAYGAME_CPP
#define PLAYGAME_CPP

using namespace std;
int main(){
	char again = 'Y';
	cout << "Welcome to the gold mine explorer! Find the gold before it's all gone, avoid the coal!" << endl;
while(again == 'Y'){
	GoldMine gm;
	while(!gm.getWinner()){
		if(gm.getGold() <= 0){
			break;
		}
		int row;
		int col;
		cout << "Gold:" << gm.getGold() << endl;
		gm.printGoldMine();
		cout << endl << "Enter the row you would like to search at:";
		cin >> row;
		cout << endl << "Enter the column you would like to search at:";
		cin >> col;
		gm.revealSelection(row,col);
	}
	if(gm.getGold() <= 0){
		cout << "You ran out of gold you loser! Better luck next time!" << endl;
	}
	else if(gm.getWinner()){
		cout << "You won " << gm.getGold() << " gold! Well aren't you proud of yourself?" << endl;
	}
	cout << endl << "Would you like to play again? (Y) yes (N) no:";
	cin >> again;
}

		
			
}
#endif
