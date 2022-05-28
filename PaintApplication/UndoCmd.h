#pragma once

#include "ICommand.h"

namespace stk {
	class UndoCmd :public ICommand
	{
	public:
		UndoCmd();
		~UndoCmd();
		void execute();
	};
}

