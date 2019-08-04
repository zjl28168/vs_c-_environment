#if !defined MAIN_MENU
#define MAIN_MENU
#include <iostream>
#include <string>
//#include "My_first_io.cpp"
#define MAIN_MENU_TITLE_LENGHT  50

void myfirst( void );
void newplace( void );
using namespace std;

enum{
    FIRST_IO,
    NEW_PLACE,

    MENU_CNT
};


string main_menu_itm[]
{
"First IO Test",
"New Place",
};

void test_func( int item )
{
    switch ( item )
    {
    case FIRST_IO:
        myfirst();
        break;
    
    case NEW_PLACE:
        newplace();
        break;

    default:
        break;
    }
}

#if(0)
typedef void ( *test_proc )( void );

static const struct
    {
    test_proc   proc;
    }
test_table[]
{
/*FIRST_IO */ { myfirst },
};
#endif
#endif