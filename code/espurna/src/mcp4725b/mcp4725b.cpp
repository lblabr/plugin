#include "../../config/custom.h"
//#define INCLUDE_MCP4725B 		1

#if INCLUDE_MCP4725B
/*

Plugin Module description
Plugin Copyright

*/

//*for better readability and usage of this template file the writing style is:
//* (//*) for comments
//* (//) for commented code (just delete the // to activate)
//* This plugin templat allows web interface provisioning the fronand
//* HTML, JS, CSS needs to be coded into the original core (on current design)

//*---------------------------------------------------------------------------
//* Plugin includes
//*---------------------------------------------------------------------------



#include <EEPROM.h>
#include <Ticker.h>
#include <ArduinoJson.h>
#include <vector>
#include <functional>

#include <arduino.h>
#include <Embedis.h>
#include "../../config/debug.h"
//#include "../../config/prototypes.h"

#include "mcp4725b.h"

//*----------------------------------------------------------------------------
//* Private
//*----------------------------------------------------------------------------
//*----------------------------------------------------------------------------
//* Plugin globals
//*----------------------------------------------------------------------------
bool _plugin_mcp4725b_enabled = false;;
unsigned long _plugin_mcp4725b_ReportInterval = 1000 * PLUGIN_MCP4725B_REPORT_EVERY;
unsigned long _plugin_mcp4725b_LastUpdate = 0;
unsigned long _plugin_mcp4725b_Counter = PLUGIN_MCP4725B_PARAMETER_1;

//additional variable initialisations
unsigned long _plugin_mcp4725b_Output = 0;
//additional variable initialisations


//*----------------------------------------------------------------------------
//* Plugin helper functions
//*----------------------------------------------------------------------------

//* Plugin loop helper function(s)
//*------------------------------
void _plugin_mcp4725b_Function1() {
    //* This is were the plugin magic happens...
    //* plugin functions called from _pluginLoop()
    //* _pluginLoop() is regitered to
    //* plugin loop helper function code goes here

    //* to get a sensor value for the plugin
    //*-------------------------------------
//    #if SENSOR_SUPPORTED
//        unsigned char _sensorID;
//        double _sensorValue;
//        _sensorValue = _getSensorValue(_sensorID, "current");
//        _sensorValue = _getSensorValue(_sensorID, "filtered");
//        _sensorValue = _getSensorValue(_sensorID, "reported");
//    #endif

    //* changing relay based on plugin logic
    //*-------------------------------------
//    unsigned char _relayID;
    //* set to true, false ot toggle status
//    _setRaleyStatus(_relayID, "ON");
//    _setRaleyStatus(_relayID, "OFF");
//    _setRaleyStatus(_relayID, "TOGGLE");

    //* In case of factory reset need
    //*------------------------------
//    resetSettings();
//    deferredReset(100, CUSTOM_RESET_FACTORY);

    //* In case of AP  need
    //*--------------------
//     createAP();

    //* In case of system reset need
    //*-----------------------------
//     deferredReset(100, CUSTOM_RESET_HARDWARE);

    //* In case of params setter/getter need
    //*-------------------------------------
//    setSetting(key, value);
//    getSetting(key, value, defaultValue);

    //* Broker publish
    //*-------------
//    #if BROKER_SUPPORT
//        brokerPublish(MQTT_TOPIC_PLUGIN, [id], message);
//    #endif

    //* MQTT publish
    //*-------------
//    #if MQTT_SUPPORT
//        mqttSend(MQTT_TOPIC_PLUGIN, [id], message);
//    #endif


    //* Debug messages (anywere in your code)
    //*--------------------------------------
    #if PLUGIN_MCP4725B_REPORT_EVERY != 0
      //DEBUG_MSG_P(PSTR("[PLUGIN] Plugin debug message c format: {%.}\n"), {.});
        if (millis() - _plugin_mcp4725b_LastUpdate > _plugin_mcp4725b_ReportInterval) {
            _plugin_mcp4725b_LastUpdate = millis();
            DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B] Loop counter: %d\n"),_plugin_mcp4725b_Counter);
            _plugin_mcp4725b_Counter++;
        }
    #endif
}

