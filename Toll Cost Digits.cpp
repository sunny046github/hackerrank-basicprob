#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int MAXN = 2e5 + 10;
const int VAL = 1e4;

int n;
vector<pair<int, int> > graph[MAXN];
vector<int> vertices;

bool visit[MAXN][20], check[MAXN];
int d[MAXN], new_d[MAXN];
long long res[20], cnt[VAL];
queue<pair<int, int> > queues;

void DFS(int s, int ds) {
    queues.push(make_pair(s, ds));
    visit[s][ds] = true;
    check[s] = true;
    while (!queues.empty()) {
        int u = queues.front().first, du = queues.front().second;
        queues.pop();
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first, w = graph[u][i].second;
            w = (w + du) % 10;
            if (!visit[v][w]) {
                if (!check[v]) {
                    d[v] = (1 << w);
                    vertices.push_back(v);
                } else {
                    d[v] += (1 << w);
                }
                check[v] = true;
                visit[v][w] = true;
                queues.push(make_pair(v, w));
            }
        }
    }
}

void compute() {
    for(int i = 0; i <= 9; i++) {
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < vertices.size(); j++) {
            int u = vertices[j], s = 0;
            for(int k = 0; k <= 9; k++) {
                if ((d[u] | (1 << k)) == d[u]) {
                    int t = (k + i) % 10;
                    s += (1 << t);
                }
            }
            new_d[u] = s;
            cnt[s]++;
        }
        for(int j = 0; j < vertices.size(); j++) {
            int u = vertices[j];
            for(int k = 0; k < (1 << 10); k++) {
                if (cnt[k] > 0) {
                    if ((k & d[u]) > 0) {
                        res[i] += cnt[k];
                    }
                }
            }
            if ((d[u] & new_d[u]) > 0) {
                res[i]--;
            }
        }
    }
}

int main(){
    int e;
    scanf("%d %d", &n, &e);
    for(int a0 = 0; a0 < e; a0++){
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        r %= 10;
        graph[x].push_back(make_pair(y, r));
        graph[y].push_back(make_pair(x, 10 - r));
    }
    memset(check, false, sizeof(check));
    for(int i = 1; i <= n; i++) {
        if (!check[i]) {
            vertices.clear();
            vertices.push_back(i);
            d[i] = 1;
            DFS(i, 0);
            compute();  
        }
    }
    
    for(int i = 0; i <= 9; i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}
