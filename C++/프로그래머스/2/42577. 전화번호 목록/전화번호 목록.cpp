#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++)
    {
        if(phone_book[i+1].rfind(phone_book[i], 0) == 0)
        {
            return false;
        }
    }
    return answer;
}