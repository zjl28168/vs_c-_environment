// class_string.cpp -- String class methods
#include <cstring>
#include "class_string.hpp"
using std::cin;
using std::cout;
using std::endl;

//initializing static class member

int String::num_strings = 0;

//static method
int String::HowMany()
{
    return num_strings;
}

//class methods
String::String( const char * s )       // constructor
{
    len = std::strlen( s );         //set size
    str = new char[len + 1];        //allot storage
    std::strcpy( str, s );         //initialize pointer
    num_strings++;
}
String::String()                       // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String( const String & st )       // copy constructor
{
    num_strings++;
    len = st.len;
    str = new char[ len + 1 ];
    std::strcpy( str, st.str );
}

String::~String()                      // destructor
{
    --num_strings;
    delete [] str;
}

//overloaded operator methods
String & String::operator=( const String & st)
{
    if( this == &st )
    {
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[ len + 1 ];
    std::strcpy( str, st.str );
    return *this;
}

String & String::operator=( const char * s)
{
    delete [] str;
    len = std::strlen( s );
    str = new char[ len + 1 ];
    std::strcpy( str, s );
    return *this;
}
char & String::operator[]( int i ) const
{
    return str[i];
}

//overloaded operator friends
bool operator<( const String & s1, const String & s2 )
{
    return ( std::strcmp( s1.str, s2.str ) < 0 );
}

bool operator>( const String & s1, const String & s2 )
{
    return s2 < s1;
}

bool operator==( const String & s1, const String & s2 )
{
    return ( std::strcmp( s1.str, s2.str ) == 0 );
}

ostream & operator<<( ostream & os, const String & st )
{
    os << st.str;
    return os;
}

istream & operator>>( istream & is, String & st )
{
    char temp[String::CINLIM];
    is.get( temp, String::CINLIM );
    if( is )
    {
        st = temp;
    }
    while( is && is.get() != '\n' )
    {
        continue;
    }
    return is;
}