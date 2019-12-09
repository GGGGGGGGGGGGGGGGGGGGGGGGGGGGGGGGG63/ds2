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

BinTree CreatBinTree(); /* 实现细节忽略 */
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
/* 你的代码将被嵌在这里 */
BinTree CreatBinTree(BinTree &BT)
{
	char ch;//输入节点用
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
		 BT->Data=ch; //生成根结点 
		 CreatBinTree(BT->Left); //构造左子树
		 CreatBinTree(BT->Right);//构造右子树
		  
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

