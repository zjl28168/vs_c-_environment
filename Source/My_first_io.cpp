//myfirst.cpp -- display a message
#include <iostream>
//#include "stdlib.h"

int my_sum_fuc( int a, int b );

void myfirst( void )
{
using namespace std;
int num1, num2;
cout << "Come up and c++ me some time." << endl;
cout << "Please input:" << endl;
cout << "a=";
cin >> num1;
cout << "b=";
cin >> num2;
cout << "a+b=" << my_sum_fuc( num1, num2 ) << endl;
cout << "You won't forget it!"<<endl;
cin.get();
cin.get();
}

int my_sum_fuc( int a, int b )
{
    int sum;
    sum = a + b;
    return sum;
}