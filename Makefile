# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 11:06:31 by hsabouri          #+#    #+#              #
#    Updated: 2018/04/24 11:04:34 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_scop

LIBDIR=lib

LIBFTDIR=$(LIBDIR)/libft
LIBFTINC=$(LIBFTDIR)/includes

LIBGLFWDIR=$(LIBDIR)/GLFW/src
LIBGLFW=$(LIBDIR)/GLFW
LIBGLFWINC=$(LIBDIR)/GLFW/include

SRCNAM= main.c\
		errors.c\
		callbacks.c\
		init.c\
		parser.c
INCNAM= ft_scop.h\
		parser.h

SRCDIR= sources
INCDIR= includes
OBJDIR= objs

SRC= $(SRCNAM:%=$(SRCDIR)/%)
INC= $(INCNAM:%=$(INCDIR)/%)
OBJ= $(SRCNAM:%.c=$(OBJDIR)/%.o)

CFLAGS = -Wall -Wextra -DNON_COMPLETE
#CFLAGS += -Werror
CFLAGS += -g
CFLAGS += -I$(LIBFTINC) -I$(LIBGLFWINC) -I$(INCDIR)

LDFLAGS += -L$(LIBFTDIR) -lft -L$(LIBGLFWDIR) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

all: libs $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	mkdir -p objs
	$(CC) -o $@ -c $< $(CFLAGS)

libs:
	$(MAKE) -s -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(NAME)

re: fclean all
