#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int x = routes.size();

    vector<vector<pair<int, int>>> path(x);
    int maxT = 0;
    for (int i = 0; i < x; i++) {
        int r = points[routes[i][0] - 1][0];
        int c = points[routes[i][0] - 1][1];
        path[i].push_back({r, c});                 

        for (int k = 1; k < routes[i].size(); k++) {
            int tr = points[routes[i][k] - 1][0];
            int tc = points[routes[i][k] - 1][1];
            while (r != tr) {                 
                r += (tr > r) ? 1 : -1;
                path[i].push_back({r, c});
            }
            while (c != tc) {                  
                c += (tc > c) ? 1 : -1;
                path[i].push_back({r, c});
            }
        }
        maxT = max(maxT, (int)path[i].size());
    }

    static bitset<100> grid[101][101];
    vector<pair<int, int>> touched;             

    for (int t = 0; t < maxT; t++) {
        touched.clear();
        for (int i = 0; i < x; i++) {
            if (t >= path[i].size()) continue;      
            auto [r, c] = path[i][t];
            if (grid[r][c].none()) touched.push_back({r, c});
            grid[r][c].set(i);
        }
        for (auto [r, c] : touched) {
            if (grid[r][c].count() >= 2) answer++;      
            grid[r][c].reset();      
        }
    }

    return answer;
}