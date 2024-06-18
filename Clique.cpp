
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <cstring>
#include <stack>
#include <bitset>

using namespace std;

#define NMAX 2147483647
#define LMAX 9223372036854775807LL
#define pb push_back
#define pob pop_back
#define mp make_pair
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>(b);--i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)

int solve1(int n,int k)
{
  int g1 = n%k ;
  int g2 = k - g1 ;
  int sz1 = n/k + 1 ;
  int sz2 = n/k ;
  int ret = g1*sz1*g2*sz2 + g1*(g1-1)*sz1*sz1/2 + g2*(g2-1)*sz2*sz2/2 ;
  return ret ;
}

int solve(int n,int e)
{
  int k,low = 1,high = n + 1 ;
  while(low + 1 < high)
  {
    int mid = low + (high - low)/2 ;
    k = solve1(n,mid) ;
    if(k < e) low = mid ;
    else high = mid ;
  }
  return high ;
}

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int TS;
  scanf("%d",&TS);
  FORE(ts,1,TS)
  {
    int N, M;
    scanf("%d%d",&N,&M);
    printf("%d\n",solve(N,M));
  }
  return 0;
}
