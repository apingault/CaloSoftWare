#ifndef EFFICIENCY_HH
#define EFFICIENCY_HH

#include <iostream>
#include <cmath>
#include <vector>

#include "CaloObject/CaloTrack.h"
#include "CaloObject/Layer.h"
#include "CaloObject/CaloCluster.h"
#include "CaloObject/CaloGeom.h"
#include "Algorithm/Tracking.h"
#include "Algorithm/Distance.h"

namespace algorithm
{

struct EfficiencyParameterSetting
{
		float maxRadius ;
		bool semiDigitalReadout ;
		bool printDebug ;
		caloobject::GeomParameterSetting geometry ;
		algorithm::TrackingParameterSetting trackingParams ;
		EfficiencyParameterSetting() : maxRadius(25.0) ,
			semiDigitalReadout(true) ,
			printDebug(false)
		{;}
} ;

class Efficiency
{
	public :
		Efficiency() ;
		~Efficiency() ;

		inline void SetEfficiencyParameterSetting(EfficiencyParameterSetting params) { settings = params ; }
		inline CLHEP::Hep3Vector &getExpectedPosition() { return expectedPos ; }
		void Run(caloobject::Layer* layer, std::vector<caloobject::CaloCluster2D*> &clusters) ;

		inline caloobject::CaloCluster2D* getGoodCluster() const { return goodCluster ; }
		inline bool isTrack() const { return _isTrack ; }
		inline caloobject::CaloTrack* getTrack() const { return track ; }

	protected :
		EfficiencyParameterSetting settings ;
		CLHEP::Hep3Vector expectedPos ;

		caloobject::CaloCluster2D* goodCluster ;
		bool _isTrack ;
		caloobject::CaloTrack* track ;


} ;

} //namespace algorithm

#endif
