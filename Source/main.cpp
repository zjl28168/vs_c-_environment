#include <iostream>
#include "main_menu.h"

#define LINE_H  "**************************************"
#define LINE_V  "*\n*\n*\n*\n*"
#define LINE_TAB  "*\t"

int main_menu_list( void );

int main()
{
using namespace std;
int select_item;
int i;

select_item = main_menu_list();

cout << "\nYou select " << select_item;

for( i = 0; i < MENU_CNT; i++ )
    {
    if( i == select_item )
        {
        test_table[i].proc();
        }
    }

cin.get();
cin.get();
}

int main_menu_list( void )
{
using namespace std;

int i;
int selcet_item;

selcet_item = 0;

cout << LINE_H << endl;
cout << LINE_V << endl;
for( i =0; i < MENU_CNT; i++ )
    {
    cout << LINE_TAB;
    cout << i << ".\t"<< main_menu_itm[i] << endl;
    }
cout << LINE_V << endl;
cout << LINE_H << endl;
cout << "Please a test:";
cin >> selcet_item;

return selcet_item;
}