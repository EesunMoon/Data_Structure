// header function declaration
#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Guest node structure
typedef struct guest
{
	char name[20]; //Reserver name
	int people_num; //the number of guests
	int total_price; //total price
	int check; //Check_in status
	int day; //length of stay
	struct guest* next; //Pointer to indicate the following address of the node
	struct guest* prev; //Pointer representing the node's former address
}Guest;

// List structure of guest
typedef struct list
{
	Guest* H; //Header (first)
	Guest* T; //Tail (End)
	int len; //the number of guests
}List;

// Hotel Room Node structure
typedef struct room
{
	int num; //Room number
	Guest customer; //guest information
	int type; //type of room
	int full; //Reservation status
}Room;

// a first greeting
void hello()
{
	printf("--------------------------------------------------------------------------------\n");
	printf("\tHello, We're giving you unforgettalbe memories with the best service.\n");
	printf("\t\t\tWe are \'Sejong Smart Hotel\'!!!!\n"); //The hotel is called 'Sejong Smart Hotel'.
	printf("--------------------------------------------------------------------------------\n\n");
}

// A menu to choose whether you are a guest or manager
void mode_menu()
{
	printf("\n--------Select MODE---------\n");
	printf("\t1. Guest\n"); // If you press one, you're a guest.
	printf("\t2. Manager\n"); // If you press two, you are an administrator.
	printf("----------------------------\n\n");
}

// Administrator Only Menu
void manager_menu()
{
	printf("\n-----------------Manager menu------------------\n");
	printf("\t1. Show the current Status of the Room\n"); // See if the room is empty or not.
	printf("\t2. Show the guest list\n"); // I see Guest list.
	printf("\t3. Search Guest\n"); // I'm getting Guest information
	printf("\t4. General Menu\n"); // Reservation, check-in, and check-out services are also available to administrators.
	printf("\t0. Log-out\n"); // Log out of Admin Mode
	printf("-----------------------------------------------\n\n");
}

// General (reservation, check-in, check-out) menu
void general_menu()
{
	printf("\n---------General Menu---------\n");
	printf("\t1: Make a reservation\n");
	printf("\t2: Check-in\n"); 
	printf("\t3: Check-out\n");
	printf("------------------------------\n\n");
}

// menu showing room type
void room_menu()
{
	printf("\n---------Room selection Menu----------\n");
	printf("\t1 : Standard Room\n"); 
	printf("\tStandard room costs $100 per night.\n"); // Shows the price of Standard Room
	printf("\t2 : Suite Room\n");
	printf("\tSuite room costs $150 per night.\n"); // Shows the price of Suite Room
	printf("\t3: VIP Room\n");
	printf("\tVIP room costs $200 per night.\n"); // Shows the price of VIP Room
	printf("--------------------------------------\n\n");
}

// Last greeting after running the program
void bye()
{
	printf("\n--------------------------------------------------------------------\n");
	printf("\tThank you for using the hotel \'Sejong Smart Hotel\'!!\n");
	printf("\t\tI wish you all the best in your future.\n");
	printf("\t\t\tHave a nice day\n");
	printf("--------------------------------------------------------------------\n\n");
}

// a function that initializes a guest's information.
void initGuest(Guest** G)
{
	(*G)->check = 0; // Initial check-in status is 0 (not checked in)
	(*G)->people_num = 0; // Initial number of people is zero.
	(*G)->total_price = 0; // The initial amount is 0 won.
	(*G)->day = 0; // The duration of the stay is zero.
	(*G)->prev = NULL; 
	(*G)->next = NULL; //Initialize pointer to NULL indicating
}

// Header, Tail Initialization and Connection in Guest List
void initList(List** L)
{
	(*L) = (List*)malloc(sizeof(List)); // space allocation of guest lists

	// Allocate Header space to indicate the beginning of the guest list
	(*L)->H = (Guest*)malloc(sizeof(Guest)); 
	// Allocate the tail space to indicate the end of the guest list.
	(*L)->T = (Guest*)malloc(sizeof(Guest)); 

	(*L)->H->prev = NULL; // Header's previous is NULL
	(*L)->T->next = NULL; // Tail next is NULL
	(*L)->H->next = (*L)->T; // Header next connect to Tail
	(*L)->T->prev = (*L)->H; // Tail previous connect to Header

	(*L)->len = 0; // The first length of the list is 0
}

