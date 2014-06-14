/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the tools applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef APPXPHONEENGINE_H
#define APPXPHONEENGINE_H

#include "appxengine.h"
#include "runnerengine.h"
#include "runner.h"

#include <QtCore/QScopedPointer>

QT_USE_NAMESPACE

class AppxPhoneEnginePrivate;
class AppxPhoneEngine : public AppxEngine
{
public:
    static bool canHandle(Runner *runner);
    static RunnerEngine *create(Runner *runner);
    static QStringList deviceNames();

    bool install(bool removeFirst = false) Q_DECL_OVERRIDE;
    bool remove() Q_DECL_OVERRIDE;
    bool start() Q_DECL_OVERRIDE;
    bool enableDebugging(const QString &debuggerExecutable,
                        const QString &debuggerArguments) Q_DECL_OVERRIDE;
    bool disableDebugging() Q_DECL_OVERRIDE;
    bool suspend() Q_DECL_OVERRIDE;
    bool waitForFinished(int secs) Q_DECL_OVERRIDE;
    bool stop() Q_DECL_OVERRIDE;

    QString devicePath(const QString &relativePath) const Q_DECL_OVERRIDE;
    bool sendFile(const QString &localFile, const QString &deviceFile) Q_DECL_OVERRIDE;
    bool receiveFile(const QString &deviceFile, const QString &localFile) Q_DECL_OVERRIDE;

private:
    explicit AppxPhoneEngine(Runner *runner);
    ~AppxPhoneEngine();

    QString extensionSdkPath() const;
    bool installPackage(IAppxManifestReader *reader, const QString &filePath) Q_DECL_OVERRIDE;

    bool connect();

    friend struct QScopedPointerDeleter<AppxPhoneEngine>;
    Q_DECLARE_PRIVATE(AppxPhoneEngine)
};

#endif // APPXPHONEENGINE_H
