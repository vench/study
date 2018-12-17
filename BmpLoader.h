#pragma once
#include "all.h"



// BMPLoader - loads Microsoft .bmp format Takes a filename, returns an array of RGB pixel data
// Copyright (C) 2006  Chris Backhouse  cjbackhouse@hotmail.com  www.backhouse.tk
class BmpLoader {

public:
	int sizeX, sizeY, size;
	std::string fname;
	byte* data;	// OpenGL formatted pixels

	BmpLoader(std::string name) { fname = name; data = 0; LoadImage(); }
	~BmpLoader() { delete[] data; };

	byte& Pixel(int x, int y, int c)
	{
		return data[(y * sizeX + x) * 3 + c];
	}

	char LoadImage()
	{
		if (sizeof(int) != 4)
			return 'i';

		FILE*f;
		//fopen_s(&f, fname.c_str(), "rb"); // Open for reading in binary mode
		f = fopen(fname.c_str(), "rb");
		if (!f)
			return 'o';

		char header[54];
		fread(header, 54, 1, f);	// Read the 54bit main header

		if (header[0] != 'B' || header[1] != 'M')
		{
			fclose(f);
			return 'b';		// All bitmaps should start "BM"
		}

		// It seems gimp sometimes makes its headers small, so we have to do this. hence all the fseeks
		int offset = *(uint*)(header + 10);

		sizeX = *(int*)(header + 18);
		sizeY = *(int*)(header + 22);
		size = sizeX * sizeY * 3;
		delete[] data;
		data = new byte[size]; // Now the bitmap knows how big it is. We can allocate its memory
		int bits = int(header[28]);	// Colour Depth
		byte cols[256 * 4];				// Colour Table
		switch (bits)
		{
		case 24:
			fseek(f, offset, SEEK_SET);
			fread(data, size, 1, f);	// 24bit is easy
			for (int x = 0; x < size; x += 3)	// Except the format (which is BGR)
			{
				byte temp = data[x];
				data[x] = data[x + 2];
				data[x + 2] = temp;
			}
			break;
		case 8:
			fread(cols, 256 * 4, 1, f);	// Read Color Table
			fseek(f, offset, SEEK_SET);
			for (int y = 0; y < sizeY; ++y)	// (Notice 4bytes/col for some reason)
			for (int x = 0; x < sizeX; ++x)
			{
				byte byte;
				fread(&byte, 1, 1, f);			// Just read one byte
				for (int c = 0; c<3; ++c)
					Pixel(x, y, c) = cols[byte * 4 + 2 - c];	// And look up in the table
			}
			break;
		case 4:
			fread(cols, 16 * 4, 1, f);
			fseek(f, offset, SEEK_SET);
			for (int y = 0; y<256; ++y)
			{
				for (int x = 0; x<256; x += 2)
				{
					byte byte;
					fread(&byte, 1, 1, f); // As above, but need to exract two pixels from each byte
					for (int c = 0; c<3; ++c)
						Pixel(x, y, c) = cols[byte / 16 * 4 + 2 - c];
					for (int c = 0; c<3; ++c)
						Pixel(x + 1, y, c) = cols[byte % 16 * 4 + 2 - c];
				}
			}
			break;
		case 1:
			fread(cols, 8, 1, f);
			fseek(f, offset, SEEK_SET);
			for (int y = 0; y < sizeY; ++y)
			{
				for (int x = 0; x < sizeX; x += 8)
				{
					byte byte;
					fread(&byte, 1, 1, f);
					// Every byte is eight pixels so I'm shifting the byte to the relevant position, then masking out
					// all but the lowest bit in order to get the index into the Colour Table.
					for (int x2 = 0; x2<8; ++x2)
					for (int c = 0; c<3; ++c)
						Pixel(x + x2, y, c) = cols[((byte >> (7 - x2)) & 1) * 4 + 2 - c];
				}
			}
			break;
		default: fclose(f);
			return 'u';
		}
		if (ferror(f))
		{
			fclose(f);
			return 'f';
		}
		fclose(f);
		return '\0';
	}

	void BMPLoadFromBuffer(byte* buf, int w, int h)
	{
		sizeX = w;
		sizeY = h;
		size = sizeX * sizeY * 3;
		delete[] data;
		data = new byte[size];
		int bits = 24;		// ColourDepth
		data = buf;
	}

	std::string TranslateBMPError(char err)
	{
		switch (err)
		{
		case 'b': return "This file is not a bitmap, specifically it doesn't start 'BM'";
		case 'o': return "Failed to open the file, suspect it doesn't exist";
		case 'f': return "ferror said we had an error. This error seems to not mean anything, try ignoring it";
		case 'i': return "sizeof(int)!=4 quite a lot of rewriting probably needs to be done on the code";
		case '\0': return "No errors detected";
		case 'u': return "Unknown bmp format, ie not 24bit, 256, 16 or 2 colour";
		default: return "Not a valid error code";
		}
	}
};

