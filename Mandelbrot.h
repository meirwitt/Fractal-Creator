#pragma once
class Mandelbrot
{
private:

public:
	static const int MAX_ITERATIONS = 1000;
	//todo 
public:
	Mandelbrot();
	~Mandelbrot();

	void seeIfIcanPushtoGit();

	static int getIterations(double x, double y);
};

