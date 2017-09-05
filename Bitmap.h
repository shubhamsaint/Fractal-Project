
#ifndef BITMAP_H_
#define BITMAP_H_

using namespace std;

namespace c8master 
{

class Bitmap 
{
private:
	int m_width;
	int m_height;
	unsigned __int8 *m_pPixels; 

public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, unsigned __int8 red, unsigned __int8 green, unsigned __int8 blue);
	bool write(string filename);
	virtual ~Bitmap();
};

} /* namespace c8master */

#endif /* BITMAP_H_ */
