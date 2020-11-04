/*
 * @Author: your name
 * @Date: 2020-10-30 20:17:08
 * @LastEditTime: 2020-10-30 20:45:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Kuangbin\disoint_set\POJ - 1456.cpp
 */


#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int vis[10000 + 100];

struct node
{
	int d, p;
} a[10000 + 100];

void init()
{
	memset(vis, 0, sizeof(vis));
	ans = 0;
}

int cmp(node a, node b)
{
	if(a.p == b.p) return a.d > b.d;
	return a.p > b.p;
}

int get(int x)
{
	for(int i=x; i>=1; --i)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			return i;
		}
	}
	return 0;
}

int main()
{

	while(~scanf("%d",&n))
	{
		init();
		for(int i=1; i<=n; ++i)
		{
			scanf("%d%d",&a[i].p,&a[i].d);
		}
		sort(a+1, a+n+1, cmp);
		for(int i=1; i<=n; ++i)
		{
			int day = get(a[i].d);
			if(day != 0) ans+= a[i].p;
			else ans += 0;
		}
		cout<<ans<<endl;
	}

}