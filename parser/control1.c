/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:01:34 by itulgar           #+#    #+#             */
/*   Updated: 2025/01/20 17:14:10 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void file_path_control(char *argv)
{
    size_t i;
    int fd;
    char *str;
    i = ft_strlen(argv) - 1;
    if(argv[i] == 'b' && argv[i -1] == 'u' && argv[i -2] == 'c' && argv[i-3] == '.'){
        if(access(argv,F_OK | R_OK) == 0){
            {
                fd = open(argv,O_RDONLY);
                if((str=get_next_line(fd)) == NULL)
                    error_message("Empty file 🥺\n");
                free(str);
                return;
            }
        }
        else
            error_message("File does not exist or is not readable 🥺\n");        
    }
           
    else
        error_message("File Path Error 🥺\n");
    
}