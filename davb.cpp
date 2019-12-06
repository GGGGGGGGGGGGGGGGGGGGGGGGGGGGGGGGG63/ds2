#include<stdio.h>
#include<stdlib.h>
#define N 5
#define price1 2//小型车每小时车费
#define price2 3// 大型车每小时车费
int a;
//车辆信息
typedef struct {
//	int h1,h2,m1,m2,s1,s2;
	int h1,h2,m1,m2;
//	int time1,time2;
	int type;
	int num;
} car;
//停车场栈
typedef struct Node {
	car *stcak[N+1];
	int top;
} parking;

//通道
typedef struct q {
	/*int*/ car *data;
	struct q *next;
} queue;
typedef struct {
	queue *head;
	queue *rear;
} LinkCar;
//初始化操作
void InitStack1(parking *p) {
	int i;
	p->top=0;
	//p->top=-1;错误，应从1开始
	for(i=0; i<=N; i++) {
		p->stcak[p->top]=NULL;
	}
}
int Initqueue(LinkCar *Q) {
	Q->head=(queue *)malloc(sizeof(queue));
	if(Q->head!=NULL) {
		Q->head->next=NULL;
		Q->rear=Q->head;
		return 1;
	} else return -1;
}
//车辆到达
void Ar(parking *E,LinkCar *W) {
	car *p;
	queue *t;
	int c;
	p=(car *)malloc(sizeof(car));
	printf("请输入车辆类型：");
	while(2) {
		scanf("%d",&c);
		if(c>0&&c<3)
			break;
		else printf("警告！请重新输入车辆类型\n");
	}
	p->type=c;
	printf("请输入进场车辆的车牌号：\n");
	scanf("%d",&(p->num));
	printf("车辆的车牌号:%d\n",p->num);

	//判断车站是否满
	if(E->top<N) {
		E->top++;
		printf("该车的位置是： %d\n",E->top);
		printf("该车的到达时间为: ");
		//scanf("%d",&(p->time1));
		scanf("%d %d",&p->h1,&p->m1);
		//E->stcak[car->time1]=p->time1;
		E->stcak[E->top]=p;
	}

	else {
		printf("停车场已满，请进入通道排队等候\n");
		//getchar();
		t=(queue *)malloc(sizeof(queue));
		t->data=p;
		t->next=NULL;
		W->rear->next=t;
		W->rear=t;
	}
}
void print_(car *p) {
	//错误四，参数不匹配，将参数重新分配
//	p=(car *)malloc(sizeof(car));
	int t1,t2;
	double m=0;
	printf("该车离开的时间：");
	//scanf("%d",&(p->time2));
	scanf("%d %d",&p->h2,&p->m2);
	printf("离开车辆的车牌：%d",p->num);
	printf("离开车辆的到达时间：%d:%d，离开时间：%d:%d\n",p->h1,p->m1,p->h2,p->m2);
	//printf("离开车辆的到达时间：%d，离开时间：%d\n",p->time1,p->time2);
	t1=p->h2-p->h1;
	t2=p->m2-p->m1;
	if(p->type==1)
		m=(t1+t2/60*1.0)*price1;
	if(p->type==2)
		m=(t1+t2/60*1.0)*price2;
	printf("应缴纳的停车费为%.lf元，谢谢惠顾！",m);
	free(p);
}
void Le(parking *E,parking *T,LinkCar *W) {
	int po;//出场车辆的位置
	car *p,*t;
	queue *q;
	p=(car *)malloc(sizeof(car));
	if(E->top>0) { //停车场不空
		//车辆出厂 的位置输入
		while(2) {
			printf("停车场中此时的车辆数： %d\n",E->top);
			printf("出场车辆的位置：");
			scanf("%d",&po);
			if(po>=1&&po<=E->top)  //保证位置合法
				//	printf("允许离开\n");
				break;
			else printf("请重新输入！\n");
		}

		while(E->top>po) { //排在出场车辆后面的车进入临时车场为其让路
			T->top++; //临时停车场的存放位置加一
			T->stcak[T->top] = E->stcak[E->top];
			//	E->stcak[E->top]=NULL;
			E->top--;
		}
		p=E->stcak[E->top];//将要离开的车辆
		//E->stcak[E->top]=NULL;//将离开的车辆的位置置空
		E->top--;//停车场的车辆数目减一

		//将暂时停在临时停车场中的车辆重新开回停车场
		while(T->top>=1) {
			E->top++;
			E->stcak[E->top]=T->stcak[T->top];
			//	T->stcak[T->top]=NULL;
			T->top--;
		}
		print_(p);
		/*判断通道上是否有车及车站是否已满*/
		if(W->head!=W->rear&&E->top<N) {//通道上有车且车厂不满
			q=W->head->next;//跳过头节点
			t=q->data;
			E->top++;
			printf("通道车牌号为%d的车辆进入停车场%d的位置",t->num,E->top);
			printf("请输入该车的入场时间：");
			scanf("%d% d",&p->h1,&p->m1);
			//scanf("%d",&t->time1);
			//scanf("%d %d %d",&(t->h1),&(t->m1),&(t->s1));
			W->head->next=q->next;//判断通道的下一辆车
			if(q==W->rear)//循环队列的队尾
				W->rear=W->head;
			E->stcak[E->top]=t;
			free(q);
		} else printf("通道内没有车辆\n");
	}

	else
		printf("停车场里没有车\n");
}
void attention() {
	printf("------------------------用户使用说明------------------------\n");
	printf("输入1代表小型车，小型车的停车费为每小时2元，输入2代表大型车，大型车的车费为每小时3元\n");
	printf("输入A｀表示到达，输入｀D｀表示离去，输入｀E｀表示输入结束\n");
}
int main() {
	int c;
	car *p;
	char ch;
	parking E,T;//E为车站，T为临时车站
	LinkCar W;//W为通道
	attention();
	InitStack1(&E);
	InitStack1(&T);
	Initqueue(&W);


	while(3) {
		printf("\n\n\t\t\t1. 车辆到达 请选择 A");
		printf("\n\n\t\t\t2. 车辆离开 请选择 D");
		printf("\n\n\t\t\t3. 退出程序 请选择 E");
		printf("\n");
		printf("\n\n\t\t\t现在请输入您的选择 :  ");
		while((ch=getchar())!='\n')
			while(1) {
				///scanf("%c",&ch);
				//getchar();
				if(ch=='A'||ch=='D'||ch=='E') {
					switch(ch) {
						case 'A':
							Ar(&E,&W);
							break;
						case 'D':
							Le(&E,&T,&W);
							break;
						case 'E':
							exit(0);
							break;
					}
					break;
				} else {
					printf("请重新输入指令\n");
					scanf("%c",&ch);
					getchar();
				}
			}
	}
	return 0;
}

