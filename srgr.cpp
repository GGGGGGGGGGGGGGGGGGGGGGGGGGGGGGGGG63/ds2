#include <iostream>
using namespace std;

template<class T>
class MyArray{
private:
    T *data;
    int size;
 
public:
    MyArray(int s);
    ~MyArray();
    void sort();
    void display();
    bool check();
};
 
template<class T>
MyArray<T>::MyArray(int s){
        size = s;
        data = new T[size];//注意分配内存，main函数调用的时候只是动态的创建一个对象
        for(int i=0;i<size;i++)
            cin>>data[i];
    }
 
template<class T>
void MyArray<T>::display(){
    for(int i=0;i<size;i++){
        cout<<data[i];
        if(i<size-1)
            cout<<" ";
    }
    cout<<endl;
}
 
template<class T>
void MyArray<T>::sort(){
        for(int i=0;i<size-1;i++)
            for(int j=0;j<size-i-1;j++)
                if(data[j]>data[j+1]){
                    T temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
    }

/* 请在这里填写答案 */

template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
