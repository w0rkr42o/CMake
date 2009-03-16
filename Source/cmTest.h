/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmTest_h
#define cmTest_h

#include "cmCustomCommand.h"
#include "cmPropertyMap.h"
class cmMakefile;

/** \class cmTest
 * \brief Represent a test
 *
 * cmTest is representation of a test.
 */
class cmTest
{
public:
  /**
   */
  cmTest();
  ~cmTest();

  ///! Set the test name
  void SetName(const char* name);
  const char* GetName() const { return this->Name.c_str(); }

  void SetCommand(std::vector<std::string> const& command);
  std::vector<std::string> const& GetCommand() const
    {
    return this->Command;
    }

  /**
   * Print the structure to std::cout.
   */
  void Print() const;

  ///! Set/Get a property of this source file
  void SetProperty(const char *prop, const char *value);
  void AppendProperty(const char* prop, const char* value);
  const char *GetProperty(const char *prop) const;
  bool GetPropertyAsBool(const char *prop) const;
  cmPropertyMap &GetProperties() { return this->Properties; };
    
  // Define the properties
  static void DefineProperties(cmake *cm);

  ///! Set the cmMakefile that owns this test
  void SetMakefile(cmMakefile *mf);
  cmMakefile *GetMakefile() { return this->Makefile;};

  /** Get/Set whether this is an old-style test.  */
  bool GetOldStyle() const { return this->OldStyle; }
  void SetOldStyle(bool b) { this->OldStyle = b; }

private:
  cmPropertyMap Properties;
  cmStdString Name;
  std::vector<std::string> Command;

  bool OldStyle;

  // The cmMakefile instance that owns this target.  This should
  // always be set.
  cmMakefile* Makefile;  
};

#endif

