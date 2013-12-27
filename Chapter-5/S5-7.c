/*
 * S5-7.c
 *
 * Copyright 2013 BaconKwan <baconkwan@Bacon-PC>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * 运输公司对用户计算运费
 *
 */


#include <stdio.h>

int main(void){

	int c, s;
	float p, w, d, f;

	scanf("%f,%f,%d", &p, &w, &s);
	if (s >= 3000)
		c =12;
	else
		c = s /250;
	switch (c){
		case 0 :
			d = 0;
			break;
		case 1 :
			d = 2;
			break;
		case 2 :
		case 3 :
			d = 5;
			break;
		case 4 :
		case 5 :
		case 6 :
		case 7 :
			d = 8;
			break;
		case 8 :
		case 9 :
		case 10 :
		case 11 :
			d = 10;
			break;
		case 12 :
			d = 15;
			break;
		default :
			break;
	}
	f = p * w * s * (1 - d / 100.0);

	printf("freight=%15.4f\n", f);

	return 0;
}
