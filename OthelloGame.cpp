#include <iostream>  
#include "OthelloGame.h";

using namespace std;

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]){
   cout << "- ";
   for (int i = 0; i < BOARD_SIZE; i++){
      cout << i << " ";
   }

   for (int row = 0; row < BOARD_SIZE; row++){
      cout << endl << row << " ";
      for (int col = 0; col < BOARD_SIZE; col++){
         if (board[row][col] == 0)
            cout << ". ";
         else if (board[row][col] == 1)
            cout << "B ";
         else if (board[row][col] == -1)
            cout << "W ";
      }
   }
   cout << endl;
}

bool InBounds(int row, int col){
   return ((row < BOARD_SIZE) && (row >= 0)) && ((col < BOARD_SIZE) && (col >= 0)) ? true : false;
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col){
   return (InBounds(row, col) && board[row][col] == '0') ? true : false;
}

void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char currentPlayer){
      
}