NAME = RTv1
SRC = source_one.c cam_trace.c create_cam.c create_obj.c create_scene.c draw_that.c \
 		gtor.c obj_col.c thread_pow.c vec_math.c light_calc.c parser.c obj_constr.c
OBJ = $(SRC:%.c=%.o)
REMOVE = rm -rf
FLAGS = -c -Wall -Werror -Wextra
MINILIBX = -lmlx -framework OpenGl -framework AppKit
LIBFT = libft/libft.a

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): ${OBJ} $(LIBFT)
	gcc $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ) -I. $(MINILIBX) libft/libft.a

%.o: %.c rtv1.h
	gcc $< $(FLAGS) -o $@

$(LIBFT):
	make -C libft

clean:
	make -C libft/ clean
	$(REMOVE) $(OBJ)
	$(REMOVE) *~

fclean: clean
	make -C libft/ fclean
	$(REMOVE) $(OBJ) $(NAME)
	$(REMOVE) *~

re: fclean all

norm:
	norminette source_one.c cam_trace.c create_cam.c create_obj.c create_scene.c draw_that.c \
 		gtor.c obj_col.c thread_pow.c vec_math.c light_calc.c parser.c obj_constr.c rtv1.h