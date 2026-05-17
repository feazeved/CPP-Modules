CC = c++

NAME = myphonebook

SRC_DIR = source
OBJ_DIR = objects
INC_DIR = includes

SRC = Contact.cpp PhoneBook.cpp main.cpp utils.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
