char *ft_itoa(int n)
{
	char *str;

	//if(!(str = (char *)malloc(sizeof(char) * 2)));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	(str = (char *)malloc(sizeof(char) * 2));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
		//printf("%s\n", str);
	else if (n < 10 && n >= 0)
	{
		str[0] = n + 48;
		str[1] = '\0';
	}
	return (str);
}

