#pragma once

#include <inttypes.h>
#include <vector>
#include <memory>
#include "Point.h"
#include <inttypes.h>
#include <string>
#include "ThirdParty/Json/json11.hpp"

namespace stk {
	/*
	This class instance denotes a stroke. A stroke is contiguous set of points(x,y) such that there is a line for every consecutive
	set of points.
	*/
	class Stroke
	{
		std::vector<Point<int32_t>> stroke;
	public:
		Stroke();
		~Stroke();
		/*To add new point to stroke*/
		void push(Point<int32_t> p);
		/*To get the point at index from the stroke*/
		Point<int32_t>* get(size_t index);
		/*To get the last point from the stroke*/
		std::shared_ptr<Point<int32_t>> pop();

		int32_t size();

		json11::Json::array to_json(int index);

		static Stroke from_json(const json11::Json::array &ref);
	};

};