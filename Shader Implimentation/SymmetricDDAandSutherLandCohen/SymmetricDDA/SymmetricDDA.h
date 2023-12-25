#pragma once
#include "Line.h"
#include "pch.h"
#include <vector>

using namespace std;

class SYMMETRICDDA_API SymmetricDDA
{
public:
	SymmetricDDA();
	~SymmetricDDA();

public:
	void drawGrid(vector<float>& vertices, vector<float>& colors);
	void drawLineBySymmetricDDA(Line& line, vector<float>& mVertices);

public:
	vector<float> mVertices;
	vector<float> mColors;
};




