#include "CommandManager.h"
#include "UndoCmd.h"
#include "RedoCmd.h"
#include "SaveCmd.h"
#include "OpenCmd.h"

namespace stk {
	CommandManager::CommandManager() {
		undocmd = std::make_shared<UndoCmd>();
		redocmd = std::make_shared<RedoCmd>();
		savecmd = std::make_shared<SaveCmd>();
		opencmd = std::make_shared<OpenCmd>();
	}

	std::shared_ptr<ICommand> CommandManager::getCommand(char key, bool ctrlDown, bool shiftDown, bool altDown) {
		//Undo Command
		if (ctrlDown && (key == 'Z' || key == 'z')) return undocmd;
		//Redo command
		if (ctrlDown && (key == 'Y' || key == 'y')) return redocmd;
		//Save Command
		if (ctrlDown && (key == 'S' || key == 's')) return savecmd;
		//open command
		if (ctrlDown && (key == 'O' || key == 'o')) return opencmd;
		//unknown options
		return nullptr;
	}

	bool CommandManager::handleCommand(char key, bool ctrlDown, bool shiftDown, bool altDown) {
		std::shared_ptr<ICommand> cmd = getCommand(key,ctrlDown,shiftDown,altDown);
		if (cmd!=nullptr) {
			cmd->execute();
			return true;
		}
		return false;
	}
}