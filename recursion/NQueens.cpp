#include<iostream>
#include<vector>
using namespace std; 

bool isSafe(vector<string> &board, int n , int row, int col){
    for(int j = 0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    for(int i = 0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void NQueens(vector<string> &board, int n, int row){
    if(row == n){
       for(string val : board){
        cout<<val<<" ";
       }
       cout<<endl;
       return;
    }
    for(int j = 0; j<n; j++){
        if(isSafe(board, n , row, j)){
            board[row][j] = 'Q';
            NQueens(board, n, row+1);
            board[row][j] = '.';
        }
    }
}

int main(){
    vector<string> board(4, string( 4, '.'));
   
    NQueens(board, 4, 0);

    return 0;
}