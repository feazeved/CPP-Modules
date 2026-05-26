NAME	=	megaphone

CC	=	c++

CFLAGS = -Wall -Werror -Wextra -std=c++98


SRC_DIR	=	.
OBJ_DIR	=	objects

SRCS = megaphone.cpp

OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)


$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
