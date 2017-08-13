#include <stdio.h>

int main()
{
	int i, n, k;
	int a[101];
	scanf("%d%d", &n, &k);

	for(i=0; i<n; i++)
		scanf("%d", a+i);

	for(i=0; i<n; i++) {
		if(a[i] <= 8) k -= a[i];
		else {
			k -= 8;
			if(i+1 < n)
				a[i+1] += a[i]-8;			
		}
		if(k <= 0) {
			printf("%d\n", i+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
