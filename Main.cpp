#include <iostream>
#include "OthelloGame.h";
using namespace std;

int main(char argc, char* args){
   char Board[BOARD_SIZE][BOARD_SIZE];
   for (int row = 0; row < BOARD_SIZE; row++){
      for (int col = 0; col < BOARD_SIZE; col++){
         Board[row][col] = 0;
      }
   }
   Board[3][3] = -1;
   Board[4][4] = -1;
   Board[3][4] = 1;
   Board[4][3] = 1;
   PrintBoard(Board);
   system("pause");
}