// fowl_auto_ptr.cpp -- auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>

void fowl_auto_ptr()
{
    using namespace std;
    #if( 1 )
    shared_ptr<string> films[5] = 
    {
        shared_ptr<string> ( new string( " Fowl Balls " ) ),
        shared_ptr<string> ( new string( " Duck Walks " ) ),
        shared_ptr<string> ( new string( " Chicken Runs " ) ),
        shared_ptr<string> ( new string( " Turkey Errors " ) ),
        shared_ptr<string> ( new string( " Goose Eggs " ) )
    };

    shared_ptr<string> pwin;
    pwin = films[2];
    #else
    auto_ptr<string> films[5] = 
    {
        auto_ptr<string> ( new string( " Fowl Balls " ) ),
        auto_ptr<string> ( new string( " Duck Walks " ) ),
        auto_ptr<string> ( new string( " Chicken Runs " ) ),
        auto_ptr<string> ( new string( " Turkey Errors " ) ),
        auto_ptr<string> ( new string( " Goose Eggs " ) )
    };

    auto_ptr<string> pwin;
    pwin = films[2];  // films loses ownership  
    #endif

    cout << " The nominees for best avian baseball film are\n ";
    for( int i = 0; i < 5; i++ )
    {
        cout << *films[i] << endl;
    }
    cout << "The winner is " << *pwin << "!\n";
}