
#include <iostream>
#include<cmath>
#include<fstream>
using namespace std;
//random number generater function
int new_random_number() {

	return rand() % 201;
}
//binary search function
int binary_Search(int arry[], int input, int first, int last) {
	while (first <= last) {
		int middle = (first + last) / 2;
		if (arry[middle] == input)
			return middle;
		else if (arry[middle] > input)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return -1;
}
//linear search function
int search_l(int a[],int size, int num) {
	int count = 0;
	while (count < size) {
		if (a[count] == num) {
			return count;

		}
		else if (a[count] != num)
			count++;


	}
	//return -1 if you can't find the value in the array
	if (count == size) {
		return -1; }
	else if (size <= 0) {
		return -2;
	}


}
//bubble sorting function 
int bubble_sort(int ary[], const int ary_size) {

	int num_1=ary_size, size_ , num_2, container;
	for (size_ = 0; size_ < (num_1 - 1); size_++)
	{
		for (num_2 = 0; num_2 < num_1 - size_ - 1; num_2++)
		{
			if (ary[num_2] > ary[num_2 + 1]) // For decreasing order use  
			{
				container = ary[num_2];
				ary[num_2] = ary[num_2 + 1];
				ary[num_2 + 1] = container;
			}
		}
	}
	return 0;
}
//main function
void main() {
	//important functions
	int linear_location=0;
	int binery_location = 0;
	//size of the array we are going to populate
	const int size = 200;
	int input = 0;
	//declaring array to store randome numbers 
	int random_numbers[size];
	//creating  random numbers and populating random_number array
	for (int i = 0; i < 200; i++) {
		random_numbers[i] = new_random_number();
		
	}
	

//sorting our random number array
bubble_sort(random_numbers, size);
//creating our text file
ofstream sorted_numbers;
//opening our random storing text file
sorted_numbers.open("sorted_numbers.txt");
//coping out array to text file and displaying it to CMD
for (int i = 0; i < size - 1; i++) {
	sorted_numbers << random_numbers[i] << endl;
	cout << random_numbers[i] << endl;
}
//closing out text file
sorted_numbers.close();
//asking user to input a value 
cout << "Please enter a random key in keyboard in between 1 and 200 " << endl;
top:
cin >> input;
//linear searching fot the value in our array and saving the index to linear_location variable
linear_location = search_l(random_numbers, size, input);
//binery searching fot the value in our array and saving the index to binery_location variable
binery_location = binary_Search(random_numbers, input, random_numbers[0], random_numbers[size - 1]);

//printing value not found if we cant find the value in our array
if (linear_location==-1||binery_location==-1) {
	cout << "Both Linear search and  Binary search can't find the value your looking for please input another number." << endl;
	goto top;
}
//displaying the location of the value if we find the value we are looking for
else {
	cout << "Key: " << input << " detected at index: " << binery_location <<" by Binary search "<< endl;
	cout <<"Next, Find out the key through sequential Search:" << endl;
	cout << "Key: " << input << " detected at position: " << linear_location << " by Linear search " << endl;

}	system("pause");
}
