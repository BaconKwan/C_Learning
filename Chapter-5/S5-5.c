/*
 * S5-5.c
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
 * 判断某一年是否润年
 *
 */


#include <stdio.h>

int main(void){

	int year, leap;

	scanf("%d", &year);
	//if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0)
				leap = 1;
			else
				leap = 0;
		}
		else
			leap = 1;
	}
	else
		leap = 0;
	if (leap)
		printf("%d is ", year);
	else
		printf("%d is not ", year);
	printf("a leap year.\n");

	return 0;
}
