/*
 * S6-9.c
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
 * 求100-200之间的全部素数
 *
 */


#include <stdio.h>
#include <math.h>

int main(void){

	int m, k, i, n = 0;

	for (m = 101; m <= 200; m += 2){
		k = sqrt(m);
		for (i = 2; i <= k; i++)
			if (m % i == 0)
				break;
		if (i >= k + 1){
			printf("%d ", m);
			n += 1;
		}
		if (n % 10 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;
}
