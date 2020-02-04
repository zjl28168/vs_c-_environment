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
void fctn_recursion( void );
void fctn_ptr( void );
void fctn_strc_ref( void );
void fctn_file_func( void );
void fctn_overload_left( void );

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
    FCTN_RECURSION,
    FCTN_PTR,
    FCTN_STRC_REF,
    FCTN_FILE_FUNC,
    FCTN_OVERLOAD_LEFT,

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
    /*FCTN_RECURSION*/       { "Function with recursion",              fctn_recursion      },
    /*FCTN_PTR*/             { "Function with pointers",               fctn_ptr            },
    /*FCTN_STRC_REF*/        { "Function struct reference",            fctn_strc_ref       },
    /*FCTN_FILE_FUNC*/       { "Function file function",               fctn_file_func      },
    /*FCTN_OVERLOAD_LEFT*/   { "Function overload left",               fctn_overload_left  },

};
#endif