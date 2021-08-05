
NAME		= 	 whatever

CC			= 	clang++

CFLAGS		= 	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \

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

fsan: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g3 -o $(NAME)

ffsan: fclean
	make fsan -j

.PHONY: all clean fclean re fsan ffsan whatever
