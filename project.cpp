// ------------------------------------------------------------------
// File name:   project.cpp
// Assign ID:   S02-FINAL
// Author:      amoody Allen Moody
// Due Date:    12/11/2012
// Purpose:    Create a program that can track the status of 30 stadium
//             seats, whether available or sold.
//              
//              
//
//-------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void DisplayAllInfo(int A[], int & SeatsAvailable, int & SeatsTaken);
void ReadArray(int A[], int M, int & N, ifstream & inF); 
void DisplayMenu();
void DisplayAvailableTickets(int A[]);
void PurchaseTickets(int A[]);
void ReturnTicket(int A[]);
void ProgramExit(int A[], ofstream & outF);
const int CAPACITY = 30;
int Seats[CAPACITY] = {'*', '*', '#', '#', '#', '#', '#', '*', '*', '*', '*',
	'*', '*', '*', '*', '#', '#', '#', '*', '*', '*', 
	'*', '*', '*', '*', '#', '#', '#', '#', '#'},
			Seats_size =0;

        char taken = '*';
        char availible = '#';

int SeatsAvailable = 0;
	int SeatsTaken = 0;

	 ifstream inF;
     ofstream outF;

int main()

{
	    const int CAPACITY = 30;
		int Seats[CAPACITY] = {'*', '*', '#', '#', '#', '#', '#', '*', '*', '*', '*',
	'*', '*', '*', '*', '#', '#', '#', '*', '*', '*', 
	'*', '*', '*', '*', '#', '#', '#', '#', '#'}, // This array will hold the data for the seats. A * indicates taken and a # indicates available.
			Seats_size =0;  //

        char taken = '*';
        char availible = '#';
		
    int SeatsAvailable = 0;
	int SeatsTaken = 0;
    int N = 0;    
	    ifstream inF;
        ofstream outF;

         
		
		//-| -----------------------------------------------------------
        //-| 1. Open files.
        //-| -----------------------------------------------------------
		
		
         outF.open ("tickets.out");
		
		//-| -----------------------------------------------------------
        //-| 2. Read 30 values from input file into array Seats.
        //-| -----------------------------------------------------------
		
		
		
		
		//-| -----------------------------------------------------------
        //-| 3. Print copyright.
        //-| -----------------------------------------------------------
	    cout << "---------------------------------------------" << endl;
        cout << "(c) 2012, amoody Allen Moody" << endl; 
        cout << "---------------------------------------------" << endl;

        
		
		 
		//-| -----------------------------------------------------------
        //-| 4. Launch first menu. All functions are linked via DisplayMenu function.
        //-| -----------------------------------------------------------
		DisplayAllInfo(Seats, SeatsAvailable, SeatsTaken);
		
		
		
		
		//-| -----------------------------------------------------------
        //-| 5. Close files.
        //-| -----------------------------------------------------------
		
        outF.close ();
		
		
		
		
		
         return 0;
}





// ------------------------------------------------------------------------
// Function: The first menu with all ticket info.
// ------------------------------------------------------------------------

void DisplayAllInfo(int A[], int & SeatsAvailible, int & SeatsTaken)
{
	
	cout << "STADIUM SEATS: " << endl;
    cout << " # - Seat Available" << endl; 
    cout << " * - Seat Taken" << endl; 
	cout << endl;
	cout << "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" << endl;
	cout << endl;

	for (int k=0; k < CAPACITY; k++)
	{
	
	if (k < 9)
	{
	if (A[k] == '#')
		{ 
			cout << "#" << " ";
			}
		else 
			{   cout << "*" << " ";
		SeatsTaken++;}
	}
	else
	{if (A[k] == '#')
		{ 
			cout << "#" << "  ";
			}
		else 
			{   cout << "*" << "  ";
		SeatsTaken++;}
	}
	
	SeatsAvailable = 30 - SeatsTaken;
	
	
	
	}

	
	cout << endl;
	cout << endl;
	cout << "Number of Seats Taken:  " << SeatsTaken << endl;
	cout << "Number of Seats Available:  " << SeatsAvailable << endl;
	cout << "Seats Available:   ";
	int a = 1;
		for (int t=0; t < CAPACITY; t++)
	{  
	if (A[t] == '#')
	{   
		cout << a << " ";
	  a++;
	}else a++;
		}
	
	DisplayMenu();

}



// ------------------------------------------------------------------------
// Function: Display the menu that comes up until the program is exited.
// ------------------------------------------------------------------------
void DisplayMenu()
{ 
	int MenuChoice;
	cout << endl;
	cout << endl;
	cout << "=============================================" << endl;
	cout << " STADIUM TICKET PURCHASE MENU" << endl;
	cout << "---------------------------------------------" << endl;
	cout << " 1. Display ALL stadium information" << endl;
	cout << " 2. Display Available Tickets" << endl;
	cout << " 3. Purchase Tickets" << endl;
	cout << " 4. Return a ticket" << endl;
	cout << " 5. EXIT" << endl;
	cout << "=============================================" << endl;
	cout << endl;
	cout << "Which option would you like: ";

	cin >> MenuChoice;
	cout << endl;
	 switch(MenuChoice)
	 {
	 case 1: DisplayAllInfo(Seats, SeatsAvailable, SeatsTaken);
		     break;

	 case 2: DisplayAvailableTickets(Seats);
		     break;

	 case 3: PurchaseTickets(Seats);
	         break;

	 case 4: ReturnTicket(Seats);
	         break;

	 case 5: ProgramExit(Seats, outF);
		     break;

	 default: cout << "Invalid option please try again." << endl;
		      DisplayMenu();
			  break;
	 
	 }

}


