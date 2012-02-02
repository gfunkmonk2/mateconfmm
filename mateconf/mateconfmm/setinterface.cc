// -*- Mode: C++; c-basic-offset: 4  -*-

/* setinterface.cc
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
#include <glibmm/ustring.h>
#include "mateconfmm/setinterface.h"

namespace Mate
{
namespace Conf
{

#ifdef GLIBMM_EXCEPTIONS_ENABLED

void SetInterface::set(const Glib::ustring& key, const ValuePair& pair)
{
  Value v(VALUE_PAIR);
  v.set_car(pair.first); 
  v.set_cdr(pair.second); 
  this->set(key, v);
}

void SetInterface::set_int_list(const Glib::ustring& key,const SListHandle_ValueInt& list)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_INT);
  v.set_int_list(list);
  this->set(key, v);
}

void SetInterface::set_float_list(const Glib::ustring& key,const SListHandle_ValueFloat& list)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_FLOAT);
  v.set_float_list(list);
  this->set(key, v);
}

void SetInterface::set_bool_list(const Glib::ustring& key,const SListHandle_ValueBool& list)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_BOOL);
  v.set_bool_list(list);
  this->set(key, v);
}

void SetInterface::set_string_list(const Glib::ustring& key,const SListHandle_ValueString& list)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_STRING);
  v.set_string_list(list);
  this->set(key, v);
}

void SetInterface::set_schema_list(const Glib::ustring& key,const SListHandle_ValueSchema& list)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_SCHEMA);
  v.set_schema_list(list);
  this->set(key, v);
}

#else //GLIBMM_EXCEPTIONS_ENABLED

void SetInterface::set(const Glib::ustring& key, const ValuePair& pair, std::auto_ptr<Glib::Error>& error)
{
  Value v(VALUE_PAIR);
  v.set_car(pair.first); 
  v.set_cdr(pair.second); 
  this->set(key, v, error);
}

void SetInterface::set_int_list(const Glib::ustring& key,const SListHandle_ValueInt& list, std::auto_ptr<Glib::Error>& error)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_INT);
  v.set_int_list(list);
  this->set(key, v, error);
}

void SetInterface::set_float_list(const Glib::ustring& key,const SListHandle_ValueFloat& list, std::auto_ptr<Glib::Error>& error)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_FLOAT);
  v.set_float_list(list);
  this->set(key, v, error);
}

void SetInterface::set_bool_list(const Glib::ustring& key,const SListHandle_ValueBool& list, std::auto_ptr<Glib::Error>& error)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_BOOL);
  v.set_bool_list(list);
  this->set(key, v, error);
}

void SetInterface::set_string_list(const Glib::ustring& key,const SListHandle_ValueString& list, std::auto_ptr<Glib::Error>& error)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_STRING);
  v.set_string_list(list);
  this->set(key, v, error);
}

void SetInterface::set_schema_list(const Glib::ustring& key,const SListHandle_ValueSchema& list, std::auto_ptr<Glib::Error>& error)
{
  Value v(VALUE_LIST);
  v.set_list_type(VALUE_SCHEMA);
  v.set_schema_list(list);
  this->set(key, v, error);
}


#endif //GLIBMM_EXCEPTIONS_ENABLED

} /* namespace Conf */
} /* namespace Mate */
