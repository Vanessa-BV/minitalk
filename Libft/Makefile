# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vbusekru <vbusekru@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/03 14:15:19 by vbusekru      #+#    #+#                  #
#    Updated: 2024/03/13 18:58:23 by vbusekru      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES_MAND = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstiter.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstmap.c \
			ft_printf.c \
			ft_write_hexa.c \
			ft_write_unsigned_int.c \
			ft_write_various.c \
			ft_strjoin_c.c \

OBJS_MAND = $(SOURCES_MAND:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_MAND)
	$(AR) rcs $(NAME) $(OBJS_MAND)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re