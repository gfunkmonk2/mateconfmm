// -*- C++ -*-

/* window_test.cc
 *
 * Copyright (C) 2000-2003 matemm Development Team
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

#include <iostream>
#include <gtkmm/window.h>
#include <gtkmm/box.h>

Window_Test::Window_Test()
: m_VBox(false, 10),
  m_Label("Maindir added 1 times\nSubdir added 0 times"),
  m_Button_Quit("Quit"),
  m_Button_RemoveSubDir("Remove subdir"),
  m_Button_AddSubDir("Add subdir"),
  m_Button_RemoveMainDir("Remove maindir"),
  m_Button_AddMainDir("Add maindir")
{
  m_bBlockEntryHandlers = false;

  m_iSubDir = 0;
  m_iMainDir = 0;

  set_title("Mate::Conf::Client Demo");
  set_default_size(200, 200);

  m_strMainDir = "/apps/mate/testmateconfclient";
  m_refClient = Mate::Conf::Client::get_default_client();

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  m_refClient->add_dir(m_strMainDir);
  #else
  std::auto_ptr<Glib::Error> error;
  m_refClient->add_dir(m_strMainDir, Mate::Conf::CLIENT_PRELOAD_NONE, error);
  if(error.get())
    std::cerr << error->what() << std::endl;
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  // test code to figure out show that list of floats work:
  /*
  Glib::ustring testkey = m_strMainDir + "/test_floattype_list";
  typedef gdouble floattype;

  std::list<floattype> testListFloat;
  testListFloat.push_back(1.1);
  testListFloat.push_back(2.2);
  testListFloat.push_back(3.3);
  m_refClient->set_float_list(testkey, testListFloat);

  std::list<floattype> testListFloatFromGet = m_refClient->get_float_list(testkey);
  for(std::list<floattype>::iterator iter = testListFloatFromGet.begin(); iter != testListFloatFromGet.end(); ++iter)
  {
    floattype a = *iter;
    //std::cout << "float list item:" << a << std::endl;
    g_warning("floattype list item: %f", a);
  }
  */
 
  

  add(m_VBox);

  m_VBox.pack_end(m_Label, Gtk::PACK_SHRINK);

  m_VBox.pack_end(m_Button_Quit, Gtk::PACK_SHRINK);
  m_VBox.pack_end(m_Button_RemoveSubDir, Gtk::PACK_SHRINK);
  m_VBox.pack_end(m_Button_AddSubDir, Gtk::PACK_SHRINK);
  m_VBox.pack_end(m_Button_RemoveMainDir, Gtk::PACK_SHRINK);
  m_VBox.pack_end(m_Button_AddMainDir, Gtk::PACK_SHRINK);

  //Connect button signals:
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &Window_Test::on_Button_Quit));
  m_Button_RemoveSubDir.signal_clicked().connect(sigc::mem_fun(*this, &Window_Test::on_Button_RemoveSubDir));
  m_Button_AddSubDir.signal_clicked().connect(sigc::mem_fun(*this, &Window_Test::on_Button_AddSubDir));
  m_Button_RemoveMainDir.signal_clicked().connect(sigc::mem_fun(*this, &Window_Test::on_Button_RemoveMainDir));
  m_Button_AddMainDir.signal_clicked().connect(sigc::mem_fun(*this, &Window_Test::on_Button_AddMainDir));


  Gtk::HBox* pBox = 0;
  pBox = create_entry_attached_to(m_strMainDir + "/blah");
  m_VBox.pack_start(*pBox, Gtk::PACK_SHRINK);

  pBox = create_entry_attached_to(m_strMainDir + "/foo");
  m_VBox.pack_start(*pBox, Gtk::PACK_SHRINK);

  pBox = create_entry_attached_to(m_strMainDir + "/bar");
  m_VBox.pack_start(*pBox, Gtk::PACK_SHRINK);

  pBox = create_entry_attached_to(m_strMainDir + "/subdir/testsub1");
  m_VBox.pack_start(*pBox, Gtk::PACK_SHRINK);

  pBox = create_entry_attached_to(m_strMainDir + "/subdir/testsub2");
  m_VBox.pack_start(*pBox, Gtk::PACK_SHRINK);

  show_all();
}

