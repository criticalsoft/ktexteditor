/*
    SPDX-FileCopyrightText: 2008 Erlend Hamberg <ehamberg@gmail.com>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KATEVI_MOTION_H
#define KATEVI_MOTION_H

#include <ktexteditor_export.h>
#include <vimode/command.h>
#include <vimode/modes/normalvimode.h>
#include <vimode/range.h>

namespace KateVi
{
/**
 * combined class for motions and text objects. execute() returns a KateViRange.
 * For motions the returned range is only a position (start pos is (-1, -1) to
 * indicate this) for text objects a range (startx, starty), (endx, endy) is
 * returned
 */
class KTEXTEDITOR_EXPORT Motion : public Command
{
public:
    Motion(NormalViMode *parent, const QString &pattern, Range (NormalViMode::*commandMethod)(), unsigned int flags = 0);
    Range execute() const;

protected:
    Range (NormalViMode::*m_ptr2commandMethod)();
};

}

#endif /* KATEVI_MOTION_H */
