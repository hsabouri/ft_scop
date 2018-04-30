# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 11:06:31 by hsabouri          #+#    #+#              #
#    Updated: 2018/04/30 14:02:33 by hsabouri         ###   ########.fr        #
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
		parser.c\
		parsing_functions.c\
		verifications.c\
		post_process.c\
		vec_basic.c\
		vec_op.c\
		tools.c\
		axis.c
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
CFLAGS += -D LINUX
LDFLAGS += -lm -ldl -lX11 -lXext -lGL -lpthread
endif
ifeq ($(UNAME_S),Darwin)
CFLAGS += -D OSX
LDFLAGS += -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif

LDFLAGS += -L$(LIBFTDIR) -lft -L$(LIBGLFWDIR) -lglfw3 

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
