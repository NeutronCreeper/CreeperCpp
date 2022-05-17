#define TIMESTR

#include<iostream>
#include<ctime>

time_t now=time(0);
tm* CurrentLocalTime=localtime(&now);

inline void refreshTime(){
    now=time(0);
    CurrentLocalTime=localtime(&now);
};
std::string time_str(){
    refreshTime();
    return std::to_string(CurrentLocalTime->tm_year+1900)
    +'-'+std::to_string(CurrentLocalTime->tm_mon+1)
    +'-'+std::to_string(CurrentLocalTime->tm_mday)
    +", "+std::to_string(CurrentLocalTime->tm_hour)
    +':'+std::to_string(CurrentLocalTime->tm_min);
};
const char* time_cstr(){
    return (std::to_string(CurrentLocalTime->tm_year+1900)
    +'-'+std::to_string(CurrentLocalTime->tm_mon+1)
    +'-'+std::to_string(CurrentLocalTime->tm_mday)
    +", "+std::to_string(CurrentLocalTime->tm_hour)
    +':'+std::to_string(CurrentLocalTime->tm_min)).c_str();
};