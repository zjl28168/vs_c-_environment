/*从左到右有n个木块，编号为0~n-1，要求模拟以下4种操作（下面的a和b都是木块编号）
1.move a noto b：把a和b上方的木块全部归位，然后把a摞在b上面；
2.move a over b：把a上方的木块全部归位，然后把a放在b所在的木块堆的顶部；
3.pile a onto b：把b上方的木块全部归位，然后把a及上面的木块整体摞在b上面；
4.pile a over b：把a及上面的木块整体摞在b所在木块堆的顶部。
遇到quit时终止一组数据。a和b在同一堆的指令是非法指令，应当忽略。所有操作结束后，输出每个位置的木块列表，按照从底部到顶部的顺序排列。
分析：每个木块堆的高度不确定，所以用vector老保存会很适合；儿木块堆的个数不超过n，所以用一个数组来存储就可以了。
 */
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn]; //每个pile[i]是一个vector

//找木块a所在的pile和height，以引用的形式返回调用者
void find_block( int a, int& p, int& h )
{
for( p = 0; p < n; p++ )
    {
    for( h = 0; h < pile[p].size(); h++ )
        {
        if( pile[p][h] == a )
            {
            return;
            }
        }
    }
}

//把p堆高度为h的木块上方的所有木块移回原位
void clear_above( int p, int h )
{
for( int i = h + 1; i < pile[p].size(); i++ )
    {
    int b = pile[p][i];
    pile[b].push_back(b);
    }
pile[p].resize( h + 1 );
}

//把p堆高度为h及其上方的木块整体移动到p2堆的顶部
void pile_onto( int p, int h, int p2 )
{
int i;
for( i = h; i < pile[p].size(); i++ )
    {
    pile[p2].push_back( pile[p][i] );
    }
pile[p].resize(h);
}

void print()
{
int i, j;
for( i = 0; i < n; i++ )
    {
    cout << "Place-" << i << ": ";
    for( j = 0; j < pile[i].size(); j++ )
        {
        cout << pile[i][j] << "#Block\t";
        }
    cout << endl;
    }
}

void the_blocks_problem()
{
int a, b, i;
cout << "Input the sum number of blocks:" << endl;
cin >> n;
cout << "There are " << n << " blocks." << endl;
string s1, s2;
for( i = 0; i < n; i++ )
    {
    pile[i].push_back( i );
    }
while( cin >> s1 >> a >> s2 >> b )
    {
    int pa, pb, ha, hb;
    find_block( a, pa, ha );
    find_block( b, pb, hb );
    if( pa == pb )
        {
        continue;
        }
    
    if( s2 == "onto" )
        {
        clear_above( pb, hb );
        }
    
    if( s1 == "move" )
        {
        clear_above( pa, ha );
        }
    pile_onto( pa, ha, pb );
    }
    //增加了两行
    cin.clear();
    cin.sync();   //或者用cin.ignore();
    print();
    
    cin.get();
    cin.get();
}