#include "common.h"
#include "memory.h"

/* Global Log Variable using Memory */
uint32_t non_secure_log_pointer __attribute__((section (".global_variable"))) = SRAM0_NS;
uint32_t secure_log_pointer __attribute__((section (".global_variable"))) = SRAM0_S;
int8_t logging[LOG_SIZE];

/* Global Memory/Register Control Functions */
/*	Read Operations */
uint32_t read_memory(uint32_t addr)
{
	uint32_t data;
	READ_MEMORY(addr, data);
	return data;
}
uint32_t read_register(uint32_t offset, uint32_t addr)
{
	uint32_t data;
	READ_MEMORY(offset + addr, data);
	return data;
}
int8_t *read_non_secure_log(void)
{
	uint32_t data;
	for (int i = 0; i < LOG_LOOP; i++)
	{
		non_secure_log_pointer -= 4;
		READ_MEMORY(non_secure_log_pointer, data);
		logging[LOG_LOOP * i + 0] = (data >> 24U);
		logging[LOG_LOOP * i + 1] = (data >> 16U);
		logging[LOG_LOOP * i + 2] = (data >> 8U);
		logging[LOG_LOOP * i + 3] = (data >> 0U);
	}
	return logging;
}
int8_t *read_secure_log(void)
{
	uint32_t data;
	for (int i = 0; i < LOG_LOOP; i++)
	{
		non_secure_log_pointer -= 4;
		READ_MEMORY(secure_log_pointer, data);
		logging[LOG_LOOP * i + 0] = (data >> 24U);
		logging[LOG_LOOP * i + 1] = (data >> 16U);
		logging[LOG_LOOP * i + 2] = (data >> 8U);
		logging[LOG_LOOP * i + 3] = (data >> 0U);
	}
	return logging;
}
/*	Write Operations */
void write_memory(uint32_t addr, uint32_t data)
{
	WRITE_MEMORY(addr, data);
	return;
}
void write_register(uint32_t offset, uint32_t addr, uint32_t data)
{
	WRITE_MEMORY(offset + addr, data);
	return;
}
void write_non_secure_log(int8_t *log)
{
	uint32_t data;
	for (int i = 0; i < LOG_LOOP; i++)
	{
		data = 0U;
		for (int j = 0; j < 4; j++) {
			data <<= 8U;
			data += log[LOG_LOOP * i + j];
		}
		WRITE_MEMORY(non_secure_log_pointer, data);
		non_secure_log_pointer += 4U;
	}
	return;
}
void write_secure_log(int8_t *log)
{
	uint32_t data;
	for (int i = 0; i < LOG_LOOP; i++)
	{
		data = 0U;
		for (int j = 0; j < 4; j++) {
			data <<= 8U;
			data |= (uint32_t)log[LOG_LOOP * i + j];
		}
		WRITE_MEMORY(secure_log_pointer, data);
		secure_log_pointer += 4U;
	}
	return;
}