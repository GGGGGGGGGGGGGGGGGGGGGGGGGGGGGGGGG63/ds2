#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}
int Length( List L ){
	PtrToLNode head,t,p;
	head=(struct LNode*)malloc(sizeof(struct LNode));
	head=L;
	int i=0;
	while(head->Data!=-1)
	{
		i++;
		head=head->Next;
	 } 
	 return i;

} 
