# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 11:06:31 by hsabouri          #+#    #+#              #
#    Updated: 2018/05/04 09:25:19 by hsabouri         ###   ########.fr        #
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
		init2.c\
		parser.c\
		parsing_functions.c\
		verifications.c\
		post_process.c\
		post_process2.c\
		vec_basic.c\
		vec_op.c\
		mat_op.c\
		tools.c\
		colors.c\
		axis.c\
		display.c
INCNAM= ft_scop.h\
		parser.h\
		types.h\
		vec.h

SRCDIR= sources
INCDIR= includes
OBJDIR= objs

SRC= $(SRCNAM:%=$(SRCDIR)/%)
INC= $(INCNAM:%=$(INCDIR)/%)
OBJ= $(SRCNAM:%.c=$(OBJDIR)/%.o)

CFLAGS = -Wall -Wextra -DNON_COMPLETE
CC = clang
#CFLAGS += -Werror
CFLAGS += -g
CFLAGS += -I$(LIBFTINC) -I$(LIBGLFWINC) -I$(INCDIR)


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
CFLAGS += -D LINUX `pkg-config --cflags glfw3` -Ilib/GLFW/deps/ -Ilib/GLFW/include/ 
LDFLAGS += -LGLFW/src `pkg-config --static --libs glfw3` -Ilib/GLFW/deps/ 
SPECIAL = lib/GLFW/deps/glad.c
endif
ifeq ($(UNAME_S),Darwin)
CFLAGS += -D OSX
LDFLAGS += -lgflw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
SPECIAL = 
endif

LDFLAGS += -L$(LIBFTDIR) -lft -L$(LIBGLFWDIR)

all: libs $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(SPECIAL) $(LDFLAGS)

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
