#include <curses.h>
#include <menu.h>
#include <panel.h>
#include "MPPwin.h"

enum {escape_key = 27};

int main()
{
	int main_char;
	initscr();
	/*For Ctrl-C, Ctrl-D ...*/
	cbreak();
	/*Turn off automatic output*/
	noecho();
	/*Handling special keys*/
	keypad(stdscr, 1);
	refresh();

	MPPWindowSize main_window;
	getmaxyx(stdscr, main_window.height, main_window.width);
	main_window.start_y = main_window.start_x = 0;

	WINDOW *mpp_main_window, *mpp_left_window, *mpp_right_window;
	mpp_left_window = mpp_create_left_win(&main_window);
	mpp_right_window = mpp_create_right_win(&main_window);
	while((main_char = getch()) != escape_key) {
		if (main_char == KEY_RESIZE) {
			mpp_destroy_win(mpp_left_window);
			mpp_destroy_win(mpp_right_window);
			getmaxyx(stdscr, main_window.height, main_window.width);
			mpp_left_window = mpp_create_left_win(&main_window);
			mpp_right_window = mpp_create_right_win(&main_window);
		}
	}
	endwin();
	return 0;
}
