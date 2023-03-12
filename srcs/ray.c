/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:26:30 by takira            #+#    #+#             */
/*   Updated: 2023/03/12 21:46:17 by takira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	raytrace(const t_scene *scene, const t_ray *eye_ray, t_colorf *out_col)
{
	/*1. 視線方向(eye_ray)の方向でもっとも近い物体を探す。*/
	int						res;
	t_shape					*shape;
	t_intersection_point	intp;
	size_t					i;
	t_colorf				color;

	res = get_nearest_shape(scene, eye_ray, FLT_MAX, 0, &shape, &intp);

	/*視線方向に物体があった場合*/
	if (res)
	{
		/*1. 環境光Laを計算 */
		/*2. 環境光の強さを計算してcolに入れる。 */
		color.r = scene->ambient_illuminance.r * shape->material.ambient_ref.r;
		color.g = scene->ambient_illuminance.g * shape->material.ambient_ref.g;
		color.b = scene->ambient_illuminance.b * shape->material.ambient_ref.b;

		/*3. すべての光源について処理する*/
		i = 0;
		while (i < scene->num_lights)
		{
			/*4. 入射ベクトルを計算する（点光源の場合と平行光源の場合）。*/

			/*5. 拡散反射光を計算してcolに足し合わせる。*/

			/*6. 鏡面反射光を計算してcolに足し合わせる*/

			i++;
		}

		*out_col = color;
		return (1);
	}
	return (0);
}

