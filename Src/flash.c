/* flash.c */

#include <flash.h>
#include <main.h>

HAL_StatusTypeDef writeFloat2Flash(float param, uint32_t Address);

struct FSU_parameters fsu_parameters;

HAL_StatusTypeDef readParametersFromFlash(struct FSU_parameters *parameters)
{	
	if ( *(uint8_t*)FSU_ID_ADDR == 0xFF) return HAL_ERROR;
	
	parameters->fsu_id = *(uint8_t*)FSU_ID_ADDR;

	return HAL_OK;
}

void setFirmwareVersion(struct FSU_parameters *parameters)
{
	if (*(uint8_t*)SW_VERSION_MINOR_ADDR!=SW_VERSION_MINOR || *(uint8_t*)SW_VERSION_MAJOR_ADDR!=SW_VERSION_MAJOR)
	{
		writeParams2Flash(parameters);
	}
}

uint8_t get_fsu_id(void)
{
	uint8_t id;
	
	if ( *(uint8_t*)FSU_ID_ADDR == 0xFF) id = FSU_ID;
	else id = *(uint8_t*)FSU_ID_ADDR;
	
	return id;
}

HAL_StatusTypeDef readDefaultParameters(struct FSU_parameters *parameters)
{
	parameters->fsu_id = FSU_ID;

	return HAL_OK;
}

HAL_StatusTypeDef writeFloat2Flash(float param, uint32_t Address)
{
	float2char floatData;
	uint8_t count;
	uint32_t data;
	
	floatData.f = param;
	
	data = (floatData.s[0]<<24 & 0xFF000000) | (floatData.s[1]<<16 & 0x00FF0000) |
		(floatData.s[2]<<8 & 0x0000FF00) | (floatData.s[3] & 0x000000FF);
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, (Address + count), data)!=HAL_OK)
	{
		// Error occurred while writing to flash
		return HAL_ERROR;
	}
	
	return HAL_OK;
}

HAL_StatusTypeDef writeParams2Flash(struct FSU_parameters *parameters)
{
	uint32_t pageError = 0x0;
	
	FLASH_EraseInitTypeDef flash_erase;
	flash_erase.TypeErase = FLASH_TYPEERASE_PAGES;
	flash_erase.PageAddress = FLASH_USER_PARAMS_START_ADDR;
	flash_erase.NbPages = 1;
	
	if (HAL_FLASHEx_Erase(&flash_erase, &pageError) == HAL_ERROR)
		return HAL_ERROR;
	
	if (pageError != 0xFFFFFFFF) return HAL_ERROR;
	
	//write acu id param to flash
	if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, FSU_ID_ADDR, parameters->fsu_id)!=HAL_OK) return HAL_ERROR;

	return HAL_OK;
}
