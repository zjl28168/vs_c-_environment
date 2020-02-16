// class_template.cpp -- class template
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V>       // nested template class member
    class hold
    {
    private:
        V val;
    public:
        hold( V v = 0 ) : val( v ) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    };
    hold<T> q;          // template object
    hold<int> n;        // template object
public:
    beta( T t, int i ) : q( t ), n( i ) {}
    template<typename U>  //template method
    U balb( U u, T t ) { return ( n.Value() + q.Value() ) * u / t; }
    void Show() const { q.show(); n.show(); }
};

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend( const T & i ) : item( i ) { ct++; }
    ~HasFriend() { --ct; };
    friend void counts();
    friend void reports( HasFriend<T> & );      // template parameter
};

// each specialization has its own static data member
template<typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> class
void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
void reports( HasFriend<int> & hf )
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports( HasFriend<double> & hf )
{
    cout << "HasFriend<double>: " << hf.item << endl;
}

void class_template()
{
    {
        beta<double> guy( 3.5, 3 );
        cout << "T was set to double" << endl;
        guy.Show();
        cout << "V was set to T, which is double, then V was set to int" << endl;
        cout << guy.balb( 10, 2.3 ) << endl;
        cout << "U was set to int" << endl;
        cout << guy.balb( 10.0, 2.3 ) << endl;
        cout << "U was set to double" << endl;
        cout << "Done!" << endl;
    }

    {
        cout << "No objects declared: ";
        counts();
        HasFriend<int> hfi1( 10 );
        cout << "After hfi1 declared: ";
        counts();
        HasFriend<int> hfi2( 20 );
        cout << "After hfi2 declared: ";
        counts();
        HasFriend<double> hfdb( 10.5 );
        cout << "After hfdb declared: ";
        counts();
        reports( hfi1 );
        reports( hfi2 );
        reports( hfdb );
    }
}