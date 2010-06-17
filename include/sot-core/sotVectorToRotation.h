/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Copyright Projet JRL-Japan, 2007
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * File:      sotVectorToRotation.h
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

#ifndef __SOTVECTORTOMATRIX_HH
#define __SOTVECTORTOMATRIX_HH

#include <dynamic-graph/entity.h>
#include <dynamic-graph/all-signals.h>
#include <dynamic-graph/all-signals.h>
#include <sot-core/sotMatrixRotation.h>

/* Matrix */
#include <MatrixAbstractLayer/boost.h>
namespace ml = maal::boost;

/* STD */ 
#include <vector>

/* --------------------------------------------------------------------- */
/* --- VECTOR ---------------------------------------------------------- */
/* --------------------------------------------------------------------- */
class sotVectorToRotation
: public Entity
{
  static const std::string CLASS_NAME;
  virtual const std::string& getClassName( void ) const { return CLASS_NAME; }

  enum sotAxis
    { 
      AXIS_X
      ,AXIS_Y
      ,AXIS_Z
    };

  unsigned int size;
  std::vector< sotAxis > axes;
  

public:
  sotVectorToRotation( const std::string& name );

  virtual ~sotVectorToRotation( void ){}

  SignalPtr<ml::Vector,int> SIN;
  SignalTimeDependant<sotMatrixRotation,int> SOUT;

  sotMatrixRotation& computeRotation( const ml::Vector& angles,
				      sotMatrixRotation& res );


  virtual void commandLine( const std::string& cmdLine,
			    std::istringstream& cmdArgs, 
			    std::ostream& os );

};
    




#endif // #ifndef __SOTVECTORTOMATRIX_HH

