#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node{
	int data;
	PtrToNode next;
};
int main()
{
	PtrToNode head,t,p;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=NULL;
	p=head;
	int n,j=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&j);
		
		t->data=j;
		t->next=NULL;
		p->next=t;
		p=t;
	}
	
	head=head->next;
	printf("%d",head->data);
	head=head->next;
	while(head)
	{
		printf(" %d",head->data);
		head=head->next;
	}
	
	return 0;
}
