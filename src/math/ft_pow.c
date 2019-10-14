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

unsigned long long ft_ullpow(unsigned long long a, unsigned long long b)
{
	unsigned long long r;

	r = 1;
	while (b--)
		r *= a;
	return (r);
}

double ft_fpow(double a, int b)
{
	double r;

	r = 1.;
	while (b > 0)
	{
		r *= a;
		b--;
	}
	while (b < 0)
	{
		r /= a;
		b++;
	}
	return (r);
}
