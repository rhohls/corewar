/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:12:31 by swilson           #+#    #+#             */
/*   Updated: 2018/06/01 10:25:24 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	if (!s || !(*f))
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
