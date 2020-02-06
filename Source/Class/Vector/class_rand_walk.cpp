// class_rand_walk -- using the vector class
// 酒鬼走50米需要多少步
#include <iostream>
#include <cstdlib>       // rand(),srand() prototypes
#include <ctime>         // time() prototype
#include <cmath>
#include "class_vector_ext.hpp"

void class_rand_walk()
{
    using namespace std;
    using VECTOR_EXT::vector_ext;
    srand( time( 0 ) );     // seed random number generator
    double direction;
    vector_ext step;
    vector_ext result( 0.0, 0.0 );
    unsigned long steps = 0;
    double target;
    double step_length;
    cout << "Enter target distance ( q to quit ): ";
    while( cin >> target )
    {
        target = fabs( target );

        cout << "Enter step length: ";
        if( !( cin >> step_length ) )
        {
            break;
        }

        while( result.get_length() < target )
        {
            direction = rand() % 360;
            step.reset( step_length, direction, vector_ext::POL );
            result = result + step;
            steps++;
        }
        cout << "After " << steps << "steps, the subject has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step =" << result.get_length() / steps << endl;
        steps = 0;
        result.reset( 0.0, 0.0 );
        cout << "Enter target distance ( q to quit ):";
    }
    cout << "Bye.\n";
    cin.clear();
    while( cin.get() != '\n' )
    {
        continue;
    }
}
