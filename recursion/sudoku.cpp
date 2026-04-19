#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, char dig){
    //horizontal

    for(int j = 0; j<9; j++){
        if(board[row][j] == dig){
            return false;
        }
    }
    //vertical
    for(int i = 0; i<9; i++){
        if(board[i][col] == dig){
            return false;
        }
    }

    //for starting row and column
    int sr = (row/3) * 3, sc = (col/3) * 3;

    for(int i = sr; i<=sr+2; i++){
        for(int j = sc; j<=sc+2; j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }
    return true;
}
void print(vector<string> &board, int row, int col){
    for(string val : board){
        cout<<val<<" "<<endl;
    }
    cout<<endl;
}

bool sudokuSolver(vector<string> &board, int row, int col){

    if(row == 9){
        print(board, row, col);
        return true;
    }


    int nextRow = row, nextCol = col + 1;
    if(nextCol == 9){
        nextRow = row + 1;
        nextCol = 0;
    }
    if(board[row][col] != '.'){
        return sudokuSolver(board, nextRow, nextCol);
    }
    for(char dig = '1'; dig <= '9'; dig++){
        if(isSafe(board, row, col, dig)){
            board[row][col] = dig;
            if(sudokuSolver(board, nextRow, nextCol)){
                return true;
            }

            board[row][col] = '.';
        }
    }
    return false;

}


int main(){
   vector<string> board = {
"53..7....",
"6..195...",
".98....6.",
"8...6...3",
"4..8.3..1",
"7...2...6",
".6....28.",
"...419..5",
"....8..79"
};
//(9, string(9, '.'));

   sudokuSolver(board, 0 , 0);

   return 0;
}

