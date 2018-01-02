using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExperimentForLPP
{
    using System;
    using Classes;
    using OpenQA.Selenium;
    using OpenQA.Selenium.Remote;
    using OpenQA.Selenium.Support.PageObjects;
    using ExperimentForLPP.Configurations;

    public class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine("Select task algorithm:\n1-Genetic Algorithm in all graph\n2-Genetic Algorithm between vertex");
            int i = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Input time wait (in second): ");
            int time = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Input number experement: ");
            int number = Int32.Parse(Console.ReadLine());
            Setting set = new Setting();
            Application app = set.open();
            if (i == 1)  app.cycleStart<GaInAllPath>(i, time, number);
            else app.cycleStart<GaBetweenVertex>(i, time, number);
        }

    }
}