NAME_APP = Dict
INC = inc
SRC = src
BIN = bin
OBJ = obj

SRC_VAR = $(SRC)/open_archive.c \
			$(SRC)/get_word.c \
			$(SRC)/main.c \
			$(SRC)/ft_strcmp.c \
			$(SRC)/ft_strcat.c \
			$(SRC)/ft_strncat.c \
			$(SRC)/ft_putstr.c \
			$(SRC)/ft_putchar.c \
			$(SRC)/print_mean.c
INC_VAR = $(INC)/arquivo.h \
			$(INC)/tools.h

OBJ_VAR = $(SRC_VAR:$(SRC)/%.c=$(OBJ)/%.o)
FLAGS = -Wall -Wextra -Werror -I$(INC) -c
CC = gcc

all: $(NAME_APP)

$(OBJ):

	mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c $(INC_VAR) | $(OBJ)
	$(CC) $(FLAGS) $< -o $@
	@echo "Objectos compilados"

$(NAME_APP): $(OBJ_VAR)
	$(CC) $(OBJ_VAR) -o $(BIN)/$(NAME_APP)
	@echo "Compilação terminada"
	@echo "arquivo binário $(NAME_APP)"

clean:
	rm -vf	$(OBJ_VAR)

fclean: clean
	rm -vf	$(BIN)/$(NAME_APP)

re: fclean all

.PHONY: all clean fclean re run
