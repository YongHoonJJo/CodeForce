#include <stdio.h>

int main()
{
	int a, b, step=1;
	scanf("%d%d", &a, &b);

	while(a>=0 && b>=0) {
		step&1 ? a -= step : b -= step;	
		step++;
	}
	b < 0 ? puts("Valera") : puts("Vladik");

	return 0;
}
