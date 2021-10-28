#include "mcu_lgt8f328p.h"

#include <stdio.h>

#ifndef GUID0
#define GUID0	(*((volatile unsigned char *)0xF3))
#endif
#ifndef GUID1
#define GUID1	(*((volatile unsigned char *)0xF4))
#endif
#ifndef GUID2
#define GUID2	(*((volatile unsigned char *)0xF5))
#endif
#ifndef GUID3
#define GUID3	(*((volatile unsigned char *)0xF6))
#endif

/*初始化MCU的唯一ID*/
void __init_lgt8f328p_id()
{
    if (!_mcu_id_init)
    {
        char guid1[4];
        char guid2[4];

        uint32_t guid = (uint32_t)&GUID2;
        uint32_t *p;
        p = guid;
        int len = sprintf(guid1, "%X", *p);

        int index=0;
        for(;index<len;index++) {
            lgtx8pMcuIdHexStr[index] = guid1[index];
        }

        guid = (uint32_t)&GUID0;
        p = guid;
        len = sprintf(guid2, "%X", *p);
        for(int i=0;i < len;i++) {
            lgtx8pMcuIdHexStr[i + index] = guid2[i];
        }

        _mcu_id_init = 1;
    }
}


char *get_mcu_sn()
{
    __init_lgt8f328p_id(); 
    return lgtx8pMcuIdHexStr;
}
