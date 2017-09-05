#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

using namespace std;

#pragma pack(2)
namespace c8master
{
struct BitmapFileHeader 
{
	char header[2];  //{b,m}
	__int32 fileSize;
	__int32 reserved;   //0
	__int32 dataOffset;
};
}
#endif