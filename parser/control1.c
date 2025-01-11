/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:01:34 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/11 20:25:37 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void file_path_control(char *argv)
{
    size_t i;
    
    i = ft_strlen(argv) - 1;
    if(argv[i] == 'b' && argv[i -1] == 'u' && argv[i -2] == 'c' && argv[i-3] == '.'){
        if(access(argv,F_OK | R_OK) == 0)
            return;
        else
            error_message("File does not exist or is not readable 🥺\n");        
    }
           
    else
        error_message("File Path Error 🥺\n");
    
}