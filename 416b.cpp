#include <stdio.h>

int p[10001];

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);

	for(i=1; i<=n; i++)
		scanf("%d", p+i);

	while(m--) {
		int L, R, x;
		int min=0, max=0;
		scanf("%d%d%d", &L, &R, &x);
		for(i=L; i<x; i++)
			if(p[x] < p[i])
				max++;
		for(i=x+1; i<=R; i++)
			if(p[x] > p[i])
				min++;
		min == max ? puts("Yes") : puts("No");
	}

	return 0;
}
