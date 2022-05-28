#include "Screen.h"
#include "framework.h"
#include "App.h"
#include "Document.h"

namespace stk {
    Screen::Screen() {
        draw = false;
        ptPrevious = Point<int32_t>();
    }

    void Screen::OnMouseDOWN(LPARAM& lParam) {
        stroke = Stroke();
        draw = TRUE;
        ptPrevious.x = LOWORD(lParam);
        ptPrevious.y = HIWORD(lParam);
        stroke.push(ptPrevious);
    }

    void Screen::OnMouseUp(HWND& hWnd, LPARAM& lParam) {
        if (draw)
        {
            HDC hdc = GetDC(hWnd);
            MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
            LineTo(hdc, LOWORD(lParam), HIWORD(lParam));
            ReleaseDC(hWnd, hdc);
            stroke.push(ptPrevious);
        }
        draw = FALSE;
        App::getInstance()->getActiveDoc()->addStroke(stroke);
    }

    void Screen::reDrawAllStrokes(HWND& hWnd) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        {
            state* strokes = App::getInstance()->getActiveDoc()->getinitialStrokes();
            // TODO: Add any drawing code that uses hdc here...
            for (Stroke& stroke : *strokes) {
                if (stroke.size() >= 2)
                for (size_t index = 0; index + 1 != stroke.size(); index++) {
                    Point<int32_t>* A = stroke.get(index);
                    Point<int32_t>* B = stroke.get(index + 1);
                    MoveToEx(hdc, A->x, A->y, NULL);
                    LineTo(hdc, B->x, B->y);
                }
            }
        }
        
        {
            state* strokes = App::getInstance()->getActiveDoc()->getStrokes();
            // TODO: Add any drawing code that uses hdc here...
            for (Stroke& stroke : *strokes) {
                if(stroke.size()>=2)
                for (size_t index = 0; index + 1 != stroke.size(); index++) {
                    Point<int32_t>* A = stroke.get(index);
                    Point<int32_t>* B = stroke.get(index + 1);
                    MoveToEx(hdc, A->x, A->y, NULL);
                    LineTo(hdc, B->x, B->y);
                }
            }
        }
        EndPaint(hWnd, &ps);
    }

    void Screen::OnMouseMove(HWND& hWnd, LPARAM& lParam) {
        if (draw)
        {
            HDC hdc = GetDC(hWnd);
            MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
            LineTo(hdc, ptPrevious.x = LOWORD(lParam), ptPrevious.y = HIWORD(lParam));
            ReleaseDC(hWnd, hdc);
            stroke.push(ptPrevious);
        }
    }
}
