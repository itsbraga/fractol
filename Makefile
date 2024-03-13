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

RED			:=	\e[31m
ORANGE		:=	\e[38;5;208m
YELLOW		:=	\e[33m
GREEN		:=	\e[32m
CYAN		:=	\e[36m
BLUE		:=	\e[34m
INDIGO		:=	\e[34;45m
PURPLE		:=	\e[35m
PINK		:=	\e[38;2;255;182;193m


#################################################################################
#																				#
#				    				BASICS										#
#																				#
#################################################################################

NAME		=	fractol
# NAME_BONUS	=	fractol_bonus

LIBFT_PATH	=	libft/
#LIBFT_X		=	$(addprefix $(LIBFT_PATH), libft.a)
LIBFT_X		=	libft/libft.a
MLX_PATH	=	minilibx-linux/
#MLX_X		=	$(addprefix $(MLX_PATH), libmlx.a)
MLX_X		=	minilibx-linux/libmlx.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-Lminilibx-linux -lX11 -lXext
DEPFLAGS	=	-MMD -MP
MAKEFLAGS	+=	--no-print-directory

RM			=	rm -rf


#################################################################################
#																				#
#				    				SOURCES										#
#																				#
#################################################################################

CONFIGS_DIR		=	configs/
CONFIGS_FILES	=	pixels.c mlx_handler.c

EXEC_DIR		=	exec/
EXEC_FILES		=	check_args.c init.c main.c

FRACTAL_DIR		=	fractals/
FRACTAL_FILES	=	formula.c

# BONUS_FILES	=	


#################################################################################
#																				#
#								COMBINE FILES									#
#				    				and											#
#								DIRECTORIES										#
#									  											#
#################################################################################

SRC_DIR		=	src/

SRCS		=	$(addprefix $(CONFIGS_DIR), $(CONFIGS_FILES)) \
				$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
				$(addprefix $(FRACTAL_DIR), $(FRACTAL_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRCS:.c=.o)

OBJ_DIRS	=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR), $(FRACTAL_DIR))

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

DEP_DIRS	=	$(addprefix $(OBJ_DIR), $(CONFIGS_DIR), $(EXEC_DIR), $(FRACTAL_DIR))

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

$(NAME): $(OBJS)
			@make -sC $(MLX_PATH) $(MAKEFLAGS)
			@printf "\n\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n"
			@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
			@printf "\n\n"
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
			@printf "$(RESET)$(shell bash rainbow.sh "[FRACT-OL Mandatory]"): "
			@printf "$(RESET)$(BOLD)$(PINK)Compilation done!\n\n$(RESET)"
			@$(CC) $(CFLAGS) $(OBJS) -Inc $(LIBFT_X) -Inc $(MLX_X) $(MLXFLAGS) -o $(NAME)
			@printf "$(RESET)$(shell bash rainbow.sh "You can now generate fractals") 🌈\n\n"

all:	$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -sC $(MLX_PATH) $(MAKEFLAGS)
		@make clean -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@printf "\n$(BOLD)$(GREEN)[objs]:\t $(RESET)Clean completed\n"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(MLX_X) $(LIBFT_X)
			@find . -name ".build" -delete
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(BLUE)[execs]: $(RESET)Full clean completed!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:		fclean build all
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


.PHONY:		all build clean fclean re diff norm