// smrtptrs.cpp -- using three kinds of smart pointers
// requires support of c++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Report
{
private:
    string str;

public:
    Report( const string s ) : str( s )
    { cout << "Object created!\n"; }

    ~Report() { cout << "Object deleted!\n"; }
    void comment() const { cout << str << "\n"; }
};

unique_ptr<string> demo( const char *s )
{
    unique_ptr<string> temp( new string( s ) );
    return temp;
}

void smrtptrs()
{
    {
        auto_ptr<Report> ps ( new Report( "Using auto_ptr" ) );
        ps->comment();   //use -> to invoke a member of function
    }
    {
        shared_ptr<Report> ps ( new Report(" Using shared_ptr" ) );
        ps->comment();
    }
    {
        unique_ptr<Report> ps ( new Report( "Using unique_ptr" ) );
        ps->comment();
    }
    {// 要安全地使用unique_ptr，可以给它赋新值，使用move（），能够将一个unique_ptr赋给另一个。
        unique_ptr<string> ps1, ps2;
        ps1 = demo( " Uniquely special " );
        ps2 = move( ps1 );
        ps1 = demo( "New Uniquely special " );//    enable assigment
        cout << "\nps1=" << *ps1 << endl;
        cout << "ps2=" << *ps2 << endl;
    }
}
//  使用new分配内存时，才能使用auto_ptr和shared_ptr，使用new[]分配内存时，不能使用它们，可以使用unique_ptr。不能使用new分配内存时，不能使用quto_ptr和
//  shared_ptr。
