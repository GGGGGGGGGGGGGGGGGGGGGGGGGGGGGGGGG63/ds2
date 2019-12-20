#include <iostream>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
int cnt=0;
class CPU{
	public: 
	CPU(CPU_Rank a=P1,int b=2,int c=100);
	CPU(const CPU &cx){
		cout<<"copy create a CPU!"<<endl;
		f=cx.f;
		v=cx.v;
		r=cx.r;
		cnt++;
	}
	void showinfo();
	
	private:
		int f,v;
		CPU_Rank r;	
};
CPU::CPU(CPU_Rank a,int b,int c):r(a),f(b),v(c){cnt++;cout<<"create a CPU!"<<endl;}
void CPU::showinfo(){
	cout<<"rank:"<<r<<endl<<"frequency:"<<f<<endl<<"voltage:"<<v<<endl;
	if(cnt==3){
		for(int i=1;i<=cnt;i++){
			cout<<"destruct a CPU!"<<endl;
		}
	}
}
int main()
{
	CPU a(P6,3,300); 
	
	cout<<"cpu a's parameter"<<endl;
	a.showinfo(); //显示性能参数

	CPU b; 
	cout<<"cpu b's parameter"<<endl;
	b.showinfo(); //显示性能参数

	CPU c(a); 
	cout<<"cpu c's parameter"<<endl;
	c.showinfo(); //显示性能参数
}
