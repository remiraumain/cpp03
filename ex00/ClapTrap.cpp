/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:31:21 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 01:31:14 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : 
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) 
{
	std::cout << "ClapTrap " << _name << " constructed\n";	
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap " << _name << " copy-constructed\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " copy-assigned\n";
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destructed\n";
};

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPoints == 0)
		std::cout << " cannot attack: DEAD\n";
	else if (_energyPoints == 0)
		std::cout << " cannot attack: NO ENERGY\n";
	else
	{
		_energyPoints--;
		std::cout << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPoints == 0)
		std::cout << " cannot be attacked: ALREADY DEAD\n";
	else if (amount < _hitPoints)
	{
		_hitPoints -= amount;
		std::cout << " is attacked, losing " << amount << " health points\n";
	}
	else
	{
		_hitPoints = 0;
		std::cout << " takes a fatal hit... now at 0 health\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPoints == 0)
		std::cout << " cannot be repaired: DEAD\n";
	else if (_energyPoints == 0)
		std::cout << " cannot be repaired: NO ENERGY\n";
	else
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << " repairs itself, regaining " << amount << " health points\n";
	}
}
