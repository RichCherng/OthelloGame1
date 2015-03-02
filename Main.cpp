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
   int turn = 0, row = 0,col = 0,pass = 0;
   while (pass < 2){
      PrintBoard(Board);
      if (turn % 2 == 0)
         cout << "Black's turn. ";
      else
         cout << "White's turn. ";

      while (true){
         cout << "Please choose a move" << endl;
         GetMove(&row, &col);
         pass += (row == -1 && col == -1) ? 1 : - 0.5;
         cout << "pass is : " << pass << endl;
         if (!IsValidMove(Board, row, col) && (row != -1 && col != -1) ){
            cout << "Invalid move. ";
         }
         else
            break;
      }
      ApplyMove(Board, row, col, (turn % 2 == 0)?1:-1);
      turn++;
   }
   cout << "Game over.";
   if (GetValue > 0)
      cout << "Black Win!" << endl;
   else if (GetValue < 0)
      cout << "White Win!" << endl;
   else
      cout << "We have a tie!" << endl;

   system("pause");
}