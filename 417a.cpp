#include <stdio.h>

int L[5], S[5], R[5], P[5];

int isAccident()
{
	int i;
	for(i=1; i<5; i++) {
		if(L[i]+S[i]+R[i] >= P[i] && P[i])
			return 1;
	}

	for(i=1; i<=2; i++) {
		if((P[i+2] && S[i] == P[i+2]) || (P[i] && S[i+2] == P[i]))
			return 1;
	}
	
	for(i=1; i<5; i++) {
		int nR = i==4 ? 1 : i+1;
		int nL = i==1 ? 4 : i-1;
		if(P[nR] && R[i] == P[nR]) return 1;
		if(P[nL] && L[i] == P[nL]) return 1;
	}
	return 0;
}


int main()
{
	int i;
	
	for(i=1; i<5; i++) 
		scanf("%d%d%d%d", L+i, S+i, R+i, P+i);
	isAccident() ? puts("YES") : puts("NO");	
	return 0;
}
