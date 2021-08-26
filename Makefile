NAME = push_swap

SRC = 	Sources/ps.c\
		Sources/sort.c\
		Sources/sortpush.c\
		Sources/parse.c\
		Sources/check.c\
		Sources/pivot.c\
		Sources/setpos.c\
		ToolBox/list.c\
		ToolBox/unit.c\
		ToolBox/check.c\
		Instructions/swap.c\
		Instructions/Push/push_pb.c\
		Instructions/Push/push_pa.c\
		Instructions/Rotate/rotate_ra.c\
		Instructions/Rotate/rotate_rb.c\
		Instructions/Rotate/rotate_rr.c\
		Instructions/Reverse/reverse_rra.c\
		Instructions/Reverse/reverse_rrb.c\
		Instructions/Reverse/reverse_rrr.c\

LIBFT = ./ToolBox/Libft

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc 

all: $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) ./ToolBox/Libft/libft.a $(OBJ) -o $(NAME)
	@echo "\x1b[36m$(NAME) created!\033[0m"

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)
	@echo "\x1b[36mAll .o deleted.\033[0m"

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	@echo "\x1b[36m$(NAME) deleted.\033[0m"

re : fclean all

.PHONY : clean fclean all re