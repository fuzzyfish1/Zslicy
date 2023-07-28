#include <string>
#include <bit>
#include <vector>
#include <iostream>
#include <fstream>

#pragma once

using namespace std;

/*
*	Common code for slicer files
*
*	System: Linux Mint 21.1 x86_64
*	Author: Zain Ali
*	IDE: terminal, nano, gcc 11.3.0
*
*/

#ifndef COMMON_H
#define COMMON_H

#define ASSERT_MSG(val, msg) if(!val) { throw runtime_error(string("\x1b[1;31m") + msg + string("\033[0m")); }

// MIN MAX funcs, biased towards op1
#define MAX(op1, op2) (op1 >= op2) ? op1 : op2;
#define MIN(op1, op2) (op1 <= op2) ? op1 : op2;

#endif
