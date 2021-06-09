#include "MPPwin.h"

WINDOW *mpp_create_left_win(const MPPWindowSize *win_size)
{
	WINDOW *local_win;
	local_win = newwin(win_size->height, win_size->width / 2,
						win_size->start_y, win_size->start_x);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return local_win;
}

WINDOW *mpp_create_right_win(const MPPWindowSize *win_size)
{
	WINDOW *local_win;
	local_win = newwin(win_size->height, win_size->width / 2,
						win_size->start_y, win_size->width / 2);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return local_win;
}

WINDOW *mpp_create_main_win(const MPPWindowSize *win_size)
{
	WINDOW *local_win;
	local_win = newwin(win_size->height, win_size->width, 
						win_size->start_y, win_size->start_x);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return local_win;
}

void mpp_destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
