// Generated by gtkmmproc -- DO NOT MODIFY!


#include <mateconfmm/changeset.h>
#include <mateconfmm/private/changeset_p.h>

// -*- Mode: C++; c-basic-offset: 4  -*-
/* $Id: changeset.ccg,v 1.3 2006/06/05 17:54:23 murrayc Exp $ */

/* changeset.ccg 
 * 
 * Copyright (C) 2002 MateConfmm Development Team
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

#include <mateconf/mateconf-changeset.h>
#include <mateconf/mateconf-value.h>
#include <mateconfmm/schema.h>

namespace Mate
{
namespace Conf
{

ChangeSet::ChangeSet() 
    : gobject_ (mateconf_change_set_new())
{}

ChangeSet::ChangeSet(const ChangeSet& src)
    : gobject_ ((src.gobject_) ? do_ref(src.gobject_) : 0)
{}

ChangeSet::ChangeSet(MateConfChangeSet* castitem, bool make_a_copy /* = false */)
{
  if(!make_a_copy)
  {
    gobject_ = castitem;
  }
  else
  {
    if(castitem)
      gobject_ = do_ref(castitem);
    else
      gobject_ = 0;
  }
}

ChangeSet& ChangeSet::operator=(const ChangeSet& src)
{
  MateConfChangeSet *const new_gobject = (src.gobject_) ? do_ref(src.gobject_) : 0;

  if(gobject_)
    mateconf_change_set_unref(gobject_);

  gobject_ = new_gobject;

  return *this;
}

ChangeSet::~ChangeSet()
{
  if(gobject_)
    mateconf_change_set_unref(gobject_);
}

MateConfChangeSet* ChangeSet::gobj_copy() const 
{
  return do_ref(gobject_);
}

Value* ChangeSet::exists(const Glib::ustring& key) const
{
  MateConfValue* gcv = 0;
  bool retval = (bool)mateconf_change_set_check_value(const_cast<MateConfChangeSet*>(gobj()),key.c_str(),&gcv);

  if(retval)
    return new Value(gcv,true);
  else
    return 0;
}

MateConfChangeSet* ChangeSet::do_ref(MateConfChangeSet* cs)
{
    mateconf_change_set_ref(cs);
    return cs;
}

static void for_each_helper(MateConfChangeSet *cs,
  const gchar *key,
  MateConfValue *value,
  gpointer user_data)
{
  ChangeSet::ForeachSlot *s = reinterpret_cast<ChangeSet::ForeachSlot*>(user_data);
  (*s)(key, Value(value, true));
}

void ChangeSet::for_each(const ForeachSlot& s)
{
    mateconf_change_set_foreach(gobj(),for_each_helper,
    (gpointer)(&(s)));
}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
void ChangeSet::set(const Glib::ustring& key, bool what)
{
  mateconf_change_set_set_bool(gobj(), key.c_str(), static_cast<int>(what)); 
}

void ChangeSet::set(const Glib::ustring& key, int what)
{
  mateconf_change_set_set_int(gobj(), key.c_str(), what); 
}

void ChangeSet::set(const Glib::ustring& key, double what)
{
  mateconf_change_set_set_float(gobj(), key.c_str(), what); 
}

void ChangeSet::set(const Glib::ustring& key, const Glib::ustring& what)
{
  mateconf_change_set_set_string(gobj(), key.c_str(), what.c_str()); 
}

void ChangeSet::set(const Glib::ustring& key, const Schema& val)
{
  mateconf_change_set_set_schema(gobj(), key.c_str(), const_cast<MateConfSchema*>((val).gobj())); 
}

void ChangeSet::set(const Glib::ustring& key, const Value& what)
{
  mateconf_change_set_set(gobj(), key.c_str(), const_cast<MateConfValue*>(what.gobj())); 
}

#else //GLIBMM_EXCEPTIONS_ENABLED

void ChangeSet::set(const Glib::ustring& key, bool what, std::auto_ptr<Glib::Error>& /* error */)
{
  mateconf_change_set_set_bool(gobj(), key.c_str(), static_cast<int>(what)); 
}

void ChangeSet::set(const Glib::ustring& key, int what, std::auto_ptr<Glib::Error>& /* error */)
{
  mateconf_change_set_set_int(gobj(), key.c_str(), what); 
}

void ChangeSet::set(const Glib::ustring& key, double what, std::auto_ptr<Glib::Error>& /* error */)
{
  mateconf_change_set_set_float(gobj(), key.c_str(), what); 
}

void ChangeSet::set(const Glib::ustring& key, const Glib::ustring& what, std::auto_ptr<Glib::Error>& /* error */)
{
  mateconf_change_set_set_string(gobj(), key.c_str(), what.c_str()); 
}

void ChangeSet::set(const Glib::ustring& key, const Schema& val, std::auto_ptr<Glib::Error>& /* error */)
{
  mateconf_change_set_set_schema(gobj(), key.c_str(), const_cast<MateConfSchema*>((val).gobj())); 
}

void ChangeSet::set(const Glib::ustring& key, const Value& what, std::auto_ptr<Glib::Error>& /* error */)
{
  mateconf_change_set_set(gobj(), key.c_str(), const_cast<MateConfValue*>(what.gobj())); 
}
#endif //GLIBMM_EXCEPTIONS_ENABLED


} /* namespace Conf */
} /* namespace Mate */

namespace
{
} // anonymous namespace


namespace Mate
{

namespace Conf
{


void ChangeSet::clear()
{
mateconf_change_set_clear(gobj()); 
}

unsigned int ChangeSet::size() const
{
  return mateconf_change_set_size(const_cast<MateConfChangeSet*>(gobj()));
}

void ChangeSet::remove(const Glib::ustring& key)
{
mateconf_change_set_remove(gobj(), key.c_str()); 
}

void ChangeSet::unset(const Glib::ustring& key)
{
mateconf_change_set_unset(gobj(), key.c_str()); 
}


} // namespace Conf

} // namespace Mate
