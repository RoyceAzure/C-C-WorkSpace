#ifndef RANDOM_H
#define RANDOM_H
#include<time.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
string random_string(){

  const string c = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string a;
    for(int j = 0; j < 5; ++j){
    	a+=c[rand()% c.size() +0];
	}
  return a;
}




#endif
