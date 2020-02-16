#if !defined MAIN_MENU_HPP
#define MAIN_MENU_HPP

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
void fctn_ovrd_tmplt( void );

void class_array( void );
void class_rand_walk( void );
void class_conversion( void );
void class_account_abc_main( void );
void class_new_placement_main( void );
void class_bank( void );
void class_ptr_main( void );
void class_template( void );

void student_main( void );
void worker_main( void );

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
    FCTN_OVRD_TMPLT,

    ClASS_ARRAY,
    CLASS_RAND_WALK,
    CLASS_CONVERSION,
    CLASS_ACCOUNT_ABC,
    CLASS_NEW_PLACEMENT,
    CLASS_BANK,
    CLASS_NEW_PTR,
    CLASS_TEMPLATE,

    CODE_OVERLOAD_STUDENT,
    CODE_OVERLOAD_MI,

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
    /*FIRST_IO*/             { "First IO Test",                        myfirst                       },
    /*NEW_PLACE*/            { "New Place",                            newplace                      },
    /*USE_NAMESPACE*/        { "Use Namespace",                        use_namespace                 },
    /*THE_BLOCKS_PROBLEM*/   { "The Blocks Problem",                   the_blocks_problem            },
    /*SMART_POINTERS*/       { "Smart Pointers",                       smrtptrs                      },
    /*FOWL_AUTO_PTR*/        { "Poor choice auto_ptr",                 fowl_auto_ptr                 },
    /*VOCTOR_TEMPLETE*/      { "Vector Templete",                      voctor                        },
    /*LAMBDA*/               { "Lambda",                               lambda                        },
 
    /*FCTN_ARRAY_RANGE*/     { "Function with an array range",         fctn_array_range              },
    /*FCTN_RECURSION*/       { "Function with recursion",              fctn_recursion                },
    /*FCTN_PTR*/             { "Function with pointers",               fctn_ptr                      },
    /*FCTN_STRC_REF*/        { "Function struct reference",            fctn_strc_ref                 },
    /*FCTN_FILE_FUNC*/       { "Function file function",               fctn_file_func                },
    /*FCTN_OVERLOAD_LEFT*/   { "Function overload left",               fctn_overload_left            },
    /*FCTN_OVRD_TMPLT*/      { "Function override template",           fctn_ovrd_tmplt               },

    /*ClASS_ARRAY*/          { "Class array",                          class_array                   },
    /*CLASS_RAND_WALK*/      { "Class rand walk",                      class_rand_walk               },
    /*CLASS_CONVERSION*/     { "Class conversion",                     class_conversion              },
    /*CLASS_ACCOUNT_ABC*/    { "Class account ABC",                    class_account_abc_main        },
    /*CLASS_NEW_PLACEMENT*/  { "Class new placement",                  class_new_placement_main      },
    /*CLASS_BANK*/           { "Class queue for Bank",                 class_bank                    },
    /*CLASS_NEW_PTR*/        { "Class new pointer",                    class_ptr_main                },
    /*CLASS_TEMPLATE*/       { "Class template",                       class_template                },

    /*CODE_OVERLOAD_STUDENT*/{ "Code Overload private",                student_main                  },
    /*CODE_OVERLOAD_MI*/     { "Code Overload MI",                     worker_main                   },

};
#endif