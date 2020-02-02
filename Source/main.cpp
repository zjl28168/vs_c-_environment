#include <iostream>
#include "main_menu.h"

#define LINE_H  "**************************************"
#define LINE_V  "*\n*\n*\n*\n*"
#define LINE_TAB  "*   "

int main_menu_list( void );

int main()
{
using namespace std;
int select_item;
int i;

select_item = main_menu_list();

cout << endl;
cout << LINE_H << endl;

cout <<"["<< select_item << "."<< menu_table[ select_item ].name << "]"<< " is as follows:" << endl;
cout << endl;

menu_table[select_item].proc();

cin.get();
cin.get();

return 0;
}

int main_menu_list( void )
{
using namespace std;

int i;
int selcet_item;

selcet_item = 0;

cout << LINE_H << endl;
cout << LINE_V << endl;
for( i = FIRST_IO; i < MENU_CNT; i++ )
    {
    cout << LINE_TAB;
    cout << i << ". "<< menu_table[i].name << endl;
    }
cout << LINE_V << endl;
cout << LINE_H << endl;
cout << "Please select a test:";
cin >> selcet_item;

while( cin.get() !='\n' )
{
    continue;
}

return selcet_item;
}