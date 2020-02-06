// class_vector_ext.cpp -- methods for the vector class
#include <cmath>
#include "class_vector_ext.hpp"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR_EXT
{
    // computer degree in one radian
    const double rad_to_degree = 45.0 / atan( 1.0 );    //shoule be about 57.2957795130823

    // private methods
    void vector_ext::set_length()
    {
        length = sqrt( x * x + y * y );
    }

    void vector_ext::set_angle()
    {
        if( x == 0 && y == 0 )
        {
            angle = 0;
        }
        else
        {
        angle = atan2( y, x );
        }
    }

    void vector_ext::set_x()
    {
        x = length * cos( angle );
    }

    void vector_ext::set_y()
    {
        y = length * sin( angle );
    }

    //public methods
    vector_ext::vector_ext()
    {}

    vector_ext::vector_ext( double n1, double n2, mode_ext form )
    {
        mode = form;
        if( RECT == form )
        {
            x = n1;
            y = n2;
            set_length();
            set_angle();
        }
        else if( POL == form )
        {
            length = n1;
            angle  = n2 / rad_to_degree;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to vector.\n";
            cout << "vector set to 0.\n";
            x = y = length = angle = 0;
            mode = RECT;
        }
    }

    void vector_ext::reset( double n1, double n2, mode_ext form )
    {
        mode = form;
        if( RECT == form )
        {
            x = n1;
            y = n2;
            set_length();
            set_angle();
        }
        else if( POL == form )
        {
            length = n1;
            angle  = n2 / rad_to_degree;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to vector.\n";
            cout << "vector set to 0.\n";
            x = y = length = angle = 0;
            mode = RECT;
        }
    }

    vector_ext::~vector_ext()
    {}

    void vector_ext::polar_mode()
    {
        mode = POL;
    }

    void vector_ext::rect_mode()
    {
        mode = RECT;
    }

    // operator overloading
    vector_ext vector_ext::operator+( const vector_ext & b ) const
    {
        return vector_ext( x + b.x, y + b.y );
    }

    vector_ext vector_ext::operator-( const vector_ext & b ) const
    {
        return vector_ext( x - b.x, y - b.y );
    }
    vector_ext vector_ext::operator-() const
    {
        return vector_ext( -x, -y );
    }

    vector_ext vector_ext::operator*( double n ) const
    {
        return vector_ext( x * n, y * n );
    }
    //friends
    vector_ext operator*( double n, const vector_ext & a )
    {
        //return vector_ext( a.x * n, a.y * n );
        return a * n;
    }
    std::ostream & operator<<( std::ostream & os, const vector_ext & v )
    {
        if( vector_ext::RECT == v.mode )
        {
            os << "( x, y ) = " << "( " << v.x << " , " << v.y << " )";
        }
        else if( vector_ext::POL == v.mode )
        {
            os << "( length, angle ) = " << "( " << v.length << " , " << v.angle * rad_to_degree << " )";
        }
        else
        {
            os << "Vector object is mode invalid.\n";
        }

        return os;
    }
}