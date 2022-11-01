#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming {

	//constuctor for bitmap 
	Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height), m_pPixels(
			new uint8_t[width * height * 3]{ }) {
		//we need 3 times the amout of pixels to store each of the three RGB values
		//in this case, in an unsigned 8-bit int
	}

	//Creates and does everything needed to make a binary bitmap
	bool Bitmap::write(string filename) {

		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
			+ m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		ofstream file;
		file.open(filename, ios::out | ios::binary);

		if (!file) {
			return false;
		}

		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);

		file.close();

		if (!file) {
			return false;
		}

		return true;
	}

	//sets the RGB values to a pixel in the bitmap
	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		//get pointer to start of pixels array
		uint8_t* pPixel = m_pPixels.get();
		
		//calculate pixel address by its xa dn y coordinate
		pPixel += (y *3)* m_width + (x*3);

		//set the RGB value for that pixel
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;


	}

	//deconstutor
	Bitmap::~Bitmap() {
		// TODO Auto-generated destructor stub
	}

} /* namespace caveofprogramming */
