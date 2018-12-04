#ifndef TASK_H
#define TASK_H

#include <deque>
#include <string>
#include <iostream>

#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {
	std::deque<CustomerOrder> m_orders;
	Task *m_pNextTask;
public:
	Task();
	Task(std::string& str);
	void runProcess(std::ostream& os);
	bool moveTask();
	void setNextTask(Task& tsk);
	bool getCompleted(CustomerOrder& ord);
	void validate(std::ostream& os);

	Task& operator=(const Task& src) = delete;
	Task(const Task& src) = delete;
	Task& operator=(Task&& src) = delete;
	Task(Task&& src) = delete;
	Task& operator+=(CustomerOrder&& ord);
	~Task();
};

#endif