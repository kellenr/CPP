/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:24:48 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:24:49 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;

    for (int i = 0; i < 4; i++) {
        if (other.templates[i] != NULL)
            this->templates[i] = other.templates[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        // Delete current templates
        for (int i = 0; i < 4; i++) {
            if (this->templates[i] != NULL) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }

        // Deep copy of templates
        for (int i = 0; i < 4; i++) {
            if (other.templates[i] != NULL)
                this->templates[i] = other.templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL) {
            delete this->templates[i];
            this->templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (this->templates[i] == NULL) {
            this->templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }

    std::cout << "MateriaSource cannot learn more materias, memory is full" << std::endl;
    delete m; // If we can't learn it, we must delete it to avoid memory leaks
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type) {
            std::cout << "MateriaSource created " << type << std::endl;
            return this->templates[i]->clone();
        }
    }

    std::cout << "MateriaSource doesn't know materia of type " << type << std::endl;
    return NULL;
}