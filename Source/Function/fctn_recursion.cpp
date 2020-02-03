// fctn_recursion.cpp
// 1. using recursion.
// 2. using recursion to subdivide a ruler.
#include <iostream>
const int len = 66;
const int divs = 6;
void subdivide( char ar[], int low, int high, int level );
void countdown( int n );

void fctn_recursion()
{
    char ruler[len];
    int i;
    int count_num = 4;
    countdown( count_num );
    std::cout << std::endl;
    for( i = 1; i < len - 2; i++ )
    {
        ruler[i] = '_';
    }
    ruler[len - 1] = '\0';
    int max = len -2;
    int min = 0;
    ruler[ min ] = ruler[ max ] = '|';
    std::cout << ruler << std::endl;
    for( i = 1; i <= divs; i++ )
    {
        subdivide( ruler, min, max, i );
        std::cout << ruler << std::endl;
        for( int j = 1; j < len - 2; j++ )
        {
            ruler[j] = '_';    //reset to blank ruler
        }
    }
}

void subdivide( char ar[], int low, int high, int level )
{
    if( level == 0 )
    {
        return;
    }
    int mid = ( low + high ) / 2;
    ar[mid] = '|';
    subdivide( ar, low, mid, level - 1 );
    subdivide( ar, mid, high, level - 1 );
}

void countdown( int n )
{
    using namespace std;
    cout << "Counting down ..." << n << endl;
    if( n > 0 )
    {
        countdown( n - 1 );
    }
    cout << n << ": Kaboom!\n";
}