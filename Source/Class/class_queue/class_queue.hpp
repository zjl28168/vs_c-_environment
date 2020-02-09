// class_queue -- interface for queue
#ifndef CLASS_QUEUE
#define CLASS_QUEUE
// This queue wil contain Customer items
class Customer
{
private:
    long arrive;        //arrival time for customer
    int process_time;   //processing time for customer
public:
    Customer() { arrive = process_time = 0; }

    void set( long when );
    long when() const { return arrive; }
    int ptime() const { return process_time; }
};

typedef Customer Item;

class Queue
{
private:
    //class scope definitions

    //Node is a nested structure definition local to this c
    struct Node { Item item; struct Node * next; };
    enum { Q_SIZE = 10 };

    //private class members
    Node * front;       //pointers to front Queue
    Node * rear;        //pointers to rear fo Queue
    int items;          //current number of items in Queue
    const int qsize;    //maxinum number fo items in Queue
    //preemptive definitions to prevent public copy
    Queue( const Queue & q ) : qsize( 0 ) {}
    Queue & operator=( const Queue & q ) { return *this; }
public:
    Queue( int qs = Q_SIZE );       //create queue with a qs limit
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const;
    bool enQueue( const Item & item );      //add item to end
    bool deQueue( Item & item );            //remove item from front
};
#endif