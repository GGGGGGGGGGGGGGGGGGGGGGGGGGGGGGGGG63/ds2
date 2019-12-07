#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *Next;
};
int main()
{
	struct Node *head,*p,*t;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->Next=NULL;
	p=head;
	
	int n,m=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=m;
		t->Next=NULL;
		p->Next=t;
		p=t;
	}
	p->Next=NULL;
	head=head->Next;
	while(head!=NULL)
	{
		printf("%d",head->data);
		if(head->Next!=NULL)
		{
			printf(" ");
		}
		head=head->Next;
	}
	
	return 0;
}
