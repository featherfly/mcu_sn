#ifdef MCU_INCLUDE_STM32_H

#ifndef MCU_STM32_H
#define MCU_STM32_H

#include <types.h>

#include "mcu.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define HEX_SIZE 2
#define INT_SIZE 4

    /*定义STM32 MCU的类型*/
    typedef enum
    {
        STM32F0MCU,
        STM32F1MCU,
        STM32F2MCU,
        STM32F3MCU,
        STM32F4MCU,
        STM32F7MCU,
        STM32L0MCU,
        STM32L1MCU,
        STM32L4MCU,
        STM32H7MCU
    } STM32_TYPE;

    static uint32_t stm32McuId[3];

    static char stm32McuIdHexStr[25]; // 多一位结束符

    static unsigned char _idBytes[4];
    static char _hexStr[2];

    static int _init = 0;

    static uint32_t stam32IdAddr[] =
        {
            0x1FFFF7AC, /*STM32F0唯一ID起始地址*/
            0x1FFFF7E8, /*STM32F1唯一ID起始地址*/
            0x1FFF7A10, /*STM32F2唯一ID起始地址*/
            0x1FFFF7AC, /*STM32F3唯一ID起始地址*/
            0x1FFF7A10, /*STM32F4唯一ID起始地址*/
            0x1FF0F420, /*STM32F7唯一ID起始地址*/
            0x1FF80050, /*STM32L0唯一ID起始地址*/
            0x1FF80050, /*STM32L1唯一ID起始地址*/
            0x1FFF7590, /*STM32L4唯一ID起始地址*/
            0x1FF0F420  /*STM32H7唯一ID起始地址*/
    };

#ifdef __cplusplus
}
#endif

#endif

#endif