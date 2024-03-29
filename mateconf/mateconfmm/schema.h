// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _MATECONFMM_SCHEMA_H
#define _MATECONFMM_SCHEMA_H


#include <glibmm.h>

// -*- Mode: C++; c-basic-offset: 4  -*-
/* $Id: schema.hg,v 1.5 2002/12/10 23:26:01 murrayc Exp $ */

/* schema.hg
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

#include <mateconfmm/value.h>


extern "C" {
    // TODO: do not include this.
#include <mateconf/mateconf-schema.h>
}

namespace Mate
{

namespace Conf
{

class Value;

class Schema 
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Schema CppObjectType;
  typedef MateConfSchema BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Schema();

  // Use make_a_copy=true when getting it directly from a struct.
  explicit Schema(MateConfSchema* castitem, bool make_a_copy = false);

  Schema(const Schema& src);
  Schema& operator=(const Schema& src);

  ~Schema();

  MateConfSchema*       gobj()       { return gobject_; }
  const MateConfSchema* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  MateConfSchema* gobj_copy() const;

protected:
  MateConfSchema* gobject_;

private:

  
public:
  
  void set_type(ValueType type);
  
  void set_list_type(ValueType type);
  
  void set_car_type(ValueType type);
  
  void set_cdr_type(ValueType type);
  
  void set_locale(const std::string& locale);
  
  void set_short_desc(const Glib::ustring& desc);
  
  void set_long_desc(const Glib::ustring& desc);
  
  void set_owner(const Glib::ustring& owner);
  
  void set_default_value(const Value& value);
  

  ValueType get_type() const;
  
  ValueType get_list_type() const;
  
  ValueType get_car_type() const;
  
  ValueType get_cdr_type() const;
  
  std::string get_locale() const;
  
  Glib::ustring get_short_desc() const;
  
  Glib::ustring get_long_desc() const;
  
  Glib::ustring get_owner() const;
  
  Value get_default_value() const;
    

};


} /* namespace Conf */
} /* namespace Mate */


namespace Glib
{

  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Mate::Conf::Schema
   */
Mate::Conf::Schema wrap(MateConfSchema* object, bool take_copy = false);

} // namespace Glib


#endif /* _MATECONFMM_SCHEMA_H */
