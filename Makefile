OBJ_DIR = obj

CLIENT_OBJ = $(addprefix $(OBJ_DIR)/,$(CLIENT_SRC:.c=.o))
SERVER_OBJ = $(addprefix $(OBJ_DIR)/,$(SERVER_SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT = client
SERVER = server

CLIENT_SRC = client.c
SERVER_SRC = server.c

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft
	@echo "Code by: Kyoshi Lima ^-^ "



$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c includes/minitalk.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -s -c $< -o $@


clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@rmdir --ignore-fail-on-non-empty $(OBJ_DIR) 2>/dev/null || true


fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
