// class_account_abc.hpp -- banck account classes
#ifndef CLASS_ACCOUNT_ABC_HPP
#define CLASS_ACCOUNT_ABC_HPP
#include <iostream>
#include <string>

//Abstract Base Class
class AcctABC
{
private:
    std::string acct_full_name;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        /* data */
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const { return acct_full_name; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore( Formatting & f ) const;
public:
    AcctABC( const std::string & s = "NullBody", long an = -1, double bal = 0.0 );
    void Deposit( double amt );
    virtual void Withdraw( double amt ) = 0;    //pure virtual functions
    double Balance() const { return balance; };
    virtual void ViewAcct() const = 0;          //pure virtual fucntions
    virtual ~AcctABC() {}
};

// Brass Account Class
class Brass : public AcctABC
{
public:
    Brass( const std::string & s = "NullBody", long an = -1, double bal = 0.0 ) : AcctABC( s, an, bal ) {}
    virtual void Withdraw( double amt );
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus( const std::string & s = "NullBody", long an = -1, double bal = 0.0, double ml = 500,
                double r = 0.10 );
    BrassPlus( const Brass & ba, double ml = 500, double r = 0.1 );
    virtual void ViewAcct() const;
    virtual void Withdraw( double amt );
    void ResetMax( double m ) { maxLoan = m; }
    void ResetRate( double r ) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};
#endif