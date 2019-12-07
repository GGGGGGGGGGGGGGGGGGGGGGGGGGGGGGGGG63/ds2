#include <stdio.h>
#include <stdlib.h> 
typedef struct BiTNode{
	char data;//���ֵ 
	struct BiTNode *leftchild,*rightchild;//���Һ��� 
}BiTNode,*BiTree; 

//�����������������ֵ���ո��ʾ���� 
int  createBiTree(BiTree &T)
{
	char ch;//����ڵ���
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
		 T->data=ch; //���ɸ���� 
		 createBiTree(T->leftchild); //����������
		 createBiTree(T->rightchild);//����������
		  
	 }
	 return 0;
	 
}

void PrintTree(BiTree T, int nLayer)  /* ��������״��ӡ�Ķ����� */
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

//�ݹ鷽���������������
int preOrderTraverse(BiTree &T)
{
	if(T)//���ǿ�
	{
		printf("%c",T->data); 
		preOrderTraverse(T->leftchild);
		preOrderTraverse(T->rightchild);
		
	 } 
	 return 0;
 } 
 
 //�ݹ鷽���������������
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
  
 //�ݹ鷽���������������
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
 	BiTNode *Q[100];//���ڵ�ָ�����飬���ڴ�ű�������Ԫ�ص�ַ
	 if(T == NULL)
	 printf("�յĶ�����\n");
	 Q[0]=T;//��������
	 int i,k=0;
	 int j=1;
	 for(i=0;i<j;i++)
	 {
	 	if(Q[i]->leftchild!=NULL) //��������ӣ������ַ��j��һ������û����
		 {
		 	Q[j]=Q[i]->leftchild;
		 	j++;
		  } 
		if(Q[i]->rightchild!=NULL)//������Һ��ӣ������ַ��j��һ������û����
		{
			Q[j]=Q[i]->rightchild;
			j++;
		 } 
		 if(Q[i]->leftchild==NULL&&Q[i]->rightchild==NULL)
		   k++;//����Ҷ���� 
		
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
		  	printf("��������");
		  }
	return 0;
 }
 
 int Depth(BiTree &T)//�����������
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
  
  int exchange(BiTree &T)//������������
  {
  	if(T!=NULL)
  	{
  		if(T->leftchild!=NULL && T->rightchild!=NULL) //�������Һ���ʱ�Ž���
		  {
		  	char t;
		  	t=T->leftchild->data;
		  	T->leftchild->data=T->rightchild->data;
		  	T->rightchild->data=t;//�������� 
		   } 
		   exchange(T->leftchild);
		   exchange(T->rightchild);
	  }
	  return 0;
   }
     
	
 	BiTree InsertBiTree(BiTree T,char e)//������� 
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
		printf("���������");
		preOrderTraverse(T); 
	}
	else if(a==3)
	{
		printf("���������");
		inOederTraverse(T); 
	 } 
	 else if(a==4)
	 {
	 	printf("���������");
		postOrderTraverse(T); 
	 }
	 else if(a==5)
	 {
	 	printf("���������");
	 	howmuch(T,2); 
		} 
	 else if(a==6)
	 {
		printf("�ܽ������");
		howmuch(T,0); 
	 }
	 else if(a==7)
	 {
	 	printf("��Ҷ������"); 
	 	howmuch(T,1);
	 }   
	 else if(a==8)
	 {
	 	printf("�������:%d",Depth(T));
	 }
	 else if(a==9)
	 {
	 	printf("����ǰ\n");
	 	howmuch(T,2);
	 	exchange(T);
	 	printf("������\n");
	 	howmuch(T,2); 
	 }
	  
	 else if(a==10)
	 exit(1);
	 else printf("û���������\n");
	 printf(" ������ɣ���������һ������\n");
	 choose(T);
	 return 0; 
	  
	
	}  

int main()
{
	printf("-------------------------�������Ļ�������----------------------\n");
	printf("���Ƚ�����������������ķ�ʽ���룬�������Ϊ������ո�\n");
	BiTree T;//�������������ʼ��
	createBiTree(T);
	printf("1.��ӡ����\n");
	printf("2.�������\n"); 
	printf("3.�������\n");
	printf("4.�������\n");
	printf("5.�������\n");
	printf("6.�ܽ����\n");
	printf("7.��Ҷ����\n");
	printf("8.�������\n");
	printf("9.������������\n");
	printf("10.����\n");
	choose(T); 
	return 0;
}
