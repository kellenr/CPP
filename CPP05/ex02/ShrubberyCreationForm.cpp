/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:47:18 by kellen            #+#    #+#             */
/*   Updated: 2025/10/05 00:55:55 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	std::ofstream ofs((target + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw std::runtime_error("Failed to open file");

	ofs << "                                     %                    &%&                                                     \n"
		"                                    &#%@@ &@&  %%       @%%&&#&&#                                                 \n"
		"                               &%% #&&@%##%@&@@@@&@&     %@@#@:@#&#@#%                                            \n"
		"                     %%  #&%#@#&&###%##@#\\@&#@@###%@&&&##   %%&&&%%#@@%%                                          \n"
		"                      ##%#@#%&##%%% @&:&&%#%&%&#%@&@@@&#   && ~&&#%##%@#@&                                        \n"
		"                    ##@%%@&&&&@@%&%#@&% @_%&##&@%@%%#&@&@&      %&&#~&%%& &                                       \n"
		"           &#%#%&@%%#%#@##&@&@##%&@@%@#@::@@ ##@|%#%~@#@%@     #&%&%###%#&@                                       \n"
		"    & #@@@#@%%&#|%@#@@%@%@@&@&&%@&%&%#@# %|~:  |~_=& @&#        ~_:|@%%&#&%                                       \n"
		"     &@%@@&@&%%%&@&&%@&&&%#%#%&&&%@@#  %    : ;_ @& %@@#&#&    __%&%@|_%&#@&                                      \n"
		"  %### @####%&@%@@@%#|%#__=@&&##%&&#         |     #|&@#@    _|    %&@#%&@@#                                      \n"
		"   %   |#&@#%#\\@@%@#@&&&% @@@@&#_&\\@#&&%_==== ;     @  #&__::\\    @&&##@#&%@                             %&       \n"
		"        @~___@\\&#%@@## |\\# %__~@&%% #       :|=_      %_&    \\|:~_##:%%@ #@                        %%@%@  #       \n"
		"             \\%@&%&  #    /|   @@ #& %#         _;=  ~      %#\\__@#%@@#@&                            @&&@%#@ %    \n"
		"              |&  #       |:  #    @@            ||  |   @%&%@@&&@@&# #  &%                         & #@#@#%@%&   \n"
		"                _\\____:__\\\\|                      :||    @#%%%#&@#@%#@@&@  &                         & |#@&&%@#@  \n"
		"                           :|\\        ~_____;_=   |:   #&  &|  %     &@  @                             @@#%&%@%%  \n"
		"                              :\\~:____=_____=__\\\\ =|       & #         @                              |#%^^#@@% @ \n"
		"                                _~_:_=         ~:\\ :=      &                            /___:|=___:_=\\_ %@@&%#%@  \n"
		"                                                 \\\\|=                                 //      ~  _    \\#&&%##%&## \n"
		"                                                   ||\\                            _///        /|      #|#@#  @    \n"
		"                                                     \\=\\                =_____;___:  @%%%&@@#/| _~@@##%&@#&% #&   \n"
		"                                                       ;:\\          _:_____\\:\\_~__     #&@%@%#|   \\_@@&%\\%#&%%    \n"
		"                                                        |\\\\\\      //____     @\\\\\\    ## &&###@#%&%&@@#%@#&@ %     \n"
		"                                                        ||=|    ///  &@      %   :\\:@   %@%#@%%&%&#|%#@&@& @%     \n"
		"                                                        ;||;  ///   %@@%\\@@&&&%#@  |          @& # |   #@   #     \n"
		"                                                        |||; ://     %@=&&@_## %@%  /     @#&%@@%%#               \n"
		"                                                       |||:://         @@ %#@\\__;_~/=   %&%@%=&@&&                \n"
		"                                                       ||///            # %%   |;   \\    @#&@|%#%#@&#             \n"
		"                                                       /~/:             &#&#   /     \\|    %#%%%## %%             \n"
		"                                                       |;|=             %%@&%%#=@&    /;__=__%   %#               \n"
		"                                                      ||||             &%%%@\\&&&#%@@%#\\   %@& ~ @&#%              \n"
		"                                                      ;~~|              #&&@%#&&#@=&_  \\:   &#%:##%%%             \n"
		"                                                      ~|||              % #%  &#\\%&%&%& /  %  @&#&@               \n"
		"                                                      ||||             &  #  && #&%##@@@#%#@@ & # %               \n"
		"                                      \\____________./|;|:\\._____________/    & & @  & % &#&                       \n"
		"                                       \\   .               *  ..~      /         @   &   @ &                      \n"
		"                                        \\_____________________________/                                           \n"
		"                                          -                         -                                             \n";
	ofs.close();
}