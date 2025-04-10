/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:24:41 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:24:42 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    std::cout << "---- Creating MateriaSource ----" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n---- Creating characters ----" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << "\n---- Creating and equipping materias ----" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n---- Testing use function ----" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n---- Testing unequip function ----" << std::endl;
    me->unequip(0);
    me->unequip(1);

    // Test using unequipped slots
    std::cout << "\n---- Testing using unequipped slots ----" << std::endl;
    me->use(0, *bob); // Should show a message about empty slot

    // Test deep copy of Character
    std::cout << "\n---- Testing Character deep copy ----" << std::endl;
    Character* originalChar = new Character("original");
    tmp = src->createMateria("ice");
    originalChar->equip(tmp);

    Character* copyChar = new Character(*originalChar);

    std::cout << "\nOriginal character using materia:" << std::endl;
    originalChar->use(0, *bob);

    std::cout << "\nCopy character using materia:" << std::endl;
    copyChar->use(0, *bob);

    // Test unknown materia type
    std::cout << "\n---- Testing unknown materia type ----" << std::endl;
    tmp = src->createMateria("unknown"); // Should return NULL
    if (tmp == NULL)
        std::cout << "Successfully handled unknown materia type" << std::endl;

    // Clean up
    std::cout << "\n---- Cleaning up ----" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete originalChar;
    delete copyChar;

    return 0;
}