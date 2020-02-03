#if !defined MAIN_MENU
#define MAIN_MENU
#include <iostream>
#include <string>
//#include "My_first_io.cpp"
#define MAIN_MENU_TITLE_LENGHT  50

void myfirst( void );
void newplace( void );
void the_blocks_problem( void );
void use_namespace( void );
void smrtptrs( void );
void fowl_auto_ptr( void );
void voctor( void );
void lambda( void );
void fctn_array_range( void );

using namespace std;

enum{
    FIRST_IO,
    NEW_PLACE,
    USE_NAMESPACE,
    THE_BLOCKS_PROBLEM,
    SMART_POINTERS,
    FOWL_AUTO_PTR,
    VOCTOR_TEMPLETE,
    LAMBDA,
    FCTN_ARRAY_RANGE,

    MENU_CNT
};

struct main_menu
{
string  name;     // Name of the menu
void   (*proc)(); // Process of the menu
};

struct main_menu menu_table[] = 
{
                                 /*Name                                Proc*/
    /*FIRST_IO*/             { "First IO Test",                        myfirst             },
    /*NEW_PLACE*/            { "New Place",                            newplace            },
    /*USE_NAMESPACE*/        { "Use Namespace",                        use_namespace       },
    /*THE_BLOCKS_PROBLEM*/   { "The Blocks Problem",                   the_blocks_problem  },
    /*SMART_POINTERS*/       { "Smart Pointers",                       smrtptrs            },
    /*FOWL_AUTO_PTR*/        { "Poor choice auto_ptr",                 fowl_auto_ptr       },
    /*VOCTOR_TEMPLETE*/      { "Vector Templete",                      voctor              },
    /*LAMBDA*/               { "Lambda",                               lambda              },
    /*FCTN_ARRAY_RANGE*/     { "Function with an array range",         fctn_array_range    },

};

#if(0)
string main_menu_itm[]
{
"First IO Test",
"New Place",
"Use Namespace",
"The Blocks Problem",
//NULL
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

    case USE_NAMESPACE:
        use_namespace();
        break;

    case THE_BLOCKS_PROBLEM:
        the_blocks_problem();
        break;

    default:
        break;
    }
}


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