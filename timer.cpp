#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

#include "timer_exception.h"
#include "timer.h"

using namespace std;

const int
SECONDS_PER_MINUTE = 60,
MINUTES_PER_HOUR = 60;

ostream &operator<<(ostream &os,Timer obj){
	os << setw(2) << setfill('0') << obj.hours() <<":"<< setw(2) << setfill('0') << obj.minutes() <<":"<< setw(2) << setfill('0');
	os << setw(2) << setfill('0') << obj.seconds() <<":"<< setw(2) << setfill('0') << obj.ticks();
	return os;
}

void Timer::start(){
	if(flag==true)
	throw TimerException("'start': Timer already started");
	start_time = clock();
	flag = true;
}

void Timer::end(){
	if(flag==false) 
	throw TimerException("'end': Timer not started");
	end_time = clock();
	flag = false;
}


int Timer::hours(){
    clock_t dur = end_time - start_time;
    if(dur <= 0) 
	throw TimerException("No valid duration");
	int hours = dur / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;
	return hours;
}

int Timer::minutes(){
	clock_t dur = end_time - start_time;
	int minutes = dur / CLOCKS_PER_SEC / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;
	return minutes;
}


int Timer::seconds(){
	clock_t dur = end_time - start_time;
	int seconds = dur / CLOCKS_PER_SEC % SECONDS_PER_MINUTE;
	return seconds;
}


int Timer::ticks(){
	clock_t dur = end_time - start_time;
	int ticks = dur % CLOCKS_PER_SEC;
	return ticks;
}
