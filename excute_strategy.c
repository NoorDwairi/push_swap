
char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	if (strategy == ADAPTIVE)
		return ("Adaptive");
	return ("Invalid");
}


int	apply_strategy(char *ch, t_config *cfg)
{
	if (ft_strncmp(ch, "--simple", 9) == 0)
		cfg->selected = SIMPLE;
	else if (ft_strncmp(ch, "--medium", 9) == 0)
		cfg->selected = MEDIUM;
	else if (ft_strncmp(ch, "--complex", 10) == 0)
		cfg->selected = COMPLEX;
	else if (ft_strncmp(ch, "--adaptive", 11) == 0)
		cfg->selected = ADAPTIVE;
	else
		return (0);
	return (1);
}