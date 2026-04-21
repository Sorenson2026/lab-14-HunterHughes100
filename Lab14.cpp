//This Program that Calculates the average of test scores
//Hunter Hughes 4-21-26
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
int getarraySize();
void getScores(int *scores, int size);
void swap(int&, int&);
void selectionSort(int *scores, int size);
double calcAvg(int *scores, int size);
void displayScores(int *scores, int size, double avg);

//Main function creates the array and calls the functions
int main()
{
	//Variables for size and average
	int size;
	double avg;

	//Gretting
	cout << "Hi, I'm a Program that Calculates the average of test scores!\n" << endl;

	//get size of the Array
	size = getarraySize();
	

	//Create array
	int* scores = new int[size];

	//get Scores and sort them
	getScores(scores, size);
	selectionSort(scores, size);

	//calculate the average
	avg = calcAvg(scores, size);

	//Display the scores and average
	displayScores(scores, size, avg);

	return 0;
}

//This function gets the size of the array from the user
int getarraySize()
{
	//Variable for size of the array
	int size;

	//Get size of the array from the user
	cout << "Please type a integer for the number of test scores: ";
	cin >> size;
	return size;

}

//This function Gets the scores from the user
void getScores(int *scores, int size)
{
	for (int i = 0; i < size; i++)
	{
		//Get score from the user
		cout << "Imput score " << (i + 1) << ": ";
		cin >> *(scores + i);

		//validate that score is positive
		while (*(scores + i) < 0)
		{
			cout << "Please enter a positive score: ";
			cin >> *(scores + i);
		}
	}
}

//This function sorts the vector using a selection sort
void selectionSort(int *scores, int size)
{
	//Create variables for the minimum index and value
	int minIndex, minValue;

	//Loop through the array
	for (int i = 0; i < (size - 1); i++)
	{
		//Set the minimum index and value to the current index and value
		minIndex = i;
		minValue = *(scores + i);

		//Loop through the array to find the minimum value
		for (int j = (i + 1); j < size; j++)
		{
			//If the current value is less than the minimum value, replae minimum value and index
			if (*(scores + j) < minValue)
			{	
			minValue = *(scores + j);
			minIndex = j;
			}
		}
		//Swap the minimum value with the current index value
		swap(*(scores + i), *(scores + minIndex));
	}
}

//This function swaps two integers
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//This function calculates the average of the scores excluding the lowest
double calcAvg(int *scores, int size)
{
	//Variable for the average and total
	double avg;
	int total = 0;

	//Compute total of the scores excluding the lowest score
	for (int i = 1; i < size; i++)
	{
		total += *(scores + i);
	}

	//Calculate the average
	avg = static_cast<double>(total) / (size - 1);
	return avg;
}

//This function displays the scores
void displayScores(int *scores, int size, double avg)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Score " << (i + 1) << ": " << *(scores + i) << endl;
	}

	cout << "The Avegrage of the Scores excluding the loweset is: " << avg << endl;
}