//------------------------------------------------------------------------------
// TERMINAL BEGIN
//------------------------------------------------------------------------------

//* If terminal Terminal commands needed
//* Plugin terminal commands helper function
//*-----------------------------------------
#if TERMINAL_SUPPORT
      void _plugin_mcp4725b_InitTerminalCommands() {
          //* Register Terminal commad to turn on/off the plugin
          //* use this as template to create additional plugin terminal commands
          terminalRegisterCommand(F("plugins/mcp4725b"), [](Embedis* e) {

                  DEBUG_MSG_P(PSTR("_plugin_mcp4725b_InitCommands() Arguments count: %d\n"), e->argc);
            
                  if (e->argc == 1) {
                      DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]:PLUGINS/mcp4725 Status: %s\n"), _plugin_mcp4725b_enabled ? "ON" : "OFF");
                      DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]:Send 0/1 to enable/disable\n"));
                      DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]:+OK\n"));
                      return;
                  }
                  _plugin_mcp4725b_enabled = (String(e->argv[1]).toInt() == 1);
//lb debug                  setSetting("PLG1_EN", _mcp4725_enabled);
                  DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]: Set Status: %s\n"), _plugin_mcp4725b_enabled ? "ON" : "OFF");
                  DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]:+OK\n"));
              });

      }
#endif
//------------------------------------------------------------------------------
// TERMINAL END
//------------------------------------------------------------------------------


//* end of helper functions
//*----------------------------------------------------------------------------


//*----------------------------------------------------------------------------
//* Plugin setup
//*----------------------------------------------------------------------------
void plugin_mcp4725b_Setup() {
    //*    plugin setup code
    //* myPluginSetup() is called by custom.h - espurna plugin entry point

//    _mcp4725_enabled = getSetting("PLG1_EN", MCP4725_ENABLE).toInt() == 1;
    _plugin_mcp4725b_enabled = true;

    //* Register plugin loop to espurna main loop
    //*------------------------------------------
    espurnaRegisterLoop(_plugin_mcp4725b_pluginLoop);

    //* If trminal used set up terminal
    //*-------------------------------
	  #if TERMINAL_SUPPORT
	      _plugin_mcp4725b_InitTerminalCommands();
	  #endif
    DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]: Plugin setup code finished \n"));
}
//* end of plugin setup
//*----------------------------------------------------------------------------

//*----------------------------------------------------------------------------
//* PLUGIN loop
//*----------------------------------------------------------------------------
void _plugin_mcp4725b_pluginLoop() {
    DEBUG_MSG_P(PSTR("[PLUGIN:MCP4725B]: Plugin Loop... \n"));

    //*   plugin loop code
    //* _pluginLoop regitered (espurnaRegisterLoop) by myPluginSetup()
    //* myPluginSetup() is called by custom.h - espurna plugin entry point

//    i2c_write_uint16(MCP4725_I2C_ADDRESS, 64, _pluginMcp4725Output << 4);

    //* if plugin disabled dont run the coded
//    if (_mcp4725_enabled != 1) return;

    //* here call all plugin loop functions (copy sumple function as needed)
//    _mcp4725Function1();

}

//*----------------------------------------------------------------------------
//* Public - Plugin API
//*----------------------------------------------------------------------------
//* Here goes ublic plugin API definitions and coded
//* currently plugin enabled query implemented
//* use this as template to create additionl API calls
//* to Set/Get internal plugin data or use plugin functions
bool plugin_mcp4725b_Enabled() {
    return _plugin_mcp4725b_enabled;
}
#endif  //#ifdef INCLUDE_MCP4725B
