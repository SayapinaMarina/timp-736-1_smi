#include <stdio.h>
int main()
{
	int n,x,next,current;
	int res=0;
	scanf("%d%d", &n, &x);
	current=x;
	for (int i=0; i<n-1; i++)
	{
		scanf("%d",&x);
		next=x;
		if (current<=next)
		{
			res=1;
		}
		else
		{
			res=0;
			break;
		}
			current=next;
		}
	printf("%d\n", res);
	return 0;
}

	
