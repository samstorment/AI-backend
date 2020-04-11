#pragma once
#include <vector>
#include <fstream>
#include <iostream>

typedef std::vector<int> iarray;
typedef std::vector<iarray> matrix;
typedef std::vector<std::string> sarray;

struct FrontEndController {
	matrix readFile(const std::string& filename);
	matrix processFile(const sarray& lines);
	sarray splitLine(std::string line, const std::string& delimiter);
	iarray toIntArray(const sarray& array);
	void writeFile(const std::string& filename);
};