#include "OpenCmd.h"
#include <fstream>
#include <string>
#include "ThirdParty/Json/json11.hpp"
#include "Document.h"
#include "Point.h"
#include "App.h"
#include "DialogBoxes.h"
#define DUMMY_FILE_TOKEN

namespace stk {
    OpenCmd::OpenCmd()
	{

	}

	OpenCmd::~OpenCmd()
	{

	}

	void OpenCmd::execute()
	{
#ifndef DUMMY_FILE_TOKEN
		std::string savingLocation = "E:/test dir/paint files/";
		std::string nameOffile = "paint.pnt";
		std::ifstream readfile(savingLocation + "/" + nameOffile);
		std::string strokes_str = "";
		std::string my_txt;
		while (getline(readfile, my_txt)) {
			strokes_str += my_txt;
		}
		readfile.close();
		using namespace json11;
		std::string err_txt;
		Json doc_obj = Json::parse(strokes_str, err_txt, JsonParse::STANDARD);
		std::vector<Stroke> strokes = *(Document::from_json(doc_obj).getStrokes());
		std::shared_ptr<Document> activeDoc = App::getInstance()->getActiveDoc();
		activeDoc->reset();
		activeDoc->setInitialStrokes(strokes);
#else 
		OutputDebugStringA("Using Dialog boxes...\n");
		std::string savedFilePath = "";
		HRESULT hr = DLOGS::BasicFileOpen(savedFilePath,false);
		if (!(savedFilePath.length()>=5 && savedFilePath.substr(savedFilePath.size() - 4) == ".pnt")) {
			OutputDebugStringA("Incorrect file path or file format is specified...\n");
			return;
		}
		OutputDebugStringA("OPEN FILE AT : ");
		OutputDebugStringA(savedFilePath.c_str());
		OutputDebugStringA("\n");
		std::ifstream readfile(savedFilePath);
		std::string strokes_str = "";
		std::string my_txt;
		while (getline(readfile, my_txt)) {
			strokes_str += my_txt;
		}
		readfile.close();
		OutputDebugStringA("READ DATA : ");
		OutputDebugStringA(strokes_str.c_str());
		OutputDebugStringA("\n");
		using namespace json11;
		std::string err_txt;
		Json doc_obj = Json::parse(strokes_str, err_txt, JsonParse::STANDARD);
		std::vector<Stroke> strokes = *(Document::from_json(doc_obj).getStrokes());
		std::shared_ptr<Document> activeDoc = App::getInstance()->getActiveDoc();
		activeDoc->reset();
		activeDoc->setInitialStrokes(strokes);
#endif
		
		
		/*
		OutputDebugStringA("Reading from point.pnt file\n");
		for (Stroke& stroke : strokes) {
			OutputDebugStringA("[");
			for (size_t index = 0; index != stroke.size(); index++) {
				Point<int32_t>* pt = stroke.get(index);
				OutputDebugStringA("{");
				OutputDebugStringA(std::to_string(pt->x).c_str());
				OutputDebugStringA(",");
				OutputDebugStringA(std::to_string(pt->y).c_str());
				OutputDebugStringA("} ");
			}
			OutputDebugStringA("],\n");
		}
		activeDoc->setInitialStrokes(strokes);
		*/
	}
}
