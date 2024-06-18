
#include<cstdio>
#include<algorithm>
#define UP(i,a,b) for(i=a;i<=(b);++i)
#define DN(i,a,b) for(i=a;i>=(b);--i)

using std::max;

int p,d,m,s,ans;

int main(){
	scanf("%d%d%d%d",&p,&d,&m,&s);
	while(s>=p){
		s-=p;p=max(p-d,m);++ans;
	}
	printf("%d\n",ans);
	return 0;
}
