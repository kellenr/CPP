/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:58:44 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 20:20:04 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class Form;

class Bureaucrat {

	private:
		const std::string	name;
		int					grade;

	public:
		//Constructors.
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& name, int grade);

		//Destructor
		~Bureaucrat();

		//Operators
		Bureaucrat& operator=(const Bureaucrat& other);

		//Getters
		std::string	getName() const;
		int			getGrade() const;

		//Methods
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form& f);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif