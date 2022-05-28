#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <memory>
#include "ICommand.h"
#include "framework.h"
#include "Point.h"
#include "Stroke.h"
#include <string>
namespace json11 {
    class Json;
}
namespace stk {
    class Document
    {
        Point<int32_t> ptPrevious;
        std::vector<Stroke> strokes;
        std::vector<Stroke> m_initial_strokes;
        std::deque<std::vector<Stroke>> undo_stack;
        std::deque<std::vector<Stroke>> redo_stack;
        void setStrokes(std::vector<Stroke>& stroke);
    public:
        Document();

        std::vector<Stroke>* getStrokes();

        std::vector<Stroke>* getinitialStrokes();

        std::deque<std::vector<Stroke>>* getUndoStack();

        std::deque<std::vector<Stroke>>* getRedoStack();

        void addStroke(Stroke newStroke);

        void save();

        std::string to_json();

        static Document from_json(const json11::Json &doc_json);

        void reset();

        void setInitialStrokes(std::vector<Stroke>& stroke);
        /*
        void undo();

        void redo();
        */
    };
}

