#include <complex>

#include "Mandelbrot.h"
using namespace std;
namespace caveofprogramming {


	//constuctor
	Mandelbrot::Mandelbrot() {
		// TODO Auto-generated constructor stub

	}

	//deconstuctor
	Mandelbrot::~Mandelbrot() {
		// TODO Auto-generated destructor stub
	}

	//gets the number of iterations each pixel needs to either be more than a constant c,
	//or to stay in the mandelbrot set
	int Mandelbrot::getIterations(double x, double y) {

		complex<double> z = 0;
		complex<double> c(x, y);
		int iterations = 0;

		
		while (iterations < MAX_ITERATIONS) {
			z = z * z + c;
			
			if (abs(z) > 2) {
				break;
			}

			iterations++;
		}
		
		
		return iterations;
	}

	//same as other iteration method, but for a Julia set
	int Mandelbrot::getJuliaIterations(double x, double y) {

		complex<double> z(x,y);
		complex<double> c(C_real, C_imag);
		int iterations = 0;



		while (iterations < MAX_ITERATIONS) {
			z = z * z + c;

			if (abs(z) > 2) {
				break;
			}

			iterations++;
		}


		return iterations;
	}

	//set real part of complex number
	void Mandelbrot::setReal(double d) {
		C_real = d;
	}
	
	//get current real part of complex number 
	double Mandelbrot::getReal()
	{
		return C_real;
	}

	//set imaginary part of complex number
	void Mandelbrot::setImag(double d) {
		C_imag = d;
	}

	//get imaginary part of complex number
	double Mandelbrot::getImag() {
		return C_imag;
	}


} /* namespace caveofprogramming */
