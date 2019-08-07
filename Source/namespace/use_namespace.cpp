// use_namespace -- using namespace
#include <iostream>
#include "namesp.h"
void other( void );
void another( void );

int use_namespace( void )
{
    using debts::Debt;
    using std::cin;

    using debts::showDebt;
    Debt golf = {{"Benny","Goatsniff"}, 120.0 };
    showDebt(golf);
    other();
    another();
    cin.get();
    cin.get();
    return 0;
}

void other( void )
{
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = { "Doodles","Glister" };
    cout << "Person dg is following:" << endl; 
    showPerson( dg );
    cout << endl;
    Debt zippy[3];
    int i;
    for( i = 0; i < 3; i++ )
    {
        cout << "Input " << i << " Debt:" << endl;
        getDebt( zippy[i] );
    }

    for( i = 0; i < 3; i++ )
    {
        showDebt( zippy[i] );
    }
    cout << "Total debt: $" << sumDebts( zippy, 3 ) << endl;
    return;
}

void another( void )
{
    using pers::Person;
    Person collector = { "Milo", "Rightshift" };
    cout << "The collector is ";
    pers::showPerson( collector );
    std::cout << std::endl;
}
/*main 函数首先使用了2个using声明：
using debts::Debt;  makes the Debt structure definition avaliable 
using debts::showDebt;  makes the showDbts function avaliable
注意，using声明只使用了名称，例如：第二个using声明没有描述showDbts的返回类型或函数的特征标，而只给出了名称；
因此，如果函数被重载，则一个using声明将导入所有的版本。另外，虽然，虽然Debt和showDebt都使用了Person类型，但
不必导入任何Person名称，因为debt名称空间有一条包含pers名称空间的using编译指令。
接下来，other（）函数使用了一种不太友好的方法，即使用一条using编译指令导入整个名称空间。
 */