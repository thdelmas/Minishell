/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:02 by thdelmas          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/03 22:08:59 by thdelmas         ###   ########.fr       */
=======
/*   Updated: 2018/11/29 00:29:10 by thdelmas         ###   ########.fr       */
>>>>>>> f55e20cd47a981f96a27acd69922697c6a13bdef
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
<<<<<<< HEAD
# define BUFF_SIZE 1
=======
# define BUFF_SIZE 2
>>>>>>> f55e20cd47a981f96a27acd69922697c6a13bdef
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_flst
{
	char			**content;
	int				num;
	struct s_flst	*next;
}					t_flst;
#endif
