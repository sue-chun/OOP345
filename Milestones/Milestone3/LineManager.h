#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include <deque>
#include <string>
#include <iostream>

#include "Task.h"
#include "CustomerOrder.h"

class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned m_cntCustomerOrder;
public:
	LineManager(const std::string& str, std::vector<Task*>& tsk, std::vector<CustomerOrder>& ord);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};

#endif 
