/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:35:12 by nico              #+#    #+#             */
/*   Updated: 2024/10/16 14:05:27 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffjoin(char *buff, char *tbuff)
{
	char	*dst;

	dst = ft_strjoin(buff, tbuff);
	free(buff);
	return (dst);
}

char	*ft_charge(int fd, char *buffer)
{
	int		r;
	char	*tmp;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp || !buffer)
		return (free(buffer), NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
			return (free(tmp), free(buffer), NULL);
		tmp[r] = '\0';
		buffer = ft_buffjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*ft_clean(char *buff, char *line)
{
	char	*dstbuff;
	size_t	i;
	size_t	linelen;
	size_t	dstlen;

	linelen = ft_strlen(line);
	dstlen = ft_strlen(buff) - linelen;
	if (dstlen == 0)
		return (free(buff), NULL);
	dstbuff = ft_calloc((dstlen + 1), sizeof(char));
	if (!dstbuff)
		return (NULL);
	i = 0;
	while (i < dstlen)
	{
		dstbuff[i] = buff[i + linelen];
		i++;
	}
	free(buff);
	return (dstbuff);
}

char	*ft_next_line(char *buff)
{
	char	*line;
	size_t	i;

	if (!buff || !buff[0])
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i + 1])
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i + 1])
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = buff[i];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_charge(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_next_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL);
	buffer = ft_clean(buffer, line);
	return (line);
}
