/*
 * S4-12.c
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
 * 求一元二次方程的根
 * 
 */


#include <stdio.h>
#include <math.h>

int main(void){
	
	float a, b, c, disc, x1, x2, p, q;
	
	scanf("a=%f,b=%f,c=%f", &a, &b, &c);
	disc = b * b - 4 * a * c;
	p = -b / (2 * a);
	q = sqrt(disc) / (2 * a);
	x1 = p + q;
	x2 = p - q;
	
	printf("x1=%5.2f\nx2=%5.2f\n", x1, x2);

	return 0;
}
