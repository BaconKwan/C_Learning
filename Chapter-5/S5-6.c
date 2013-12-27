/*
 * S5-6.c
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
 * 求ax^2+bx+c=0方程的解
 *
 */


#include <stdio.h>
#include <math.h>

int main(void){

	float a, b, c, disc, x1, x2, realpart, imagpart;

	scanf("%f,%f,%f", &a, &b, &c);

	printf("The equation ");
	if (fabs(a) <= 1e-6)
		printf("is not a quadratic.\n");
	else{
		disc = b * b - 4 * a * c;
		if (fabs(disc) <= 1e-6)
			printf("has two equal roots: %8.4f\n", -b / (2 * a));
		else{
			if (disc > 1e-6){
				x1 = (-b + sqrt(disc)) / (2 * a);
				x2 = (-b - sqrt(disc)) / (2 * a);
				printf("has distinct real roots: %8.4f and %8.4f\n", x1, x2);
			}
			else{
				realpart = -b / (2 * a);
				imagpart = sqrt(-disc) / (2 * a);
				printf("has complex roots: \n");
				printf("%8.4f+%8.4fi\n", realpart, imagpart);
				printf("%8.4f-%8.4fi\n", realpart, imagpart);
			}
		}
	}

	return 0;
}
