/*
 * S3-9.c
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
 * 有符号数据传送给无符号变量
 * 
 */


#include <stdio.h>

int main(void){
	
	unsigned short int a;
	//unsigned a;
	
	int b = -1;
	a = b;
	
	printf("%u, %d\n", a, b);
	
	return 0;
}
