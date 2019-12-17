#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType   r[MAXSIZE+1]; 
  int   length;
} SqList;                      

void Create(SqList &L)
{ int i;
  cin>>L.length;
  for(i=1;i<=L.length;i++)
     cin>>L.r[i].key;   
}

void Output(SqList L)
{ int i;
  for(i=1;i<=L.length;i++)
     cout<<L.r[i].key<<" ";
  cout<<endl;;
}

int Partition(SqList &L,int low,int high);  
void QuickSort(SqList &L, int low, int high);

int main () 
{  SqList L;  int low,high;
   Create(L);
   low=1; high=L.length;
   QuickSort(L,low,high);
   Output(L);
   return 0;
}
int Partition(SqList &L,int low,int high)
{
	int center = L.r[low].key;
	L.r[low].key = L.r[high].key;
	L.r[high].key = center;
	return center;
} 

void QuickSort(SqList &L, int low, int high)
{
	int p,lo,hi;
	if(low < high)
	{
		p = Partition(L, low, high);
		lo = low-1; hi = high;
		while(1)
		{
			while(L.r[++lo].key<p);
			while(L.r[--hi].key>p);
			if(lo<hi) 
			{
				int t = L.r[lo].key;
				L.r[lo].key = L.r[hi].key;
				L.r[hi].key = t;
			}
			else break; 
		}
		int t = L.r[lo].key;
		L.r[lo].key = L.r[high].key;
		L.r[high].key = t;
		QuickSort(L, low, lo-1);
		QuickSort(L, lo+1, high);
	}
}
