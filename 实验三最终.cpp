#include <stdio.h>
#include <stdlib.h> 
typedef struct BiTNode{
	char data;//���ֵ 
	struct BiTNode *leftchild,*rightchild;//���Һ��� 
}BiTNode,*BiTree; 

//�����������������ֵ���ո��ʾ���� 
void  createBiTree(BiTree &T)//����һ���� 
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
void preOrderTraverse(BiTree &T)
{
	if(T)//���ǿ�
	{
		printf("%c",T->data); 
		preOrderTraverse(T->leftchild);
		preOrderTraverse(T->rightchild);
		
	 } 
 } 
 
 //�ݹ鷽���������������
void inOederTraverse(BiTree &T)
 {
 	if(T)
 	{
 		inOederTraverse(T->leftchild);
 	    printf("%c",T->data);
		inOederTraverse(T->rightchild);
	 }
	
  } 
  
 //�ݹ鷽���������������
void postOrderTraverse(BiTree &T)
 {
 	if(T)
 	{
 		postOrderTraverse(T->leftchild);
 		postOrderTraverse(T->rightchild);
 		printf("%c",T->data);
	 }
	 
   }  
   
   
   void FindMax(BiTree T)//�ҳ����ֵ 
   {
   	if(T==NULL){
		printf("������Ϊ��,�޷��������ֵ!\n");
	}
	else{
		while(T->rightchild!=NULL){
			T = T->rightchild; 
		}
		printf("���ֵ�ǣ� %c\n",T->data);
	}

   }
   BiTree FindMin(BiTree T)//������Сֵ 
   {
   	if(!T) return NULL;
	   else if(!T->leftchild) return T;
	   else return FindMin(T->leftchild); 
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
 
 void operation(BiTree T,int h)
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
	  if(h==0) //j=����� 
	  printf("%d",j);
	  else if(h==1)//k=Ҷ���� 
	  printf("%d",k);
	  else if(h==2)//������� 
	  {
	  	for(i=0;i<j;i++)
	  	printf("%c",Q[i]->data);
		}
		  else
		  {
		  	printf("��������");
	   }

 }
 
 
 
  void exchange(BiTree &T)//������������
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
   }
     
	
 	BiTree InsertBiTree(BiTree T,char e)//������� 
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

   	BiTree Delete(BiTree T,char e)//ɾ������
	{
		BiTree tmp;
		if(!T)
		printf("Ҫɾ����Ԫ��δ�ҵ�");
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
			printf("��Сֵ�ǣ�%c",min->data);
		}
		
	 else if(a==8)
	 {
		printf("�ܽ������");
		operation(T,0); 
	 }
	 else if(a==9)
	 {
	 	printf("��Ҷ������"); 
	 	operation(T,1);
	 }   
	 else if(a==10)
	 {
	 	printf("�������:%d",Depth(T));
	 }
	 else if(a==11)
	 {
	 	printf("����ǰ\n");
	 	operation(T,2);
	 	exchange(T);
	 	printf("������\n");
	 	operation(T,2); 
	 }
    else if(a==12)
    {
    	getchar();
    	char e;
    	printf("������Ҫ����ֵ��");
		scanf("%c",&e);
    	InsertBiTree(T,e);
	}
	else if(a==13)
	{
		getchar();
		char e;
		printf("������Ҫɾ����");
		scanf("%c",&e);
		Delete(T,e); 
		
	
	}
	 else if(a==14)
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
	printf("6.���ֵ\n");
	printf("7.��Сֵ\n");
	printf("8.�ܽ����\n");
	printf("9.��Ҷ����\n");
	printf("10.�������\n");
	printf("11.������������\n");
	printf("12.����һ�����\n");
	printf("13.ɾ��һ�����\n");
	printf("14.����\n"); 
	choose(T); 
	return 0;
} 
