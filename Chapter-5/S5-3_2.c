/*
 * S5-3_2.c
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
 * 有一函数：y = {-1, 0, 1 (x<0, x=0, x>0)}，编写一个程序，输入一个x值，输出y值
 * 
 */


#include <stdio.h>

int main(void){
	
	int x, y;
	
	scanf("%d",&x);
	if (x >= 0)	if (x > 0)	y = 1;
		else y = 0;
	else y = -1;
	
	printf("x=%d,y=%d\n", x, y);

	return 0;
}
