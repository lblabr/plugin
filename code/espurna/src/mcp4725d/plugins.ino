/*

PLUGINS MODULE MCP4725D

Copyright (C) 2016-2019 by Lars Bretschneider

*/

#if USE_EXTRA
	void extraSetup() {
//* extraSetup is called by espurna.ino (depended on USE_EXTRA flag)

//* This is a generated template file for the dectlaration of extraSetup, in earlier Version placed in custom.h

//* This is a single entry point to the plugin code
//* Call the plugin setup function
		#if INCLUDE_MCP4725D
			plugin_mcp4725d_Setup();
		#endif
	}
#endif
