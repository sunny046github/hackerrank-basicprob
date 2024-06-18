
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10, maxm = (int)2e6 + 10;
char s[maxm];
int len;

struct point {
	int ed[26];
	int lnk;
	int par;
	int c;
	vector <int> pos;

	point() {
		memset(ed, -1, sizeof ed);
		lnk = -1;
		par = -1;
		c = -1;
	}
};

point mas[maxm];
int posit = 0;

int my_new() {
	return posit++;
}

void add(int it, int pos, int num) {
	if (pos == len) {
		mas[it].pos.push_back(num);
		return;
	}

	int c = s[pos] - 'a';

	if (mas[it].ed[c] == -1) {
		mas[it].ed[c] = my_new();
		int nit = mas[it].ed[c];

		mas[nit].par = it;
		mas[nit].c = c;
	}

	add(mas[it].ed[c], pos + 1, num);
}

int h[maxn];
int l[maxn], r[maxn];

vector <int> z[maxm];

int getlnk(int it);

int go(int it, int c) {
	if (mas[it].ed[c] != -1) {
		return mas[it].ed[c];
	}

	if (it == 0) {
		mas[it].ed[c] = 0;
	} else {
		mas[it].ed[c] = go(getlnk(it), c);
	}

	return mas[it].ed[c];
}

int getlnk(int it) {
	if (mas[it].lnk != -1) {
		return mas[it].lnk;
	}

	if (it == 0 || mas[it].par == 0) {
		mas[it].lnk = 0;
	} else {
		mas[it].lnk = go(getlnk(mas[it].par), mas[it].c);
	}

	return mas[it].lnk;
}

vector <int> ed[maxm];
ll ans[maxn];
ll tr[maxn];

void change(int pos, int x) {
	for ( ; pos < maxn; pos |= pos + 1) {
		tr[pos] += x;
	}
}

ll getsum(int pos) {
	ll ans = 0;

	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += tr[pos];
	}

	return ans;
}

ll gores(int l, int r) {
	return getsum(r) - getsum(l - 1);
}

void dfs(int v) {
	for (int i = 0; i < (int)mas[v].pos.size(); i++) {
		int g = mas[v].pos[i];

		change(g, h[g]);
	}

	for (int i = 0; i < (int)z[v].size(); i++) {
		int num = z[v][i];

		int lm = l[num];
		int rm = r[num];

		ans[num] += gores(lm, rm);
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs(u);
	}

	for (int i = 0; i < (int)mas[v].pos.size(); i++) {
		int g = mas[v].pos[i];

		change(g, -h[g]);
	}
}

int main() {
	int n;

	cin >> n;

	int tr = my_new();

	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		len = strlen(s);

		add(tr, 0, i);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}

	int q;

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		scanf("%d %d %s", &l[i], &r[i], s);

		len = strlen(s);

		int it = tr;

		for (int j = 0; j < len; j++) {
			it = go(it, s[j] - 'a');

			z[it].push_back(i);
		}
	}

	ll mins = (ll)1e18;
	ll maxs = 0;

	for (int i = 1; i < posit; i++) {
		ed[getlnk(i)].push_back(i);
	}

	dfs(0);

	for (int i = 0; i < q; i++) {
		mins = min(mins, ans[i]);
		maxs = max(maxs, ans[i]);
	}

	cout << mins << ' ' << maxs << endl;

	return 0;
}
