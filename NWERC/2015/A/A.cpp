#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Researcher {
	int arrives;
	int stays;
	Researcher(int arrives = 0, int stays = 0) : arrives(arrives), stays(stays) {}
};

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<Researcher> researchers(n);
	for (int i = 0; i < n; i++) scanf("%d%d", &researchers[i].arrives, &researchers[i].stays);
	sort(researchers.begin(), researchers.end(), [](const Researcher &a, const Researcher &b){
		if (a.arrives != b.arrives) return a.arrives < b.arrives;
		return a.stays > b.stays;
	});
	int sol = 1;
	for (int i = 0; i < n; ) {
		int j;
		int maxv = -1;
		int maxj = -1;
		for (j = i + 1; j < n && researchers[j].arrives <= researchers[i].arrives + researchers[i].stays + m; j++)
			if (researchers[j].stays > maxv) {
				maxv = researchers[j].stays;
				maxj = j;
			}
		if (maxj == -1) sol++;
		i = j;
	}
	printf("%d", sol);
}