#include "../fdf.h"

// /*
// 	mns = monitors 
// 	mc = monitor count 
// 	c_x = cursor x
// 	c_y = cursor y */

static GLFWmonitor *ft_which(GLFWmonitor **mns, int mc, double c_x, double c_y)
{
	int 				xpos;
	int 				ypos;
	int					width;
	int					height;
	int					i;
	const GLFWvidmode	*mode;

	i = 0;
	while (i < mc)
	{
		glfwGetMonitorPos(mns[i], &xpos, &ypos);
		mode = glfwGetVideoMode(mns[i]);
		if (!mode)
			continue;
		width = mode->width;
		height = mode->height;

		if (c_x >= xpos && c_x < xpos + width &&
			c_y >= ypos && c_y < ypos + height)
				return mns[i];
		i++;
	}
	return (NULL);
}



void get_global_cursor_position(double* x, double* y)
{
	Display*	display;
	Window		root;
	Window 		ret_root;
	Window		ret_child;

	display = XOpenDisplay(NULL);
	if (!display)
	{
		fprintf(stderr, "Unable to open X display\n");
		return;
	}
	root = DefaultRootWindow(display);
	int root_x, root_y;
	int win_x, win_y;
	unsigned int mask;
	if (XQueryPointer(display, root, &ret_root, &ret_child, &root_x, &root_y, &win_x, &win_y, &mask)) 
	{
		*x = root_x;
		*y = root_y;
	} else {
		fprintf(stderr, "Failed to query pointer position\n");
	}
	XCloseDisplay(display);
}


GLFWmonitor* ft_get_active_monitor(void)
{
	int					i;
	double				c_x;
	double				c_y;
	int					mc;
	GLFWmonitor			**mns;
	GLFWmonitor			*act_monitor;

	mns = glfwGetMonitors(&mc);
	if (!mns || mc == 0)
		return (glfwGetPrimaryMonitor());

	get_global_cursor_position(&c_x, &c_y);

	act_monitor = ft_which(mns, mc, c_x, c_y);

	if (!act_monitor)
		act_monitor = glfwGetPrimaryMonitor();

	return (act_monitor);	
}



