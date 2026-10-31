#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> tang;
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        tang[tangerine[i]]++;
    }
    
    vector<pair<int, int>> vec(tang.begin(), tang.end());
    
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    for(int i = 0; i < vec.size(); i++)
    {
        k -= vec[i].second;
        answer++;
        if(k <= 0) break;
    }
    
    
    
    return answer;
}