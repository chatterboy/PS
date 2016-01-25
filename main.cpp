#include <cstdio>

struct Node {
	char c;
	bool terminal;
	Node * children[10];
	Node(char c = 0) : c(c), terminal(false) {
		for (int i = 0; i < 10; ++i) children[i] = NULL;
	}
};

int n;
Node root;

void insert(Node * p, char * c) {
	if (*c == NULL) p->terminal = true;
	else {
		if (p->children[*c - '0'] == NULL)
			p->children[*c - '0'] = new Node(*c);
		insert(p->children[*c - '0'], c + 1);
	}
}

bool travel(Node * p) {
	bool leaf = true;
	for (int i = 0; i < 10; ++i)
		leaf &= p->children[i] == NULL;
	if (leaf) return true;
	if (!leaf && p->terminal) return false;
	bool ret = true;
	for (int i = 0; i < 10; ++i)
		if (p->children[i] != NULL)
			ret &= travel(p->children[i]);
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			char s[11] = {};
			scanf("%s", s);
			insert(&root, s);
		}
		if (travel(&root)) puts("YES");
		else puts("NO");
		root = Node();
	}
}