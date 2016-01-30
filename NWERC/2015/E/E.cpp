#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> inputs;
	vector<pair<int, int>> answers;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		inputs.push_back(make_pair(a, b));
		answers.push_back(make_pair(a + b, i));
		answers.push_back(make_pair(a - b, i));
		answers.push_back(make_pair(a * b, i));
	}
	sort(answers.begin(), answers.end());
	vector<pair<int, pair<char, int>>> sols;
	for (auto input : inputs) {
		bool found = false;
		int cands[] = {input.first + input.second, input.first - input.second, input.first * input.second};
		char ops[] = {'+', '-', '*'};
		for (int i = 0; i < 3; i++) {
			int lo = lower_bound(answers.begin(), answers.end(), cands[i], [](){
				
			});
			int hi = upper_bound(answers.begin(), answers.end(), cands[i], [](){

			});
			int init = answers[lo].second;
			bool duplicate = false;
			for (int j = lo + 1; j < hi; j++) if (init != answers[j].second) {
				duplicate = true;
				break;
			}
			if (!duplicate) {
				sols.push_back(make_pair(input.first, make_pair(ops[i], input.second)));
				found = true;
				break;
			}
		}
		if (!found) { printf("impossible"); return 0; }
	}
	for (auto sol : sols) {
		printf("%d %c %d = ", sol.first, sol.second.first, sol.second.second);
		switch (sol.second.first) {
			case '+': printf("%d\n", sol.first + sol.second.second) break;
			case '-': printf("%d\n", sol.first - sol.second.second) break;
			case '*': printf("%d\n", sol.first * sol.second.second) break;
		}
	}
}