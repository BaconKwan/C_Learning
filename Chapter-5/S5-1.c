/*
 * S5-1.c
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
 * 输入两个实数，按代数值由小到大的顺序输出这两个数
 * 
 */


#include <stdio.h>

int main(void){
	
	float a, b, t;
	
	scanf("%f,%f", &a, &b);
	if(a > b){
		t = a;
		a = b;
		b = t;
	}
	
	printf("%5.2f,%5.2f\n", a, b);

	return 0;
}
