#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(long i=a;i<=b;i++)
long n,m;
struct bg
{	long vt;long ts;
};
long dd[100001];
long dodai[100001],dem[100001];
vector <bg> a[100001];
void doc()
{	cin>>n>>m;
	f(i,2,n) 
	{	bg w;
		long x,y;
		cin>>x>>y;
		w.vt=x;
		w.ts=y;
		a[i].push_back(w);
		w.vt=i;
		a[x].push_back(w);
	}
}
void dfs(long u)
{	dd[u]=1;
	f(j,0,a[u].size()-1)
	{	long v=a[u][j].vt;
		long gt=a[u][j].ts;
		if(dd[v]==0)
		{
			dodai[v]=dodai[u]+gt;
			dem[v]=dem[u]+1;
			dfs(v);
		}
	}
}
void xuli()
{	f(t,1,m)
	{	long u,v;
		cin>>u>>v;
		f(i,1,n) 
		{	dd[i]=0;
			dodai[i]=0;
			dem[i]=0;
		}
		dfs(u);
		if(dem[v]<dodai[v]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
int main()
{	freopen("C11BC2.INP","r",stdin);
	freopen("C11BC2.OUT","w",stdout);
	doc();
	xuli();
	return 0;
}
