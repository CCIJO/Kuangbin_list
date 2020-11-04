/*
 * @Author: cc
 * @Date: 2020-10-31 15:41:41
 * @LastEditTime: 2020-11-04 23:17:21
 * @LastEditors: cc
 * @FilePath: \Kuangbin\disjoint_set\HDU_3038.cpp
 * @Solution: 
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

const int MAX_N = 200000 + 100;
int dist[MAX_N];
int father[MAX_N];
int n, m, ans;

void init()
{
	ans = 0;
	for(int i=0; i<=n; ++i)
	{
		father[i] = i;
		dist[i] = 0;
	}
}

int get(int x)
{
	if(x == father[x]) return x;
	int y = father[x];
	father[x] = get(y);
	dist[x] += dist[y];
	return father[x];
}

bool merge(int a, int b, int w)
{
	int root1 = get(a);
	int root2 = get(b);
	if(root1 == root2)
	{
		if(dist[a] == w + dist[b])
			return true;
		return false;
	}
	else
	{
		father[root1] = root2;
		dist[root1] = dist[b] - dist[a] + w;
		return true;
	}
}


int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		init();
		while(m--)
		{
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			ans += (!merge(x-1, y, z));
		}
		cout << ans << endl;
	}

	return 0;
}