#include <cstdio>
int main() {
	int n, no[26] = {0};
	scanf("%d", &n);
	while (n--) {
		char name[31] = {0};
		scanf("%s", name);
		no[name[0]-'a']++;
	}
	bool sw = false;
	for (int i = 0; i < 26; i++)
		if (no[i] > 4) { putchar(i+'a'); sw = true; }
	if (!sw) printf("PREDAJA");
}