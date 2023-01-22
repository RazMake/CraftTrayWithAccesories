#define LOGGING_SERIAL_SPEED 115200
#define LoggingEnabled

#ifdef LoggingEnabled
    #define LOGGING_INIT (Serial.begin(LOGGING_SERIAL_SPEED))
    #define LOG(text)    (Serial.print(text))
    #define LOGLN(line)  (Serial.println(line))
#else
    #define LOGGING_INIT
    #define LOG(text)
    #define LOGLN(line)
#endif
