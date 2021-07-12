CC		=	gcc

CFLAGS	= 	-g #-fsanitize=address #-Werror -Wall -Wextra

HEADER	=	minitalk_header.c

CLIENT	=	client

SERVER	=	server

SRC1	=	client.c utils1.c utils2.c

SRC2	=	server.c utils1.c utils2.c

OBJECTS1=	$(SRC1:.c=.o)

OBJECTS2=	$(SRC2:.c=.o)

all:		$(CLIENT)

$(CLIENT): 	$(OBJECTS1) $(SERVER)
			@$(CC) $(CFLAGS) $(OBJECTS1) -I $(HEADER) -o $(CLIENT)
			@echo ""
			@echo "\033[33m     ▂▃▅▇█▓▒░ CLIENT DONE ░▒▓█▇▅▃▂\033[0m"
			@echo ""

$(SERVER): 	$(OBJECTS2)
			@$(CC) $(CFLAGS) $(OBJECTS2) -I $(HEADER) -o $(SERVER)
			@echo ""
			@echo "\033[33m     ▂▃▅▇█▓▒░ SERVER DONE ░▒▓█▇▅▃▂\033[0m"
			@echo ""

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADER) -c $^ -o $@
			@echo "\033[35m   Compiling...  $<\033[0m"

clean:
			@rm -f $(OBJECTS1) $(OBJECTS2)
			@echo "\033[32m------> CLEAN  completed <------\033[0m"

fclean:		clean
			@rm -f $(SERVER) $(CLIENT)
			@echo "\033[34m------> FCLEAN completed <------\033[0m"

re:			fclean all
			@echo "\033[36m------>   RE completed   <------\033[0m"

.PHONY:		all clean fclean re