//A function that initializes the information in a hotel room.
void init_room(Room R[][10])
{
	for (int i = 8; i >= 0; i--)
	{
		for (int j = 0; j < 9; j++)
		{
			// store Hotel's room number
			(*(R + i) + j)->num = (i + 1) * 100 + j + 1; 
			// The initial hotel is empty, so Zero
			(*(R + i) + j)->full = 0; 
			// Standard Room is designated as No. 1 (101 to 709)
			(*(R + i) + j)->type = 1; 
			// Suite Room is designated as No. 1 (801 to 809)
			if (i == 7) (*(R + i) + j)->type = 2; 
			// VIP Room is designated as No. 1 (901 to 909)
			else if (i == 8) (*(R + i) + j)->type = 3; 
		}
	}
}

//Find the guest node using its name
Guest* search_guest(List *a, char *search_name)
{
	Guest *p = a->H; // Pointer p acts as a browse through the guest list 

	while (p != a->T) // Execute repeating statement until last in guest list
	{
		// If the guest node has the same name as the one you are looking for,
		if (strcmp(p->name, search_name) == 0) 
			return p; // Returns the address of a node
		p = p->next; // Move to next node
	}

	//Initialize with header if no guest with the entered name exists
	p = a->H; 
	return p; // Return address of header node
}

//Find a room by name
Room* search_room(Room R[][10], char *name)
{
	Room *p = NULL;

	for (int i = 8; i >= 0; i--)
	{
		for (int j = 0; j < 9; j++)
		{
			if (strcmp(R[i][j].customer.name, name) == 0) 
				p = (*(R + i) + j);
		}
	} 
	// If the guest information stored in the room is the same as the name you are looking for,
	//store the room's information in p

	return p; // return address of p
}

//A function that shows whether a room is empty or not.
void show_room(Room R[][10])
{
	printf("\n-----------------------------Room Status-----------------------------\n");
	for (int i = 8; i >= 0; i--)
	{
		if (i == 8)      printf("\tVIP Room\t"); //R[8] is VIP room
		else if (i == 7)   printf("\tSuite Room\t"); // R[7]is Suite Rooms
		else   printf("\tStandard Room\t"); // The rest of the floor is Standard Room

		for (int j = 0; j < 9; j++)
		{
			if (R[i][j].full == 0) // If room is empty
				printf(" %d ", R[i][j].num); // print room number
			else //If room is full
				printf("  X  "); // print X
		}
		printf("\n"); 
	}
	printf("---------------------------------------------------------------------\n\n");
}

// Output guest information entered
void show_info(Guest *g, int room_num)
{
	printf("\n*************Guest Information****************\n");
	printf("\tPerson who made reservation : %s\n", g->name); //Reserver name
	printf("\tThe number of guests : %d\n", g->people_num); //the number of guests

	//room information
	printf("\tRoom number : %d\n", room_num);   //room number
	printf("\tRoom type : ");   // room type
	if (room_num / 100 == 9) printf("VIP\n"); //Romm starting with 9 is VIP Room
	else if (room_num / 100 == 8) printf("Suite\n"); //Room starting with 8 is Suite Room
	else printf("Standard\n"); //The rest of room is Standard room

	printf("\tAccommodation period : %d\n", g->day); //length of stay
	printf("\tTotal Price : $%d\n", g->total_price); //total price

	//check-in status
	printf("\tCheck-in Status : ");
	if (g->check == 0) printf("Still Empty\n"); // if check in is not done
	else if (g->check == 1) printf("Checked in!\n"); // if check in is done

	printf("**********************************************\n\n");
}

