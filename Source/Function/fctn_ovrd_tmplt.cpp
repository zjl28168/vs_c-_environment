// fctn_ovrd_tmplt.cpp -- 
//1. specialization overrides a template
//2. choosing a template
#include <iostream>
template <typename T>
void swap_ext( T &a, T &b );

template <typename T>
T lesser( T a, T b )    // #1
{
    return a < b ? a : b;
}

int lesser( int a, int b )    //#2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}
struct job
{
    char name[40];
    double salary;
    int floor;
};

// explicit specialization
template <> void swap_ext<job>( job &j1, job &j2 );
static void show( const job &j );

void fctn_ovrd_tmplt()
{
    using namespace std;
    // 1.specialization overrides a template
        {
        cout.precision( 2 );
        cout.setf( ios::fixed, ios::floatfield );
        int i = 10; 
        int j = 20;
        cout << "i, j = " << i << ", " << j << ".\n";
        cout << "Using compiler-generated int swapper:\n";
        swap_ext( i, j ); // generates void swap( int &, int & );
        cout << "Now i, j = " << i << ", " << j <<".\n";

        job one = { "One", 1.11, 1 };
        job two = { "Two", 2.22, 2 };
        cout << "Before job swapping:\n";
        show( one );
        show( two );
        swap_ext( one, two );   // Using void swap( job &, job & )
        cout << "After swapping:\n";
        show( one );
        show( two );
        }

    //2. choosing a template
    {
        int m = 20;
        int n = 30;
        double x = 15.65;
        double y = 25.55;
        cout << endl;
        cout << "m, n = " << m << ", " << n << endl;
        cout << "x, y = " << x << ", " << y << endl;

        cout << "min of (m, n) is " << lesser( m, n ) << endl;     //use #2
        cout << "min of (x, y) is " << lesser( x, y ) << endl;     //use #1 with double
        cout << "min of (m, n) is " << lesser<>( m, n ) << endl;   //use #1 with int
        cout << "min of (x, y) is " << lesser<int>( x, y ) << endl; //use #1 with int;
    }
}

template <typename T>
void swap_ext( T &a, T &b )
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure
template <> void swap_ext<job>( job &j1, job &j2 )
{
    double salary_temp;
    int floor_temp;

    salary_temp = j1.salary;
    j1.salary = j2.salary;
    j2.salary = salary_temp;

    floor_temp = j1.floor;
    j1.floor = j2.floor;
    j2.floor = floor_temp;
}

static void show( const job &j )
{
    using namespace std;
    cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
