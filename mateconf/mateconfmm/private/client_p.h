// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _MATECONFMM_CLIENT_P_H
#define _MATECONFMM_CLIENT_P_H


#include <glibmm/class.h>

namespace Mate
{

namespace Conf
{

class Client_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Client CppObjectType;
  typedef MateConfClient BaseObjectType;
  typedef MateConfClientClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class Client;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void value_changed_callback(MateConfClient* self, const gchar* p0, MateConfValue* p1);
  static void unreturned_error_callback(MateConfClient* self, GError* p0);
  static void error_callback(MateConfClient* self, GError* p0);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

  //Callbacks (virtual functions):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED
};


} // namespace Conf

} // namespace Mate


#endif /* _MATECONFMM_CLIENT_P_H */
