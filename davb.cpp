#include<stdio.h>
#include<stdlib.h>
#define N 5
#define price1 2//С�ͳ�ÿСʱ����
#define price2 3// ���ͳ�ÿСʱ����
int a;
//������Ϣ
typedef struct {
//	int h1,h2,m1,m2,s1,s2;
	int h1,h2,m1,m2;
//	int time1,time2;
	int type;
	int num;
} car;
//ͣ����ջ
typedef struct Node {
	car *stcak[N+1];
	int top;
} parking;

//ͨ��
typedef struct q {
	/*int*/ car *data;
	struct q *next;
} queue;
typedef struct {
	queue *head;
	queue *rear;
} LinkCar;
//��ʼ������
void InitStack1(parking *p) {
	int i;
	p->top=0;
	//p->top=-1;����Ӧ��1��ʼ
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
//��������
void Ar(parking *E,LinkCar *W) {
	car *p;
	queue *t;
	int c;
	p=(car *)malloc(sizeof(car));
	printf("�����복�����ͣ�");
	while(2) {
		scanf("%d",&c);
		if(c>0&&c<3)
			break;
		else printf("���棡���������복������\n");
	}
	p->type=c;
	printf("��������������ĳ��ƺţ�\n");
	scanf("%d",&(p->num));
	printf("�����ĳ��ƺ�:%d\n",p->num);

	//�жϳ�վ�Ƿ���
	if(E->top<N) {
		E->top++;
		printf("�ó���λ���ǣ� %d\n",E->top);
		printf("�ó��ĵ���ʱ��Ϊ: ");
		//scanf("%d",&(p->time1));
		scanf("%d %d",&p->h1,&p->m1);
		//E->stcak[car->time1]=p->time1;
		E->stcak[E->top]=p;
	}

	else {
		printf("ͣ���������������ͨ���ŶӵȺ�\n");
		//getchar();
		t=(queue *)malloc(sizeof(queue));
		t->data=p;
		t->next=NULL;
		W->rear->next=t;
		W->rear=t;
	}
}
void print_(car *p) {
	//�����ģ�������ƥ�䣬���������·���
//	p=(car *)malloc(sizeof(car));
	int t1,t2;
	double m=0;
	printf("�ó��뿪��ʱ�䣺");
	//scanf("%d",&(p->time2));
	scanf("%d %d",&p->h2,&p->m2);
	printf("�뿪�����ĳ��ƣ�%d",p->num);
	printf("�뿪�����ĵ���ʱ�䣺%d:%d���뿪ʱ�䣺%d:%d\n",p->h1,p->m1,p->h2,p->m2);
	//printf("�뿪�����ĵ���ʱ�䣺%d���뿪ʱ�䣺%d\n",p->time1,p->time2);
	t1=p->h2-p->h1;
	t2=p->m2-p->m1;
	if(p->type==1)
		m=(t1+t2/60*1.0)*price1;
	if(p->type==2)
		m=(t1+t2/60*1.0)*price2;
	printf("Ӧ���ɵ�ͣ����Ϊ%.lfԪ��лл�ݹˣ�",m);
	free(p);
}
void Le(parking *E,parking *T,LinkCar *W) {
	int po;//����������λ��
	car *p,*t;
	queue *q;
	p=(car *)malloc(sizeof(car));
	if(E->top>0) { //ͣ��������
		//�������� ��λ������
		while(2) {
			printf("ͣ�����д�ʱ�ĳ������� %d\n",E->top);
			printf("����������λ�ã�");
			scanf("%d",&po);
			if(po>=1&&po<=E->top)  //��֤λ�úϷ�
				//	printf("�����뿪\n");
				break;
			else printf("���������룡\n");
		}

		while(E->top>po) { //���ڳ�����������ĳ�������ʱ����Ϊ����·
			T->top++; //��ʱͣ�����Ĵ��λ�ü�һ
			T->stcak[T->top] = E->stcak[E->top];
			//	E->stcak[E->top]=NULL;
			E->top--;
		}
		p=E->stcak[E->top];//��Ҫ�뿪�ĳ���
		//E->stcak[E->top]=NULL;//���뿪�ĳ�����λ���ÿ�
		E->top--;//ͣ�����ĳ�����Ŀ��һ

		//����ʱͣ����ʱͣ�����еĳ������¿���ͣ����
		while(T->top>=1) {
			E->top++;
			E->stcak[E->top]=T->stcak[T->top];
			//	T->stcak[T->top]=NULL;
			T->top--;
		}
		print_(p);
		/*�ж�ͨ�����Ƿ��г�����վ�Ƿ�����*/
		if(W->head!=W->rear&&E->top<N) {//ͨ�����г��ҳ�������
			q=W->head->next;//����ͷ�ڵ�
			t=q->data;
			E->top++;
			printf("ͨ�����ƺ�Ϊ%d�ĳ�������ͣ����%d��λ��",t->num,E->top);
			printf("������ó����볡ʱ�䣺");
			scanf("%d% d",&p->h1,&p->m1);
			//scanf("%d",&t->time1);
			//scanf("%d %d %d",&(t->h1),&(t->m1),&(t->s1));
			W->head->next=q->next;//�ж�ͨ������һ����
			if(q==W->rear)//ѭ�����еĶ�β
				W->rear=W->head;
			E->stcak[E->top]=t;
			free(q);
		} else printf("ͨ����û�г���\n");
	}

	else
		printf("ͣ������û�г�\n");
}
void attention() {
	printf("------------------------�û�ʹ��˵��------------------------\n");
	printf("����1����С�ͳ���С�ͳ���ͣ����ΪÿСʱ2Ԫ������2������ͳ������ͳ��ĳ���ΪÿСʱ3Ԫ\n");
	printf("����A���ʾ��������D���ʾ��ȥ�������E���ʾ�������\n");
}
int main() {
	int c;
	car *p;
	char ch;
	parking E,T;//EΪ��վ��TΪ��ʱ��վ
	LinkCar W;//WΪͨ��
	attention();
	InitStack1(&E);
	InitStack1(&T);
	Initqueue(&W);


	while(3) {
		printf("\n\n\t\t\t1. �������� ��ѡ�� A");
		printf("\n\n\t\t\t2. �����뿪 ��ѡ�� D");
		printf("\n\n\t\t\t3. �˳����� ��ѡ�� E");
		printf("\n");
		printf("\n\n\t\t\t��������������ѡ�� :  ");
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
					printf("����������ָ��\n");
					scanf("%c",&ch);
					getchar();
				}
			}
	}
	return 0;
}

