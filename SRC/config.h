#ifndef CONFIG_WIFI
#define CONFIG_WIFI

#define THING_NAME "RyanBroker"
#define mqttBroker "192.168.1.176"
#define LIGHT_LEVEL_SET_TOPIC "RyanBroker/lightSet"
#define LIGHT_LEVEL_TOPIC "/lightLevel"
#define ANNOUNCE_TOPIC "announce"
#define TEMP_SET_TOPIC "/tempSet"
#define TEMPERATURE_SET_TOPIC "RyanBroker/tempSet"
#define TEMPERATURE_TOPIC "/temp"
#define GET_TIME_TOPIC "getTime"
#define TIME_TOPIC "timeStamp"
#define MQTTClient_QOS2 1
#define LEDON 0
#define LEDOFF 1

#endif