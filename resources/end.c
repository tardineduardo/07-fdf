// discord harndt


int    end_program(t_win *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->legend.mlx_img);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    mlx_loop_end(data->mlx_ptr);
    free(data->mlx_ptr);
    free(data->fdf->controls);
    free_fdf(data->fdf);
    free(data->fdf);
    free(data);
    exit(0);
}