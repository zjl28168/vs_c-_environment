//vector.cpp  -- methods and interators
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
    std::string title;
    int rating;
};
bool FillReview( Review &rr );
void ShowReview( const Review &rr );
bool operator<( const Review &r1, const Review &r2 );
bool worseThan( const Review &r1, const Review &r2 );

void voctor()
{
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while( FillReview( temp ) )
    {
        books.push_back( temp );
    }

    int num = books.size();
    if( num > 0 )
    {
        cout << " Thank you. You entered the following:\n" << "Rating\tBook\n";
        for( int i = 0; i < num; i++ )
        {
            ShowReview( books[i] );
        }
        cout << "Reprising:\n" << "Rating Book\n";
        vector<Review>::iterator pr;
        for( pr = books.begin(); pr != books.end(); pr++ )
        {
            ShowReview( *pr );
        }

        vector<Review> oldlist( books );    //copy constructor used
        if( num > 3 )
        {
            //remove 2 items
            books.erase( books.begin() + 1, books.begin() + 3 );
            cout << "After erasure:\n";
            for( pr = books.begin(); pr != books.end(); pr++ )
            {
                ShowReview( *pr );
            }

            //insert 1 item
            books.insert( books.begin(), oldlist.begin() + 1, oldlist.begin() + 2 );
            cout << "After insertion:\n";
            for( pr = books.begin(); pr != books.end(); pr++ )
            {
                ShowReview( *pr );
            }

            books.swap( oldlist );
            cout << "Swaping oldlist with books:\n";
            for( pr = books.begin(); pr != books.end(); pr++ )
            {
                ShowReview( *pr );
            }
        }
        else
        {
            cout << "Nothing entered, nothing gained.\n ";
        }
    }

    if( books.size() > 0 )
    {
        cout << "\nThis is vect3.cpp. You entered the following " << books.size() << " ratings\n" << "Rating Book\n";
        for_each( books.begin(), books.end(), ShowReview );

        sort( books.begin(), books.end() );
        cout << "Sorted by title:\n Rating\tBook\n";
        for_each( books.begin(), books.end(), ShowReview );

        sort( books.begin(), books.end(), worseThan );
        cout << "Sorted by rating:\n Rating\tBook\n";
        for_each( books.begin(), books.end(), ShowReview );

        random_shuffle( books.begin(), books.end() );
        cout << "After shuffling:\n Rating\tBook\n";
        for_each( books.begin(), books.end(), ShowReview );
    }
    else
    {
        cout << "No entries. Bye.\n";
    }
}

bool FillReview( Review & rr )
{
    std::cout << " Enter book title ( quit to quit ): ";
    std::getline( std::cin, rr.title );
    if( "quit" == rr.title )
    {
        return false;
    }
    std::cout << " Enter book rating: ";
    std::cin >> rr.rating;
    if( !std::cin )
    {
        return false;//    get rid od rest of input line
    }
    while( std::cin.get() !='\n' )
    {
        continue;
    }
    return true;
}

void ShowReview( const Review &rr )
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}

bool operator<( const Review &r1, const Review &r2 )
{
    if( r1.title < r2.title )
    {
        return true;
    }
    else if( r1.title == r2.title && r1.rating < r2.rating )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool worseThan( const Review &r1, const Review &r2 )
{
    if( r1.rating < r2.rating )
    {
        return true;
    }
    else
    {
        return false;
    }
}