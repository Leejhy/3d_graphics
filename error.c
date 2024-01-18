/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:25:06 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/17 21:41:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	args_error(void)
{
	write(2, "invalid number of arguments\n", 28);
	exit(EXIT_FAILURE);
}

void	malloc_failed(void)
{
	write(2, "malloc failed\n", 14);
	exit(EXIT_FAILURE);
}
