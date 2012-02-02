// -*- C++ -*-

/* main.cc
 * 
 * Copyright (C) 2000 matemm Development Team
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

#include "window_test.h"

int main (int argc, char *argv[])
{
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENABLED
    Mate::Conf::init();
    Gtk::Main kit(argc, argv);

    Window_Test windowTest;
   
    kit.run(windowTest);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  }
  catch(const Glib::Error& ex)
  {
    //MateConf::Client can throw exceptions.
    std::cout << ex.what() << std::endl;
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  return 0;
}
