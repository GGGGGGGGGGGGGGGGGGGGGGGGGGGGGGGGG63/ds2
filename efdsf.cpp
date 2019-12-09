#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ʵ��ϸ�ں��� */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
BinTree CreatBinTree(BinTree &BT)
{
	char ch;//����ڵ���
	ch=getchar();
	if(ch ==' ')
	{
		BT=NULL;
	 }else{
	 	BT=(TNode *)malloc(sizeof(TNode));
	 	if(!BT)
	 	{
	 		exit(1);
		 }
		 BT->Data=ch; //���ɸ���� 
		 CreatBinTree(BT->Left); //����������
		 CreatBinTree(BT->Right);//����������
		  
	 }
}
void InorderTraversal( BinTree BT ){
	if(BT)
	{
		printf("%c",BT->Data);
		InorderTraversal( BT->Left );
		InorderTraversal( BT->Right );
	}	
} 

void PreorderTraversal( BinTree BT )
{
	if(BT)
	{
		
		PreorderTraversal(  BT->Left );
		printf("%c",BT->Data);
		PreorderTraversal(  BT->Right );
	}
}

void PostorderTraversal( BinTree BT )
{
	if(BT)
	{
		PostorderTraversal(  BT->Left );
		PostorderTraversal(  BT->Right );
		printf("%c",BT->Data);
	}
}

void LevelorderTraversal( BinTree BT )
{
	
	
}

