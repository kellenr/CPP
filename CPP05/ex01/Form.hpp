/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:26:14 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 19:32:39 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat;

class Form {

	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;

	public:
		//Constructors.
		Form();
		Form(const Form& other);
		Form(const std::string& name, int signGrade, int execGrade);

		//Destructor
		~Form();

		//Operators
		Form& operator=(const Form& other);

		//Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		//Methods
		void	beSigned(const Bureaucrat& b);

		class FormException : public std::exception {};

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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif