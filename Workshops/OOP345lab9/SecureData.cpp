// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 21 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg()+1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes-1] = '\0';
        
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
        //char str[] = {*text};
        
        char * firsthalf = text;
        char * secondhalf = &text[nbytes/2];
        
        //cout << str[nbytes/2] << endl;
        
        std::thread t1(bind(converter, firsthalf, key, nbytes/2, Cryptor()));
        std::thread t2(bind(converter, secondhalf, key, nbytes/2, Cryptor()));

		// TODO: rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
        t1.join();
        t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
            std::ofstream bof(file, std::ios::out|std::ios::binary|std::ios::trunc);
			// TODO: write data into the binary file
			//         and close the file
            bof.write(text, nbytes);  // not -1 
            bof.close();    // apparently is writing to second argument?

		}
	}

	void SecureData::restore(const char* file, char key) {

		// TODO: - read the content of the binary file
        std::ifstream bif(file, std::ios::in|std::ios::binary); // apparently opening encoded file
        
        if(bif) {
            // TODO: - allocate memory here for the file content
            delete [] text;
            
            bif.seekg (0, ios::end);
            nbytes = (int)bif.tellg()+1;    // position of cursor location of bif +1 (0 based)
            text = new char[nbytes];
           // bif >> noskipws; // counts white spaces as valid input
            bif.seekg(ios::beg);
            
            while(bif)
                bif.read(text++, nbytes);    // data member text
            
            *--text = '\0';
            
            bif.close();
            
        }
        nbytes--;  // null byte already included from constructor
		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
