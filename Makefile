CC = cc

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code

SRCS	=	srcs/main.c \
			srcs/parsing2.c\
			srcs/get_pos.c \
			srcs/ft_count.c \
			srcs/load_wind.c \
			srcs/flood_fill.c \
			srcs/memfree.c \
			srcs/errorhandle.c \
			srcs/load_wind.c \
			srcs/ft_abbreviations.c \

SRCS_B	=	BONUS/main_bonus.c \
			BONUS/parsing2_bonus.c\
			BONUS/get_pos_bonus.c \
			BONUS/ft_count_bonus.c \
			BONUS/load_wind_bonus.c \
			BONUS/flood_fill_bonus.c \
			BONUS/errorhandle_bonus.c \
			BONUS/memfree_bonus.c \
			BONUS/ft_abbreviations_bonus.c \
			BONUS/enemy_patrol_bonus.c \
			BONUS/move_player_bonus.c \
			
OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

NAME = so_long

NAME_BONUS = so_long_bonus

DIR_LIB = libft/libft.a

all: $(NAME)

BONUS/%.o: BONUS/%.c BONUS/so_long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(DIR_LIB)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $(CFLAGS) $^ -o $(NAME) $(DIR_LIB)

$(NAME_BONUS) :$(OBJS_B)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $(CFLAGS) $(OBJS_B) -o $(NAME_BONUS) $(DIR_LIB)

bonus: $(NAME_BONUS)

$(DIR_LIB):
	@make -C libft/

clean:
	@rm -f $(OBJS) $(OBJS_B)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C libft/ 

re : fclean all