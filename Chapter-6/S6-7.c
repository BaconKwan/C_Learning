/*
 * S6-7.c
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
 * 求Fibonacci数列前40个数。
 *
 */


#include <stdio.h>

int main(void){

	long int f1 = 1, f2 = 1;
	int i;

	for (i = 1; i <= 20; i++){
		printf("%12ld %12ld", f1, f2);
		if (i % 2 == 0)
			printf("\n");
		f1 += f2;
		f2 += f1;
	}

	return 0;
}
