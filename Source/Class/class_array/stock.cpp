// stock.cpp -- stock class with constructors, destructor added
#include <iostream>
#include "stock.hpp"

//constructor
stock::stock()      // default constructor
{
    std::cout << "Deault constructor called:\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

stock::stock( const std::string & co, long num, double price )
{
    std::cout << "Campany: " << co << " is calling constructor\n";
    company  = co;
    if( num < 0 )
    {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = num;
    }

    if( price < 0 )
    {
        std::cout << "Number of share_val can't be negative; " << company << " share_val set to 0.\n";
        share_val = 0;
    }
    else
    {
        share_val = price;
    }

    set_total();
}

//class destructor
stock::~stock()
{
    std::cout << "Bye, " << company << "!\n";
}

// other methods
void stock::buy( long num, double price )
{
    if( num < 0 || price < 0 )
    {
        std::cout << "Number of shares/share_val can't be negative. Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_total();
    }
}

void stock::sell( long num, double price )
{
    if( num < 0 || price < 0 )
    {
        std::cout << "Number of shares/share_val can't be negative. Transaction is aborted.\n";
    }
    else if( num > shares )
    {
        std::cout << "You can't sell more than you have! Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_total();
    }
}

void stock::update( double price )
{
    if( price < 0 )
    {
        std::cout << "Number of share_val can't be negative. Transaction is aborted.\n";
    }
    else
    {
        share_val = price;
        set_total();
    }
}

void stock::show() const
{
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig = cout.setf( ios_base::fixed, ios_base::floatfield );
    std::streamsize perc = cout.precision( 3 );

    cout << "Company: " << company << " Shares: " << shares << "\n";
    cout << " Share Price: $" << share_val;

    //set format to #.##
    cout.precision( 2 );
    cout << " Total Worth: $" << total_val << "\n";

    //restore original format
    cout.setf( orig, ios_base::floatfield );
    cout.precision( perc );
}

const stock & stock::top_value( const stock &s ) const
{
    if( s.total_val > total_val )
    {
        return s;
    }
    else
    {
        return *this;
    }
}