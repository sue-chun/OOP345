// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 7 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <functional>
#include <iomanip>

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H


namespace w7 {
    template <typename T>
    class DataTable {
        std::vector<T> x_value;
        std::vector<T> y_value;
        int width, decs;
    public:
        DataTable();
        DataTable(std::ifstream&, int, int);
        T mean() const;
        T sigma() const;
        T median() const;
        void regression(T& slope, T& y_intercept) const;
        void display(std::ostream&) const;
        size_t getSize() const;
    };
    
    template <typename T>
    DataTable<T>::DataTable() {
        width = 0;
        decs = 0;
    }
    
    template <typename T>
    DataTable<T>::DataTable(std::ifstream& fs, int w, int d) : DataTable() {
        std::string lines;
        if (fs.is_open()) {
            while (!fs.eof()) {
                getline(fs, lines);
                if (!fs.eof()){
                    T xval = stod(lines.substr(0, lines.find(' ')));
                    x_value.push_back(xval);
                    T yval = stod(lines.substr(lines.find(' ')));
                    y_value.push_back(yval);
                }
            }
        }
        width = w;
        decs = d;
    }   // get first and second values and push them into the corresponding vectors
    
    template <typename T>
    T DataTable<T>::mean() const {
        return std::accumulate(y_value.begin(), y_value.end(), (T)0, [=] (T initial, T total){return initial + total / y_value.size();});
    }   // add y_value values and divide by y_value size
    
    template <typename T>
    T DataTable<T>::sigma() const {     // for standard deviation
        T theMean = mean();
        std::vector<T> meanVec(x_value.size());
        std::transform(y_value.begin(), y_value.end(), meanVec.begin(), [=] (T x) {return (x - theMean) * (x - theMean);});
        // is the Σ of y_value element subtract y_value mean squared
        T meanVecMean = std::accumulate(meanVec.begin(), meanVec.end(), (T)0, [=] (T initial, T total) {return initial + total / (meanVec.size()-1);});
        // is the previous calculation divide by y_value size subtract 1
        return std::sqrt(meanVecMean);
    }
    // is square root of Σ of y_value element subtract y_value mean squared divide by y_value size subtract 1
    
    template <typename T>
    T DataTable<T>::median() const {
        std::vector<T> temp;
        temp = y_value;
        
        std::sort(temp.begin(), temp.end());
        // sort the elements in ascending order
        // std::sort(temp.begin(), temp.end(), [] (T x, T y) {return x > y;});
        // sort the elements in descending order
        if (temp.size() % 2 == 0)
            return temp[(temp.size()/2)];
        else
            return temp[(temp.size()/2)+1];
    }
    // the middle number of the set when sorted in ascending or descending order
    
    template <typename T>
    void DataTable<T>::regression(T& slope, T& y_intercept) const {
        std::vector<T> prod(x_value.size());
        // create vector of size x_value
        T product0 = x_value.size()*(std::inner_product(x_value.begin(), x_value.end(), y_value.begin(), (T)0));
        // size * Σ of x*y
        T product1 = (std::accumulate(x_value.begin(), x_value.end(), (T)0))*(std::accumulate(y_value.begin(), y_value.end(), (T)0));
        // Σ of x_value * Σ of y_value
        std::transform(x_value.begin(), x_value.end(), prod.begin(), [] (T x) { return x*x;});
        T product2 = x_value.size()*(std::accumulate(prod.begin(), prod.end(), (T)0));
        // n * Σ(x^2)
        //T product3 = std::accumulate(x_value.begin(), x_value.end(), (T)0, [] (T x, T y) { std::cout << "this is y: " << y << "this is x:" << x << std::endl; return y*y;});  // this didn't work
        T product3 = std::accumulate(x_value.begin(), x_value.end(), (T)0);
        product3 = product3 * product3;
        // n * Σ(x)^2
        slope = (product0-product1)/(product2-product3);
        y_intercept = ((std::accumulate(y_value.begin(), y_value.end(), (T)0))-slope*(std::accumulate(x_value.begin(), x_value.end(), (T)0)))/x_value.size();
        // Σ of y_value subtract slope * Σ of x_value divided by size of x_value vector 
    }
    
    template <typename T>
    void DataTable<T>::display(std::ostream& os) const {
        os << std::setw(width) << std::setprecision(decs) << "x" << std::setw(width) << std::setprecision(decs) << "y" << std::endl;
        for (size_t a = 0 ;a < x_value.size(); a++) {
            os << std::setw(width) << std::setprecision(decs) << std::fixed << x_value[a] << std::setw(width) << y_value[a] << std::endl;
        }
    }
    
    template <typename T>
    size_t DataTable<T>::getSize() const {
        return x_value.size();
    }
    
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const DataTable<T>& input) {
        input.display(os);
        return os;
    }
}

#endif
