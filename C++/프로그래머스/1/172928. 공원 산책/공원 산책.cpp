#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int current_x, current_y = -1;
    
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[0].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                current_x = i;
                current_y = j;
                
                break;
            }
        }
        
        if(current_y != -1) break;
    }
    
    for(int i = 0; i < routes.size(); i++)
    {
        char way = routes[i][0];
        int len = routes[i][2] - '0';
        
        int route;
        if(way == 'E') route = 0;
        else if(way == 'W') route = 1;
        else if(way == 'S') route = 2;
        else route = 3;
        
        for(int j = 1; j <= len; j++)
        {
            int px = current_x + dx[route] * j;
            int py = current_y + dy[route] * j;
            
            if(px < 0 || px >= park.size() || py < 0 || py >= park[0].size() || park[px][py] == 'X') break;
            
            if(j == len)
            {
                current_x = px;
                current_y = py;
            }
            
            cout << j << " ";
            cout << current_x << " " << current_y << endl;
        }
    }
    
    answer.push_back(current_x);
    answer.push_back(current_y);
    return answer;
}