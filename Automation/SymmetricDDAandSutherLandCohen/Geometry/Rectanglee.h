#pragma once
#include "Line.h"
#include <vector>
#include "pch.h"


class GEOMETRY_API Rectanglee
{
public:
	Rectanglee();
	Rectanglee(Point3D inMin, Point3D inMax);
	~Rectanglee();

public:
	std::vector<Line> lines();

private:
	std::vector<Line> mLines;
};



