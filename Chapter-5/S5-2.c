/*
 * S5-2.c
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
 * 输入3个数a、b、c，要求按由小到大的顺序输出
 * 
 */


#include <stdio.h>

int  main(void){
	
	float a, b, c, t;
	
	scanf("%f,%f,%f", &a, &b, &c);
	if(a > b){
		t = a;
		a = b;
		b = t;
	}
	if(a > c){
		t = a;
		a = c;
		c = t;
	}
	if(b > c){
		t = b;
		b = c;
		c = t;
	}
	
	printf("%5.2f,%5.2f,%5.2f\n", a, b, c);

	return 0;
}
