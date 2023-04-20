/*
	- Sonne + comme un pipex qu'un minishell
	- implémentation "|" et ";"
	- implémentation de cd (bas de gamme)
*/

int		ft_strlen(char *src)
{
	int ret = 0;
	for (int i = 0; src[i]; i++)
		ret = i;
	return (ret);
}

char	*ft_strdup(char *src)
{
	int len = ft_strlen (src);
	char *ret = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		src[i] = ret[i];
	ret[len] = '\0';
	return (ret);
}

int main(int ac, char *av[], char *envp[])
{
	
}
