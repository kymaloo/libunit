NAME		:= libunit.a
LIBFT_DIR	:= ./libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a

INCLUDES	:= -Iincludes
ARCHIVES	:= $(LIBFT_A)
CFLAGS		:= -Wall -Wextra -Werror -g3 $(INCLUDES)

BRED	:=	\033[1;31m
RED		:=	\033[31m
YELLOW	:=	\033[33m
GREEN	:=	\033[32m
BLUE	:=	\033[1;34m
RESET	:=	\033[0m

SRCS	:= 	srcs/main.c \
			srcs/test_utils.c \
			srcs/tests/ft_strlen/01_empty_test.c \
			srcs/tests/ft_strlen/02_basic_test.c \
			srcs/tests/ft_atoi/00_launcher.c \
			srcs/tests/ft_atoi/01_basic_test.c \
			srcs/tests/ft_atoi/02_negative_test.c \
			srcs/tests/ft_atoi/03_zero_test.c \
			srcs/tests/ft_atoi/04_whitespace_test.c \
			srcs/tests/ft_atoi/05_sign_test.c \
			srcs/tests/ft_atoi/06_mixed_test.c \
			srcs/tests/ft_atoi/07_large_positive_test.c \
            srcs/tests/ft_atoi/08_large_negative_test.c \
            srcs/tests/ft_atoi/09_leading_zeros_test.c \
            srcs/tests/ft_atoi/010_empty_string_test.c \
			srcs/tests/ft_strlen/00_launcher.c \
			srcs/tests/ft_split/00_launcher.c \
			srcs/tests/ft_split/01_basic_test.c \
			srcs/print_results.c \
			srcs/tests/real/00_launcher.c \
			srcs/tests/real/ko.c \
			srcs/tests/real/ok.c \
			srcs/tests/real/segfault.c \
			srcs/tests/real/bus.c \
			srcs/tests/real/real.c \

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

test: $(NAME)

%.o: %.c
	@printf "$(BLUE)$(NAME): compiling objects:\n$(BLUE)$(NAME): compiling $(RESET)%-45.45s\n" $@
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "\033[F\033[F" || (echo "$(BLUE)$(NAME): $(BRED) $<: error: $(RESET)compilation failure$(RESET)" && return 1)

$(LIBFT_A):
	@echo "$(BLUE)$(NAME): archiving $(LIBFT_A)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(BLUE)$(NAME): $(GREEN)$(LIBFT_A) archived !$(RESET)"

$(NAME): $(LIBFT_A) $(OBJS) 
	@printf "\33[2K\r$(BLUE)$(NAME): objects $(GREEN)compiled$(RESET)\n"
	@echo "$(CC) $(CFLAGS) \$$($(NAME)_OBJS) $(ARCHIVES) $(LIBS) -o $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(ARCHIVES) $(LIBS) -o $(NAME)
	@printf "\33[2K\r$(BLUE)$(NAME): $(NAME) $(GREEN)Linked!$(RESET)\n"

clear:
	@clear

clean:
	@echo "$(BLUE)$(NAME): Cleaning object files$(RESET)"
	@rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(BLUE)$(NAME): Cleaning $(NAME)$(RESET)"
	@rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: clear fclean all

re_project_only: clear
	@echo "$(BLUE)$(NAME): Cleaning object files$(RESET)"
	@rm -rf $(OBJS)
	@echo "$(BLUE)$(NAME): Cleaning $(NAME)$(RESET)"
	@rm -rf $(NAME)
	make all

.PHONY: all, clean, fclean, re, clear