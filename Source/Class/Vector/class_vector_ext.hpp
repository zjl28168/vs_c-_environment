// class_vector_ext.hpp -- vector class test
#ifndef CLASS_VECTOR_HPP
#define CLASS_VECTOR_HPP
#include <iostream>
namespace VECTOR_EXT
{
    class vector_ext
    {
    public:
        enum mode_ext { RECT, POL };  //RECT fro rectangular, POL for Polar modes
    private:
        double x;           // horizontal value
        double y;           // vertical vanle
        double length;      // length of the vector
        double angle;       // angle of the vector
        mode_ext mode;     // RECT or POL
        //private methods for setting values
        void set_length();
        void set_angle();
        void set_x();
        void set_y();
    public:
        vector_ext();
        vector_ext( double n1, double n2, mode_ext form = RECT );
        void reset( double n1, double n2, mode_ext form = RECT );
        ~vector_ext();
        double get_x() const { return x; }
        double get_y() const { return y; }
        double get_length() const { return length; }
        double get_angle() const { return angle; }
        void polar_mode();
        void rect_mode();
        // operator overloading
        vector_ext operator+( const vector_ext & b ) const;
        vector_ext operator-( const vector_ext & b ) const;
        vector_ext operator-() const;
        vector_ext operator*( double n ) const;
        //friends
        friend vector_ext operator*( double n, const vector_ext & a );
        friend std::ostream & operator<<( std::ostream & os, const vector_ext & v );
    };
}
#endif