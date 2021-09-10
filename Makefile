
CC = gcc -Wall -Wextra -Werror -o push_swap

CC_B = gcc -Wall -Wextra -Werror -g -o checker

SRC = push_swap.c ft_isdigit.c instructions.c sort_four.c \
		ft_itoa.c instructionss.c sort_three.c sort_five.c \
		ft_putstr.c manage_struct.c treatement.c ft_atoi.c \
		ft_sort.c push_data.c \

SRC_B = ./checker_bonus/push_swap_checker.c ./checker_bonus/ft_isdigit.c ./checker_bonus/instructions.c \
		./checker_bonus/ft_itoa.c ./checker_bonus/instructionss.c ./checker_bonus/sort_three.c \
		./checker_bonus/ft_putstr.c ./checker_bonus/manage_struct.c ./checker_bonus/ft_atoi.c \
		./checker_bonus/push_data.c ./checker_bonus/ft_strcmp.c ./checker_bonus/ft_strjoin.c \
		./checker_bonus/ft_commands.c \

NAME = push_swap

BONUS = checker

all: $(NAME)

bonus : $(BONUS)

$(NAME): 
	$(CC) $(SRC)

$(BONUS):
	$(CC_B) $(SRC_B) 

clean:
	rm -f $(NAME) $(BONUS)

fclean: clean	
	rm -f $(NAME) $(BONUS)

re : fclean all
