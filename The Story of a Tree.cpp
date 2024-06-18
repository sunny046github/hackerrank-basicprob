#include <vector>
#include <map>
#include <algorithm>

const int kN = 200000 + 5;

int n;
std::vector<int> edges[kN];
int dfn[kN], ed[kN], stmp, parent[kN];

void dfs(int u, int fa)
{
    parent[u] = fa;
    dfn[u] = stmp ++;
    for (int v : edges[u]) if (v != fa) {
        dfs(v, u);
    }
    ed[u] = stmp - 1;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

std::map<int, int> count;

struct SegmentTree {
    bool in[kN << 2];
    int t[kN << 2];

    void modify(int L, int R, int dt, int l, int r, int rt)
    {
        if (R < l || r < L) return ;
        in[rt] = true;
        if (L <= l && r <= R) {
            t[rt] += dt;
            return ;
        }
        int mid = l + r >> 1;
        modify(L, R, dt, l, mid, rt << 1);
        modify(L, R, dt, mid + 1, r,rt << 1 | 1);
    }

    int calc(int val, int l, int r, int rt)
    {
        if (in[rt] == false) return 0;
        int mid = l + r >> 1;
        val += t[rt];
        int total = r - l + 1;
        if (in[rt] && l != r) {
            total -= calc(val, l, mid, rt << 1);
            total -= calc(val, mid + 1, r, rt << 1 | 1);
        }
        count[val] += total;
        in[rt] = false;
        t[rt] = 0;
        return r - l + 1;
    }
} sgt;

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) edges[i].clear();
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b); a --; b --;
            edges[a].emplace_back(b);
            edges[b].emplace_back(a);
        }
        stmp = 0;
        dfs(0, -1);
        int g, k;
        scanf("%d%d", &g, &k);
        for (int i = 0; i < g; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b); a --; b --;
            if (parent[b] == a) {
                sgt.modify(0, dfn[b] - 1, 1, 0, n - 1, 1);
                sgt.modify(ed[b] + 1, n - 1, 1, 0, n - 1, 1);
            } else {
                sgt.modify(dfn[a], ed[a], 1, 0, n - 1, 1);
            }
        }
        count.clear();
        sgt.calc(0, 0, n - 1, 1);
        int a = 0, b = n;
        for (auto t : count) {
            if (t.first >= k) {
                a += t.second;
            }
        }
        int r = gcd(a, b);
        a /= r;
        b /= r;
        printf("%d/%d\n", a, b);
    }
}
