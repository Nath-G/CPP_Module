
NAME		= 	 aweapon

CC			= 	clang++

CFLAGS		= 	-Wall -Wextra -Werror -std=c++98 -g3

SRCS		=	main.cpp \
				AWeapon.cpp \
				PlasmaRifle.cpp \
				Flamethrower.cpp \
				Flowerthrower.cpp \
				PowerFist.cpp \
				Enemy.cpp \
				SuperMutant.cpp \
				RadScorpion.cpp \
				Piggsy.cpp \
				Character.cpp \

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
	$(CC) $(CFLAGS) $(OBJS) -fsanitize=address -g3 -o $(NAME)

ffsan: fclean
	make fsan -j

.PHONY: all clean fclean re fsan ffsan
