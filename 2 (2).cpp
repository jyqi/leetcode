#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int flag[100010];
int h[100010];
queue<int> q;
vector<int> f[100010];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			int x;
			scanf("%d",&x);
			f[x].push_back(i);
		}
	}
	memset(flag,0,sizeof(flag));
	memset(h,0,sizeof(h));
	while(!q.empty())
		q.pop();
	for(int i=0;i<f[0].size();i++)
	{
		int v=f[0][i];
		h[v]=1;
		q.push(v);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<f[x].size();i++)
		{
			int v=f[x][i];
			if(h[v]==1) continue;
			flag[v]++;
			if(flag[v]==2)
			{
				h[v]=1;
				q.push(v);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(h[i]==1)
			ans++;
	cout<<ans<<endl;
}