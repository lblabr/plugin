#include "../../../config/custom.h"

#if MCP4725_I2C_SUPPORT

	#define MCP4725_I2C_ID 		100

	#ifndef MCP4725_I2C_ADDRESS
	#define MCP4725_I2C_ADDRESS 	0x60    // 0x60 means default, 0x61
	#endif
	
	void i2cScan();
	void i2cClearBus();
	bool i2cGetLock(unsigned char address);
	bool i2cReleaseLock(unsigned char address);
	unsigned char i2cFindAndLock(size_t size, unsigned char * addresses);

	void i2c_wakeup(uint8_t address);
	uint8_t i2c_write_buffer(uint8_t address, uint8_t * buffer, size_t len);
	uint8_t i2c_write_uint8(uint8_t address, uint8_t value);
	uint8_t i2c_write_uint8(uint8_t address, uint8_t reg, uint8_t value);
	uint8_t i2c_write_uint8(uint8_t address, uint8_t reg, uint8_t value1, uint8_t value2);
	uint8_t i2c_write_uint16(uint8_t address, uint16_t value);
	uint8_t i2c_write_uint16(uint8_t address, uint8_t reg, uint16_t value);
	uint8_t i2c_read_uint8(uint8_t address);
	uint8_t i2c_read_uint8(uint8_t address, uint8_t reg);
	uint16_t i2c_read_uint16(uint8_t address);
	uint16_t i2c_read_uint16(uint8_t address, uint8_t reg);
	uint16_t i2c_read_uint16_le(uint8_t address, uint8_t reg);
	int16_t i2c_read_int16(uint8_t address, uint8_t reg);
	int16_t i2c_read_int16_le(uint8_t address, uint8_t reg);
	void i2c_read_buffer(uint8_t address, uint8_t * buffer, size_t len);	

	void debugSend_P(PGM_P format_P, ...);
	
	#include "../../../config/types.h"
	#include "../../../config/debug.h"
	#include "../../../sensors/I2CSensor.h"

	class MCP4725I2CActor : public I2CSensor {
		public:
			
			MCP4725I2CActor() : I2CSensor() {
				_sensor_id = MCP4725_I2C_ID;
				_count = 1;
			}

			// Initialization method, must be idempotent
			void begin();

			// Descriptive name of the sensor
			String description();

			// Type for slot # index
			unsigned char type(unsigned char index);

			// Pre-read hook (usually to populate registers with up-to-date data)
			void pre();

			// Current value for slot # index
			double value(unsigned char index);

		protected:
			long _output = 0;
	};	
	
	
	
#endif
