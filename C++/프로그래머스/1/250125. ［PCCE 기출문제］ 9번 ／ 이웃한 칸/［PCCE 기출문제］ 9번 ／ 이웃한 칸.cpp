#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int check[7][7] = {0, };
    int cur_x, cur_y;
    string cur_color = board[h][w];
    
    cur_x = h;
    cur_y = w;
        
    for(int i = 0; i < 4; i++)
    {
        int new_x = cur_x + dx[i];
        int new_y = cur_y + dy[i];
        if(new_x < 0 || new_y < 0 || new_x >= board.size() || new_y >= board[0].size()) continue;
        if(board[new_x][new_y] != cur_color) continue;
        answer++;
    }
    
    
    return answer;
}