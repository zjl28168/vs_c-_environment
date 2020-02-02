// lambda.cpp using lambda expressions and captured variable
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long size1 = 39L;
const long size2 = size1 * 100;
const long size3 = size2 * 100;

bool f3( int x ) { return x % 3 == 0; }
bool f13( int x ) { return x % 13 == 0; }

void lambda()
{
    using std::cout;
    std::vector<int> numbers( size1 );

    std::srand( std::time( 0 ) );
    std::generate( numbers.begin(), numbers.end(), std::rand );

    //using function pointers
    cout << "Sample size = " << size1 << std::endl;

    int count3 = std::count_if( numbers.begin(), numbers.end(), f3 );
    cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    int count13 = std::count_if( numbers.begin(), numbers.end(), f13 );
    cout << "Count of numbers divisible by 13: " << count13 << std::endl << std::endl;

    // Increase number of numbers
    numbers.resize( size2 );
    std::generate( numbers.begin(), numbers.end(), std::rand );
    cout << "Sample size = " << size2 << std::endl;
    //using a functor
    class f_mod
    {
    private:
        int dv;

    public:
        f_mod( int n = 1 ) : dv( n ) {}
        bool operator() ( int x ) { return x % dv == 0; }
    };

    count3 = std::count_if( numbers.begin(), numbers.end(), f_mod( 3 ) );
    cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    count13 = std::count_if( numbers.begin(), numbers.end(), f_mod( 13 ) );
    cout << "Count of numbers divisible by 13: " << count13 << std::endl << std::endl;

    // Increase number of numbers
    numbers.resize( size3 );
    std::generate( numbers.begin(), numbers.end(), std::rand );
    cout << "Using lambda:" << std::endl;
    cout << "Sample size = " << size3 << std::endl;
    // Using lambda
    count3 = std::count_if( numbers.begin(), numbers.end(),
             [] ( int x ) { return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    count13 = std::count_if( numbers.begin(), numbers.end(),
             [] ( int x ) { return x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << std::endl << std::endl;

    //Using lambdas
    cout << "Using lambdas:" << std::endl;
    count3 = 0;
    std::for_each( numbers.begin(), numbers.end(),
            [ &count3 ] ( int x ) { count3 += x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    count13 = 0;
    std::for_each( numbers.begin(), numbers.end(),
            [ &count13 ] ( int x ) { count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << std::endl << std::endl;

    //Using a single lambda
    cout << "Using a single lambda:" << std::endl;
    count3 = 0;
    count13 = 0;
    std::for_each( numbers.begin(), numbers.end(),
            [&] ( int x ) { count3 += x % 3 == 0; count13 += x % 13 == 0; } );
    cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    cout << "Count of numbers divisible by 13: " << count13 << std::endl;
}