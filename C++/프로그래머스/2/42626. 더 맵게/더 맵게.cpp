#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> q;
    for(int i : scoville)
    {
        q.push(-i);
    }
    
    while(q.size() > 1)
    {
        if(-q.top() >= K) break;
        int x = -q.top();
        q.pop();
        int y = -q.top();
        q.pop();
        
        q.push(-(x + y * 2));
        answer++;
    }
    
    if(q.size() == 1)
        if(-q.top() < K) return -1;
    
    return answer;
}