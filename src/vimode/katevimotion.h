/*  This file is part of the KDE libraries and the Kate part.
 *
 *  Copyright (C) 2008 Erlend Hamberg <ehamberg@gmail.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#ifndef KATE_VI_MOTION_INCLUDED
#define KATE_VI_MOTION_INCLUDED

#include "katevicommand.h"
#include <vimode/range.h>
#include <ktexteditor_export.h>

namespace KateVi { class NormalMode; }

/**
 * combined class for motions and text objects. execute() returns a KateViRange.
 * For motions the returned range is only a position (start pos is (-1, -1) to
 * indicate this) for text objects a range (startx, starty), (endx, endy) is
 * returned
 */

class KTEXTEDITOR_EXPORT KateViMotion : public KateViCommand
{
public:
    KateViMotion(KateVi::NormalMode *parent, const QString &pattern,
                 KateVi::Range(KateVi::NormalMode::*commandMethod)(), unsigned int flags = 0);
    KateVi::Range execute() const;

protected:
    KateVi::Range(KateVi::NormalMode::*m_ptr2commandMethod)();
};

#endif
