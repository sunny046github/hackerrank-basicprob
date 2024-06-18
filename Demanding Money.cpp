
#include <bits/stdc++.h>

using namespace std;

using tint=int;
#define int long long
vector<int> c;
int n;
class E;
vector<list<E>> e;
using T=array<int,2>;

class E {
    list<E>::iterator it;
    int v;
    public:
    static void insert(int a, int b) {
        E x; x.v=b; e[a].push_front(x); x.it=e[a].begin();
        x.v=a; e[b].push_front(x); x.it->it=e[b].begin();
    };
    list<E>::iterator erase() {
        auto tmp=*it;
        e[v].erase(it);
        return e[tmp.v].erase(tmp.it);
    };
    operator int() const {return v;}
};

T dfs(int i, vector<bool>&v) { //random node selection
    T r={i,1};
    v[i]=1;
    for(int x : e[i]) {
        if(!v[x]) {
            T tmp=dfs(x,v); r[1]+=tmp[1];
            if(rand()%r[1]<tmp[1]) r[0]=tmp[0];
        }
    }
    return r;
}

void reduce(T& a, const T& b) {
    a[0]+=b[0];
    a[1]*=b[1];
}

T dop(int i) {
    if(e[i].empty())return {c[i],c[i]?1:2};
    vector<int> p;
#define edo(p,x) for(auto it=x.begin();it!=x.end();it=it->erase())p.push_back(*it)
    edo(p,e[i]);
    vector<bool> v(n);
    T r={0,1};for(auto x : p)if(!v[x])reduce(r,dop(dfs(x,v)[0]));
    vector<vector<int>> p2(p.size());
    for(int i=0;i<p.size();i++)edo(p2[i],e[p[i]]);
#undef edo
    v.assign(n,0);for(auto x:p)v[x]=1;T r2={c[i],1};for(auto&x:p2)for(auto y:x)if(!v[y])reduce(r2,dop(dfs(y,v)[0]));
    for(int i=0;i<p2.size();i++)for(auto x : p2[i])E::insert(p[i],x);
    for(auto x : p)E::insert(i,x);
    return r[0]==r2[0]?T{r[0],r[1]+r2[1]}:r[0]>r2[0]?r:r2;
}

tint main() {
    int m;cin>>n>>m;
    c.resize(n);e.resize(n);for(auto&x:c)cin>>x;
    for(int i=0;i<m;i++) { int x,y; cin>>x>>y; E::insert(x-1,y-1); }
    T r={0,1};vector<bool> v(n);for(int i=0;i<n;i++)if(!v[i])reduce(r,dop(dfs(i,v)[0]));
    cout<<r[0]<<" "<<r[1]<<endl;
    return 0;
}
