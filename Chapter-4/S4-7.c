/*
 * S4-7.c
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
 * 输出双精度数时的有效位数
 * 
 */


#include <stdio.h>

int main(void){
	
	double x, y;
	
	x = 1111111111111.111111111;
	y = 2222222222222.222222222;
	
	printf("%f\n", x+y);

	return 0;
}
