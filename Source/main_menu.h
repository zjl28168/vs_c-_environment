#if !defined MAIN_MENU
#define MAIN_MENU

#define MAIN_MENU_TITLE_LENGHT  50

enum{
    FIRST_IO,

    MENU_CNT
};

char main_menu_itm[MENU_CNT][MAIN_MENU_TITLE_LENGHT]
{
"First IO Test",
};

void myfirst( void );

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