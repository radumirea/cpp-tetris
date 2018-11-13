#pragma once
#include <vector>
#include <algorithm>

class Observer {

public:
	virtual void update() = 0;

};

class Subject {

private:
	std::vector<Observer*> obs;

public:
	void attach(Observer* o) {
		obs.push_back(o);
	};
	void detach(Observer* o) {
		obs.erase(std::remove(obs.begin(), obs.end(), o), obs.end());
	};
	void notify() {
		for (std::vector<Observer*>::const_iterator iter = obs.begin(); iter != obs.end(); ++iter)
			if ((*iter) != 0)
				(*iter)->update();
	};

};