// Output guest list
void show_guestlist(List *L, Room R[][10])
{
	Guest *p = L->H; 	p = p->next; // Allow pointer p to show header of guest list
	int show, flag=0, i, j;

	if (p == L->T) { // If there is no guest
		//Informs no customer and ends function
		printf("\n\t\tNo guests!!\n\n");  
		return;
	}
	
	// Selected mode to output
	printf("\n\t1. The whole Guest\n"); printf("\t2. VIP Only\n");
	printf("\t3. Suite Only\n"); printf("\t4. Standard Only\n\n");
	printf("Enter the number : "); scanf("%d", &show); printf("\n");

	// output form
	printf("\n-------------------Guest List-------------------\n\n");
	printf("\tGuest name\tRoom number\n");

	if (show == 1) // If you want to see the total guest list
	{
		while (p != L->T) 
		{	// Execute repeating statement until p points to the end of the guest list
			printf("\t  %s\t\t   %d\n", p->name, (search_room(R, p->name))->num); //print guest information
			p = p->next; //move to the next node
		}
	}
	else if (show == 2) // If you only want to see the VIP guest list
	{
		for (i = 0; i < 9; i++)
		{
			if (R[8][i].full == 1) // if the room is full, guest exists
			{
				//print VIP guest list in order of room number
				printf("\t  %s\t\t   %d\n", R[8][i].customer.name, R[8][i].num); 
				flag = 1; // variables indicating whether or not there are VIP customers
			}
		}
		if (flag == 0) //If there is no VIP customer
			printf("\n\t\tNo VIP Guest!!\n\n");
	}
	else if (show == 3) // If you only want to see the Suite guest list
	{
		for (i = 0; i < 9; i++)
		{
			if (R[7][i].full == 1) // if the room is full, guest exists
			{
				//print Suite guest list in order of room number
				printf("\t  %s\t\t   %d\n", R[7][i].customer.name, R[7][i].num); 
				flag = 1; // variables indicating whether or not there are Suite customers
			}
		}
		if (flag == 0) // If there is no Suite customer
			printf("\n\t\tNo Suite Guest!!\n\n");
	}
	else if (show == 4) //If you only want to see the Standard guest list
	{
		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (R[i][j].full == 1) // if the room is full, guest exists
				{
					//print standard guest list in order of room number
					printf("\t  %s\t\t   %d\n", R[i][j].customer.name, R[i][j].num); 
					flag = 1; // variables indicating whether or not there are Standard customers
				}
			}

		}
		if (flag == 0) // If there is no standard customer
			printf("\n\t\tNo Standard Guest!!\n");
	}

	printf("\n-------------------------------------------------\n\n");
}

//show guest information using name
void show_guestname(Guest *g, Room r[][10])
{
	printf("\n*************Guest Information****************\n");
	printf("\tPerson who made reservation : %s\n", g->name); //Reserver name
	printf("\tThe number of guests : %d\n", g->people_num); //the number of guests

	//room information
	Room *t = search_room(r, g->name);   //search room using name
	printf("\tRoom number : %d\n", t->num);   //room number
	printf("\tRoom type : ");   //room type
	if (t->type == 1) printf("Standard\n");
	else if (t->type == 2) printf("Suite\n");
	else if (t->type == 3) printf("VIP\n");

	printf("\tAccommodation period : %d\n", g->day); //length of stay
	printf("\tTotal Price : $%d\n", g->total_price); //total price

	//check in status
	printf("\tCheck-in Status : ");
	if (g->check == 0) printf("Still Empty\n");
	else if (g->check == 1) printf("Checked in!\n");

	printf("**********************************************\n\n");
}

//show guest information using room number
void show_guest(Room *R)
{
	printf("\n*************Guest Information****************\n");
	printf("\tPerson who made reservation : %s\n", R->customer.name); //Reserver name
	printf("\tThe number of guests : %d\n", R->customer.people_num); //the number of guests

	//room information
	printf("\tRoom number : %d\n", R->num); //room number
	printf("\tRoom type : ");
	if (R->type == 1) printf("Standard\n");
	else if (R->type == 2) printf("Suite\n");
	else if (R->type == 3) printf("VIP\n");   //room type

	printf("\tAccommodation period : %d\n", R->customer.day); //length of stay
	printf("\tTotal Price : $%d\n", R->customer.total_price); //total price

	//check in status
	printf("\tCheck-in Status : ");
	if (R->customer.check == 0) printf("Still Empty\n");
	else if (R->customer.check == 1) printf("Checked in!\n");

	printf("**********************************************\n\n");
}

