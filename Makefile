MAIN =	src/fdf.c \
		src/parsing/parse.c \
		src/utils/utils.c \
		src/screen/get_monitor_resolution.c \
		src/screen/set_sizes.c \
		src/colors/colors.c \
		src/transform/point.c \
		src/transform/fit.c \
		src/transform/isometric.c \
		src/transform/bounds.c \
		src/drawing/draw_line.c \
		src/drawing/draw_grid.c \
		src/drawing/launch_iso_map.c \
		src/utils/inits.c \
		src/drawing/draw_solid_background.c \
		src/hooks/hooks.c \
		src/utils/min_max_z.c \
		src/drawing/extrude.c \
		src/drawing/zoom.c \
		src/drawing/redraw.c \
		src/transform/center.c \
		src/colors/interpolate.c \
		src/colors/gradient.c \
		src/drawing/rotate_z.c \
		src/drawing/rotate_x.c \
		src/drawing/rotate_y.c \
		src/drawing/translate_key.c \
		src/colors/color_hooks.c \
		src/drawing/launch_dim_map.c \
		src/transform/dimetric.c \
		src/drawing/change_view.c \
		src/transform/top.c \
		src/drawing/launch_top_map.c \

OBJS_SRC = $(MAIN:.c=.o) 

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = fdf

# Libft Configuration
LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

# MLX42 Configuration
LIBMLX_PATH = ./libs/MLX42
MLX_BUILD_PATH = $(LIBMLX_PATH)/build
HEADERS = -I ./include -I $(LIBMLX_PATH)/include
LIBS = $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm -lGL
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
