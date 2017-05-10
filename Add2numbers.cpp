//
// Purpose:  Read in 2 positive integral numbers with up to MAX_DIGITS digits, add them together
// and display the result.
//
// Note: If result is more than MAX_DIGITS, an INCORRECT result will be displayed. Therefore
//      if reading in 2 numbers with n digits, and the result may be n+1 digits, MAX_DIGITS should
//      be set to n+1 to ensure the correct result will be calculated and displayed.
//
// Author: 
// Date:   
//

#include <iostream>
#include <conio.h>

using namespace std;

// Function prototypes
void readNumber(unsigned short []);
void writeNumber(const unsigned short []);
void addNumbers(const unsigned short [], const unsigned short [], unsigned short []);

//global constants
const unsigned int MAX_DIGITS = 41; // Largest result that can be calculated!

int main()
{
	//Declare variables
	unsigned short number1[MAX_DIGITS];
	unsigned short number2[MAX_DIGITS];
	unsigned short result[MAX_DIGITS];
	// Read in 2 numbers
	cout << "Enter in the first number (max " << MAX_DIGITS << " digits):" << endl;
	readNumber(number1);

	cout << "\nEnter in the second number (max " << MAX_DIGITS << " digits):" << endl;
	readNumber(number2);

	// Add the 2 numbers into result
	addNumbers(number1, number2, result);

	// Display original numbers and answer
	cout << "\nThe result of adding the 2 numbers input is:\n\n ";
	writeNumber(number1);

	cout << "\n+";
	writeNumber(number2);

	// You need to add some missing code here !!!
	cout << "\n ";
	for (int i = 0; i < MAX_DIGITS; i++){
		cout << "=";
	}
	cout << "\n ";
	writeNumber(result);

	cout << '\n' << endl;

	_getch(); // causes execution to pause until char is entered

}

// Function reads in number up to MAX_DIGITS digits in length
void readNumber(unsigned short input[])
{
	unsigned short num[MAX_DIGITS];
	int digits = 0;//total digits
	char singleDigit;
	do{
		//Use code similar to line of code below to input a single digit as a char:
		singleDigit  = cin.get();
		unsigned short nextUnsigned;
		//Make sure the total number of digits read in is less than or equal to MAX_DIGITS.
		if (digits < MAX_DIGITS){
			if (singleDigit  >= '0' && singleDigit  <= '9'){
				//Use code similar to line of code below to convert an ASCII char '0' to '9' to the integer value it represents:
				nextUnsigned = singleDigit - '0';
				//You read the list of digits into an array of MAX_DIGITS. 
				num[digits++] = nextUnsigned;
			}
		}
		//The first digit will be read into num[0] and the second digit num[1] and so on until you hit end of line.
	} while (singleDigit  != '\n' || digits==0); 
	
	// Afterward, leading digits not being used must be set to 0. You will have to do the same for the second number entered
	for (int i = 0; i < (MAX_DIGITS - digits);i++){
		input[i] = 0;
	}
	//After you have read in the list you will have to "push" the list down so that the last digit is in num[MAX_DIGITS-1] and the second 
	//to last digit is in num[MAX_DIGITS-2] and so on
	int counter = 0;
	for (int i = (MAX_DIGITS - digits); i < MAX_DIGITS; i++){
		input[i] = num[counter++];
	}
}

// Function writes out number up to MAX_DIGITS digits in length
void writeNumber(const unsigned short output[]){
	int indexCounter=-1;
	for (int i = 0; i < MAX_DIGITS; i++){
		if (output[i]>0){
			indexCounter = i;
			break;
		}
		else{
			cout << " ";
		}
	}
	for (int i = indexCounter; i < MAX_DIGITS; i++){
		cout << output[i];
	}
}

// Function adds first 2 arrays (num1 and num2) and puts result in 3rd array -> sum
void addNumbers(const unsigned short num1[], const unsigned short num2[], unsigned short sum[])
{
	unsigned short over1=0;
	for (int index = MAX_DIGITS-1; index >=0; index--){
		unsigned short totalSum = num1[index] + num2[index] + over1;
		if (totalSum > 9){//if the sum is greater than 9
			sum[index] = totalSum - 10;
			//carry the one over to the sum of the next digits on the left.
			over1 = 1;
		}
		else{
			over1 = 0;
			sum[index] = totalSum;
		}
	}
}
