/*

Name: Daniel Wu
Student ID: C21460524
Programming
Assessment 2 Due: 20th March 2022

Requirements:

Develop a program that will play the Lotto game. The program should allow a user to
enter their 6 selected numbers and give them a set of options, each performing a
specific requirement. You must store the 6 numbers in a 1-Dimensional array.
There are a number of requirements that your program must meet. Your program
must be modularised (i.e., use functions) and each task should be dealt in a separate
function. The program should display a simple menu to the user and each option in
the menu will be implemented by calling a separate function. You must use pointer
notation to access array elements – DO NOT use subscript notation.
The requirements are as follows (each implemented in a separate function):

1. Enter any 6 numbers (1–42 inclusive) from the keyboard. Perform any
necessary validation (error-checking) required (e.g., all numbers must be
different, range 1–42, etc.).

2. Display the contents of the 1-D array containing your lotto numbers that you
entered.

3. Sort the contents of the array in increasing order (i.e., 1st element = smallest
number, 2nd element = 2nd smallest number, etc.). You may use any sorting
algorithm of your choice.

4. Compare your chosen lotto numbers in the 1-D array with the following
winning numbers:
1,3,5,7,9,11 (Winning numbers)
Depending on how many of your chosen numbers match the above winning numbers,
your program should display one of the following messages:
Match 6 Jackpot
Match 5 New car
Match 4 Weekend away
Match 3 Cinema pass

5. Display the frequency of the numbers entered each time the user enters a new
set of numbers (without exiting the program) on the screen. For example, it
might display:
number 1 has been selected x times
number 7 has been selected x times
number 28 has been selected x times
etc.,

6. Exit program

Extra:

• After a function has completed, your program should return to the main menu
and allow the user to select another option.
• The user should only be allowed to select options 2, 3, 4 & 5 only if they have
correctly entered their 6 valid chosen numbers, i.e., option 1. Display
appropriate error messages to handle any errors.

*/

// Header File
#include <stdio.h>

// Array Signatures
#define SIZE 6 // array for number of questions (6)
#define SIZE2 42 // array for (1 - 42)

// Function Signatures
void enter(int *, int *); // Task 1: Enter 6 Lotto Numbers (1 - 42)
void display(int *); // Task 2: Display Lotto Numbers
void increasing(int *); // Task 3: Display Lotto Numbers in Increasing Order
void lotto(int *, int *); // Task 4: Play the Lottery
void frequency(int *); // Task 5: Frequency of Each Number
// Task 6 (Done in Main because function not needed): Terminate the Program

