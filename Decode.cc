#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 80;

struct Encoded {
	int key;
	char message[BUFFER_SIZE];
};


int main () {
	ifstream file ("coded_message.txt", ios::in | ios::binary);
	if ( file.is_open() ) {
		streampos begin, end, size;
		
		Encoded encoded_data;
		file.seekg(0, ios::beg);
		file.read((char *) &encoded_data, sizeof(Encoded));

		int key = encoded_data.key;
		cout << "Key: " << key << endl;
		cout << "Message: " << endl; 
		for (int i = 0; i < BUFFER_SIZE; i++){
			cout << (char)(encoded_data.message[i]-key-i) << endl;
		}
		
	}
	file.close();
	
	return 0;
}
