#include "RedoCmd.h"
#include "Document.h"
#include "App.h"
#include <memory>

namespace stk {
	RedoCmd::RedoCmd() {}

	RedoCmd::~RedoCmd() {}

	void RedoCmd::execute() {
		std::shared_ptr<stk::Document> doc = App::getInstance()->getActiveDoc();
		if (doc.use_count() == 0) {
			return;
		}
		std::deque<std::vector<Stroke>>* undo_stack = doc->getUndoStack();
		std::deque<std::vector<Stroke>>* redo_stack = doc->getRedoStack();
		state* curr_state = doc->getStrokes();
		if (redo_stack->empty())
		{
			return;
		}
		*curr_state = redo_stack->front();
		redo_stack->pop_front();
		undo_stack->push_front(*curr_state);
	}
}
