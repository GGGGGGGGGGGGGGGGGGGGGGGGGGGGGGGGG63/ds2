#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List Reverse( List L ) {
  List p, q;
  p = L;
  L = NULL;
  while (p) {
    q = p;
    p = p->Next;
    q->Next = L;
    L = q;
  }
  return L;
}
