/*
 * T5-4.c
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
 * 有3个整数a、b、c，由键盘输入，输出其中最大的数
 *
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c;
	printf("Please input 3 number : ");
	scanf("%d,%d,%d", &a, &b, &c);
	if(a > b && a > c)
		printf("Max is : %d\n", a);
	else{
		if(b >= c)
			printf("Max is : %d\n", b);
		else
			printf("Max is : %d\n", c);
	}

	return 0;
}

