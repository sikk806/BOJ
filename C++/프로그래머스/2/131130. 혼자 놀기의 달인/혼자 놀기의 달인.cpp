#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
    int check[101] = {0, };
    vector<int> nums;
    
    for(int i = 1; i <= cards.size(); i++)
    {
        if(check[i] == 1) continue;
        check[i] = 1;
        int k = cards[i - 1];
        int cnt = 1;
        
        while(check[k] != 1)
        {
            cnt++;
            check[k] = 1;
            k = cards[k - 1];
        }
        
        nums.push_back(cnt);
    }
    
    if(nums.size() == 1) return 0;
    
    for(int i = 0; i < nums.size() - 1; i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            answer = max(answer, nums[i] * nums[j]);
        }
    }
    
    
    return answer;
}