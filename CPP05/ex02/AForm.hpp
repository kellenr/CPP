/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:36:53 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 20:40:48 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;

	public:
		//Constructors.
		AForm();
		AForm(const AForm& other);
		AForm(const std::string& name, int signGrade, int execGrade);

		//Destructor
		virtual ~AForm();

		//Operators
		AForm& operator=(const AForm& other);

		//Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		//Methods
		void	beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class AFormException : public std::exception {};

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high!";
				};
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low!";
				};
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form is not signed!";
				};
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif