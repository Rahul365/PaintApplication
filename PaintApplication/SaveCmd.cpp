#include "SaveCmd.h"
#include "App.h"
#include "Document.h"
#include <fstream>
#include "DialogBoxes.h"
#define DUMMY_FILE_TOKEN

namespace stk {
	SaveCmd::SaveCmd() {
	}

	SaveCmd::~SaveCmd() {
	}

	void SaveCmd::execute() {
		OutputDebugStringA("Save Command Triggered");
#ifndef DUMMY_FILE_TOKEN
		std::shared_ptr<Document> doc = App::getInstance()->getActiveDoc();
		if (doc == nullptr) {
			OutputDebugStringA("No document is open...\n");
		}
		else {
			using namespace json11;
			OutputDebugStringA("Document is open...\n");
			std::string doc_obj = doc->to_json();
			std::string savingLocation = "E:/test dir/paint files/";
			std::string nameOffile = "paint.pnt";
			std::ofstream file(savingLocation + "/" + nameOffile);
			file << doc_obj.c_str();
			file.close();
		}
#else   
		std::shared_ptr<Document> doc = App::getInstance()->getActiveDoc();
		if (doc == nullptr) {
			OutputDebugStringA("No document is open...\n");
		}
		else {
			using namespace json11;
			OutputDebugStringA("Document is open...\n");
			std::string doc_obj = doc->to_json();
			HRESULT hr = DLOGS::WritePropertiesWithoutUsingHandlers(doc_obj);
		}
#endif
	}
}

