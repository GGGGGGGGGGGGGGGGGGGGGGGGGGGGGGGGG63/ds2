#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    Solution(int num) {
        n = num;
    }
    void solve();//��n�ֽ�Ϊ�����ӵĳ˻�
private:
    int n;
};
void Solution::solve(){
	int j;
	if(n>=2)
	cout<<n<<"=";
	for( j=2; j<=sqrt(n);j++ ){
		if(n%j==0){
			cout<<j;
			n /= j;
			j = 1;
			if(n>1)
			cout<<"*";
		}
		
	}
	cout<<endl;
}
int main()
{
    int n;
    while (cin >> n) {
        Solution obj(n);
        obj.solve();
    }
    return 0;
}
