/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:11 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 20:11:35 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		void	search_contact(void);
		void	display_info(void);
		void	display_phonebook(PhoneBook &phoneBook);

	private:
		Contact	contacts[8];
		int		index;
		int		total;
};

#endif
