#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int BUFFER_SIZE = 80;

struct Encoded {
	int key;
	char message[BUFFER_SIZE];
};

int main () {
	int key;
	Encoded encoded_data;	
	char input_buffer[BUFFER_SIZE];
	
	ofstream outfile("coded_message.txt", ios::out | ios::binary);
	
	if ( !outfile ) {
		cerr << "Connot open file!" << endl;
		return 2;
	}
	
	cout << "Enter a positive integer for key: ";
	cin >> key;
	
	while ( key > 0 ) {
		cout << "Enter one line of message: ";
		cin.ignore();
		cin.getline(input_buffer, BUFFER_SIZE);
		cerr << "HAVE MESSAGE: " << input_buffer << endl;
		encoded_data.key = key;
		
		for ( int i = 0; i < strlen(input_buffer); i++ ) {
			encoded_data.message[i] = i + key + input_buffer[i];
		} 
		
		outfile.write( (char *) &encoded_data, sizeof(Encoded));
		
		cout << "Enter next key (0 to stop): ";
		
		cin >> key;
		cerr << "HAVE key: " << key << endl << endl;
	}
	
	outfile.close();
	return 0;
}
