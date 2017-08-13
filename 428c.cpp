#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > v;
vector<bool> visited;
double ans;

void dfs(int cur, int d, double p)
{
	visited[cur] = 1;

	if(cur != 1 && v[cur].size() == 1) {
		ans += (d*p);
		return ;
	}

	int sz=v[cur].size();
	if(cur != 1) sz--;
	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i];
		if(!visited[next])
			dfs(next, d+1, p/sz);
	}

}

int main()
{
	int n;
	scanf("%d", &n);

	v = vector<vector<int> >(n+1);
	for(int i=1; i<n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visited = vector<bool>(n+1);
	dfs(1, 0, 1.0);
	
	printf("%.15lf\n", ans);
}
