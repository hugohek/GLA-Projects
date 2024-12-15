//Operations.h
#ifndef _OPERATIONS_H
#define _OPERATIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include "Parse.h"


// Helper functions
bool isOperator(const std::string &token);       
int applyOperator(const std::string &op, int a, int b); 
//end of helper functions

void run();  
int postFix(std::vector<std::string> &blip);
int polishExpression(std::string op);     
int updateExpression();

#endif // _OPERATIONS_H
