NAME = pipex

OBJDIR=./obj/

HEADER = pipex.h

SRC = ft_getpaths.c ft_strdup.c ft_error.c ft_initialize.c\
	ft_split.c ft_strlen.c ft_substr.c ft_stradd.c\
	ft_strjoin.c ft_checkaccess.c ft_strncmp.c ft_processes.c

SRC_O = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = cc

CFLAGS = -Wall -Werror -Wextra 

$(NAME): $(OBJDIR) $(OBJDIR)$(NAME).o $(SRC_O) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJDIR)$(NAME).o $(SRC_O)  -o $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)$(NAME).o: $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJDIR)%.o: %.c $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

all: $(NAME) $(NAME_CHECKER)

exec: all clean

clean: 
	rm -f $(SRC_O) $(OBJDIR)$(NAME).o; 

fclean: clean
	rm -f $(NAME); rm -rf $(OBJDIR);

re: fclean all

.PHONY: all clean fclean re exec