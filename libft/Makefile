# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 11:40:52 by bshang            #+#    #+#              #
#    Updated: 2020/08/08 12:36:33 by bshang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_substr.c \
			ft_strmapi.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa_base.c \
			ft_putchar.c \
			ft_putstr.c
BONUS_SRC = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = libft.a
INCLUDES = $(NAME:.a=.h)

COMPILE = gcc -c -Wall -Werror -Wextra
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(NAME) compiled"

so:
	@gcc -shared -o libft.so -fPIC $(SRC) $(BONUS_SRC)

%.o:	%c $(INCLUDES)
	@$(COMPILE) $< -o $@

clean:
	@rm -rf *.o
	@echo "Object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re:	fclean all

bonus: $(OBJ) $(BONUS_OBJ) $(INCLUDES)
	@ar -rcs $(NAME) $(BONUS_OBJ) $(OBJ)
