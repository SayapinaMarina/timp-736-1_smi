#include <stdio.h>
#include <math.h>
int main (void)
{
	int i, n, x, sum;
	sum=0;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &x);
		sum=sum+((i+1)%2)*pow(x,3);
	}
	printf("%d\n", sum);
	return 0;
}
