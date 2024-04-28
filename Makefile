NAME	=		cub3D

SRCS_FILES	=	init_map.c \
					init_ray.c \
					cub.c \
					get_data.c \
					map.c \
					parsing.c \
					utils.c \
					walls.c \
					ray.c \
					display_2d.c \
					img_pix_put.c \
					main.c

INC_FILES	= cub3d.h

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I./includes -g3

INCLUDES	= -I. -Iminilibx-linux/.

LIB		= -Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft -lm

OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)

OBJS	=		$(addprefix objs/, $(OBJS_FILES))

DEP		=		$(OBJS:%.o=%.d)

all		:		$(NAME)

$(NAME)	:	$(OBJS)
	make -C libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

clean	:
	make -C libft clean
	make -C minilibx-linux clean
	rm -rf $(OBJS) $(DEP)
	rm -rf objs/

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

objs/%.o	: srcs/%.c $(INCS)
	mkdir -p objs
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re