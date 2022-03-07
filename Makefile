NAME = pipex

NAME_BONUS = pipex_bonus

$(NAME): ./mandatory/*
	make -C ./mandatory/;
	cp ./mandatory/pipex ./pipex

$(NAME_BONUS): ./bonus/*
	make -C ./bonus/;
	cp ./bonus/pipex_bonus ./pipex_bonus

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean: 
	make clean -C ./mandatory/; make clean -C ./bonus/;

fclean: 
	make fclean -C ./mandatory/; make fclean -C ./bonus/; rm -f $(NAME) $(NAME_BONUS);

re: fclean all

.PHONY: all clean fclean re bonus