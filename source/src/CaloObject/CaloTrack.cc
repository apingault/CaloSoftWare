#include "CaloObject/CaloTrack.h"

namespace caloobject
{

  CaloTrack::CaloTrack(std::vector<caloobject::CaloCluster2D*> &vec)
  {
    clusters=vec;
  }
}
