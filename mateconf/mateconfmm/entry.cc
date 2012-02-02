// Generated by gtkmmproc -- DO NOT MODIFY!


#include <mateconfmm/entry.h>
#include <mateconfmm/private/entry_p.h>

// -*- Mode: C++; c-basic-offset: 4  -*-
/* $Id: entry.ccg,v 1.3 2002/11/26 19:58:13 murrayc Exp $ */

/* entry.ccg
 *
 * Copyright (C) 2000-2002 MateConfmm Development Team
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

Entry::Entry(const Glib::ustring& key, const Value& val)
{
  gobject_ = mateconf_entry_new(key.c_str(), const_cast<MateConfValue*>(val.gobj()));
}

// There is no mateconf_entry_copy, so we provide one...
MateConfEntry* Entry::entry_copy(const MateConfEntry* entry)
{
  if(entry == 0)
    return 0;

  MateConfEntry* retval = mateconf_entry_new(mateconf_entry_get_key(entry), mateconf_entry_get_value(entry) );

  mateconf_entry_set_schema_name(retval, mateconf_entry_get_schema_name(entry) );
  mateconf_entry_set_is_default(retval, mateconf_entry_get_is_default(entry) );
  mateconf_entry_set_is_writable(retval, mateconf_entry_get_is_writable(entry) );
  return retval;
}

Value Entry::get_value() const
{
  return Value(mateconf_entry_get_value(gobj()), true);
}
  
} /* namespace Conf */
} /* namespace Mate */

namespace
{
} // anonymous namespace


namespace Glib
{

Mate::Conf::Entry wrap(MateConfEntry* object, bool take_copy /* = false */)
{
  return Mate::Conf::Entry(object, take_copy);
}

} // namespace Glib


namespace Mate
{

namespace Conf
{


Entry::Entry()
:
  gobject_ (0) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

Entry::Entry(const Entry& src)
:
  gobject_ ((src.gobject_) ? entry_copy(src.gobject_) : 0)
{}

Entry::Entry(MateConfEntry* castitem, bool make_a_copy /* = false */)
{
  if(!make_a_copy)
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
  else
  {
    // We are probably getting it via direct access to a struct,
    // so we can not just take it - we have to take a copy of it.
    if(castitem)
      gobject_ = entry_copy(castitem);
    else
      gobject_ = 0;
  }
}

Entry& Entry::operator=(const Entry& src)
{
  MateConfEntry *const new_gobject = (src.gobject_) ? entry_copy(src.gobject_) : 0;

  if(gobject_)
    mateconf_entry_free(gobject_);

  gobject_ = new_gobject;

  return *this;
}

Entry::~Entry()
{
  if(gobject_)
    mateconf_entry_free(gobject_);
}

MateConfEntry* Entry::gobj_copy() const
{
  return entry_copy(gobject_);
}


void Entry::set_value(const Value& val)
{
mateconf_entry_set_value(gobj(), (val).gobj()); 
}

void Entry::set_schema_name(const Glib::ustring& val)
{
mateconf_entry_set_schema_name(gobj(), val.c_str()); 
}

void Entry::set_is_default(bool is_default)
{
mateconf_entry_set_is_default(gobj(), static_cast<int>(is_default)); 
}

void Entry::set_is_writable(bool is_writable)
{
mateconf_entry_set_is_writable(gobj(), static_cast<int>(is_writable)); 
}

Glib::ustring Entry::get_schema_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(mateconf_entry_get_schema_name(const_cast<MateConfEntry*>(gobj())));
}

Glib::ustring Entry::get_key() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(mateconf_entry_get_key(const_cast<MateConfEntry*>(gobj())));
}

bool Entry::get_is_default() const
{
  return mateconf_entry_get_is_default(const_cast<MateConfEntry*>(gobj()));
}

bool Entry::get_is_writable() const
{
  return mateconf_entry_get_is_writable(const_cast<MateConfEntry*>(gobj()));
}


} // namespace Conf

} // namespace Mate
