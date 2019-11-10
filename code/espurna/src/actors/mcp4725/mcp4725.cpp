// -----------------------------------------------------------------------------
// MCP4725 Actor over I2C
// Copyright (C) 2017-2019 by Lars Bretschneider
// -----------------------------------------------------------------------------

#include "../../../config/custom.h"

#if SENSOR_SUPPORT && MCP4725_I2C_SUPPORT

#pragma once

#undef I2C_SUPPORT
#define I2C_SUPPORT 1 // Explicitly request I2C support.

#include "Arduino.h"
#include "mcp4725.h"

//void MCP4725I2CActor::


void MCP4725I2CActor::begin() {
	
	DEBUG_MSG_P(PSTR("MCP4725I2CActor::begin() \n"));

	if (!_dirty) return;

	unsigned char addresses[] = {MCP4725_I2C_ADDRESS};
	_address = _begin_i2c(_address, sizeof(addresses), addresses);
	if (_address == 0) return;

	_ready = true;
	_dirty = false;
}

// Descriptive name of the sensor
String MCP4725I2CActor::description() {
	char buffer[25];
	snprintf(buffer, sizeof(buffer), "MCP4725 @ I2C (0x%02X)", _address);
	return String(buffer);
}


// Type for slot # index
unsigned char MCP4725I2CActor::type(unsigned char index) {
	if (index == 0) return MAGNITUDE_ANALOG;
	return MAGNITUDE_NONE;
}

// Pre-read hook (usually to populate registers with up-to-date data)
void MCP4725I2CActor::pre() {
	_error = SENSOR_ERROR_OK;

	i2c_write_uint16(_address, 64, _output << 4);
/*

	unsigned char buffer[6];
	i2c_write_uint8(_address, 0x2C, 0x06);
	nice_delay(500);
	i2c_read_buffer(_address, buffer, 6);

	// cTemp msb, cTemp lsb, cTemp crc, humidity msb, humidity lsb, humidity crc
	_temperature = ((((buffer[0] * 256.0) + buffer[1]) * 175) / 65535.0) - 45;
	_humidity = ((((buffer[3] * 256.0) + buffer[4]) * 100) / 65535.0);
*/
}

// Current value for slot # index
double MCP4725I2CActor::value(unsigned char index) {
	if (index == 0) return _output;
	return 0;
}


#endif // SENSOR_SUPPORT && SHT3X_I2C_SUPPORT
