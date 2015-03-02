#include <iostream>  
#include <stack>
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
   cout << endl << endl;
}

bool InBounds(int row, int col){
   return (row < BOARD_SIZE) && (row >= 0) && (col < BOARD_SIZE) && (col >= 0);
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col){
   bool isPass = (row == -1) && (col == -1);
   return (InBounds(row, col) && board[row][col] == 0 || isPass);
}

void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row
   , int col, char currentPlayer){
   //stack<char*> dir;
   board[row][col] = currentPlayer;
   for (int r = -1; r <= 1; r++){ //check every direction
      for (int c = -1; c <= 1; c++){
         int bRow = row + r, bCol = col + c, count = 0; //go in that direction 
         while (InBounds(bRow, bCol) && (board[bRow][bCol] != 0)){ //while valid (in bound and not empty)
            if (board[bRow][bCol] != currentPlayer) //true if that room contain enemy
               count++;
            else{ //room contain player
               if (count > 0){
                  for (; count > 0; count--){
                     bRow -= r,bCol -= c;
                     board[bRow][bCol] = currentPlayer;
                  }
               }
               break;
            }
            bRow += r;
            bCol += c;
         }

      }
   }
}

void GetMove(int *row, int *col){
   char tmp;
   cin >> tmp >> *row >> tmp >> *col >> tmp;
}

int GetValue(char board[BOARD_SIZE][BOARD_SIZE]){
   int count = 0;
   for (int row = 0; row < BOARD_SIZE; row++){
      for (int col = 0; col < BOARD_SIZE; col++){
         count += board[row][col];
      }
   }
   return count;
}