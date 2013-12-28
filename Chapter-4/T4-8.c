/*
 * T4-8.c
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
 * 2013-10-18  求圆周长、圆面积、球表面积、球体积、圆柱体积， r = 1.5, h = 3
 *
 */


#include <stdio.h>
#define PI 3.1416

int main(int argc, char **argv)
{
	float r, h, cp, ca, ba, bv, cv;
	cp = 2 * r * PI;
	ca = r * r * PI;
	ba = 4 * r * r * PI;
	bv = 4.0 / 3.0 * PI * r * r * r;
	cv = ca * h;

	printf("Pls input the radius & height with format \"r,h\" : ");
	scanf("%f,%f", &r, &h);
	cp = 2 * r * PI;
	ca = r * r * PI;
	ba = 4 * r * r * PI;
	bv = 4.0 / 3.0 * PI * r * r * r;
	cv = ca * h;

	printf("Radius is %.2f, Height is %.2f\n", r, h);
	printf("Perimeter of the circle is %.2f\n", cp);
	printf("Area of the circle is %.2f\n", ca);
	printf("Superficial area of the ball is %.2f\n", ba);
	printf("Volume of the ball is %.2f\n", bv);
	printf("Volume of the cylinder is %.2f\n", cv);

	return 0;
}

