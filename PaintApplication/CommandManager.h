#pragma once
#include "ICommand.h"
namespace stk {
	/*Make this class non-inheritable*/
	class CommandManager final
	{
		std::shared_ptr<ICommand> undocmd;
		std::shared_ptr<ICommand> redocmd;
		std::shared_ptr<ICommand> savecmd;
		std::shared_ptr<ICommand> opencmd;
		std::shared_ptr<ICommand> getCommand(char key, bool ctrlDown, bool shiftDown, bool altDown);
	public:
		CommandManager();
		bool handleCommand(char key, bool ctrlDown, bool shiftDown, bool altDown);
	};
}

