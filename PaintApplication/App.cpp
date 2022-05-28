#include "App.h"
#include "Screen.h"
#include "Document.h"
#include "CommandManager.h"

/*Initialize static member of a class*/
App* App::appInstance = nullptr;

/*Define constructor of App class*/
App::App() {
	m_docs.emplace_back(std::make_shared<stk::Document>());
	m_screen = std::make_shared<stk::Screen>();
	m_cmdManager = std::make_shared<stk::CommandManager>();
}

/*Make App class Singleton*/
App* App::getInstance() {
	if (appInstance == nullptr) {
		 appInstance = new App();
	}
	return appInstance;
}

/*Returns the active document pointer*/
std::shared_ptr<stk::Document> App::getActiveDoc() {
	return m_docs[0];
}

std::shared_ptr<stk::Screen> App::getScreen() {
	return m_screen;
}

std::shared_ptr<stk::CommandManager> App::getCommandManager() {
	return m_cmdManager;
}