/*
 * Sd.cpp
 *
 *  Created on: 2015年8月10日
 *      Author: i
 */

#include <sdcard/SdCard.h>
void SdCard::checkSdCard() {
	Serial.print("\nInitializing SD card ");
	Serial.print("at pin ");
	Serial.print(SPI_SD_CS);
	// we'll use the initialization code from the utility libraries
	// since we're just testing if the card is working!
	if (!card.init(SPI_HALF_SPEED, chipSelect)) {
		Serial.println("initialization failed. Things to check:");
		Serial.println("* is a card inserted?");
		Serial.println("* is your wiring correct?");
		Serial.println(
				"* did you change the chipSelect pin to match your shield or module?");
		return;
	} else {
		Serial.println("Wiring is correct and a card is present.");
	}
	// print the type of card
	Serial.print("\nCard type: ");
	switch (card.type()) {
	case SD_CARD_TYPE_SD1:
		Serial.println("SD1");
		break;
	case SD_CARD_TYPE_SD2:
		Serial.println("SD2");
		break;
	case SD_CARD_TYPE_SDHC:
		Serial.println("SDHC");
		break;
	default:
		Serial.println("Unknown");
	}

	// Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
	if (!volume.init(card)) {
		Serial.println(
				"Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
		return;
	}

	// print the type and size of the first FAT-type volume
	uint32_t volumesize;
	Serial.print("\nVolume type is FAT");
	Serial.println(volume.fatType(), DEC);
	Serial.println();

	volumesize = volume.blocksPerCluster(); // clusters are collections of blocks
	volumesize *= volume.clusterCount();       // we'll have a lot of clusters
	volumesize *= 512;                    // SD card blocks are always 512 bytes
	Serial.print("Volume size (bytes): ");
	Serial.println(volumesize);
	Serial.print("Volume size (Kbytes): ");
	volumesize /= 1024;
	Serial.println(volumesize);
	Serial.print("Volume size (Mbytes): ");
	volumesize /= 1024;
	Serial.println(volumesize);
	Serial.println(
			"\nFiles found on the card (name, date and size in bytes): ");
	root.openRoot(volume);
	// list all files in the card with date and size
	root.ls(LS_R | LS_DATE | LS_SIZE);
}
void SdCard::play() {
	pinMode(SPI_SD_CS, OUTPUT);
	Serial.print("Initializing SD card...");
	if (!SD.begin(chipSelect)) {
		Serial.println("initialization failed!");
		return;
	}
}
void SdCard::readFile(char* fileName) {
	Serial.print("readFile:");
	Serial.println(fileName);
	myFile = SD.open(fileName);
	if (myFile) {
		Serial.println(fileName);
		while (myFile.available()) {
			Serial.write(myFile.read());
		}
		myFile.close();
	} else {
		Serial.print("error opening to read ");
		Serial.println(fileName);
	}
}
void SdCard::writeFile(char* fileName, char* code) {
	Serial.print("writeFile:");
	Serial.println(fileName);
	myFile = SD.open(fileName, FILE_WRITE);
	if (myFile) {
		Serial.print("Writing to ");
		Serial.print(fileName);
		Serial.print(":");
		Serial.println(code);
		myFile.println(code);
		myFile.close();
		Serial.println("done.");
	} else {
		Serial.print("error opening to write ");
		Serial.println(fileName);
	}
}
