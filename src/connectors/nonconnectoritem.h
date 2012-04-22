/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2011 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 5442 $:
$Author: cohen@irascible.com $:
$Date: 2011-08-28 23:10:08 -0700 (Sun, 28 Aug 2011) $

********************************************************************/

#ifndef NONCONNECTORITEM_H
#define NONCONNECTORITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QPen>
#include <QBrush>
#include <QXmlStreamWriter>
#include <QPointer>

#include "../items/itembase.h"

class NonConnectorItem : public QObject, public QGraphicsRectItem
{
Q_OBJECT

public:
	NonConnectorItem(ItemBase* attachedTo);
	~NonConnectorItem();

	ItemBase * attachedTo();
	virtual void setHidden(bool hidden);
	bool hidden();
	virtual void setInactive(bool inactivate);
	bool inactive();
	long attachedToID();
	const QString & attachedToTitle();
	const QString & attachedToInstanceTitle();
	void setCircular(bool);
	void setRadius(double radius, double strokeWidth);
	double radius();
	double strokeWidth();
	void setShape(QPainterPath &);
	void paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
	QPainterPath shape() const;

protected:
	bool doNotPaint();

	enum Effectively {
		EffectivelyCircular = 1,
		EffectivelyRectangular,
		EffectivelyPolygonal,
		EffectivelyUnknown
	};

protected:
	QPointer<ItemBase> m_attachedTo;
	bool m_hidden;
	bool m_inactive;
	bool m_paint;
	double m_opacity;
	bool m_circular;
	Effectively m_effectively;
	double m_radius;
	double m_strokeWidth;
	double m_negativePenWidth;
	bool m_negativeOffsetRect;
	QPainterPath m_shape;
	
};

#endif
