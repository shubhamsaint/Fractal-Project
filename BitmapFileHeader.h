#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_


using namespace std;
namespace c8master
{
#pragma pack(2)
struct BitmapInfoHeader 
{
	__int32 headerSize;   //40
	__int32 width;
	__int32 height;
	__int16 planes;      //1
	__int16 bitsPerPixel;  //24
	__int32 compression;   //0
	__int32 dataSize;    //0
	__int32 horizontalResolution;    //2400
	__int32 verticalResolution;    //2400
	__int32 colors;    //0
	__int32 importantColors;   //0
};
}
#endif
