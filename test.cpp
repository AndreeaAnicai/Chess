#include <iostream>
using namespace std;

int main () {
	int coordinates;
	char letter = 'A';
	char max = 'D';
	int letter_as_int = 65;

	cout << "bool letter < max: " << (letter < max) << endl;
	cout << "value max - letter: " << max - letter << endl;
	cout << "bool letter_as_int < max: " << (letter_as_int < max) << endl;
	cout << "value max - letter: " << max - letter_as_int << endl;

	const char* input = "B3";
	char file = input[0];
	cout << "file: " << file << endl;
	char rank = input[1]; 
	cout << "rank: " << rank << endl;

	if (strlen(input) != 2 || file < 'A' || file > 'H' || rank < '1' || rank > '8')  
		cout << "error" << endl;

	else {
		int fileInt = file - 'A';     // Setting the char 'A' to the int 0
        int rankInt = rank - '0' - 1; // Setting the char '1' to the int 0
        cout << "fileInt: " << fileInt << endl;
        cout << "rankInt: " << rankInt << endl;
        *(coordinates[0]) = fileInt;
        *(coordinates[1]) = rankInt;

	cout << "coordinates[0]: " << coordinates[0] << endl;
	cout << "coordinates[1]: " << coordinates[1] << endl;

	}

	return 0;
}