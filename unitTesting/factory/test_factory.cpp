/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Copyright Projet JRL-JAPAN, Tsukuba, 2007
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * File:      test_factory.cc
 * Project:   SOT
 * Author:    Nicolas Mansard
 *
 * Version control
 * ===============
 *
 *  $Id$
 *
 * Description
 * ============
 *
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* -------------------------------------------------------------------------- */
/* --- INCLUDES ------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */


#include <string>
#include <iostream>

#include <sot-core/factory.h>
#include <dynamic-graph/entity.h>
#include "../test-paths.h"
#include <sot-core/feature-visual-point.h>
#include <sot-core/exception-feature.h>
#include <sot-core/debug.h>
using namespace std;
using namespace sot;
using namespace dg;

#ifdef WIN32
#include <Windows.h>
#else 
#include <dlfcn.h> 
#endif

#ifdef WIN32
	typedef HMODULE sotPluginKey;
#else
	typedef void* sotPluginKey;
#endif

class TestFeature
  :public FeatureAbstract
{
public:
  TestFeature( void ) : FeatureAbstract("") {}
  virtual ~TestFeature( void ) {}
  virtual unsigned int& getDimension( unsigned int& res,int time ) {return res;}
  
  virtual ml::Vector& computeError( ml::Vector& res,int time ) {return res;} 
  virtual ml::Matrix& computeJacobian( ml::Matrix& res,int time ) {return res;}
  virtual ml::Vector& computeActivation( ml::Vector& res,int time ) {return res;}
};


int main()
{
  
  sotDEBUG(0) << "# In {"<<endl;
//   Entity test("");
//   ExceptionFeature t2(ExceptionFeature::BAD_INIT);
//   ExceptionSignal t4(ExceptionSignal::COPY_NOT_INITIALIZED);
//   Flags t3;
//   TestFeature t5;

#ifndef WIN32
  sotPluginKey dlib = dlopen(PLUGIN_LIB_INSTALL_PATH "/feature-visual-point.so", RTLD_NOW);
#else
  sotPluginKey dlib = LoadLibrary (PLUGIN_LIB_INSTALL_PATH "/feature-visual-point.lib");
#endif
if( NULL==dlib ) 
    {
      cerr << " Error dl"<<endl;
#ifndef WIN32
      cerr << dlerror() <<endl;
#else
    // Retrieve the system error message for the last-error code
    LPTSTR pszMessage;
    DWORD dwLastError = GetLastError(); 
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwLastError,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&pszMessage,
        0, NULL );


	  cerr << pszMessage <<endl;
	  LocalFree(pszMessage);
#endif

      exit(1);
    }


#ifndef WIN32
	dlib = dlopen(PLUGIN_LIB_INSTALL_PATH "/gain-adaptative.so", RTLD_NOW);
#else
	dlib = LoadLibrary (PLUGIN_LIB_INSTALL_PATH "/gain-adaptative.lib");
#endif
  if( NULL==dlib ) 
    {
      cerr << " Error dl"<<endl;
#ifndef WIN32
      cerr << dlerror() <<endl;
#else
    // Retrieve the system error message for the last-error code
    LPTSTR pszMessage;
    DWORD dwLastError = GetLastError(); 
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwLastError,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&pszMessage,
        0, NULL );


	  cerr << pszMessage <<endl;
	  LocalFree(pszMessage);
#endif
      exit(1);
    }

  Entity* gain = g_factory.newEntity("GainAdaptive","Gain");
  FeatureAbstract* point = sotFactory.newFeature("FeatureVisualPoint","DynamicTest.");
  
  try {
  gain->display(cout); cout << endl;
  cout <<gain->getClassName(); cout << endl;

  point->display(cout); cout << endl;
  cout <<point->getClassName(); cout << endl;
  }
  catch ( ExceptionSignal e ) {
	  cout << "Exception caught! " << e << endl;
  }

  sotDEBUG(0) << "# Out }"<<endl;
}

