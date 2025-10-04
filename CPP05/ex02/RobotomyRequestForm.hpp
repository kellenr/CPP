/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:04:06 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 21:04:47 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		std::string target;

	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string& target);

		// Destructor
		~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		// Methods
		void execute(Bureaucrat const & executor) const;

};

#endif
