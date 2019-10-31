#include "../../config/custom.h"
#include "../../config/all.h"

#ifdef INCLUDE____PLUGIN___
	___plugin___
	#ifndef _MCP4725_H
	#define _MCP4725_H

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
	#define ___PLUGIN____ENABLE             1
	//* sample plugin MTQQ topic
	#define MQTT_TOPIC_MCP4725          "mcp4725"
	//* Sample plugin reporting interval (0 no reporting)
	#define PLUGIN_REPORT_EVERY        5
	//* Sample plugin parameter values
	#define PLUGIN_PARAMETER_1         0

	//------------------------------------------------------------
	//* Plugin public interface
	//------------------------------------------------------------
	//* declare the plugin setup function (used by custom.h)
	void mcp4725Setup();
	//* get plugin enabled state
	bool mcp4725Enabled();

	void _mcp4725_pluginLoop();

	void espurnaRegisterLoop(void (*callback)());

	//* Declare espurna calling function
	//* Plugin integation point

//	#if defined(USE_EXTRA)
//		//* Declare espurna calling function
//		void extraSetup();
//	#endif	

	void extraSetup() {
		//* extraSetup is called by espurna.ino (depended on USE_EXTRA flag)
		//* This is a single entry point to the plugin code
		//* Call the plugin setup function
		#if defined(INCLUDE_MCP4725)
			mcp4725Setup();
		#endif
	}

	#endif
#endif
