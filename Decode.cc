// Bikash Thapa

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
		// compute the size of whole bin. file == end - begin
		streampos begin, end;
  		begin = file.tellg();
  		file.seekg (0, ios::end);
  		end = file.tellg();
		// number of encrypted 'Encoded' structs
		int total_encoded = (end - begin) / sizeof(Encoded);
		cout << "Total Messages:\t" << total_encoded << endl;
		// set the cursor at the beginning of bin. file
		file.seekg (0, ios::beg);

		Encoded encoded_data[total_encoded];
		for ( int i=0; i < total_encoded; i++) {
			file.read((char *) &encoded_data[i], sizeof(Encoded));
		}

		int key = 0;
		for ( int i=0; i < total_encoded; i++) {
			key = encoded_data[i].key;
			cout << "Key "<< i+1 << ":\t\t" << key << endl;

			cout << "Message "<< i+1 << ":\t";
			for ( int j=0; j < sizeof(encoded_data[i].message); j++) {
				if ( encoded_data[i].message[j] == (char)0)
					break;
				cout << (char)(encoded_data[i].message[j] - key - j);
			}
			cout << endl << endl;
		}
	}
	file.close();

	return 0;
}
