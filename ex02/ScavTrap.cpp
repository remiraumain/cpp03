/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:10:08 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 07:59:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed\n";	
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << _name << " copy-constructed\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		std::string	destName = _name;
		ClapTrap::operator=(copy);
		std::cout << "ScavTrap " << destName << " copy-assigned from " << copy._name << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destructed\n";
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << _name;
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl;
}
