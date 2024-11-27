MAIN =	src/fdf.c \
		src/parse.c \

OBJS_SRC = $(MAIN:.c=.o) 

CC = cc
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g

NAME = fdf

# Libft Configuration
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# MLX42 Configuration
LIBMLX_PATH = ./MLX42
MLX_BUILD_PATH = $(LIBMLX_PATH)/build
HEADERS = -I ./include -I $(LIBMLX_PATH)/include
LIBS = $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SRC) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

# Compile MLX42
libmlx:
	@cmake $(LIBMLX_PATH) -B $(MLX_BUILD_PATH) && make -C $(MLX_BUILD_PATH) -j4

# Compile Libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

# Object Files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SRC)
	$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(MLX_BUILD_PATH)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libmlx