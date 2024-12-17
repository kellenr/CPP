/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:05 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 20:09:41 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_phone_number() const;
		std::string	get_darkest_secret() const;

		void	set_first_name(const std::string &value);
		void	set_last_name(const std::string &value);
		void	set_nickname(const std::string &value);
		void	set_phone_number(const std::string &value);
		void	set_darkest_secret(const std::string &value);

		// Display short contact info (for SEARCH table)
		void displayShort(int index) const;

		// Display full contact details (for SEARCH)
		void displayFull() const;

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
