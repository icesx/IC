/*
 * w5100.cpp
 *
 *  Created on: 2015年8月10日
 *      Author: i
 */

#include <spi/SPI.h>
#include <ethernet/Ethernet.h>
#include <ethernet/EthernetClient.h>
#include "http.h"
// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 177);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

char* HttpClient::httpGet(char* server, char* url, int timeout) {
//	if (Ethernet.begin(mac) == 0) {
//	Serial.println("Failed to configure Ethernet using DHCP");
	// no point in carrying on, so do nothing forevermore:
	// try to congifure using IP address instead of DHCP:
	Serial.print("init ip address for 192.168.0.177");
	Ethernet.begin(mac, ip);
//	}
	// give the Ethernet shield a second to initialize:
	delay(1000);
	Serial.println("connecting...");
	// if you get a connection, report back via serial:
	if (client.connect(server, 80)) {
		Serial.println("connected");
		client.print("GET ");
		client.println(url);
		client.println("Connection: close");
		client.println();
		return readHttp(client, timeout);
	} else {
		// kf you didn't get a connection to the server:
		Serial.println("connection failed");
	}
}
char* HttpClient::readHttp(EthernetClient client, int timeout) {
	while (timeout) {
		if (client.available()) {
			char c = client.read();
			Serial.print(c);
		}
		if (!client.connected()) {
			Serial.println();
			Serial.println("disconnecting.");
			client.stop();
		}
	}
}

