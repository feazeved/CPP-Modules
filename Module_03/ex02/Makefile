CC = c++

NAME = repetitive

OBJ_DIR = objects

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
