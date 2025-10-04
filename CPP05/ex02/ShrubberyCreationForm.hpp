/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:44:43 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 20:47:15 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;

	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(const std::string& target);

		// Destructor
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		// Methods
		void execute(Bureaucrat const & executor) const;

};

#endif