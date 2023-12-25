#pragma once
#include<vector>

#include "Rectanglee.h"
#include "pch.h"

using namespace std;

class SUTHERLANDANDCOHENALGO_API SutherlandandCohenAlgorithm
{
public:
	SutherlandandCohenAlgorithm(Line& line, Line& diagonalLine, vector<float>& mVertices, vector<float>& mColors);
	~SutherlandandCohenAlgorithm();

	int computeBinaryCode(double x, double y, Line& diagonalLine);
	void lineDrawingBySutherlandCohen(Line& line, Line& diagonalLine, vector<float>& mVertices, vector<float>& mColors);

public:
	vector<float> verticesOfOrignalLine;
	vector<float> colorOfOrignalLine;

private:
	Line* mLine;

	const int INSIDE = 0;    
	const int LEFT = 1;	 
	const int RIGHT = 2;     
	const int BOTTOM = 4;     
	const int TOP = 8;     
};



