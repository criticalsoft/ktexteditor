/*
    SPDX-FileCopyrightText: 2011-2018 Dominik Haumann <dhaumann@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef VARIABLE_LIST_VIEW_H
#define VARIABLE_LIST_VIEW_H

#include <QMap>
#include <QScrollArea>

class VariableItem;
class VariableEditor;

class VariableListView : public QScrollArea
{
    Q_OBJECT

public:
    explicit VariableListView(const QString &variableLine, QWidget *parent = nullptr);
    ~VariableListView() override;

    void addItem(VariableItem *item);

    /// always returns the up-to-date variables line
    QString variableLine();

Q_SIGNALS:
    void aboutToHide();
    void changed(); // unused right now

protected:
    void resizeEvent(QResizeEvent *event) override;
    void hideEvent(QHideEvent *event) override;

    void parseVariables(const QString &line);

    QVector<VariableItem *> m_items;
    QVector<VariableEditor *> m_editors;

    QMap<QString, QString> m_variables;
};

#endif
