/*
 * T5-7.c
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
 * 给一个不多于5位的正整数，要求：
 * 1、求出它是几位数
 * 2、分别输出每一位数字
 * 3、逆序输出各位数字
 *
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int num1, c = 0, num2 = 0;
	scanf("%d", &num1);
	for( ; num1 != 0; num1 /= 10){
		printf("%d ", num1 % 10);
		num2 = 10 * num2 + num1 % 10;
		c++;
	}
	printf("\n%d, %d位数", num2, c);
	return 0;
}

