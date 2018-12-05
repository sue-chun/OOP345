#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <fstream>

#include "Utilities.h"
#include "LineManager.h"

LineManager::LineManager(const std::string& str, std::vector<Task*>& tsk, std::vector<CustomerOrder>& ord) {
	std::vector<std::string> assemblylinefile;	// order of assembly line file 
	std::ifstream ifs(str);		// open the file
	
	std::string lines;

	while (!ifs.eof()) {
		getline(ifs, lines);
		assemblylinefile.push_back(lines);
	}

	for (size_t i = 0; i < tsk.size(); ++i) { // loop through 2nd parameter of this constructor size 
		for (size_t j = 0; j < assemblylinefile.size(); ++j) { // loop through file size (vector assemblylinefile)
			Utilities obj; // to use extractToken
			bool more; 
			size_t pos = 0; 

			std::string first = obj.extractToken(assemblylinefile[j], pos, more);
			if (tsk[i]->getName() == first) {
				std::string second;
				if (more)
					second = obj.extractToken(assemblylinefile[j], pos, more);
				
				for (size_t k = 0; k < tsk.size(); ++k) {
					if (tsk[k]->getName() == second && second != first) {
						tsk[i]->setNextTask(*tsk[k]);
					}
				}
			}
		}
	}

	// AssemblyLine = tsk;		// can I do this?  

	for (size_t i = 0; i < ord.size(); ++i)
		ToBeFilled.push_back(std::move(ord[i]));

	for (size_t i = 0; i < tsk.size(); ++i)
		AssemblyLine.push_back(tsk[i]);

	m_cntCustomerOrder = ToBeFilled.size();

}



bool LineManager::run(std::ostream & os) {

	CustomerOrder temp;
	static int cnt = 0;

	if (!ToBeFilled.empty()) {
		for (size_t i = 0; i < m_cntCustomerOrder; ++i) {
			(*AssemblyLine.back()) += (std::move(ToBeFilled.front()));	// moving customerObject to starting point of AssemblyLine 
			ToBeFilled.pop_front();
		}
	}


	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		(*AssemblyLine[i]).runProcess(os);	// run one cycle of task's process
	}

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (i != 3)		// next task is nullptr - error 
			(*AssemblyLine[i]).moveTask();
		}// moving customerObjects down the line 
		
	
	if (AssemblyLine[3]->getCompleted(temp))
		Completed.push_back(std::move(temp));

	if (Completed.size() == m_cntCustomerOrder)
		return true;
	else
		return false;
}		



void LineManager::displayCompleted(std::ostream & os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

void LineManager::validateTasks() const {
	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->validate(std::cout);
		
	}
}
