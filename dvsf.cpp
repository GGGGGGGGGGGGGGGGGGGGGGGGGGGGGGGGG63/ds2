 #include<stdio.h>
 #include<stdlib.h>
 
 typedef char ElemType;
 typedef struct node 
   {
       ElemType data;
       struct node *lchild;
       struct node *rchild;
  }BTNode;
  
  const int MaxSize = 100 + 10;    
  
  //���ݶ��������ű�ʾ���ַ���str���ɶ�Ӧ�Ķ�������ʽ�洢�ṹ
  void CreateBTree(BTNode * &b, char *str)
  {
      BTNode *St[MaxSize], *p;        //St��Ϊ˳��ջ
      int top = -1, k,j = 0;            //top��Ϊջ��ָ��
      char ch;
      b = NULL;
      ch = str[j];
      while (ch != '\0')
      {
          switch (ch)
          {
          case '(':top++; St[top] = p; k = 1; break;        //��ʼ�������ӽ��
          case ')':top--; break;                            //ջ�����������������
          case ',':k = 2; break;                            //��ʼ�����Һ��ӽ��
          default:
              p = (BTNode *)malloc(sizeof(BTNode));        //����һ����㣬��pָ����
              p->data = ch;
              p->lchild = p->rchild = NULL;                
              if (b == NULL)  b = p;                        //����δ�������ڵ�
              else
              {
                  switch (k)
                 {
                  case 1:St[top]->lchild = p; break;
                 case 2:St[top]->rchild = p; break;
                  }
              }
          }
         j++;                                            //����ɨ��str
          ch = str[j];
      }
  }
  
  //���������DispBTree(b)
  void DispBTree(BTNode *b)
  {
      if (b != NULL)
      {
          printf("%c", b->data);
          if (b->lchild != NULL || b->rchild != NULL)
          {
              printf("(");                            //�к��ӽ��ʱ�����������
              DispBTree(b->lchild);                    //�ݹ鴦��������
              if (b->rchild != NULL)  printf(",");    //���Һ��ӽ��ʱ�������,��
              DispBTree(b->rchild);                    //�ݹ鴦��������
              printf(")");                            //�к��ӽ��ʱ�����
          }
     }
  }
  
  //�������
  void PreOrder(BTNode * b)
  {
      if (b != NULL)
      {
          printf("%c", b->data);
          PreOrder(b->lchild);
          PreOrder(b->rchild);
      }
  }
  //�������
  void InOrder(BTNode * b)
  {
      if (b != NULL)
      {
          InOrder(b->lchild);
          printf("%c", b->data);
         InOrder(b->rchild);
      }
  }
 //�������
 void PostOrder(BTNode * b)
 {
     if (b != NULL)
     {
          InOrder(b->lchild);
         InOrder(b->rchild);
         printf("%c", b->data);
    }
 }
 
 //���ٶ�����
 void DestroyBTree(BTNode *& b)
 {
     if (b != NULL)
     {
         DestroyBTree(b->lchild);
         DestroyBTree(b->rchild);
         free(b);
     }
 }
 
 
 //����ֵΪx�Ľ��
 BTNode *FindNode(BTNode *b, ElemType x)
 {
     BTNode *p;
     if (b == NULL)  return NULL;
     else if (b->data == x)  return b;
     else
     {
         p = FindNode(b->lchild, x);
         if (p != NULL)  return p;
         else  return FindNode(b->rchild, x);
     }
 }
 
 //��������ĸ߶�
 int BTHeight(BTNode *b)
 {
     int lchildh, rchildh;
     if (b == NULL)  return 0;
     else
     {
         lchildh = BTHeight(b->lchild);
         rchildh = BTHeight(b->rchild);
         return lchildh > rchildh ? (lchildh + 1) : (rchildh + 1);
     }
 }
 
 //�������Ԫ�ص����ֵ
 int BTMax(BTNode *b)
 {
     if (b == NULL)  return 0;
     else
     {
         int m1 = BTMax(b->lchild);
         int m2 = BTMax(b->rchild);
         int m3 = b->data;
         if (m1 > m2)  return m1 > m3 ? m1 : m3;
         else  return m2 > m3 ? m2 : m3;
     }
 }
 
 //�������������
 int BTNum(BTNode * b)
 {
     if (b == NULL)  return 0;
     else  return BTNum(b->lchild) + BTNum(b->rchild) + 1;
 }
 
 //������е�Ҷ�ӽ��
 void DispLeaf(BTNode *b)
 {
     if (b != NULL)
     {
         if (b->lchild == NULL && b->rchild == NULL)
             printf("%c", b->data);
         DispLeaf(b->lchild);
         DispLeaf(b->rchild);
    }
}
 
 //��������н��ֵx�Ĳ���
 //����0��ʾδ�ҵ�,h��ʼ��Ϊ0
 int BTLevel(BTNode *b, ElemType x, int h)
 {
     int level;
     if (b == NULL)  return 0;
     else if (b->data == x)  return h;
     else
     {
         level = BTLevel(b->lchild, x, h + 1);
         if (level != 0)  return level;
         else  return BTLevel(b->rchild, x, h + 1);
     }
 }
 
 //���������k��Ľ�����
 //��ǰ����h��ʼ��Ϊ0
 int BTKlevel(BTNode *b,int h, int k)
 {
     if (b == NULL)  return 0;
     else
     {
         if (h == k)  return 1;
         if (h < k)   return (BTKlevel(b->lchild, h + 1, k) + BTKlevel(b->rchild,h + 1,k));
     }
 }

 //���k����Ҷ�ӽ��ĸ���
 int BTKlevelLeaf(BTNode *b, int h, int k)
 {
    if (b == NULL)  return 0;
     else
    {
         if (h == k && b->lchild == NULL && b->rchild == NULL)  return 1;
         if (h < k)   return (BTKlevelLeaf(b->lchild, h + 1, k) + BTKlevelLeaf(b->rchild, h + 1, k));
     }
    return 0;                //�����������0
 }
 
 //������������е���֧������
 int BTSingleSonNode(BTNode * b)
{
    if (b == NULL)  return 0;
     else if ((b->lchild == NULL && b->rchild != NULL) || (b->lchild != NULL && b->rchild == NULL))  return BTSingleSonNode(b->lchild) + BTSingleSonNode(b->rchild) + 1;
    else  return BTSingleSonNode(b->lchild) + BTSingleSonNode(b->rchild);
 }
 
 //�ж��������Ƿ�����
 //��̬һ�������ֵ���Բ�ͬ
 bool BTLike(BTNode *b1, BTNode *b2)
 {
     bool flag1, flag2;
     if (b1 == NULL && b2 == NULL)  return true;
     else if (b1 == NULL || b2 == NULL)  return false;
    else
     {
         flag1 = BTLike(b1->lchild, b2->lchild);
         flag2 = BTLike(b1->rchild, b2->rchild);
        return flag1 && flag2;
    }
 }
 
 //���ֵΪx�Ľ�����������
 //f(b,x)=true��ʾ�Խ��bΪ���ڵ�Ķ���������x
 bool BTAncestor(BTNode *b, ElemType x)
 {
     if (b == NULL)  return false;
     else if ((b->lchild != NULL && b->lchild->data == x) || (b->rchild != NULL && b->rchild->data == x))
     {
         printf("%c", b->data);
         return true;
     }
     else
     {
         int flag1 = BTAncestor(b->lchild, x);
        int flag2 = BTAncestor(b->rchild, x);        //���ǵ����ܴ��ڶ��x���ֿ�д
         if(flag1 || flag2)  printf("%c", b->data);
         return true;
   }
     return false;
 }
 
 //���ֵΪx�Ľ�������������
 void BTChild(BTNode *b, ElemType x)
 {
     if (b != NULL)
    {
         if (b->data == x)
        {
            PreOrder(b->lchild);
             PreOrder(b->rchild);
        }
        else
         {
             BTChild(b->lchild,x);
             BTChild(b->rchild,x);
         }
     }
}
 
 //�ж�ֵΪx�Ľ���ֵΪy�Ľ���Ƿ�Ϊ�ֵ�
 bool BTBrother(BTNode *b, ElemType x, ElemType y)
 {
     if (b == NULL)  return false;
     else
     {
         if (b->lchild != NULL && b->rchild != NULL)
             if ((b->lchild->data == x && b->rchild->data == y) || (b->lchild->data == y && b->rchild->data == x))
                 return true;
        return BTBrother(b->lchild, x, y) || BTBrother(b->rchild, x, y);
    }
 }
 
 //��������b1���Ƶ�������b2
 void BTCopy(BTNode *b1, BTNode * &b2)
 {
    if (b1 == NULL)      b2 = NULL;
     else
     {
         b2 = (BTNode *)malloc(sizeof(BTNode));
         b2->data = b1->data;
        BTCopy(b1->lchild, b2->lchild);
         BTCopy(b1->rchild, b2->rchild);
     }
 }
 
 //�������������������������н���
 void BTSwap(BTNode *b1, BTNode * &b2)
 {
     if (b1 == NULL)  b2 = NULL;
     else
     {
         b2 = (BTNode *)malloc(sizeof(BTNode));
        b2->data = b1->data;
         BTSwap(b1->rchild, b2->lchild);
         BTSwap(b1->lchild, b2->rchild);
    }
 }
 
 
 //�ж�һ�Ŷ������Ƿ�����ȫ������
 //��������Υ������һ����������ȫ������
 //1��ĳ��������ӣ���һ��û���Һ���
 //2����ĳ���ȱ�����ӻ��Һ��ӣ��������к�̣���α����ĺ�̣�һ���޺���
 bool BTComp(BTNode *b)
 {
    BTNode *Qu[MaxSize], *p;            //����һ���������ڲ�α���
     int front = 0, rear = 0;            //���ζ��еĶ�ͷ�Ͷ�βָ��
     bool cm = true;                        //cmΪ���ʾ������Ϊ��ȫ������
     bool flag = true;                    //flagΪ���ʾ���н�㵽ĿǰΪֹ�������Һ���
     if (b == NULL)  return true;
     rear++;
     Qu[rear] = b;                        //��������
    while (front != rear)                //���в�Ϊ��
    {
         front = (front + 1) % MaxSize;
         p = Qu[front];                    //���׳���
         if (p->lchild == NULL)  
        {
            flag = false;
           if (p->rchild != NULL)        //û�����ӣ���һ��û���Һ���
           {
               cm = false;
                break;
             }
        }
        else
         {
            if ((!flag))                //���ֿ�ȱ�����ӻ��Һ���֮�����еĽ����޺���
             {
                 cm = false;
                 break;
             }
            rear = (rear + 1) % MaxSize;
             Qu[rear] = p->lchild;            //�������
             if (p->rchild == NULL)  flag = false;
           else
            {
                rear = (rear + 1) % MaxSize;
                Qu[rear] = p->rchild;        //�Һ������
            }
        }
    }
     return cm;
 }
 
 int main()
 {
     BTNode *b1, *b2;
     char str1[] = "A(B(D(,G)),C(E(,G),F))";
    char str2[] = "A(B(D,D),C(E))";
    CreateBTree(b2,str2);
    printf("%d\n", BTComp(b2));
    return 0;
 }
