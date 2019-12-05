#include <stdio.h>
#include <stdlib.h> 
typedef struct BiTNode{
	char data;//存放值 
	struct BiTNode *leftchild,*rightchild;//左右孩子 
}BiTNode,*BiTree; 

//先序输出二叉树结点的值，空格表示空树 
void  createBiTree(BiTree &T)//创建一棵树 
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
void preOrderTraverse(BiTree &T)
{
	if(T)//若非空
	{
		printf("%c",T->data); 
		preOrderTraverse(T->leftchild);
		preOrderTraverse(T->rightchild);
		
	 } 
 } 
 
 //递归方法中序遍历二叉树
void inOederTraverse(BiTree &T)
 {
 	if(T)
 	{
 		inOederTraverse(T->leftchild);
 	    printf("%c",T->data);
		inOederTraverse(T->rightchild);
	 }
	
  } 
  
 //递归方法后序遍历二叉树
void postOrderTraverse(BiTree &T)
 {
 	if(T)
 	{
 		postOrderTraverse(T->leftchild);
 		postOrderTraverse(T->rightchild);
 		printf("%c",T->data);
	 }
	 
   }  
   
   
   void FindMax(BiTree T)//找出最大值 
   {
   	if(T==NULL){
		printf("二叉树为空,无法查找最大值!\n");
	}
	else{
		while(T->rightchild!=NULL){
			T = T->rightchild; 
		}
		printf("最大值是： %c\n",T->data);
	}

   }
   BiTree FindMin(BiTree T)//查找最小值 
   {
   	if(!T) return NULL;
	   else if(!T->leftchild) return T;
	   else return FindMin(T->leftchild); 
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
 
 void operation(BiTree T,int h)
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
	  if(h==0) //j=结点数 
	  printf("%d",j);
	  else if(h==1)//k=叶子数 
	  printf("%d",k);
	  else if(h==2)//层序遍历 
	  {
	  	for(i=0;i<j;i++)
	  	printf("%c",Q[i]->data);
		}
		  else
		  {
		  	printf("参数错误");
	   }

 }
 
 
 
  void exchange(BiTree &T)//交换左右子树
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
   }
     
	
 	BiTree InsertBiTree(BiTree T,char e)//插入操作 
{ 
  if(!T){
  	T=(BiTree)malloc(sizeof(struct BiTNode));
  	T->data = e;
  	T->leftchild = T->rightchild = NULL;
  }
  else{
  	if(e<T->data)
  	   	T->leftchild = InsertBiTree(T->leftchild,e);
  	else if(e>T->data)
  	   	T->rightchild = InsertBiTree(T->rightchild,e);
	  }
	  	return T;
}  

   	BiTree Delete(BiTree T,char e)//删除操作
	{
		BiTree tmp;
		if(!T)
		printf("要删除的元素未找到");
		else {
			if(e<T->data)
			T->leftchild=Delete(T->leftchild,e);
			else if(e>T->data)
			T->rightchild=Delete(T->rightchild,e);
			else{
				if(T->leftchild && T->rightchild)
				{
					tmp = FindMin(T->rightchild);
					T->data=tmp->data;
					T->rightchild=Delete(T->rightchild,T->data);
				
				}
				else{
					tmp = T;
					if(!T->leftchild)
					T=T->rightchild;
					else
					T=T->leftchild;
					free(tmp);
				}
			}
		} 
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
	 	operation(T,2); 
		} 
		else if(a==6)
		{
			FindMax(T);
		}
		else if(a==7)
		{
			BiTree min;
			min=FindMin(T);
			printf("最小值是：%c",min->data);
		}
		
	 else if(a==8)
	 {
		printf("总结点数：");
		operation(T,0); 
	 }
	 else if(a==9)
	 {
	 	printf("总叶子数："); 
	 	operation(T,1);
	 }   
	 else if(a==10)
	 {
	 	printf("树的深度:%d",Depth(T));
	 }
	 else if(a==11)
	 {
	 	printf("交换前\n");
	 	operation(T,2);
	 	exchange(T);
	 	printf("交换后\n");
	 	operation(T,2); 
	 }
    else if(a==12)
    {
    	getchar();
    	char e;
    	printf("请输入要插入值：");
		scanf("%c",&e);
    	InsertBiTree(T,e);
	}
	else if(a==13)
	{
		getchar();
		char e;
		printf("请输入要删除：");
		scanf("%c",&e);
		Delete(T,e); 
		
	
	}
	 else if(a==14)
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
	printf("6.最大值\n");
	printf("7.最小值\n");
	printf("8.总结点数\n");
	printf("9.总叶子数\n");
	printf("10.数的深度\n");
	printf("11.交换左右子树\n");
	printf("12.插入一个结点\n");
	printf("13.删除一个结点\n");
	printf("14.结束\n"); 
	choose(T); 
	return 0;
} 
