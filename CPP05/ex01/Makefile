NAME = Maggots
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
includeS = -I inc
SRCS = src/main.cpp src/Bureaucrat.cpp src/Form.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(includeS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re