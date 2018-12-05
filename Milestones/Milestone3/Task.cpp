#include <utility>

#include "Task.h"

Task::Task() {
	m_pNextTask = nullptr;
}

Task::Task(std::string& str) : Item(str) {
	Task();
}

void Task::runProcess(std::ostream & os) {
	if (m_orders.size() > 0) {
		if (!m_orders.back().getItemFillState(getName())) {
			//std::cout << "is fucked" << std::endl;
			// true means item doesn't exist in the order 
			m_orders.back().fillItem(*this, os);
		}
	}
}

bool Task::moveTask() {
	if (m_orders.size() <= 0) {
		return false;
	}
	else if (m_orders.back().getItemFillState(getName())) {
		// true means all items filled, false otherwise
		*m_pNextTask += (std::move(m_orders.back()));
		m_orders.pop_back();
		return true;
	}
	else
		return false;
}

void Task::setNextTask(Task& tsk) {
	m_pNextTask = &tsk;
}

bool Task::getCompleted(CustomerOrder& ord) {
	if (m_orders.size() <= 0)
		return false;
	else {
		if (m_orders.back().getItemFillState(getName())) {
			ord = std::move(m_orders.back());
			m_orders.pop_back();
			return true;
		}
		else
			return false;
	}
}

void Task::validate(std::ostream& os) {
	if (m_pNextTask == nullptr)
		os << getName() << "--> END OF LINE" << std::endl;
	else
		os << getName() << " --> " << (*m_pNextTask).getName() << std::endl;
}

Task& Task::operator+=(CustomerOrder&& ord) {
	m_orders.push_front(std::move(ord));
	return *this;
}

Task::~Task() {
	m_pNextTask = nullptr;
}
