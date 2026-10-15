#include <string>
#include <vector>

using namespace std;

int s = 0;
int answer = 0;

void dfs(int cnt, vector<int> numbers, int target) {
	if(cnt == numbers.size()) {
		if(s == target) {
			answer++;
		}
		return;
	}

	s += numbers[cnt];
	dfs(cnt + 1, numbers, target);
	s -= numbers[cnt];
	s -= numbers[cnt];
	dfs(cnt + 1, numbers, target);
	s += numbers[cnt];

}

int solution(vector<int> numbers, int target) {
    dfs(0, numbers, target);
    return answer;
}