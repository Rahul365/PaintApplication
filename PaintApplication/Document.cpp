#include "Document.h"
#include "ThirdParty/Json/json11.hpp"
#include <string>
#include <fstream>
#include "App.h"

namespace stk {
	Document::Document() {
		undo_stack = std::deque<std::vector<Stroke>>();
		redo_stack = std::deque<std::vector<Stroke>>();
	}

	std::vector<Stroke>* Document::getStrokes() {
		return &strokes;
	}

	std::vector<Stroke>* Document::getinitialStrokes() {
		return &m_initial_strokes;
	}


	void Document::setStrokes(std::vector<Stroke>& strokes)
	{
		this->strokes = std::move(strokes);
	}

	void Document::setInitialStrokes(std::vector<Stroke>& strokes)
	{
		this->m_initial_strokes= std::move(strokes);
	}


	void Document::addStroke(Stroke newStroke) {
		strokes.emplace_back(newStroke);
		undo_stack.push_front(strokes);/*record the updated state of the screen*/
		while (!redo_stack.empty()) redo_stack.pop_front();
	}
	

	std::deque<std::vector<Stroke>>* Document::getUndoStack() {
		return &undo_stack;
	}

	std::deque<std::vector<Stroke>>* Document::getRedoStack() {
		return &redo_stack;
	}

	void Document::save() {
		OutputDebugStringA("Saving current doc...\n");
		using namespace json11;
		std::string doc_obj = to_json();
		std::string savingLocation = "E:/test dir/paint files/";
		std::string nameOffile = "paint.pnt";
		std::ofstream file(savingLocation+"/"+nameOffile);
		file << doc_obj.c_str();
		file.close();
	}


	std::string Document::to_json() {
		using namespace json11;
		Json::array strokes_json;
		for (size_t index = 0; index < m_initial_strokes.size(); ++index) {
			strokes_json.emplace_back(m_initial_strokes[index].to_json(index));
		}
		for (size_t index = 0; index < strokes.size(); ++index) {
			strokes_json.emplace_back(strokes[index].to_json(index));
		}
		Json doc_json = Json::object{
			{"strokes",strokes_json}
		};
		return doc_json.dump();
	}

	void Document::reset() {
		undo_stack.clear();
		redo_stack.clear();
		strokes.clear();
		m_initial_strokes.clear();
	}

	Document Document::from_json(const json11::Json& doc_json) {
		Document doc;
		using namespace json11;
		std::vector<Stroke> strokes;
		Json::array strokes_json = doc_json["strokes"].array_items();
		for (Json stroke_obj : strokes_json) {
			/*
			 "strokes":[[{x,y}] ,[{x1,y1}]]
			*/
			Json::array stroke = stroke_obj.array_items();
			strokes.emplace_back(Stroke::from_json(stroke));
		}
		doc.setStrokes(strokes);
		return doc;
	}


}