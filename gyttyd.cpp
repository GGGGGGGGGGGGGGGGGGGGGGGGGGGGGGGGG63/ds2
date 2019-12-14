
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct stackstruct                     /*ջ�Ľṹ��*/
{
	int id;
	int time;
	struct stackstruct *pre;
	struct stackstruct *next;
};
 
struct queuestruct
{
	int id;
	struct queuestruct *next;
};
 
struct stackstruct *stackhead1, *stackend1;
struct stackstruct *stackhead2, *stackend2;
struct queuestruct *queuehead, *queueend;
int stack1count, stack2count;                         /*ջ��Ԫ������*/
int queuecount;                         /*������Ԫ������*/
 
void push(int flag, struct stackstruct *p)
{
	struct stackstruct *stack;
	if (flag == 0)                  /*ջ1��ջ����*/
	{
		if (stack1count == 0)
		{
			stackhead1 = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stackhead1->id = p->id;
			stackhead1->time = p->time;
			stackhead1->next = NULL;
			stackhead1->pre = NULL;
			stackend1 = stackhead1;
		}
		else
		{
			stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stack->id = p->id;
			stack->time = p->time;
			stackend1->next = stack;
			stack->pre = stackend1;
			stack->next = NULL;
			stackend1 = stack;
		}
		stack1count++;
	}
	else if (flag == 1)               /*ջ2��ջ����*/
	{
		if (stack2count == 0)
		{
			stackhead2 = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stackhead2->id = p->id;
			stackhead2->time = p->time;
			stackhead2->next = NULL;
			stackhead2->pre = NULL;
			stackend2 = stackhead2;
		}
		else
		{
			stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stack->id = p->id;
			stack->time = p->time;
			stackend2->next = stack;
			stack->pre = stackend2;
			stack->next = NULL;
			stackend2 = stack;
		}
		stack2count++;
	}
}
 
struct stackstruct *pop(int id, int time)
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	if (stackend1->id != id)
	{
		stack->id = stackend1->id;
		stack->time = stackend1->time;
		stack->pre = stackend1->pre;
		free(stackend1);
		stackend1 = stack->pre;
		stackend1->next = NULL;
		stack1count--;
	}
	else
	{
		stack->id = stackend1->id;
		stack->time = stackend1->time;
		stack->pre = stackend1->pre;
		printf("%d��������ͣ����\n", id);
		printf("ͣ����ͣ��ʱ��: %d\n", time - stack->time);
		printf("Ӧ�ý��ɵķ���(����: 5): %d\n", 5 * (time - stack->time));
		printf("лл�عˣ�ף����;��죡\n"); 
		printf("--------------------------------------------------------------------------\n");
		free(stackend1);
		if (--stack1count == 0)
			stackend1 = stackhead1 = NULL;
		else
		{
			stackend1 = stack->pre;
			stackend1->next = NULL;
		}
		stack = NULL;
	}
	return stack;
}
 
struct stackstruct *pop1()
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	stack->id = stackend2->id;
	stack->time = stackend2->time;
	stack->pre = stackend2->pre;
	free(stackend2);
	stackend2 = stack->pre;
	stack2count--;
 
	return stack;
}
 
void Enqueue(struct stackstruct *p)
{
	struct queuestruct *queue;
	if (queuecount == 0)
	{
		queuehead = (struct queuestruct *)malloc(sizeof(struct queuestruct));
		queuehead->id = p->id;
		queuehead->next = NULL;
		queueend = queuehead;
	}
	else
	{
		queue = (struct queuestruct *)malloc(sizeof(struct queuestruct));
		queue->id = p->id;
		queue->next = NULL;
		queueend->next = queue;
		queueend = queue;
	}
	queuecount++;
}
 
struct stackstruct *Dequeue(int time)
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	stack->id = queuehead->id;
	stack->time = time;
	if (--queuecount == 0)
	{
		queuehead = NULL;
		queueend = NULL;
	}
	else
		queuehead = queuehead->next;
	return stack;
}
int main()
{
	int n;
	char s;
	struct stackstruct *p;
 
	printf("������ͣ����������ͨ����ͣ������������");
	scanf("%d", &n);
	getchar();
	stack1count = stack2count = queuecount = 0;
	p = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	while (scanf("(%c,%d,%d)", &s, &p->id, &p->time) != EOF)
	{
		getchar();
		if (s == 'E')
			break;
		else if (s == 'A')                /*��������*/
		{
			if (stack1count < n)                 /*ջδ������ջ����*/
			{
				push(0, p);
				printf("%d����������ͣ����\n", stackend1->id);
				printf("����ͣ����ʱ��: %d\n", stackend1->time);
				printf("ͣ��λ��: %d\n", stack1count);
					printf("--------------------------------------------------------------------------\n");
			}
			else                                /*ջ���������в���*/
			{
				Enqueue(p);
				printf("%d������������\n", p->id);
				printf("������ʱ��: %d\n", p->time);
				printf("���λ��: %d\n", queuecount);
					printf("--------------------------------------------------------------------------\n");
			}
		}
		else if (s == 'D')                /*������ȥ*/
		{
			struct stackstruct *temp;
			while ((temp = pop(p->id, p->time)) != NULL)
			{
				push(1, temp);                  
			}
			while (stack2count != 0)
			{
				push(0, pop1());
			}
			if (queuecount != 0)
			{
				push(0, Dequeue(p->time));
				printf("%d����������ͣ����\n", stackend1->id);
				printf("����ʱ��: %d\n", stackend1->time);
				printf("ͣ��λ��: %d\n", stack1count);
					printf("--------------------------------------------------------------------------\n");
			}
		}
	}
	return 0;}

