#include <stdio.h>
#include <stdlib.h>//malloc����

struct Node {    //������
    int data;    //����
    struct Node* link;    //ָ����һ������ָ��
};

/* β�巨�������������ص������ͷָ�� */
struct Node* buildLinkedList(int* arr, int n); /* β�巨���������� */
void printLinkedList(struct Node* head);       /* ��ӡ���� */

int main(int argc, char const *argv[]) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));	//��̬�ڴ������������ռ�
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    struct Node* head = NULL;	//����һ��ָ�����head

    //���������ѷ��ص�ͷָ�븳ֵ��headָ�����
    head = buildLinkedList(a, n);

    //��ӡ��������������head������
    printLinkedList(head);

    free(a);	//�ͷŴ洢�ռ�

    return 0;
}

/* ����������д�� */
struct Node* buildLinkedList(int* arr, int n)
{
	struct Node *head,*p,*t;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->link=NULL;
	p=head;
	for(int i=0;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=arr[i];
		t->link=NULL;
		p->link=t;
		p=t;
	}
	return head;
} 
void printLinkedList(struct Node* head)
{
	head=head->link;
	printf("%d",head->data);
	head=head->link;
	while(head!=NULL)
	{
		printf(" %d",head->data);
		head=head->link;
	}
}
