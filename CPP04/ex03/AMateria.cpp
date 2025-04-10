/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:05:53 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:23:41 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria constructor called for type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called for type: " << type << std::endl;
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses an unknown materia on " << target.getName() << " *" << std::endl;
}