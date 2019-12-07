#include <stdio.h>
#include <stdlib.h> 
typedef struct BiTNode{
	char data;//存放值 
	struct BiTNode *leftchild,*rightchild;//左右孩子 
}BiTNode,*BiTree; 

//先序输出二叉树结点的值，空格表示空树 
int  createBiTree(BiTree &T)
{
	char ch;//输入节点用
	ch=getchar();
	if(ch ==' ')
	{
		T=NULL;
	 }else{
	 	T=(BiTNode *)malloc(sizeof(BiTNode));
	 	if(!T)
	 	{
	 		exit(1);
		 }
		 T->data=ch; //生成根结点 
		 createBiTree(T->leftchild); //构造左子树
		 createBiTree(T->rightchild);//构造右子树
		  
	 }
	 return 0;
	 
}

void PrintTree(BiTree T, int nLayer)  /* 按竖向树状打印的二叉树 */
{
  if( T==NULL ) 
    return;
  PrintTree(T->rightchild,  nLayer+1);
  for(int i=0;i<nLayer;i++)
  {
     printf("   ");
  }
  printf("%c\n",T->data);
    
  PrintTree(T->leftchild ,  nLayer+1);
} 

//递归方法先序遍历二叉树
int preOrderTraverse(BiTree &T)
{
	if(T)//若非空
	{
		printf("%c",T->data); 
		preOrderTraverse(T->leftchild);
		preOrderTraverse(T->rightchild);
		
	 } 
	 return 0;
 } 
 
 //递归方法中序遍历二叉树
int inOederTraverse(BiTree &T)
 {
 	if(T)
 	{
 		inOederTraverse(T->leftchild);
 	    printf("%c",T->data);
		inOederTraverse(T->rightchild);
	 }
	 return 0;
  } 
  
 //递归方法后序遍历二叉树
int postOrderTraverse(BiTree &T)
 {
 	if(T)
 	{
 		postOrderTraverse(T->leftchild);
 		postOrderTraverse(T->rightchild);
 		printf("%c",T->data);
	 }
	 return 0;
   }  
 

 
 int howmuch(BiTree T,int h)
 {
 	BiTNode *Q[100];//树节点指针数组，用于存放遍历到的元素地址
	 if(T == NULL)
	 printf("空的二叉树\n");
	 Q[0]=T;//存入树根
	 int i,k=0;
	 int j=1;
	 for(i=0;i<j;i++)
	 {
	 	if(Q[i]->leftchild!=NULL) //如果有左孩子，存入地址，j加一，否则没操作
		 {
		 	Q[j]=Q[i]->leftchild;
		 	j++;
		  } 
		if(Q[i]->rightchild!=NULL)//如果有右孩子，存入地址，j加一，否则没操作
		{
			Q[j]=Q[i]->rightchild;
			j++;
		 } 
		 if(Q[i]->leftchild==NULL&&Q[i]->rightchild==NULL)
		   k++;//计算叶子数 
		
	  } 
	  if(h==0)
	  printf("%d",j);
	  else if(h==1)
	  printf("%d",k);
	  else if(h==2)
	  {
	  	for(i=0;i<j;i++)
	  	printf("%c",Q[i]->data);
		}
		  else
		  {
		  	printf("参数错误");
		  }
	return 0;
 }
 
 int Depth(BiTree &T)//计算树的深度
 {
 	int lh,rh;
 	if(NULL == T)
 	{
 		return 0;
	 }
	 else
	 {
	 	lh = Depth(T->leftchild);
	 	rh = Depth(T->rightchild);
	 	return (lh>rh?lh:rh)+1;
	 }
  } 
  
  int exchange(BiTree &T)//交换左右子树
  {
  	if(T!=NULL)
  	{
  		if(T->leftchild!=NULL && T->rightchild!=NULL) //当有左右孩子时才交换
		  {
		  	char t;
		  	t=T->leftchild->data;
		  	T->leftchild->data=T->rightchild->data;
		  	T->rightchild->data=t;//交换数据 
		   } 
		   exchange(T->leftchild);
		   exchange(T->rightchild);
	  }
	  return 0;
   }
     
	
 	BiTree InsertBiTree(BiTree T,char e)//插入操作 
{ 
   //BiTree f,p;
   BiTNode *s,*f,*p;
   s=(BiTNode*)malloc(sizeof(BiTNode));
   s->data=e;
   s->leftchild=NULL;
   s->rightchild=NULL;
   if(T==NULL)
     {
     	return s;
	 }
   f=NULL;
   p=T;
   while(p!=NULL)
     {
     	f=p;
     	if(p->data>e)
     	  p=p->leftchild;
     	else
     	  p=p->rightchild;
	 }
   if(f->data>e)
     f->leftchild=s;
   else
     f->rightchild=s;	 
   return T;
}  

 int choose(BiTree T)
{
	int a;
	scanf("%d",&a);
	if(a==1)
	 {
	 	 PrintTree(T, 1);
	 }
	else if(a==2)
	{
		printf("先序遍历：");
		preOrderTraverse(T); 
	}
	else if(a==3)
	{
		printf("中序遍历：");
		inOederTraverse(T); 
	 } 
	 else if(a==4)
	 {
	 	printf("后序遍历：");
		postOrderTraverse(T); 
	 }
	 else if(a==5)
	 {
	 	printf("层序遍历：");
	 	howmuch(T,2); 
		} 
	 else if(a==6)
	 {
		printf("总结点数：");
		howmuch(T,0); 
	 }
	 else if(a==7)
	 {
	 	printf("总叶子数："); 
	 	howmuch(T,1);
	 }   
	 else if(a==8)
	 {
	 	printf("树的深度:%d",Depth(T));
	 }
	 else if(a==9)
	 {
	 	printf("交换前\n");
	 	howmuch(T,2);
	 	exchange(T);
	 	printf("交换后\n");
	 	howmuch(T,2); 
	 }
	  
	 else if(a==10)
	 exit(1);
	 else printf("没有这个操作\n");
	 printf(" 操作完成，请输入下一个操作\n");
	 choose(T);
	 return 0; 
	  
	
	}  

int main()
{
	printf("-------------------------二叉树的基本操作----------------------\n");
	printf("请先建立二叉树，按先序的方式输入，如果数据为空输入空格\n");
	BiTree T;//定义二叉树，初始化
	createBiTree(T);
	printf("1.打印树形\n");
	printf("2.先序遍历\n"); 
	printf("3.中序遍历\n");
	printf("4.后序遍历\n");
	printf("5.层序遍历\n");
	printf("6.总结点数\n");
	printf("7.总叶子数\n");
	printf("8.数的深度\n");
	printf("9.交换左右子树\n");
	printf("10.结束\n");
	choose(T); 
	return 0;
}
