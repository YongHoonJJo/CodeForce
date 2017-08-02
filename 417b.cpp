#include <stdio.h>
#define INF 0x7fffffff

int n, m, mF=-1, ans=INF;
int bd[20][105];
int L[20], R[20];

void go(int F, int LR, int cnt)
{
	if(cnt > ans) return ;
	if(F == mF) {
		if(LR) cnt += m+1-L[F];
		else cnt += R[F];

		if(ans > cnt) ans = cnt;
		return ;
	}	
	if(!L[F]) {
		go(F-1, LR, cnt+1);
	}
	else {
		if(LR == 1) {
			go(F-1, 0, cnt+m+2);
			go(F-1, 1, cnt+(m+1-L[F])*2+1);
		}
		else {
			go(F-1, 1, cnt+m+2);
			go(F-1, 0, cnt+2*R[F]+1);
		}
	}
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) {
		for(j=0; j<m+2; j++) {
			scanf("%1d", &bd[i][j]);
			if(bd[i][j]) {
				if(mF == -1) mF = i;
				if(!L[i]) L[i] = j;
				R[i] = j;
			}
		}
	}

	if(mF == -1) ans = 0;
	else go(n-1, 0, 0);
	printf("%d\n", ans);	
	return 0;
}
