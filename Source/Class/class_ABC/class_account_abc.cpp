// class_account_abc.cpp -- bank account class methods
#include <iostream>
#include "class_account_abc.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
using std::string;

//Abstract Bass Class
AcctABC::AcctABC( const std::string & s, long an, double bal )
{
    acct_full_name = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit( double amt )
{
    if( amt < 0 )
    {
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    }
    else
    {
        acctNum = amt;
    }
}

void AcctABC::Withdraw( double amt )    //pure virtual functions
{
    balance -= amt;
}


// virtual void AcctABC::ViewAcct()          //pure virtual fucntions
// {
// }

// protected methods for fomartting
AcctABC::Formatting AcctABC::SetFormat() const
{
    // set up ###.### format
    Formatting f;
    f.flag = cout.setf( ios_base::fixed, ios_base::floatfield );
    f.pr = cout.precision( 2 );
    return f;
}

void AcctABC::Restore( Formatting & f ) const
{
    cout.setf( f.flag, ios_base::floatfield );
    cout.precision( f.pr );
}

// Brass methods
void Brass::Withdraw( double amt )
{
    if( amt < 0 )
    {
        cout << "Withdrawal must be positive; withdrawal canceled.\n";
    }
    else if( amt <= Balance() )
    {
        AcctABC::Withdraw( amt );
    }
    else
    {
        cout << "Withdrawal amout of $" << amt <<" exceeds your balance.\n";
        cout << "Withdraw canceled.\n";
    }
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore( f );
}
    double maxLoan;
    double rate;
    double owesBank;

// BrassPlus Methods
BrassPlus::BrassPlus( const std::string & s, long an, double bal, double ml, double r )
          : AcctABC( s, an, bal ),
            maxLoan( ml ),
            rate( r ),
            owesBank( 0.0 )
{
}

BrassPlus::BrassPlus( const Brass & ba, double ml, double r )
                  : AcctABC( ba ),
                    maxLoan( ml ),
                    rate( r ),
                    owesBank( 0.0 )
{
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maxinum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision( 3 );
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore( f );
}

void BrassPlus::Withdraw( double amt )
{
    Formatting f = SetFormat();

    double bal = Balance();
    if( amt <= bal )
    {
        AcctABC::Withdraw( amt );
    }
    else if( amt <= bal + maxLoan - owesBank )
    {
        double advance = amt - bal;
        owesBank += advance * ( 1.0 + rate );
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        AcctABC::Withdraw( amt );
        Deposit( advance );     // Avoid negative desposite
        AcctABC::Withdraw( amt );
    }
    else
    {
        cout << "Credit limit exceeded. Translation cancelled.\n";
    }
    Restore( f );
}
