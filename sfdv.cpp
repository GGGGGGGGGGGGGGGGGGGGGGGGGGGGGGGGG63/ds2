#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	sort(a,a+N);
	for(int i=0;i<N;i++)
	{
		if(i==N-1)
		{
			cout<<a[i];
			break;
		}
		cout<<a[i]<<" ";
		
	}
	return 0;
}
