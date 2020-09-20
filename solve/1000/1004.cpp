#include <stdio.h>

int main(void)
{
	int a, n, tnum, plposx[51], plposy[51], plrad[51], stposx, stposy, endposx, endposy, result;
	scanf("%d",&tnum);
	while(tnum--)
	{
		scanf(" %d%d", &stposx, &stposy);
		scanf(" %d%d", &endposx, &endposy);
		scanf(" %d",&n);
				result=0;
		a=n;
		while(n--)
		{
			scanf(" %d%d%d", &plposx[n], &plposy[n], &plrad[n]);
		}
		while(a--)
		{
			if((plposx[a]-stposx)*(plposx[a]-stposx)+(plposy[a]-stposy)*(plposy[a]-stposy) < plrad[a]*plrad[a])
			{
				if((plposx[a]-endposx)*(plposx[a]-endposx)+(plposy[a]-endposy)*(plposy[a]-endposy)>plrad[a]*plrad[a])
				{
					result++;
				}
			}
			if((plposx[a]-endposx)*(plposx[a]-endposx)+(plposy[a]-endposy)*(plposy[a]-endposy)<plrad[a]*plrad[a])
			{
				if((plposx[a]-stposx)*(plposx[a]-stposx)+(plposy[a]-stposy)*(plposy[a]-stposy)>plrad[a]*plrad[a])
				{
					result++;
				}
			}
        }
        printf("%d\n",result);
	}
	return 0;
}