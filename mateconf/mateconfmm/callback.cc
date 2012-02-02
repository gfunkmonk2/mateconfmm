// $Id$

/* callback.cc
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

#include <mateconfmm/callback.h>

#include <mateconfmm/client.h>

namespace Mate
{

namespace Conf
{
    
CallbackHolder::CallbackHolder(Callback slot)
: m_Slot(slot)
{
}

CallbackHolder::~CallbackHolder()
{
}

void CallbackHolder::add(Client* pObj)
{
  pObj->set_data ("mateconfmm-client-cb", this, &CallbackHolder::destroy);
}

void CallbackHolder::destroy(void* data)
{
  delete (CallbackHolder*)data;
}

void CallbackHolder::call(MateConfClient* client, guint i, MateConfEntry* pEntry, void* data)
{
  if(data)
    ((CallbackHolder*)data)->m_Slot (i, Entry (pEntry, true));
}

} /* namespace Conf */
} /* namespace Mate */
