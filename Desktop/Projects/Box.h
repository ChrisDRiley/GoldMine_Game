#ifndef BOX_H
#define BOX_H
class Box
{
  public:
        Box();
        bool getVisited();
        void setVisited(bool visited);
        int getGoldLost();
        void setGoldLost(int amount);
        char getCharacter();
        void setCharacter(char special);
   private:
        char character; //(N)othing, (C)oal, (G)old, (R)ainbow
        int goldLost;   //holds the amount of gold lost
        bool selected;  //determines if the box has been selected or not
};
#endif
