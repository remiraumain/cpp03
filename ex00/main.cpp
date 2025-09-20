/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:43:47 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 01:16:56 by rraumain         ###   ########.fr       */
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
	// Energie à 0 -> devrait échouer
	a.attack("dummy (should fail)");

	b.takeDamage(200);          // HP <= 0
	b.beRepaired(5);            // devrait échouer (0 HP)
	b.attack("someone");        // devrait échouer (0 HP)

	ClapTrap c(a);              // copie de Alpha (energie déjà épuisée)
	ClapTrap d("Delta");
	d = b;                      // assignation de Bravo (0 HP)

	c.attack("target (copy of Alpha)"); // échoue: énergie 0 si votre copie est correcte
	d.beRepaired(1);                     // échoue: HP 0 si votre assignation est correcte

	ClapTrap e("Echo");
	e.takeDamage(5);
	e.beRepaired(5);           // devrait réussir (énergie -1, HP +5)

	return 0;
}
