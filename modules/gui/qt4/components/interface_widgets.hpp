/*****************************************************************************
 * interface_widgets.hpp : Custom widgets for the main interface
 ****************************************************************************
 * Copyright (C) 2006 the VideoLAN team
 * $Id$
 *
 * Authors: Clément Stenac <zorglub@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef _INTFWIDGETS_H_
#define _INTFWIDGETS_H_

#include <vlc/vlc.h>
#include <vlc/intf.h>
#include <QWidget>
#include <QFrame>
#include <QPalette>
#include <QResizeEvent>
#include <QPixmap>

class QLabel;
class QHBoxLayout;

/******************** Video Widget ****************/
class VideoWidget : public QFrame
{
    Q_OBJECT
public:
    VideoWidget( intf_thread_t * );
    virtual ~VideoWidget();

    void *request( vout_thread_t *, int *, int *,
                   unsigned int *, unsigned int * );
    void release( void * );
    int control( void *, int, va_list );

    int i_video_height, i_video_width;
    vout_thread_t *p_vout;

    QSize widgetSize;
    virtual QSize sizeHint() const;
private:
    QWidget *frame;
    intf_thread_t *p_intf;
    vlc_mutex_t lock;
};

/******************** Background Widget ****************/
class BackgroundWidget : public QFrame
{
    Q_OBJECT
public:
    BackgroundWidget( intf_thread_t * );
    virtual ~BackgroundWidget();
    QSize widgetSize;
    virtual QSize sizeHint() const;
private:
    QPalette plt;
    QLabel *label;
    QHBoxLayout *backgroundLayout;
    virtual void resizeEvent( QResizeEvent *e );
    int DrawBackground();
    int CleanBackground();
    intf_thread_t *p_intf;
};

class VisualSelector : public QFrame
{
    Q_OBJECT
public:
    VisualSelector( intf_thread_t *);
    virtual ~VisualSelector();
private:
    intf_thread_t *p_intf;
};

/******************** Playlist Widget ****************/
#include <QModelIndex>
class QSignalMapper;
class PLSelector;
class PLPanel;

class PlaylistWidget : public QFrame
{
    Q_OBJECT;
public:
    PlaylistWidget( intf_thread_t * );
    virtual ~PlaylistWidget();
    QSize widgetSize;
    virtual QSize sizeHint() const;
private:
    PLSelector *selector;
    PLPanel *rightPanel;
    intf_thread_t *p_intf;
};

#endif
