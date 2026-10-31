#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> want_buy;
    for(int i = 0; i < want.size(); i++)
    {
        want_buy[want[i]] = number[i];
    }
    
    map<string, int> dis;    
    for(int i = 0; i < 10; i++)
    {
        dis[discount[i]]++;
    }
    
    if(want_buy == dis) answer++;
    
    for(int i = 10; i < discount.size(); i++)
    {
        dis[discount[i - 10]]--;
        if(dis[discount[i - 10]] == 0) dis.erase(discount[i - 10]);
        
        dis[discount[i]]++;
        
        if(want_buy == dis) answer++;
    }
    
    return answer;
}