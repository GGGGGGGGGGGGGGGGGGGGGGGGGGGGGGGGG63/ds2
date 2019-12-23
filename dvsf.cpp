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
  
  //根据二叉树括号表示法字符串str生成对应的二叉树链式存储结构
  void CreateBTree(BTNode * &b, char *str)
  {
      BTNode *St[MaxSize], *p;        //St作为顺序栈
      int top = -1, k,j = 0;            //top作为栈顶指针
      char ch;
      b = NULL;
      ch = str[j];
      while (ch != '\0')
      {
          switch (ch)
          {
          case '(':top++; St[top] = p; k = 1; break;        //开始处理左孩子结点
          case ')':top--; break;                            //栈顶结点的子树处理完毕
          case ',':k = 2; break;                            //开始处理右孩子结点
          default:
              p = (BTNode *)malloc(sizeof(BTNode));        //创建一个结点，由p指向它
              p->data = ch;
              p->lchild = p->rchild = NULL;                
              if (b == NULL)  b = p;                        //若尚未创建根节点
              else
              {
                  switch (k)
                 {
                  case 1:St[top]->lchild = p; break;
                 case 2:St[top]->rchild = p; break;
                  }
              }
          }
         j++;                                            //继续扫描str
          ch = str[j];
      }
  }
  
  //输出二叉树DispBTree(b)
  void DispBTree(BTNode *b)
  {
      if (b != NULL)
      {
          printf("%c", b->data);
          if (b->lchild != NULL || b->rchild != NULL)
          {
              printf("(");                            //有孩子结点时才输出“（”
              DispBTree(b->lchild);                    //递归处理左子树
              if (b->rchild != NULL)  printf(",");    //有右孩子结点时才输出“,”
              DispBTree(b->rchild);                    //递归处理右子树
              printf(")");                            //有孩子结点时才输出
          }
     }
  }
  
  //先序遍历
  void PreOrder(BTNode * b)
  {
      if (b != NULL)
      {
          printf("%c", b->data);
          PreOrder(b->lchild);
          PreOrder(b->rchild);
      }
  }
  //中序遍历
  void InOrder(BTNode * b)
  {
      if (b != NULL)
      {
          InOrder(b->lchild);
          printf("%c", b->data);
         InOrder(b->rchild);
      }
  }
 //后序遍历
 void PostOrder(BTNode * b)
 {
     if (b != NULL)
     {
          InOrder(b->lchild);
         InOrder(b->rchild);
         printf("%c", b->data);
    }
 }
 
 //销毁二叉树
 void DestroyBTree(BTNode *& b)
 {
     if (b != NULL)
     {
         DestroyBTree(b->lchild);
         DestroyBTree(b->rchild);
         free(b);
     }
 }
 
 
 //查找值为x的结点
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
 
 //求二叉树的高度
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
 
 //求二叉树元素的最大值
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
 
 //求二叉树结点个数
 int BTNum(BTNode * b)
 {
     if (b == NULL)  return 0;
     else  return BTNum(b->lchild) + BTNum(b->rchild) + 1;
 }
 
 //输出所有的叶子结点
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
 
 //求二叉树中结点值x的层数
 //返回0表示未找到,h初始置为0
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
 
 //求二叉树第k层的结点个数
 //当前层数h初始置为0
 int BTKlevel(BTNode *b,int h, int k)
 {
     if (b == NULL)  return 0;
     else
     {
         if (h == k)  return 1;
         if (h < k)   return (BTKlevel(b->lchild, h + 1, k) + BTKlevel(b->rchild,h + 1,k));
     }
 }

 //求第k层上叶子结点的个数
 int BTKlevelLeaf(BTNode *b, int h, int k)
 {
    if (b == NULL)  return 0;
     else
    {
         if (h == k && b->lchild == NULL && b->rchild == NULL)  return 1;
         if (h < k)   return (BTKlevelLeaf(b->lchild, h + 1, k) + BTKlevelLeaf(b->rchild, h + 1, k));
     }
    return 0;                //其它情况返回0
 }
 
 //求二叉树中所有单分支结点个数
 int BTSingleSonNode(BTNode * b)
{
    if (b == NULL)  return 0;
     else if ((b->lchild == NULL && b->rchild != NULL) || (b->lchild != NULL && b->rchild == NULL))  return BTSingleSonNode(b->lchild) + BTSingleSonNode(b->rchild) + 1;
    else  return BTSingleSonNode(b->lchild) + BTSingleSonNode(b->rchild);
 }
 
 //判断两棵树是否相似
 //形态一样，结点值可以不同
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
 
 //输出值为x的结点的所有祖先
 //f(b,x)=true表示以结点b为根节点的二叉树包含x
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
        int flag2 = BTAncestor(b->rchild, x);        //考虑到可能存在多个x，分开写
         if(flag1 || flag2)  printf("%c", b->data);
         return true;
   }
     return false;
 }
 
 //输出值为x的结点的所有子孙结点
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
 
 //判断值为x的结点和值为y的结点是否为兄弟
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
 
 //将二叉树b1复制到二叉树b2
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
 
 //将二叉树的所有左右子树进行交换
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
 
 
 //判断一颗二叉树是否是完全二叉树
 //两条规则，违反任意一条均不是完全二叉树
 //1、某结点无左孩子，则一定没有右孩子
 //2、若某结点缺少左孩子或右孩子，则其所有后继（层次遍历的后继）一定无孩子
 bool BTComp(BTNode *b)
 {
    BTNode *Qu[MaxSize], *p;            //定义一个队列用于层次遍历
     int front = 0, rear = 0;            //环形队列的队头和队尾指针
     bool cm = true;                        //cm为真表示二叉树为完全二叉树
     bool flag = true;                    //flag为真表示所有结点到目前为止都有左右孩子
     if (b == NULL)  return true;
     rear++;
     Qu[rear] = b;                        //根结点入队
    while (front != rear)                //队列不为空
    {
         front = (front + 1) % MaxSize;
         p = Qu[front];                    //队首出队
         if (p->lchild == NULL)  
        {
            flag = false;
           if (p->rchild != NULL)        //没有左孩子，则一定没有右孩子
           {
               cm = false;
                break;
             }
        }
        else
         {
            if ((!flag))                //出现空缺少左孩子或右孩子之后，所有的结点均无孩子
             {
                 cm = false;
                 break;
             }
            rear = (rear + 1) % MaxSize;
             Qu[rear] = p->lchild;            //左孩子入队
             if (p->rchild == NULL)  flag = false;
           else
            {
                rear = (rear + 1) % MaxSize;
                Qu[rear] = p->rchild;        //右孩子入队
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
