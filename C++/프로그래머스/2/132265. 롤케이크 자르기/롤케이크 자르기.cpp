#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> left_topping;
    map<int, int> right_topping;
    
    for(int i = 0; i < topping.size(); i++)
    {
        right_topping[topping[i]]++; 
    }
    
    for(int i = 0; i < topping.size() - 1; i++)
    {
        left_topping[topping[i]]++;
        
        right_topping[topping[i]]--;
        if(right_topping[topping[i]] == 0) right_topping.erase(topping[i]);
        
        if(left_topping.size() == right_topping.size()) answer++;
    }
    
    return answer;
}