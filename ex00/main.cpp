/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:43:47 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 01:36:03 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"


int main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");

	a.attack("training dummy");
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 10; ++i)
		a.attack("dummy");
	a.attack("dummy (should fail)");

	b.takeDamage(200);
	b.beRepaired(5);
	b.attack("someone");

	ClapTrap c(a);
	ClapTrap d("Delta");
	d = b;

	c.attack("target (copy of Alpha)");
	d.beRepaired(1);

	ClapTrap e("Echo");
	e.takeDamage(5);
	e.beRepaired(5);

	return 0;
}
