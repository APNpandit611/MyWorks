#include <iostream>
using namespace std;
/*
**** Steps to find the solution of Sudoku puzzle ****
#1 : As sudoku is 9x9 grid puzzle, first step is to find the empty spaces in the row and column
#2 : if blank space found, insert the guess and check if the guess is valid
#3 : to check if the guess is right, we first check the row, column and then sub 3x3 grid box if the
      guess is already there. if the guess is not valid use the backtracking operation
      to find the valid guess.
      And if validation process failed, the solution doesnt Exist
#4 : use the recursive function to continue the process until none of the empty spaces are left
*/
bool find_empty_space(int sudoku[9][9], int *r, int *c){
  // check if there's any empty space to add in the guess
  for (*r = 0; *r < 9; (*r)++){
    for (*c = 0; *c < 9; (*c)++){
      if(sudoku[*r][*c] == 0)
      {
        return true;
      }
    }
  }
  return false;
}

bool isValid(int sudoku[9][9], int row, int col, int guess){
  // #3 validiting the number in the row.
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[row][i] == guess)
        {
            return false;
        }
    }
    // #validating the guess number in the col
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[i][col] == guess)
        {
            return false;
        }
    }
    // #3 validating the position for entire 3x3 sub grid.
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            if(sudoku[i][j] == guess)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudo_solver(int sudoku[9][9]){
  int row = 0, col = 0;
  if(!find_empty_space(sudoku, &row, &col)){
    return true;
  }
  for (int guess = 1; guess <= 9; guess++) {
    if(isValid(sudoku, row, col, guess)){
      sudoku[row][col] = guess;
      if(sudo_solver(sudoku)){
          return true;
      }
      sudoku[row][col] = 0; //reset the grid back to 0 if guess is not valid
    }
  }
  return false;
}

void print_solution_board(int sudoku[9][9])
{
    for(int i=1;i<=9;i++)
    {
        cout <<"| ";
        for(int j=1;j<=9;j++)
        {
            cout<<sudoku[i-1][j-1]<<" ";
            if(j%3 == 0) cout << "| ";
        }
        cout<<endl;
        if(i%3 == 0) cout << "--------+-------+--------" << endl;
    }
}

int main(){
  int sudoku[9][9] = {
  {0, 2, 0, 6, 0, 8, 0, 0, 0},
  {5, 8, 0, 0, 0, 9, 7, 0, 0},
  {0, 0, 0, 0, 4, 0, 0, 0, 0},
  {3, 7, 0, 0, 0, 0, 5, 0, 0},
  {6, 0, 0, 0, 0, 0, 0, 0, 4},
  {0, 0, 8, 0, 0, 0, 0, 1, 3},
  {0, 0, 0, 0, 2, 0, 0, 0, 0},
  {0, 0, 9, 8, 0, 0, 0, 3, 6},
  {0, 0, 0, 3, 0, 6, 0, 9, 0}};
  system("clear");
  // printing the board of 9x9
  cout<<"-------------------------"<<endl;
  for(int i=1;i<=9;i++)
  {
      cout <<"| ";
      for(int j=1;j<=9;j++)
      {
          cout<<sudoku[i-1][j-1]<<" ";
          if(j%3 == 0) cout << "| ";
      }
      cout<<endl;
      if(i%3 == 0) cout << "--------+-------+--------" << endl;
  }

//  cout<<"-------------------------"<<endl;
  if(sudo_solver(sudoku) == true){
    cout<<"         SOLVED!         "<<endl;
    cout<<"-------------------------"<<endl;
    print_solution_board(sudoku);
  }
  else{
    cout << "The Solution doesnt Exist!!" << endl;
  }
}
