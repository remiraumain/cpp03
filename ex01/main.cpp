/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:18:31 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 08:20:06 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		ScavTrap s("Serena");
		s.attack("Training Dummy");
		s.guardGate();
	}

	{
		ScavTrap a("Alpha");
		ScavTrap b(a);
		b.attack("CopyTarget");
	}
	
	{
		ScavTrap x("Source");
		ScavTrap y("Dest");
		y = x;
		y.guardGate();
	}

	ClapTrap* p = new ScavTrap("S");
	p->attack("X");
	delete (p);  

	return (0);
}
