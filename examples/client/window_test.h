// -*- C++ -*-

/* window_test.h
 * 
 * Copyright (C) 2000 MateConf-- Development Team
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

#ifndef HEADER_WINDOW_TEST
#define HEADER_WINDOW_TEST

#include <iostream>

#include "gtkmm.h"
#include "mateconfmm.h"
#include <list>


class Window_Test : public Gtk::Window
{
public:
  Window_Test();
  virtual ~Window_Test();
  
protected:

  //Signal handlers:
  void on_Button_Quit();
  void on_Button_RemoveSubDir();
  void on_Button_AddSubDir();
  void on_Button_RemoveMainDir();
  void on_Button_AddMainDir();

  void on_Entry_changed(Gtk::Entry* pEntry, Glib::ustring key);

  void Client_notify_func(guint cnxn_id, Mate::Conf::Entry conf_entry, Gtk::Entry* pEntry);
  
protected:

  Gtk::HBox* create_entry_attached_to(const Glib::ustring& key);
  void update_label_text();

  //Member data:

  Glib::RefPtr<Mate::Conf::Client> m_refClient;
  gint m_iSubDir, m_iMainDir;
  Glib::ustring m_strMainDir;

  typedef std::list<guint> type_listNotifyIDs;
  std::list<guint> m_listNotifyIDs; //callback connection IDs from MateConf::Client::notify_add().

  bool m_bBlockEntryHandlers;

  //Member widgets:
  Gtk::VBox m_VBox;
  Gtk::Label m_Label;

  Gtk::Button m_Button_Quit;
  Gtk::Button m_Button_RemoveSubDir, m_Button_AddSubDir;
  Gtk::Button m_Button_RemoveMainDir, m_Button_AddMainDir;
};

#endif //HEADER_WINDOW_TEST
