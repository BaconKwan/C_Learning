/*
 * S4-10.c
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
 * 输入三角形的三边长，求三角形面积
 * 
 */


#include <stdio.h>
#include "math.h"

int main(void){
	
	double a, b, c, s, area;
	//double area;
	
	scanf("%lf,%lf,%lf", &a, &b, &c);
	s = (1.0 / 2) * (a + b + c);
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	
	printf("a=%7.2f,  b=%7.2f,  c=%7.2f,  s=%7.2f\n", a, b, c, s);
	printf("area=%7.2f\n", area);
	
	return 0;
}