// ------------------------------------------------------------------------
// Function: Display the seats for which tickets are available.
// ------------------------------------------------------------------------
	 void DisplayAvailableTickets(int A[])
	 {
		 cout << "Seats Available:  ";
	int a = 1;
		for (int t=0; t < CAPACITY; t++)
	{  
	if (A[t] == '#')
	{   
		cout << a << " ";
	  a++;
	}else a++;
		}
	cout << endl;
	DisplayMenu();
	 }


	 
	 
// ------------------------------------------------------------------------
// Function: Read the M integer values in array from an input stream.
// ------------------------------------------------------------------------
      void ReadArray(int A[], int M, int & N, ifstream & inF)
      {  
	     int seatsread =0;
         while ( seatsread < 30)
		 { inF >> A[seatsread];
		  seatsread++;
         }
      }



// ------------------------------------------------------------------------
// Function: Allow user to purchase tickets. 
// ------------------------------------------------------------------------
	  void PurchaseTickets(int A[])
	  {   int c =0;
		  int TicketChoice = 0;
		  int TicketAmount = 0;
		  cout << "How many seats would you like to purchase: ";
		  cin >> TicketAmount;
		  
		  
		 
		  if (TicketAmount > SeatsAvailable)
			  {cout << "Not enough seats available. Only " <<
			  SeatsAvailable << " seats are available." << endl;
		      cout << "Please try again" << endl;
			  PurchaseTickets(Seats);
		  }
		   
		  do{ 
			  cout << endl;
			  cout << "Which seat(s) would you like (Type in -1 to get available seats) : ";
		  cin >> TicketChoice;
		  
		  while (TicketChoice == -1)
		  {
		      cout << endl;
			  cout << "Seats Available:  ";
	           
		        int a = 1;
		      for (int t=0; t < CAPACITY; t++)
	            {  
	          if (A[t] == '#')
	           {   
		         cout << a << " ";
	                 a++;
	               }else a++;
	                	}
           	cout << endl;
		  int b;
		  cout << endl;
		  cout << "Let's try that again. Which seat(s) would you like: ";
		  cin >> b;
		  TicketChoice = b;
		  }
		  
		  TicketChoice--;
		 
		  while (A[TicketChoice] == '*')
		  {
		     
		     cout << endl;
			  cout << "This seat is already taken or not valid, please try again." << endl;
			 cout << endl;
			  cout << "Which seat(s) would you like (" << TicketAmount << " seats left): ";
			 cin >> TicketChoice;
			 TicketChoice--;
		  }
		   
		   A[TicketChoice] = '*';
		    
		    cout << "Seat " << TicketChoice + 1 << " assigned." << endl;
		    c++;
		  
	  } while (c < TicketAmount); 
	  
		   cout << endl;
		   cout << "Seats Available:  ";
	           
		        int a = 1;
		      for (int t=0; t < CAPACITY; t++)
	            {  
	          if (Seats[t] == '#')
	           {   
		         cout << a << " ";
	                 a++;
	               }else a++;
	                	}


        DisplayMenu();
		 
		 

	  }

	  
// ------------------------------------------------------------------------
// Function: Allows user to change status of seat from taken to available.
// ------------------------------------------------------------------------

	  void ReturnTicket(int A[])
	  {
		 int ReturnedTicket;
		  
		  cout << endl;
		  cout << "Which seat would you like to return: ";
		  cin >> ReturnedTicket;
		         ReturnedTicket--;
				 if (A[ReturnedTicket] == '#')
		  {
		     
		     cout << endl;
			 cout << "Invalid seat. Cannot return." << endl;
			 DisplayMenu();
			
		  }
		   else
		   {
			   A[ReturnedTicket] = '#';
		    cout << endl;
		    cout << "Seat " << ReturnedTicket + 1 << " returned." << endl;
		    DisplayMenu();
		   }
		  


	  }

	  
// ------------------------------------------------------------------------
// Function: Exits the program and writes to output file tickets.out
// ------------------------------------------------------------------------

	  void ProgramExit(int A[], ofstream & outF)
{  
	    cout << "Program exiting" << endl;
		cout << endl;
		cout << "---------------------------------------------" << endl;
        cout << "(c) 2012, amoody Allen Moody" << endl; 
        cout << "---------------------------------------------" << endl;
		cout << endl;

	
	for(int t = 0; t < CAPACITY; t++)
    {  
		
       if (A[t] == '#')
		{ 
		     outF << "#" << " ";
			}
		else 
			{   outF << "*" << " ";
		}
		
	}
		
		
}
