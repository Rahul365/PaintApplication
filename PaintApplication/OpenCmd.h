#pragma once

#include "ICommand.h"

namespace stk {
	class OpenCmd :public ICommand
	{
	public:
		OpenCmd();
		~OpenCmd();
		void execute();
	};
}

