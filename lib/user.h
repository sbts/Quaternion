/******************************************************************************
 * Copyright (C) 2015 Felix Rohrbach <kde@fxrh.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef QMATRIXCLIENT_USER_H
#define QMATRIXCLIENT_USER_H

#include <QtCore/QString>
#include <QtCore/QObject>

namespace QMatrixClient
{
    class Event;
    class User: public QObject
    {
            Q_OBJECT
        public:
            User(QString userId);
            virtual ~User();

            /**
             * Returns the id of the user
             */
            QString id() const;

            /**
             * Returns the name chosen by the user
             */
            QString name() const;

            /**
             * Returns the name that should be used to display the user.
             */
            QString displayname() const;

            void processEvent(Event* event);

        signals:
            void nameChanged();

        private:
            class Private;
            Private* d;
    };
}

#endif // QMATRIXCLIENT_USER_H