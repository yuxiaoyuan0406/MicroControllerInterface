/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/
 
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

//#include <stdio.h>
#include <iostream>
#include <tchar.h>

void count//声明了一个数字数的函数, 输入一个三行的字符数组, 还有五个题目要求的引用
(
	const char words[3][80],
	unsigned int &capital,
	unsigned int &lower,
	unsigned int &numbers,
	unsigned int &space,
	unsigned int &other
);

// TODO: 在此处引用程序需要的其他头文件