//Function to verify that the room number entered is correct
int isValid(int room_num)
{
	//Return 1 if correct range
	if ((room_num >= 101 && room_num <= 109) || (room_num >= 201 && room_num <= 209)
		|| (room_num >= 301 && room_num <= 309) || (room_num >= 401 && room_num <= 409)
		|| (room_num >= 501 && room_num <= 509) || (room_num >= 601 && room_num <= 609)
		|| (room_num >= 701 && room_num <= 709) || (room_num >= 801 && room_num <= 809)
		|| (room_num >= 901 && room_num <= 909))
		return 1;
	else return 0; //Return 0 if incorrect range
}


//Add Guest (On Appointment)
void addGuest(List *L, Room R[][10])
{
	int room_num, flag = 0;
	Guest *tmp = L->H; //Pointer to tour guest list
	//Assigning and initializing guest nodes to insert
	Guest *g = (Guest*)malloc(sizeof(Guest)); initGuest(&g); 

	//Reserver name
	while (1) 
	{ //Terminate repeating statements if the content of the booker is entered correctly
		// Reserver name
		while (1)
		{
			printf("Please Enter your Name : "); scanf("%s", g->name); //Enter reserver name

			Guest *dup = search_guest(L, g->name);   //Check for duplicate names

			// Confirm the name of the bookingee 
			//if the name you entered does not overlap with the name of the existing bookingee
			if (dup == L->H) break;
			else // If the name you entered is the same as the name of an existing reservation
			{
				printf("\n\tDuplicated name!\n");
				printf("\tPlease re-enter your name!\n\n"); 
				continue; // re-enter name (ID)
			}
		}

		// accommodation personnel
		while (1)
		{
			printf("How many people are there? "); scanf("%d", &(g->people_num)); //Enter the number of guests
			if (g->people_num >= 4) 
			{ //Maximum capacity is 3 people, and if 4 or more people are entered, re-enter them.
				// Print out the statement that the maximum capacity has been exceeded
				printf("\nThe number of people has been exceeded.\n");
				printf("The maximum number of people is up to three.\n");
				printf("Please re-enter the number of people to stay.\n\n");
				continue;
			}
			else if (g->people_num>0)
				break; // Confirm if 3 or more people are entered
		}

		while(1)
		{
			printf("Please enter the length of stay : "); scanf("%d", &g->day); //Enter length of stay
			if (g->day <=0) // Staying period must be at least one day
			{
				// Output that the guest entry is invalid
				printf("\n\t\tInput Error!\n");
				printf("Staying period must be at least one day!\n");
				printf("Please re-enter the length of stay.\n\n");
				continue;
			}
			else break; // Confirm if entered for more than one day
		}
		g->check = 0; //check-in initial state 0

		//room information
		printf("\nPlease Choose a room form\n"); room_menu(); //show room menu
		show_room(R); //show the current status of room

		while (1)
		{
			printf("Room number : "); scanf("%d", &room_num); //enter room number
			if (isValid(room_num) == 1) //if room number entered is correct
			{
				if (R[(room_num / 100) - 1][(room_num % 100) - 1].full == 1) //if it is not empty
				{
					// Output that a room is reserved
					printf("The Room %d is Full!\n", room_num);
					printf("Please enter another Room number\n\n");
					continue; //let re-enter
				}
				else //if it is empty room
				{
					//price measurement
					if ((room_num / 100) == 9) g->total_price = 200 * g->day;
					else if ((room_num / 100) == 8) g->total_price = 150 * g->day;
					else g->total_price = 100 * g->day;

					break; //exit repeating statement
				}
			}
			else //if room number entered is incorrect
			{
				//Output that the room has been entered incorrectly
				printf("\n\tInvalid room number!\n");
				printf("\tPlease Enter the room number again\n\n");
				continue; // lets re-enter the room number
			}
		}

		show_info(g, room_num); //print information entered

		//Check whether the input is correct or not
		printf("Is the reservation history correct?\n");
		printf("If correct, enter 1. If you want to type again, enter 0. "); scanf("%d", &flag);   printf("\n");

		if (flag == 0) //If re-entering
			continue; //Return to the beginning of the iteration to re-enter from the beginning
		else //If the information entered is correct
		{
			//Entering guest information into the room
			R[(room_num / 100) - 1][(room_num % 100) - 1].customer = *g; 
			//The room status is changed to 1 because it is reserved.
			R[(room_num / 100) - 1][(room_num % 100) - 1].full = 1; 

			//Add Customer Node to Customer List
			while (tmp->next != NULL) //Tmp moved to tail
				tmp = tmp->next;
			g->next = tmp; 
			g->prev = tmp->prev; 
			(tmp->prev)->next = g; 
			tmp->prev = g; 

			L->len++; // Increase the length of the guest list by one.

			break; // End Full Repetition
		}
	}

	// Output a message that the reservation is complete
	printf("\n\tReservation completed!!\n");
	printf("\tThank you for reservation\n\n");
}

