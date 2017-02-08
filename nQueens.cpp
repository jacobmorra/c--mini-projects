#include<iostream>
#define N 8 //set board size

using namespace std;

/* print the board */
void printBoard(int board[N][N]) {
   int i,j;
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
           cout<<board[i][j]<<" ";
      }
      cout<<endl;
   }
}

/* check if board position is safe for placement */    
bool isSafe(int board[N][N], int row, int col) {
   int i, j;

   /*check left of position*/
   for (i = 0; i < col; i++) {
      if (board[row][i] == 1) {
         return false;
      }
   }

   /*check above position*/
   for (j = 0; j < row; j++) {
      if (board[j][col] == 1) {
         return false;
      }
   }

   i = row; j = col; //set i,j to arg coordinates 
   
   /* check upper left diag */
   while (i >= 0 && j >= 0) {
      if (board[i][j] == 1) {
         return false;
      }
      i--; j--;
   }

   i = row; j = col; //set i,j to arg coordinates
   
   /* check lower left diag */
   while (i < N && j >= 0) {   
      if (board[i][j] == 1) {
         return false;
      }
      i++; j--;
   }

   return true;
}

/* Algorithm nQueens(board[][], # of columns) 
   From (0,0), traverses board[][] and places a total
   of N queens.
   The algorithm "backs up" when there is a placement 
   conflict.
*/
bool nQueens(int board[N][N], int col) {
   if (col >= N) {
      return true;
   }

   int i;
   for (i = 0; i < N; i++) {
      if (isSafe(board, i, col)) {
         /* place a queen at (i,col) */
         board[i][col] = 1;

         /* traverse remaining columns and place queens */
         if (nQueens(board, col + 1) == true )
            return true;

         board[i][col] = 0;
      }
   }

   return false;
}


// main
int main() {
   
   int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0} };
   
   bool n_queens_sol = nQueens(board,0);
   
   if (n_queens_sol){
      printBoard(board);
   }
   
   cout<<endl;
   
   return 0;
}