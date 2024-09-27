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

#Directories
SRCDIR := src
INCDIR := inc
OBJDIR := obj
LIBFTDIR := libft

#Libraries
LIBFT := $(LIBFTDIR)/libft.a

#Sources
SRCS := $(addprefix $(SRCDIR)/, main.c)

#Objects
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

#Flags
CC := cc
CFLAGS :=  -g -I$(INCDIR) -I$(LIBFTDIR)
LDFLAGS := -L$(LIBFTDIR)

all: $(NAME)

$(NAME): $(HEADERS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT): $(LIBFTHEADERS)
	$(MAKE) -C $(LIBFTDIR)


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re