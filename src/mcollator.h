/***************************************************************************
**
** Copyright (C) 2010, 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of libmeegotouch.
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#ifndef ML10N_MCOLLATOR_H
#define ML10N_MCOLLATOR_H

#include "mlocaleexport.h"
#include "mlocale.h"

class QString;

namespace ML10N {

class MCollatorPrivate;

class MLOCALE_EXPORT MCollator
{
public:
    MCollator();
    MCollator(const MLocale &locale);
    MCollator(const MCollator &other);
    virtual ~MCollator();

    /*!
     * \brief returns the strength of an MCollator
     *
     * \sa setStrength(MLocale::CollatorStrength collatorStrength)
     */
    MLocale::CollatorStrength strength() const;

    /*!
     * \brief sets the strength of an MCollator
     *
     * \sa strength()
     */
    void setStrength(MLocale::CollatorStrength collatorStrength);

    bool operator()(const QString &s1, const QString &s2) const;

    static MLocale::Comparison compare(const QString &first, const QString &second);

    static MLocale::Comparison compare(MLocale &locale, const QString &first,
                                         const QString &second);

    MCollator &operator=(const MCollator &other);

private:
    // not implemented
    bool operator==(const MCollator &other) const;
    bool operator!=(const MCollator &other) const;

    Q_DECLARE_PRIVATE(MCollator)
    MCollatorPrivate *const d_ptr;

    friend class MLocale;
};

}

#endif
