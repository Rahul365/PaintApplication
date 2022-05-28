#pragma once

#include "resource.h"
#include "Stroke.h"
#include "ICommand.h"


namespace stk {
    class Screen {
        BOOL draw = false;
        Point<int32_t> ptPrevious;
        stk::Stroke stroke;
    public:
        Screen();
        /*
        Stroke Cycle Functions :
        1)OnMouseDOWN() : when the mouse left key is pressed down, start drawing from that point inclusively
        2)OnMouseMove() : if(drawing is enabled) then draw every point as the mouse moves
        3)OnMouseUp() : when the mouse left key is released, end point is drawn on the window then stroke is recorded and drawing is disabled.
        */
        void OnMouseDOWN(LPARAM& lParam);

        void OnMouseUp(HWND& hWnd, LPARAM& lParam);

        void reDrawAllStrokes(HWND& hWnd);

        void OnMouseMove(HWND& hWnd, LPARAM& lParam);
    };
}
