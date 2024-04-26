NAME1 = client
NAME2 = server

LIBFT = Libft/libft.a

LIBFTDIR = Libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SOURCE1 =	client.c
SOURCE2 =	server.c

OBJECTS1 = $(SOURCE1:%.c=$(OBJS_DIR)/%.o)
OBJECTS2 = $(SOURCE2:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

all: $(NAME1) $(NAME2)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME1): $(LIBFT) $(OBJECTS1)
	$(CC) $(CFLAGS) $(OBJECTS1) $(LIBFT) -o $(NAME1)

$(NAME2): $(LIBFT) $(OBJECTS2)
	$(CC) $(CFLAGS) $(OBJECTS2) $(LIBFT) -o $(NAME2)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR) 
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re