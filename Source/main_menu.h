#if !defined MAIN_MENU
#define MAIN_MENU
#include <iostream>
#include <string>
#include "My_first_io.cpp"
#define MAIN_MENU_TITLE_LENGHT  50

using namespace std;

enum{
    FIRST_IO,

    MENU_CNT
};


string main_menu_itm[]
{
"First IO Test",
};


void test_func( int item )
{
    switch ( item )
    {
    case FIRST_IO:
        myfirst();
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