#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        if(q.front().first == pq.top())
        {
            if(q.front().second == location) return answer + 1;
            pq.pop();
            q.pop();
            answer++;
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}