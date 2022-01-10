//============================================================================
// Name        : HelloWord++.cpp
// Author      : icesx
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<iostream>

#include<fstream>

using namespace std;

enum ImageType {
	jpg, bmp, png, nothing
};

ImageType image_type(const char* path) {

	unsigned char png_type[9] = { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A,
			0x0A, '0' };

	unsigned char file_head[9];

	ifstream inFile(path);
	for (int i = 0; i < 8; ++i) {
		inFile >> file_head[i];
	}
	file_head[8] = '0';
	switch (file_head[0]) {
	case 0xff:
		if (file_head[1] == 0xd8)
			return jpg; //jpeg
		break;
	case 0x42:
		if (file_head[1] == 0x4D)
			return bmp; //bmp
		break;
	case 0x89:
		if (file_head[1] == png_type[1] && file_head[2] == png_type[2]
				&& file_head[3] == png_type[3] && file_head[4] == png_type[4]
				&& file_head[5] == png_type[5] && file_head[6] == png_type[6]
				&& file_head[7] == png_type[7])
			return png; //png
		break;
	default:
		return nothing;
	}
	return nothing;
}

int main() {
	ImageType it=image_type("/ICESX/ICESX/imgs/Noname.jpg");
	if(it==jpg){
		cout<<"this is a jpg!";
	}else if(it==png){
		cout <<"this is a png!";
	}else if(it==bmp){
		cout<<"this is bmp!";
	}else{
		cout<<"this is nothig!";
	}
	return 0;
}
