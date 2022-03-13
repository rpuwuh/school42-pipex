NAME = pipex

NAME_BONUS = pipex_bonus

$(NAME): ./mandatory/*
	cd ./mandatory; make; cd ..;
	cp ./mandatory/pipex ./pipex

$(NAME_BONUS): ./bonus/*
	cd ./bonus; make all; cd ..;
	cp ./bonus/pipex_bonus ./pipex_bonus

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean: 
	cd ./mandatory; make clean; cd ..;
	cd ./bonus; make clean; cd ..;

fclean: 
	cd ./mandatory; make fclean; cd ..;
	cd ./bonus; make fclean; cd ..;
	rm -f $(NAME) $(NAME_BONUS);

re: fclean all

.PHONY: all clean fclean re bonus