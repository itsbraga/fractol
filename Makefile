#################################################################################
#																				#
#				      				COLORS										#
#																				#
#################################################################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM			:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED			:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE		:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN		:=	\e[96m

# define rainbow
# $(shell echo $(1) | sed -e "s/./\$(shell printf '\033[38;5;%dm' \$$(shell expr \( \$$(od -An -N1 -tu1 /dev/urandom) \% 6 + 196))&) /g")
# endef

# COLORED_TEXT	:= $(call (rainbow))


#################################################################################
#																				#
#				    				BASICS										#
#																				#
#################################################################################

NAME		=	fractol
# NAME_BONUS	=	fractol_bonus

LIBFT_PATH	=	libft/
LIBFT_X		=	$(addprefix $(LIBFT_PATH), libft.a)
MLX_PATH	=	minilibx-linux/
MLX_X		=	$(addprefix $(MLX_PATH), libmlx.a)

CC			=	cc

MAKEFLAGS	+=	--no-print-directory
MLXFLAGS	=	-Lminilibx-linux -lX11 -lXext
DEPFLAGS	=	-MMD -MP
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf


#################################################################################
#																				#
#				    				SOURCES										#
#																				#
#################################################################################

FRACTAL_DIR		=	fractals/
FRACTAL_FILES	=	mandelbrot.c julia.c

PARSING_DIR		=	parsing/
PARSING_FILES	=	check_args.c

EXEC_DIR		=	exec/
EXEC_FILES		=	main.c

# BONUS_FILES	=	


#################################################################################
#																				#
#								COMBINE FILES									#
#				    				and											#
#								DIRECTORIES										#
#									  											#
#################################################################################

SRC_DIR		=	src/

SRCS		=	$(addprefix $(FRACTAL_DIR), $(FRACTAL_FILES)) \
				$(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
				$(addprefix $(EXEC_DIR), $(EXEC_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRCS:.c=.o)

OBJ_DIRS	=	$(addprefix $(OBJ_DIR), $(FRACTAL_DIR), $(PARSING_DIR), $(EXEC_DIR))

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#############################	  BONUS PART	#################################

# BONUS_SRC_DIR	=	bonus/

# OBJ_B_DIR		=	obj_bonus/


#################################################################################
#																				#
#								DEPENDENCIES									#
#																				#
#################################################################################

DEP_NAMES	=	$(SRCS:.c=.d)

DEP_DIRS	=	$(addprefix $(OBJ_DIR), $(FRACTAL_DIR), $(PARSING_DIR), $(EXEC_DIR))

DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))


#################################################################################
#																				#
#				     				RULES										#
#																				#
#################################################################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<          \r"
				@$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@
-include $(DEPS)

# links .o files to libraries, constructs the necessary dependencies and do ASCII art
$(NAME): $(OBJS)
			@make -sC $(MLX_PATH) $(MAKEFLAGS)
			@printf "\n\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n"
			@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
			@printf "\n"
			@if [ ! -f .build ]; then \
				printf "\t\t%s\n" \
				"░░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░░░░" \
				"░░░░░░░░▄▄▄▄█▀▀▀░░░░░░░░░░░░▀▀██░░░░░░░░░░░░" \
				"░░░░░▄███▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄░░░░░░░░" \
				"░░░▄▀▀░█░░░░▀█▄▀▄▀██████░▀█▄▀▄▀████▀░░░░░░░░" \
				"░░░█░░░█░░░░░░▀█▄█▄███▀░░░░▀▀▀▀▀▀▀░▀▀▄░░░░░░" \
				"░░░█░░░█░▄▄▄░░░░░░░░░░░░░░░░░░░░░▀▀░░░█░░░░░" \
				"░░░█░░░▀█░░█░░░░▄░░░░▄░░░░░▀███▀░░░░░░░█░░░░" \
				"░░░█░░░░█░░▀▄░░░░░░▄░░░░░░░░░█░░░░░░░░█▀▄░░░" \
				"░░░░▀▄▄▀░░░░░▀▀▄▄▄░░░░░░░▄▄▄▀░▀▄▄▄▄▄▀▀░░█░░░" \
				"░░░░█▄░░░░░░░░░░░░▀▀▀▀▀▀▀░░░░░░░░░░░░░░█░░░░" \
				"░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██░░░░░" \
				"░░░░░▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░▄▀▀░░░▀█░░░" \
				"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" \
				"█░░█▀▄ █▀▀ █▀█ █░░░░█░▄░█ █ ▀█▀ █░█░░█ ▀█▀░█" \
				"█░░█░█ █▀▀ █▀█ █░░░░▀▄▀▄▀ █ ░█░ █▀█░░█ ░█░░█" \
				"█░░▀▀░ ▀▀▀ ▀░▀ ▀▀▀░░░▀░▀░ ▀ ░▀░ ▀░▀░░▀ ░▀░░█" \
				"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"; \
				printf "\n\n"; \
				touch .build; fi
			@$(CC) $(CFLAGS) $(OBJS) -I $(LIBFT_X) -I $(MLX_X) $(MLXFLAGS) -o $(NAME)
			@printf "$(BOLD)$(CYAN)[Mandatory]:\t$(RESET)$(BOLD)Compilation done! *** "
			@printf "$(RESET)$(PINK)You can now generate fractals 🌈\n\n"

all:	$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -sC $(MLX_PATH) $(MAKEFLAGS)
		@make clean -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t\t$(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(MLX_X) $(LIBFT_X)
			@find . -name ".build" -delete
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]:\t$(RESET)Full clean completed!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:		fclean all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

norm:
		@clear
		@norminette $(SRC_DIR) $(LIBFT_PATH) | grep -v Norme -B1 || true


#################################################################################
#																				#
#				     				BONUS										#
#																				#
#################################################################################

# $(NAME_BONUS): $(OBJS_BONUS)
# 			@printf "\n\n$(RESET)$(BOLD)$(CYAN)[FRACT-OL BONUS]:\t$(RESET)"
# 			@$(CC) $(CFLAGS) $(INC) $(OBJS_BONUS) libft.a -o $(CHECKER)
# 			@printf "$(CYAN) ./? ready to launch !$(RESET)\n\n"

# $(OBJ_B_DIR)%.o: $(BONUS_SRC_DIR)%.c
# 			@mkdir -p $(dir $@)
# 			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<                  \r"
# 			@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@

# -include $(BONUS_DEP_NAMES)

# bonus:
# 		@make -sC $(MLX_PATH) $(MAKEFLAGS)
# 		@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
# 		@cp $(MLX_PATH)/libmlx.a .
# 		@cp $(LIBFT) .
#		@make $(NAME_BONUS)
# 		@printf "\n\n✨ $(BOLD)$(YELLOW)Bonuses successfully compiled! $(RESET)✨\n"


.PHONY:		build all clean fclean re diff norm