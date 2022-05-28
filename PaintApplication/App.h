#pragma once

#include<memory>
#include<vector>

namespace stk {
	class Screen;
	class Document;
	class CommandManager;
}

class App {
	/*List of docs*/
	/*
		Nomenclature : 
		m_ : prefix is used to name members of the class for clarity purposes
	*/
	static App* appInstance;
	std::shared_ptr<stk::CommandManager> m_cmdManager;
	std::vector<std::shared_ptr<stk::Document>> m_docs;
	std::shared_ptr<stk::Screen> m_screen;
	App();
public:
	static App* getInstance();
	std::shared_ptr<stk::Document> getActiveDoc();
	std::shared_ptr<stk::Screen> getScreen();
	std::shared_ptr<stk::CommandManager> getCommandManager();
};

