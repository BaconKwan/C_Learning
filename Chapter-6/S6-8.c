/*
 * S6-8.c
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
 * 判断m是否素数
 *
 */


#include <stdio.h>
#include <math.h>

int main(void){

	int m, i, k;

	scanf("%d", &m);
	k = sqrt(m);
	for (i = 2; i <= k; i++)
		if (m % i == 0)
			break;
	if (i > k)
		printf("%d is a prime number.\n", m);
	else
		printf("%d is not a prime number.\n", m);

	return 0;
}
