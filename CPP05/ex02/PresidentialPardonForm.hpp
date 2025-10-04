/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:05:10 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 21:05:33 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string target;

	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm(const std::string& target);

		// Destructor
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		// Methods
		void execute(Bureaucrat const & executor) const;

};

#endif