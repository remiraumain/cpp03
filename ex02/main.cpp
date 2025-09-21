/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:18:31 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 08:27:34 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		FragTrap f("Fraggy");
		f.attack("Training Dummy");
		f.highFivesGuys();
	}

	{
		FragTrap a("Alpha");
		FragTrap b(a);
		b.attack("CopyTarget");
		b.highFivesGuys();
	}

	{
		FragTrap src("Source");
		FragTrap dst("Dest");
		dst = src;
		dst.highFivesGuys();
	}

	ClapTrap* p = new FragTrap("S");
	p->attack("X");
	delete (p);

	return 0;
}

