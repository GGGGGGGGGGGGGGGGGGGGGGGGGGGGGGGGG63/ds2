#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	getchar();
	for(int i=0;i<n;i++)
	{
		int in=0,out=0,maxsize=m;
		getline(cin,s);
		int flag=0;
		for(int i=0;i<s.size();i++)
		{
			if(in == 0 && s[i] == 'X')
		{
			cout<<"No"<<endl;
			flag = 1;
			break;
		}
		if(in > m && i<s.size() || out<0)
		{
			cout<<"No"<<endl;
			flag = 1;
			break;
		}
		if(s[i] == 'S')
		{
			in++;
			out++;
		}
		else
		{
			in--;
			out--;
		}
		}
		
		if(flag == 0 && in==0)
	    {
		cout<<"Yes"<<endl;
		}
		else if(flag==0)
		{
			cout<<"No"<<endl;
		}
	}

	return 0;
}
