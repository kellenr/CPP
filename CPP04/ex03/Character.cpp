/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:24:17 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:24:18 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name), floorCount(0) {
    std::cout << "Character constructor called for " << name << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    for (int i = 0; i < 10; i++)
        this->floor[i] = NULL;
}

Character::Character(const Character &other) : name(other.name), floorCount(0) {
    std::cout << "Character copy constructor called" << std::endl;

    // Initialize inventory to NULL
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;

    // Deep copy of inventory
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i] != NULL)
            this->inventory[i] = other.inventory[i]->clone();
    }

    // Initialize floor to NULL
    for (int i = 0; i < 10; i++)
        this->floor[i] = NULL;
}

Character &Character::operator=(const Character &other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;

        // Delete current inventory
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }

        // Deep copy of inventory
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL)
                this->inventory[i] = other.inventory[i]->clone();
        }

        // Clean up floor
        for (int i = 0; i < 10; i++) {
            if (this->floor[i] != NULL) {
                delete this->floor[i];
                this->floor[i] = NULL;
            }
        }
        this->floorCount = 0;
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called for " << this->name << std::endl;

    // Clean up inventory
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }

    // Clean up floor
    for (int i = 0; i < 10; i++) {
        if (this->floor[i] != NULL) {
            delete this->floor[i];
            this->floor[i] = NULL;
        }
    }
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            std::cout << this->name << " equipped " << m->getType() << " to slot " << i << std::endl;
            return;
        }
    }

    std::cout << this->name << " has no empty inventory slots" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory index " << idx << std::endl;
        return;
    }

    if (this->inventory[idx] == NULL) {
        std::cout << "No materia in slot " << idx << " to unequip" << std::endl;
        return;
    }

    // Store materia on the floor to avoid memory leaks
    if (floorCount < 10) {
        this->floor[floorCount++] = this->inventory[idx];
        std::cout << this->name << " dropped " << this->inventory[idx]->getType() << " from slot " << idx << " on the floor" << std::endl;
        this->inventory[idx] = NULL;
    } else {
        std::cout << "The floor is full of materias, cannot unequip more" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory index " << idx << std::endl;
        return;
    }

    if (this->inventory[idx] == NULL) {
        std::cout << "No materia in slot " << idx << " to use" << std::endl;
        return;
    }

    this->inventory[idx]->use(target);
}