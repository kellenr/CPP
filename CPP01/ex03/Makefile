# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 16:44:39 by keramos-          #+#    #+#              #
#    Updated: 2024/12/17 23:15:26 by keramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

# **************************************************************************** #
#                                 SOURCES                                      #
# **************************************************************************** #

SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJS = $(SRCS:.cpp=.o)

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                clean RULES                                   #
# **************************************************************************** #

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
