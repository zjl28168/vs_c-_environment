//class_new_ptr -- using pointer to objects
#include <iostream>
#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include "class_string.hpp"

const int ArSize = 10;
const int MaxLen = 81;

void class_ptr_main()
{
    using namespace std;

    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;

    cout << name << ", please enter up to " << ArSize << " short saying <empty line to quit>:\n";
    String saying[ArSize];
    char temp[MaxLen];
    int i;
    for( i = 0; i < ArSize; i++ )
    {
        cout << i + 1 << ": ";
        cin.get( temp, MaxLen );
        while( cin && cin.get() != '\n' )
        {
            continue;
        }
        if( !cin || temp[0] == '\0' )
        {
            break;
        }
        else
        {
            saying[i] = temp;   //overloaded assignment
        }
    }
    cin.clear();
    int total = i;

    if( total > 0 )
    {
        //use pointers to keep track of shortest, first strings
        String * shortest = &saying[0];
        String * first    = &saying[0];

        cout << "Here are your saying:\n";
        for( i = 0; i < total; i++ )
        {
            cout << saying[i] << endl;
            if( saying[i].length() < shortest->length() )
            {
                shortest = &saying[i];
            }
            if( saying[i] < *first )
            {
                first = &saying[i];
            }
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First saying:\n" << *first << endl;
        srand( time(0) );
        int choice = rand() % total;    //pick index at random

        //use new to create, initalize new String object
        String * favorite = new String( saying[choice] );
        cout << "My favorite saying: \n" << *favorite << endl;
        delete favorite;
    }
    else
    {
        cout << "Not much to say, eh?\n";
    }
    cout << "Bye!" << endl;
}
