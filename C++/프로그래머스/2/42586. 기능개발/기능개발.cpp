#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> work;
    
    for(int i = 0; i < progresses.size(); i++) {
    	int k = (100-progresses[i])/speeds[i];
    	if((100-progresses[i])%speeds[i] == 0) {
    		work.push(k);
		}
		else work.push(k+1);
	}
    
    
    int cnt = 1;
    int highest = 0;
    while(!work.empty()){
    	if(highest < work.front()) {
    		if(highest != 0) answer.push_back(cnt);
    		highest = work.front();
    		work.pop();
    		cnt = 1;
		}
		else {
			cnt++;
			work.pop();
		}
	}
	answer.push_back(cnt);
    
    return answer;
}