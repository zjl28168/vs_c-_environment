#include <iostream>
#include "main_menu.hpp"

#define LINE_H  "**************************************"
#define LINE_V  "*\n*\n*\n*\n*"
#define LINE_TAB  "*   "

#define INVALID_INT  0xffff

int main_menu_list( void );

int main()
{
using namespace std;
int select_item;
int i;

while( ( select_item = main_menu_list() ) && ( INVALID_INT != select_item ) )
{
    cout << endl;
    cout << LINE_H << endl;

    cout <<"["<< select_item << "."<< menu_table[ select_item ].name << "]"<< " is as follows:" << endl;
    cout << endl;

    menu_table[select_item].proc();
    cout << endl;
    cin.get();
    cin.get();
}

cout << "Bye!\n";
cin.get();
cin.get();

return 0;
}

int main_menu_list( void )
{
using std::cout;
using std::cin;

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
cout << "Please select a test ( q to quit ):";

if( cin >> selcet_item )
{
    while( cin.get() !='\n' )
    {
        continue;
    }
}
else
{
    selcet_item = INVALID_INT;
}

return selcet_item;
}