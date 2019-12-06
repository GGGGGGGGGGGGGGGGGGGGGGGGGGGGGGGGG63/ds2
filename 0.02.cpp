#include <iostream>  
#include <iomanip> 
#include <cmath> 
using namespace std;

int main()
{
    double eps, s = 1, sum = 0;
    cin >> eps;
    int i = 1, flag = -1; 
    do {
        flag *= -1;
        s = flag * (1.0/i); 
  
        sum += s;
        i += 3;
    }while(fabs(s) > eps);

    cout <<"sum = "<< fixed << sum << endl;

    return 0;
}

