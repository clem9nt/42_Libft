/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 07:35:45 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/28 07:42:15 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** @brief      Return the absolute value of a number.
 **
 ** @param[in]  nb a number.
 ** @return     The absolute value of 'nb'.
 */

int	ft_abs(int nb)
{
	return (nb * ((nb > 0) - (nb < 0)));
}
