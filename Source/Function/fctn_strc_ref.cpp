// fctn_strc_ref.cpp -- Using structure references
#include <iostream>
#include <string>
struct free_throws
{
    /* data */
    std::string name;
    int made;
    int attempts;
    float percent;
};

static void display( const free_throws & ft );
static void set_pc( free_throws & ft );
static free_throws & accumulate( free_throws & target, const free_throws & source );

void fctn_strc_ref()
{
    // partial initialization - remaining members set to 0
    free_throws one   = { "One", 13, 14 };
    free_throws two   = { "Two", 10, 16 };
    free_throws three = { "Three", 7, 9 };
    free_throws four  = { "Four", 5, 9 };
    free_throws five  = { "Five", 6, 14 };
    free_throws team  = { "Team", 0, 0 };
    // No initialization
    free_throws dup;

    set_pc( one );
    display( one );
    accumulate( team, one );
    display( team );

    // Using return value as argument
    display( accumulate( team, two ) );
    accumulate( accumulate( team, three ), four );
    display( team );

    // Using return value in assignment
    dup = accumulate( team, five );
    std::cout << "Displaying team:\n";
    display( team );
    std::cout << "Displaying dup after assignment:\n";
    display( dup );
    set_pc( four );
    // ill-advised assignment
    accumulate( dup, five ) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display( dup );
}

static void display( const free_throws & ft )
{
    using std::cout;
    using std::endl;

    cout << "Name: " << ft.name << endl;
    cout << "Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << endl << endl;
}

static void set_pc( free_throws & ft )
{
    if( ft.attempts != 0 )
    {
        ft.percent = 100.0f * float( ft.made ) / float( ft.attempts );
    }
    else
    {
        ft.percent = 0;
    }
}

static free_throws & accumulate( free_throws & target, const free_throws & source )
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc( target );
    return target;
}