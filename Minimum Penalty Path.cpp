
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

vector<pii> w[nax];
bool vis[nax];

void dfs(int a, int answer) {
	vis[a] = true;
	for(pii edge : w[a]) {
		int b = edge.first;
		if(vis[b]) continue;
		int cost = edge.second;
		if((answer | cost) == answer)
			dfs(b, answer);
	}
}

bool are_connected(int a, int b, int answer, int n) {
	RI(i, n) vis[i] = false;
	dfs(a, answer);
	return vis[b];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		w[a].pb(mp(b,c));
		w[b].pb(mp(a,c));
	}
	int x, y;
	scanf("%d%d", &x, &y);
	const int K = 10; // the maximum number of bits
	int answer = (1 << K) - 1; // 1023
	if(!are_connected(x, y, answer, n)) {
		puts("-1");
		return 0;
	}
	for(int i = K - 1; i >= 0; --i)
		if(are_connected(x, y, answer - (1 << i), n))
			answer -= 1 << i;
	printf("%d\n", answer);
	return 0;
}
