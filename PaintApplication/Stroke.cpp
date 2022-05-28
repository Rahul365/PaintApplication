#include "Stroke.h"
#include "framework.h"
#include "Point.h"
#include <vector>
#include <memory>
#include <inttypes.h>
#include <string>
#include "ThirdParty/Json/json11.hpp"

namespace {
	//anonymous namespace
	json11::Json point_to_json(const Point<int32_t>& pt) {
		using namespace json11;
		Json pt_json = Json::object{
			{"x",pt.x},
			{"y",pt.y}
		};
		std::string valx = std::to_string(pt_json["x"].int_value()).c_str();
		std::string valy = std::to_string(pt_json["y"].int_value()).c_str();
		OutputDebugStringA("x : ");
		OutputDebugStringA(valx.c_str());
		OutputDebugStringA(" y : ");
		OutputDebugStringA(valy.c_str());
		OutputDebugStringA("\n");
		return pt_json;
	}

	Point<int32_t> from_json_to_point(const json11::Json &pt) {
		return std::move(Point<int32_t>(pt["x"].int_value(),pt["y"].int_value()));
	}
}

namespace stk {
	/*
	This class instance denotes a stroke. A stroke is contiguous set of points(x,y) such that there is a line for every consecutive
	set of points.
	*/
	using namespace std;
		Stroke::Stroke() {
			stroke = vector<Point<int32_t>>();
		}
		Stroke::~Stroke() {
			stroke.clear();
		}
		/*To add new point to stroke*/
		void Stroke::push(Point<int32_t> p) {
			stroke.emplace_back(p);
		}
		/*To get the point at index from the stroke*/
		Point<int32_t>* Stroke::get(size_t index) {
			Point<int32_t>* ret = nullptr;
			if (index < 0 || index >= stroke.size()) return ret;
			ret = &stroke[index];
			return ret;
		}
		/*To get the last point from the stroke*/
		shared_ptr<Point<int32_t>> Stroke::pop() {
			shared_ptr<Point<int32_t>> ret = nullptr;
			if (stroke.size() == 0) return move(ret);
			ret = make_shared<Point<int32_t>>(stroke.back());
			stroke.pop_back();
			return ret;
		}

		int32_t Stroke::size() {
			return stroke.size();
		}

		json11::Json::array Stroke::to_json(int index) {
			using namespace json11;
			Json::array pts;
			for (Point<int32_t>& pt : stroke) {
				pts.push_back(point_to_json(pt));
			}
			return pts;
		}


		Stroke Stroke::from_json(const json11::Json::array &stroke_json) {
			Stroke stroke;
			using namespace json11;
			for (Json point : stroke_json) {
				stroke.push(from_json_to_point(point));
			}
			return std::move(stroke);
		}
};