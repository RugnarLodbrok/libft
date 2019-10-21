int ft_startswith(const char *s, const char *prefix)
{
	if (!s)
		return (0);
	while (*prefix)
	{
		if (!*s)
			return (0);
		if (*prefix++ != *s++)
			return (0);
	}
	return (1);
}
