/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:05:27 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:23:47 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter; // Forward declaration

class AMateria {
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const & getType() const; // Returns the materia type
    virtual AMateria* clone() const = 0; // Pure virtual function
    virtual void use(ICharacter& target);
};

#endif