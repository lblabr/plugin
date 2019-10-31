//#ifndef _MCP4725B_H
//	#define _MCP4725B_H

//#include "../../config/custom.h"


#if INCLUDE_MCP4725B
	#define _MCP4725B_H

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
	#define PLUGIN_MCP4725B_ENABLE             1
	//* sample plugin MTQQ topic
	#define MQTT_TOPIC_MCP4725B          "mcp4725b"
	//* Sample plugin reporting interval (0 no reporting)
	#define PLUGIN_MCP4725B_REPORT_EVERY        5
	//* Sample plugin parameter values
	#define PLUGIN_MCP4725B_PARAMETER_1         0

	//------------------------------------------------------------
	//* Plugin public interface
	//------------------------------------------------------------
	//* declare the plugin setup function (used by custom.h)
	void plugin_mcp4725b_Setup();

	void _plugin_mcp4725b_pluginLoop();
	
		
	//* get plugin enabled state
	bool mcp4725bEnabled();


	void mcp4725bPluginLoop();

	void espurnaRegisterLoop(void (*callback)());

	
	#if TERMINAL_SUPPORT
		void terminalRegisterCommand(const String& name, void (*call)(Embedis*));
		void terminalInject(void *data, size_t len);
		Stream & terminalSerial();
	#endif

	#if DEBUG_WEB_SUPPORT
		void debugSend_P(PGM_P format_P, ...);
	#endif

	//* Declare espurna calling function
	//* Plugin integation point

//	#if defined(USE_EXTRA)
//		//* Declare espurna calling function
//		void plugin_mcp4725b_extraSetup();
//	#endif	

	void plugin_mcp4725b_extraSetup() {
		//* extraSetup is called by espurna.ino (depended on USE_EXTRA flag)
		//* This is a single entry point to the plugin code
		//* Call the plugin setup function
		#if INCLUDE_MCP4725B
			plugin_mcp4725b_Setup();
		#endif
	}

#endif
//#endif