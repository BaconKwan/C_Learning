/*
 * T5-5.c
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
 * y = {x, 2x-1, 3x-11 (x<1, 1<=x<10, x>=10)}， 输入x，输出y
 *
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	float x, y;
	printf("please input the value of x :");
	scanf("%f", &x);
	if(x < 1){
		y = x;
		printf("x = %f, y = x = %f\n", x, y);
	}
	else if(x >= 1 && x< 10){
		y = 2 * x - 1;
		printf("x = %f, y = 2x - 1 = %f\n", x, y);
	}
	else{
		y = 3 * x - 11;
		printf("x = %f, y = 3x - 11 = %f\n", x ,y);
	}

	return 0;
}

