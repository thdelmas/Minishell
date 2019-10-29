
#include "osh.h"

static int	sh_check_var(char *str)
{
	str--;
	while (*(++str))
		if (!(ft_isalnum(*(str)) || *str == '_'))
			return (0);
	return (1);
}

void		sh_export(t_osh *sh, t_cmd *cmd)
{
	char	**tmp;
	char	*str;

	tmp = sh->env;
	if (!(cmd->av)[1])
		sh_print_env(sh, cmd);
	else if ((cmd->av)[2] && (cmd->av)[3])
		ft_putendl_fd("setenv : Too many arguments.", 2);
	else
	{
		if (!sh_check_var((cmd->av)[1]))
			ft_putendl_fd("setenv : Variable name must \
				contain alphanumeric characters.", 2);
		else
		{
			if (sh_find_env((cmd->av)[1], sh->env))
			{
				tmp = sh->env;
				sh_var_del(&(sh->env), (cmd->av)[1]);
			}
			str = ft_strjoin((cmd->av)[1], "=");
			sh_var_add(&(sh->env), str, cmd->av[2]);
			free(str);
		}
	}
}
