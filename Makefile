NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       main_utils.c \
       main_utils2.c \
       parsing.c \
       parsing_2.c \
       stack_utils.c \
       ft_functions_1.c \
       ft_functions_2.c \
       ft_functions_3.c \
       ft_functions_4.c \
       ft_algo_simple.c \
       ft_algo_medium.c \
       ft_algo_medium_utils.c \
       ft_algo_complex.c \
       ft_algo_complex_utils.c \
       ft_algo_adaptive.c \
       ft_benchmark.c \
	   ft_printf_functions_1.c \
	   ft_printf_functions_2.c \
	   ft_printf.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
