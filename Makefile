#################################################################################
#										#
#				      COLORS					#
#										#
#################################################################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
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
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m

# define rainbow
# $(shell echo $(1) | sed -e "s/./\$(shell printf '\033[38;5;%dm' \$$(shell expr \( \$$(od -An -N1 -tu1 /dev/urandom) \% 6 + 196))&) /g")
# endef

# COLORED_TEXT	:= $(call (rainbow))


#################################################################################
#										#
#				    BASICS					#
#										#
#################################################################################

NAME		=	fractol
# NAME_BONUS	=	fractol_bonus

LIBFT_PATH	=	libft/
MLX_PATH	=	minilibx-linux/

CC		=	cc

MAKEFLAGS	+=	--no-print-directory
MLXFLAGS	=	-lmlx -lXext -lX11
DEPFLAGS	=	-MMD -MP
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/

DEBUG		=	-g -O0
RM		=	rm -rf


#################################################################################
#										#
#				    SOURCES					#
#										#
#################################################################################

FRACTAL_DIR	=	fractal_types/
FRACTAL_FILES	=	julia.c \
			mandelbrot.c

UTILS_DIR	=	
UTILS_FILES	=	

# BONUS_FILES	=	


#################################################################################
#										#
#				COMBINE FILES					#
#				    and						#
#				DIRECTORIES					#
#									  	#
#################################################################################

SRC_DIR		=	src/

SRCS		=	$(addprefix $(FRACTAL_DIR), $(FRACTAL_FILES)) \
			$(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRCS:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(FRACTAL_DIR) \
            		$(UTILS_DIR))

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#############################	  BONUS PART	#################################

# BONUS_SRC_DIR	=	bonus/

# OBJ_B_DIR	=	obj_bonus/


#################################################################################
#										#
#				DEPENDENCIES					#
#										#
#################################################################################

DEP_NAMES	=	$(SRCS:.c=.d)

DEP_FOLDERS	=	$(addprefix $(OBJ_DIR), $(FT_FD_DIR) \
                		$(FT_IS_DIR) \
				$(FT_MEM_DIR) \
				$(FT_STR_DIR) \
                   		$(FT_TO_DIR) \
				$(FT_LST_DIR) \
                		$(GNL_DIR) \
				$(FT_PRINTF_DIR) \
				$(FT_FROM_TO_DIR) \
				$(INT_DIR) \
				$(MATHS_DIR))

DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_NAMES))


#################################################################################
#										#
#				     RULES					#
#										#
#################################################################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(BOLD)$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<         \r"
			@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@

-include $(DEPS)

# links .o files to libraries, constructs the necessary dependencies and do ASCII art
$(NAME): $(OBJS)
		@printf "\t\t\t──▒▒▒▒▒▒───▄████▄\n"
		@printf "\t\t\t─▒─▄▒─▄▒──███▄█▀\n"
		@printf "\t\t\t─▒▒▒▒▒▒▒─▐████──█─█\n"
		@printf "\t\t\t─▒▒▒▒▒▒▒──█████▄\n"
		@printf "\t\t\t─▒─▒─▒─▒───▀████▀\n\n\n"
		@make -sC $(MLX_PATH) $(MAKEFLAGS)
		@make -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@$(CC) $(CFLAGS) $(INC) $(OBJS) libft.a $(MLX_PATH) $(MLXFLAGS) -o $(NAME)
		@printf "\n$(BOLD)$(PINK). ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .$(RESET)\n\n\n"
		@printf "$(BOLD)$(GREEN)[Mandatory]: Compilation done!$(RESET)\n\n"

# @printf "\n\n$(RESET)$(BOLD)$(BLUE)[FRACT-OL]:\t$(RESET)"
# @printf "$(BLUE)./fractol ready to draw fractals $(RESET)🌈\n\n"

all:	$(NAME)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -sC $(MLX_PATH) $(MAKEFLAGS)
		@make clean -sC $(LIBFT_PATH) $(MAKEFLAGS)
		@printf "\n$(BOLD)$(PINK)Clean completed\n"

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(MLX_PATH)/libmlx $(LIBFT_PATH)/libft.a
		@$(RM) libmlx libft.a
		@find . -name ".DS_Store" -delete
		@printf "$(BOLD)$(BLUE)[All]:\t$(RESET)Full clean completed!\n\n"
		@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:	fclean all
		@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

norm:
		@clear
		@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


#################################################################################
#										#
#				     BONUS					#
#										#
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
# 		@cp $(LIBFT_PATH)/libft.a .
#		@make $(NAME_BONUS)
# 		@printf "\n\n✨ $(BOLD)$(YELLOW)Bonuses successfully compiled! $(RESET)✨\n"

.PHONY:		build all clean fclean re diff norm