//check-in
void check_in(List *L, Room R[][10])
{
	Guest *tmp = L->H; // The tmp points to the header of the guest node.
	int search_num;

	if (tmp->next == L->T) // if the hotle is empty
	{
		printf("\n\tThe Hotel is Empty!!\n\n"); //print Hotel is empty
		return; //function termination
	}

	while (1) 
	{	// Exit repeating statement when the check-in information entered is correct
		// Determines whether to search by name or room number
		printf("\t1. By name\n"); printf("\t2. By Room number\n"); 
		printf("Enter number : "); scanf("%d", &search_num);

		if (search_num == 1) //Find by Name
		{
			char re[20] = "";
			//enter Reserver name
			printf("\nWhat is the name of the person who made the reservation? ");  
			scanf("%s", re); 

			Guest *p = search_guest(L, re); // get guest information using name
			if (p == L->H) //if name entered doesnt existed
			{
				//Notice that the person who made the reservation has no name.
				printf("\n\tYou're not on the reservation list!\n");
				printf("\tPlease check again.\n");
			}
			else if (p->check == 1) //If you have already checked in
				//Notify that you have already checked in
				printf("\n\tYou already checked-in\n"); 
			else //You checked in, and if you're on the reservation list,
			{
				p->check = 1; //Change check-in state to 1
				Room *r = search_room(R, re); // get room information using name
				printf("\n\tCheck-in complete!\n"); //Notify that check-in is complete
				printf("\tThe total price is $%d\n", (r->customer).total_price); //inform total price
				printf("\tYour Room number is %d.\n", r->num); //inform room number
				printf("\n"); 
			}
			break; //exit repeating statement
		}
		else if (search_num == 2) //When inquiring by room number
		{
			int room_num;
			printf("\nEnter the Room number : ");   scanf("%d", &room_num); //enter room number

			if (isValid(room_num) == 1) //if room number entered is correct
			{
				//The room entered is not a reserved number
				if (R[(room_num / 100) - 1][(room_num % 100) - 1].full == 0) 
					printf("\n\tThe room has Empty status!\n"); // Outputs that the room is not a reserved room
				//If the room is already checked in
				else if (R[(room_num / 100) - 1][(room_num % 100) - 1].customer.check == 1) 
					printf("\n\tYou already checked-in!\n"); // Notify that you have already checked in
				else // The room number you entered is a reserved room and is not checked in.
				{
					// Change check-in status to 1
					R[(room_num / 100) - 1][(room_num % 100) - 1].customer.check = 1; 
					printf("\n\tCheck-in complete!\n"); //Notify that check-in is complete
					// Outputs a checked-in room number
					printf("\tYour Room number is %d.\n", R[(room_num / 100) - 1][(room_num % 100) - 1].num); 
					// inform total price
					printf("\tThe total price is $%d\n", R[(room_num / 100) - 1][(room_num % 100) - 1].customer.total_price); 
					printf("\n"); 
				}
				break; //exit repeating statement
			}
			else //if room number entered is incorrect 
			{
				// Notify that the room number has been entered incorrectly
				printf("\n\tInvalid room number!\n");
				printf("\tPlease Enter the room number again\n\n");
				continue; //let them re-enter
			}
		}
		else //if menu number entered is incorrect
		{
			//Notify me that you entered the wrong menu number
			printf("\t\tInput Error!!\n");
			printf("\tPlease Enter search number, again!\n\n");
			continue; //let them re-enter
		}
	}
}

