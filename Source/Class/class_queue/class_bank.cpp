// class_bank.cpp -- using the Queue interface
//模拟银行处理排队问题，平均每6分钟有一个客户，然后每个可出处理时间1-3分钟，
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "class_queue.hpp"

const int MIN_PER_HR = 60;

bool new_customer( double x );       // is there a new customer

void class_bank()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::ios_base;
    //setting thing up
    std::srand( std::time( 0 ) );       //random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maxinum size of queue: ";
    int qs;
    cin >> qs;
    Queue line( qs );                   // line queue holds up to qs people

    cout << "Enter the number of simulator hours: ";
    int hours;
    cin >> hours;
    //simulation will run 1 cycle per minute
    long cycleLimit = MIN_PER_HR * hours;

    cout << "Enter the averange number of customer per hours: ";
    double perHour;
    cin >> perHour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perHour;

    Item temp;          // new customer data
    long turnAways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0;    // served during the sumulation
    long sum_line = 0;  // cumulative line length
    int wait_time = 0;  // time until autoteller is free
    long line_wait = 0; // cumulative time in line

    // running the simulation
    for( int cycle = 0; cycle < cycleLimit; cycle++ )
    {
        if( new_customer( min_per_cust ) )       // have new customer
        {
            if( line.isFull() )
            {
                turnAways++;
            }
            else
            {
                customers++;
                temp.set( cycle );      // cycle = time of arrive
                line.enQueue( temp );   // add new customer to lines
            }
        }
        if( wait_time <= 0 && !line.isEmpty() )
        {
            line.deQueue( temp );       // attend next customer
            wait_time = temp.ptime();   // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if( wait_time > 0 )
        {
            wait_time--;
        }
        sum_line += line.queueCount();
    }

    // report results
    if( customers > 0 )
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "        turn aways: " << turnAways << endl;
        cout << "average queue sieze: ";
        cout.precision( 2 );
        cout.setf( ios_base::fixed, ios_base::floatfield );
        cout << (double) sum_line / cycleLimit << endl;
        cout << " average wait time: " ;
        cout << (double) line_wait / served << " minutes\n";
    }
    else
    {
        cout << "No customers!\n";
    }
    cout << "Done!\n";
}

// x = average time, in minute, between customers
// return value is true if customer shows up this munutes
bool new_customer( double x )
{
    return ( ( ( std::rand() * x ) / RAND_MAX ) < 1 );
}