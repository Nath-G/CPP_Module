
NAME		= 	 identifier

CC			= 	clang++

CFLAGS		= 	-Wall -Wextra -Werror

SRCS		=	main.cpp \
				Base.cpp \
				

OBJS		=	$(SRCS:.cpp=.o)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		@	rm -rf $(OBJS)

fclean:	clean
		@	rm -rf $(NAME)

re: fclean
	make -j

fsan: $(OBJS) -fsanitize=address -g3
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

ffsan: fclean
	make fsan -j

.PHONY: all clean fclean re fsan ffsan identifier
