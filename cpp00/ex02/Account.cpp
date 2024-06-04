/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 11:28:02 by jovieira      #+#    #+#                 */
/*   Updated: 2024/06/04 15:29:37 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Init static vars
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// static member functions
int	Account::getNbAccounts() { return(_nbAccounts); }

int	Account::getTotalAmount() { return(_totalAmount); }

int	Account::getNbDeposits() { return(_totalNbDeposits); }

int	Account::getNbWithdrawals() { return(_totalNbWithdrawals); }

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

// Constructor and deconstructor
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(_totalNbDeposits), _nbWithdrawals(_totalNbWithdrawals)
{
	_nbAccounts++;
	_totalAmount +=_amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << "\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	updateAmount;

	updateAmount = _amount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << updateAmount << ";nb_deposits:" << _nbDeposits << "\n";
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	updateAmount;

	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << "\n";
		return false;
	}
	_nbWithdrawals++;
	updateAmount = _amount - withdrawal;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << updateAmount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return true;
}

int Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp()
{
	std::time_t result = std::time(nullptr);
    std::tm * timeinfo = std::localtime(&result);

    char buffer[80];
    std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);

    std::cout << buffer << " ";
}