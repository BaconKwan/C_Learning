/*
 * S6-6.c
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
 * 用pi/4约等于1-1/3+1/5-1/7...公式求pi的近似值，直到某一项的绝对值小于10e-6为止
 *
 */


#include <stdio.h>
#include <math.h>

int main(void){

	int s = 1;
	float n = 1, t = 1, pi = 0;

	while (fabs(t) > 1e-6){
		pi += t;
		n += 2;
		s = -s;
		t = s / n;
	}
	pi *= 4;

	printf("pi = %.6f\n", pi);

	return 0;
}
