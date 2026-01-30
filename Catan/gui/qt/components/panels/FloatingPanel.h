#ifndef FLOATINGPANEL_H
#define FLOATINGPANEL_H

#include <QFrame>
#include "FloatingPanel.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>

class FloatingPanel : public QFrame {
    Q_OBJECT
private:
    bool m_activeHighlight = false;
public:
    explicit FloatingPanel(QWidget* parent=nullptr) : QFrame(parent) {
        setFrameStyle(QFrame::NoFrame);
        setAttribute(Qt::WA_StyledBackground, true);
        setStyleSheet(R"(
            FloatingPanel {
                background: rgba(245,245,245,230);
                border-radius: 10px;
            }
        )");
        setMouseTracking(true);
    }
    explicit FloatingPanel(Qt::WindowType type, QWidget* parent=nullptr) : QFrame(parent, type) {
        setFrameStyle(QFrame::NoFrame);
        setAttribute(Qt::WA_StyledBackground, true);
        setStyleSheet(R"(
            FloatingPanel {
                background: rgba(245,245,245,230);
                border-radius: 10px;
            }
        )");
        setMouseTracking(true);
    }
    void setActiveHighlight(bool on) { m_activeHighlight = on; update(); }
    bool activeHighlight() const { return m_activeHighlight; }
    void paintEvent(QPaintEvent* e) override;
};

#endif // FLOATINGPANEL_H
