#pragma once

#include "ICommand.h"
namespace stk {
	class RedoCmd :public ICommand
	{
	public:
		RedoCmd();
		~RedoCmd();
		void execute();
	};
}

