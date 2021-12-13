#include "mcu.h"

#if defined(MCU_INCLUDE_STM32_H)

#include "mcu_stm32.h"

#elif defined(MCU_INCLUDE_LGT8F_H)

#include "mcu_lgt8f328p.h"

#elif defined(MCU_INCLUDE_H)

#include MCU_INCLUDE_H

#else

// 提示

#endif