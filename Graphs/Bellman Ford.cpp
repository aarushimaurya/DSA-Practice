#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n=5;

	vector<vector<int>> edges;

	edges.push_back({1,2,2});
	edges.push_back({1,3,2});
	edges.push_back({2,3,-3});
	edges.push_back({3,4,5});
	edges.push_back({3,5,-4});
	edges.push_back({4,2,-1});
	edges.push_back({5,4,9});

	vector<int> dist(n, INT_MAX);
	dist[0]=0;

	for(int i=0; i<n-1; i++)
	{
		for(auto j: edges)
		{
			if(dist[j[0]-1]<INT_MAX)
			{
				if(dist[j[1]-1] > (dist[j[0]-1]+j[2]))
					dist[j[1]-1] = dist[j[0]-1]+j[2];
			}
		}
	}

	for(int i=0; i<dist.size(); i++)
	{
		cout<<dist[i]<<" ";
	}

	return 0;
	
}
