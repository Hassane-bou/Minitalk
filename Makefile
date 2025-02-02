CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_PRINTF = printf/ft_hexa.c printf/ft_printf.c printf/ft_putchar.c \
		printf/ft_putnbr.c printf/ft_putnbruns.c printf/ft_putstr.c


SRC_CLIENT_BONUS = bonus/client_bonus.c 
SRC_SERVER_BONUS = bonus/server_bonus.c


OBJS = $(SRC_CLIENT:.c=.o) $(SRC_SERVER:.c=.o) $(SRC_PRINTF:.c=.o)

OBJS_BONUS = $(SRC_CLIENT_BONUS:.c=.o) $(SRC_SERVER_BONUS:.c=.o)  

NAME_SERVER = server
NAME_CLIENT =client

NAMEB_SERVER = server_bonus
NAMEB_CLIENT = client_bonus


all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(SRC_PRINTF) -o $(NAME_SERVER)
$(NAME_CLIENT): $(OBJS)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(SRC_PRINTF) -o $(NAME_CLIENT)

bonus: $(NAMEB_SERVER) $(NAMEB_CLIENT)

$(NAMEB_SERVER): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(SRC_PRINTF) -o $(NAMEB_SERVER)
$(NAMEB_CLIENT): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(SRC_PRINTF) -o $(NAMEB_CLIENT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAMEB_CLIENT) $(NAMEB_SERVER)

re: fclean all

.PHONY: clean 