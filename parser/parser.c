/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:59:12 by bshang            #+#    #+#             */
/*   Updated: 2020/09/20 19:50:48 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_header.h"

int		process_line(char *l, t_scanned *scan)
{
	while (*l)
	{
		if (*l == '\n' || *l == '\f' || *l == '\r' || *l == '\t' || *l == '\v')
			return (1);
		while (*l && !(ft_strchr("RNSWESFC", *l)) && check_f(scan->f_val) < 0)
			return (ERR_FILE);
		if (*l == 'R')
			return (read_res(++l, (scan)->res, (scan)->f_val));
		else if (*l == 'F')
			return (read_colors('F', ++l, (scan)->floor, (scan)->f_val));
		else if (*l == 'C')
			return (read_colors('C', ++l, (scan)->ceiling, (scan)->f_val));
		else if (ft_strncmp(l, "NO", 2) == 0)
			return (read_file_link('N', l, &(scan)->path_no, (scan)->f_val));
		else if (ft_strncmp(l, "SO", 2) == 0)
			return (read_file_link('S', l, &(scan)->path_so, (scan)->f_val));
		else if (ft_strncmp(l, "EA", 2) == 0)
			return (read_file_link('E', l, &(scan)->path_ea, (scan)->f_val));
		else if (ft_strncmp(l, "WE", 2) == 0)
			return (read_file_link('W', l, &(scan)->path_we, (scan)->f_val));
		if (ft_strncmp(l, "S ", 2) == 0)
			return (read_file_link('Z', l, &(scan)->sprite, (scan)->f_val));
		return (check_f(scan->f_val) >= 0 ? read_map(l, scan) : (ERR_FILE));
	}
	return (0);
}

int		process_line_start(char *line, t_scanned *scanned)
{
	int		res;

	if ((res = process_line(line, scanned)) && res < 0)
	{
		free(line);
		return (res);
	}
	free(line);
	return (0);
}

int		read_file(t_head *head, t_scanned *scanned, int fd)
{
	char		*line;
	int			seen;
	int			res;

	line = NULL;
	seen = 0;
	while ((seen = get_next_line(fd, &line)) > 0)
		if ((res = process_line_start(line, scanned)) && res < 0)
			return (res);
	if (seen == 0)
		if ((res = process_line_start(line, scanned)) && res < 0)
			return (res);
	head->scan = scanned;
	return (0);
}

int		scan_file(int ac, char **av, t_head *head)
{
	t_scanned	*scanned;
	int			fd;
	int			res;

	if (!(scanned = (t_scanned*)malloc(sizeof(t_scanned))))
		return (ERR_MEM);
	set_scanned_struct(scanned);
	if ((ac == 3 && check_scrshot_flag(av[2], scanned) == -1)
	|| ac > 3 || ac < 2)
		return (ERR_ARG);
	if (ac == 2 || ac == 3)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0 || check_fname(av[1], fd) < 0)
			return (ERR_OPEN);
		res = read_file(head, scanned, fd);
		close(fd);
		if (res < 0)
			return (res);
		res = convert_raw_to_valid_field(head);
		if (res < 0)
			return (res);
	}
	return (0);
}
