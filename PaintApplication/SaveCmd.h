#pragma once

#include "ICommand.h"

namespace stk {
	class SaveCmd :public ICommand
	{
	public:
		SaveCmd();
		~SaveCmd();
		void execute();
	};
}
