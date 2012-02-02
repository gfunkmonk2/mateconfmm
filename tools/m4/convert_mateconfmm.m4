_CONVERSION(`MateConfValue*',  `Value', `Value($3)')
_CONVERSION(`Value', `MateConfValue*',  `($3).gobj()')
_CONVERSION(`const Value&', `const MateConfValue*',  `($3).gobj()')
_CONVERSION(`MateConfSchema*',  `Schema', `Schema($3)')
_CONVERSION(`Schema', `MateConfSchema*',  `($3).gobj()')
_CONVERSION(`const Schema&', `const MateConfSchema*',  `($3).gobj()')
_CONVERSION(`const Schema&', `MateConfSchema*',  `const_cast<MateConfSchema*>(($3).gobj())')
_CONVERSION(`MateConfEntry*',  `Entry', `Entry($3)')
_CONVERSION(`GError*', `Glib::Error', `Glib::Error($3, true)')
_CONVERSION(`Glib::Error', `GError*', `($3).gobj()')
_CONVERSION(`MateConfChangeSet*',  `ChangeSet', `ChangeSet($3)')
_CONVERSION(`ChangeSet&', `MateConfChangeSet*',  `($3).gobj()')
_CONVERSION(`const ChangeSet&', `const MateConfChangeSet*',  `($3).gobj()')
_CONVERSION(`const ChangeSet&', `MateConfChangeSet*',  `const_cast<MateConfChangeSet*>(($3).gobj())')

# This is purely for covenience. Some functions return a failure indicator, we 
# just throw an exception.
_CONVERSION(`gboolean',`void', `$3')

# Used by Signals:
# For some reason the compiler can't find Glib::unwrap_boxed().
_CONVERSION(`const Value&',`MateConfValue*',`const_cast<MateConfValue*>($3.gobj())')
_CONVERSION(`MateConfValue*',`const Value&',`Value($3, true)')
_CONVERSION(`const Glib::Error&',`GError*',`const_cast<GError*>($3.gobj())')
_CONVERSION(`GError*',`const Glib::Error&',`Glib::Error($3, true)')

# Our Enumeration conversion
define(`_CONV_ENUM_MATECONFMM',`dnl
_CONVERSION(`MateConf$1', `$1', (($1)(__ARG3__)))
_CONVERSION(`MateConf$1', `Mate::Conf::$1', ((Mate::Conf::$1)(__ARG3__)))
_CONVERSION(`$1', `MateConf$1', ((MateConf$1)(__ARG3__)))
_CONVERSION(`Mate::Conf::$1', `MateConf$1', ((MateConf$1)(__ARG3__)))
')dnl
_CONV_ENUM_MATECONFMM(`ClientPreloadType')
_CONV_ENUM_MATECONFMM(`UnsetFlags')
_CONV_ENUM_MATECONFMM(`ClientErrorHandlingMode')
_CONV_ENUM_MATECONFMM(`ValueType')


# The GSList conversions
define(`__FL2H_DEEP',`$`'2($`'3, Glib::OWNERSHIP_DEEP)')
define(`__FL2H_SHALLOW',`$`'2($`'3, Glib::OWNERSHIP_SHALLOW)')
define(`__FL2H_NONE',`$`'2($`'3, Glib::OWNERSHIP_NONE)')
_CONVERSION(`GSList*',`Glib::SListHandle<Entry>',__FL2H_SHALLOW)
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::ustring>',__FL2H_DEEP)
# These are for MateConfValues, which are optimized to reduce copies
_CONVERSION(`GSList*',`SListHandle_ValueString',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueSchema',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueInt',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueBool',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueFloat',__FL2H_NONE)
_CONVERSION(`const SListHandle_ValueString&',`GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueSchema&',`GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueInt&',   `GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueBool&',  `GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueFloat&', `GSList*',`$3.data()')
# Arrays... ChangeSet needs this :-/
_CONVERSION(`const Glib::SArray&',`const gchar**',`const_cast<const char**>(($3).data())')

# This is purely for covenience. Some functions return a failure indicator, we 
# just throw an exception.
_CONVERSION(`gboolean',`void', `$3')
