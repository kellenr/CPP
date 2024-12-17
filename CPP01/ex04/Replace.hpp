/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:30:34 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/18 00:04:09 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

class	Replace
{
	public:
		Replace(std::string filename, std::string s1, std::string s2);
		~Replace(void);
		void	replaceInFile(void);

	private:
		std::string	file;
		std::string	sf1;
		std::string	sf2;
		std::ifstream	inputFile;
		std::ofstream	outputFile;
};

#endif
