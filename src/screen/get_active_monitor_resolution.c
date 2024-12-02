#include "../fdf.h"

static void ft_get_active_monitor_res(t_sizes *size)
{
	const GLFWvidmode	*vidmode;

	if (!glfwInit())
		ft_perror_exit("Failed to initialize GLFW.\n", errno);
	vidmode = glfwGetVideoMode(ft_get_active_monitor());
	if (!vidmode)
		ft_perror_func_exit("Failed to get vid mode.\n", glfwTerminate, errno);
	size->scr_w = vidmode->width;
	size->scr_h = vidmode->height;
	glfwTerminate();
}
