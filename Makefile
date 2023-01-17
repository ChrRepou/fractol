NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = fractol.c error.c
OBJS = $(SRCS:.c=.o)

#GNL = gnl.a
LIBMLX = ./MLX42

all: libmlx $(NAME) 

libmlx:
	@make -C $(LIBMLX)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -L$(LIBMLX) -lmlx42 -lglfw -L "$(shell brew --prefix glfw)/lib/" -o $(NAME)

#$(GNL):
#	@make -C ./gnl
#	@cp gnl/gnl.a $(GNL)	

clean:
	rm -f $(OBJS)
#	@make -C ./gnl clean
	@make -C $(LIBMLX) clean 
fclean: clean
	rm -f $(NAME) $(GNL)
#	@make -C ./gnl fclean
	@make -C $(LIBMLX) fclean 
re: fclean
#	@make -C ./gnl fclean
	@make -C $(LIBMLX) fclean 	
	@make all