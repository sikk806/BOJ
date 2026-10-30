#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size();
    int m = maps[0].size();
    
    int check[100][100] = {0, };
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maps[i][j] == 'X') continue;
            if(check[i][j] == 1) continue;
            check[i][j] = 1;
            
            int total = 0;
            queue<pair<int, int>> q;
            
            q.push({i, j});
            
            while(!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                total += (maps[x][y] - '0');
                
                for(int a = 0; a < 4; a++)
                {
                    int next_x = x + dx[a];
                    int next_y = y + dy[a];
                    
                    if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
                    if(check[next_x][next_y] == 1) continue;
                    if(maps[next_x][next_y] == 'X') continue;
                    q.push({next_x, next_y});
                    check[next_x][next_y] = 1;
                }
            }
            
            answer.push_back(total);
        }
    }
    
    if(answer.size() == 0)
    {
        return {-1};
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}