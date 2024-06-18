
#include <bits/stdc++.h>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define UP upper_bound
#define LB lower_bound
#define LL long long 
#define Pi 3.14159265358
#define si size()
#define en end()
#define be begin()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii set<int>::iterator
#define Tree int ind, int L, int R
#define Left 2*ind,L,(L+R)/2
#define Right 2*ind+1,(L+R)/2+1,R
using namespace std;
bool f[20][20];
string s[20];
int n, m, k, i, j, res, x;
bool check(int i, int j, int x)
{
     int I=i;	
     while(s[I][j]=='G' && I<=n && !f[I][j])
	   I++;	
	 if(I-i<x)return false;
	 I=i+x/2;
	 int J=i;
	 while(s[I][J]=='G' && J<=m && !f[I][J])
	   J++;
	 if(J-j<(x+1)/2)return false;
	 J=i;
	 while(s[I][J]=='G' && J>=1 && !f[I][J])
	   J--;
	 if(j-J<(x+1)/2)return false;
	 return true;
			   	 	  	 
}
int main(){
	   cin>>n>>m;
	   for(i=1;i<=n;i++)
	    {
	     cin>>s[i];
		 s[i]=' '+s[i];	
		}
	   for(x=1;x<=n;x+=2)
	     for(i=1;i<=n;i++)
		   for(j=1;j<=n;j++)
		     if(s[i][j]=='G' && check(i,j,x))	
		      {	
               for(int l=i;l<i+x;l++)f[l][j]=1;
			   for(int l=j;l<j+(x+1)/2;l++)f[i+x/2][l]=1;
			   for(int l=j;l>j-(x+1)/2;l--)f[i+x/2][l]=1;
			   for(int X=1;X<=n;X+=2)
			     for(int I=1;I<=n;I++)
			       for(int J=1;J<=n;J++)
				     if(s[I][J]=='G' && check(I,J,X))
				       res=max(res,(2*x-1)*(2*X-1));	
               for(int l=i;l<i+x;l++)f[l][j]=0;
			   for(int l=j;l<j+(x+1)/2;l++)f[i+x/2][l]=0;
			   for(int l=j;l>j-(x+1)/2;l--)f[i+x/2][l]=0;	       
			  }
	   cout<<res;		  
       }

