//
//  ipForInt.c
//  IPOrInt
//
//  Created by OuYang on 2018/4/8.
//  Copyright © 2018年 OuYang. All rights reserved.
//

#include "ipForInt.h"

/* ip 字符串合法性由调用者保证 */
unsigned int ip_str2int(const char* ip)
{
    unsigned int re = 0;
    unsigned char tmp = 0;
    while (1) {
        if (*ip != '\0' && *ip != '.') {
            tmp = tmp * 10 + *ip - '0';
        } else {
            re = (re << 8) + tmp;
            if (*ip == '\0')
                break;
            tmp = 0;
        }
        ip++;
    }
    return re;
}

/* str长度合法性由调用者保证 */
char * ip_int2str(unsigned int ip, char str[])
{
    unsigned char *val = (unsigned char *)&ip;
    sprintf(str, "%u.%u.%u.%u", val[3], val[2], val[1], val[0]);
    return str;
}


/////////////// 下面方法结果一样////////////////////////////////////
//将整数IP地址转换成字符串IP地址
char *IntToStr(const int ip, char *buf)
{
    sprintf(buf, "%u.%u.%u.%u",
            (unsigned char )*((char *)&ip + 0),
            (unsigned char )*((char *)&ip + 1),
            (unsigned char )*((char *)&ip + 2),
            (unsigned char )*((char *)&ip + 3));
    return buf;
}

//IP字符串转32位int数
unsigned int IPStrToInt(const char *ip)
{
    unsigned uResult = 0;
    int nShift = 24;
    int temp = 0;
    const char *pStart = ip;
    const char *pEnd = ip;
    
    while (*pEnd != '\0')
    {
        while (*pEnd!='.' && *pEnd!='\0')
        {
            pEnd++;
        }
        temp = 0;
        for (pStart; pStart!=pEnd; ++pStart)
        {
            temp = temp * 10 + *pStart - '0';
        }
        
        uResult += temp<<nShift;
        nShift -= 8;
        
        if (*pEnd == '\0')
            break;
        pStart = pEnd + 1;
        pEnd++;
    }
    
    return uResult;
}
