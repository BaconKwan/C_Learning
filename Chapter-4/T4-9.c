/*
 * T4-9.c
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
 * 输入话是温度，输出摄氏温度
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	float f, c;

	printf("pls input a degree of Fahrenheit: ");
	scanf("%f", &f);
	c = 5.0 / 9 * ( f - 32 );
	printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius.\n", f, c);

	return 0;
}

