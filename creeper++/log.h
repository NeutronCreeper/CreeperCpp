#define LOG

#include<fstream>

#ifndef TIMESTR
#include "timestr.h"
#endif

#define debug ((char)0)
#define fatal ((char)1)
#define error ((char)2)
#define warn ((char)3)
#define note ((char)4)
#define info ((char)5)

const char* levels[6]={"Debug","FATAL","ERROR","Warn ","Note ","Info "};
std::ofstream log;
void log_do(){
    log.open("Log.txt",std::ios::app);
    log<<"\n\n\t####Program Log from "<<time_str<<"####\n";
};
void log_end(){
    log<<"\t####Log ended at "<<time_str<<"####\n";
    log.close();
};
void logw(const char lvl,const std::string& msg){
    log<<levels[lvl]<<': '<<msg<<'\n';
};

void fwrite_cstr(const char* route,const char* msg){
    fprintf(fopen(route,"a"),msg);
};