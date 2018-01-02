using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExperimentForLPP.Classes
{
   public abstract class GA
    {
       public int PopulationSize { get; set; }
       public int typeTask { get; set; }
       public String graph { get; set; }
       public int numVertex { get; set; }
       public int numEdge { get; set; }
       public int numberStep { get; set; }
       public double time { get; set; }
       public GA() {}
   
   }
}

