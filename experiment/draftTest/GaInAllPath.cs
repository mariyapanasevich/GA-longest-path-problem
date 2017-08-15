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

        public void setTypeAlgorithm(string Name)
        {
            if (Name == "Genetic Algorithm using non - intersecting paths")
            {
                this.typeAlgorithm = 1;
            }
            else if (Name == "Genetic Algorithm using intersecting paths")
            {
                this.typeAlgorithm = 2;
            }
            else if (Name == "Genetic Algorithm using a mutation mechanism")
            {
                this.typeAlgorithm = 3;
            }

            else if (Name == "Genetic Algorithm using non - intersecting paths and intersecting paths")
            {
                this.typeAlgorithm = 4;
            }
        }

        public double persentToCross { get; set; }
        public int typeAlgorithm { get; set; }
        public String Name { get; set; }
    }
}
