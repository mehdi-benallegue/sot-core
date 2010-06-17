/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Copyright Projet JRL-Japan, 2007
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * File:      sotFeatureLineDistance.h
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


#ifndef __SOT_FEATURE_LINEDISTANCE_HH__
#define __SOT_FEATURE_LINEDISTANCE_HH__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* SOT */
#include <sot-core/sotFeatureAbstract.h>
#include <sot-core/sotExceptionTask.h>
#include <sot-core/sotMatrixHomogeneous.h>

/* --------------------------------------------------------------------- */
/* --- API ------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#if defined (WIN32)
#  if defined (sotFeatureLineDistance_EXPORTS)
#    define SOTFEATURELINEDISTANCE_EXPORT __declspec(dllexport)
#  else
#    define SOTFEATURELINEDISTANCE_EXPORT __declspec(dllimport)
#  endif
#else
#  define SOTFEATURELINEDISTANCE_EXPORT
#endif

/* --------------------------------------------------------------------- */
/* --- CLASS ----------------------------------------------------------- */
/* --------------------------------------------------------------------- */


/*!
  \class sotFeatureLineDistance
  \brief Class that defines point-3d control feature
*/
class SOTFEATURELINEDISTANCE_EXPORT sotFeatureLineDistance
: public sotFeatureAbstract
{

 public:
  static const std::string CLASS_NAME;
  virtual const std::string& getClassName( void ) const { return CLASS_NAME; }

 protected:

  /* --- SIGNALS ------------------------------------------------------------ */
 public:
  SignalPtr< sotMatrixHomogeneous,int > positionSIN;
  SignalPtr< ml::Matrix,int > articularJacobianSIN;
  SignalPtr< ml::Vector,int > positionRefSIN;
  SignalPtr< ml::Vector,int > vectorSIN;
  SignalTimeDependant<ml::Vector,int> lineSOUT;

  using sotFeatureAbstract::desiredValueSIN;
  using sotFeatureAbstract::selectionSIN;

  using sotFeatureAbstract::jacobianSOUT;
  using sotFeatureAbstract::errorSOUT;
  using sotFeatureAbstract::activationSOUT;

 public:
  sotFeatureLineDistance( const std::string& name );
  virtual ~sotFeatureLineDistance( void ) {}

  virtual unsigned int& getDimension( unsigned int & dim, int time );

  virtual ml::Vector& computeError( ml::Vector& res,int time );
  virtual ml::Matrix& computeJacobian( ml::Matrix& res,int time );
  virtual ml::Vector& computeActivation( ml::Vector& res,int time );
  ml::Vector& computeLineCoordinates( ml::Vector& cood,int time );

  virtual void display( std::ostream& os ) const;

  virtual void commandLine( const std::string& cmdLine,
			    std::istringstream& cmdArgs,
			    std::ostream& os );

} ;



#endif // #ifndef __SOT_FEATURE_LINEDISTANCE_HH__

/*
 * Local variables:
 * c-basic-offset: 2
 * End:
 */