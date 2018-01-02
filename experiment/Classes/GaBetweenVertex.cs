using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExperimentForLPP.Classes
{
    public class GaBetweenVertex:GA
    {
        public GaBetweenVertex():base()
        {
            this.typeTask = 2;
        }

        public int firstVertex { get; set; }
        public int secondVertex { get; set; }

    }
}
