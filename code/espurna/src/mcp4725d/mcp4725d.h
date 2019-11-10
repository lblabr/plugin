#ifdef INCLUDE_MCP4725D

//	#ifndef _MCP4725D_H
//	#define _MCP4725D_H

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
	#define PLUGIN_MCP4725D_ENABLE             1
	//* sample plugin MTQQ topic
	#define MQTT_TOPIC_MCP4725D          "mcp4725d"
	//* Sample plugin reporting interval (0 no reporting)
	#define PLUGIN_MCP4725D_REPORT_EVERY        5
	//* Sample plugin parameter values
	#define PLUGIN_MCP4725D_PARAMETER_1         0

	//------------------------------------------------------------
	//* Plugin public interface
	//------------------------------------------------------------
	//* declare the plugin setup function (used by custom.h)
	void plugin_mcp4725d_Setup();

	//* get plugin enabled state
	bool mcp4725dEnabled();
	void _plugin_mcp4725d_pluginLoop();

#endif
