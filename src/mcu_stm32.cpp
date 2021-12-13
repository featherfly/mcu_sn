#include "mcu_stm32.h"

#ifdef MCU_INCLUDE_STM32_H

#include "stdlib.h"
#include "numbers.h"
#include "arrays.h"

// #define init_stm32_id(t) \
// stm32McuId[0] = *(uint32_t *)(stam32IdAddr[type]); \
// stm32McuId[1] = *(uint32_t *)(stam32IdAddr[type] + 4); \
// stm32McuId[2] = *(uint32_t *)(stam32IdAddr[type] + 8);  \

void __write_stm32_mcu_id_hex_Str(int index)
{
    int32_to_bytes(stm32McuId[index], _idBytes);
    int offset = (index * INT_SIZE * HEX_SIZE);
    for (size_t i = 0; i < INT_SIZE; i++)
    {
        to_hex(_idBytes[i], _hexStr);
        array_set(stm32McuIdHexStr, _hexStr, offset + i * HEX_SIZE, HEX_SIZE);
    }
}

/*初始化MCU的唯一ID*/
void __init_stm32_id(int type)
{
    if (!_init)
    {
        stm32McuId[0] = *(uint32_t *)(stam32IdAddr[type]);
        stm32McuId[1] = *(uint32_t *)(stam32IdAddr[type] + 4);
        stm32McuId[2] = *(uint32_t *)(stam32IdAddr[type] + 8);

        __write_stm32_mcu_id_hex_Str(0);
        __write_stm32_mcu_id_hex_Str(1);
        __write_stm32_mcu_id_hex_Str(2);

        stm32McuIdHexStr[24] = '\0';

        _init = 1;
    }
}

/*初始化MCU的唯一ID*/
void __init_stm32_id_(STM32_TYPE type)
{
    __init_stm32_id(type);
}

#if defined(CH32_F1)

char *get_mcu_sn()
{
    // ch32f1和stm32f1是一样的地址
    __init_stm32_id(STM32F1MCU); 
    return stm32McuIdHexStr;
}

#elif defined(STM32_F0)

char *get_mcu_sn()
{
    __init_stm32_id(STM32F0MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_F1)

char *get_mcu_sn()
{
    __init_stm32_id(STM32F1MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_F2)

char *get_mcu_sn()
{
    __init_stm32_id(STM32F2MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_F3)

char *get_mcu_sn()
{
    __init_stm32_id(STM32F3MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_F4)

char *get_mcu_sn()
{
    __init_stm32_id(STM32F4MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_F7)

char *get_mcu_sn()
{
    __init_stm32_id(STM32F7MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_L0)

char *get_mcu_sn()
{
    __init_stm32_id(STM32L0MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_L1)

char *get_mcu_sn()
{
    __init_stm32_id(STM32L1MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_L4)

char *get_mcu_sn()
{
    __init_stm32_id(STM32L4MCU);
    return stm32McuIdHexStr;
}

#elif defined(STM32_H7)

char *get_mcu_sn()
{
    __init_stm32_id(STM32H7MCU);
    return stm32McuIdHexStr;
}

#else

char *get_mcu_sn()
{
    return "UNKNOW STM32 MCU";
}

#endif

#endif