//check-out(delete)
void deleteGuest(List *L, Room R[][10])
{
	//tmp points to the guest node address to check-out, and p points to the header of the guest list
	Guest *tmp, *p = L->H; 
	int room_num;

	if (p->next == L->T) //In case there are no customers at all
	{
		// Inform hotel that there are no guests and end function
		printf("\t\tHotel is empty!\n");
		return;
	}

	while (1) 
	{ //Release guest node and end function if room number is entered correctly
		printf("Please enter the room number : "); scanf("%d", &room_num); //enter room number

		if (isValid(room_num) == 1) //if room number entered is correct
		{
			//When a room is not reserved
			if (R[(room_num / 100) - 1][(room_num % 100) - 1].full == 0)  
				printf("\n\tThe room is already empty!\n"); //Notify that a room is not reserved
			//When the room is booked but not checked in
			else if (R[(room_num / 100) - 1][(room_num % 100) - 1].customer.check == 0) 
				printf("\n\tCheck-in First!\n"); //Let them check in first
			else
			{
				R[(room_num / 100) - 1][(room_num % 100) - 1].full = 0; //Switch to an empty room
				//Store guest node information in tmp
				tmp = search_guest(L, R[(room_num / 100) - 1][(room_num % 100) - 1].customer.name); 
				(tmp->prev)->next = tmp->next; 
				(tmp->next)->prev = tmp->prev; 
				free(tmp); //free tmp
				L->len--; //Reduce the length of the guest list by 1
				printf("\n\tCheck-out complete!\n"); //Notify me that checkout is complete
			}
			break; //function termination
		}
		else //If you enter the wrong room number
		{
			//Notify me that you have entered the wrong room number
			printf("\n\tInvalid room number!\n");
			printf("\tPlease Enter the room number again\n\n");
			continue; //Re-do Repetition
		}
	}
}

