// class_string.hpp -- test string definition
#ifndef CLASS_STRING_HPP
#define CLASS_STRING_HPP
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;         // pointer to string
    int len;            // length of string
    static int num_strings;     // number of object
    static const int CINLIM = 80;   // cin input limit
public:
    //constructors and other methods
    String( const char * s );       // constructor
    String();                       // default constructor
    String( const String & );       // copy constructor
    ~String();                      // destructor
    int length() const { return len; }
    //overloaded operator methods
    String & operator=( const String & );
    String & operator=( const char * );
    char & operator[]( int i ) const;
    //overloaded operator friends
    friend bool operator<( const String & s1, const String & s2 );
    friend bool operator>( const String & s1, const String & s2 );
    friend bool operator==( const String & s1, const String & s2 );
    friend ostream & operator<<( ostream & os, const String & st );
    friend istream & operator>>( istream & is, String & st );

    //static function
    static int HowMany();
};
#endif