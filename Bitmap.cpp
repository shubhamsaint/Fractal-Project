#include <fstream>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace c8master;

namespace c8master
{

Bitmap::Bitmap(int width, int height)
{
	m_width=width;
	m_height=height;
	m_pPixels=new unsigned __int8[width * height * 3]();
}

bool 
Bitmap::write(string filename) 
{

	BitmapFileHeader fileHeader;
	fileHeader.header[0]='B';             //create bitmap file header                 
	fileHeader.header[1]='M';			  //create bitmap file header
	fileHeader.reserved = 0;
    
	//create bitmap information header
	BitmapInfoHeader infoHeader;
	infoHeader.headerSize=40;
	infoHeader.planes=1;
	infoHeader.bitsPerPixel=24;
	infoHeader.compression=0;
	infoHeader.horizontalResolution=2400;
	infoHeader.verticalResolution=2400;
	infoHeader.importantColors=0;
	infoHeader.colors=0;
	infoHeader.dataSize=0;



	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)+ m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;


	
    //save all header and bitmap information into file

	ofstream file;
	file.open(filename.c_str(), ios::out | ios::binary);

	if (!file) 
	{
		return false;
	}

	file.write((char *) &fileHeader, sizeof(fileHeader));
	file.write((char *) &infoHeader, sizeof(infoHeader));
	file.write((char *) (char*)(m_pPixels), m_width * m_height * 3);

	file.close();

	if (!file) 
	{
		return false;
	}

	return true;
}
void 
Bitmap::setPixel(int x, int y, unsigned __int8 red, unsigned __int8 green, unsigned __int8 blue)   // set the value for each pixe by giving RGB
{
	unsigned __int8 *pPixel = m_pPixels;

	pPixel += (y * 3) * m_width + (x * 3);      //row wise filling the values into the pixels 

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}



Bitmap::~Bitmap() 
{
	delete(m_pPixels);
}

}