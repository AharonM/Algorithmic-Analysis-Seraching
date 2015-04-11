#ifndef TIMER_H
#define TIMER_H

#include <ctime>

using namespace std;

class Timer
{
	friend ostream &operator<<(ostream &os,Timer obj);
private:
	clock_t start_time;
	clock_t end_time;
	bool flag;
public:
	Timer(): start_time(0),end_time(0),flag(false){}
	void start();
	void end();
	int hours();
	int minutes();
	int seconds();
	int ticks();
};
#endif
