// class_conversion.cpp -- user-definition conversions
#include <iostream>
using std::cout;
#include "class_stone.hpp"

static void display( const stonewt & st, int n );

void class_conversion()
{
    {
        stonewt one = 275;      //uses constructor to initialize
        stonewt two( 285.7 );   //same as stonewt two(285.7)
        stonewt three( 21, 8 );

        cout << "The one weighed ";
        one.show_stn();
        cout << "The two weighed ";
        two.show_stn();
        cout << "The three weighed ";
        three.show_lbs();

        one = 276.8;
        three = 325;
        cout << "After dinner, the one weighed: ";
        one.show_lbs();
        cout << "After dinner, the three weighed: ";
        three.show_lbs();
        display( three, 2 );
        cout << "The two weighed enve more.\n";
        display( 422, 2 );
        cout << "No stone left unearned\n";
    }

    {
        stonewt four( 9, 2.8 );
        double p_wt = (double)four;     // explicit conversion
        cout << std::endl;
        cout << "Convert to double => ";
        cout << "four: " << p_wt << " pounds.\n";
        cout << "Convert to int => ";
        cout << "four: " << int( four ) << " pounds.\n";
    }
}

static void display( const stonewt & st, int n )
{
    int i;
    for( i = 0; i < n; i++ )
    {
        cout << "Wow: ";
        st.show_stn();
    }
}