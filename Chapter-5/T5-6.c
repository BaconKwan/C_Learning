/*
 * T5-6.c
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
 * 输入成绩，输出等级
 *
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int mark;
	char lv;
	printf("please input a score :");
	scanf("%d", &mark);
	switch (mark / 10){
		case 10:
		case 9:
			lv = 'A';
			break;
		case 8:
			lv = 'B';
			break;
		case 7:
			lv = 'C';
			break;
		case 6:
			lv = 'D';
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			lv = 'E';
			break;
		default:
			lv = '$';
			break;
	}

	printf("%d gets %c", mark, lv);

	return 0;
}