Window_Test::~Window_Test()
{
  if(m_refClient)
  {
    //Remove callbacks (Is this really necessary)
    for(type_listNotifyIDs::iterator iter = m_listNotifyIDs.begin(); iter != m_listNotifyIDs.end(); iter++)
    {
      guint notify_id = *iter;

      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      m_refClient->notify_remove(notify_id);
      #else
      std::auto_ptr<Glib::Error> error;
      m_refClient->notify_remove(notify_id, error);
      if(error.get())
        std::cerr << error->what() << std::endl;
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
    m_listNotifyIDs.clear();
  }
}

void Window_Test::on_Button_Quit()
{
  Gtk::Main::quit();
}

void Window_Test::on_Entry_changed(Gtk::Entry* pEntry, Glib::ustring key)
{
  if(!m_bBlockEntryHandlers)
  {
    if(pEntry)
    {
      const Glib::ustring text = pEntry->get_text();

      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      m_refClient->set(key, text);
      #else
      std::auto_ptr<Glib::Error> error;
      m_refClient->set(key, text, error);
      if(error.get())
        std::cerr << error->what() << std::endl;
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
}

Gtk::HBox* Window_Test::create_entry_attached_to(const Glib::ustring& key)
{
  Gtk::HBox* pHBox = Gtk::manage(new Gtk::HBox(false, 10));
  Gtk::Label* pLabel = Gtk::manage(new Gtk::Label(key));

  pHBox->pack_start(*pLabel, Gtk::PACK_SHRINK);

  Gtk::Entry* pEntry = Gtk::manage(new Gtk::Entry());

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  pEntry->set_text( m_refClient->get_string(key) );
  #else
  std::auto_ptr<Glib::Error> error;
  pEntry->set_text( m_refClient->get_string(key, error ) );
  if(error.get())
    std::cerr << error->what() << std::endl;
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  //Connect callback and remember the ID for later:
  guint notify_id = m_refClient->notify_add(key, sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &Window_Test::Client_notify_func), pEntry));
  m_listNotifyIDs.push_back(notify_id);

  pEntry->signal_changed().connect(sigc::bind(
                            sigc::mem_fun(*this, &Window_Test::on_Entry_changed),
                            pEntry,
                            key)
                         );

  /* Set sensitive according to whether the key is writable or not. */
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  pEntry->set_sensitive( m_refClient->key_is_writable(key) );
  #else
  {
    std::auto_ptr<Glib::Error> error;
    pEntry->set_sensitive( m_refClient->key_is_writable(key, error) );
    if(error.get())
      std::cerr << error->what() << std::endl;
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  pHBox->pack_end(*pEntry, Gtk::PACK_SHRINK);

  return pHBox;
}

void Window_Test::update_label_text()
{
  gchar* s = g_strdup_printf("Maindir added %d times\nSubdir added %d times", m_iMainDir, m_iSubDir);
  Glib::ustring str = s;
  g_free(s);

  m_Label.set_text(str);
}

void Window_Test::on_Button_RemoveSubDir()
{
  m_iSubDir--;

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  m_refClient->remove_dir(m_strMainDir + "/subdir");
  #else
  std::auto_ptr<Glib::Error> error;
  m_refClient->remove_dir(m_strMainDir + "/subdir", error);
  if(error.get())
    std::cerr << error->what() << std::endl;
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  update_label_text();
}



void Window_Test::on_Button_AddSubDir()
{
  m_iSubDir++;
  
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  m_refClient->add_dir(m_strMainDir + "/subdir");
  #else
  std::auto_ptr<Glib::Error> error;
  m_refClient->add_dir(m_strMainDir + "/subdir", Mate::Conf::CLIENT_PRELOAD_NONE, error);
  if(error.get())
    std::cerr << error->what() << std::endl;
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  update_label_text();
}

void Window_Test::on_Button_RemoveMainDir()
{
  m_iMainDir--;

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  m_refClient->remove_dir(m_strMainDir);
  #else
  std::auto_ptr<Glib::Error> error;
  m_refClient->remove_dir(m_strMainDir, error);
  if(error.get())
    std::cerr << error->what() << std::endl;
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  update_label_text();
}

void Window_Test::on_Button_AddMainDir()
{
  m_iMainDir++;

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  m_refClient->add_dir(m_strMainDir);
  #else
  std::auto_ptr<Glib::Error> error;
  m_refClient->add_dir(m_strMainDir, Mate::Conf::CLIENT_PRELOAD_NONE, error);
  if(error.get())
    std::cerr << error->what() << std::endl;
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  update_label_text();
}

//notify callback.
//The Gtk::Entry* pEntry callback is extra. I used sigc::bind in the connection.
void Window_Test::Client_notify_func(guint cnxn_id, Mate::Conf::Entry conf_entry, Gtk::Entry* pEntry)
{
  if(pEntry)
  {
    //gtk_signal_handler_block_by_data(GTK_OBJECT(pEntry->gtkobj()), m_refClient);
    //Our alternative to gtk_signal_handler_block_by_data(),
    //Because we couldn't have connected the signal handler with that data:
    m_bBlockEntryHandlers = true;

    pEntry->set_text(conf_entry.get_value().get_string());

    //gtk_signal_handler_unblock_by_data(GTK_OBJECT(pEntry->gtkobj()), m_refClient);
    m_bBlockEntryHandlers = false;
  }
}
