// -*- Mode: C++; c-basic-offset: 4  -*-

/* setinterface.h
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
#ifndef MATECONFMM_SET_INTERFACE_H
#define MATECONFMM_SET_INTERFACE_H
#include <mateconfmm/value.h>

/* Suppress no virtual destructor warning so -Werror can be used.
 */
#if (__GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96))
#pragma GCC system_header
#endif

namespace Mate
{
namespace Conf
{

/** Common Interface for key-value settable objects.
 * This class defines a common interface for MateConfmm objects that
 * implement the set() methods for configuration keys. It also 
 * provides the implementations for the set_*_list() family of methods.
 *
 * The only classes that support this interface are Client and 
 * ChangeSet.
 *
 * The set_*_list() methods take as a parameter any STL-compatible container
 * that has the appropriate value_type.
 */
class SetInterface
{
public:
    //TODO: Add a virtual destructor, to avoid warnings, when we can break ABI.

    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    virtual void set(const Glib::ustring& key, const Value& value) = 0;
    virtual void set(const Glib::ustring& key, bool what) = 0;
    virtual void set(const Glib::ustring& key, int what) = 0;
    virtual void set(const Glib::ustring& key, double what) = 0;
    virtual void set(const Glib::ustring& key, const Glib::ustring& what) = 0;
    virtual void set(const Glib::ustring& key, const Schema& what) = 0;

    void set(const Glib::ustring& key,const ValuePair& pair);

    void set_int_list(const Glib::ustring& key, const SListHandle_ValueInt& list);
    void set_bool_list(const Glib::ustring& key, const SListHandle_ValueBool& list);
    void set_float_list(const Glib::ustring& key, const SListHandle_ValueFloat& list);
    void set_string_list(const Glib::ustring& key, const SListHandle_ValueString& list);
    void set_schema_list(const Glib::ustring& key, const SListHandle_ValueSchema& list);

    #else //GLIBMM_EXCEPTIONS_ENABLED

    virtual void set(const Glib::ustring& key, const Value& value, std::auto_ptr<Glib::Error>& error) = 0;
    virtual void set(const Glib::ustring& key, bool what, std::auto_ptr<Glib::Error>& error) = 0;
    virtual void set(const Glib::ustring& key, int what, std::auto_ptr<Glib::Error>& error) = 0;
    virtual void set(const Glib::ustring& key, double what, std::auto_ptr<Glib::Error>& error) = 0;
    virtual void set(const Glib::ustring& key, const Glib::ustring& what, std::auto_ptr<Glib::Error>& error) = 0;
    virtual void set(const Glib::ustring& key, const Schema& what, std::auto_ptr<Glib::Error>& error) = 0;

    void set(const Glib::ustring& key,const ValuePair& pair, std::auto_ptr<Glib::Error>& error);

    void set_int_list(const Glib::ustring& key, const SListHandle_ValueInt& list, std::auto_ptr<Glib::Error>& error);
    void set_bool_list(const Glib::ustring& key, const SListHandle_ValueBool& list, std::auto_ptr<Glib::Error>& error);
    void set_float_list(const Glib::ustring& key, const SListHandle_ValueFloat& list, std::auto_ptr<Glib::Error>& error);
    void set_string_list(const Glib::ustring& key, const SListHandle_ValueString& list, std::auto_ptr<Glib::Error>& error);
    void set_schema_list(const Glib::ustring& key, const SListHandle_ValueSchema& list, std::auto_ptr<Glib::Error>& error);
    #endif //GLIBMM_EXCEPTIONS_ENABLED
};

} /* namespace Conf */
} /* namespace Mate */

#endif
