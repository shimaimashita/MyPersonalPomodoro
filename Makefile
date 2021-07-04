CC=gcc
FLAGS=-Wall -g
LIBS=-lncurses -lmenu -lpanel
NAME=Pomodoro

$(NAME): MPPmain.c MPPwin.o
	$(CC) $(FLAGS) $^ $(LIBS) -o $@

MPPwin.o: MPPwin.c
	$(CC) $(FLAGS) $^ $(LIBS) -c -o $@

clean: 
	rm *.o
	rm $(NAME)
