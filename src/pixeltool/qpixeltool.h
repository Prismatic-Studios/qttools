/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QPIXELTOOL_H
#define QPIXELTOOL_H

#include <qwidget.h>
#include <qpixmap.h>

QT_BEGIN_NAMESPACE

class QPixelTool : public QWidget
{
    Q_OBJECT
public:
    explicit QPixelTool(QWidget *parent = nullptr);
    ~QPixelTool();

    void setPreviewImage(const QImage &image);

    QSize sizeHint() const override;

public slots:
    void setZoom(int zoom);
    void setGridSize(int gridSize);
    void toggleGrid();
    void toggleFreeze();
    void setZoomVisible(bool visible);
#if QT_CONFIG(clipboard)
    void copyToClipboard();
    void copyColorToClipboard();
#endif
    void saveToFile();
    void increaseGridSize() { setGridSize(m_gridSize + 1); }
    void decreaseGridSize() { setGridSize(m_gridSize - 1); }
    void increaseZoom();
    void decreaseZoom();
    void aboutPixelTool();

protected:
    void timerEvent(QTimerEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void grabScreen();
    void startZoomVisibleTimer();
    void startGridSizeVisibleTimer();
    QString aboutText() const;

    bool m_freeze = false;
    bool m_displayZoom = false;
    bool m_displayGridSize = false;
    bool m_mouseDown = false;
    bool m_autoUpdate;
    bool m_preview_mode = false;

    int m_gridActive;
    int m_zoom;
    int m_gridSize;
    int m_lcdMode;

    int m_updateId;
    int m_displayZoomId = 0;
    int m_displayGridSizeId = 0;

    QRgb m_currentColor = 0;

    QPoint m_lastMousePos;
    QPoint m_dragStart;
    QPoint m_dragCurrent;
    QPixmap m_buffer;

    QSize m_initialSize;

    QImage m_preview_image;
};

QT_END_NAMESPACE

#endif // QPIXELTOOL_H
