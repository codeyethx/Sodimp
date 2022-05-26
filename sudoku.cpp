/*
@description: Given an arbitrary input puzzle, this program will compute an assignment of empty grid cells to integers 1 to 9, and solve the puzzle.
@file: sudoku.cpp
@author: Gift Chidera Uwakwe
@date: 03/15/2021
*/

#include <iostream>

const int ROWS = 9;
const int COLS = 9;

/**
 * Read a sudoku board from standard input
 * @param sudoku_board contains the board after reading
 */
void read_board(int sudoku_board[ROWS][COLS]) {
    // TODO: Replace with your code.
    char g;
    bool flag = true;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            std::cin.get(g);
            if(g != '\n'){
                if(g == ' '){
                    sudoku_board[i][j] = 0;
                }
                else{
                    sudoku_board[i][j] = g - '0';

                }
            }
            else{
                j--;
            }
        }
    }
}
/**
 * Prints a sudoku board to standard output.
 * @param sudoku_board the board to print
 */
void write_board(int sudoku_board[ROWS][COLS]) {
    // TODO: Replace with your code.
    for(int h = 0; h < ROWS; h++)
    {
        for(int y = 0; y < COLS; y++)
        {
            std::cout << sudoku_board[h][y];
        }
        std::cout << std::endl;
    }
}
/**
 * Find an empty cell in the sudoku board.
 * @param sudoku_board the board to search through
 * @param row the row of the empty cell found
 * @param col the column of the empty cell found
 * @return true if an empty cell was found, false otherwise
 */

bool find_empty_cell(int sudoku_board[ROWS][COLS], int & row, int & col) {
     // TODO: Replace with your code.
    for (row = 0; row < ROWS; row++){
        for (col = 0; col < COLS; col++){
            if (sudoku_board[row][col] == 0){
                return true;
            }
        }
    }
    return false;
}
bool is_in_row(int puzzle[ROWS][COLS], int row, int check)
{
    for(int col = 0; col < COLS; col++)
    {
        if(puzzle[row][col] == check){
            return true;
        }
    }
    return false;
}
bool is_in_col(int puzzle[ROWS][COLS], int col, int check)
{
    for(int row = 0; row < COLS; col++)
    {
        if(puzzle[row][col] == 0){
            return true;
        }
    }
    return false;
}
bool is_in_box(int puzzle[ROWS][COLS], int bx_row, int bx_col, int check)
{
    for (int row = 0; row < 3; row++){
      for (int col = 0; col < 3; col++){
         if (puzzle[row+bx_row][col+bx_col] == check){
            return false;
         }
      }
    }
   return false;
}
/**
 * Solves a given sudoku board.
 * @param sudoku_board the sudoku board to solve
 */
bool is_solved(int sudoku_board[ROWS][COLS], int row, int col , int val)
{
    return !is_in_col(sudoku_board, col, val) && !is_in_row(sudoku_board, row, val) && is_in_box(sudoku_board, row - row%3, col - col%3, val);
}

void solve(int sudoku_board[ROWS][COLS],int num/* add additional parameters as needed */)
{
    int row, col;
    if(find_empty_cell(sudoku_board,row, col)){

        if(!(is_in_row(sudoku_board, row, num) && is_in_col(sudoku_board,col,num))){
            sudoku_board[row][col] = num;
        }
        else{
            sudoku_board[row][col] = 0;
        }
        if(num > 8){
            num = 0;
        }
        solve(sudoku_board, num + 1);
    }

}

// Do not modify code below this line, except to add additional parameters to solve.
int main() {
    int sudoku_board[ROWS][COLS] = {};
    read_board(sudoku_board);
    solve(sudoku_board,1);
    write_board(sudoku_board);
    return 0;;

}
