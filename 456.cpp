#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Athlete{
	int school;//学校编号 
	int item;//项目编号 
	int rank;//名次 
	int score;//成绩 
	char name[20];//成绩
	char sex;//性别 
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
	cout<<"编号为奇数的项目取前五名，得分顺序为7，5，3，2，1；编号为偶数的项目取前三名，得分顺序为5，3，2"<<endl;
	cout<<"请输入项目，运动员姓名，性别(w/m)，学校，名次"<<endl; 
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
	cout<<"打印成绩单和成绩报表："<<endl;
	for(j=1;j<=n;j++)  //学校数目 
	{
		womansum=0,mansum=0,sum=0;
		cout<<"*********************************"<<endl;
		cout<<"  学校   姓名   性别 项目 名次 分数"<<endl;
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
		    cout<<j<<"学校的团体总分是："<<sum<<endl;
			cout<<j<<"号学校的女子团体总分是："<<womansum<<endl;
			cout<<j<<"号学校的男子团体总分是："<<mansum<<endl;
			cout<<endl;
	}
}
int main()
{
	list L;
	int n,m,w;
	cout<<"请输出学校个数，男子项目以及女子项目的个数："<<endl;
	cin>>n>>m>>w;
	input(L,m,w);
	display(L,n);
	return 0;
}
