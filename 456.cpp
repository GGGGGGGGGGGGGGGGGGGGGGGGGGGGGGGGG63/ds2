#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Athlete{
	int school;//ѧУ��� 
	int item;//��Ŀ��� 
	int rank;//���� 
	int score;//�ɼ� 
	char name[20];//�ɼ�
	char sex;//�Ա� 
}a; 
struct list{
	Athlete athlete[100];
	int last;
};
int sum(int m,int w)
{
	int Sum=0;
	for(int i=1;i<=(m+w);i++)
	{
		if(i%2==1)
		    Sum=Sum+5;
		if(i%2==0)
		    Sum=Sum+3;		
	}
	return Sum;
}
void change(Athlete* a)
{
	if(a->item%2==0)
	{
		switch(a->rank)
		{
			case 1:
				a->score=5;
				break;
			case 2:
				a->score=3;
				break;
				case 3:
				a->score=2;
				break;
		}
	}
	if(a->item%2==1)
	{
		switch(a->rank)
		{
			case 1:
				a->score=7;
				break;
		    case 2:
		    	a->score=5;
		    	break;
		    case 3:
		    	a->score=3;
		    	break;
		    case 4:
		    	a->score=2;
		    	break;
		    case 5:
		    	a->score=1;
		    	break;
		}
	}
}
void input(list* L,int m,int w)
{
	int i=1; 
	L->last=sum(m,w);
	cout<<"���Ϊ��������Ŀȡǰ�������÷�˳��Ϊ7��5��3��2��1�����Ϊż������Ŀȡǰ�������÷�˳��Ϊ5��3��2"<<endl;
	cout<<"��������Ŀ���˶�Ա�������Ա�(w/m)��ѧУ������"<<endl; 
	for(int i=1;i<=L->last;i++)
	{
		cin>>L->athlete[i].item;
		cin>>L->athlete[i].name;
		cin>>L->athlete[i].sex;
		cin>>L->athlete[i].school;
		cin>>L->athlete[i].rank;
		change(& L->athlete[i]);
	}
}
void display(list* L,int n)
{
	int i,j;
	int sum=0,mansum=0,womansum=0;
	cout<<"��ӡ�ɼ����ͳɼ�����"<<endl;
	for(j=1;j<=n;j++)  //ѧУ��Ŀ 
	{
		womansum=0,mansum=0,sum=0;
		cout<<"*********************************"<<endl;
		cout<<"  ѧУ   ����   �Ա� ��Ŀ ���� ����"<<endl;
		for(i=1;i<=L->last;i++)
		{
			if(L->athlete[i].school==j)
			{
				cout<<"    "<<L->athlete[i].school;
				cout<<"    "<<L->athlete[i].name;
				cout<<"    "<<L->athlete[i].sex;
				cout<<"    "<<L->athlete[i].item;
				cout<<"    "<<L->athlete[i].rank;
				cout<<"    "<<L->athlete[i].score<<endl;
				if(L->athlete[i].sex=='w')
				womansum+=L->athlete[i].score;
					if(L->athlete[i].sex=='m')
				mansum+=L->athlete[i].score;
				sum=womansum+mansum;
				
			}
			
		 } 
		    cout<<j<<"ѧУ�������ܷ��ǣ�"<<sum<<endl;
			cout<<j<<"��ѧУ��Ů�������ܷ��ǣ�"<<womansum<<endl;
			cout<<j<<"��ѧУ�����������ܷ��ǣ�"<<mansum<<endl;
			cout<<endl;
	}
}
int main()
{
	list L;
	int n,m,w;
	cout<<"�����ѧУ������������Ŀ�Լ�Ů����Ŀ�ĸ�����"<<endl;
	cin>>n>>m>>w;
	input(L,m,w);
	display(L,n);
	return 0;
}
