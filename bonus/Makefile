NAME = pipex_bonus

OBJDIR=./obj/

HEADER = pipex_bonus.h

SRC_WITHOUT_BONUS = ft_getpaths.c ft_strdup.c ft_error.c ft_initialize.c\
	ft_split.c ft_strlen.c ft_substr.c ft_stradd.c\
	ft_strjoin.c ft_checkaccess.c ft_strncmp.c ft_processes.c

SRC = $(SRC_WITHOUT_BONUS:.c=_bonus.c)

SRC_O = $(addprefix $(OBJDIR),$(SRC:.c=.o))

GNL = $(addprefix $(OBJDIR),get_next_line.a)

CC = cc

CFLAGS = -Wall -Werror -Wextra 

$(NAME): $(OBJDIR) $(GNL) $(SRC_O) $(OBJDIR)$(NAME).o $(HEADER) Makefile
	$(CC) $(CFLAGS) $(GNL) $(SRC_O) $(OBJDIR)$(NAME).o -o $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(GNL): get_next_line/*.c get_next_line/*.h
	make -C ./get_next_line/; cp ./get_next_line/get_next_line.a $(OBJDIR)get_next_line.a;
	make fclean -C ./get_next_line;

$(OBJDIR)$(NAME).o: $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJDIR)%.o: %.c $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

all: $(NAME) $(NAME_CHECKER)

exec: all clean

clean: 
	rm -f $(SRC_O) $(OBJDIR)$(NAME).o $(GNL); 
	make clean -C ./get_next_line;

fclean: clean
	rm -f $(NAME); rm -rf $(OBJDIR);
	make fclean -C ./get_next_line;

re: fclean all

.PHONY: all clean fclean re exec