// Main
int main()
{

    int gameStart = 1; // gamestart function
    int lottery = 0; // Condition for the main body do while
    int values[SIZE] = {0}; // Holds User Lotto Numbers entered in
    int lottoNum[SIZE] = {1, 3, 5, 7, 9, 11}; // Winning Lotto Numbers
    int fre[SIZE2 + 1] = {0}; // Frequency counter
    int option; // Choose option for Cases


    do // Do while for looping the game
    {
        do // Do While for looping the menu
        {
            // Menu
            printf("\n1 - Enter 6 of your Chosen Lotto Numbers Between (1-42)"); // Task 1
            printf("\n2 - Display your Chosen Lotto Numbers"); // Task 2
            printf("\n3 - Display Chosen Lotto Numbers in Increasing Order"); // Task 3
            printf("\n4 - Start the Lottery"); // Task 4
            printf("\n5 - Display Frequency of Chosen Lotto Numbers throughout the Game");  // Task 5
            printf("\n6 - Exit program\n"); // Task 6
            scanf("\n%d", &option); // Lotto Number Input

            // Start of menu
            switch (option) // use of switch statement
            {

                case 1: // Option 1
                {

                    enter(values, fre); // Function Part 1 + frequency counter

                    break; // Break is used to stop the case

                } // end case

                case 2: // Option 2
                {
                    
                    // Error Checking if User tries to select options (2-5) before inputting their Lotto Numbers
                    if (*(values) == 0) // If Values = 0 (No Values entered in) it will display the error message and break the case
                    {

                        printf("\nSorry you have to enter your Lotto Numbers first\n");

                        break; // Break is used to stop the case 

                    }

                    display(values); // Function Part 2

                    break; // Break is used to stop the case

                } // end case

                case 3: // Option 3
                {
                    
                    // Error Checking if User tries to select options (2-5) before inputting their Lotto Numbers
                    if (*(values) == 0) // If Values = 0 (No Values entered in) it will display the error message and break the case
                    {

                        printf("\nSorry you have to enter your Lotto Numbers first\n");

                        break; // Break is used to stop the case

                    }

                    increasing(values); // Function Part 3

                    break; // Break is used to stop the case

                } // end case 

                case 4: // Option 4
                {
                    
                    // Error Checking if User tries to select options (2-5) before inputting their Lotto Numbers
                    if (*(values) == 0) // If Values = 0 (No Values entered in) it will display the error message and break the case
                    {

                        printf("\nSorry you have to enter your Lotto Numbers first\n");

                        break; // Break is used to stop the case

                    }

                    lotto(lottoNum, values); // Function Part 4

                    break; // Break is used to stop the case

                } // end case

                case 5: // Option 5
                {
                    
                    // Error Checking if User tries to select options (2-5) before inputting their Lotto Numbers
                    if (*(values) == 0) // If Values = 0 (No Values entered in) it will display the error message and break the case
                    {

                        printf("\nSorry you have to enter your Lotto Numbers first\n");

                        break; // Break is used to stop the case

                    }

                    frequency(fre); // Function Part 5

                    break; // Break is used to stop the case 

                } // end case

                case 6: // Option 6
                {
                    // Task 6 (Done in Main because function not needed): Terminate the Program
                    printf("\nHope you did well!!! Come back SOON!!!"); 

                    return 0; // terminates the program

                } // end case

                default: // error checking if user does not enter any of the (1-6) options
                {

                    printf("\nInvalid Option"); // error checking for wrong input

                    break; // Break is used to stop the case

                } // end default
            
            } // End of Switch Statement

        } while (lottery == 1); // If = 1 Stays in the loop
        
    
    } while (gameStart == 1); // The code will always run if the condtion is equal to 1 as stated here
    

} // End of main

// Start of Functions

void enter(int *values, int *fre) // Function 1: Enter 6 Lotto Numbers (1-42)
{

    int i, j; // i and j for the for loops
    int temp; // temporary variable

    printf("\nPlease Enter Your 6 Lotto Numbers Between (1-42)\n");
    
    // Nested If and For loops for Input and error checking
    for (i = 0; i < SIZE; i++)
    {

        scanf("%d", & *(values + i));
        
        // Error Checking
        if (*(values + i) >= 1 && *(values + i) <= 42)
        {
            for (j = 0; j < i; j++)
            {   

                // Error Checking for same value
                if (*(values + i) == *(values + j))
                {

                    printf("\nSorry you are not allowed to enter the same number (more than ONCE)\n");
                    printf("Lottery will restart\n");

                    return; // Restarts Lottery

                }

            } // end for

        } // end if
        

        // Error Checking for numbers between (1-42)
        else
        {

            printf("\nSorry you are only allowed to enter numbers BETWEEN (1-42)\n");
            printf("Lottery will restart\n");

            return; // Restarts Lottery

        } // end else
        
        // Frequency Counter
        temp = *(values + i); // Temporary variable is = to Values

        *(fre + temp) = *(fre + temp) + 1; // Increments the number using (+ 1)

    } // end for



} // End of Function

//------------------------------------------------------------------------------------------------------------------------------

