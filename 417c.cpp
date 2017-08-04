#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long lli;
struct P { int a, i; };

lli ans;
int n, S;
int low, high;
vector<P> v;

bool C(int k)
{
	lli T=0;
	priority_queue<lli, vector<lli>, greater<lli> > pq;
	for(int i=0; i<n; i++) {
		lli t = 1LL*v[i].a + v[i].i*k;
		pq.push(t);
	}

	while(k--) {
		T += pq.top(); 
		pq.pop();
	}
	if(T <= S) {
		ans = T;
		return 1;
	}
	return 0;
}

int main()
{
	int i, a;
	scanf("%d%d", &n, &S);

	for(i=1; i<=n; i++) {
		scanf("%d", &a);
		v.push_back((P){a, i});
	}

	low = 0; high = n;
	for(int i=0; i<320; i++) { 
		int mid = (low+high+1)/2;
		if(C(mid)) low = mid;
		else high = mid-1;
	}

	printf("%d %lld\n", low, ans);
	return 0;
}
