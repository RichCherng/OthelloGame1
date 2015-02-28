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
   int turn = 0, row,col;
   while (true){
      PrintBoard(Board);
      if (turn % 2 == 0)
         cout << "Black's turn. ";
      else
         cout << "White's turn. ";

      while (true){
         cout << "Please choose a move" << endl;
         GetMove(&row, &col);
         if (!IsValidMove(Board, row, col)){
            cout << "Invalid move.";
         }
         else
            break;
      }
      turn++;

      //Board[row][col] = ((turn % 2) * 2) - 1;
   }
   

   system("pause");
}