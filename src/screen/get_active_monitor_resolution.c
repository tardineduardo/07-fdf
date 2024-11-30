#include "../fdf.h"

static void ft_get_active_monitor_res(int32_t *scr_w, int32_t *scr_h)
{
	const GLFWvidmode *vidmode;

	if (!glfwInit())
		ft_perror_exit("Failed to initialize GLFW.\n", errno);
	vidmode = glfwGetVideoMode(ft_get_active_monitor());
	if (!vidmode)
		ft_perror_func_exit("Failed to get vid mode.\n", glfwTerminate, errno);
	*scr_w = vidmode->width;
	*scr_h = vidmode->height;
	glfwTerminate();
}
