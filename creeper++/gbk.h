#define GBK
// It works... why?
#include<iostream>
#include <windows.h>

std::string gbk_to_utf8(const std::string& strGBK){
    std::string ans="";
    wchar_t* str1;
    int n=MultiByteToWideChar(CP_ACP,0,strGBK.c_str(),-1,nullptr,0);
    str1= new wchar_t[n];
    MultiByteToWideChar(CP_ACP,0,strGBK.c_str(),-1,str1,n);
    n=WideCharToMultiByte(CP_UTF8,0,str1,-1,nullptr,0,nullptr,nullptr);
    char* str2= new char[n];
    WideCharToMultiByte(CP_UTF8,0,str1,-1,str2,n,nullptr,nullptr);
    ans=str2;
    delete[] str1;
    str1=nullptr;
    delete[] str2;
    str2=nullptr;
    return ans;
};
std::string gbk_to_utf8(const char* strGBK){
    std::string ans="";
    wchar_t* str1;
    int n=MultiByteToWideChar(CP_ACP,0,strGBK,-1,nullptr,0);
    str1= new wchar_t[n];
    MultiByteToWideChar(CP_ACP,0,strGBK,-1,str1,n);
    n=WideCharToMultiByte(CP_UTF8,0,str1,-1,nullptr,0,nullptr,nullptr);
    char* str2= new char[n];
    WideCharToMultiByte(CP_UTF8,0,str1,-1,str2,n,nullptr,nullptr);
    ans=str2;
    delete[] str1;
    str1=nullptr;
    delete[] str2;
    str2=nullptr;
    return ans;
};

std::string utf8_to_gbk(const std::string& strUTF8){
    std::string ans="";
	int len=MultiByteToWideChar(CP_UTF8,0,strUTF8.c_str(),-1,nullptr,0);
	wchar_t* str1= new wchar_t[len+1];
	memset(str1,0,len*2+2);
	MultiByteToWideChar(CP_UTF8,0,strUTF8.c_str(),-1,str1,len);
	len=WideCharToMultiByte(CP_ACP,0,str1,-1,nullptr,0,nullptr,nullptr);
	char* str2= new char[len+1];
	memset(str2,0,len+1);
	WideCharToMultiByte(CP_ACP,0,str1,-1,str2,len,nullptr,nullptr);
	ans=str2;
	delete[] str1;
    str1=nullptr;
	delete[] str2;
    str2=nullptr;
	return ans;
};
std::string utf8_to_gbk(const char* strUTF8){
    std::string ans="";
	int len=MultiByteToWideChar(CP_UTF8,0,strUTF8,-1,nullptr,0);
	wchar_t* str1= new wchar_t[len+1];
	memset(str1,0,len*2+2);
	MultiByteToWideChar(CP_UTF8,0,strUTF8,-1,str1,len);
	len=WideCharToMultiByte(CP_ACP,0,str1,-1,nullptr,0,nullptr,nullptr);
	char* str2= new char[len+1];
	memset(str2,0,len+1);
	WideCharToMultiByte(CP_ACP,0,str1,-1,str2,len,nullptr,nullptr);
	ans=str2;
	delete[] str1;
    str1=nullptr;
	delete[] str2;
    str2=nullptr;
	return ans;
};