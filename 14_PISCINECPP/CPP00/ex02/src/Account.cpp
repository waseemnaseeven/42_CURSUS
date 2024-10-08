/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:05:33 by wnaseeve          #+#    #+#             */
/*   Updated: 2023/07/06 01:55:45 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << initial_deposit
		<< ";created" << std::endl;

	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

// ************************************************************************** //
//                                                                            //
//                             Getters                                        //
//                                                                            //
// ************************************************************************** //

int	Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

// ************************************************************************** //
//                                                                            //
//                             Display                                        //
//                                                                            //
// ************************************************************************** //

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *currentTime = std::localtime(&now);

	char timestamp[20];
	std::strftime(timestamp,sizeof(timestamp), "[%Y%m%d_%H%M%S]", currentTime);

	std::cout << timestamp;
}

void	Account::displayAccountsInfos()
{

	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposit:" << _nbDeposits
		<< ";withdrawal:" << _nbWithdrawals << std::endl;
}

// ************************************************************************** //
//                                                                            //
//                             Actions                                        //
//                                                                            //
// ************************************************************************** //

void	Account::makeDeposit(int deposit)
{

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
		<< ";nb_depostis:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount;

	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount() const
{
	return _amount;
}
