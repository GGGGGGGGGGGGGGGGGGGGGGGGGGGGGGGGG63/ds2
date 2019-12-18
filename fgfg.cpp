#include <stdio.h>
#include <stdlib.h>
struct node 
	{
		int data;
		struct node * next;
	} ;
typedef struct node * nodePtr;
int main()
{
	nodePtr head,t,p;
	int i,j,n;
	head=(struct node *) malloc(sizeof(struct node));
	head->next=NULL;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	   t=(struct node *) malloc(sizeof(struct node));
	   //scanf("%d",&t->data);
	   scanf("%d",&j);	
	   t->data=j;
	   t->next=head->next;
	   head->next=t;
	}
	
	p=head->next;
	while(p!=NULL)
	{
		printf("%d \n",p->data);
		p=p->next;
	}
	
	return 0;
}
