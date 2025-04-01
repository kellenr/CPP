/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:05 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/23 18:28:09 by kellen           ###   ########.fr       */
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
		void displayShort(int index) const;
		void displayFull() const;

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
