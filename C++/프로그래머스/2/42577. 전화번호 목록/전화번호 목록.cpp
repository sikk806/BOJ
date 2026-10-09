#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_set<string> s;
    unordered_set<string> pb;
    
    for(int i = 0; i < phone_book.size(); i++)
    {        
        string str = "";
        
        pb.insert(phone_book[i]);
        
        for(int j = 0; j < phone_book[i].length() - 1; j++)
        {
            str += phone_book[i][j];
            
            if(pb.find(str) != pb.end())
                return false;
            
            s.insert(str);
        }
        
        if(s.find(phone_book[i]) != s.end())
        {
            return false;
        }
    }
    
    return answer;
}