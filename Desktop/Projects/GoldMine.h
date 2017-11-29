#include <string>
#include "Box.h"
#ifndef GOLDMINE_H
#define GOLDMINE_H
class GoldMine
{
  public:
        GoldMine();
        void randomRowColumn(int &row, int &column);
        void setMyBox(char c);
        void setRainbow();
        void setGold();
        void setCoal();
        void rainbowMessage();
        void revealSelection(int row, int column);
        void printGoldMine();
        int getGold();
	bool getWinner();
		//Can  add any methods necessary.
   private:
        Box gm[6][6]; //creates the array of boxes
        int gold; // holds the initial amount of gold 1000 – 9000
	int locRowGold;
	int locColGold;
	bool found;
	bool cheatMode;
};
#endif
