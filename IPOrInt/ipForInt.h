//
//  ipForInt.h
//  IPOrInt
//
//  Created by OuYang on 2018/4/8.
//  Copyright © 2018年 OuYang. All rights reserved.
//

#ifndef ipForInt_h
#define ipForInt_h

#include <stdio.h>

/// ip 转 整数 +进制
unsigned int ip_str2int(const char* ip);

/// 整数 转 ip
char * ip_int2str(unsigned int ip, char str[]);


/* 与上面方法一样 */
char *IntToStr(const int ip, char *buf);
unsigned int IPStrToInt(const char *ip);

#endif /* ipForInt_h */
