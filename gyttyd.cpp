#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
int main(void)
{
	int i,n,j,sum=0,z=0;
	scanf("%d",&n);
	char str[105][105];
	int b[18]={7,9,10,5,8,4,2,1,6,3,7,9,1,0,5,8,4,2};
	char m[]={'1','0','X','9','8','7','6','5','4','3','2'};
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);//str[320124198808240056	
	}
    for(i=0;i<n;i++)
    {
    	for(j=0;j<17;j++)
    	{
    		str[i][j]-='0';
    		printf("%d",str[i][j]);
    		str[i][j]=str[i][j]*b[j];
    		sum=sum+str[i][j];	
		}
		z=sum%11;//6
		printf("%d\n",z);
		//if(z==0)m='1';if(z==1)m='0';if(z==2)m='X';if(z==3)m='9';if(z==4)m='8';if(z==5)m='7';if(z==6)m='6';if(z==7)m='5';if(z==8)m='4';if(z==9)m='3';if(z==10)m='2';
		printf("%c,%d",m,sizeof(m));

		}
	return 0;
} 
