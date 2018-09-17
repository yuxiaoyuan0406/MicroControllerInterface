// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
/***********************

 * Author:	Yu Xiaoyuan
 * Date:	2018-9-17 23:10:24
 * Email:	yuxiaoyuan0406@hotmail.com

 ***********************/

#pragma once

#include "targetver.h"

//#include <stdio.h>
#include <iostream>
#include <tchar.h>

int findMax(const int argn, const int *val);//寻找数组val中前argn个中最大者，作为返回值返回
int findMin(const int argn, const int *val);//寻找数组val中前argn个中最小者，作为返回值返回
int reline//将数组val的前argn个从大到小排序, 去重之后放入到lined中
(
	const int argn,
	const int *val,
	int *lined
);
void sort//将数组val中的前argn个在lined中对应的位置输出到code数组中
(
	const int argn,
	const int *val,
	const int *lined,
	int *code
);


// TODO: 在此处引用程序需要的其他头文件
