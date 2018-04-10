/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
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
****************************************************************************/

#pragma once

#include <projectexplorer/runconfiguration.h>
#include <projectexplorer/runnables.h>

#include <utils/fileutils.h>

namespace QmakeProjectManager {
namespace Internal {

class DesktopQmakeRunConfiguration : public ProjectExplorer::RunConfiguration
{
    Q_OBJECT

public:
    explicit DesktopQmakeRunConfiguration(ProjectExplorer::Target *target);

    QWidget *createConfigurationWidget() override;

    ProjectExplorer::Runnable runnable() const override;
    QVariantMap toMap() const override;

    void addToBaseEnvironment(Utils::Environment &env) const;

signals:
    void baseWorkingDirectoryChanged(const QString&);

    // Note: These signals might not get emitted for every change!
    void effectiveTargetInformationChanged();

private:
    bool fromMap(const QVariantMap &map) override;

    void updateTargetInformation();
    void doAdditionalSetup(const ProjectExplorer::RunConfigurationCreationInfo &info) final;

    QString defaultDisplayName();
    bool canRunForNode(const ProjectExplorer::Node *node) const final;

    Utils::FileName proFilePath() const;
};

class DesktopQmakeRunConfigurationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DesktopQmakeRunConfigurationWidget(ProjectExplorer::RunConfiguration *rc);

private:
    ProjectExplorer::RunConfiguration *m_runConfiguration = nullptr;
};

class DesktopQmakeRunConfigurationFactory : public ProjectExplorer::RunConfigurationFactory
{
public:
    DesktopQmakeRunConfigurationFactory();
};

} // namespace Internal
} // namespace QmakeProjectManager
