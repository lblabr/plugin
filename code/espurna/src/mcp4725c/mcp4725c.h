#ifdef INCLUDE_MCP4725C

//	#ifndef _MCP4725C_H
//	#define _MCP4725C_H

	//*---------------------------------------------------------------------------
	//* Espurna overrides
	//* -------------------------------------------------------------------------
	//*  Here put espurna plugin specific overrides
	//#define RELAY_PROVIDER          RELAY_PROVIDER_HW655
	//#define SERIAL_BAUDRATE         9600 

	//---------------------------------------------------------------------------
	//* Plugin defines
	//----------------------------------------------------------------------------
	//* plese refer to plugin1.ino for more help and inline documentaion
	//* Plugin enabled flag (enabling or disabling execution)
	#define PLUGIN_MCP4725C_ENABLE             1
	//* sample plugin MTQQ topic
	#define MQTT_TOPIC_MCP4725C          "mcp4725c"
	//* Sample plugin reporting interval (0 no reporting)
	#define PLUGIN_MCP4725C_REPORT_EVERY        5
	//* Sample plugin parameter values
	#define PLUGIN_MCP4725C_PARAMETER_1         0

	//------------------------------------------------------------
	//* Plugin public interface
	//------------------------------------------------------------
	//* declare the plugin setup function (used by custom.h)
	void plugin_mcp4725c_Setup();

	//* get plugin enabled state
	bool mcp4725cEnabled();
	void _plugin_mcp4725c_pluginLoop();

#endif
