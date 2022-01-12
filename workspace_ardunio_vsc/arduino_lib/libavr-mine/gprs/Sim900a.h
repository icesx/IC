/*
 * Sim900a.h
 *
 *  Created on: 2015年8月6日
 *      Author: i
 */
#ifndef Sim900a_H_
#define Sim900a_H_
#include <Arduino.h>
#define SIM900A_PIN 2
#define SIM900A_SENDSZ 512
#define SERIAL_RESPONSE_SIZE 100
struct HttpParam
{
	char *host;
	int port;
	char *url;
	char *code;
	int length;
};
class Sim900a
{
public:
	Sim900a(HardwareSerial *mySerial, long band)
	{
		this->mySerial = mySerial;
		this->band = band;
		HTTP_METHOD_POST = (char *)"POST";
		HTTP_METHOD_GET = (char *)"GET";
		SEND_FLAG = (char *)"\x1A";
		HTTP_NEW_LINE = (char *)"\n";
	}
	void prepare();
	void prepareHttp();
	char *tcp(char *code);
	char *httpPost(HttpParam *param);
	char *httpGet(HttpParam *param);
	~Sim900a()
	{
	}

private:
	inline void runCommand(char *ATcommand);
	inline void sendATcommandTimeout(char *ATcommand, char *okFlag,
									 long timeout, boolean retry);
	boolean readFromMySerial(long timeout, char *okFlag);
	inline void close_connect();
	void sendCode(char *code);
	void sendCodeln(char *code);
	void sendCodeln(int i);
	void sendCode(int i);
	void poweron();
	void reconnect(char *host, int port);
	char *requestOnTcp(char *code, char *method, HttpParam *param);
	char *requestOnHttp(char *code, char *method, HttpParam *param);
	void readFromServer(long timeout, char *key);
	void runHttpPara(HttpParam *param);
	void runHttpData(HttpParam *param);

	HardwareSerial *mySerial;
	long band;
	HttpParam *httpParam;
	long previous;
	char *HTTP_METHOD_POST;
	char *HTTP_METHOD_GET;
	char *HTTP_NEW_LINE;
	char *HTTP_VERSION =(char *) " HTTP/1.1";
	char *HTTP_CONTENTYPE =(char *) " application/x-www-form-urlencoded";
	//\x1A=ctrl+z
	char *SEND_FLAG;
	char serialResponse[SERIAL_RESPONSE_SIZE];

	char *const defaultOk =(char *) "OK";
};
#endif
