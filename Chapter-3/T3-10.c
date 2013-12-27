/*
 * T3-10.c
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
	
	int i, j, m, n;
	
	i = 8;
	j = 10;
	m = ++i;
	n = j++;
	
	printf("%d, %d, %d, %d\n", i, j, m, n);

	return 0;
}

//Result:
//------------------
//9, 11, 9, 10


//------------------
//(program exited with code: 0)
//Press return to continue
