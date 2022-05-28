#pragma once
#include "PaintApplication.h"
#include "framework.h"
#include <iostream>
#include <memory.h>
#include <stack>
#include "Stroke.h"
#define UNDO_LIMIT 10
/*Enum class containing custom commandCodes*/
enum class CommandCodes {
	Undo, Redo
};


using state = std::vector<stk::Stroke>;
namespace stk{
	/*Generic Command Interface*/
	class ICommand
	{
	  public:
		  /*Execute the command*/
		  virtual void execute() = 0;
	};
}
/*
class UndoCommand : public CommandInterface {
	public:
	UndoCommand(){}
	~UndoCommand(){}
	void info() {
		OutputDebugStringA("This command undo max upto 10 strokes (or less if any)\n");
	}

	void execute(state& curr_state, std::stack<state> &undo_stack, std::stack<state> &redo_stack) {
		OutputDebugStringA("UNDO Command executed...\n");
		//Logic for UNDO operation
		if (undo_stack.empty()) return;
		redo_stack.push(undo_stack.top()); undo_stack.pop();
		if (!undo_stack.empty())
			curr_state = undo_stack.top();
		else
			curr_state = state();
	}
};


class RedoCommand : public CommandInterface {
public:
	RedoCommand() {}
	void info() {
		OutputDebugStringA("This command redo max upto 10 strokes(or less if any)\n");
	}

	void execute(state& curr_state, std::stack<state>& undo_stack, std::stack<state>& redo_stack) {
		OutputDebugStringA("REDO Command executed...\n");
		//Logic for REDO operation
		if (redo_stack.empty())
		{
			return;
		}
		curr_state = redo_stack.top();
		redo_stack.pop();
		undo_stack.push(curr_state);
	}
};

*/