

// 'Encodes' four individual bytes into an int.
int ft_get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Get the red channel.
int ft_get_r(int rgba)
{
    return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int ft_get_g(int rgba)
{
    return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int ft_get_b(int rgba)
{
    return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int ft_get_a(int rgba)
{
    return (rgba & 0xFF);
}
