#include <bits/stdc++.h>
using namespace std;

int main() {
	list<char> s;
	char c;
	while ((c = getchar()) != '\n')
		s.push_back(c);
	
	int N;
	scanf("%d\n", &N);
	auto p = s.end();
	while (N--) {
		char cmd;
		scanf("%c", &cmd);
		if (cmd == 'L') {
			if (p != s.begin())
				p--;
		} else if (cmd == 'D') {
			if (p != s.end())
				p++;
		} else if (cmd == 'B') {
			if (p != s.begin()) {
				auto pp = p;
				pp--;
				s.erase(pp);
			}
		} else {
			char c;
			scanf(" %c", &c);
			s.insert(p, c);
		}
		scanf("\n");
	}

	for (auto c : s)
		putchar(c);
	return 0;
}