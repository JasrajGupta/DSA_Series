#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &board, int r, int c, string path, vector<string> &ans){
    int n = board.size();

    if(r < 0 || c < 0 || r >= n || c >= n || board[r][c] == 0 || board[r][c] == -1){
        return;
    }

    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    board[r][c] = -1;

    helper(board, r+1, c, path + "D", ans);
    helper(board, r-1, c, path + "U", ans);
    helper(board, r, c-1, path + "L", ans);
    helper(board, r, c+1, path + "R", ans);

    board[r][c] = 1;
}

vector<string> ratInMaze(vector<vector<int>> &board){
    vector<string> ans;
    string path = "";

    helper(board, 0, 0, path, ans);

    return ans;
}

int main(){

    vector<vector<int>> board = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    vector<string> ans = ratInMaze(board);

    for(string val : ans){
        cout << val << endl;
    }

    return 0;
}