void espurnaRegisterLoop(void (*callback)());

#if TERMINAL_SUPPORT
	void terminalRegisterCommand(const String& name, void (*call)(Embedis*));
	void terminalInject(void *data, size_t len);
	Stream & terminalSerial();
#endif

#if DEBUG_WEB_SUPPORT
	void debugSend_P(PGM_P format_P, ...);
#endif

#if MQTT_SUPPORT
	using mqtt_callback_f = std::function<void(unsigned int, const char *, char *)>;

	void mqttSubscribe(const char * topic);
	void mqttRegister(mqtt_callback_f callback);

	String mqttTopic(const char * magnitude, bool is_set);
	String mqttTopic(const char * magnitude, unsigned int index, bool is_set);

	String mqttMagnitude(char * topic);

	void mqttSendRaw(const char * topic, const char * message, bool retain);
	void mqttSendRaw(const char * topic, const char * message);

	void mqttSend(const char * topic, const char * message, bool force, bool retain);
	void mqttSend(const char * topic, const char * message, bool force);
	void mqttSend(const char * topic, const char * message);

	void mqttSend(const char * topic, unsigned int index, const char * message, bool force);
	void mqttSend(const char * topic, unsigned int index, const char * message);

	const String& mqttPayloadOnline();
	const String& mqttPayloadOffline();
	const char* mqttPayloadStatus(bool status);

	void mqttSendStatus();
#endif