void display(int *values) // Function 2: Display Lotto Numbers
{

    int i; // for the loop

    printf("\nDisplaying Lotto Numbers\n");
    
    // For Loop for printing out numbers
    for (i = 0; i < SIZE; i++)
    {

        printf("%d ", *(values + i));

    } // end for

} // End of Function

//------------------------------------------------------------------------------------------------------------------------------

void increasing(int *values) // Function 3: Display Lotto Numbers in Increasing Order
{

    int temp; // Temporary Variable
    int i, j; // i and j for loops
    int sort; // sorting variable
    
    // Sorting Algorithm
    for (i = 0; i < SIZE - 1; i++)
    {
        sort = i; // sort initialize to i

        for (j = i + 1; j < SIZE; j++)
        {
            
            // If values[j] is less than values[sort]
            if (*(values + j) < *(values + sort))
            {

                sort = j; // sort then initialize to j

            } // end if
            
        } // end for

        // Sorting with Temporary Varibale
        temp = *(values + sort); // temp = values[sort = i]
        *(values + sort) = *(values + sort); // values[sort = i] = values[sort = i]
        *(values + sort) = *(values + i); // values[sort = i] = values[i]
        *(values + i) = temp; // values[i] = temp

        // Sorting done
        
    } // end for

    printf("\nNumbers in Increasing order\n");
    
    // Printing out sorted values in Increasing order
    for (i = 0; i < SIZE; i++)
    {

        printf("%d ", *(values + i));

    } // end for


} // End of Function

//------------------------------------------------------------------------------------------------------------------------------

void lotto(int *lottoNum, int *values) // Function 4: Play the Lottery
{

    int i, j; // i and j for the loops
    int winNum = 0; // Winning number variable
    
    // Lotto Prizes
    printf("\n---Lottery Prizes---\n");
    printf("6 Matching Numbers: Jackpot\n");
    printf("5 Matching Numbers: New Car\n");
    printf("4 Matching Numbers: Weekend Away\n");
    printf("3 Matching Numbers: Cinema Pass\n");
    printf("1-2 Matching Numbers: Hard Luck\n");
    printf("0 Matching Numbers: You got no Winning Numbers\n");
    
    // Checking for matching numbers loop
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {   

            // If lottoNum[j] is equal to values[i]
            if (*(lottoNum + j) == *(values + i))
            {
                winNum++; // Counting Winning Number
                printf("\nCongratulations!!! You matched a winning number!\n");
                printf("Winning Number = %d | Your Number = %d\n", *(lottoNum + j), *(values + i));
            }
           
        } // end for

    } // end for

    // Comparing Numbers for prizes with if and else if statements
    if (winNum == 0 || winNum == 1 || winNum == 2) // Match is 0,1 or 2
    {
        printf("\nSorry!!! Better Luck next Time :)\n");
    }

    else if (winNum == 3) // if match is 3
    {
        printf("\nCongratulations!!! You won a Cinema Pass\n");
    }

    else if (winNum == 4) // if match is 4
    {
        printf("\nCongratulations!!! You won a trip for a Weekend Away\n");
    }

    else if (winNum == 5) // if match is 5
    {
        printf("\nCongratulations!!! You won a New Car\n");
    }

    else if (winNum == 6) // if match is 6
    {
        printf("\nCONGRATULATIONS!!! YOU WON THE JACKPOT!!!!!!!\n");
    }


} // End of Function

//------------------------------------------------------------------------------------------------------------------------------

void frequency(int *fre) // Function 5: Frequency of Each Number
{

    int i; // i for the loop

    printf("\nFrequency of all the Lotto Numbers is:\n");

    // Note: Counting already done in the first function
    
    // Printing out recurring values
    for (i = 0; i < SIZE2 + 1; i++)
    {   

        // If Frequency is not equal to 0
        if (*(fre + i) != 0)
        {

            printf("\nLotto Number: %d | Frequency: %d\n", i, *(fre + i));

        }

    } // end for

} // End of Function

