// fctn_array_range.cpp -- functions with an array range
#include <iostream>
const int arsize = 8;
static int sum_arr( const int *begin, const int *end );

void fctn_array_range()
{
    using namespace std;
    int cookies[arsize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
    //Some systems require preceding int with satic to enable array initialization

    int sum  = sum_arr( cookies, cookies + arsize );
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr( cookies, cookies + 3 );
    cout << "First three eaters are: " << sum << " cookies." << endl;
    sum = sum_arr( cookies + 4, cookies + 8 );
    cout << "Last four eaters are: " << sum << " cookies." << endl;
}

//return the sum of an integer array
int sum_arr( const int *begin, const int *end )
{
    const int *pt;
    int total = 0;

    for( pt = begin; pt != end; pt++ )
    {
        total += *pt;
    }
    return total;
}