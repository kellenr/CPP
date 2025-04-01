# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kellen <kellen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 10:39:19 by kellen            #+#    #+#              #
#    Updated: 2025/04/01 10:39:20 by kellen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap
CXX = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -g
OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
SRC =	ClapTrap.cpp \
		main.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@-rm $(NAME)

re: clean all
