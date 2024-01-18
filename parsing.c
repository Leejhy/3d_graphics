/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:24:20 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/17 22:14:24 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*parsing(char *file_name)
{
	int	fd;
	// char	**split_str;

	if (*file_name == '\0')
		error();//
	// split_str = ft_split(file_name);
	ft_split(file_name);//여기 안에서 에러처리됨 다음줄이 실행되면 무조건 에러 아닌것
	fd = open(file_name, O_RDWR);
	//read부분~
}

