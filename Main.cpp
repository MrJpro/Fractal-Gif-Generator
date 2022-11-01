// 1/8/2022 Advance c++ 
#include <iostream>
#include <string>
#include <cmath>

#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"
#include "Mandelbrot.h"


using namespace std;
using namespace caveofprogramming;


//declaring pi as constant value
const double pi = 3.14159265358979;
const double radius = .7885;
double Mandelbrot::C_real = radius;
double Mandelbrot::C_imag;
static Mandelbrot mb = Mandelbrot();

//function declarations
double getImaginaryPart(int i,double r);
double getRealPart(int i, double r);
string getTextName(int i);

	
//declaring and instancating a FractalCreator object
FractalCreator fractalCreator(852, 480);

int main() {
	
	

	//adding multiple color ranges to the fractal 
	fractalCreator.addRange(0.0079125, RGB(255, 255, 255)); //black RGB(0, 0, 0)
	fractalCreator.addRange(0.015825, RGB(128, 0, 128)); //orange RGB(255, 165, 0)
	fractalCreator.addRange(0.03175, RGB(0, 0, 255)); //yellow RGB(255, 255, 0)
	fractalCreator.addRange(0.0625, RGB(0,128, 0)); //green  RGB(0,128, 0)
	fractalCreator.addRange(0.125, RGB(255, 255, 0)); //blue RGB(0, 0, 255)
	fractalCreator.addRange(0.25, RGB(255, 165, 0)); // purple RGB(128, 0, 128)
	fractalCreator.addRange(0.5, RGB(255, 0, 0)); //pink RGB(255, 105, 180)
	fractalCreator.addRange(1.0, RGB(0, 0, 0)); //red RGB(255,0,0)


	//applying zooms to the original to zoom in
	fractalCreator.addZoom(Zoom(426, 240, 1.25));
	//fractalCreator.addZoom(Zoom(312, 304, 0.1));
	
	//run and create all 360 bitmaps	
	for (int i = 0; i <= 359; i++) {
		
		double k = getRealPart(i, radius);
		mb.C_real = k;
		double j = getImaginaryPart(i, radius);
		mb.C_imag = j;
		fractalCreator.run(getTextName(i));
		

		cout << "Completed bitmap #: " << i << endl;
	}
	
	//creating and writing the file 
	//fractalCreator.run("julia.bmp");

	cout << "Finished." << endl;
	return 0;
}

//returns the imaginary part of the complex number
double getImaginaryPart(int i, double r) {
	/*
	if (i <= 180) {
		return (2.0 * pi * (double) (i / 360.0));
	}
	
	else {
		return (2.0 * pi * (double) (i / 360.0) * -1.0);
	}
	*/

	double a = 2.0 * pi * (double)(i / 360.0);
	return r * sin(a);


}

//returns a string for text file based on iteration
string getTextName(int i) {

	string s = "juliaSet";
	s.append(to_string(i));
	s.append(".bmp");

	return s;
}

//returns the real part of the complex number: index, radius
double getRealPart(int i, double r) {
	//calculate radians based in 
	double a = 2.0 * pi * (double)(i / 360.0);
	return r * cos(a);
	
}

//JuliaSet1.bmp - julia set(c = 0.285 + .01i)
//JuliaSet2.bmp - julia set(c = -.4 + .6i)
//JuliaSet3.bmp - julia set(c = -.8 + .156i)
//JuliaSet4.bmp - julia set(c = -.7269 + .1889i)
//JuliaSet5.bmp - julia set(c = -.79 + .15i)
//JuliaSet6.bmp - julia set(c = .28 + .008i)