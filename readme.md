# keagull

Yea kernel stuff UwU.

## Conventions

Keagull classes are `PascalCased`.
Keagull namespaces usually one-word lowercase.
Keagull functions, variables and members are `camelCased`.

Members have the `m_` prefix.
Globals have the `g_` prefix.
Statics have the `s_` prefix.

## Layout

Keagull is entirely contained in the `keagull` namespace. The `keagull` namespace contains:

* `keagull::undoc` - Ofiicialy undocumented Windows kernel features, such as `APC`'s.
