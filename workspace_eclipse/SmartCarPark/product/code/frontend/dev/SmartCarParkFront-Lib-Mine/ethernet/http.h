/*
 * w5100.h
 *
 *  Created on: 2015年8月10日
 *      Author: i
 */
#include <EthernetClient.h>
#ifndef W5100_H_
#define W5100_H_
class HttpClient {

public:
	char* httpGet(char* server, char* url, int timeout);
private:
	char* readHttp(EthernetClient client, int timeout);
};

#endif /* W5100_H_ */
