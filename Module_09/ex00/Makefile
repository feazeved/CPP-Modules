CC = c++

NAME = btc

OBJ_DIR = objects

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	make re
	clear
	./$(NAME) input.txt

vrun:
	make re
	clear
	valgrind ./$(NAME) input.txt

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run vrun
