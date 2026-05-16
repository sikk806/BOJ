#include <string>
using namespace std;

bool solution(string s) {
    int cnt = 0;

    for (char c : s) {
        cnt += c == '(' ? 1 : -1;

        if (cnt < 0) return false;
    }

    return cnt == 0;
}