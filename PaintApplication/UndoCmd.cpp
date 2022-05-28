#include "UndoCmd.h"
#include "App.h"
#include "Document.h"
#include <memory>
namespace stk {
	UndoCmd::UndoCmd() {

	}

	UndoCmd::~UndoCmd() {

	}

	void UndoCmd::execute() {
		std::shared_ptr<stk::Document> doc = App::getInstance()->getActiveDoc();
		if (doc.use_count() == 0) {
			return;
		}
		std::deque<std::vector<Stroke>> *undo_stack = doc->getUndoStack();
		std::deque<std::vector<Stroke>> *redo_stack = doc->getRedoStack();
		state *curr_state = doc->getStrokes();
		/*Logic for UNDO operation*/
		if (undo_stack->empty()) return;
		redo_stack->push_front(undo_stack->front()); undo_stack->pop_front();
		if (!undo_stack->empty())
		{
			*curr_state = undo_stack->front();
		}
		else
			*curr_state = state();
	}
}