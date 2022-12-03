/*
Program Description: Assignment 2 - A program that allows a user to enter 6 numbers they select for the lotto. They are then given 6 options that each carry out
                        a specific requirement.Each of these 6 different tasks is executed in different functions each having their own specific purpose where
                        the program displays a simple menu where each option of this menu will call a different function that carries out one of the 6 tasks for 
                        the user. The first option allows the user to enter their 6 lotto numbers 1-42 inclusive. The second option allows the user to display the
                        6 lotto numbers they entered. The third option sorts the 6 lotto numbers into ascending order. The fourth option allows the user to compare
                        their 6 lotto numbers to the winning lotto numbers and depending on the amount of matches they get shows their prize(s). The fifth option 
                        allows the user to display the frequency of times the same lotto number is selected regardless of how many times a user inputs new lotto 
                        numbers in the program. The last option allows the user to gracefully terminate the whole program. This program also contains all input
                        validation that is necessary and pointer notation rather than subscript notation to access array elements.

Author: Sean Culleton
Date completed: 10 March 2022
*/
#include <stdio.h>

#include <stdbool.h>

// This #define is used for the array size of the 6 lotto numbers entered
#define sizeLotto 6

// This #define is used for the array of the 1-42 numbers thats being compared to the user input array for the frequency of the numbers
#define matchFreqSize 42

// function signatures for 6 menu functions
int menu1(int *userLotto);

int menu2 (int *userLotto);

int menu3(int *userLotto);

int menu4(int *userLotto);

void menu5(int *userLotto, int *freqMatch);

int menu6(int onOff);

int main()
{
    int menu, onOff;
    int userLotto[sizeLotto];
    int matches[matchFreqSize] = {0};
    bool oneDone = false;

        do
        {

            // user input for menu
            printf("\n\n1. Enter lotto numbers\n\n2. Display lotto numbers\n\n3. Sort lotto numbers in increasing order\n\
                    \n4. Compare lotto numbers to winning numbers\n\n5. Display the frequency of numbers you entered\n\n6. Exit program\n\n");  

            scanf("%d", &menu);

            while (getchar() != '\n')
            {

                printf("\nInvalid entry please try again\n");

            } // end while

            // if is input validation for menu selected outside of 1-6
            if (menu >= 1 && menu <= 6)
            {

                // switch calls each function which each have a task for the menu options
                switch (menu)
                {
                case 1:

                    menu1(userLotto);

                    // setting bool oneDone to true allows options 2-5 now to be done only after option 1 has been completed
                    oneDone = true;

                    break;

                case 2:
                    // this if else ensures option 2 isn't allowed to be entered unless option 1 is entered first using the bool
                    if (oneDone == true)
                    {

                        menu2(userLotto);

                    }
                    else
                    {

                        printf("\nYou must enter your lotto numbers in option 1 first");

                    }
                    break;

                case 3:
                    // this if else ensures option 3 isn't allowed to be entered unless option 1 is entered first using the bool
                    if (oneDone == true)
                    {

                        menu3(userLotto);

                    }
                    else
                    {

                        printf("\nYou must enter your lotto numbers in option 1 first");

                    }
                    break;


                case 4:
                    // this if else ensures option 4 isn't allowed to be entered unless option 1 is entered first using the bool
                    if (oneDone == true)
                    {

                        menu4(userLotto);

                    }
                    else
                    {

                        printf("\nYou must enter your lotto numbers in option 1 first");

                    }
                    break;

                                        
                case 5:
                    // this if else ensures option 2 isn't allowed to be entered unless option 1 is entered first using the bool
                    if (oneDone == true)
                    {

                        menu5(userLotto, matches);

                    }
                    else
                    {

                        printf("\nYou must enter your lotto numbers in option 1 first");

                    }
                    break;

                // option 6 is allowed to be called anytime menu pops up as it should not need option 1 to be entered first
                case 6:

                    onOff = menu6(onOff);

                    break;
                } // end switch

            } // end if 

            // else is also input validation for menu selected outside of 1-6
            else
            {

                printf("\nInvalid option please select options 1-6");

            } // end else
            
        }while(onOff != 0);

    return 0;

} // end main()3


// This function is for the user input of lottery numbers
int menu1(int *userLotto)
{
    register int i, j;
    int duplicateNum = -1; // set to -1 as the if statement below has "duplicateNum < 0"
    int *p;


    // assign pointer to userLotto
    p = userLotto;
    
    // User input for the 6 lotto numbers
    printf("\nPlease enter 6 lotto numbers (1-42 inclusive)\n\n");

    for(i = 0; i < sizeLotto; i++)
    {

        scanf("%d", & *(userLotto + i) );
        
        // input validation for lotto numbers being out of range of 1-42 inclusive
        if ( *(userLotto + i) < 1 || *(userLotto + i) > 42 )
        {

            printf("\nInvalid lotto number please try again\n");

        } // end if 
        
    } // end for

    // input validation for no characters allowed into user input of lotto numbers
    while (getchar() != '\n')
    {

        printf("\nInvalid entry please try again\n");
            
    } // end while

    // input validation for not allowing two numbers being the same number
    for ( i = 0; i < sizeLotto; i++)
    {

        for ( j = i + 1; j < sizeLotto; j++)
        {   

            // if statement to check for duplicate numbers and calling menu1 again to allow users to try again
            if ( ( *(userLotto + i) == ( *(userLotto + j) ) && duplicateNum < 0) )
            { 

                printf("\nNo two numbers the same in lotto, please try again");

                duplicateNum = 1;

                menu1(userLotto);

            } // end if
            
        } // end inner for j
        
    } // end outer for i
    
    return *p;

} // end menu1()


