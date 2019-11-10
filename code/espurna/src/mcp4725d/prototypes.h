


void espurnaRegisterLoop(void (*callback)());

#if TERMINAL_SUPPORT
	void terminalRegisterCommand(const String& name, void (*call)(Embedis*));
	void terminalInject(void *data, size_t len);
	Stream & terminalSerial();
#endif

#if DEBUG_WEB_SUPPORT
	void debugSend_P(PGM_P format_P, ...);
#endif