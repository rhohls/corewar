/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:24:12 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/27 16:24:21 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

U_INT		get_prog_size(char *header_at_size)
{
	U_INT	ret;

	ret = *((U_INT *)header_at_size);
	swap_bits((int *)&ret);
	return (ret);
}

int			open_file(char *file_name)
{
	int fd;
	int name_length;

	name_length = ft_strlen(file_name);
	if (ft_strcmp(file_name + (name_length - 4), ".cor") != 0)
		exit_str("Please use only \".cor\" files\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error: There was an error opening file \"%s\"\nReason: ",
			file_name);
		exit_errno();
	}
	return (fd);
}

void		read_header(t_player *player, int fd)
{
	char		header[HEADER_SIZE];
	int			i;
	int			read_ret;

	read_ret = read(fd, header, HEADER_SIZE);
	if (read_ret < HEADER_SIZE)
		exit_errnostr("Error reading file\n");
	if (get_point_int(header) != COREWAR_EXEC_MAGIC)
		exit_str("Error: Magic numbers don't match\n");
	i = 0;
	while (header[i + 4])
	{
		player->name[i] = header[i + 4];
		i++;
	}
	player->program_size = get_prog_size(&header[136]);
	if (player->program_size >= CHAMP_MAX_SIZE || player->program_size <= 0)
		exit_str("Error: Champ size incorrect\n");
}

void		check_progam(t_player *player)
{
	U_INT i;

	i = 0;
	while (i < player->program_size)
	{
		if (player->program[i] != 0)
			return ;
		i++;
	}
	ft_dprintf(2, "Error with player \"%s\"\n", player->name);
	exit(0);
}
