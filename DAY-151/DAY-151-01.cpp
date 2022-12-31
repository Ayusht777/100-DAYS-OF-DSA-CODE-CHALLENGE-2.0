#include <bits/stdc++.h>
using namespace std;
// Sudoku Solver 
//https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919

bool isSafe(int row,int col,vector<vector<int>>& board,int val){
    for(int i=0;i<9;i++){
        //row check
        if(board[row][i]==val){
            return false;
        }
        //col check 
        if(board[i][col] ==val){
            return false;
        }
        //3*3 matrxi check
        if(board[3*(row/3) + i/3][3*(col/3) +i%3] ==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& board){
    for(int row = 0;row<9;row++){
        for(int col = 0;col<9;col++){
            //cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] =val;
                        //recusrive call
                        bool nextsoultionPossible =solve(board);
                        if(nextsoultionPossible ){
                            return true;
                        }
                        else{
                            //backtracking
                            board[row][col] =0;
                        }
                    }
                    
                }
                return false;
            }
        }
        
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}