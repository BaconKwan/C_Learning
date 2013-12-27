/*
 * T4-4.c
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
 * 2013-10-18  要输出结果要求，编写程序
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 3, b = 5, c = 5;
	float x = 1.2, y = 2.4, z = -3.6;
	unsigned long u = 51274, n = 128765;
	char c1 = 'a', c2 = 'b';
	
	printf("a= %d  b= %d  c= %d\n", a, b, c);
	printf("x=%6f,y=%6f,z=%6f\n",x ,y, z);
	printf("x+y=%5.2f  y+z=%5.2f  z+x=%5.2f\n", x+y, y+z, z+x);
	printf("u=%6lu  n=%9lu\n", u, n);
	printf("c1=\'%c\' or %d（ASCII）\n", c1, c1);
	printf("c2=\'%c\' or %d（ASCII）\n", c2, c2);
	
	return 0;
}

