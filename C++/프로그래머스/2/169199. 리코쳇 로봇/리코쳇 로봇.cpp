#include <bits/stdc++.h>

using namespace std;

int px[4] = {-1, 1, 0, 0};
int py[4] = {0, 0, -1, 1};

int solution(vector<string> board) {
    int answer = 0;
    
    int h = board.size();
    int w = board[0].length();
    
    // 그 위치에서 위로 갔으면 0, 아래면 1, 왼쪽은 2, 오른쪽은 3
    int check[100][100][4] = {0, };
    
    int x = -1, y = -1;
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(board[i][j] == 'R')
            {
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    int cnt = q.size();
    
    while(!q.empty())
    {
        if(cnt == 0)
        {
            answer++;
            cnt = q.size();
        }
        
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt--;
        
        for(int i = 0; i < 4; i++)
        {
            int len = 1;
            int dx = x , dy = y;
            check[dx][dy][i] = 1;
            while(1)
            {
                dx = x + px[i] * len;
                dy = y + py[i] * len;
                
                if(dx < 0 || dy < 0 || dx >= h || dy >= w || board[dx][dy] == 'D')
                {
                    if(len == 1) break;
                    
                    dx -= px[i];
                    dy -= py[i];
                    q.push({dx, dy});
                    if(board[dx][dy] == 'G')
                    {
                        return answer + 1;
                    }
                    break;
                }
                if(check[dx][dy][i] == 1) break;
                
                check[dx][dy][i] = 1;
                len++;
            }
        }
    }
    answer = -1;
    return answer;
}