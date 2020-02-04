// fctn_file_func.cpp 8.8-- function with ostream & parameter
//要求用户输入望远镜物镜和一些目镜的焦距，然后计算并显示每个目镜的放大倍数。放大倍数等于物镜的焦距除以目镜的焦距。并将数据写入文件和显示到屏幕上。
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it( ostream & os, double fo, const double fe[], int n );
const int LIMIT = 5;

void fctn_file_func()
{
    ofstream fout;
    const char *fn  = "ep-data.txt";
    fout.open( fn );
    if( !fout.is_open() )
    {
        cout <<"Can't open " << fn << ". Bye" << endl;
        exit( EXIT_FAILURE );
    }

    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
    for( int i = 0; i < LIMIT; i++ )
    {
        cout << "Eyepieces #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it( fout, objective, eps, LIMIT );    // Write the data to file ep-data.txt.
    file_it( cout, objective, eps, LIMIT );    // Display the data on the screen.
    cout << "Done\n";
}

void file_it( ostream & os, double fo, const double fe[], int n )
{
    ios_base::fmtflags initial;
    initial = os.setf( ios_base::fixed ); // save initial formating state。将对象置于使用定点表示法的模式，提示返回调用它之前有效的所有设置
    os.precision( 0 );
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf( ios::showpoint );    //将对象置于小数点的模式
    os.precision( 1 );    //指定显示多少位小数，这个设置保持不变，指导再次调用相应的方法重新设置
    os.width( 12 );    //设置下一次输出操作使用的字段宽度，只在显示下一个值时有效，然后将恢复到默认设置
    os << "f.1. eyeiece";
    os.width( 15 );
    os << "magnification" << endl;
    for( int i = 0; i < n; i++ )
    {
        os.width( 12 );
        os << fe[i];
        os.width( 15 );
        os << int( fo /fe[i] + 0.5 ) << endl;
    }
    os.setf( initial ); // restore initial formating state
    //参数os（类型为 ostream &）可以指向ostream对象（cout），也可以指向ofstream对象（fcout）。
}