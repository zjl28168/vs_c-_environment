// class_array.cpp -- using the stock class array
#include <iostream>
#include "stock.hpp"

const int STKS = 4;

void class_array()
{
    {
        using std::cout;
        cout << "Create an array of initialized objects\n";
        stock stock_arr[STKS] = 
        {
            stock( "One", 1, 10 ),
            stock( "Two", 2, 20 ),
            stock( "Three", 3, 30 ),
            stock( "Four", 4, 40 ),
        };

        std::cout << "holding:\n";
        int st;
        for( st = 0; st < STKS; st++ )
        {
            stock_arr[st].show();
        }

        //set pointer to the first element
        const stock *top = & stock_arr[0];
        for( st = 1; st < STKS; st++ )
        {
            top = &top->top_value( stock_arr[st] );
        }
        //now top pointer to the most valuable holding
        cout << "\n Most valuable holding:\n";
        top->show();
    }   //call the destructor function
}