//newplace.cpp  -- using placement new
/*定位new 运算符 通常，new负责在堆（heap）中找到一个足以能够满足要求的内存块。new 运算符还有另外一种遍体，被称为定位（placement）
new 运算符，它让您能制定要使用的位置。程序员可能使用这个特性来设置其内存管理规程、处理需要通过特定地址进行访问的硬件或在特定位置创建对象*/
#include <iostream>
#include <new>  //for placement new
const int BUF = 512;
const int N = 5;
char buffer[BUF];  //chunk of memory

void newplace()
{
    using namespace std;
    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];    //use heap
    pd2 = new (buffer)double[N];   //use buffer array
    for( i = 0; i < N; i++ )
        {
        pd2[i] = pd1[i] = 1000 + 20.0 * i;  
        }
    cout << "Memory addresses:\n" << " heap: " << pd1 << " static: " << (void *)buffer << endl;

    cout << "Memory contents:\n";
    for( i = 0; i < N; i++ )
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3 = new double[N];    //find new address;
    pd4 = new (buffer) double[N];   //overwrite old data
    for( i = 0; i < N; i++ )
    {
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    }
    cout << "Memory contens:\n";
    for( i = 0; i < N; i++ )
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete [] pd1;
    pd1 = new double[N];
    pd2 = new ( buffer + N * sizeof( double ) ) double[N];
    for( i = 0; i < N; i++ )
    {
        pd2[i] = pd1[i] = 1000 + 60.0 * i; 
    }
    cout << "Memory contents:\n";
    for( i = 0; i < N; i++ )
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    delete [] pd1;
    delete [] pd3;
    cin.get();
    cin.get();
}
/*定位new运算符确实将数组p2放在了数组buffer中，p2和buffer的地址都是一样的。然而，它们的类型不同，p1是double指针，而buffer是char
指针（顺便说一句，这也是程序使用（void *）对buffer进行强制转换的原因，如果不这样，cout将显示一个字符串）同时，常规new将数组p1
放在很远的地方，位于动态管理的堆中 */
