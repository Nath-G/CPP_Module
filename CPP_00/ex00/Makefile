
# NAME - COMPLIATOR - FLAGGS -LIB****************************************** #

NAME		= megaphone
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -I.
RM			= rm -f

# SRCS *********************************************************************** #

SRCS	= megaphone.cpp 
#SRCS		= ${wildcard *.cpp}

# OBJS *********************************************************************** #

OBJS	=	${SRCS:.cpp=.o}

# RULES ********************************************************************** #

%.o :		%.cpp
			${CC} ${CFLAGS} -c $< -o $@

all :		${NAME}

${NAME} :	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} 

clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME}

re :		fclean all

.PHONY :
			all ${NAME} clean fclean re
