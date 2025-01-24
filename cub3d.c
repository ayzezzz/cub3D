/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:16 by itulgar           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/01/24 17:12:36 by zayaz            ###   ########.fr       */
=======
/*   Updated: 2025/01/24 15:37:43 by itulgar          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"


int main(int argc, char **argv)
{
    if(argc != 2)
        error_message("Invalid Argumanet!!! 🥺\n");
    file_path_control(argv[1]);
   t_data *data;
    data=(t_data*) ft_calloc(1,sizeof(t_data));
    data->path = argv[1];
    if(!cub_check(data))
        {
            free(data);
            return 0;
        }
    //libx
    printf("çiktim kips");
<<<<<<< Updated upstream
   double_str_free(data->cub_map.map);
   double_str_free(data->cub_map.cpymap);
=======
    
>>>>>>> Stashed changes
   textures_free(data);

   free(data);
   
}
