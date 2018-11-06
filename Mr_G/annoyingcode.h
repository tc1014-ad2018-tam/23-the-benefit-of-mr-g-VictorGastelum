// This struct will stores all the information of the customer
struct customerInfo{
    char name[30];
    char payment[30];
    bool seat;
    int priceticket;
}seats[400][200];

// Main menu
void menu(){
	printf("A. Sell a ticket\n");
	printf("B. Save sells data\n");
	printf("C. Reports\n");
	printf("D. Exit\n");
	printf("Your option:\n");
}

void reportMenu(){
    printf("1. Total tickets sold\n");
    printf("2. Total tickets sold per zone\n");
    printf("3. Total income\n");
    printf("4. Total income per zone\n");
    printf("5. Occupation rate\n");
    printf("6. Occupation rate per zone\n");
    printf("\nYour option:\n");
}

// These are the prices of the central column
void prices1(){
	printf("\nThese prices are from the central column:\n");
	printf("1. Vip zone       $100\n");
	printf("2. Platinum zone  $90\n");
	printf("3. Gold zone      $70\n");
	printf("4. Silver zone    $55\n");
	printf("5. Green zone     $45\n");
	printf("6. Yellow zone    $40\n");
	printf("7. Red zone       $30\n");
}

// These are the prices of the right and left columns
void prices2(){
	printf("\nThese prices are from the right and left columns:\n");
	printf("1. Sky blue zone  $50\n");
	printf("2. Navy blue zone $35\n");
	printf("3. Deep blue zone $20\n");
}

// Display all the zones
void zones(){
	printf("1. Vip zone\n");
	printf("2. Platinum zone\n");
	printf("3. Gold zone\n");
	printf("4. Silver zone\n");
	printf("5. Green zone\n");
	printf("6. Yellow zone\n");
	printf("7. Red zone\n");
	printf("8. Sky blue zone\n");
	printf("9. Navy blue zone\n");
	printf("10. Deep blue zone\n");
}

// Display the available payment methods
void payment(){
	printf("These are our available payment methods:\n");
	printf("1. Visa\n");
	printf("2. Mastercard\n");
	printf("3. American Express\n");
}

// This void will ask to the user what zone he wants, once the user select the zone it will store the cost of the cost of the ticket
// then it will ask for the wanted seat and all the information to procede with the purchase
void ticket(){
	int zone;
	int row;
	int row1; // This variable store the first row 
	int row2; // This variable store the last row
	int cost; 
	int seat;
	int method;
	
	printf("These are the prices of each zone:\n");
	prices1(); // Display the prices of the central seats
	prices2();  // Display the prices of the left and right seats
	system("PAUSE"); // Set a pause in the program
	system("cls"); // Set a pause in the program
	
    // Here I ask about the desired zone
	zones();
	printf("Select the zone:\n");
	scanf("%i", &zone);
	
	// Depending on the zone it will assign the values for the first and last rows
	// also will assign the cost of the ticket
	switch(zone){
		
   		case 1: // Case for the Vip Zone 
			row1=1;
			row2=5;
			cost=100;
		break;
		
		case 2: // Case for the Platinum Zone 
			row1=6;
			row2=10;
			cost=90;
		break;
	
		case 3: // Case for the Gold Zone 
			row1=11;
			row2=50;
			cost=70;
		break;
	
	    case 4: // Case for the Silver Zone 
			row1=51;
			row2=100;
			cost=55;
		break;
		
		case 5: // Case for the Green Zone 
			row1=101;
			row2=250;
			cost=45;
		break;
		
		case 6: // Case for the Yellow Zone 
			row1=251;
			row2=350;
			cost=40;
		break;
		
		case 7: // Case for the Red Zone 
			row1=351;
			row2=400;
			cost=30;
		break;
		
		case 8: // Case for the Sky Blue Zone 
			row1=1;
			row2=100;
			cost=50;
		break;
		
		case 9: // Case for the Navy Blue Zone 
			row1=101;
			row2=300;
			cost=35;
		break;
		
		case 10:// Case for the Deep blue Zone 
			row1=301;
			row2=400;
			cost=20;
		break;
		
		default:
			printf("Error\n");
		break;
	}
	
	seats[row][seat].priceticket=cost; // Store the cost of the ticket in the struct
	
	// This loop will ask to the user for the desired row depending on the zone selected before
	do {
        printf("Choose a row between %d-%d", row1, row2);
        scanf("%i", &row);
    } while (row<row1 || row>row2);
    
    // This if is for the right and left columns
    if (zone>=7 && zone<=10) {
        
		do {
            printf("Choose a seat between 1-50 or 151-200");
            scanf("%d", &seat);
        }while ((seat<1 || seat>50) && (seat<151 || seat>200));

    }else{
        do{
            printf("Choose a seat between 51-150");
            scanf("%d", &seat);
        }while (seat<51 || seat>150);
    }
    
    // In case that the user input an invalid number
    if(zone>10){
    	printf("That's an invalid number\n");
	}
	
	// Here I ask for the information of the customer	    
	printf("Perfect!. I just need your information to continue with your purchase\n");
	printf("What is your name?:\n");
	fgets(seats[row][seat].name, sizeof(seats[row][seat].name), stdin); // Store the name of the customer in the struct
	
	// Ask the desired payment method
	printf("Select one payment method(if you want to cancel press any other number):\n");
	payment();
	scanf("%i", &method);
	
	// Depending on which payment the user selects, it stores the payment method in a "char"
	if(method>=1 || method<=3){
	    switch(method){
		    case 1:
			   strcpy(seats[row][seat].payment, "Visa");
		    break;
		
		    case 2:
			   strcpy(seats[row][seat].payment, "MasterCard");
		    break;
		
		    case 3:
			   strcpy(seats[row][seat].payment, "American Express");
		    break;
	    }
	    
    }else{
    	printf("Purchase canceled\n");
	}
}


// This void will store all the data that the user input before with a loop
// that save the incomes of the clients and all their information in their respective struct
void saveData(){
	
	printf("Saving all the data...\n");
	
	// Open the file
	FILE*fd;
	fd=fopen("Mr_G_Data.txt", "wb");

    for (int j=0; j<400; j++) {
        for (int i=0; i<200 ; i++) {
            strcpy(seats[j][i].name, "");
            seats[j][i].payment, "";
            seats[j][i].seat=false;


            if(i<50 || i>149){
                if (j<100) {
                    seats[j][i].priceticket=50;
                } else if (j<300) {
                    seats[j][i].priceticket=35;
                } else {
                    seats[j][i].priceticket=20;
                }

            }else{
                if(j<5){
                    seats[j][i].priceticket = 100;
                } else if (j < 10) {
                    seats[j][i].priceticket = 90;
                } else if (j < 50) {
                    seats[j][i].priceticket = 70;
                } else if (j < 100) {
                    seats[j][i].priceticket = 55;
                } else if (j < 250) {
                    seats[j][i].priceticket = 45;
                } else if (j < 350) {
                    seats[j][i].priceticket = 40;
                } else {
                    seats[j][i].priceticket = 30;
                }
            }
        }
    }
    fwrite(&seats, sizeof(seats), 1, fd);
    
    printf("All data has been stored successfully\n");
}

// I tried to do the report part but i didn't find the way to do it 
void report(){
	int op;
	reportMenu();
	printf("Your option: \n");
	scanf("%i", &op);
	
	switch(op){
		case 1:
			
		break;
		
	    case 2:
			
		break;
		
	    case 3:
			
		break;
		
		case 4:
			
		break;
		
		case 5:
			
		break;
		
		case 6:
			
		break;
		
		default:
			
		break;
	}
	
}
