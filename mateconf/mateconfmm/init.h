#ifndef _MATECONFMM_INIT_H
#define _MATECONFMM_INIT_H

/* init.h
 *
 * Copyright (C) 2001 The mateconfimm Development Team
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

namespace Mate
{

namespace Conf
{

/* Initialize mateconfmm wrap table:
 * You still need a Gtk::Main instance, or a subclass such as Mate::Main.
 */
void init();

} /* namespace Conf */
} /* namespace Mate */

#endif // _MATECONFMM_INIT_H
