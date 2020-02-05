// stock.hpp -- Stock class declaration with constuctors, destructor added
#ifndef STOCK_HPP
#define STOCK_HPP
#include <string>

class stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_total() { total_val = shares * share_val; }
public:
    stock();    // default constructor
    stock( const std::string & co, long num = 0, double price = 0.0 );
    ~stock();   //doing nothing destructor
    void buy( long num, double price );
    void sell( long num, double price );
    void update( double price );
    void show() const;
    const stock & top_value( const stock &s ) const;
};
#endif