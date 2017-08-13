#include <stdio.h>

int seat[5], cnt[5];

int main()
{
	int i, n, k;
	scanf("%d%d", &n, &k);

	seat[4] = n; seat[2] = n*2;

	for(i=0; i<k; i++) {
		int x;
		scanf("%d", &x);
		while(x >= 3) {
			if(seat[4]) {
				seat[4]--;
				x -= 4;
			}
			else if(seat[2]) {
				seat[2]--;
				x -= 2;
			}
			else {
				puts("NO");
				return 0;
			}
		}
		if(x > 0) cnt[x]++;
	}

	while(cnt[2]) {
		if(seat[2]) {
			seat[2]--;
			cnt[2]--;
		}
		else if(seat[4]){
			cnt[2]--;
			seat[4]--;
			seat[1]++;
		}
		else {
			cnt[2]--;
			cnt[1] += 2;
		}
	}

	if(cnt[1] > seat[1]+seat[2]+seat[4]*2) puts("NO");
	else puts("YES");

	return 0;
}
