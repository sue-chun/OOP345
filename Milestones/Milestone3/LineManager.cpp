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
}


/*
LineManager::LineManager(const std::string& input, std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders) {


	std::vector<std::string> taskSequence;
	std::ifstream ifs(input);

	do {
		std::string tmp;
		getline(ifs, tmp);
		taskSequence.push_back(tmp);
	} while (!ifs.eof());

	for (size_t i = 0; i < tasks.size(); i++) {
		for (size_t j = 0; j < taskSequence.size(); j++) {
			Utilities obj;
			bool more;
			size_t pos = 0;
			std::string firstHalf = obj.extractToken(taskSequence[j], pos, more);
			if (tasks[i]->getName() == firstHalf) {
				std::string secondHalf;
				if (more)
					secondHalf = obj.extractToken(taskSequence[j], pos, more);
				//secondHalf.pop_back();
				for (size_t k = 0; k < tasks.size(); k++) {
					if (tasks[k]->getName() == secondHalf) {
						tasks[i]->setNextTask(*tasks[k]);
					}
				}
			}
		}
	}

	AssemblyLine = tasks;

	for (size_t i = 0; i < orders.size(); i++) {
		ToBeFilled.push_back(std::move(orders[i]));
	}

	m_cntCustomerOrder = ToBeFilled.size();

}
*/

bool LineManager::run(std::ostream & os) {

	CustomerOrder temp;
	m_cntCustomerOrder = ToBeFilled.size();

	for (size_t i = 0; i < m_cntCustomerOrder; ++i) {
		(*AssemblyLine.back()) += (std::move(ToBeFilled[i]));	// moving customerObject to starting point of AssemblyLine 
	}

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		(*AssemblyLine[i]).runProcess(os);	// run one cycle of task's process
	//	(*AssemblyLine[i]).moveTask();		// moving customerObjects down the line 
	}

	//(*AssemblyLine[4]).runProcess(os);	// run one cycle of task's process
	//(*AssemblyLine[0]).runProcess(os);	// run one cycle of task's process
	//(*AssemblyLine[2]).runProcess(os);	// run one cycle of task's process
	//(*AssemblyLine[1]).runProcess(os);	// run one cycle of task's process
	//(*AssemblyLine[3]).runProcess(os);	// run one cycle of task's process

	/*(*AssemblyLine[4]).moveTask();
	(*AssemblyLine[0]).moveTask();
	(*AssemblyLine[2]).moveTask();
	(*AssemblyLine[1]).moveTask();
	(*AssemblyLine[3]).moveTask();*/

	for (size_t i = 0; i < AssemblyLine.size(); ++i) 
		(*AssemblyLine[i]).moveTask();		// moving customerObjects down the line 


	for (size_t i = 0; i < m_cntCustomerOrder; ++i) {
		Completed.push_back(std::move(temp));
		AssemblyLine.back()->getCompleted(Completed[i]);
		// ToBeFilled.pop_back();
	}

	//if (m_cntCustomerOrder == Completed.size())
	//	return true;
	//else 
		return false;
}		



void LineManager::displayCompleted(std::ostream & os) const {

}

void LineManager::validateTasks() const {
	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->validate(std::cout);
		
	}
}
