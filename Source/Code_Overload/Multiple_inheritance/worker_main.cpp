// worker_main.cpp -- multiple inheritance
#include <iostream>
#include <cstring>
#include "worker.hpp"
const int SIZE = 5;

void worker_main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker * lolas[SIZE];

    int ct;
    for( ct = 0; ct < SIZE; ct++ )
    {
        char choice;
        cout << "Enter the employee category:\n";
        cout << "w: waiter   s: singer ";
        cout << "t: singing waiter   q: quit\n";
        cin >> choice;

        while ( strchr( "wstq", choice ) == nullptr )
        {
            cout << "Please enter a w, s, t, or q:";
            cin >> choice;
        }
        if( 'q' == choice )
        {
            break;
        }
        switch( choice )
        {
            case 'w':
                lolas[ct] = new Waiter;
                break;

            case 's':
                lolas[ct] = new Singer;
                break;

            case 't':
                lolas[ct] = new SingerWaiter;
                break;
        }

        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for( i = 0; i < ct; i++ )
    {
        cout << endl;
        lolas[i]->Show();
    }
    for( i = 0; i < ct; i++ )
    {
        delete lolas[i];
    }
    cout << "Bye!";
}