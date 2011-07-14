////////////////////////////////////////////////////////////////////////////////
// taskwarrior - a command line task list manager.
//
// Copyright 2006 - 2011, Paul Beckingham, Federico Hernandez.
// All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the
//
//     Free Software Foundation, Inc.,
//     51 Franklin Street, Fifth Floor,
//     Boston, MA
//     02110-1301
//     USA
//
////////////////////////////////////////////////////////////////////////////////
#ifndef INCLUDED_COMMAND
#define INCLUDED_COMMAND
#define L10N                                           // Localization complete.

#include <map>
#include <vector>
#include <string>
#include <Task.h>
#include <Arguments.h>

class Command
{
public:
  Command ();
  Command (const Command&);
  Command& operator= (const Command&);
  bool operator== (const Command&) const;     // TODO Is this necessary?
  virtual ~Command ();

  static void factory (std::map <std::string, Command*>&);

  std::string keyword () const;
  std::string usage () const;
  std::string description () const;
  bool read_only () const;
  bool displays_id () const;
  virtual int execute (std::string&) = 0;

protected:
  void filter (std::vector <Task>&, std::vector <Task>&);
  void filter (std::vector <Task>&);

  void modify_task_description_replace (Task&, Arguments&);
  void modify_task_description_prepend (Task&, Arguments&);
  void modify_task_description_append (Task&, Arguments&);
  void modify_task_annotate (Task&, Arguments&);
  void modify_task (Task&, Arguments&, std::string&);
  void apply_defaults (Task&);

protected:
  std::string _keyword;
  std::string _usage;
  std::string _description;
  bool        _read_only;
  bool        _displays_id;
};

#endif
////////////////////////////////////////////////////////////////////////////////
