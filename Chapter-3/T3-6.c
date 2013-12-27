/*
 * T3-6.c
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
 * 
 * 
 */


#include <stdio.h>

int main(void){
	
	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = '\101', c5 = '\116';
	
	printf("a%c b%c\tc%c\tabc\n", c1, c2, c3);
	printf("\t \b%c %c\n", c4, c5);
	
	return 0;
}

//Result:
//--------------------
//~ aa bb	cc	abc
//~         A N
//~ 
//~ 
//~ ------------------
//~ (program exited with code: 7)
//~ Press return to continue


