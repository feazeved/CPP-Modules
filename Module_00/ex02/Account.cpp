#include <iostream>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) :
    _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created\n";
    _nbAccounts += 1;
}

Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created"
              << "\n";
    _nbAccounts += 1;
    _totalAmount += _amount;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed"
              << "\n";
    _nbAccounts -= 1;
    _totalAmount -= _amount;
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm      datetime = *localtime(&t);

    char output[20];

    strftime(output, 20, "[%Y%m%d_%H%M%S] ", &datetime);
    std::cout << output;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals()
              << "\n";
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";";

    _amount += deposit;
    _nbDeposits += 1;

    _totalAmount += deposit;
    _totalNbDeposits += 1;

    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits
              << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "withdrawal:";

    _amount -= withdrawal;
    if (checkAmount())
    {
        _amount += withdrawal;
        std::cout << "refused\n";
        return (false);
    }

    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    _nbWithdrawals += 1;

    std::cout << withdrawal << ";"
              << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals
              << "\n";
    return (true);
}

int		Account::checkAmount(void) const
{
    if (_amount < 0)
        return (1);
    return (0);
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals
              << "\n";
}

int  Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}
