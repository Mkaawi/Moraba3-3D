# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 16:48:52 by abdennac          #+#    #+#              #
#    Updated: 2025/03/09 01:30:55 by abdennac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= moraba3
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	= /Users/$(USER)/MLX42

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= 	main.c \
			parsing/parsing.c \
			parsing/parse_map.c \
			parsing/fill_map.c \
			parsing/utils.c   \
			get_next_line/get_next_line.c \
			libft/ft_atoi.c libft/ft_bzero.c			\
			libft/ft_isalnum.c libft/ft_isalpha.c		\
			libft/ft_isascii.c libft/ft_isdigit.c		\
			libft/ft_isprint.c libft/ft_memcmp.c		\
			libft/ft_memcpy.c	libft/ft_memset.c		\
			libft/ft_putchar_fd.c libft/ft_putstr_fd.c 	\
			libft/ft_strdup.c	libft/ft_strjoin.c		\
			libft/ft_strlen.c	libft/ft_strncmp.c		\
			libft/ft_strlcpy.c libft/ft_tolower.c		\
			libft/ft_toupper.c libft/ft_memmove.c		\
			libft/ft_strchr.c	libft/ft_strrchr.c		\
			libft/ft_putnbr_fd.c libft/ft_strnstr.c		\
			libft/ft_calloc.c libft/ft_memchr.c			\
			libft/ft_itoa.c libft/ft_strlcat.c			\
			libft/ft_putendl_fd.c libft/ft_substr.c		\
			libft/ft_strtrim.c libft/ft_split.c 		\
			libft/ft_striteri.c libft/ft_strmapi.c		\
			libft/ft_lstmap.c				\
			libft/ft_lstsize_bonus.c		\
			libft/ft_lstnew_bonus.c			\
			libft/ft_lstadd_back_bonus.c	\
			libft/ft_lstadd_front_bonus.c	\
			libft/ft_lstlast_bonus.c		\
			libft/ft_lstdelone_bonus.c 		\
			libft/ft_lstclear_bonus.c		\
			libft/ft_lstiter_bonus.c
			
OBJS	= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c cube.h parsing/parsing.h
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx