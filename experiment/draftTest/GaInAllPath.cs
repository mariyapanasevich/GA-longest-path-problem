using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExperimentForLPP.Classes
{
    class GaInAllPath:GA
    {
        public GaInAllPath() :base() 
        {
            this.typeTask = 1;
        }

        public double persentToCross { get; set; }
        public int typeAlgorithm { get; set; }
    }
}
