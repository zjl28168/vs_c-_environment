// class_account_abc_main.cpp -- polymorphic example using an abstract base class
#include <iostream>
#include <string>
#include "class_account_abc.hpp"
const int CLIENTS = 4;

void class_account_abc_main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long temp_num;
    double temp_bal;
    char kind;
    int i;

    for( i = 0; i < CLIENTS; i++ )
    {
        cout << "Enter client's name: ";
        getline( cin, temp );
        cout << "Enter client's account number: ";
        cin >> temp_num;
        cout <<"Enter opening balance: $";
        cin >> temp_bal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while( cin >> kind && ( kind != '1' && kind != '2' ) )
        {
            cout << "Enter 1 or 2: ";
        }
        if( '1' == kind )
        {
            p_clients[i] = new Brass( temp, temp_num, temp_bal );
        }
        else
        {
            double max_t, rate_t;
            cout << "Enter the overdraft limit: $" << endl;
            cin >> max_t;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> rate_t;
            p_clients[i] = new BrassPlus( temp, temp_num, temp_bal, max_t, rate_t );
        }
        while( cin.get() != '\n' )
        {
            continue;
        }
    }

    cout << endl;

    for( i = 0; i < CLIENTS; i++ )
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for( i = 0; i < CLIENTS; i++ )
    {
        delete p_clients[i];    //free memory
    }
    cout << "Done!\n";
}