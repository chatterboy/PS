#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<int,string> tb;
void preprocess() {
	tb[1] = "one"; tb[2] = "two"; t
}
int len(int x) {

}
int main() {
	int N, i, num;
	vector<string> words;
	cin >> N;
	words.resize(N);
	for (i = 0; i < N; i++)
		cin >> words[i];
	int lens = 0;
	for (i = 0; i < N; i++)
		if (words[i] != "$")
			lens += words[i].size();
	for (num = 0; num < 1000; num++)
		if (lens + len(num) == num) {
			// output
			break;
		}
}