int ft_pow(int a, int b)
{
	int r;

	r = 1;
	if (b < 0)
		return (0);
	while (b--)
		r *= a;
	return (r);
}
