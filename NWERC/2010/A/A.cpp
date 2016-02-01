#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Friend {
	int id;
	int canPay;
	int paid;
	Friend(int id = 0, int canPay = 0, int paid = 0) : id(id), canPay(canPay), paid(paid) {}
};

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int p, n; scanf("%d%d", &p, &n);
		vector<Friend> friends(n);
		int total = 0;
		for (int i = 0; i < n; i++) {
			int w; scanf("%d", &w);
			friends[i] = Friend(i, w);
			total += w;
		}
		if (total < p) { puts("IMPOSSIBLE"); continue; }
		sort(friends.begin(), friends.end(), [](const Friend &a, const Friend &b){
			if (a.canPay != b.canPay) return a.canPay > b.canPay;
			return a.id < b.id;
		});
		int changes = p % n;
		for (auto &fnd : friends) fnd.paid += p / n;
		for (auto &fnd : friends) if (fnd.paid > fnd.canPay) {
			changes += fnd.paid - fnd.canPay;
			fnd.paid = fnd.canPay;
		}
		while (changes > 0)
			for (int i = 0; i < n && changes > 0; i++) if (friends[i].canPay - friends[i].paid > 0) friends[i].paid++, changes--;
		sort(friends.begin(), friends.end(), [](const Friend &a, const Friend &b){ return a.id < b.id; });
		for (auto fnd : friends) printf("%d ", fnd.paid); puts("");
	}
}