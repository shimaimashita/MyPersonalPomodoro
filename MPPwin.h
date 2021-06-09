#ifndef MPPWIN_H
#define MPPWIN_H

#include <curses.h>
#include <panel.h>
#include <menu.h>

/* structure storing data about an object (object size) */
typedef struct MPPWindowSize {
	unsigned int height;
	unsigned int width;
	unsigned int start_y;
	unsigned int start_x;
} MPPWindowSize;

WINDOW *mpp_create_left_win(const MPPWindowSize *win_size);

WINDOW *mpp_create_right_win(const MPPWindowSize *win_size);

/* create new window with passed parameters */
WINDOW *mpp_create_main_win(const MPPWindowSize *win_size);

/* destroy window by putting white space as border */
void mpp_destroy_win(WINDOW *local_win);



#endif
