# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommehdiz <ommehdiz@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 14:31:22 by ommehdiz          #+#    #+#              #
#    Updated: 2024/09/27 16:55:07 by ommehdiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# CFLAGS = -Wall -Wextra -Werror -O3
CFLAGS = -Wall -Wextra -Werror -g -Og

LIBFTDIR = libft

SRCS = \
	src/init_targets.c\
	src/main.c\
	src/sort.c\
	src/sort_five.c\
	src/sort_utils.c\
	src/ops/push.c\
	src/ops/reverse_rotate.c\
	src/ops/rotate.c\
	src/ops/swap.c\
	src/atoi_checked.c\
	src/stack_parse.c\
	src/location.c\
	src/chunk.c\
	src/min_max_ranged.c\
	src/min_max.c\

OBJ = $(SRCS:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c -I$(LIBFTDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	# CFLAGS='$(CFLAGS)'
	cc $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -o $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
