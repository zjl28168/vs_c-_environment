// class_queue.cpp -- Queue and Customer methos
#include "class_queue.hpp"
#include<stdlib.h>

//Queue methods
Queue::Queue( int qs ) : qsize( qs )       //create queue with a qs limit
{
    front = rear = nullptr;
    items = 0;
}
Queue::~Queue()
{
    Node * temp;
    while( front != nullptr )
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isEmpty() const
{
    return items == 0;
}

bool Queue::isFull() const
{
    return items == qsize;
}

int Queue::queueCount() const
{
    return items;
}

bool Queue::enQueue( const Item & item )      //add item to end
{
    if( isFull() )
    {
        return false;
    }

    Node * add = new Node;
    // on failure, new throws std::bad_alloc exception
    add->item = item;
    add->next =nullptr;
    items++;
    if( nullptr == front )
    {
        front = add;
    }
    else
    {
        rear->next = add;
    }
    rear = add;
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::deQueue( Item & item )            //remove item from front
{
    if( nullptr == front )
    {
        return false;
    }
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if( 0 == items )
    {
        rear = nullptr;
    }
    return true;
}

//time set a random value in the rang 1 - 3
void Customer::set( long when )
{
    process_time = std::rand() % 3 + 1;
    arrive = when;
}