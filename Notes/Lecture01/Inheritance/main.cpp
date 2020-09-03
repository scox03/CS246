#include <iostream>
#include <string>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "CD.h"
using namespace cw1;

int main()
{
    Account acc;
    Checking acc2(500);
    Savings acc3;
    CD acc4(10000.00);

    std::cout << "Account Run\n";
    std::cout << acc << "\n";
    acc.Deposit(700.00);
    std::cout << acc << "\n";
    acc.Withdraw(800.50);
    std::cout << acc << "\n";

    std::cout << "\nChecking Run\n";
    std::cout << acc2 << "\n";
    acc2.Deposit(700.00);
    std::cout << acc2 << "\n";
    acc2.Withdraw(800.50);
    std::cout << acc2 << "\n";

    std::cout << "\nSavings Run\n";
    std::cout << acc3 << "\n";
    acc3.Deposit(700.00);
    std::cout << acc3 << "\n";
    acc3.Withdraw(800.50);
    std::cout << acc3 << "\n";

    std::cout << "\nCD Run\n";
    std::cout << acc4 << "\n";
    //If you remove the comment symbols 
    //you will receive an error
    //acc4.Deposit(700.00);
    std::cout << acc4 << "\n";
    //acc4.Withdraw(800.50);
    std::cout << acc4 << "\n";

    std::cout << "CD Copy\n";
    CD acc5 = acc4;
    std::cout << acc5 << "\n";

    return 0;
}