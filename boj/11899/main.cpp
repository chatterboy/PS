// 올바르지 않은 괄호 문자열이 주어졌을 때, 올바르게 만들기 위해
// 앞과 뒤에 붙여야 할 괄호의 최소 개수

#include <bits/stdc++.h>
using namespace std;

int main() {
	char S[51] = {};
	scanf("%s", S);
	int N = strlen(S);
	int nmr;// 매칭되지 않은 ')'의 수
	int nml;// 매칭되지 않은 '('의 수
	nmr = nml = 0;
	stack<char> st;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(')
			st.push(S[i]);
		else {
			if (st.empty()) {
				nmr++;
				continue;
			}
			st.pop();
		}
	}
	while (!st.empty()) {
		nml++;
		st.pop();
	}
	printf("%d", nml + nmr);
}