// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }
    std::ifstream productList(argv[1]);
    if (!productList) {
        std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
        return 2;
    }
    std::cout << std::fixed << std::setprecision(2);

	// TODO: Define a variable of type vector named "products"
    std::vector<w6::iProduct*> products;    // vector of iProduct pointers

	std::cout << "====================================\n";
	std::cout << "Reading data from the file\n";
	std::cout << "====================================\n";
	{
            int i = 1;
            std::ifstream fin(argv[1]);
            if (fin.is_open()) {
                while (!fin.eof()) {
                    try {//   - Print a message before starting processing a product.
                        std::cout << "Processing record " << i << ": ";
                        // TODO: Read from the file one record at a time and create a product.
                        i++;
                        w6::iProduct* prod = w6::readProduct(fin);
                        //   - Add the product to the vector "products", created above.
                        products.push_back(prod);
                        std::cout << "done!" << std::endl;
                    } // close try
                    catch (std::string msg) {
                        std::cout << msg << std::endl;
                    }
                } // try/catch inside while loop to continue to next record after catching 
            } // close if
	}
	std::cout << "====================================\n";

	std::cout << std::endl;
	std::cout << "====================================\n";
	std::cout << "Printing the content of the vector\n";
	std::cout << "====================================\n";

    double total = 0.0;
	std::cout << "      Product No         Taxable\n";
	std::cout << "------------------------------------\n";
    for (auto i = 0u; i < products.size(); i++) {
        total += products[i]->getPrice();
        std::cout << *products[i];
    }
	std::cout << "------------------------------------\n";
	std::cout << std::setw(22) <<"Total: ";
    std::cout << std::setw(10) << total << std::endl;
	std::cout << "====================================\n";

	return 0;
}
