
#include<iostream>
using namespace std; 
class Horse{
    public:
      Horse(){
          cout<<"Horse �����˿ռ�..."<<endl;
      }
      virtual void Fly(){
          cout<<"Just a horse."<<endl;
      }
      virtual ~Horse(){
          cout<<"Horse �ͷ��˿ռ�..."<<endl;
      }
};
class Pegasus:public Horse{
    public:
      Pegasus(){
          cout<<"Pegasus �����˿ռ�..."<<endl;
      }
      void Fly(){
          cout<<"I can fly!"<<endl;
      }
      /*~Pegasus(){
          cout<<"Pegasus �ͷ��˿ռ�..."<<endl;
      }*/ 
};
using namespace std;
int main()
{
	Horse *p1 = new Horse; //�����Horse �����˿ռ�...
	Horse *p2 = new Pegasus; /*  ������У�  
	                             Horse �����˿ռ�...
	                             Pegasus �����˿ռ�...   
			         */	
	cout << endl; 
	
	p1->Fly(); //�����Just a horse.
	p2->Fly(); //�����I can fly!
	cout << endl; 
	
	delete p1; //�����Horse �ͷ��˿ռ�...
	delete p2;  /* ������У�
	               Pegasus �ͷ��˿ռ�... 
	               Horse �ͷ��˿ռ�... 
		    */
	return 0;
}

