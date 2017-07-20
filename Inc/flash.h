/* flash.h */

#ifndef FLASH_H
#define FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f3xx_hal.h"

typedef union _data {
  float f;
  char  s[4];
} float2char;

struct FSU_parameters
{
	uint8_t fsu_id;
};

extern struct FSU_parameters fsu_parameters;

/* Base address of the Flash sectors */
#define ADDR_FLASH_PAGE_0    			((uint32_t)0x08000000)
#define ADDR_FLASH_PAGE_1   		  ((uint32_t)0x08000800)
#define ADDR_FLASH_PAGE_2   		  ((uint32_t)0x08001000)
#define ADDR_FLASH_PAGE_3   		  ((uint32_t)0x08001800)
#define ADDR_FLASH_PAGE_4   		  ((uint32_t)0x08002000)
#define ADDR_FLASH_PAGE_5   		  ((uint32_t)0x08002800)
#define ADDR_FLASH_PAGE_6   		  ((uint32_t)0x08003000)
#define ADDR_FLASH_PAGE_7   		  ((uint32_t)0x08003800)
#define ADDR_FLASH_PAGE_8   		  ((uint32_t)0x08004000)
#define ADDR_FLASH_PAGE_9				  ((uint32_t)0x08004800)
#define ADDR_FLASH_PAGE_10   			((uint32_t)0x08005000)
#define ADDR_FLASH_PAGE_11    		((uint32_t)0x08005800)
#define ADDR_FLASH_PAGE_12    		((uint32_t)0x08006000)
#define ADDR_FLASH_PAGE_13    		((uint32_t)0x08006800)
#define ADDR_FLASH_PAGE_14    		((uint32_t)0x08007000)
#define ADDR_FLASH_PAGE_15    		((uint32_t)0x08007800)
#define ADDR_FLASH_PAGE_16    		((uint32_t)0x08008000)
#define ADDR_FLASH_PAGE_17    		((uint32_t)0x08008800)
#define ADDR_FLASH_PAGE_18    		((uint32_t)0x08009000)
#define ADDR_FLASH_PAGE_19    		((uint32_t)0x08009800)
#define ADDR_FLASH_PAGE_20    		((uint32_t)0x0800A000)
#define ADDR_FLASH_PAGE_21    		((uint32_t)0x0800A800)
#define ADDR_FLASH_PAGE_22    		((uint32_t)0x0800B000)
#define ADDR_FLASH_PAGE_23    		((uint32_t)0x0800B800)
#define ADDR_FLASH_PAGE_24    		((uint32_t)0x0800C000)
#define ADDR_FLASH_PAGE_25    		((uint32_t)0x0800C800)
#define ADDR_FLASH_PAGE_26    		((uint32_t)0x0800D000)
#define ADDR_FLASH_PAGE_27    		((uint32_t)0x0800D800)
#define ADDR_FLASH_PAGE_28    		((uint32_t)0x0800E000)
#define ADDR_FLASH_PAGE_29    		((uint32_t)0x0800E800)
#define ADDR_FLASH_PAGE_30    		((uint32_t)0x0800F000)
#define ADDR_FLASH_PAGE_31    		((uint32_t)0x0800F800)

#define FLASH_USER_PARAMS_START_ADDR  			ADDR_FLASH_PAGE_30

#define FSU_ID_ADDR							(FLASH_USER_PARAMS_START_ADDR)
#define SW_VERSION_MINOR_ADDR		(FLASH_USER_PARAMS_START_ADDR+0x04)
#define SW_VERSION_MAJOR_ADDR		(FLASH_USER_PARAMS_START_ADDR+0x08)


HAL_StatusTypeDef writeParams2Flash(struct FSU_parameters *parameters);
HAL_StatusTypeDef readParametersFromFlash(struct FSU_parameters *parameters);
HAL_StatusTypeDef readDefaultParameters(struct FSU_parameters *parameters);

uint8_t get_fsu_id(void);
void setFirmwareVersion(struct FSU_parameters *parameters);

#ifdef __cplusplus
}
#endif

#endif
