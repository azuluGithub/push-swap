CC = gcc
CHECKER = checker
PUSH_SWAP = push_swap
FLAGS = -Wall -Wextra -Werror

SRC_CH = checker.c \
		apply.c \
		init_struct.c \
		stack_operations.c \
		sa_sb_ss.c \
		pa.c \
		pb.c \
		ra_rb_rr.c \
		rra_rrb_rrr.c \
		is_sorted.c \
		push_to_stack.c \
		get_arguments.c \
		init_program.c

SRC_PS = push_swap.c \
		init_struct.c \
		stack_operations.c \
		sa_sb_ss.c \
		pa.c \
		pb.c \
		ra_rb_rr.c \
		rra_rrb_rrr.c \
		is_sorted.c \
		push_to_stack.c \
		get_arguments.c \
		init_program.c \
		sort.c \
		sort_all.c \
		sort_2_3.c \
		position_of_numbers.c \
		push_2_elem_to_b.c \
		check_size_of_a.c \
		push_rem_to_b.c \
		push_back_to_a.c \
		push_to_stack_b.c

OBJ_CH = $(SRC_CH:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS) -c $(SRC_CH)
	@$(CC) $(FLAGS) $(OBJ_CH) libft/libft.a -o $(CHECKER)

$(PUSH_SWAP):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS) -c $(SRC_PS)
	@$(CC) $(FLAGS) $(OBJ_PS) libft/libft.a -o $(PUSH_SWAP)

clean:
	@rm -f $(OBJ_CH)
	@rm -f $(OBJ_PS)
	@make -C libft/ clean

fclean: clean
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)
	@rm -f libft/libft.a

re: fclean all
