NAME = push_swap

NAME2 = checker

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = push_swap.h

INCLUDESB = push_swap_bonus.h

SRC =	push_swap.c			\
		ft_strjoin.c		\
		ft_split.c			\
		ft_check.c			\
		ft_utils_check.c 	\
		ft_utils0.c			\
		ft_fuctions.c		\
		ft_fuctions1.c 		\
		ft_utils1.c			\
		ft_utils2.c			\
		ft_utils3.c 		\
		best_move_stack_a.c	\
		ft_mv_fb_to_a.c 	\
		ft_memmove.c	 	\
		ft_mv_fa_to_b2.c 	\

SRCB =	checker_bon/checker_bonus.c 		\
		checker_bon/ft_check_bonus.c		\
		checker_bon/ft_fuctions1.c			\
		checker_bon/ft_fuctions.c			\
		checker_bon/ft_spilt_bonus.c		\
		checker_bon/ft_strjoin_bonus.c		\
		checker_bon/checker_bonus_utils.c	\
		checker_bon/checker_bonus_utils2.c 	\
		checker_bon/get_next_line.c			\
		checker_bon/utils_malloc.c			\


OBJECTS = $(SRC:.c=.o)
OBJECTSB = $(SRCB:.c=.o)

all: $(NAME)
	@echo "------------------push_swap-----------------"
	@echo " "
	@echo " "

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(OBJECTSB)
	@$(CC) $(CFLAGS) $(OBJECTSB) -o $(NAME2)
	@echo "------------------push_swap_bonus-----------------"
	@echo " "
	@echo " "

%.o : %.c $(INCLUDESB)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJECTS) $(OBJECTSB) 

fclean: clean
	@rm -rf $(NAME) $(NAME2)

re: fclean all