NAME		:= libunit.a
LIBFT_DIR	:= ./libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a

INCLUDES	:= -Iinclude
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
			srcs/tests/ft_strlen/00_launcher.c \
			srcs/print_results.c \

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)


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