int main()
{
	int mode, general, manage_num, search_num, search_roomnum;
	char id[10] = "Eesun1004", pw[7] = "001018"; //Administrator ID & Password Designation
	char id_e[10] = "", pw_e[7] = "", search_name[20] = ""; //ID & Password to be entered

	// Creating and initializing headers, tailing, and initializing guest lists
	List *L; initList(&L);

	//Create & Initialize Hotel Room
	Room hotel[10][10]; init_room(hotel);

	while (1) //End program on 0 input
	{
		//initial greeting
		hello();

		//mode selection
		mode_menu();
		//Enter whether you are manager or guest
		printf("Enter Mode number : ");   scanf("%d", &mode); printf("\n");

		//If you are a guest
		if (mode == 1) 
		{
			general_menu(); //Customer menu output
							//enter menu number
			printf("Select Menu : "); scanf("%d", &general); 
			printf("\n"); 
			if (general == 1) //Reservation function
				addGuest(L, hotel); //add Guest Node
			else if (general == 2) //check-in function
				check_in(L, hotel); 
			else if (general == 3) //check-out function
				deleteGuest(L, hotel); //delete Guest Node
			else //When you enter a number other than the specified menu.
			{
				//Outputs that the input is invalid
				printf("\n\t\tInput Error!!\n");
				printf("\tEnter correct mode number again!!\n\n");
				continue; //Re-do Function
			}
		}

		//If you are an administrator
		else if (mode == 2) 
		{
			//Enter Administrator ID and Password
			printf("\nEnter administrator ID : "); scanf("%s", id_e);
			printf("Enter administrator PW : "); scanf("%s", pw_e);

			if (strcmp(id, id_e) == 0 && strcmp(pw, pw_e) == 0) 
			{	//When you enter your ID and password correctly,
				printf("\n\t\tLog-in!\n"); //You are logged in!

				while (1) // Administrator mode until you enter 0 to log out
				{
					manager_menu(); //Admin menu
					//menu selection
					printf("Select Manager Menu : "); scanf("%d", &manage_num); 

					if (manage_num == 1) //Showing the status of hotel rooms
						show_room(hotel);

					else if (manage_num == 2)  //print guest list
						show_guestlist(L, hotel);

					else if (manage_num == 3) //Customer Inquiry
					{
						if (L->H->next == L->T) //In case there are no guests at the hotel
							printf("\n\t\tNo guest in the Hotel!\n");
						else
						{
							//Enter Query Method
							printf("\t1. By name\n"); printf("\t2. By Room number\n"); 
							printf("Enter number : "); scanf("%d", &search_num);

							if (search_num == 1) //When inquiring by name
							{
								//Check by guest name
								printf("Enter the name of the guest you want to find : "); 
								scanf("%s", search_name);   printf("\n"); 

								// Find the guest node by the name you entered
								Guest *p = search_guest(L, search_name); 

								//If no customer information is available, print no information
								if (p == L->H) printf("\t\tNo information\n"); 
								//Output if customer information is available
								else show_guestname(p, hotel); 
							}
							else if (search_num == 2) 
							{ //When inquiring by room number,
								while (1) 
								{ //Exit repeating statement when room number is entered correctly
									//enter room number
									printf("Enter the Room number : "); scanf("%d", &search_roomnum); 

									if (isValid(search_roomnum) == 1) //if room number entered is correct
									{
										//if the hotel have a reservation
										if (hotel[(search_roomnum / 100) - 1][(search_roomnum % 100) - 1].full == 1) 
											//Outputs information from the booker
											show_guest(&hotel[(search_roomnum / 100) - 1][(search_roomnum % 100) - 1]); 
										else // In case there is no reserved person
											 //Notify that the room is empty
											printf("\nThe Room %d is already Empty!!\n", search_roomnum); 
										break; //exit repeating statement
									}
									else //When the room number entered is invalid
									{
										// Notify that the room number has been entered incorrectly
										printf("\n\tInvalid room number!\n");
										printf("\tPlease Enter the room number again\n\n");
										continue; //Redo Repetition
									}
								}
							}
						}
					}

					else if (manage_num == 4) //Basic features for booking, checking in, and checking out
					{
						general_menu(); //print menu

						printf("Select Menu : "); scanf("%d", &general); //enter the menu number
						if (general == 1) //booking function
							addGuest(L, hotel);
						else if (general == 2) //check-in function
							check_in(L, hotel);
						else if (general == 3) //check-out function
							deleteGuest(L, hotel);
					}

					else if (manage_num == 0) //Exit Admin Mode
					{
						printf("\n\tLog-out Complete!\n"); //You have been logged out!
						break; //exit repeating statement
					}
				}
			}

			else //If the administrator's ID and password do not match, return to the initial screen
			{
				// Notify me that my ID and password are wrong
				printf("\n\tThe administrator's ID and password are incorrect!\n");
				printf("\t\tReturn to Initialization Plane\n\n");
				continue;
			}
		}

		else if (mode == 0)  //If 0 is entered, exit program
			break;

		else //If you enter an incorrect number for Admin & Guests mode.
		{
			// Notify that you entered it incorrectly
			printf("\n\t\tInput Error!!\n");
			printf("\tEnter correct mode number again!!\n\n");
			continue; //Re-run from the beginning of the repeating statement
		}

		//closing greeting
		bye();
	}

	printf("\n\tProgram ended\n"); //Notify me that the program is over
	return 0;
}