
#include <glib.h>

// Disable the 'const' function attribute of the get_type() functions.
// GCC would optimize them out because we don't use the return value.
#undef  G_GNUC_CONST
#define G_GNUC_CONST /* empty */

#include <mateconfmm/wrap_init.h>
#include <glibmm/error.h>
#include <glibmm/object.h>

// #include the widget headers so that we can call the get_type() static methods:

#include "client.h"
#include "entry.h"
#include "schema.h"
#include "value.h"
#include "changeset.h"

extern "C"
{

//Declarations of the *_get_type() functions:

GType mateconf_client_get_type(void);

//Declarations of the *_error_quark() functions:

GQuark mateconf_error_quark(void);
} // extern "C"


//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

namespace Mate { namespace Conf {  class Client_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  } }

namespace Mate { namespace Conf { 

void wrap_init()
{
  // Register Error domains:
  Glib::Error::register_domain(mateconf_error_quark(), &Mate::Conf::Error::throw_func);

// Map gtypes to gtkmm wrapper-creation functions:
  Glib::wrap_register(mateconf_client_get_type(), &Mate::Conf::Client_Class::wrap_new);

  // Register the gtkmm gtypes:
  Mate::Conf::Client::get_type();

} // wrap_init()

} //Conf
} //Mate
