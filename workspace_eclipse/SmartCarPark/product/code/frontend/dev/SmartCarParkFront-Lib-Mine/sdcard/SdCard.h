/*
 * SdCard.h
 *
 *  Created on: 2015年8月10日
 *      Author: i
 */

#ifndef SDCARD_H_
#define SDCARD_H_
#include <SPI.h>
#include <SD.h>
#define SPI_SD_CS 4
class SdCard {

public:
	SdCard() {
	}
	~SdCard() {

	}
	void play();
	void readFile(char* fileName);
	void writeFile(char* fileName, char* code);
	void checkSdCard();
	void puse();
private:
	int chipSelect;
	File myFile;
	Sd2Card card;
	SdVolume volume;
	SdFile root;
};

#endif /* SDCARD_H_ */

