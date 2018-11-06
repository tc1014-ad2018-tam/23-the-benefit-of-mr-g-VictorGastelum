/*
   This program is designed to sell tickets for a show that will take place on September 26, 2020 for the benefit of Mr. G.

   These are the main functions of the program:
   sell tickets
   save sells data
   and also generate a report that shows:
   Total tickets sold (number of tickets sold)
   Total tickets sold per zone (the user must be able to specify which zone he wants
   report).
   Total income (amount of sales in USD).
   Total income by zone (the user must be able to specify which zone he wants
   report).
   Occupancy rate (local occupancy rate)
   Occupancy rate by area (the user must be able to specify which area he wants
   report). 
   
   Author: Victor Manuel Gastelum Huitzil
   Date: 05/11/18
   e-mail: A01411985@itesm.mx
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"annoyingcode.h" // Here I created a ".h" file to store all the menus, structs and functions

void option(){
	char op;
	
	menu(); // I display the main menu
	scanf("%c",&op); // Ask for the option

	do{
		system("cls"); // Set a pause in the program
	    switch(toupper(op)){
	    	
		    case 'A':
		    	ticket();
		    	system("PAUSE"); // Set a pause in the program
		    break;
		
	        case 'B':
	        	saveData();
			    system("PAUSE"); // Set a pause in the program
	        break;
		
	        case 'C':
	        	report();
	        	system("PAUSE"); // Set a pause in the program
		    break;
		
		    case 'D':
			    printf("\nBye!");
		    break;
		
		    default:
			    printf("\nThat's an invalid option!");
		    break;
	    }
    }while(op!='D');
}

int main(){
	
	option();

return 0;
}
