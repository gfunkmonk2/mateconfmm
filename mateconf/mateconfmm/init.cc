/* init.cc
 *
 * Copyright (C) 2001 The libmateuimm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <mateconfmm/init.h>
#include <glibmm/init.h>
#include <glibmm/error.h>
#include <mateconfmm/wrap_init.h>

namespace Mate
{

namespace Conf
{

void init()
{
  //Glib::Main::init_gtkmm_internals(); //Sets up the g type system and the Glib::wrap() table.

  //Intitialize glibmm:
  Glib::init();

  //There is no mateconf_init() - well, it's deprecated.
  wrap_init(); //Tells the Glib::wrap() table about the mateconfmm classes.
}

} /* namespace Conf */
} /* namespace Mate */