// This function displays the 6 lotto numbers entered by the user
int menu2(int *userLotto)
{
    register int i;


    printf("\nLotto numbers you entered: ");

    // This displays the 6 lotto numbers entered by user
    for ( i = 0; i < sizeLotto; i++)
    {

        printf("%d ", *(userLotto + i) );

    } // end for

} // end menu2()

// This function sorts the 6 lotto numbers entered in ascending order using the BubbleSort algorithim
int menu3(int *userLotto)
{
    register int i, j;
    int a;


    // Sorts array
    for (i = 0; i < sizeLotto; i++) 
        {
 
            for (j = i + 1; j < sizeLotto; j++)
            {
 
                if ( *(userLotto + i) > *(userLotto + j) ) 
                {

                    a =  *(userLotto + i);

                    *(userLotto + i) = *(userLotto + j);

                    *(userLotto + j) = a;

                } // end if
 
            } // end inner for j
 
        } // end outer for i

        // Prints sorted array
        printf("\nThe numbers sorted into ascending order: \n");

        for (i = 0; i < sizeLotto; i++)
        {

            printf("%d ", *(userLotto + i) );
            
        } // end for

} // end menu3

// This function compares user entered numbers to the winning numbers of the lotto
int menu4(int *userLotto)
{   
    int win[sizeLotto] = {1, 3, 5, 7, 9, 11};
    int matched = 0;
    register int i = 0;
    int *p;


    // assign pointer to win array
    p = win;

    // Check to compare matches between user entered numbers and actual winning numbers 
    for(i = 0; i < sizeLotto; i++)
    {

        if( *(userLotto + i) == *p)
        {

            matched++;

        } // end if

        if( *(userLotto + i) == *(p + 1) )
        {

            matched++;

        } // end if

        if( *(userLotto + i) + 2 == *(p + 2) )
        {

            matched++;

        } // end if

        if( *(userLotto + i) == *(p + 3) )
        {

            matched++;

        } // end if

        if( *(userLotto + i) == *(p + 4) )
        {

            matched++;

        } // end if

        if( *(userLotto + i) == *(p + 5) )
        {

            matched++;

        } // end if

    } // end for 

    // Display messages for winnings or no winnings
    if (matched < 3)
    {

        printf("\n\nMatches less than 3\nNOT a winner! Sorry!");

    } // end if
    
    if (matched == 3)
    {

        printf("\n\nMatched 3\nYou won a CINEMA PASS!");

    } // end if
    
    if (matched == 4)
    {

        printf("\n\nMatched 4\nYou won a WEEKEND AWAY!");

    } // end if
    
    if (matched == 5)
    {

        printf("\n\nMatched 5\nYou won a CAR!");

    } // end if
    
    if (matched == 6)
    {

        printf("\n\nMatched all 6\nYou won the JACKPOT!");

    } // end if
    
} // end menu4()


// This function is to display the frequency of times the same number is selected regardless of how many times a user inputs new lotto numbers
void menu5(int *userLotto, int *matches)
{
    register int i, j;
    int *p;
    // This array is the array of numbers being compared to userLotto[sizeLotto]
    int frequency[matchFreqSize] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,
                                22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42};
    

    // assign pointer to frequency array
    p = frequency;

    // This outer for loop is for the run through of frequency[matchFreqSize]
    for ( i = 0; i < matchFreqSize; i++)
    {

        // This inner for is for the run through of userLotto[sizeLotto]
        for (j = 0; j < sizeLotto; j++)
        {

            // this if statement will increment my matches variable if userLotto[element] == frequency[element]
            if ( *(userLotto + j) == *(p + i) )
            {

                matches[i]++;

            } // end if
            
        } // end inner for j

    } // end outer for i
    
    // This for loop is to print the frequencies 
    for ( i = 0; i < matchFreqSize; i++)
    {

        if (matches[i] != 0)
        {

            printf("\nThe frequency %d entered was %d time(s))", *(p + i), matches[i]);

        } // end if
          
    } // end for
    
} // end menu5()


// This function gracefully terminates the whole program
int menu6(int onOff)
{

    printf("\n\nThanks for playing the lotto!\nRemember it could be you!\n");

    // turn off lotto game
    onOff = 0;

    return onOff;

} // end menu6()