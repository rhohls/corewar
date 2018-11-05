/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:35:45 by swilson           #+#    #+#             */
/*   Updated: 2018/05/18 07:36:18 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c <= 'z') && (c >= 'a')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}
