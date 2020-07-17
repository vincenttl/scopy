/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Copyright (c) 2020 Analog Devices Inc.
 *
 * This file is part of Scopy
 * (see http://www.github.com/analogdevicesinc/scopy).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef PULSEVIEW_PV_BINDING_BINDING_HPP
#define PULSEVIEW_PV_BINDING_BINDING_HPP

#include <glib.h>
// Suppress warnings due to use of deprecated std::auto_ptr<> by glibmm.
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
#include <glibmm.h>
G_GNUC_END_IGNORE_DEPRECATIONS

#include <map>
#include <memory>
#include <vector>

#include <QObject>
#include <QString>

using std::map;
using std::shared_ptr;
using std::vector;

class QFormLayout;
class QLabel;
class QWidget;

namespace adiscope {

namespace prop {
class Property;
}

namespace bind {

class Binding: public QObject
{
	Q_OBJECT

public:
	const vector< shared_ptr<prop::Property> >& properties();

	void commit();

	void add_properties_to_form(QFormLayout *layout, bool auto_commit = false);

	QWidget* get_property_form(QWidget *parent, bool auto_commit = false);

	void update_property_widgets();

	static QString print_gvariant(Glib::VariantBase gvar);

protected Q_SLOTS:
	void on_help_clicked();

protected:
	vector< shared_ptr<prop::Property> > properties_;
	map<QWidget*, QLabel*> help_labels_;
};

}  // namespace binding
}  // namespace pv

#endif // PULSEVIEW_PV_BINDING_BINDING_HPP
