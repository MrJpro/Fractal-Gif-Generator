#pragma once
#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace caveofprogramming {

	class Mandelbrot {
	public:
		static const int MAX_ITERATIONS = 81;
		static double C_real;
		static double C_imag;

	public:
		Mandelbrot();
		virtual ~Mandelbrot();

		static int getIterations(double x, double y);
		static int getJuliaIterations(double x, double y);

		void setReal(double d);
		double getReal();

		void setImag(double d);
		double getImag();
	};

} /* namespace caveofprogramming */

#endif /* MANDELBROT_H_ */

