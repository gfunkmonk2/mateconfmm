// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _MATECONFMM_VALUE_H
#define _MATECONFMM_VALUE_H


#include <glibmm.h>

// -*- Mode: C++; c-basic-offset: 4  -*-
/* $Id: value.hg,v 1.3 2004/12/12 22:04:01 murrayc Exp $ */

/* value.hg
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
#include <mateconfmm/value_listhelpers.h>


namespace Mate
{

namespace Conf
{

/** @addtogroup mateconfmmEnums Enums and Flags */

/**
 * @ingroup mateconfmmEnums
 */
enum ValueType
{
  VALUE_INVALID,
  VALUE_STRING,
  VALUE_INT,
  VALUE_FLOAT,
  VALUE_BOOL,
  VALUE_SCHEMA,
  VALUE_LIST,
  VALUE_PAIR
};

} // namespace Conf

} // namespace Mate


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Mate::Conf::ValueType> : public Glib::Value_Enum<Mate::Conf::ValueType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Mate
{

namespace Conf
{

/**
 * @ingroup mateconfmmEnums
 */
enum UnsetFlags
{
  UNSET_INCLUDING_SCHEMA_NAMES
};

} // namespace Conf

} // namespace Mate


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Mate::Conf::UnsetFlags> : public Glib::Value_Enum<Mate::Conf::UnsetFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Mate
{

namespace Conf
{


typedef std::pair<Value, Value> ValuePair;    
typedef std::pair<ValueType, ValueType> ValueTypePair;

/** Wrapper for primitive types.
 * This class wraps the primitive types that are passed to 
 * and from instances of Mate::Conf::Client. It has an associated 
 * @c ValueType, which is specified at creation time, 
 * but can be changed with assignment. If the type is @c VALUE_INVALID then the effect
 * of the set and get methods is undefined. Using a default-constructed
 * Value without using any of the set methods produces undefined
 * behaviour.
 *
 * Compound Values of type VALUE_PAIR and VALUE_LIST can only have 
 * elements whose types are neither VALUE_PAIR or VALUE_LIST - they can only have primitive types.
 *
 * The Value class has copy-by-value semantics - all arguments to the
 * set methods are copied.
 * 
 * Note that while the type is named VALUE_FLOAT, the accessors for 
 * floating-point values use @c double, not @c float, to preserve 
 * accuracy.
 */
class Value 
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Value CppObjectType;
  typedef MateConfValue BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  // Use make_a_copy=true when getting it directly from a struct.
  explicit Value(MateConfValue* castitem, bool make_a_copy = false);

  Value(const Value& src);
  Value& operator=(const Value& src);

  ~Value();

  MateConfValue*       gobj()       { return gobject_; }
  const MateConfValue* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  MateConfValue* gobj_copy() const;

protected:
  MateConfValue* gobject_;

private:

  
public:

  /** Create a Value.
   * You should call a set() method before using the Value.
   * @param type: The type of the produced value.
   */
  Value(ValueType type = VALUE_INVALID);

  /** Set the integer value of a Value whose type is VALUE_INT
   */
  
  void set(gint val);

  /** Set the float value of a Value whose type is VALUE_FLOAT
   * @param val: the @c double this Value will be se to.
   */
  
  void set(gdouble val);

  /** Set the boolean value of a Value whose type is VALUE_BOOL */
  
  void set(bool val);

  /** Set the Schema of a Value whose type is VALUE_SCHEMA */
  
  void set(const Schema& sc);

  /** Set the car (in a pair, the first element) of a Value whose type is VALUE_PAIR */
  
  void set_car(const Value& car);

  /** Set the cdr (in a pair, the second element) of a Value whose type is VALUE_PAIR */
  
  void set_cdr(const Value& cdr);

  /** Set the string of a Value whose type is VALUE_STRING */
  
  void set(const Glib::ustring& val);
  

  /** Sets the type of the elements of a Value with type VALUE_LIST */
  
  void set_list_type(ValueType type);

  /** Sets the Value to contain a list of integers.
   * set_list_type(VALUE_INT) must have been called prior this call.
   * @param list: an STL-compatible container whose value_type is @c int
   */
  
  void set_int_list(const SListHandle_ValueInt& list);

  /** Sets the Value to contain a list of bools.
   * @see set_int_list */
  
  void set_bool_list(const SListHandle_ValueBool& list);

  /** Sets the Value to contain a list of doubles.
   * @see set_int_list */
  
  void set_float_list(const SListHandle_ValueFloat& list);

  /** Sets the Value to contain a list of strings.
   * @see set_int_list */
  
  void set_string_list(const SListHandle_ValueString& list);

  /** Sets the Value to contain a list of Schema.
   * @see set_int_list */
  
  void set_schema_list(const SListHandle_ValueSchema& list);
  

  /** Get the type of the Value.
   * @return the type of the Value
   */
  ValueType get_type() const;
  

  /** Get the type of the list elements of the Value.
   * Do not call this method on non-list Values.
   * @return the type of the list elements.
   */
  
  ValueType get_list_type() const;

  /** Get the integer that the Value contains */
  
  int get_int() const;

  /** Get the boolean that the Value contains */
  
  bool get_bool() const;

  /** Get the double that the Value contains */
  
  double get_float() const;

  /** Get the string that the Value contains */
  
  Glib::ustring get_string() const;
  

  /** Get a copy of the Schema of the value.. */
  Schema get_schema() const;
  

  /** Get a copy of the car of a VALUE_PAIR Value */
  Value get_car() const;

  /** Get a copy of the cdr of a VALUE_PAIR Value */
  Value get_cdr() const;

  /** Gets a list of doubles from the Value.
   * Typical usage is
   * @code
   * std::vector<double> foo = value.get_float_list();
   * @endcode.
   * @return: an STL-compatible container with doubles as its value type.
   * Assign to an std::vector, list or deque for proper use.
   */
  
  SListHandle_ValueFloat  get_float_list() const;

  /** Retrieves the list of integers from the Value.
   * @see get_float_list
   */
  
  SListHandle_ValueInt    get_int_list() const;

  /** Retrieves the list of booleans from the Value.
   * @see get_float_list
   */
  
  SListHandle_ValueBool   get_bool_list() const;

  /** Retrieves the list of strings from the Value.
   * @see get_float_list
   */
  
  SListHandle_ValueString get_string_list() const;

  /** Retrieves the list of Schemas from the Value.
   * @See get_float_list
   */
  
  SListHandle_ValueSchema get_schema_list() const;

  /** Convert the Value to a string.
   * The string is not machine-parseable. Do not depend on the
   * format of the string.
   */
  
  Glib::ustring to_string() const;


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
   * @relates Mate::Conf::Value
   */
Mate::Conf::Value wrap(MateConfValue* object, bool take_copy = false);

} // namespace Glib


#endif /* _MATECONFMM_VALUE_H */
